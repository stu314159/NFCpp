#include "Lattice.h"
#include <cstdlib>

Lattice::Lattice(const int Nx, const int Ny, const int Nz):
Nx(Nx), Ny(Ny), Nz(Nz)
{
ex = NULL;
ey = NULL;
ez = NULL;
bbSpd = NULL;
w = NULL;
numSpd = 0;

}

Lattice::~Lattice()
{


}
