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


// check if a char is an int
int is_int ( char a[] )
{
	int size = length( a );

	if ( size >= 10 )
		return 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' && a[i] <= '9') || a[i] == '-' )  )
			return 0;

	return 1;
}
// convert char to int
int char_to_int ( char a[] )
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

	int num_int = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_int = num_int * 10 + ( a[i] - 48 );

	if ( is_neg == 1 )
		num_int = -num_int;

	return num_int;
}


// check if a char is a long
int is_long ( char a[] )
{
	int size = length( a );

	if ( size > 19 && a[0] == '-' )
		return 0;
	if ( size >= 19 && a[0] != '-' )
		return 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' && a[i] <= '9') || a[i] == '-' )  )
			return 0;

	return 1;
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

// check if a char is a double ( or a long / int )
int is_double ( char a[] )
{
	int size = length( a );

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= '0' && a[i] <= '9' ) || a[i] == '.' || a[i] == '-' ) )
			return 0;

	return 1;
}
// convert char to double
double char_to_double ( char a[] )
{
	if ( length( a ) == 1 )
		return a[0] - 48;

	int i = 0;
	int is_neg = 0;
	if ( a[0] == '-' )
	{
		is_neg = 1;
		i = 1;
	}

	int num_long = 0;
	while ( a[i] != '.' )
	{
		num_long = num_long * 10 + (int) ( a[i] - 48 );
		i = i + 1;
	}

	i = i + 1;
	int decimal_tens = 1;

	int num_decimals = 0;
	while ( a[i] != '\0' )
	{
		int temp = (int) ( a[i] - 48 );

		num_decimals = num_decimals * 10 + temp ;		
		decimal_tens = decimal_tens * 10;
		i = i + 1;
	}

	if ( num_long == 1 )
		num_long = -num_long;


	double num_double = (double) num_long + (double) num_decimals / decimal_tens;

	return num_double;
}



// datatypes to chars



// converts an int to a char array
void int_to_chars ( int a, char digits[] ) 
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

// converts a double to a char array
void double_to_chars ( double a, char digits[] ) 
{
	// gets digit of   (long) a   into   char digits[]
	long_to_chars( (long) a, digits );
	int size = length( digits );
	digits[ size ] = '.';
	digits[ size + 1 ] = '\0';
	size = size + 1;

	// gets decimals of a as long in   a_long   
	a = a - (long) a;
	for ( int i=0; i<=7; i=i+1 )
		a = a * 10;
	long a_long = (long) a;


	// gets digits of  a_long  ( decimals of  a  )  into   char decimals[]   
	char decimals[ 90 ];

	int i=0;
	int is_lasts = 1;
	while ( a_long != 0 )
	{
		char a_char = (char) ( a_long % 10 + 48 );

		if ( a_char != '0' )
			is_lasts = 0;

		if ( a_char == '0' && is_lasts == 1 )
		{
			a_long = a_long / 10;
			continue;
		}

		decimals[ i ] = a_char;
		i = i + 1;

		a_long = a_long / 10;
	}
	decimals[i] = '\0';

	// adds  decimals[]  to  digits[]  
	int size_decimals = length( decimals );

	invert_chars( decimals );

	for ( int i=0; i<size_decimals; i=i+1 )
		digits[ size + i ] = decimals[i];

	digits[ size + size_decimals ] = '\0';
}



int main ()
{


	char a_digits[90];

	int a_int = 17;
	int_to_chars( a_int, a_digits );
	printf( "%s\n", a_digits );

	long a_long = 19999999999;
	long_to_chars( a_long, a_digits );
	printf( "%s\n", a_digits );

	double a_double = 1701.901;
	double_to_chars( a_double, a_digits );
	printf( "%s\n\n", a_digits );




	char b_int_digits[10] = { '1', '7', '9', '4' };
	printf( "%d\n", is_int( b_int_digits ) );
	int b_int = char_to_int( b_int_digits );
	printf( "%d\n", b_int );

	char b_long_digits[10] = { '1', '7', '9', '9', '9', '9', '9', '4' };
	printf( "%d\n", is_long( b_long_digits ) );
	long b_long = char_to_long( b_long_digits );
	printf( "%d\n", b_long );

	char b_double_digits[17] = { '1', '7', '9', '.', '9', '9', '9', '4' };
	printf( "%d\n", is_double( b_double_digits ) );
	double b_double = char_to_double( b_double_digits );
	printf( "%f\n", b_double );

	
}
