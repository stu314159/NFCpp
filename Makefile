MPI_CC=g++

ifeq ($(PE_ENV),PGI)
	MPI_FLAGS=
	MPI_CC=CC
endif

ifeq ($(PE_ENV),CRAY)
	MPI_FLAGS=
	MPI_CC=CC
endif

ifeq ($(PE_ENV),INTEL)
	MPI_FLAGS=
	MPI_CC=CC
endif



SOURCES= Lattice.cpp
OBJECTS= Lattice.o
LIBS=

TARGET=NFCpp

%.o:%.cpp
	$(MPI_CC) $(MPI_FLAGS) -c $^

$(TARGET): $(OBJECTS)
	$(MPI_CC) $(MPI_FLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o $(TARGET) *~
