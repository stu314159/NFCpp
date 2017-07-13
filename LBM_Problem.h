/*
 * LBM_Problem.h
 *
 *  Created on: Jul 11, 2017
 *      Author: sblair
 */

#ifndef LBM_PROBLEM_H_
#define LBM_PROBLEM_H_

#include <string>
#include <omp.h>
#include "Lattice.h"
#include "LBM_Problem.h"
#include "D3Q15Lattice.h"
#include "D3Q19Lattice.h"
#include "D3Q27Lattice.h"
#include "LBM_DataHandler.h"

class LBM_Problem
{
public:
	LBM_Problem();
	~LBM_Problem();
	int get_NumTs(){return Num_ts;};
	int get_tsRepFreq(){return ts_rep_freq;};
	int get_plotFreq(){return plot_freq;};
	int getNumNodes(){return Nx*Ny*Nz;};
	void do_TimeStep(bool isEven);
	void write_Data(bool isEven);

private:
	// private methods
	void readInput();
	void initializeDensityData();
	void initializeBCarrays();
	void initializeAdjacency();
	void get_XYZ_gInd(int& x, int& y, int& z, const int gInd);
	void get_gInd_xyz(int& gInd, const int x, const int y, const int z);

	static inline unsigned getIdx(const unsigned nnodes, const unsigned numSpd,
			unsigned nd, unsigned spd)
	{
		//return spd*nnodes+nd; // for nd sequential
		return  nd*numSpd+spd; // for spd sequential
	}

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
	float * fIn;
	float * fOut;

	// boundary condition arrays
	int * inl;
	int * onl;
	int * snl;

	// adjacency array (use getIdx inline to address just like fEven and fOdd
	int * adjacency;

	//input files
	static const std::string params_file_name;
	static const std::string inl_file_name;
	static const std::string onl_file_name;
	static const std::string snl_file_name;

	//output file name stubs
	static const std::string ux_stub;
	static const std::string uy_stub;
	static const std::string uz_stub;
	static const std::string density_stub;
	static const std::string suffix;
	static int dumpCounter;

	// output data areas:
	float * ux;
	float * uy;
	float * uz;
	float * rho;

};



#endif /* LBM_PROBLEM_H_ */
