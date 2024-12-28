CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=c99 -g

.PHONY: clean

all: 
	$(CC) $(CFLAGS) -c ./dict.c ./dict_helpers.c ./string.c ./helpers.c ./main.c
	$(CC) $(CFLAGS) -o dictionary *.o

clean:
	rm -rf dictionary *.o
