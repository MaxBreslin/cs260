TARGET=main
CC=g++
CFLAGS= --std=c++11 -Wall -g

build: $(TARGET)

$(TARGET): main.o person.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o person.o

main.o: main.cpp main.h stack.h queue.h node.h person.o
	$(CC) $(CFLAGS) -c main.cpp
person.o: person.cpp person.h
	$(CC) $(CFLAGS) -c person.cpp

check:
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(TARGET) main.o person.o