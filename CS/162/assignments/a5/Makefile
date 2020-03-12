CC=g++
FLAGS=-std=c++11 -g
EXE_FILE=test_ll

all: $(EXE_FILE)

$(EXE_FILE): linked_list.o input_handler.o test.cpp
	$(CC) $(FLAGS) linked_list.o input_handler.o test.cpp -o $(EXE_FILE)

linked_list.o: linked_list.h linked_list.cpp
	$(CC) $(FLAGS) -c linked_list.cpp

input_handler.o: input_handler.h input_handler.cpp
	$(CC) $(FLAGS) -c input_handler.cpp

clean:
	rm -r –f *.out *.o *.dSYM $(EXE_FILE)