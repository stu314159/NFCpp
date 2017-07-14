# NFCpp
re-factored Numeric Fluid Channel
Currently working for single processor for all lattice structures on GNU, PGI, Cray, and Intel compilers.

Performance for single thread is acceptable, but not sufficient for production work.  Attempting single-node OpenMP
acceleration to be followed by partitioning and acceleration with MPI.
