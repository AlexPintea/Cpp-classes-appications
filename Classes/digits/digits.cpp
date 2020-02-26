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





// digits of a double ( same as float ) and float





// digits of double ( imprecise )
void digits ( double a, int num_digits[], int precision )
{
	long a_int = (long) a;

	digits ( a_int, num_digits );

	a = a - a_int;

	int empties = 0; // 0-s of 1.0004
	for ( int i=0; i<precision; i=i+1 )
	{
		a = a * 10;

		if ( (int) a == 0 )
			empties = empties + 1;
	}

	int size_num_digits = length( num_digits );

	long a_decimals = (long) a;
	int size_decimals = length( a_decimals );

	int decimals[1000];

	for ( int i=0; i<size_decimals; i=i+1 )
	{
		decimals[ size_decimals - i - 1 ] = a_decimals%10;
		a_decimals = a_decimals / 10;
	}

	for ( int i=size_num_digits; i<size_num_digits + empties + size_decimals; i=i+1 )
	{
		int l=0;

		if ( i - size_num_digits < empties )
			num_digits[i] = 0;
		else
		{
			num_digits[i] = decimals[ l ];
			l = l + 1;
		}
	}

}

// digits of float ( imprecise )
void digits ( float a, int num_digits[] )
{
	digits ( a, num_digits );
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



// Segm fault. 


// how many times a digit appeans in a long
int count_digits ( long a, int digit )
{
	int digit_ints[1000];
	digits ( a, digit_ints );

	return appears( digit_ints, digit );
}

// how many times a digit appeans in an int
int count_digits ( int a, int digit )
{
	return count_digits(a, digit);
}

// how many times a digit appeans in a double
int count_digits ( double a, int digit )
{
	int digit_ints[1000];
	digits ( a, digit_ints, 7 );

	return appears( digit_ints, digit );
}

// how many times a digit appeans in a float
int count_digits ( float a, int digit )
{
	return count_digits( a, digit );
}



// count has Segm. faults
int main ()
{


	// int


	cout << "// int\n";
	int num_digits[1000];
	int a_int = 4194;
	
	digits( a_int, num_digits );
	for ( int i=0; i<length( a_int ); i=i+1 )
		cout << "\'" << num_digits[i] << "\' ";
	cout << "\n";


	// double ( imprecise ). Precision is 7.


	cout << "// double ( imprecise )\n";
	int num_digits_1[1000];
	double a = 12.00004;
	digits( a, num_digits_1, 7 ); // precision

	for ( int i=0; i<7; i=i+1 )
		cout << "\'" << num_digits_1[i] << "\' ";
	cout << "\n";

	return 0;
}
