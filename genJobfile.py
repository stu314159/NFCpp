#genJobfile.py
"""
more-or-less automated generation of PBS jobfile
"""

import argparse

parser = argparse.ArgumentParser(prog="genJobfile.py",
                                description="PBS Jobfile generation script.")

parser.add_argument('jobfileName',type=str)
parser.add_argument('jobName',type=str)
parser.add_argument('nnodes',type=int)
parser.add_argument('ppn',type=int)
parser.add_argument('mpi_procs_per_node',type=int)
parser.add_argument('omp_numthread_per_node',type=int)
parser.add_argument('runtimeNumHours',type=int)
parser.add_argument('queue',type=str)
parser.add_argument('latticeType',type=int)


# parse input arguments
args = parser.parse_args()

# assign to the variables

jobfileName = args.jobfileName
jobName = args.jobName
nnodes = args.nnodes
ppn = args.ppn
mpi_procs_per_node = args.mpi_procs_per_node
omp_num_threads = args.omp_numthread_per_node
runtimeNumHours = args.runtimeNumHours
queue = args.queue
latticeType = args.latticeType


executableName = 'NFCpp'

filesToCopy = ['NFCpp','genInput.py','FluidChannel.py',  'validate.py', 'vtkHelper.py', 'test_script.sh',
               'NFCpp_preprocess.py','NFCpp_postprocess.py','gen_gold_standard.py']



if runtimeNumHours < 10:
    walltime = "0%d:00:00"%runtimeNumHours
else:
    walltime = "%d:00:00"%runtimeNumHours # may be a problem if runtime > 99 hours
    
mpi_procs = mpi_procs_per_node*nnodes

jobfileName = "%s.pbs"%(jobfileName)
#--------- more-or-less fixed code below -----------------

proj_id = 'USNAM37752431'

# open the file
jf = open(jobfileName,'w')

# essential PBS directives
jf.write('#!/bin/bash \n') # the shell
jf.write('#PBS -A %s \n'%proj_id) # project identifier
jf.write('#PBS -q %s \n'%queue) # specify queue
jf.write('#PBS -l select=%d:ncpus=%d:mpiprocs=%d:ompthreads=%d \n'% \
         (nnodes,ppn,mpi_procs_per_node,omp_num_threads))
jf.write('#PBS -l walltime=%s \n'%walltime)
jf.write('#PBS -l ccm=1 \n') # specify cluster compatibility mode.  Why wouldn't you?

#optional PBS directives
jf.write('#PBS -N %s \n'%jobName)
jf.write('#PBS -j oe \n')
#jf.write('#PBS -V \n')
jf.write('#PBS -S /bin/bash \n')


# Execution block
jf.write('cd $WORKDIR\n')
jf.write("JOBID=`echo $PBS_JOBID | cut -d '.' -f 1` \n")
jf.write('if [ ! -d $JOBID ]; then \n')
jf.write('  mkdir -p $JOBID \n')

jf.write('fi \n')
jf.write('cd $JOBID \n')
# copy files 
for s in filesToCopy:
    jf.write('cp $PBS_O_WORKDIR/%s . \n'% s)

## move to the $JOBDIR
#jf.write('cd $JOBDIR \n')  #<--- this was an error

# invoke execution
#jf.write('module swap PrgEnv-cray PrgEnv-intel\n')
jf.write('module load costinit\n')
jf.write('module load python\n')
jf.write('module load numpy\n')
jf.write('module load scipy\n')
jf.write('module load mpi4py\n')
jf.write('export OMP_NUM_THREADS=%d\n'%omp_num_threads)
jf.write('./test_script.sh %d %d\n'%(latticeType,omp_num_threads))
jf.close()
