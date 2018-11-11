try: main.o queue.o stack.o
	gcc main.o stack.o queue.o -Wall -o try

main.o: main.c
	gcc -c main.c -Wall
