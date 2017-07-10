/*
 * D3Q27Lattice.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: sblair
 */
#include "Lattice.h"
#include "D3Q27Lattice.h"
#include <cstdlib>

D3Q27Lattice::D3Q27Lattice(const int Nx, const int Ny, const int Nz):
Lattice(Nx,Ny,Nz)
{
	ex = new float[27];
	ey = new float[27];
	ez = new float[27];
	w = new float[27];
	bbSpd = new int[27];
	numSpd = 27;

}

D3Q27Lattice::~D3Q27Lattice()
{
	delete [] ex;
	delete [] ey;
	delete [] ez;
	delete [] w;
	delete [] bbSpd;
}



