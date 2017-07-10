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

private:
	static const int numSpd=19;
	float ex[numSpd];
	float ey[numSpd];
	float ez[numSpd];
	float w[numSpd];
	int bbSpd[numSpd];
	float fEq[numSpd];

};


#endif /* D3Q19LATTICE_H_ */
