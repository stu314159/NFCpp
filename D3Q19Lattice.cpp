/*
 * D3Q19Lattice.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: sblair
 */

#include "D3Q19Lattice.h"
#include <cstdlib>

D3Q19Lattice::D3Q19Lattice(const int Nx, const int Ny, const int Nz):
Lattice(Nx,Ny,Nz),
ex{0,1,-1,0,0,0,0,1,-1,1,-1,1,-1,1,-1,0,0,0,0},
ey{0,0,0,1,-1,0,0,1,1,-1,-1,0,0,0,0,1,-1,1,-1},
ez{0,0,0,0,0,1,-1,0,0,0,0,1,1,-1,-1,1,1,-1,-1},
w{3.f/9.f,1.f/18.f,1.f/18.f,1.f/18.f,1.f/18.f,1.f/18.f,1.f/18.f,
    1.f/36.f,1.f/36.f,1.f/36.f,1.f/36.f,1.f/36.f,1.f/36.f,
    1.f/36.f,1.f/36.f,1.f/36.f,1.f/36.f,1.f/36.f,1.f/36.f},
bbSpd{0, 2, 1, 4, 3, 6, 5, 10, 9, 8, 7, 14, 13, 12, 11, 18, 17, 16, 15},
Qflat{-1./3.,0,0,0,-1./3.,0,0,0,-1./3.,
	2./3.,0,0,0,-1./3.,0,0,0,-1./3.,
	2./3.,0,0,0,-1./3.,0,0,0,-1./3.,
	-1./3.0,0,0,-2./3.,0,0,0,-1./3.,
	-1./3.,0,0,0,2./3.,0,0,0,-1./3.,
	-1./3.,0,0,0,-1./3.,0,0,0,2./3.,
	-1./3.,0,0,0,-1./3.,0,0,0,2./3.,
	2./3.,1,0,1,2./3.,0,0,0,-1./3.,
	2./3.,-1,0,-1,2./3.,0,0,0,-1./3.,
	2./3.,-1,0,-1,2./3.,0,0,0,-1./3.,
	2./3.,1,0,1,2./3.,0,0,0,-1./3.,
	2./3.,0,1,0,-1./3.,0,1,0,2./3.,
	2./3.,0,-1,0,-1./3.,0,-1,0,2./3.,
	2./3.,0,-1,0,-1./3.,0,-1,0,2./3.,
	2./3.,0,1,0,-1./3.,0,1,0,2./3.,
	-1./3.,0,0,0,2./3.,1,0,1,2./3.,
	-1./3.,0,0,0,2./3.,-1,0,-1,2./3.,
	-1./3.,0,0,0,2./3.,-1,0,-1,2./3.,
	-1./3.,0,0,0,2./3.,1,0,1,2./3.}
{
	// direct base-class pointers to lattice variables
	setNumSpd(numSpd);
	setEx(ex);
	setEy(ey);
	setEz(ez);
	setW(w);
	setBBspd(bbSpd);
}

D3Q19Lattice::~D3Q19Lattice()
{

}

void D3Q19Lattice::set_inlet_bc_micro(LBM_DataHandler& f)
{
  //finish me...
}

void D3Q19Lattice::set_inlet_bc_macro(LBM_DataHandler& f)
{
	//finish me...
}

void D3Q19Lattice::set_outlet_bc_micro(LBM_DataHandler& f)
{
	//finish me...
}

void D3Q19Lattice::set_outlet_bc_macro(LBM_DataHandler& f)
{
	//finish me...
}


