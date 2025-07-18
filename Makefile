CC = gcc
CFLAGS = -O2 -Wall
LDFLAGS = -lraylib

CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

all: main

main: $(OFILES)
	gcc $(CFLAGS) -o $@ $(OFILES) $(LDFLAGS)
	./main

%.o: %.c 
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES) main