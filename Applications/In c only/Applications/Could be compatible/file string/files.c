#include <stdio.h>

char file[] = "filename is in file is that is files";


// length of a string
int length( char word[] )
{
	int	length = 0;
	while ( word[ length ] )
		length = length + 1;

	return length;
}

// sets a file through filename
void set_file ( char filename[], char file[] )
{
	FILE* fo = fopen( filename, "w");

	fprintf( fo, "%s", file );

	fclose( fo );
}



int main ()
{

	char filename[1000] = {0};

	printf( "Filename: " );

	fgets( filename, 90, stdin );
	filename[ length( filename ) - 1 ] = '\0';

	set_file ( filename, file );

	return 0;
}
