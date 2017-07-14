#!/bin/bash
# $1 - lattice type
# $2 - omp num threads 
# 1 = D3Q15  
# 2 = D3Q19 
# 3 = D3Q27
#


# pre-process
python ./NFCpp_preprocess.py

# input
python ./genInput.py sphere.mat $1 2000 10 0 200 10 5e-3 0 0

# run the code
export OMP_NUM_THREADS=$2
aprun -n 1 -d $2 ./NFCpp

# gold standard is set on output from 10th time step
#python ./validate.py 1

# post-process the output
#aprun -n 4 ./NFCpp_postprocess.py
python ./processNFC.py

