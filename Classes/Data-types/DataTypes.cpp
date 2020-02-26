#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;



int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}

int length(long a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
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

int length(float a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(double a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(char a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(bool a[]) // does not return validly
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
}



// invert a char array
void char_invert (char word[], char inverted[])
{
	int size = length(word);

	inverted[size] = {};

	for ( int i=0; i<size; i=i+1 )
		inverted[ size - i - 1 ] = word[i];
}


// count how many times a char appears in a char array
int char_count (char word[], char a) 
{
	int size = length(word);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
	{
		if (word[i] == a)
		counter = counter + 1;
	}

	return counter;
	
}



























// inverts an int nr
int int_invert (int a)
{
	int tens = 0;
	int copy = a;

	while ( a % 10 == 0 )
	{
		tens = tens + 1;
		a = a / 10;
	}

	if ( tens !=  0 )
		cout<<"For the nr " << copy << ", " << tens << " 0-s were deleted when inverting. " << copy << " now is ";

	int digits[1243];

	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
	{
		digits[i] = a % 10;
		a=a/10;
	}

	for ( int i=0; i<size; i=i+1 )
	{
		a = a * 10 + digits[i];
	}

	cout << a << ".\n";
	return a;
}


// converts an int to a string
string int_to_string (int a)
{
	int size = length(a);

	string result = "                       ";

	for (int i=0; i<size; i=i+1)
	{		
		result[ size - i - 1 ] = a % 10 + 48;
		a = a / 10;
	}


	for (int i=0; i<size; i=i+1)
		if ( result[i] == ' ' )
			result[i] = '\0';

	return result;
}

// counts how many times a digit appears in a nr
int int_count (int a, int digit) 
{
	int counter = 0;

	while (a != 0)
	{
		if ( a%10 == digit )
			counter = counter + 1;
		a=a/10;
	}

	return counter;
}









// returns the size of the integer part of a float nr
int float_int_size (float a) 
{
	a = (int) a;
	return length(a);
}

// returns the decimals of a float as int
int float_decimals_int (float a)
{
	a = a - (int) a;

	while ( a != (int) a )
		a=a*10;

	
	int size = length(a);
	int digits[ size ];


	for ( int i=0; i<size; i=i+1 )
	{
		digits[ size - i - 1] = ( (int) a ) % 10;
		a=a/10;
	}

	a=0;

	int i;

	for ( i=0; i<size; i=i+1 )
	{
		if ( digits[i] != 9 and digits[i] != 0 )
			a = a * 10 + digits[i];
		else
			break;
	}

	if (digits[i] == 0)
		return (int) a;	
	else
		return (int) a + 1;
}

// returns the decimals of a float nr
float float_decimals (float a) 
{
	int tens = 1;

	a = a - (int) a;

	while ( (int) a == 0  )
	{
		tens = tens * 10;
		a = a * 10;
	}

	while ( (int) a != a )
	{
		tens = tens * 10;
		a = a * 10;
	}

	a = a / tens;

	return a;
}


// returns the size of the decimals in a float nr
float float_decimals_size (float a) 
{
	return length( float_decimals_int(a) );
}











// counts how many times a char appears in a string
int string_count (string a, char find)
{
	int size = a.length();
	int counter = 0;

	for (int i=0; i<size; i=i+1)
		if (a[i] == find)
			counter = counter + 1;

	return counter;
			
}











int main () 
{	

	cout << float_decimals( 1.009010902 ) << "\n";
	cout << float_decimals_int( 1.412 ) << "\n";

	return 0;	
}
