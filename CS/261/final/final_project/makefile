CC = gcc
CFLAGS = -g -Wall -std=c99

all : final 

final : main.o hashMap.o userInput.o
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.c hashMap.h

hashMap.o : hashMap.h hashMap.c

userInput.o : userInput.h userInput.c

clean :
	-rm *.o
	-rm final
