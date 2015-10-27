CC=g++ -std=c++11
CFLAGS=-c -g -Wall

all: driver

driver: main.o template_test.o
	$(CC) main.o template_test.o -g -o driver

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

template_test.o: template_test.cpp template_test.h
	$(CC) $(CFLAGS) template_test.cpp

clean:
	rm -f *.o driver