#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string file[ 10000 ];
int file_iter = 0;


int length ( string a[] )
{
	int i = 0;


	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}

bool is_string_empty ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();

	return file;
}

void get_file ( string filename, string strings[], string a )
{
	if ( a.length() == 0 ) return;

	string file = get_file( filename );

	int size = file.length();
	int strings_iter = 0;

	for ( int i = 0; i < size - 1; i = i + 1 )
	{
		if ( file[ i ] == a[ 0 ] )
		{
			bool have_a = 1;
			int file_iter = i;
			for ( int l = file_iter; l < a.length(); l = l + 1 )
				if ( file[ l ] != a[ l ] )
				{
					have_a = 0;
					break;
				}

			if ( have_a )
			{
				i = i + a.length() - 1;
				strings_iter = strings_iter + 1;
				strings[ strings_iter ] = "";
				continue;
			}
		}

		strings[ strings_iter ] = strings[ strings_iter ] + file[ i ];
	}
}




int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	cout << "Prgrph length ( sentnces ): ";
	int l;
	cin >> l;

	get_file( filename, file, "." );
	file_iter = length( file );

	ofstream fo;
	fo.open( "result" );
	fo.close(); // clear file

	fo.open( "result" );

	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		if ( is_string_empty( file[ i ] ) ) continue;

		fo << file[ i ] << '.';

		if ( i % l == l - 1 )
			fo << "\n\n";
	}

	fo.close();
	return 0;
}
