CC=g++
EXE_FILE=lab1

all: $(EXE_FILE)

$(EXE_FILE): lab1.o mult_div.h prog.cpp
	$(CC) lab1.o prog.cpp -o $(EXE_FILE)

lab1.o: mult_div.h lab1.cpp
	$(CC) -c lab1.cpp