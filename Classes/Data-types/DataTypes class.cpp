#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int char_size (char word[])
{
	int i=0;

	while ( word[i] != '\0' )
	{	
		i=i+1;
	}

	return i;
}


// make a copy of a char array
void char_copy (char word[], char copy[]) 
{
	int size = char_size(word);

	copy[size] = {};

	for ( int i=0; i<size; i=i+1 )
		copy[ i ] = word[i];
}


// invert a char arrau
void char_invert (char word[], char inverted[])
{
	int size = char_size(word);

	inverted[size] = {};

	for ( int i=0; i<size; i=i+1 )
		inverted[ size - i - 1 ] = word[i];
}


// count how many times a char appears in a char array
int char_count (char word[], char a) 
{
	int size = char_size(word);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
	{
		if (word[i] == a)
		counter = counter + 1;
	}

	return counter;
	
}


// converts a char array into a string
string char_to_string(char word[]) 
{
	string result = word;

	return result;
}

























// determine nr of digits in a number
int int_size (int a)
{
	int i=0;

	while (a!=0)
	{
		i=i+1;
		a=a/10;
	}

	return i;
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

	int size = int_size(a);

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

// converts an int to a char array
void int_to_char ( int a, char chars[] ) 
{
	int size = int_size(a);

	char digits[ size + 1 ];
	
	for (int i=0; i<size; i=i+1)
	{
		digits[ size - i - 1 ] = a % 10 + 48;
		a = a / 10;
	}

	char_copy(digits, chars);
	
}

// converts an int to a string
string int_to_string (int a)
{
	int size = int_size(a);

	string result = "                       ";

	for (int i=0; i<size; i=i+1)
	{		
		result[ size - i - 1 ] = a % 10 + 48;
		a = a / 10;
	}


	for (int i=0; i<size; i=i+1)
		if ( result[i] == ' ' )
		{	
			result[i] = '\0';
			break;
		}

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


int cmmdc () 
{
	return 0;
}







// returns the int part of a floar nr
int float_to_int (float a) 
{
	return (int) a;;
}


// returns the size of the integer part of a float nr
int float_int_size (float a) 
{
	a = (int) a;
	return int_size(a);
}

// returns the decimals of a float as int
int float_decimals_int (float a)
{
	a = a - (int) a;

	while ( a != (int) a )
		a=a*10;

	
	int size = int_size(a);
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
	return int_size( float_decimals_int(a) );
}











// returns the size of the string
int string_size (string a)
{
	return a.length();
}


// counts how many times a char appears in a string
int string_count (string a, char find)
{
	int size = string_size(a);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
		if (a[i] == find)
			counter = counter + 1;

	return counter;
			
}

// converts a string to a char array
void string_to_char (string a, char result[])
{
	int size = a.length();

	for (int i=0; i<size; i=i+1)
		result[i] = a[i];
}
