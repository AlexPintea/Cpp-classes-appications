// #include "lengths.cpp"
// #include "empty.cpp"


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
int length_with_decimals( float a )
{
	return length( float_digits_int(a) );
}

// length of a double with decimals
int length_with_decimals( double a )
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




