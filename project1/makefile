TARGET=main
CC=g++
CFLAGS= --std=c++11 -Wall -g

$(TARGET): main.o songlist.o node.o song.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o songlist.o node.o song.o

main.o: main.cpp main.h songlist.h
	$(CC) $(CFLAGS) -c main.cpp
songlist.o: songlist.cpp songlist.h node.h
	$(CC) $(CFLAGS) -c songlist.cpp
node.o: node.cpp node.h song.h
	$(CC) $(CFLAGS) -c node.cpp
song.o: song.cpp song.h
	$(CC) $(CFLAGS) -c song.cpp

check:
	valgrind --leak-check=full ./$(TARGET)

clean:
	rm $(TARGET)