CC = gcc
CFLAGS = -g -Wall -std=c99

all : final 

final : main.o hashMap.o
	$(CC) $(CFLAGS) -o $@ $^

main.o : main.c hashMap.h

hashMap.o : hashMap.h hashMap.c

.PHONY : clean memCheckTests memCheckProg

clean :
	-rm *.o
	-rm final
