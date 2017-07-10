MPI_CC=g++
MPI_FLAGS= -std=c++11

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



SOURCES= Lattice.cpp testMain.cpp D3Q15Lattice.cpp D3Q19Lattice.cpp D3Q27Lattice.cpp
OBJECTS= Lattice.o  testMain.o D3Q15Lattice.o D3Q19Lattice.o D3Q27Lattice.o
LIBS=

TARGET=NFCpp

%.o:%.cpp
	$(MPI_CC) $(MPI_FLAGS) -c $^

$(TARGET): $(OBJECTS)
	$(MPI_CC) $(MPI_FLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o $(TARGET) *~
