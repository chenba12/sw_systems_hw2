CC = gcc
CFLAGS = -Wall -g

all: connections

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

my_math.o: my_mat.c
	$(CC) $(CFLAGS) -c my_math.c

libmath.a: my_mat.o
	ar -rc libmath.a my_math.o

connections: main.o libmath.a
	$(CC) $(CFLAGS) main.o libmath.a -o connections -lm
clean:
	rm -f  connections *.o *.a
