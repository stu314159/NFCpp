#ifndef LATTICE_H
#define LATTICE_H

class Lattice{
  public:
    Lattice(const int Nx, const int Ny, const int Nz);
    virtual ~Lattice();
    int getNx(){return Nx;}
    int getNy(){return Ny;}
    int getNz(){return Nz;}


  private:
    const int Nx, Ny, Nz; // global lattice size
    // data members that all classes deriving from Lattice must have (and initialize)


};
#endif
