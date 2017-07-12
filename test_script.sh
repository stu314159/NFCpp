#!/bin/bash
# $1 - lattice type
# 
# 1 = D3Q15  
# 2 = D3Q19 
# 3 = D3Q27
#


# pre-process
python ./NFCpp_preprocess.py

# input
python ./genInput.py sphere.mat $1 12 1 0 3 10 1e-2 0 0

# run the code
./NFCpp

# gold standard is set on output from 10th time step
#python ./validate.py 1

# post-process the output
mpirun -np 4 ./NFCpp_postprocess.py

