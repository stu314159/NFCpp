/*
 * LBM_Problem.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: sblair
 */


#include "LBM_Problem.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>

const std::string LBM_Problem::params_file_name="params.lbm";
const std::string LBM_Problem::snl_file_name="snl.lbm";
const std::string LBM_Problem::inl_file_name="inl.lbm";
const std::string LBM_Problem::onl_file_name="onl.lbm";

const std::string LBM_Problem::ux_stub="ux";
const std::string LBM_Problem::uy_stub="uy";
const std::string LBM_Problem::uz_stub="uz";
const std::string LBM_Problem::density_stub="density";
const std::string LBM_Problem::suffix=".b_dat";
int LBM_Problem::dumpCounter = 0;

LBM_Problem::LBM_Problem()
{
	// get the input data
	readInput();

	// create the lattice object
	switch (lattice_type)
	{
	case(1):
		myLattice = new D3Q15Lattice(Nx,Ny,Nz); break;
	case(2):
		myLattice = new D3Q19Lattice(Nx,Ny,Nz); break;
	case(3):
		myLattice = new D3Q27Lattice(Nx,Ny,Nz);

	}
	// allocate memory for the data arrays
	nnodes = Nx*Ny*Nz;
	numSpd = myLattice->getNumSpd();

	fEven = new float[nnodes*numSpd];
	fOdd = new float[nnodes*numSpd];

	// initialize fEven and fOdd
	initializeDensityData();

	// allocate memory for boundary condition arrays
	inl = new int[nnodes];
	onl = new int[nnodes];
	snl = new int[nnodes];
	// initialize boundary condition arrays
	initializeBCarrays();

	// allocate memory for output data arrays
	ux = new float[nnodes];
	uy = new float[nnodes];
	uz = new float[nnodes];
	rho = new float[nnodes];


}

LBM_Problem::~LBM_Problem()
{

	delete myLattice;
	delete [] fEven;
	delete [] fOdd;
	delete [] inl;
	delete [] onl;
	delete [] snl;
	delete [] ux;
	delete [] uy;
	delete [] uz;
	delete [] rho;
}

void LBM_Problem::do_TimeStep(bool isEven)
{
	//assign fIn and fOut pointers
	if (isEven) //for even time step, fEven holds up-to-date info at beginning of step
	{
		fIn = fEven; fOut = fOdd;
	}else{ // for odd time steps, fOdd holds up-to-date info at beginning of step
		fIn = fOdd; fOut = fEven;
	}


}

