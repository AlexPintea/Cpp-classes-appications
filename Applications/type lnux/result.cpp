#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

string get_string ( string a, int l )
{
	string result = "";
	for ( int i = 0; i < l; i = i + 1 )
		result = result + a[ i ];

	return result;
}




int main ()
{
	string a = "string size\n\nstring \n\nstring size\n\nstring \n\nstring size\n";

	cout << "\033c" << get_string( a, 0 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 1 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 2 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 3 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 4 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 5 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 6 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 7 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 8 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 9 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 10 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 11 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 12 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 13 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 14 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 15 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 16 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 17 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 18 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 19 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 20 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 21 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 22 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 23 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 24 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 25 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 26 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 27 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 28 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 29 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 30 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 31 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 32 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 33 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 34 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 35 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 36 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 37 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 38 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 39 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 40 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 41 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 42 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 43 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 44 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 45 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 46 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 47 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 48 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 49 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 50 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 51 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 52 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 53 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 54 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 55 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 56 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 57 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 58 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 59 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 60 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 61 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 62 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 63 ) << '\n';
	usleep( 150000 );

	cout << "\033c" << get_string( a, 64 ) << '\n';
	usleep( 150000 );

	usleep( 210000 );

	return 0;
}
