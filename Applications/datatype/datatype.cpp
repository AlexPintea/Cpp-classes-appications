#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


bool is_numeric ( char a )
{
	if ( a >= '0' and a <= '9' )
		return 1;
	return 0;
}

bool is_int ( string a )
{
	int size = a.length();

	if ( a[ 0 ] != '-' and ! is_numeric( a[ 0 ] ) )
		return 0;

	if ( a[ 0 ] == '-' and size == 1 )
		return 0;

	for ( int i = 1; i < size; i = i + 1 )
		if ( ! is_numeric( a[ i ] ) )
			return 0;

	return 1;
}

bool is_double ( string a )
{
	int size = a.length();

	if ( a[ 0 ] != '-' and ! is_numeric( a[ 0 ] ) )
		return 0;

	if ( a[ 0 ] == '-' and size == 1 )
		return 0;

	if ( a[ size - 1 ] == '.' )
		return 0;

	for ( int i = 1; i < size; i = i + 1 )
		if ( ! is_numeric( a[ i ] ) and a[ i ] != '.' )
			return 0;

	return 1;
}

string filename;

string file[ 100000 ];
int file_iter = 0;

void set_files ()
{
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( fi >> temp ) 
	{
		file[ file_iter ] = temp;
		file_iter = file_iter + 1;
	}

	fi.close();

	ofstream fo;

	fo.open( "integers" );

	for ( int i = 0; i < file_iter; i = i + 1 )
		if ( is_int( file[ i ] ) )
			fo << file[ i ] << '\n';

	fo.close();

	fo.open( "doubles" );

	for ( int i = 0; i < file_iter; i = i + 1 )
		if ( is_double( file[ i ] ) and ! is_int( file[ i ] ) )
			fo << file[ i ] << '\n';

	fo.close();

	fo.open( "strings" );

	for ( int i = 0; i < file_iter; i = i + 1 )
		if ( ! is_int( file[ i ] ) and ! is_double( file[ i ] ) )
			fo << file[ i ] << '\n';

	fo.close();

}


int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );


	set_files();


	return 0;
}
