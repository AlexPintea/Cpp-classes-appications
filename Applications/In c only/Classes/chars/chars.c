#include <stdio.h>


int length_chars ( char n[] )
{
	int i = 0;

	while ( n[ i ] )
		i = i + 1;

	return i;
}

void sort ( char n[] )
{
	int l = length_chars( n );

	char swap;
	for ( int i1 = 0; i1 < l - 1; i1 = i1 + 1 )
		for ( int i2 = i1 + 1; i2 < l; i2 = i2 + 1 )
			if ( n[ i1 ] > n[ i2 ] )
			{
				swap = n[ i1 ];
				n[ i1 ] = n[ i2 ];
				n[ i2 ] = swap;
			}
}

void sort_desc ( char n[] )
{
	int l = length_chars( n );

	char swap;
	for ( int i1 = 0; i1 < l - 1; i1 = i1 + 1 )
		for ( int i2 = i1 + 1; i2 < l; i2 = i2 + 1 )
			if ( n[ i1 ] < n[ i2 ] )
			{
				swap = n[ i1 ];
				n[ i1 ] = n[ i2 ];
				n[ i2 ] = swap;
			}
}

void swap_char ( char n[], int i1, int i2 )
{
	char swap = n[ i1 ];
	n[ i1 ] = n[ i2 ];
	n[ i2 ] = swap;
}

char max_char ( char n[] )
{
	int l = length_chars( n );

	if ( l == 0 )
		return '\0';

	if ( l == 1 )
		return n[ 0 ];

	char largest = n[ 0 ];

	for ( int i = 1; i < l; i = i + 1 )
		if ( n[ i ] > largest )
			largest = n[ i ];

	return largest;
}

char min_char ( char n[] )
{
	int l = length_chars( n );

	if ( l == 0 )
		return '\0';

	if ( l == 1 )
		return n[ 0 ];

	char smallest = n[ 0 ];

	for ( int i = 1; i < l; i = i + 1 )
		if ( n[ i ] < smallest )
			smallest = n[ i ];

	return smallest;
}

void add_last ( char n[], char i )
{
	n[ length_chars( n ) ] = i;
}

void add_iter ( char n[], char i, int pos )
{
	int l = length_chars( n );

	for ( int i = l - 1; i >= pos; i = i - 1 )
		n[ i + 1 ] = n[ i ];

	n[ pos ] = i;
}

void remove_iter ( char n[], int pos )
{
	int l = length_chars( n );

	if ( pos >= l )
		return;

	for ( int i = pos; i < l; i = i + 1 )
		n[ i ] = n[ i + 1 ];

	n[ l - 1 ] = '\0';
}


int multiple_length ( char* n[] )
{
	int l = 0;

	while ( n[ l ] && n[ l ] != "\0" )
		l = l + 1;

	return l;
}

void add_chars ( char* n[], char added[] )
{
	n[ multiple_length( n ) ] = added;
}

void remove_last ( char* n[] )
{
	n[ multiple_length( n ) - 1 ] = NULL;	
}

void show ( char* n[] )
{
	int l = multiple_length( n );

	for ( int i = 0; i < l; i = i + 1 )
	{
		printf( n[ i ] );
		if ( i != l - 1 )
			printf( ", " );
	}
}



void insert_chars ( char* n[], char insert[], int pos )
{
	int l = multiple_length( n );

	if ( pos >= l )
		return;

	for ( int i = l - 1; i >= pos; i = i - 1 )
		n[ i + 1 ] = n[ i ];

	n[ pos ] = insert;
}

void remove_chars ( char* n[], int pos )
{
	int l = multiple_length( n );

	if ( pos >= l )
		return;

	for ( int i = pos; i < l; i = i + 1 )
		n[ i ] = n[ i + 1 ];

	n[ l - 1 ] = NULL;
}



int compare ( char l1[], char l2[] )
{
	int i = 0;

	while ( l1[ i ] && l2[ i ] )
	{
		if ( l1[ i ] > l2[ i ] )
			return 1;
		if ( l1[ i ] < l2[ i ] )
			return -1;
		i = i + 1;
	}

	if ( l1[ i ] && ! l2[ i ] )
		return 1;
	if ( ! l1[ i ] && l2[ i ] )
		return -1;

	return 0;
}

char* max_chars ( char* n[] )
{
	int l = multiple_length( n );

	if ( l == 0 )
		return NULL;

	if ( l == 1 )
		return n[ 0 ];

	char* largest = n[ 0 ];

	for ( int i = 1; i < l; i = i + 1 )
		if ( compare( n[ i ] , largest ) == 1 )
			largest = n[ i ];

	return largest;
}

char* min_chars ( char* n[] )
{
	int l = multiple_length( n );

	if ( l == 0 )
		return NULL;

	if ( l == 1 )
		return n[ 0 ];

	char* smallest = n[ 0 ];

	for ( int i = 1; i < l; i = i + 1 )
		if ( compare( n[ i ] , smallest ) == -1 )
			smallest = n[ i ];

	return smallest;
}

int get_iter ( char* n[], char get[] )
{
	int l = multiple_length( n );

	for ( int i = 0; i < l; i = i + 1 )
		if ( n[ i ] == get )
			return i;

	return -1;
}

int get_last_iter ( char* n[], char get[] )
{
	int l = multiple_length( n );

	for ( int i = l - 1; i >= 0; i = i - 1 )
		if ( n[ i ] == get )
			return i;

	return -1;
}





int main ()
{
//	printf( "where " );

//	printf( "strng " );


	char n[] = "42351";
	// finalised with 0

	// char n[ 6 ] = "42351\0";
	// has to be finalised with 0

	sort( n );
	printf( "sort: %s\n", n );

	sort_desc( n );
	printf( "sort_desc: %s\n", n );

	swap_char( n, 2, 4 );
	printf( "swap_char: %s\n", n );

	// char* z[] = { "12", "23", "34", "45", "56", "67", "78", "89" };
	// does not finalise itself with 0, gives Segm. Fault if above length - 1

	char* z[ 45 ] = { "12", "23", "34", "45", "56", "67", "89", "89" };
	// char* z[ 9 ] = { "12", "23", "34", "45", "56", "67", "78", "89" };
	// every ininitialised string above length becomes 0

	// char* z[] = { "12", "23", "34", "45", "56", "67", "78", "89", NULL };
	// has to be finalised with 0
	printf( "swap_char: %d\n", multiple_length( z ) );

	int l2;

	add_chars( z, n );
	printf( "add_chars: %s\n", z[ multiple_length( z ) - 1 ] );
	
	remove_last( z );
	printf( "remove_last: %s\n", z[ multiple_length( z ) - 1 ] );

	insert_chars( z, n, 5 );
	printf( "insert_chars: " );
	show( z );
	printf( "\n" );

	remove_chars( z, 5 );
	printf( "remove_chars: " );
	show( z );
	printf( "\n" );

	printf( "max_chars: %s\n", max_chars( z ) );
	printf( "get_iter: %d\n", get_iter( z, "67" ) );
	printf( "get_last_iter: %d\n", get_last_iter( z, "67" ) );

	// get every iter of ar

	return 0;	
}
