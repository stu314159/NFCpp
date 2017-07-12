#include "Lattice.h"
#include <cstdlib>

Lattice::Lattice(const int Nx, const int Ny, const int Nz):
Nx(Nx), Ny(Ny), Nz(Nz), numSpd(0),

ex(NULL), ey(NULL), ez(NULL),w(NULL), bbSpd(NULL), Qflat(NULL)
{

}

Lattice::~Lattice()
{


}

void Lattice::bounceBack(LBM_DataHandler& f)
{
	float fTmp[numSpd];
	for(int spd=0;spd<numSpd;spd++)
	{
		fTmp[spd]=f.f[bbSpd[spd]];
	}
	for(int spd=0;spd<numSpd;spd++)
	{
		f.f[spd]=fTmp[spd];
	}

}
void Lattice::computeMacroscopicData(float& rho, float& ux, float& uy, float& uz, const float* f)
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
void Lattice::computeMacroscopicData(LBM_DataHandler& f)
{
	int rho, ux, uy, uz;
	rho = 0.; ux = 0.; uy = 0.; uz = 0.;
	for(int spd = 0; spd<numSpd; spd++)
	{
		rho+=f.f[spd];
		ux+=ex[spd]*f.f[spd];
		uy+=ey[spd]*f.f[spd];
		uz+=ez[spd]*f.f[spd];
	}
	ux/=rho; uy/=rho; uz/=rho;
	f.rho = rho; f.ux = ux; f.uy = uy; f.uz = uz;

}

void Lattice::computeEquilibrium(float * fEq,const float ux, const float uy, const float uz, const float rho)
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

void Lattice::computeFout(LBM_DataHandler& f)
{
	// node type 1: just bounce back
	if (f.nodeType==1)
	{
		// just bounce back
		bounceBack(f);

	}else
	{
		// node type 0, 2, and 3 continue with the following steps:

		// compute macroscopic velocity and pressure
		computeMacroscopicData(f);

		// node type 2 and 3 apply macroscopic boundary conditions

		// compute equilibrium

		// node type 2 and 3 apply microscopic boundary conditions and regularization
	}



}
