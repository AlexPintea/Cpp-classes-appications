#include <stdio.h>



void show_ints ( int n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%d", n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_longs ( long n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%d", n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_floats ( float n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%g", n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_doubles ( double n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%g", n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_chars ( char n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%c", n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_ints_sep ( int n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%d", n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_longs_sep ( long n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%d", n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_floats_sep ( float n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%g", n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_doubles_sep ( double n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%g", n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_chars_sep ( char n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "%c", n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_ints_iter (int n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %d", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_longs_iter (long n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %d", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_floats_iter (float n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %g", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_doubles_iter (double n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %g", i, n[ i ] );
		if ( n[ i + 1 ] )
				printf( ", " );
		i = i + 1;
	}
}

void show_chars_iter (char n[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %c", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( ", " );
		i = i + 1;
	}
}

void show_ints_sep_iter (int n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %d", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_longs_sep_iter (long n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %d", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_floats_sep_iter (float n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %g", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_doubles_sep_iter (double n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %g", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}

void show_chars_sep_iter (char n[], char l[] )
{
	int i = 0;

	while ( n[ i ] )
	{
		printf( "[%d]: %c", i, n[ i ] );
		if ( n[ i + 1 ] )
			printf( l );
		i = i + 1;
	}
}







// void get_chars ( char n[] )
// {
//	int i = 0;
//	while ( n[ i ] )
//		i = i + 1;
//
//	gets( n, i, stdin );
// }

void get_chars ( char n[] )
{
	int i = 0;
	while ( n[ i ] )
		i = i + 1;

	fgets( n, i, stdin );

	n[ i - 1 ] = '\0';
}

void ln ()
{
	printf( "\n" );
}

void lns ( int l )
{
	for ( int i = 0; i < l; i = i + 1 )
		printf( "\n" );
}

void rep ( char n[], int l )
{
	for ( int i = 0; i < l; i = i + 1 )
		printf( n );
}

void set ( char n[] )
{
	printf( n );
}

void clr ()
{
	printf( "\n" );	
}

void show_formats ( int l ) // for every type
{
	printf( "%d\n", l );
	printf( "%e\n", l );
	// have formats
}





int main ()
{
//	printf( "get " );

	int n;

	float l2;

	int ints[ 6 ] = { 6, 15, 8, 9, 10 };
	long longs[ 6 ] = { 6, 15, 8, 9, 10 };
	float floats[ 6 ] = { 6.5, 15, 8, 9, 10 };
	double doubles[ 6 ] = { 6.5, 15, 8, 9, 10 };
	char chars[ 6 ] = { 'c', 'h', 'a', 'r', 's' };

	show_ints( ints );
	printf( "\n" );

	show_longs( longs );
	printf( "\n" );

	show_floats( floats );
	printf( "\n" );

	show_doubles( doubles );
	printf( "\n" );

	show_chars( chars );
	printf( "\n" );

	show_ints_sep( ints, " - " );
	printf( "\n" );

	show_longs_sep( longs, " - " );
	printf( "\n" );

	show_floats_sep( floats, " - " );
	printf( "\n" );

	show_doubles_sep( doubles, " - " );
	printf( "\n" );

	show_chars_sep( chars, " - " );
	printf( "\n" );


	show_ints_iter( ints );
	printf( "\n" );

	show_longs_iter( longs );
	printf( "\n" );

	show_floats_iter( floats );
	printf( "\n" );

	show_doubles_iter( doubles );
	printf( "\n" );

	show_chars_iter( chars );
	printf( "\n" );

	show_ints_sep_iter ( ints, " - " );
	printf( "\n" );

	show_longs_sep_iter ( longs, " - " );
	printf( "\n" );

	show_floats_sep_iter ( floats, " - " );
	printf( "\n" );

	show_doubles_sep_iter ( doubles, " - " );
	printf( "\n" );

	show_chars_sep_iter ( chars, " - " );
	printf( "\n" );


//	char get_chrs[ 1000 ];
//	get_chars( get_chrs );
//	show_chars( get_chrs );
//	printf( "\n" );

	show_formats( 5 );
	

	return 0;
}
