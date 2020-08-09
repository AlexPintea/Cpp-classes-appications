#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string details[ 10000 ];
int details_iter = 0;

string file_name = "";

string choice;

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}

void get_file_lines ( string filename, string strings[] )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	int strings_iter = 0;
	string temp;
	while ( getline( fi, temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();
}

bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}

void upper ( string &a )
{
	if ( a[ 0 ] > 'a' and a[ 0 ] < 'z' )
		a[ 0 ] = a[ 0 ] - 32;
}

void set_file ()
{
	upper( file_name );

	ofstream fo;
	fo.open( "result" );
	fo.close(); // clear file

	fo.open( "result" );

	fo << "Welcome to " << file_name << "!\n\n";

	fo << "Details:\n\n";

	for ( int i = 0; i < details_iter; i = i + 1 )
		fo << details[ i ] << "\n";

	fo.close();
}

int main ()
{
	cout << "format_file\n";
	cout << "Choices:  1. Add details  2. Add file ( lines are details )\n";
	cout << "Choice: ";

	getline( cin, choice );


	cout << "Name of file: ";

	getline( cin, file_name );


	if ( choice != "2" )
	{
		cout << "Empty means done:\n";

		string temp = "format";
		while ( getline( cin, temp ) and ! is_string_empty( temp ) )
		{
			details[ details_iter ] = temp;
			details_iter = details_iter + 1;
		}
	}
	else
	{
		cout << "Filename: ";

		string filename;
		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		get_file_lines( filename, details );
		details_iter = length( details );
	}

	set_file();

	return 0;
}
