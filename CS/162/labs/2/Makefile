CC=g++
EXE_FILE=lab2

all: $(EXE_FILE)

$(EXE_FILE): lab2.o file_io.h prog.cpp
	$(CC) lab2.o prog.cpp -o $(EXE_FILE)

lab2.o: file_io.h lab2.cpp
	$(CC) -c lab2.cpp