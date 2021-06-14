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
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> enter;
	cout << "\n";
}



// Name



string name;

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

// gets name
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



// Order of brights




// order of brighties
int order[ 1000 ] = { 1, 2, 4, 3, 2, 1, 3 };
int order_iter = 0; // set to 0 to verif. file

// makes "brighties" file and saves defaults in it
void save_default_order()
{
	// make "brighties" file
	ofstream fo;
	fo.open( "brighties" );
	fo.close();

	// set to default
	fo.open( "brighties" );
	fo << order_iter << "\n";
	for ( int i=0; i<order_iter; i=i+1 )
		fo << order[ i ] << " ";
	fo.close();
}

// gets order of file "brighties"
void get_order ()
{
	ifstream fi;
	fi.open( "brighties" );
	fi >> order_iter;

	// setup order to default
	if ( order_iter == 0  )
	{
		order_iter = 7;
		save_default_order();
		fi.close();
		return;
	}

	for ( int i=0; i<order_iter; i=i+1 )
		fi >> order[ i ];
	fi.close();
}

// sets order of file "brighties"
void set_order ()
{
	ofstream fo;
	fo.open( "brighties" );
	fo << order_iter << "\n";
	for ( int i=0; i<order_iter; i=i+1 )
		fo << order[ i ] << " ";
	fo.close();
}

// clears order[]
void clear_order ()
{
	for ( int i=0; i<order_iter; i=i+1 )
		order[i] = 0;
	order_iter = 0;
}

// clears, modifies and sets order to file "brighties"
void modify_order ()
{
	clear_order();

	cout << "Num. or brightlies: ";
	cin >> order_iter;

	cout << "1. Slow  2. Slight Flicker  3. Slow down  4. Flicker\n";

	for ( int i=0; i<order_iter; i=i+1 )
	{
		cout << "Birghtly num. " << i + 1 << ": ";
		cin >> order[i];
	}
	
	set_order();
	cout << "( info ) Order of brighties modified.\n\n";
	enter();
}



// Intensity



// modify intensity
void xrandr ( int bright_int, int bright_decimals )
{
	string command = "xrandr --output " + name + " --brightness ";
	command = command + int_to_char( bright_int ) + "." + int_to_char( bright_decimals );

	command_linux( command );
}


// in bright3 folder ( slow )
void bright3 ( int bright_min, int bright_max, int rate )
{
	int decimals = 0;
	int bright = bright_min;
	bool direction = true;

	for ( int i=0; i<900; i=i+1 )
	{
		if ( i % rate == 0 )
		{
			if ( direction )
			{
				if ( bright < bright_max )
				{
					if ( decimals == 9 )
					{
						bright = bright + 1;
						decimals = 0;
					}
					else
						decimals = decimals + 1;
				}
				else
					direction = false;
			}
			
			if ( !direction )
			{
				if ( bright > bright_min )
				{
					if ( decimals == 0 )
					{
						bright = bright - 1;
						decimals = 9;
					}
					else
						decimals = decimals - 1;
				}
				else
					direction = true;
			}
			
			xrandr( bright, decimals );
		}

	}
}

// in bright4 folder ( flicker )
void bright4 ( int bright_min, int bright_max, int rate )
{
	for ( int i=0; i<90; i=i+1 )
	{
		if ( i % rate == rate / 2 )
			xrandr( bright_min, 0 );
		else
			xrandr( bright_max, 0 );
	}
}

// type of bright
void type ( int bright_int )
{
	// Slow
	if ( bright_int == 1 )
		bright3( 1, 4, 20 );
	
	// Slight Flicker
	if ( bright_int == 2 )
		bright4( 1, 2, 10 );

	// Slow Down
	if ( bright_int == 3 )
		bright3( 0, 2, 10 );

	// Flicker
	if ( bright_int == 4 )
		bright4( 1, 2, 2 );
}





int main ()
{
	get_name();
	get_order();

	// reset
	xrandr( 0 , 9 );

	cout << "( info ) Ctrl + Z to stop.\n";
	enter();

	// modify the "brighties" file
	string choice;
	cout << "Modify order file ( y / n ): ";
	getline( cin, choice );
	getline( cin, choice );
	if ( choice == "y" )
		modify_order();




	// modifies bright
	for ( int i=0; i<order_iter; i=i+1 )
		type( order[i] );



	// reset
	xrandr( 0 , 9 );

	cout << "\n\nDone. Exited.\n\n";

	return 0;
}
