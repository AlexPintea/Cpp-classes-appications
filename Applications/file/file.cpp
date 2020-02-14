#include <iostream>
#include <fstream>
#include <string>
#include <string.h>

using namespace std;
fstream file;


int length( int a )
{
	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}

void num_digits ( int a, char result[] )
{
	int i=0;
	int size = length(a);

	while (a != 0)
	{
		result[ size - i - 1 ] = a%10 + 48;
		i=i+1;
		a=a/10;
	}
}

string int_to_string( int a )
{
	string result = "";
	char digits[10];
	
	int size = length(a);
	num_digits( a, digits );
	
	for ( int i=0; i<size; i=i+1 )
	{
		result = result + digits[i];
	}
	
	return result;
}

void string_to_char (string a, char result[])
{
	int size = a.length();


	int i;

	for (i=0; i<size; i=i+1)
		result[i] = a[i];

	result[i] = '\0';
}




















void mkdir ( string name )
{
	string command = "mkdir " + name;

	char command_char[10000];
	string_to_char( command, command_char );
	system( command_char );
}

void chmod ( string name, int permission )
{
	char digits[10];
	int size = length(permission);
	num_digits( permission, digits );

	for (int i=0; i<size; i=i+1)
	{
		if ( digits[i] > 7 )
		{
			cout << "Entered num. is not a valid linux permission\n";
			return;
		}
	}

	string command = "chmod -R " + int_to_string( permission ) + " " + name;

	char command_char[10000];
	string_to_char( command, command_char );
	system( command_char );
}

void rm ( string name )
{
	string command = "rm -R " + name;

	char command_char[10000];
	string_to_char( command, command_char );
	system( command_char );
}


void cp ( string filepath1, string filepath2 )
{
	string command = "cp -R " + filepath1 + " " + filepath2;

	char command_char[10000];
	string_to_char( command, command_char );
	system( command_char );
}

void ls ()
{
	string command = "ls";

	char command_char[10];
	string_to_char( command, command_char );
	system( command_char );
}



int main ()
{
	cout << int_to_string( 104 );

	return 0;
}
