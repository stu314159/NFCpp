#ifndef LATTICE_H
#define LATTICE_H

class Lattice{
  public:
    Lattice(const int Nx, const int Ny, const int Nz);
    virtual ~Lattice();
    // "setter/getter functions for lattice variables"
    int getNx(){return Nx;}
    int getNy(){return Ny;}
    int getNz(){return Nz;}
    void setNumSpd(const int ns){numSpd=ns;}
    int getNumSpd(){return numSpd;}
    void setEx(float * x){ex = x;}
    void setEy(float * y){ey = y;}
    void setEz(float * z){ez = z;}
    void setW(float * tw){w = tw;}
    void setBBspd(int* BB){bbSpd = BB;}
    void setFeq(float * feq){fEq = feq;}
    float * get_ex(){return ex;}
    float * get_ey(){return ey;}
    float * get_ez(){return ez;}
    float * get_w(){return ez;}
    int * get_bb(){return bbSpd;}
    // common functions for LBM stream/collide tasks
    void computeMacroscopicData(float& rho,float& ux, float& uy, float& uz,
    		                    const float * f);
    void computeEquilibrium(float * fEq);
    // declarations for lattice variables common to all subclasses




  private:
    const int Nx, Ny, Nz; // global lattice size
    // data members that all classes deriving from Lattice must have (and initialize)
    int numSpd;
    float ux,uy,uz,rho; //macroscopic data variables
    float rho_bc,u_bc; // macroscopic boundary conditions
    float * ex;
    float * ey;
    float * ez;
    float * w;
    int * bbSpd;
    float * fEq;

};
#endif
