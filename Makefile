CC = gcc
CFLAGS = -g -Wall -std=c99 -D_DEFAULT_SOURCE

gps: main.o interface.o bike.o dir.o utils.o
	$(CC) main.o interface.o bike.o dir.o utils.o -o gps 

*.o: *.c
	$(CC) $(CFLAGS) -c *.c

clean:
	rm *.o

purge: clean
	rm gps
