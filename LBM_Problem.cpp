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

}

LBM_Problem::~LBM_Problem()
{

	delete myLattice;
	delete [] fEven;
	delete [] fOdd;
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
