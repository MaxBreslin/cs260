TARGET=main
CC=g++
CFLAGS= --std=c++11 -Wall -g

build: $(TARGET)

$(TARGET): main.o website.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o website.o

main.o: main.cpp main.h table.h node.h website.o
	$(CC) $(CFLAGS) -c main.cpp
website.o: website.cpp website.h
	$(CC) $(CFLAGS) -c website.cpp

check:
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(TARGET) main.o website.o