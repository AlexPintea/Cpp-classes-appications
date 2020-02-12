#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

class FileCounter {

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

int char_size (char word[])
{
	int i=0;

	while ( word[i] != '\0' )
	{	
		i=i+1;
	}

	return i;
}

void char_copy (char word[], char copy[]) 
{
	int size = char_size(word);

	copy[size] = {};

	for ( int i=0; i<size; i=i+1 )
		copy[ i ] = word[i];
}






public:

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

void string_to_char (string a, char result[])
{
	int size = a.length();
	int i;
	for (i=0; i<size; i=i+1)
		result[i] = a[i];
	
	result[i] = '\0';

}


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

void file_counter_clear ( fstream &num )
{
	num.open("counter.txt"); // open num as usual, read its contents etc.

	num.close();		     // close it

	// do this ( open and close the num to empty it )
	num.open("counter.txt", std::ofstream::out | std::ofstream::trunc);
	num.close();
}

int file_counter ()
{
	fstream num;

	num.open( "counter.txt" );

	int counter;
	num >> counter;

	if ( counter == 0 )
		counter = 1;
	
	int copy_counter = counter;

	file_counter_clear(num);
	
	copy_counter = copy_counter + 1;

	num.open( "counter.txt" );

	num << copy_counter;

	num.close();

	return counter;
}

}
