/*
 * D3Q19Lattice.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: sblair
 */

#include "Lattice.h"
#include "D3Q19Lattice.h"
#include <cstdlib>

D3Q19Lattice::D3Q19Lattice(const int Nx, const int Ny, const int Nz):
Lattice(Nx,Ny,Nz)
{
	ex = new float[19];
	ey = new float[19];
	ez = new float[19];
	w = new float[19];
	bbSpd = new int[19];
	numSpd = 19;

}

D3Q19Lattice::~D3Q19Lattice()
{
	delete [] ex;
	delete [] ey;
	delete [] ez;
	delete [] w;
	delete [] bbSpd;
}


