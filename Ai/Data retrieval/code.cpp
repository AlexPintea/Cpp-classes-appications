#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int ints[1000];
int iter = 0;
string filename = "file";
int step = 5;

void get_ints()
{
	ifstream fi;
	fi.open( filename );

	while ( fi >> ints[ iter ] )
		iter = iter + 1;

	fi.close();

	int swap;
	for ( int i1 = 0; i1 < iter - 1; i1 = i1 + 1 )
		for ( int i2 = i1 + 1; i2 < iter; i2 = i2 + 1 )
			if ( ints[ i1 ] > ints[ i2 ] )
			{
				swap = ints[ i1 ];
				ints[ i1 ] = ints[ i2 ];
				ints[ i2 ] = swap;
			}
}

void decide ()
{
	cout << "{ ";
	for ( int i = 0; i < iter - 1; i = i + 1 )
	{
		if ( ints[ i + 1 ] - ints[ i ] > step )
		{
			cout << ints[ i ] << " ], [ " << ints[ i + 1 ] << ' ';
			i = i + 1;
			continue;
		}

		cout << ints[ i ] << ' ';
	}
	cout << "] ";
}

int main ()
{
	get_ints();
	decide();

	return 0;
}
