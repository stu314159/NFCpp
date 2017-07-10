/*
 * D3Q27Lattice.h
 *
 *  Created on: Jul 10, 2017
 *      Author: sblair
 */

#ifndef D3Q27LATTICE_H_
#define D3Q27LATTICE_H_
#include "Lattice.h"

class D3Q27Lattice: public Lattice
{
public:
	D3Q27Lattice(const int Nx, const int Ny, const int Nz);
	~D3Q27Lattice();
};




#endif /* D3Q27LATTICE_H_ */
