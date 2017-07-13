MPI_CC=g++
MPI_FLAGS= -std=c++11 -O3 -Wall

ifeq ($(PE_ENV),PGI)  ## requires module swap pgi/14.3.0 pgi/15.10.0
	MPI_FLAGS= -std=c++11 -g -O0 -Mbounds
	MPI_CC=CC
endif

ifeq ($(PE_ENV),CRAY)
	MPI_FLAGS= -h std=c++11 -g -O0 
	MPI_CC=CC
endif

ifeq ($(PE_ENV),INTEL)
	MPI_FLAGS= -std=c++11 -O2 -Wall -xHost 
	MPI_CC=CC
endif



SOURCES= Lattice.cpp testMain.cpp D3Q15Lattice.cpp D3Q19Lattice.cpp D3Q27Lattice.cpp \
	LBM_DataHandler.cpp LBM_Problem.cpp
OBJECTS= Lattice.o  testMain.o D3Q15Lattice.o D3Q19Lattice.o D3Q27Lattice.o \
	LBM_DataHandler.o LBM_Problem.o
LIBS=

TARGET=all
EX_NAME=NFCpp

%.o:%.cpp
	$(MPI_CC) $(MPI_FLAGS) -c $^

$(TARGET): $(OBJECTS)
	$(MPI_CC) $(MPI_FLAGS) -o $(EX_NAME) $^ $(LIBS)

clean:
	rm -f *.o $(TARGET) *~
