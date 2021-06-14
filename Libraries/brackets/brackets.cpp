#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

template<int x, int y>
int length_1 ( double (&a)[x][y] )
{
	int i=0;

	while ( a[i][0] )
		i = i + 1;

	return i;
}

template<int x, int y>
int length_2 ( double (&a)[x][y] )
{
	int i=0;

	while ( a[0][i] )
		i = i + 1;

	while ( i % length_1(a) != 0 )
		i = i + 1;

	return i / length_1(a);
}


template<int x, int y>
int length_1 ( string (&a)[x][y] )
{
	int i=0;

	while ( a[i][0].length() > 0 )
		i = i + 1;

	return i;
}

template<int x, int y>
int length_2 ( string (&a)[x][y] )
{
	int i=0;

	while ( a[0][i].length() > 0 )
		i = i + 1;

	while ( i % length_1(a) != 0 )
		i = i + 1;


	return i / length_1(a);
}


template<int x, int y>
int length_1 ( char (&a)[x][y] )
{
	int i=0;

	while ( a[i][0] )
		i = i + 1;

	return i;
}

template<int x, int y>
int length_2 ( char (&a)[x][y] )
{
	int i=0;

	while ( a[0][i] )
		i = i + 1;

	while ( i % length_1(a) != 0 )
		i = i + 1;


	return i / length_1(a);
}




template<int x, int y>
double maximum( double (&a)[x][y] )
{
	double maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}

template<int x, int y>
long maximum( long (&a)[x][y] )
{
	long maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}

template<int x, int y>
int maximum( int (&a)[x][y] )
{
	int maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}

template<int x, int y>
char maximum( char (&a)[x][y] )
{
	char maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}

template<int x, int y>
string maximum( string (&a)[x][y] )
{
	string maximum = a[0][0];

	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
			if ( a[i][l] > maximum )
				maximum = a[i][l];

	return maximum;
}



template<int x, int y>
void arr ( string (&a)[x][y], string result[] )
{
	int counter = 0;
	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
		{
			result[ counter ] = a[i][l];
			counter = counter + 1;
		}
}

template<int x, int y>
void arr ( char (&a)[x][y], char result[] )
{
	int counter = 0;
	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
		{
			result[ counter ] = a[i][l];
			counter = counter + 1;
		}
}

template<int x, int y>
void arr ( long (&a)[x][y], long result[] )
{
	int counter = 0;
	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
		{
			result[ counter ] = a[i][l];
			counter = counter + 1;
		}
}

template<int x, int y>
void arr ( int (&a)[x][y], int result[] )
{
	int counter = 0;
	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
		{
			result[ counter ] = a[i][l];
			counter = counter + 1;
		}
}

template<int x, int y>
void arr ( double (&a)[x][y], double result[] )
{
	int counter = 0;
	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
		{
			result[ counter ] = a[i][l];
			counter = counter + 1;
		}
}

template<int x, int y>
void arr ( float (&a)[x][y], float result[] )
{
	int counter = 0;
	for ( int i=0; i<length_1( a ); i=i+1 )
		for ( int l=0; l<length_2( a ); l=l+1 )
		{
			result[ counter ] = a[i][l];
			counter = counter + 1;
		}
}







template<int x, int y>
void arr_invert ( double a[], double (&res)[x][y] )
{
	int x1 = x - 1;
 	int y1 = y - 1;

	int i=0;
	int i1=0;
	int i2=0;

	while ( a[i] )
	{
		if ( i1 == x1 and i2 == y1 )
			return;

		if ( i2 == y1 + 1 and i1 < x1 )
		{
			i1 = i1 + 1;
			i2 = 0;
		}

		res[ i1 ][ i2 ] = a[i];

		i = i + 1;
		i2 = i2 + 1;
	}
}


int main ()
{

	double a_double[14][14] = { 1,   4.1, 2.7,
					            4.9, 3,   2, 
					            3,   0.1, 2  };

	string a_string[14][14] = { "a", "ab", "bl",
					            "b", "b",  "p", 
					            "o", "l",  "m"  };

	char a_char[14][14] = { '1', 'a', 'p',
					        'b', 'p', 'm', 
					        '7', 'l', 'r'  };



	cout << sizeof(a_double) / sizeof(a_double[0]) << "\n\n";

	cout << length_1(a_double) << "\n";
	cout << length_2(a_double) << "\n\n";

	cout << maximum(a_double) << "\n";
	cout << maximum(a_string) << "\n";
	cout << maximum(a_char) << "\n";


	int i=0;
	string arr_string[1000];
	arr( a_string, arr_string );
	while ( arr_string[i].length() > 0 )
	{
		cout << arr_string[i] << " ";
		i = i + 1;
	}
	cout << "\n\n";

	double l_string[7][9];
	double l_arr[1000] = { 1, 4, 3, 2, 4, 5, 3, 2, 6,      3, 2, 5, 6, 4, 2, 3, 9, 4,      3, 1, 5, 1, 4, 2, 3, 1, 9 };

	arr_invert( l_arr, l_string );

	cout << length_1(l_string) << "\n";
	cout << length_2(l_string) << "\n";


	for ( int i=0; i<length_1( l_string ); i=i+1 )
	{
		for ( int l=0; l<length_2( l_string ); l=l+1 )
			cout << l_string[i][l] << "  ";
		cout << "\n";
	}
	cout << "\n";

	return 0;
}
