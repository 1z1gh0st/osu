CC=g++
FLAGS=-std=c++11 -g
EXE_FILE=a2

all: $(EXE_FILE)

$(EXE_FILE): card.o deck.o hand.o player.o game.o input_handler.o driver.cpp
	$(CC) $(FLAGS) card.o deck.o hand.o player.o game.o input_handler.o driver.cpp -o $(EXE_FILE)

card.o: card.h card.cpp
	$(CC) $(FLAGS) -c card.cpp

deck.o: deck.h deck.cpp
	$(CC) $(FLAGS) -c deck.cpp

hand.o: hand.h hand.cpp
	$(CC) $(FLAGS) -c hand.cpp

player.o: player.h player.cpp
	$(CC) $(FLAGS) -c player.cpp

game.o: game.h game.cpp
	$(CC) $(FLAGS) -c game.cpp

input_handler.o: input_handler.h input_handler.cpp
	$(CC) $(FLAGS) -c input_handler.cpp


clean:
	rm –f *.out *.o $(EXE_FILE)