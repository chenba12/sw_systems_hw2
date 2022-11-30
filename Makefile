CC = gcc
CFLAGS = -Wall -g
.PHONY: all clean
all: connections my_mat.o main.o libmy_mat.a

my_mat.o: my_mat.c
	$(CC) $(CFLAGS) -c my_mat.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

libmy_mat.a: my_mat.o
	ar -rc libmy_mat.a my_mat.o

connections: main.o libmy_mat.a
	$(CC) $(CFLAGS) main.o libmy_mat.a -o connections -lm
clean:
	rm -f  connections *.o *.a
