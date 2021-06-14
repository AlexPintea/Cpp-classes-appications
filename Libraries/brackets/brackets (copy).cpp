#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

template<int x, int y>

int length_1 ( double a[1000][ 3 ] )
{
	int i=0;

	while ( a[i][0] )
		i = i + 1;

	return i;
}

int length_2 ( double a[1000][ 3 ] )
{
	int i=0;

	while ( a[0][i] )
		i = i + 1;

	return i / length_1(a);
}



double maximum( double a[][ 3 ] )
{
	double maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}

long maximum( long a[][ 3 ] )
{
	long maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}

int maximum( int a[][ 3 ] )
{
	int maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}



int main ()
{

	double a[3][3] = { 1,   4.1, 2.7,
					   4.9, 3,   2, 
					   3,   0.1, 2  };

	cout << sizeof(a) / sizeof(a[0]) << "\n\n";

	cout << length_1(a) << "\n";
	cout << length_2(a) << "\n\n";

	cout << maximum( a ) << "\n";

	return 0;
}
