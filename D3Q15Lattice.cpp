#include "Lattice.h"
#include "D3Q15Lattice.h"


D3Q15Lattice::D3Q15Lattice(const int Nx, const int Ny, const int Nz):
Lattice(Nx,Ny,Nz)
{
	// allocate lattice data arrays
	ex = new float[15];
	ey = new float[15];
	ez = new float[15];
	w = new float[15];
	bbSpd = new int[15];
	numSpd = 15;
}

D3Q15Lattice::~D3Q15Lattice()
{
	delete [] ex;
	delete [] ey;
	delete [] ez;
	delete [] w;
	delete [] bbSpd;


}
