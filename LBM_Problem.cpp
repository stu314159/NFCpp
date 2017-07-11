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

const std::string LBM_Problem::params_file_name="params.lbm";
const std::string LBM_Problem::snl_file_name="snl.lbm";
const std::string LBM_Problem::inl_file_name="inl.lbm";
const std::string LBM_Problem::onl_file_name="onl.lbm";

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

	std::cout << "There are " << nnodes << " nodes, and " << numSpd <<" speeds per node."
			<< std::endl;
	fEven = new float[nnodes*numSpd];
	fOdd = new float[nnodes*numSpd];

	// initialize fEven and fOdd
	initializeDensityData();

	// initialize boundary condition arrays
	inl = new int[nnodes];
	onl = new int[nnodes];
	snl = new int[nnodes];

	initializeBCarrays();

}

LBM_Problem::~LBM_Problem()
{
	std::cout << "entering destructor..." << std::endl;

	std::cout << "destroying my lattice..." << std::endl;
	delete myLattice;

	std::cout << "destroying fEven and fOdd..." << std::endl;
	delete [] fEven;
	delete [] fOdd;

	std::cout << "destroying boundary data arrays..." << std::endl;
	std::cout << "inl..." << std::endl;
	delete [] inl;
	std::cout << "onl..." << std::endl;
	delete [] onl;
	std::cout << "snl..." << std::endl;
	delete [] snl;
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
