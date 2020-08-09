#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


void get_files ( string filenames[], string files[] )
{
	int size = 0;
	while ( filenames[ size ].length() > 0 )
		size = size + 1;

	ifstream fi;

	string temp;

	for ( int i = 0; i < size; i = i + 1 )
	{
		files[ i ] = "";

		fi.open( filenames[ i ] );

		while ( getline( fi, temp ) )
			files[ i ] = files[ i ] + temp + '\n';

		fi.close();
	}
}

void set_files ( string filenames[], string files[] )
{
	int size = 0;
	while ( filenames[ size ].length() > 0 )
		size = size + 1;

	ofstream fo;

	string temp;

	for ( int i = 0; i < size; i = i + 1 )
	{
		fo.open( filenames[ i ] );

		fo << files[ i ];

		fo.close();
	}
}












bool is_string_empty ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;

	return 1;
}

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}

int main ()
{
	string filenames[ 10000 ];
	int file_iter = 0;
	
	string files[ 10000 ];
	cout << "Filenames ( empty means done )\n";

	string temp = "filename";
	while ( ! is_string_empty( temp ) )
	{
		getline( cin, temp );
		if ( temp == "" )
			getline( cin, temp );

		if ( is_string_empty( temp ) )
			break;


		filenames[ file_iter ] = temp;
		file_iter = file_iter + 1;
	}

	get_files( filenames, files );
	set_files( filenames, files );
	for ( int i = 0; i < length( files ); i = i + 1 )
		cout << files[ i ] << "\n\n";

	return 0;
}
