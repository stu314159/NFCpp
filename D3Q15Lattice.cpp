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
f{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
fEq{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
ft{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
{
	// direct base-class pointers to lattice variables
	setNumSpd(numSpd);
	setEx(ex);
	setEy(ey);
	setEz(ez);
	setW(w);
	setBBspd(bbSpd);
	setF(f);
	setFeq(fEq);
	setFt(ft);
}

D3Q15Lattice::~D3Q15Lattice()
{


}

