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

// to continue
void enter()
{
	char enter;
	cout << "[ \']\' + Enter ] to contiue: ";
	cin >> enter;
	cout << "\n";
}

// converts int to sting ( 1 digit only )
char int_to_char( int a )
{
	char a_char = (char) (a + 48);

	return a_char;
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
	cout << "( setup ) Enter name - 2nd line\n";

	enter();

	command_linux ( "xrandr" );

	cout << "\n\nName: ";
	cin >> name;
	cout << "\n";

	// save name in file
	ofstream fo;
	fo.open( "brights/name" );
	fo << name;
	fo.close();	
}

void get_name()
{
	ifstream fi;
	fi.open( "brights/name" );
	fi >> name;
	fi.close();

	// setup name
	if ( name.length() < 1 )
		save_name();
}


int main ()
{

	get_name();

	string choice;

	cout << "( info ) Reset is done to bright 0.9. Reset it to 1.0 with \'reset.\'.\n";
	cout << "         Only \'1.\' and \'2.\' do not reset.\n\n";
	cout << "Brightly choices:\n";
	cout << "  1. Modify Bright\n";
	cout << "  2. Bright Choices\n";
	cout << "  3. Continous slow    ( also exits )\n";
	cout << "  4. Continous flicker ( also exits )\n";
	cout << "  more. More Birghties\n";
	cout << "  reset. Reset Bright\n\n";
	cout << " [exit]. Exits\n";

	cout << "\nYour Choice: ";
	getline( cin, choice );

	if ( choice == "1" )
		command_linux( "printf \"\033c\" && brights/brightly[]" );

	if ( choice == "2" )
		command_linux( "printf \"\033c\" && brights/brightly_choices" );

	if ( choice == "3" )
		command_linux( "printf \"\033c\" && brights/brightly_continous_slow" );

	if ( choice == "4" )
		command_linux( "printf \"\033c\" && brights/brightly_continous_flicker" );

	if ( choice == "more" )
		command_linux( "printf \"\033c\" && brights/brightly_more" );

	if ( choice == "reset" )
		xrandr( 1, 0 );

	if ( choice == "exit" or choice == "[exit]" )
	{
		if ( choice == "[exit]" )
			cout << "( info ) Enter \"exit\" instead of \"[exit]\".\n";
		cout << "Exited.\n";
	}
	else
		command_linux( "printf \"\033c\" && ./brightly" );

	return 0;
}
