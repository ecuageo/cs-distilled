# Makefile for stack

CC = gcc
CFLAGS = -Wall -g

current: main

#
# main - used to try out check test framework
#

main: main.o implementation.o
	$(CC) $(CFLAGS) -o main main.o implementation.o

main.o: main.c implementation.h
	$(CC) $(CFLAGS) -c main.c

implementation.o: implementation.c implementation.h
	$(CC) $(CFLAGS) -c implementation.c

#
# markov chain
#

markov: markov.c
	$(CC) $(CFLAGS) -o markov markov.c

#
# hashing - CURRENTLY BROKEN
#

hashtest: hashtest.o hash.o
	$(CC) $(CFLAGS) -o hashtest hashtest.o hash.o

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

hashtest.o: hashtest.c hash.h
	$(CC) $(CFLAGS) -c hashtest.c

#
# Sorting with quicksort
#

quicksorttest: quicksorttest.o quicksort.o
	$(CC) $(CFLAGS) -o quicksorttest quicksorttest.o quicksort.o

quicksorttest.o: quicksorttest.c quicksort.h
	$(CC) $(CFLAGS) -c quicksorttest.c

quicksort.o: quicksort.c quicksort.h
	$(CC) $(CFLAGS) -c quicksort.c

#
# linked list stacks
#

llstacktest: llstacktest.o llstack.o
	$(CC) $(CFLAGS) -o llstacktest llstacktest.o llstack.o

llstacktest.o: llstacktest.c llstack.h
	$(CC) $(CFLAGS) -c llstacktest.c

llstack.o: llstack.c llstack.h
	$(CC) $(CFLAGS) -c llstack.c

# 
# stacks
#

stacktest: stacktest.o stack.o
	$(CC) $(CFLAGS) -o stacktest stacktest.o stack.o

stacktest.o: stacktest.c stack.h
	$(CC) $(CFLAGS) -c stacktest.c

stack.o: stack.c stack.h
	$(CC) $(CFLAGS) -c stack.c

# 
# queues
#

queuetest: queuetest.o queue.o
	$(CC) $(CFLAGS) -o queuetest queuetest.o queue.o

queuetest.o: queuetest.c queue.h
	$(CC) $(CFLAGS) -c queuetest.c

queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c

#
# utils: clean
#

clean:
	rm -f *.o
	rm -f queuetest
	rm -f stacktest

