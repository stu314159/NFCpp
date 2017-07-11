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
	int ts_rep_freq = myLBM.get_tsRepFreq();
	int plot_freq = myLBM.get_plotFreq();
	std::cout << "Commencing LBM simulation with " << Num_Ts <<
			" time steps." << std::endl;

	for(int ts = 0; ts<Num_Ts; ts++)
	{
		if(((ts+1)%ts_rep_freq)==0)
		{
			std::cout << "Executing time step " << ts+1 << std::endl;
		}

		// do lattice Boltzmann time step calculations



		if(((ts+1)%plot_freq)==0)
		{
			std::cout << "Outputting data for time step " << ts+1 << std::endl;
			myLBM.write_Data(ts%2);
		}


	}

	std::cout << "everything done" << std::endl;
	return 0;
}



