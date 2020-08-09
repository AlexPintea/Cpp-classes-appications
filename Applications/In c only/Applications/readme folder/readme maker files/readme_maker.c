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
void readme ( char file[] )
{
	FILE* fo = fopen( "Readme.md", "w");

	fprintf( fo, "%s", file );

	fclose( fo );
}



