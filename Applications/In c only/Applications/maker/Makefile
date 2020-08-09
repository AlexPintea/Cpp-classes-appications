maker: maker.o
	gcc maker.o -o maker
	rm -f maker.o

maker.o: maker.c
	gcc -c maker.c

clean:
	rm -f maker
	rm -f maker.o