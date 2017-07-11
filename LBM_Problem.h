/*
 * LBM_Problem.h
 *
 *  Created on: Jul 11, 2017
 *      Author: sblair
 */

#ifndef LBM_PROBLEM_H_
#define LBM_PROBLEM_H_

class LBM_Problem
{
public:
	LBM_Problem();
	~LBM_Problem();

private:
	// data members to be read from the input file
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

	// LBM density data arrays
	float * fEven;
	float * fOdd;

};



#endif /* LBM_PROBLEM_H_ */
