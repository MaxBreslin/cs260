TARGET = hello
CC = g++
CFLAGS = -Wall -g
OBJS = hello.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

hello.o:
	$(CC) $(CFLAGS) -c hello.cpp

clean:
	rm -f $(TARGET) $(OBJS)
