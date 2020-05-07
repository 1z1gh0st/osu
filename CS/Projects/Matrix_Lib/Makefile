CC=g++
FLAGS=-std=c++11 -g
EXE_FILE=test
all: $(EXE_FILE)
$(EXE_FILE): matrix.o test.cpp
	$(CC) $(FLAGS) matrix.o test.cpp -o $(EXE_FILE)
matrix.o: matrix.h matrix.cpp
	$(CC) $(FLAGS) -c matrix.cpp
clean:
	rm -r –f *.out *.o *.dSYM *.tar $(EXE_FILE) 
tar: 
	tar -cvf $(EXE_FILE).tar .
