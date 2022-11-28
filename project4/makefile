TARGET=main
CC=g++
CFLAGS= --std=c++11 -Wall -g

build: $(TARGET)

$(TARGET): main.o website.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o website.o string.o

main.o: main.cpp main.hpp avltree.hpp avltreenode.hpp list.hpp website.o
	$(CC) $(CFLAGS) -c main.cpp
website.o: website.cpp website.hpp string.o
	$(CC) $(CFLAGS) -c website.cpp
string.o: string.cpp string.hpp
	$(CC) $(CFLAGS) -c string.cpp

check:
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(TARGET) main.o website.o string.o