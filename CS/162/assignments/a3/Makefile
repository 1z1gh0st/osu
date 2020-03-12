CC=g++
FLAGS=-std=c++11 -g
EXE_FILE=a3

all: $(EXE_FILE)

$(EXE_FILE): animal.o tiger.o bear.o sea_lion.o zoo.o input_handler.o driver.cpp
	$(CC) $(FLAGS) animal.o tiger.o bear.o sea_lion.o zoo.o input_handler.o driver.cpp -o $(EXE_FILE)

animal.o: animal.h animal.cpp
	$(CC) $(FLAGS) -c animal.cpp

tiger.o: tiger.h tiger.cpp
	$(CC) $(FLAGS) -c tiger.cpp

bear.o: bear.h bear.cpp
	$(CC) $(FLAGS) -c bear.cpp

sea_lion.o: sea_lion.h sea_lion.cpp
	$(CC) $(FLAGS) -c sea_lion.cpp

zoo.o: zoo.h zoo.cpp
	$(CC) $(FLAGS) -c zoo.cpp

input_handler.o: input_handler.h input_handler.cpp
	$(CC) $(FLAGS) -c input_handler.cpp

clean:
	rm -r –f *.out *.o *.dSYM $(EXE_FILE)