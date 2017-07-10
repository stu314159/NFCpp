#include "Lattice.h"
#include <cstdlib>

Lattice::Lattice(const int Nx, const int Ny, const int Nz):
Nx(Nx), Ny(Ny), Nz(Nz)
{
	float * ex = NULL;
	float * ey = NULL;
	float * ez = NULL;
	float * w =  NULL;
	int * bbSpd = NULL;

}

Lattice::~Lattice()
{


}

void Lattice::computeMacroscopicData(float& rho, float& ux, float& uy, float& uz,
		                             const float * f)
{
	rho = 0.; ux = 0.; uy = 0.; uz = 0.;
	for(int spd = 0; spd<numSpd; spd++)
	{
		rho+=f[spd];
		ux+=ex[spd]*f[spd];
		uy+=ey[spd]*f[spd];
		uz+=ez[spd]*f[spd];
	}
	ux/=rho; uy/=rho; uz/=rho;

}
