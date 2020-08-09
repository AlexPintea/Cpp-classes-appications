#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string filename;
string file = "";
string files[ 10000 ];
int files_iter = 0;

void insert_char ( string &a, char b, int pos )
{
	if ( pos < 0 or pos >= a.length() )
		return;

	string result = "";

	for ( int i = 0; i < a.length(); i = i + 1 )
	{
		if ( i == pos )
			result = result + b;
		result = result + a[ i ];
	}

	a = result;
}


string reduce_string ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
	{
		if ( a[ i ] == '.' )
			continue;
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";
	}

	// for ( int i = 0; i < result.length(); i = i + 1 )
	//	if ( result[ i ] >= 'A' and result[ i ] <= 'Z' )
	//		result[ i ] = result[ i ] + 32;

	return result;
}

bool is_string_empty( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
}


void set_file ()
{
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	for ( int i = 0; i < file.length(); i = i + 1 )
		if ( file[ i ] == '.' and i != file.length() - 1 )
			insert_char( file, '\n', i + 1 );
	ofstream fo;
	fo.open( filename );
	fo.close(); // clears file

	fo.open( filename );

	fo << file;
	fo.close();

	fi.open( filename );

	while ( getline( fi, temp ) )
	{
		if ( is_string_empty ( temp ) )
			continue;
		files[ files_iter ] = reduce_string( temp );
		files_iter = files_iter + 1;
	}

	fi.close();


	fo.open( filename );
	fo.close(); // clears file

	fo.open( filename );

	for ( int i = 0; i < files_iter; i = i + 1 )
		fo << files[ i ] << '\n';

	fo.close();
}









int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );
	set_file();
	return 0;
}
