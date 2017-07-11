/*
 * LBM_Problem.cpp
 *
 *  Created on: Jul 11, 2017
 *      Author: sblair
 */


#include "LBM_Problem.h"
#include <fstream>
#include <stdexcept>

const std::string LBM_Problem::params_file_name="params.lbm";
const std::string LBM_Problem::snl_file_name="snl.lbm";
const std::string LBM_Problem::inl_file_name="inl.lbm";
const std::string LBM_Problem::onl_file_name="onl.lbm";

LBM_Problem::LBM_Problem()
{
	readInput();
}

LBM_Problem::~LBM_Problem()
{

}

void LBM_Problem::readInput()
{
	std::ifstream input_params(params_file_name.c_str(),std::ios::in);
	if(!input_params.is_open())
		throw std::runtime_error("Could not open params file!");
	input_params >> lattice_type;
	input_params >> Num_ts;
	input_params >> ts_rep_freq;
	input_params >> Warmup_ts;
	input_params >> plot_freq;
	input_params >> Cs;
	input_params >> rho_lbm;
	input_params >> u_lbm;
	input_params >> omega;
	input_params >> Nx;
	input_params >> Ny;
	input_params >> Nz;
	input_params >> Restart;
	input_params.close();


}
