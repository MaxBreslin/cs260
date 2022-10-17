TARGET=main
CC=g++
CFLAGS= --std=c++11 -Wall -g

build: $(TARGET)

$(TARGET): main.o person.o queue.o stack.o node.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o person.o queue.o stack.o node.o

main.o: main.cpp main.h
	$(CC) $(CFLAGS) -c main.cpp
queue.o: queue.cpp queue.h
	$(CC) $(CFLAGS) -c queue.cpp
node.o: node.cpp node.h
	$(CC) $(CFLAGS) -c node.cpp
stack.o: stack.cpp stack.h
	$(CC) $(CFLAGS) -c stack.cpp
person.o: person.cpp person.h
	$(CC) $(CFLAGS) -c person.cpp

check:
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(TARGET) main.o person.o queue.o stack.o node.o