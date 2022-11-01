TARGET=main
CC=g++
CFLAGS= --std=c++11 -Wall -g

build: $(TARGET)

$(TARGET): main.o dlist.o supplied.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o dlist.o supplied.o

main.o: main.cpp dlist.cpp dlist.h
	$(CC) $(CFLAGS) -c main.cpp
dlist.o: dlist.cpp dlist.h
	$(CC) $(CFLAGS) -c dlist.cpp

check:
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(TARGET) main.o dlist.o