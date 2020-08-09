#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


// checks if  a  is in  b   or   b  is in  a  for datatype "string"
bool a_is_in_b ( string a, string b )
{
	if (a == b)
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	return a_is_in_b( a, b );
}


string filename;
string strings[ 10000 ];
string swaps[ 10000 ];
int strings_iter = 0;
bool is_string_empty ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
}


void swap_strings ()
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";
	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	string result = "";

	for ( int i = 0; i < file.length(); i = i + 1 )
	{
		bool have_swaps = 0;

		for ( int l = 0; l < strings_iter; l = l + 1 )
		{
			if ( i + strings[ l ].length() < file.length() and strings[ l ][ 0 ] == file[ i ] )
			{
				bool have_string = 1;
				for ( int d = 1; d < strings[ l ].length(); d = d + 1 )
					if ( strings[ l ][ d ] != file[ i + d ] )
					{
						have_string = 0;
						break;
					}

				if ( have_string )
				{
					result = result + swaps[ l ];
					have_swaps = 1;
					i = i + strings[ l ].length() - 1;
				}
			}

			if ( i + swaps[ l ].length() < file.length() and swaps[ l ][ 0 ] == file[ i ] )
			{
				bool have_string = 1;
				for ( int d = 1; d < swaps[ l ].length(); d = d + 1 )
					if ( swaps[ l ][ d ] != file[ i + d ] )
					{
						have_string = 0;
						break;
					}

				if ( have_string )
				{
					result = result + strings[ l ];
					have_swaps = 1;
					i = i + swaps[ l ].length() - 1;

				}
			}

		}

		if ( have_swaps )
			continue;

		result = result + file[ i ];
	}

	ofstream fo;
	fo.open( filename );
	fo.close(); // clear file

	fo.open( filename );
	fo << result;
	fo.close();
}




int main ()
{

	cout << "choice\n";

	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	cout << "( empty means done )\n";

	string temp;
	cout << "Swap: ";
	getline( cin, temp );
	while ( ! is_string_empty( temp ) )
	{
		strings[ strings_iter ] = temp;

		temp = "";

		while ( is_string_empty( temp ) or strings[ strings_iter ] == temp )	
		{
			cout << "Swap \"" << strings[ strings_iter ] << "\" with: ";
			getline( cin, temp );
		}


		swaps[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;

		cout << "Swap: ";
		getline( cin, temp );
	}

	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( b_is_in_a( swaps[ i ], strings[ i ] ) and strings[ i ] != swaps[ i ] )
		{
			temp = strings[ i ];
			strings[ i ] = swaps[ i ];
			swaps[ i ] = temp;
		}

	string temp_swap;
	for ( int i = 0; i < strings_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < strings_iter; l = l + 1 )
			if ( strings[ i ] > strings[ l ] )
			{
				temp = strings[ i ];
				temp_swap = swaps[ i ];

				strings[ i ] = strings[ l ];
				swaps[ i ] = swaps[ l ];

				strings[ l ] = temp;
				swaps[ l ] = temp_swap;
			}

	swap_strings();

	cout << "Exited.\n";

	return 0;
}
