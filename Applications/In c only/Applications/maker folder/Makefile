file: file.o
	gcc file.o -o file
	rm -f file.o

file.o: file.c
	gcc -c file.c

clean:
	rm -f file
	rm -f file.o