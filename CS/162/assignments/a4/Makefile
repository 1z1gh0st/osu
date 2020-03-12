CC=g++
FLAGS=-std=c++11 -g
EXE_FILE=a4

all: $(EXE_FILE)

$(EXE_FILE): room.o board.o point.o input_handler.o event.o wumpus.o bats.o pit.o gold.o interactive_obj.o assignment4.cpp
	$(CC) $(FLAGS) room.o board.o point.o input_handler.o event.o wumpus.o bats.o pit.o gold.o interactive_obj.o assignment4.cpp -o $(EXE_FILE)

room.o: room.h room.cpp
	$(CC) $(FLAGS) -c room.cpp

board.o: board.h board.cpp
	$(CC) $(FLAGS) -c board.cpp

point.o: point.h point.cpp
	$(CC) $(FLAGS) -c point.cpp

input_handler.o: input_handler.h input_handler.cpp
	$(CC) $(FLAGS) -c input_handler.cpp

event.o: event.h event.cpp
	$(CC) $(FLAGS) -c event.cpp

wumpus.o: wumpus.h wumpus.cpp
	$(CC) $(FLAGS) -c wumpus.cpp

bats.o: bats.h bats.cpp
	$(CC) $(FLAGS) -c bats.cpp

pit.o: pit.h pit.cpp
	$(CC) $(FLAGS) -c pit.cpp

gold.o: gold.h gold.cpp
	$(CC) $(FLAGS) -c gold.cpp

interactive_obj.o: interactive_obj.h interactive_obj.cpp
	$(CC) $(FLAGS) -c interactive_obj.cpp

clean:
	rm -r –f *.out *.o *.dSYM $(EXE_FILE)