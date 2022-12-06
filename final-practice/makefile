TARGET=main
CC=g++
CFLAGS= --std=c++11 -Wall -g

build: $(TARGET)

$(TARGET): main.o table.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o table.o supplied.o

main.o: main.cpp table.o
	$(CC) $(CFLAGS) -c main.cpp
table.o: table.cpp table.h
	$(CC) $(CFLAGS) -c table.cpp

check:
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(TARGET) main.o table.o