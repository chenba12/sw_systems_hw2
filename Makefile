CC = gcc
CFLAGS = -Wall -g

all: connections

my_mat.o: my_mat.c
	$(CC) $(CFLAGS) -c my_mat.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

libmat.a: my_mat.o
	ar -rc libmat.a my_mat.o

connections: main.o libmat.a
	$(CC) $(CFLAGS) main.o libmat.a -o connections -lm
clean:
	rm -f  connections *.o *.a
