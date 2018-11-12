try: main.o queue.o stack.o ftw.o flags.o
	gcc main.o stack.o queue.o flags.o ftw.o -Wall -o mygrep

ftw.o: ftw.c
	gcc -c ftw.c -Wall

regex.o: regex.c
	gcc -c regex.c -Wall

flags.o: flags.c
	gcc -c flags.c -Wall

main.o: main.c
	gcc -c main.c -Wall
