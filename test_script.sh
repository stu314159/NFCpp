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
python ./genInput.py sphere.mat $1 200 10 0 20 10 5e-3 0 0

# run the code
aprun -B ./NFCpp

# gold standard is set on output from 10th time step
#python ./validate.py 1

# post-process the output
aprun -n 4 ./NFCpp_postprocess.py

