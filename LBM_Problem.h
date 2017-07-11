/*
 * LBM_Problem.h
 *
 *  Created on: Jul 11, 2017
 *      Author: sblair
 */

#ifndef LBM_PROBLEM_H_
#define LBM_PROBLEM_H_

#include <string>
#include "Lattice.h"
#include "LBM_Problem.h"
#include "D3Q15Lattice.h"
#include "D3Q19Lattice.h"
#include "D3Q27Lattice.h"

class LBM_Problem
{
public:
	LBM_Problem();
	~LBM_Problem();

private:
	// private methods
	void readInput();

	// data members to be read from the input file
	int lattice_type;
	int Num_ts;
	int ts_rep_freq;
	int Warmup_ts;
	int plot_freq;
	float Cs;
	float rho_lbm;
	float u_lbm;
	float omega;
	int Nx,Ny,Nz;
	bool Restart;
	float Lx_p;
	float Ly_p;
	float Lz_p;
	int nnodes;
	int numSpd;

	//Lattice data structure
	Lattice * myLattice;

	// LBM density data arrays
	float * fEven;
	float * fOdd;

	//input files
	static const std::string params_file_name;
	static const std::string inl_file_name;
	static const std::string onl_file_name;
	static const std::string snl_file_name;

};



#endif /* LBM_PROBLEM_H_ */
