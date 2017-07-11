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

	LBM_Problem myLBM = LBM_Problem();
	int Num_Ts = myLBM.get_NumTs();
	std::cout << "Commencing LBM simulation with " << Num_Ts <<
			" time steps." << std::endl;

	std::cout << "everything done" << std::endl;
	return 0;
}



