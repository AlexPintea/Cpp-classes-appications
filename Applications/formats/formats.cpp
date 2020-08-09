#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string strings[ 10000 ];
int strings_iter = 0;

void set_string ( string &a, string l1, string l2 )
{
	int size = a.length();

	if ( size == 0 ) return;

	string result = "";
	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( ( a[ i ] == ' ' or a[ i ] == '\n' or a[ i ] == '	' ) and ( i > 0 and i < size - 1 ) )
		{
			if ( a[ i + 1 ] == ' ' or a[ i + 1 ] == '\n' or a[ i + 1 ] == '	' )
				if ( a[ i - 1 ] == ' ' or a[ i - 1 ] == '\n' or a[ i - 1 ] == '	' )
				{
					result = result + a[ i ];
					continue;
				}

			if ( a[ i - 1 ] != ' ' and a[ i - 1 ] != '\n' and a[ i - 1 ] != '	' )
				result = result + l2;
			result = result + a[ i ];
			if ( a[ i + 1 ] != ' ' and a[ i + 1 ] != '\n' and a[ i + 1 ] != '	' )
				result = result + l1;
			continue;
		}

		if ( ( a[ i ] == ' ' or a[ i ] == '\n' or a[ i ] == '	' ) and i > 0 )
		{
			result = result + l2 + a[ i ];	
			continue;
		}

		result = result + a[ i ];
	}


	if ( a[ 0 ] != ' ' and a[ 0 ] != '\n' and a[ 0 ] != '	' )
		result = l1 + result;

	if ( a[ size - 1 ] != ' ' and a[ size - 1 ] != '\n' and a[ size - 1 ] != '	' )
		result = result + l2;

	a = result;
}

void set_string_line ( string &a, string l1, string l2 )
{
	int size = a.length();

	if ( size == 0 ) return;

	string result = "";

	int l;
	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
		{
			l = i;
			break;
		}

		result = result + a[ i ];
	}		


	int p;
	for ( int i = size - 1; i >= 0; i = i - 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
		{
			p = i;
			break;
		}


	result = result + l1;
	for ( int i = l; i <= p; i = i + 1 )
		result = result + a[ i ];
	result = result + l2;

	for ( int i = p + 1; i < size; i = i + 1 )
		result = result + a[ i ];


	a = result;
}

void set_string_char ( string &a, string l1, string l2 )
{
	int size = a.length();

	if ( size == 0 )
		return;

	string result = "";
	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( a[ i ] == ' ' or a[ i ] == '\n' or a[ i ] == '	' )
		{
			result = result + a[ i ];
			continue;
		}

		result = result + l1 + a[ i ] + l2;
	}

	a = result;
}

void set_file( int choice, string l1, string l2 )
{
	ifstream fi;
	fi.open( filename );

	string temp;

	while ( getline( fi, temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}

	fi.close();


	if ( choice == 1 )
	{
		for ( int i = 0; i < strings_iter; i = i + 1 )
			set_string( strings[ i ], l1, l2 );
	}

	if ( choice == 2 )
	{
		for ( int i = 0; i < strings_iter; i = i + 1 )
			set_string_line( strings[ i ], l1, l2 );
	}

	if ( choice == 3 )
	{
		for ( int i = 0; i < strings_iter; i = i + 1 )
			if ( strings[ i ].length() != 0 )
				set_string_char( strings[ i ], l1, l2 );
	}


	ofstream fo;
	fo.open( "result" );

	for ( int i = 0; i < strings_iter; i = i + 1 )
		fo << strings[ i ] << '\n';

	fo.close();
}



int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	cout << "Choices:  1. Strings  2. Lines  3. Chars\n";
	cout << "Choice: ";

	string choice;
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	string l1;
	string l2;

	cout << "Preced: ";
	getline( cin, l1 );
	if ( l1 == "" )
		getline( cin, l1 );
	cout << "Aftr: ";
	getline( cin, l2 );
	if ( l2 == "" )
		getline( cin, l2 );

	if ( choice == "1" )
	{
		set_file( 1, l1, l2 );
	}

	if ( choice == "2" )
	{
		set_file( 2, l1, l2 );
	}

	if ( choice == "3" )
	{
		set_file( 3, l1, l2 );
	}

	return 0;
}
