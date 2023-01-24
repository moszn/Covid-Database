# the compiler to use
CC=g++
CFLAGS=-c -Wall
all: client
client: client.o moviedb.o movieentry.o
	$(CC) client.o moviedb.o movieentry.o -o client 
client.o: client.cpp
	$(CC) $(CFLAGS) client.cpp
moviedb.o: moviedb.cpp
	$(CC) $(CFLAGS) moviedb.cpp
movieentry.o: movieentry.cpp
	$(CC) $(CFLAGS) movieentry.cpp
clean:
	rm -f *o client
 