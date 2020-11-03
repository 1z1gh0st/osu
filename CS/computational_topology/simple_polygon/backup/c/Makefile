CC = g++
CFLAGS = -std=c++14 -g -Wall
EXE_FILE = lines

all: $(EXE_FILE)

$(EXE_FILE): point.o line.o angle.o polygon.o main.cpp
	$(CC) $(CFLAGS) point.o line.o angle.o polygon.o main.cpp -o $(EXE_FILE)

point.o: point.cpp point.h
	$(CC) $(CFLAGS) -c point.cpp

line.o: line.cpp line.h point.h angle.h
	$(CC) $(CFLAGS) -c line.cpp

angle.o: angle.cpp angle.h
	$(CC) $(CFLAGS) -c angle.cpp

polygon.o: polygon.cpp line.h
	$(CC) $(CFLAGS) -c polygon.cpp

clean: 
	rm -r -f *.out *.o *.dSYM *.tar $(EXE_FILE)

tar:
	tar -cvf $(EXE_FILE).tar .
