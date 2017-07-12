#include "Lattice.h"
#include "D3Q15Lattice.h"


D3Q15Lattice::D3Q15Lattice(const int Nx, const int Ny, const int Nz):
Lattice(Nx,Ny,Nz),
ex{0,1,-1,0,0,0,0,1,-1,1,-1,1,-1,1,-1},
ey{0,0,0,1,-1,0,0,1,1,-1,-1,1,1,-1,-1},
ez{0,0,0,0,0,1,-1,1,1,1,1,-1,-1,-1,-1},
w{2.f/9.f,1.f/9.f,1.f/9,1.f/9.f,1.f/9.f,1.f/9.f,1.f/9.f,
    1.f/72.f,1.f/72.f,1.f/72.f,1.f/72.f,
    1.f/72.f,1.f/72.f,1.f/72.f,1.f/72.f},
bbSpd{0,2,1,4,3,6,5,14,13,12,11,10,9,8,7},
Qflat{1./3.,0.,0.,0,-1./3.,0,0,0,-1./3.,  //this is embarrassing, but better than implementing the LA
	2./3.,0,0,0,-1./3.,0,0,0,-1./3.,
	2./3.,0,0,0,-1./3.,0,0,0,-1./3.,
	-1./3.,0,0,0,2./3.,0,0,0,-1./3.,
	-1./3.,0,0,0,2./3.,0,0,0,-1./3.,
	-1./3.,0,0,0,-1./3.,0,0,0,2./3.,
	-1./3.,0,0,0,-1./3.,0,0,0,2./3.,
	2./3.,1,1,1,2./3.,1,1,1,2./3.,
	2./3.,-1,-1,-1,2./3.,1,-1,1,2./3.,
	2./3.,-1,1,-1,2./3.,-1,1,-1,2./3.,
	2./3.,1,-1,1,2./3.,-1,-1,-1,2./3.,
	2./3.,1,-1,1,2./3.,-1,-1,-1,2./3.,
	2./3.,-1,1,-1,2./3.,-1,1,-1,2./3.,
	2./3.,-1,-1,-1,2./3.,1,-1,1,2./3.,
	2./3.,1,1,1,2./3.,1,1,1,2./3.}
{
	// direct base-class pointers to lattice variables
	setNumSpd(numSpd);
	setEx(ex);
	setEy(ey);
	setEz(ez);
	setW(w);
	setBBspd(bbSpd);

}

D3Q15Lattice::~D3Q15Lattice()
{


}

void D3Q15Lattice::set_inlet_bc_micro(LBM_DataHandler& f)
{
  //finish me...
}

void D3Q15Lattice::set_inlet_bc_macro(LBM_DataHandler& f)
{
	//finish me...
}

void D3Q15Lattice::set_outlet_bc_micro(LBM_DataHandler& f)
{
	//finish me...
}

void D3Q15Lattice::set_outlet_bc_macro(LBM_DataHandler& f)
{
	//finish me...
}

