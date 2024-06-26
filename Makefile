CC = gcc
CFLAGS = -g -Wall
LDLIBS = -lslang

slmatch: slmatch.c

clean:
	rm -f slmatch
