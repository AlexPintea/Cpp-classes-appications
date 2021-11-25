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

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	return file;
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
	fo.open ( "result.tex" );
	fo.close(); // clear file

	fo.open ( "result.tex" );

	fo << get_file( "data/before" ); 
	for ( int i = 0; i < name_iter; i = i + 1 )
	{
		fo << get_file( "data/1" ); 
		fo << "\\text Given to " << name[ i ] << "\\\\\n\\vspace{21pt}\nfor ";
		fo << dplma << "\\\\\n\n";
		fo << get_file( "data/2" ); 
		fo << "\n\\newpage\n";
	}
	fo << get_file( "data/after" ); 

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

	system( "mkdir \"Awards\"" );
	system( "cp data/dplma.ttf Awards" );
	system( "cp data/texts.ttf Awards" );
	system( "cp data/style.jpg Awards" );
	system( "mv result.tex Awards" );
//	system( "cd Awards && " ); // complie xeltx

	cout << "Folder Awards was made.\nExited.\n";

	return 0;
}
