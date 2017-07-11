/*
 * testMain.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: stu
 */

#include <iostream>
#include "Lattice.h"
#include "LBM_Problem.h"
#include "D3Q15Lattice.h"
#include "D3Q19Lattice.h"
#include "D3Q27Lattice.h"


int main(int argc, char * argv[]){

	std::cout << "Hello test main!" << std::endl;
	D3Q15Lattice d15 = D3Q15Lattice(10,10,10);
	D3Q19Lattice d19 = D3Q19Lattice(10,10,10);
	D3Q27Lattice d27 = D3Q27Lattice(10,10,10);


	std::cout << "d15 numSpd = " << d15.getNumSpd() << std::endl;
	std::cout << "d19 numSpd = " << d19.getNumSpd() << std::endl;
	std::cout << "d27 numSpd = " << d27.getNumSpd() << std::endl;

	LBM_Problem myLBM = LBM_Problem();

	std::cout << "everything done" << std::endl;
	return 0;
}



