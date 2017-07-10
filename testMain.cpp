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

	std::cout << "everything done" << std::endl;
	return 0;
}



