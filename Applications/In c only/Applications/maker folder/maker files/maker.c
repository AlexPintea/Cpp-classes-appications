#include <stdio.h>



// length of a string
int length( char word[] )
{
	int	length = 0;
	while ( word[ length ] )
		length = length + 1;

	return length;
}

// sets a file through filename
void makefile ( char filename[] )
{
	FILE* fo = fopen( "Makefile", "w");

	fprintf( fo, "%s: %s.o\n", filename, filename );
	fprintf( fo, "	gcc %s.o -o %s\n", filename, filename );
	fprintf( fo, "	rm -f %s.o\n\n", filename );
	fprintf( fo, "%s.o: %s.c\n", filename, filename );
	fprintf( fo, "	gcc -c %s.c\n\n", filename );
	fprintf( fo, "clean:\n" );
	fprintf( fo, "	rm -f %s\n", filename );
	fprintf( fo, "	rm -f %s.o", filename );

	fclose( fo );
}
