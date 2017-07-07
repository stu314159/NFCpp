#ifndef LATTICE_H
#define LATTICE_H

class Lattice{
  public:
    Lattice(const int Nx, const int Ny, const int Nz);
    ~Lattice();

  private:
    const int Nx, Ny, Nz // global lattice size
    // data members that all classes deriving from Lattice must have (and initialize)
    float * ex;
    float * ey;
    float * ez;
    float * w;
    int * bbSpd;
    int numSpd;
}
#endif
