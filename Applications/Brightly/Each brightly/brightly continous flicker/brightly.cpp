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

void bright ( int bright_min, int bright_max, int rate )
{
	for ( int i=0; i<90; i=i+1 )
	{
		if ( i % rate == rate / 2 )
			xrandr( bright_min, 0 );
		else
			xrandr( bright_max, 0 );

		if ( i == 89 )
			i = 1;
	}
}





int main ()
{
	get_name();

	// reset
	xrandr( 0 , 9 );

	cout << "( info ) Ctrl + Z to stop.\n";
	enter();

	bright( 1, 2, 10 );
//	bright( 1, 2, 2 );

	// reset
	xrandr( 0 , 9 );

	return 0;
}