void LBM_Problem::write_Data(bool isEven)
{
	// write_Data only at the end of a time step.
	float * fOutput;
	float fBuff[numSpd];
	float ux_nd, uy_nd, uz_nd, rho_nd;
	std::stringstream ts_ind;
	std::string density_fn, ux_fn, uy_fn, uz_fn;
	if (isEven)
	{
		fOutput = fOdd; //at end of an Even time step, fOdd is up to date.
	}else
	{
		fOutput = fEven; //at end of an Odd time step, fEven is up to date.
	}
	//loop through all lattice points (I own them after all)
	for(int nd=0;nd<nnodes;nd++)
	{
		// package up density distribution data for each lattice point in turn
		for(int spd=0;spd<numSpd;spd++)
		{
			fBuff[spd]=fOutput[getIdx(nnodes,numSpd,nd,spd)];
		}

		// pass to lattice object to compute ux,uy,uz, and rho
		myLattice->computeMacroscopicData(rho_nd,ux_nd,uy_nd,uz_nd,fBuff);

		// package ux,uy,uz, and rho into output buffers
		ux[nd]=ux_nd; uy[nd]=uy_nd; uz[nd]=uz_nd; rho[nd]=rho_nd;

	}

	// write output buffer to binary file
	// generate current dump file names
	ts_ind << dumpCounter;
	density_fn = density_stub+ts_ind.str()+suffix;
	ux_fn = ux_stub+ts_ind.str()+suffix;
	uy_fn = uy_stub+ts_ind.str()+suffix;
	uz_fn = uz_stub+ts_ind.str()+suffix;
	std::ofstream uxFile(ux_fn.c_str(),std::ios::out | std::ios::binary);
	uxFile.write((const char *)ux,nnodes*sizeof(float));
	uxFile.close();

	std::ofstream uyFile(uy_fn.c_str(),std::ios::out | std::ios::binary);
	uyFile.write((const char *)uy,nnodes*sizeof(float));
	uyFile.close();

	std::ofstream uzFile(uz_fn.c_str(),std::ios::out | std::ios::binary);
	uzFile.write((const char*)uz,nnodes*sizeof(float));
	uzFile.close();

	std::ofstream rhoFile(density_fn.c_str(),std::ios::out | std::ios::binary);
	rhoFile.write((const char*)rho,nnodes*sizeof(float));
	rhoFile.close();

	// after data is written:
	dumpCounter+=1;
}
void LBM_Problem::initializeBCarrays()
{
	// initialize all arrays to zer
	for(int nd=0;nd<nnodes; nd++)
	{
		inl[nd]=0; onl[nd]=0; snl[nd] = 0;
	}


	int bc_nd; int numBCnd;
	// inlet node lists
	std::ifstream inl_file(inl_file_name.c_str(),std::ios::in);
	if(!inl_file.is_open())
		throw std::runtime_error("Could not open inlet node list file!");
	inl_file >> numBCnd;
	for(int nd=0;nd<numBCnd;nd++)
	{
		inl_file >> bc_nd;
		if(bc_nd > (nnodes-1))
			throw std::runtime_error("invalid inlet node number read!");
		inl[bc_nd] = 1;

	}
	inl_file.close();


	// outlet node list
	std::ifstream onl_file(onl_file_name.c_str(),std::ios::in);
	if(!onl_file.is_open())
		throw std::runtime_error("Could not open outlet node list file!");
	onl_file >> numBCnd;
	for(int nd=0;nd<numBCnd;nd++)
	{
		onl_file >> bc_nd;
		if(bc_nd > (nnodes-1))
			throw std::runtime_error("invalid outlet node number read!");
		onl[bc_nd] = 1;
	}
	onl_file.close();


	// solid node list
	std::ifstream snl_file(snl_file_name.c_str(),std::ios::in);
	if(!snl_file.is_open())
		throw std::runtime_error("Cound not open solid node list file!");
	snl_file >> numBCnd;
	for(int nd=0; nd<numBCnd;nd++)
	{
		snl_file >> bc_nd;
		if(bc_nd > (nnodes-1))
			throw std::runtime_error("invalid solid node number read!");
		snl[bc_nd]=1;
	}
	snl_file.close();



}

void LBM_Problem::initializeDensityData()
{
	float * w = myLattice->get_w();
	for(int nd=0;nd<nnodes;nd++)
	{
		for(int spd=0;spd<numSpd;spd++)
		{
			fEven[getIdx(nnodes,numSpd,nd,spd)]=rho_lbm*w[spd];
			fOdd[getIdx(nnodes,numSpd,nd,spd)]=rho_lbm*w[spd];
		}
	}
}

void LBM_Problem::readInput()
{
	std::ifstream input_params(params_file_name.c_str(),std::ios::in);
	if(!input_params.is_open())
		throw std::runtime_error("Could not open parameter file!");
	input_params >> lattice_type;
	input_params >> Num_ts;
	input_params >> ts_rep_freq;
	input_params >> Warmup_ts;
	input_params >> plot_freq;
	input_params >> Cs;
	input_params >> rho_lbm;
	input_params >> u_lbm;
	input_params >> omega;
	input_params >> Nx;
	input_params >> Ny;
	input_params >> Nz;
	input_params >> Restart;
	input_params.close();


}
