MPI_CC=g++
MPI_FLAGS= -std=c++11 -g

ifeq ($(PE_ENV),PGI)
	MPI_FLAGS= -std=c++11
	MPI_CC=CC
endif

ifeq ($(PE_ENV),CRAY)
	MPI_FLAGS= -std=c++11
	MPI_CC=CC
endif

ifeq ($(PE_ENV),INTEL)
	MPI_FLAGS= -std=c++11
	MPI_CC=CC
endif



SOURCES= Lattice.cpp testMain.cpp D3Q15Lattice.cpp D3Q19Lattice.cpp D3Q27Lattice.cpp LBM_DataHandler.cpp
OBJECTS= Lattice.o  testMain.o D3Q15Lattice.o D3Q19Lattice.o D3Q27Lattice.o LBM_DataHandler.o
LIBS=

TARGET=all
EX_NAME=NFCpp

%.o:%.cpp
	$(MPI_CC) $(MPI_FLAGS) -c $^

$(TARGET): $(OBJECTS)
	$(MPI_CC) $(MPI_FLAGS) -o $(EX_NAME) $^ $(LIBS)

clean:
	rm -f *.o $(TARGET) *~
