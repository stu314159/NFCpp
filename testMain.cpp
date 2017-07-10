/*
 * testMain.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: stu
 */

#include <iostream>
#include "Lattice.h"
#include "D3Q15Lattice.h"
#include "D3Q19Lattice.h"
#include "D3Q27Lattice.h"


int main(int argc, char * argv[]){

	std::cout << "Hello test main!" << std::endl;
	D3Q15Lattice d15 = D3Q15Lattice(10,10,10);
	D3Q19Lattice d19 = D3Q19Lattice(10,10,10);
	D3Q27Lattice d27 = D3Q27Lattice(10,10,10);

	float * f15 = new float[d15.numSpd];
	float * f19 = new float[d19.numSpd];
	float * f27 = new float[d27.numSpd];

	for(int spd = 0; spd<d15.numSpd;spd++){
		f15[spd]=spd;
	}
	for(int spd=0; spd<d19.numSpd; spd++){
		f19[spd]=spd;
	}
	for(int spd=0; spd<d27.numSpd;spd++){
		f27[spd]=spd;
	}
	float rho15, ux15, uy15, uz15;
	float rho19, ux19, uy19, uz19;
	float rho27, ux27, uy27, uz27;

	d15.computeMacroscopicData(rho15,ux15,uy15,uz15,f15,d15.numSpd,
			d15.ex,d15.ey, d15.ez);
	d19.computeMacroscopicData(rho19,ux19,uy19,uz19,f19,d19.numSpd,
			d19.ex, d19.ey, d19.ez);
	d27.computeMacroscopicData(rho27,ux27,uy27,uz27,f27,d27.numSpd,
			d27.ex, d27.ey, d27.ez);

	std::cout << "output for Q15 = " << rho15 << ", " << ux15 << ", "
			<< uy15 << ", " << uz15 << std::endl;

	std::cout << "output for Q19 = " << rho19 << ", " << ux19 << ", "
				<< uy19 << ", " << uz19 << std::endl;

	std::cout << "output for Q27 = " << rho27 << ", " << ux27 << ", "
				<< uy27 << ", " << uz27 << std::endl;


	delete [] f15;
	delete [] f19;
	delete [] f27;
	std::cout << "everything done" << std::endl;
	return 0;
}



