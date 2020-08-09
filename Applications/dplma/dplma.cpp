#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string dplma;
string name[ 10000 ];
int name_iter = 0;


int length ( string a[] )
{
	int i = 0;
	while ( a[ i ].length() > 0 ) i = i + 1;

	return i; 
}

bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return 0;
	return 1;
}

void get_strings ( string strings[] )
{
	string temp;
	int strings_iter = 0;

	cout << " ( empty means done )\n";

	while ( getline( cin, temp ) and ! is_string_empty ( temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
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

void set_file ()
{
	ofstream fo;
	fo.open ( "result" );
	fo.close(); // clear file

	fo.open ( "result" );

	for ( int i = 0; i < name_iter; i = i + 1 )
	{
		fo << dplma << '\n';
		fo << name[ i ] << "\n\n";
	}

	fo.close();
}

int main ()
{
	cout << "Dplma for: ";

	getline( cin, dplma );
	if ( dplma == "" )
		getline( cin, dplma );

	string choice;
	cout << "Get names:  1. type  2. file\n";
	cout << "Choice: ";

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice != "2" )
	{
		cout << "Names";
		get_strings ( name );
	}
	else
	{
		string filename;
		cout << "Filename: ";

		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		get_file_lines ( filename, name );
	}
	name_iter = length( name );

	set_file ();
	

	return 0;
}
