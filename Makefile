CC = clang
CFLAGS = -Wall -Wextra -g

matrixTest: matrixTest.o Matrix.o List.o 
	$(CC) $(CFLAGS) -o matrixTest matrixTest.o Matrix.o List.o

matrixTest.o: matrixTest.c 
	$(CC) $(CFLAGS) matrixTest.c -c 

Matrix.o: Matrix.c Matrix.h
	$(CC) $(CFLAGS) Matrix.c -c 

List.o: List.c List.h
	$(CC) $(CFLAGS) List.c -c

.PHONY: clean
	rm -f *.o matrixTest

