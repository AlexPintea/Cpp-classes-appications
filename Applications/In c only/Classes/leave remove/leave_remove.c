#include <string.h>
#include <stdio.h>


// !check for ' '



// length of a char[]


int length(char a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}


// empty a char[]


char empty_char[10000] = {};

// empties a char[]
void empty ( char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_char[i];
}




// char




// leave chars in a char[] to leave only $#$%!#
void leave_chars ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= 'a' && a[i] <= 'z' ) || ( a[i] >= 'A' && a[i] <= 'Z' ) || ( a[i] >= '0' && a[i] <= '9' ) ) )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}

void leave_data ( char a[] );

// remove chars in a char[] to leave only 
void remove_chars ( char a[] )
{
	leave_data(a);
}

// leaves numerics in a char[]
void leave_numerics ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= '0' && a[i] <= '9' )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}

// remove numerics in a char[]
void remove_numerics ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( a[i] >= '0' && a[i] <= '9' ) )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}

// leaves data in a char[] ( a, b, 1, 4, 2 etc. )
void leave_data ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( ( a[i] >= '0' && a[i] <= '9' ) || ( a[i] >= 'a' && a[i] <= 'z' ) || ( a[i] >= 'A' && a[i] <= 'Z' ) )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}


// remove data in a char[] ( a, b, 1, 4, 2 etc )
void remove_data ( char a[] )
{
	leave_chars(a);
}



int main()
{




	// leave / remove



	printf( "// chars leave / remove:\n" );
	char leave_chars_char[20] = { '[', '1', 'b', '7', '9', 'l', '&' };
	leave_chars( leave_chars_char );\
	for ( int i=0; i<length(leave_chars_char); i=i+1 )
		printf( "\'%c\'", leave_chars_char[i] );
	printf( "\n" );

	char leave_numerics_char[20] = { '[', '1', 'b', '7', '9', 'l', '&' };
	leave_numerics( leave_numerics_char );\
	for ( int i=0; i<length(leave_numerics_char); i=i+1 )
		printf( "\'%c\'", leave_numerics_char[i] );
	printf( "\n" );

	char leave_data_char[20] = { '[', '1', 'b', '7', '9', 'l', '&' };
	leave_data( leave_data_char );\
	for ( int i=0; i<length(leave_data_char); i=i+1 )
		printf( "\'%c\'", leave_data_char[i] );
	printf( "\n" );



	return 0;
}

