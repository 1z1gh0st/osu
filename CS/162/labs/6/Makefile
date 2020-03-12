CC=g++
EXE_FILE=lab6

all: $(EXE_FILE)

$(EXE_FILE): shape.o circle.o rectangle.o square.o driver.cpp
	$(CC) shape.o circle.o rectangle.o square.o driver.cpp -o $(EXE_FILE)

shape.o: shape.h shape.cpp
	$(CC) -c shape.cpp

circle.o: circle.h circle.cpp
	$(CC) -c circle.cpp

rectangle.o: rectangle.h rectangle.cpp
	$(CC) -c rectangle.cpp

square.o: square.h square.cpp
	$(CC) -c square.cpp

clean:
	rm –f *.out *.o $(EXE_FILE)