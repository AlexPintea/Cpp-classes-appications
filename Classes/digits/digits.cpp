#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;


// lengths


int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != '\0' )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}

int length(long a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != '\0' )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}

int length(int a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}



// empty


// empty digits
void empty ( int num_digits[] )
{
	for ( int i=0; i<length( num_digits ); i=i+1 )
		num_digits[i] = 0;
}




// digits of long ( same as int ) and int




// digits of a long
void digits ( long a, int num_digits[] )
{
	int size = length(a);

	empty ( num_digits );

	for ( int i=0; i<size; i=i+1 )
	{
		num_digits[ size - i - 1 ] = (int) (a%10);
		a = a / 10;
	}
}

// digits of an int
void digits ( int a, int num_digits[] )
{
	digits ( (long) a, num_digits );
}





// digits and decimals of a float ( same as double ) and float




float float_decimals (float a);
double double_decimals (double a);
int float_digits_int (float a);
int double_digits_int (double a);


// digits of a float
void digits ( float a, int num_digits[] )
{
	int a_as_int = float_digits_int( a );


	int size = length(a_as_int);

	empty ( num_digits );

	for ( int i=0; i<size; i=i+1 )
	{
		num_digits[ size - i - 1 ] = (int) (a_as_int%10);
		a_as_int = a_as_int / 10;
	}
}

// digits of a double
void digits ( double a, int num_digits[] )
{
	int a_as_int = double_digits_int( a );


	int size = length(a_as_int);

	empty ( num_digits );

	for ( int i=0; i<size; i=i+1 )
	{
		num_digits[ size - i - 1 ] = (int) (a_as_int%10);
		a_as_int = a_as_int / 10;
	}
}

// returns the decimals of a float num
float float_decimals (float a) 
{
	a = a - (int) a;

	return a;
}

// returns the decimals of a double num
double double_decimals (double a) 
{
	a = a - (int) a;

	return a;
}

// returns digits of a float as an int
int float_digits_int (float a)
{
	while ( float_decimals( a ) != 0.0 )
		a = a * 10;

	return (int) a;
}

// returns digits of a double as an int
int double_digits_int (double a)
{
	while ( double_decimals( a ) != 0.0 )
		a = a * 10;

	return (int) a;
}

// returns the decimals of a float as int
int float_decimals_int (float a)
{
	int digits_a[70];

	digits( a, digits_a );

	int size_a_int = length( (int) a );
	int size_a = length( float_digits_int(a) );
	int result = 0;

	for ( int i=size_a_int; i<size_a; i=i+1 )
		result = result * 10 + digits_a[i];

	return result;
}

// returns the decimals of a double as int
int double_decimals_int (double a)
{
	int digits_a[70];

	digits( a, digits_a );

	int size_a_int = length( (int) a );
	int size_a = length( double_digits_int(a) );
	int result = 0;

	for ( int i=size_a_int; i<size_a; i=i+1 )
		result = result * 10 + digits_a[i];

	return result;
}

// length of a float with decimals
int length( float a )
{
	return length( float_digits_int(a) );
}

// length of a double with decimals
int length( double a )
{
	return length( double_digits_int(a) );
}

// length of float decimals
int length_decimals( float a )
{
	return length( float_decimals_int(a) );
}

// length of double decimals
int length_decimals( double a )
{
	return length( double_decimals_int(a) );
}




// count digit





// how many times  item  is in  a[]  
int appears (int a[], int item) 
{
	int size = length(a);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
		if ( a[i] == item )
			counter = counter + 1;

	return counter;
}



// how many times a digit appears in a long
int count_digits ( long a, int digit )
{
	int digit_ints[1000];
	digits ( a, digit_ints );

	return appears( digit_ints, digit );
}

// how many times a digit appears in an int
int count_digits ( int a, int digit )
{
	return count_digits( (long) a, digit);
}

// how many times a digit appears in a double
int count_digits ( double a, int digit )
{
	int digit_ints[1000];
	digits ( a, digit_ints );

	return appears( digit_ints, digit );
}

// how many times a digit appears in a float
int count_digits ( float a, int digit )
{
	return count_digits( (double) a, digit );
}




int main ()
{


	// int


	cout << "// int ( same as long )\n";
	int num_digits_int[1000];
	int a_int = 4194;
	
	digits( a_int, num_digits_int );
	for ( int i=0; i<length( a_int ); i=i+1 )
		cout << "\'" << num_digits_int[i] << "\' ";
	cout << "\n";

	cout << count_digits( a_int , 4 ) << "\n";


	// double ( same as float ).


	cout << "// double ( same as float )\n";
	int num_digits_double[1000];
	double a_double = 12.9104;
	digits( a_double, num_digits_double );

	for ( int i=0; i<7; i=i+1 )
		cout << "\'" << num_digits_double[i] << "\' ";
	cout << "\n";

	cout << double_digits_int( a_double ) << "\n";
	cout << double_decimals_int( a_double ) << "\n";

	cout << length( a_double ) << "\n";
	cout << length_decimals( a_double ) << "\n";

	cout << count_digits( a_double , 1 ) << "\n";
	

	return 0;
}
