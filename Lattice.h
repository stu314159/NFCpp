#ifndef LATTICE_H
#define LATTICE_H

class Lattice{
  public:
    Lattice(const int Nx, const int Ny, const int Nz);
    virtual ~Lattice();
    // "getter functions for lattice variables"
    int getNx(){return Nx;}
    int getNy(){return Ny;}
    int getNz(){return Nz;}
    float * get_ex(){return ex;}
    float * get_ey(){return ey;}
    float * get_ez(){return ez;}
    float * get_w(){return ez;}
    int * get_bb(){return bbSpd;}
    // common functions for LBM stream/collide tasks
    void computeMacroscopicData(float& rho,float& ux, float& uy, float& uz,
    		                    const float * f, const int numSpd,
    		                    const float * ex, const float * ey, const float * ez);
    // declarations for lattice variables common to all subclasses
    float ux,uy,uz,rho; //macroscopic data variables
    float rho_bc,u_bc; // macroscopic boundary conditions
    float * ex;
    float * ey;
    float * ez;
    float * w;
    int * bbSpd;



  private:
    const int Nx, Ny, Nz; // global lattice size
    // data members that all classes deriving from Lattice must have (and initialize)


};
#endif
