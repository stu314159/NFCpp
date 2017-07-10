/*
 * D3Q19Lattice.h
 *
 *  Created on: Jul 10, 2017
 *      Author: sblair
 */

#ifndef D3Q19LATTICE_H_
#define D3Q19LATTICE_H_

#include "Lattice.h"


class D3Q19Lattice: public Lattice
{
public:
	D3Q19Lattice(const int Nx, const int Ny, const int Nz);
	~D3Q19Lattice();

};


#endif /* D3Q19LATTICE_H_ */
