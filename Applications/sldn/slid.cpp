#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

string get_string ( string a, int l )
{
	string result = "";
	for ( int i = l; i < a.length(); i = i + 1 )
		result = result + a[ i ];

	return result;
}




int main ()
{
	string a = "   -S-/-L-/-I-/-D-";

	cout << "\033c\n" << get_string( a, 17 ) << "\n\n";
	usleep( 10000 );
	cout << "\033c\n" << get_string( a, 16 ) << "\n\n";
	usleep( 10000 );
	cout << "\033c\n" << get_string( a, 15 ) << "\n\n";
	usleep( 10000 );
	cout << "\033c\n" << get_string( a, 14 ) << "\n\n";
	usleep( 10000 );
	cout << "\033c\n" << get_string( a, 13 ) << "\n\n";
	usleep( 21000 );
	cout << "\033c\n" << get_string( a, 12 ) << "\n\n";
	usleep( 21000 );
	cout << "\033c\n" << get_string( a, 11 ) << "\n\n";
	usleep( 90000 );
	cout << "\033c\n" << get_string( a, 10 ) << "\n\n";
	usleep( 90000 );
	cout << "\033c\n" << get_string( a, 9 ) << "\n\n";
	usleep( 90000 );
	cout << "\033c\n" << get_string( a, 8 ) << "\n\n";
	usleep( 150000 );
	cout << "\033c\n" << get_string( a, 7 ) << "\n\n";
	usleep( 150000 );
	cout << "\033c\n" << get_string( a, 6 ) << "\n\n";
	usleep( 150000 );
	cout << "\033c\n" << get_string( a, 5 ) << "\n\n";
	usleep( 150000 );
	cout << "\033c\n" << get_string( a, 4 ) << "\n\n";
	usleep( 150000 );
	cout << "\033c\n" << get_string( a, 3 ) << "\n\n";
	usleep( 210000 );
	cout << "\033c\n" << get_string( a, 2 ) << "\n\n";
	usleep( 210000 );
	cout << "\033c\n" << get_string( a, 1 ) << "\n\n";
	usleep( 259000 );
	cout << "\033c\n" << get_string( a, 0 ) << "\n\n";
	usleep( 259000 );
	usleep( 950000 );

	return 0;
}
