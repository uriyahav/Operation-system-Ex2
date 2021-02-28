#MAKEFILE
CC=gcc

all: 2_1_1 2_1_2 2_2_1 2_2_2 2_3_1 2_3_2

2_1_1: 2_1_1.c
	$(CC) -pthread -o 2_1_1 2_1_1.c

2_1_2: 2_1_2.c
	$(CC) -pthread -o 2_1_2 2_1_2.c

2_2_1: 2_2_1.c
	$(CC) -pthread -o 2_2_1 2_2_1.c

2_2_2: 2_2_2.c
	$(CC) -pthread -o 2_2_2 2_2_2.c

2_3_1: 2_3_1.c
	$(CC) -pthread -o 2_3_1 2_3_1.c

2_3_2: 2_3_2.c
	$(CC) -pthread -o 2_3_2 2_3_2.c

.PHONY: clean

clean:
	-rm 2_1_1 2_1_2 2_2_1 2_2_2 2_3_1 2_3_2



