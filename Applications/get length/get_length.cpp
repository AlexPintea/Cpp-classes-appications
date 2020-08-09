#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filenames[ 10000 ];
string results[ 10000 ];
int filenames_iter = 0;
string choice;
int length = 0;

string strings[ 10000 ];
int strings_iter = 0;


int length_num ( int a )
{
	if ( a == 0 ) return 1;
	int i = 0;

	while ( a != 0 )
	{
		i = i + 1;
		a = a / 10;
	}

	return i;
}

bool is_length ( string a )
{
	if ( choice == "1" )
	{

		if ( a.length() >= length )
			return 1;
		return 0;
	}

	if ( choice == "2" )
	{
		if ( a.length() <= length )
			return 1;
		return 0;
	}


	if ( a.length() == length )
		return 1;
	return 0;
}

bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}

void num_digits ( int a, char result[] )
{
	int i=0;
	int size = length_num(a);

	while (a != 0)
	{
		result[ size - i - 1 ] = a%10 + 48;
		i=i+1;
		a=a/10;
	}
}

string int_to_string( int a )
{
	string result = "";
	char digits[10];
	
	int size = length_num(a);
	num_digits( a, digits );
	
	for ( int i=0; i<size; i=i+1 )
	{
		result = result + digits[i];
	}
	
	return result;
}

void get_files ()
{
	ifstream fi;

	string temp;
	for ( int i = 0; i < filenames_iter; i = i + 1 )
	{
		fi.open( filenames[ i ] );

		results[ i ] = "\nResults in \"" + filenames[ i ] + "\":\n";
		
		int l = 0;
		while ( fi >> temp )
		{
			l = l + 1;
			if ( ! is_length( temp ) )
				continue;
			results[ i ] = results[ i ] + "  '" + temp + "' - line " + int_to_string( l ) + '\n';

			strings[ strings_iter ] = '"' + filenames[ i ] + "\": '" + temp + "' - line " + int_to_string( l );
			strings_iter = strings_iter + 1;
		}
		results[ i ] = results[ i ] + "\n";

		fi.close();
	}

	ofstream fo;
	fo.open( "result" );
	fo.close(); // clear file


	fo.open( "result" );


	if ( strings_iter == 0 )
	{
		fo << "Results invalid for ";
		fo << "( length ";
		if( choice == "1" ) { fo << "greater " << length; }
		if( choice == "2" ) { fo << "fewer " << length; }
		if( choice == "3" or ( choice != "1" and choice != "2" ) ) { fo << "= " << length; }
		fo << " ) of:\n";
		for ( int i = 0; i < filenames_iter; i = i + 1 )
			fo << "  \"" << filenames[ i ] << "\"\n";
		fo << '\n';
		return;
	}

	fo << "Results ( length ";
	if( choice == "1" ) { fo << "greater " << length; }
	if( choice == "2" ) { fo << "fewer " << length; }
	if( choice == "3" or ( choice != "1" and choice != "2" ) ) { fo << "= " << length; }
	fo << " ) of:\n";
	for ( int i = 0; i < filenames_iter; i = i + 1 )
		fo << "  \"" << filenames[ i ] << "\"\n";
	fo << '\n';


	for ( int i = 0; i < strings_iter; i = i + 1 )
		fo << "  " << strings[ i ] << '\n';
	fo << '\n';
	

	if ( filenames_iter != 1 )
		for ( int i = 0; i < filenames_iter; i = i + 1 )
			fo << results[ i ];

	fo.close();
}


int main ()
{
	cout << "String length: ";
	cin >> length;

	cout << "Choices:  1. Larger  2. Fewer  3. Equal\n";
	cout << "Choice: ";

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );


	cout << "Filenames ( empty means done ):\n";

	string temp;
	getline( cin, temp );
	while ( ! is_string_empty( temp ) )
	{
		if ( is_string_empty( temp ) )
			break;

		filenames[ filenames_iter ] = temp;
		filenames_iter = filenames_iter + 1;
		getline( cin, temp );
	}
	get_files();

	return 0;
}
