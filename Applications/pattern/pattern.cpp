#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string common[ 10000 ];
int common_iter = 0;

string patterns[ 10000 ];
int patterns_iter = 0;

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}

void move_words ( string text, string words[] )
{
	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}




void get_patterns ()
{
	ifstream fi;
	fi.open( "pattern" );



	string temp;
	while ( getline( fi, temp ) )
	{
		patterns[ patterns_iter ] = temp;
		patterns_iter = patterns_iter + 1;
	}

	fi.close();
}

void set_patterns ()
{
	ofstream fo;
	fo.open( "pattern" );
	fo.close();
	fo.open( "pattern" );

	for ( int i = 0; i < patterns_iter; i = i + 1 )
		fo << patterns[ i ] << '\n';

	fo.close();
}

void get_common ()
{
	ifstream fi;

	fi.open( "common" );


	string temp;
	while ( fi >> temp )
	{
		common[ common_iter ] = temp;
		common_iter = common_iter + 1;
	}

	fi.close();
}
bool is_common ( string a )
{
	for ( int i = 0; i < common_iter; i = i + 1 )
		if ( common[ i ] == a )
			return 1;
	return 0;
}

bool is_pattern ( string a )
{
	for ( int i = 0; i < patterns_iter; i = i + 1 )
		if ( patterns[ i ] == a )
			return 1;
	return 0;
}

void leave_usual ( string &a )
{
	string temps[ 10000 ];

	move_words( a, temps );

	a = "";

	int size = length( temps );

	for ( int i = 0; i < size; i = i + 1 )
		if ( is_common( temps[ i ] ) )
			a = a + temps[ i ] + ' ';
}

void add_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string strings[ 10000 ];
	int strings_iter = 0;

	string temp;
	while ( getline( fi, temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();


	for ( int i = 0; i < strings_iter; i = i + 1 )
		leave_usual( strings[ i ] );

	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( ! is_pattern( strings[ i ] ) )	
		{
			patterns[ patterns_iter ] = strings[ i ];
			patterns_iter = patterns_iter + 1;
		}
	set_patterns();	
}




int main ()
{
	get_common();
	get_patterns();

	string filename;
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	add_file( filename );
	return 0;
}
