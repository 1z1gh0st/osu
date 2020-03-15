CC=g++
FLAGS=-std=c++11 -g
EXE_FILE=linked_list

all: $(EXE_FILE)

$(EXE_FILE): input_handler.o test.cpp
	$(CC) $(FLAGS) input_handler.o test.cpp -o $(EXE_FILE)

input_handler.o: input_handler.h input_handler.cpp
	$(CC) $(FLAGS) -c input_handler.cpp

clean:
	rm -r –f *.out *.o *.dSYM *.tar.gz $(EXE_FILE)

tar:
	tar -cvf $(EXE_FILE).tar.gz .
