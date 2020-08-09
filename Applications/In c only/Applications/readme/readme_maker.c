#include <stdio.h>

char readme_string[] = "# Readme\n\nApplication does that.";


// length of a string
int length( char word[] )
{
	int	length = 0;
	while ( word[ length ] )
		length = length + 1;

	return length;
}

// sets a file through filename
void readme ( char filename[], char file[] )
{
	FILE* fo = fopen( filename, "w");

	fprintf( fo, "%s", file );

	fclose( fo );
}



int main ()
{

	readme ( "Readme.md", readme_string );

	return 0;
}
