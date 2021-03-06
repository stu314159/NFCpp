#!/bin/bash
# $1 - lattice type
# $2 - OMP num threads
# 
# 1 = D3Q15  
# 2 = D3Q19 
# 3 = D3Q27
#


# pre-process
python ./NFCpp_preprocess.py

# input
python ./genInput.py sphere.mat $1 20 10 0 10 10 5e-3 0 0

# run the code
export OMP_NUM_THREADS=$2
./NFCpp

# gold standard is set on output from 10th time step
# 1st argument: dump number, second argument: lattice type (int)
#python ./validate.py 10 1
# post-process the output
mpirun -np 4 ./NFCpp_postprocess.py

