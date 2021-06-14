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

// converts int to sting ( 1 digit only )
char int_to_char( int a )
{
	char a_char = (char) (a + 48);

	return a_char;
}

// to continue
void enter()
{
	char enter;
	cout << "[ \']\' + Enter ] to contiue: ";
	cin >> enter;
	cout << "\n";
}




string name;

// modify intensity
void xrandr ( int bright_int, int bright_decimals )
{
	string command = "xrandr --output " + name + " --brightness ";
	command = command + int_to_char( bright_int ) + "." + int_to_char( bright_decimals );

	command_linux( command );
}

// saves name of what we want to dim
void save_name()
{
	command_linux ( "xrandr > screen_name" );

	ifstream fi;
	fi.open( "screen_name" );

	getline( fi, name );
	fi >> name;

	fi.close();

	command_linux( "rm -r screen_name" );

	// save name in file
	ofstream fo;
	fo.open( "name" );
	fo << name;
	fo.close();	
}

void get_name()
{
	ifstream fi;
	fi.open( "name" );
	fi >> name;
	fi.close();

	// setup name
	if ( name.length() < 1 )
		save_name();
}

int main ()
{
	get_name();

	string modify;
	int bright_int = 0;
	int bright_decimals = 9;

	cout << "Modify with [ / ]. Stop with \"done\".\n";
	enter();

	while ( modify != "done" )
	{
		cout << "Bright: " << bright_int << "." << bright_decimals << " range: [ 0 - 3 ]. Enter ( [ / ] ): ";
		cin >> modify;

		if ( modify[0] == ']' )
			if ( bright_int < 3 )
			{
				if ( bright_decimals == 9 )
				{
					bright_int = bright_int + 1;
					bright_decimals = 0;
				}
				else
					bright_decimals = bright_decimals + 1;

			}
			else
				cout << "Max. was reached.\n";

		
		if ( modify[0] == '[' )
			if ( bright_int > 0 )
			{
				if ( bright_decimals == 0 )
				{
					bright_int = bright_int - 1;
					bright_decimals = 9;
				}
				else
					bright_decimals = bright_decimals - 1;
			}
			else
				cout << "Min. was reached.\n";


		xrandr ( bright_int, bright_decimals );
	}
	return 0;
}
