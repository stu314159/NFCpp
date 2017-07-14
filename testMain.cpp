/*
 * testMain.cpp
 *
 *  Created on: Jul 7, 2017
 *      Author: stu
 */

#include <iostream>
#include <ctime>
#include "Lattice.h"
#include "LBM_Problem.h"
#include "D3Q15Lattice.h"
#include "D3Q19Lattice.h"
#include "D3Q27Lattice.h"

#include <omp.h>


int main(int argc, char * argv[]){

	LBM_Problem myLBM = LBM_Problem();
	int Num_Ts = myLBM.get_NumTs();
	int ts_rep_freq = myLBM.get_tsRepFreq();
	int plot_freq = myLBM.get_plotFreq();

	// write initial data (might be interesting for re-start)
	// necessary for compatibility with existing post-processing tools
	myLBM.write_Data(0);

	std::cout << "Commencing LBM simulation with " << Num_Ts <<
			" time steps." << std::endl;
	int ompThreads = omp_get_max_threads();

	std::cout << "There are " << ompThreads << " OMP threads detected. " << std::endl;

	clock_t tStart, tEnd;
	float runTime;
	float totalLPU, LPUperSecond;

#pragma omp parallel
	{
		int tid = omp_get_thread_num();
		int size = omp_get_num_threads();
		double tS_omp, tE_omp;
		if(tid==0)
		{
			tS_omp = omp_get_wtime();
		}
		std::cout << "thread " << tid << " of " << size << " entering time step loop." << std::endl;
		tStart = clock();
		for(int ts = 0; ts<Num_Ts; ts++)
		{
			if(((ts+1)%ts_rep_freq)==0)
			{
				if(tid==0)
				{
					std::cout << "Executing time step " << ts+1 << std::endl;
				}
			}
			//std::cout << "entering do_TimeStep" << std::endl;
			// do lattice Boltzmann time step calculations
			myLBM.do_TimeStep(ts%2==0);
#pragma omp barrier
			if(((ts+1)%plot_freq)==0)
			{
				if(tid==0)
				{


					std::cout << "Outputting data for time step " << ts+1 << std::endl;
					myLBM.write_Data(ts%2);
				}
			}


		}
		if(tid==0)
		{
			tE_omp = omp_get_wtime();
			runTime = tE_omp - tS_omp;
			totalLPU = Num_Ts*myLBM.getNumNodes();
			LPUperSecond = totalLPU/runTime;
			std::cout << "From OMP - Estimated performance: " << LPUperSecond << " LPU/sec" << std::endl;
		}
	}
	tEnd = clock();
	runTime = ((float)tEnd - (float)tStart)/CLOCKS_PER_SEC;
	totalLPU = Num_Ts*myLBM.getNumNodes();
	LPUperSecond = totalLPU/runTime;
	std::cout << "Estimated performance: " << LPUperSecond <<" LPU/sec"<< std::endl;

	return 0;
}



