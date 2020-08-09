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

char empty[1000] = {};

void empty_chars ( char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty[i];
}


void invert_chars ( char a[] )
{
	int size = length(a);
	char result[1000] = {};

	for ( int i=0; i<size; i=i+1 )
		result[ size - i - 1 ] = a[i];

	empty_chars( a );

	for ( int i=0; i<size; i=i+1 )
		a[i] = result[i];	
}

// converts a long to a char array
void long_to_chars ( long a, char digits[] ) 
{
	int i=0;
	while ( a != 0 )
	{
		char a_char = (char) ( a % 10 + 48 );

		digits[ i ] = a_char;

		a = a / 10;

		i = i + 1;
	}
	digits[i] = '\0';

	invert_chars( digits );
}

// convert char to long
long char_to_long ( char a[] )
{
	if ( length( a ) == 1 )
		return a[0] - 48;

	int size = length( a );

	int iter = 0;
	int is_neg = 0;
	if ( a[0] == '-' )
	{
		is_neg = 1;
		iter = 1;
	}

	long num_long = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_long = num_long * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_long = -num_long;

	return num_long;
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

// adds to a file through filename
void add_to_file ( char filename[], char add[] )
{
	char file_temp[1000] = {0};
	get_file ( filename, file_temp );


	FILE* fo = fopen( filename, "w");

	fprintf( fo, "%s", file_temp );
	fprintf( fo, "%s", add );

	fclose( fo );
}

void count ( char filename[] )
{
	long counter = 0;

	char counter_chars[90];
	get_file( filename, counter_chars );

	counter = char_to_long( counter_chars );
	counter = counter + 1;

	long_to_chars( counter, counter_chars );
	set_file( filename, counter_chars );
}

long get_count ( char filename[] )
{
	long counter = -1;

	char counter_chars[90];
	get_file( filename, counter_chars );

	counter = char_to_long( counter_chars );

	return counter;
}

int main ()
{

	count( "filename" );
	int counter = get_count( "filename" );
	printf( "%d\n", counter );

	return 0;
}
