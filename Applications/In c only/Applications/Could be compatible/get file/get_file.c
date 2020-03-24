#include <string.h>
#include <stdio.h>



// length of a string
int length( char word[] )
{
	int	length = 0;
	while ( word[ length ] )
		length = length + 1;

	return length;
}


// gets a file through filename
void get_file ( char filename[], char file[] )
{
	FILE* fi = fopen( filename, "r");

	// gets in file_temp, to make sure size is valid
	char file_temp[1000] = {0};

	char c; // char in which we input file data
	int iter = 0;
	while ( ( c = fgetc(fi) ) != EOF ) // check for EOF
	{
		file_temp[iter] = c;
		iter = iter + 1;
	}

	strcpy( file, file_temp );

	fclose( fi );
}

// sets a file through filename
void set_file ( char filename[], char file[] )
{
	FILE* fo = fopen( filename, "w");

	fprintf( fo, "%s", file );

	fclose( fo );
}

void file ( char filename[] )
{
	char file[1000] = {0};

	get_file( filename, file );
	set_file( filename, file );
}

int main ()
{

	file( "files.c" );


	return 0;
}
