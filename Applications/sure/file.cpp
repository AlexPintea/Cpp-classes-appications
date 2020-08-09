#include <string>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

long long a ( short int &ints, string strings[], double doubles ){ return 9; }


int main ()
{
	short int ints[ 4 ];
	for ( int i=0; i<2; i=i+1 )
		ints[i] = i;

	string strings[ 9 ];
	for ( int i=0; i<7; i=i+1 )
		strings[i] = "";
	for ( int i=0; i<7; i=i+1 )
	{
		for ( int l=0; l<=i; l=l+1 )
			strings[i] = strings[i] + (char) ( l % 127 + 32 );
	}
	double doubles[ 9 ];
	for ( int i=0; i<7; i=i+1 )
		doubles[i] = i;

	ofstream fo;
	fo.open( "results" );
	fo.close();

	fo.open( "results" );
	for ( int i_1 = 0; i_1 < 2; i_1 = i_1 + 1 )
		for ( int i_2 = 0; i_2 < 7; i_2 = i_2 + 1 )
			for ( int i_3 = 0; i_3 < 7; i_3 = i_3 + 1 )
			{
				fo << "ints = \'" << ints[ i_1 ] << "\' ";
 fo << "strings[] ";
				fo << "doubles = \'" << doubles[ i_3 ] << "\' ";
 				fo << "a = " << a( ints[ i_1 ], strings, doubles[ i_3 ] ) << "   ";
				fo << "&ints = \'" << ints[ i_1 ] << "\' ";
 				fo << "\n";
			}
	fo.close();

	return 0;
}