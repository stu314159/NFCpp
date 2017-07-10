#include "Lattice.h"
#include <cstdlib>

Lattice::Lattice(const int Nx, const int Ny, const int Nz):
Nx(Nx), Ny(Ny), Nz(Nz), numSpd(0),
ux(0),uy(0),uz(0),rho(0),u_bc(0),rho_bc(0),
ex(NULL), ey(NULL), ez(NULL),w(NULL), bbSpd(NULL),fEq(NULL)
{

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

void Lattice::computeEquilibrium(float * fEq)
{
	//this will assume that up-to-date data exists in rho, ux, uy, and uz class variables
	//and that ex,ey,ez,and w have been updated with the lattice-specific info
	float cu;
	for(int spd = 0; spd<numSpd;spd++)
	{
		fEq[spd] = 0;
		cu = 3.f*(ex[spd]*ux+ey[spd]*uy+ez[spd]*uz);
		fEq[spd]=w[spd]*rho*(1.f+cu+0.5f*(cu*cu)-3.f/2.f*(ux*ux+uy*uy+uz*uz));

	}
}
