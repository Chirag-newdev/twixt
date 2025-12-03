CC = gcc
CFLAGS = -Wall -Wextra -g

all: twixt

twixt: main.o game.o display.o
	$(CC) $(CFLAGS) -o twixt main.o game.o display.o

main.o: main.c game.h display.h
	$(CC) $(CFLAGS) -c main.c

game.o: game.c game.h
	$(CC) $(CFLAGS) -c game.c

display.o: display.c display.h game.h
	$(CC) $(CFLAGS) -c display.c

clean:
	del /q *.o twixt.exe
