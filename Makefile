try: main.o queue.o stack.o flags.o
	gcc main.o stack.o queue.o flags.o -Wall -o try

flags.o: flags.c flags.h
	gcc -c flags.c -Wall

main.o: main.c
	gcc -c main.c -Wall
