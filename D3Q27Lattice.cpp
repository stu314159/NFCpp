/*
 * D3Q27Lattice.cpp
 *
 *  Created on: Jul 10, 2017
 *      Author: sblair
 */
#include "D3Q27Lattice.h"
#include <cstdlib>

D3Q27Lattice::D3Q27Lattice(const int Nx, const int Ny, const int Nz):
Lattice(Nx,Ny,Nz),
ex{0,-1,0,0,-1,-1,-1,-1,0,0,-1,-1,-1,-1,1,0,0,1,1,1,1,0,0,1,1,1,1},
ey{0,0,-1,0,-1,1,0,0,-1,-1,-1,-1,1,1,0,1,0,1,-1,0,0,1,1,1,1,-1,-1},
ez{0,0,0,-1,0,0,-1,1,-1,1,-1,1,-1,1,0,0,1,0,0,1,-1,1,-1,1,-1,1,-1},
w{8.f/27.f,2.f/27.f,2.f/27.f,2.f/27.f,1.f/54.f,1.f/54.f,1.f/54.f,1.f/54.f,1.f/54.f,
	1.f/54.f,1.f/216.f,1.f/216,1.f/216.f,1.f/216.f,2.f/27.f,2.f/27.f,
	2.f/27.f,1.f/54.f,1.f/54.f,1.f/54.f,1.f/54.f,1.f/54.f,
	1.f/54.f,1.f/216.f,1.f/216,1.f/216.f,1.f/216.f},
bbSpd{0,14,15,16,17,18,19,20,21,22,23,24,25,26,
		1,2,3,4,5,6,7,8,9,10,11,12,13},
fEq{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
{
	// direct base-class pointers to lattice variables
	setNumSpd(numSpd);
	setEx(ex);
	setEy(ey);
	setEz(ez);
	setW(w);
	setBBspd(bbSpd);
	setFeq(fEq);
	setF(f);
	setFt(ft);

}

D3Q27Lattice::~D3Q27Lattice()
{

}




