#include <string.h>
#include <stdio.h>

int length(char a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}




// for []-s



// a[] && b[] have iters
int is_in ( int a[], int b[], int size, int iter )
{
	for ( int i=0; i<size; i=i+1 )
		if ( iter >= a[i] && iter <= b[i] )
			return 1;

	return 0;
}




// add to []




// add  char  to  char[]  
void add_char ( char chars[], char a )
{
	int size = length( chars );

	chars[ size ] = a;
}




// empty []




char empty_char[10000] = {};

// empties a char[]
void empty ( char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_char[i];
}







// a_is_in_b








// char



// checks if  a  is in  b  for datatype "char"[]
int a_is_in_b ( char a[], char b[] )
{
	int size_a = length(a);
	int size_b = length(b);

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				int verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				int verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "char"[]
int b_is_in_a ( char a[], char b[] )
{
	if ( length(a) < length(b) )
		return 0;

	return a_is_in_b( a, b );
}

// removes  b  in  a  for datatype "char"[]
void remove_b_in_a ( char a[], char b[] )
{
	if ( !b_is_in_a( a, b ) )
		return;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	char result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				int verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	for ( int i=0; i<size_a; i=i+1 )
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			add_char( result, a[i] );

	empty( a );

	int size_result = length(result);

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];
}

// removes  a  in  b   ||   b  in  a  for datatype "char"[]
void remove_a_in_b ( char a[], char b[] )
{
	if ( length(a) > length(b) )
		remove_b_in_a ( a, b );
	else
		remove_b_in_a ( b, a );
}

// counts  b  in  a  for datatype "char"[]
int count_b_in_a ( char a[], char b[] )
{
	if ( !b_is_in_a( a, b ) )
		return -1;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	long result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				int verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	return size_iter;
}

// counts  b  in  a   ||   a  in  b  for datatype "char"[]
int count_a_in_b ( char a[], char b[] )
{
	if ( length(a) > length(b) )
		return count_a_in_b ( a, b );
	else
		return count_a_in_b ( b, a );
}


int main()
{

	// ( info ) b in a is unidirectional 

	// a is in b


	char a_char[20] = { 'a', 'a', 'e', 'r', 'b', 'l', 'm', 'r', 'r', 'a' };
	char b_char[20] = { 'r', 'b', 'l', 'm' };
	printf( "%d\n", a_is_in_b( a_char, b_char ) );
	remove_b_in_a ( a_char, b_char );
	for ( int i=0; i<length(a_char); i=i+1 )
		printf( "\'%c\'", a_char[i] );
	printf( "\n" );

	return 0;
}

