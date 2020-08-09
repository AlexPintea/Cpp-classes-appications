#include <string.h>
#include <stdio.h>


int length(int a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int empty[1000] = {};

void empty_ints ( int a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty[i];
}

void invert_ints ( int a[] )
{
	int size = length(a);
	int result[1000] = {};

	for ( int i=0; i<size; i=i+1 )
		result[ size - i - 1 ] = a[i];

	empty_ints( a );

	for ( int i=0; i<size; i=i+1 )
		a[i] = result[i];	
}





void digits_int ( int a, int digits[] ) 
{
	int i=0;
	while ( a != 0 )
	{
		digits[ i ] = a % 10;

		a = a / 10;

		i = i + 1;
	}
	digits[i] = '\0';

	invert_ints( digits );
}


void digits_long ( long a, int digits[] ) 
{
	int i=0;
	while ( a != 0 )
	{
		digits[ i ] = a % 10;

		a = a / 10;

		i = i + 1;
	}
	digits[i] = '\0';

	invert_ints( digits );
}


void digits_double ( double a, int digits[] ) 
{
	// gets digit of   (long) a   into   char digits[]
	digits_long( (long) a, digits );
	int size = length( digits );

	// gets decimals of a as long in   a_long   
	a = a - (long) a;
	for ( int i=0; i<=7; i=i+1 )
		a = a * 10;
	long a_long = (long) a;


	// gets digits of  a_long  ( decimals of  a  )  into   char decimals[]   
	int decimals[ 90 ];

	int i=0;
	int is_lasts = 1;
	while ( a_long != 0 )
	{
		char a_digit = a_long % 10;

		if ( a_digit != 0 )
			is_lasts = 0;

		if ( a_digit == 0 && is_lasts == 1 )
		{
			a_long = a_long / 10;
			continue;
		}

		decimals[ i ] = a_digit;
		i = i + 1;

		a_long = a_long / 10;
	}
	decimals[i] = '\0';

	// adds  decimals[]  to  digits[]  
	int size_decimals = length( decimals );

	invert_ints( decimals );

	for ( int i=0; i<size_decimals; i=i+1 )
		digits[ size + i ] = decimals[i];

	digits[ size + size_decimals ] = '\0';
}






int main ()
{


	int a_digits[90];

	int a_int = 17; // 17041 does not return validly
	digits_int( a_int, a_digits );
	for ( int i=0; i<length( a_digits ); i=i+1 )
		printf( "%d ", a_digits[i] );
	printf( "\n" );

	long a_long = 19999999999; // 17041 does not return validly
	digits_long( a_long, a_digits );
	for ( int i=0; i<length( a_digits ); i=i+1 )
		printf( "%d ", a_digits[i] );
	printf( "\n" );

	double a_double = 1741.91; // 17041.901 does not return validly
	digits_double( a_double, a_digits );
	for ( int i=0; i<length( a_digits ); i=i+1 )
		printf( "%d ", a_digits[i] );
	printf( "\n" );


	return 0;
}
