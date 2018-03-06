CC = g++
CFLAGS = -Wall -Werror -ansi -pedantic
DEBUG = $(CFLAGS) += -ggdb

all: main rshell command connector rshellcontainer
	mkdir -p bin
	$(CC) $(CFLAGS) main.o rshell.o command.o connector.o rshellcontainer.o -o ./bin/rshell
main:
	$(CC) $(CFLAGS) -c ./src/main.cpp
rshell:
	$(CC) $(CFLAGS) -c ./src/rshell.cc
command:
	$(CC) $(CFLAGS) -c ./src/command.cc
connector:
	$(CC) $(CFLAGS) -c ./src/connector.cc
rshellcontainer:
	$(CC) $(CFLAGS) -c ./src/rshellcontainer.cc
clean:
	rm -r *.o