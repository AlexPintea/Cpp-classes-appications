#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// converts a string to a char array
void string_to_chars ( string a, char chars[] ) 
{
	int size = a.length();

	int i;

	for ( i=0; i<size; i=i+1 )
		chars[i] = a[i];
	chars[i] = '\0';
}

// linux command
void command_linux ( string command_string )
{
	char command_chars[1000];
	string_to_chars( command_string, command_chars );
	system( command_chars );
}

void unzip_unrar ( string a )
{

	command_linux( "unzip " + a + ".zip");
	command_linux( "unrar " + a + ".rar" );
}

int main ()
{

	string filename;
	cout << "Filename: ";
	getline( cin, filename );

	return 0;
}
