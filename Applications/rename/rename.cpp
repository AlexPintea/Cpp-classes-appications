#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;


string folder;

string files[ 10000 ];
int files_iter = 0;

int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}
void string_to_char (string a, char result[])
{
	int size = a.length();

	int i;

	for (i=0; i<size; i=i+1)
		result[i] = a[i];

	result[i] = '\0';
}

void command ( string command_string )
{
	char command_char[1000];
	string_to_char( command_string, command_char );
	system( command_char );
}

void remove_last_char ( string &a )
{
	string result = "";
	for ( int i = 0; i < a.length() - 2; i = i + 1 )
		result = result + a[ i ];
	a = result;
}

bool have_char ( string a, char b )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] == b )
			return 1;
	return 0;
}

// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			if ( i != 0 )
				if ( text[i-1] != ',' )
				{
					words[ words_iter ] = words[ words_iter ] + text[i];
					continue;
				}

			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}

// inverts a string
void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}

// is numeric char
bool is_numeric( char a )
{
	if ( a >= '0' and a <= '9' )
		return true;

	return false;
}

// converts an int to a string
string int_to_string (int a)
{
	int size = length(a);

	bool is_neg = false;
	if ( a < 0 )
	{
		is_neg = true;
		a = -a;
	}

	string result = "";

	for (int i=0; i<size; i=i+1)
	{	
		char a_char = (char) (a % 10 + 48);

		if ( is_numeric( a_char ) )
			result = result + a_char;
		a = a / 10;
	}

	if ( is_neg )
		result = result + '-';

	invert_string( result );

	return result;
}

string get_ext ( string a )
{
	string ext = "";
	for ( int i = a.length() - 1; i >= 0; i = i - 1 )
	{

		if ( a[ i ] == '.' )
			break;
		ext = ext + a[ i ];
	}

	invert_string( ext );
	return ext;
}


void get_files ()
{
	ofstream fo;
	fo.open( "files-ls" );
	fo.close(); // clear file

	fo.open( "files-ls" );
	fo << folder;
	fo.close();

	command ( "./code.sh" );
	sleep( 1 );

	ifstream fi;
	fi.open( "files-ls" );
	string temp;
	getline( fi, temp );
	temp = temp + ',';
	fi.close();	


	string strings[ 10000 ];
	move_words( temp, strings );
	int strings_iter = length( strings );

	temp = "";
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( ! have_char( temp, ',' ) or temp == "" )
		{
			temp = temp + strings[ i ] + ' ';
			continue;
		}

		remove_last_char( temp );
		files[ files_iter ] = temp;
		files_iter = files_iter + 1;
		temp = "";
		if ( i != 0 )
			i = i - 1;
	}
	remove_last_char( temp );
	files[ files_iter ] = temp;
	files_iter = files_iter + 1;

	fo.open( "commands.sh" );
	fo.close(); // clear file

	command( "chmod 767 -R commands.sh" );

	fo.open( "commands.sh" );

	fo << "cd \"" + folder + "\"\n";
	for ( int i = 0; i < files_iter; i = i + 1 )
	{
		if ( files[ i ] == "" )
			continue;

		string filename;

		if ( have_char( files[ i ], '.' ) )
			filename = int_to_string( i + 1 ) + '.' + get_ext( files[ i ] );
		else
			filename = int_to_string( i + 1 );

		if ( files[ i ] == filename )		
			continue;

		fo << "\ncp \"" + files[ i ] + "\" \"" + filename + "\"\n";
		fo << "chmod 767 \"" + filename + "\"\n";
		fo << "rm \"" + files[ i ] + "\"\n";

		cout << "Renamed file: \"" << files[ i ] << "\" into \"" << filename << "\"\n";
	}

	fo.close();

	command ( "./commands.sh" );
}

int main ()
{
	cout << "chocies\n";
	cout << "Folder path: ";

	getline( cin, folder );
	if ( folder == "" )
		getline( cin, folder );


	get_files();

	return 0;
}
