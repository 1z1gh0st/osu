CC=g++
EXE_FILE=lab3

all: $(EXE_FILE)

$(EXE_FILE): card.o deck.o driver.cpp
	$(CC) card.o deck.o driver.cpp -o $(EXE_FILE)

card.o: card.h card.cpp
	$(CC) -c card.cpp

deck.o: deck.h deck.cpp
	$(CC) -c deck.cpp

clean:
	rm –f *.out *.o $(EXE_FILE)