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
	cout << "Welcome to File!\n\n";

	usleep( 900000 );

	cout << "Details:\n";

	usleep( 540000 );

	cout << "details of file are details of file" << '\n';
	usleep( 490000 );

	cout << "details of file are details of file" << '\n';
	usleep( 490000 );

	cout << "details of file are details of file" << '\n';
	usleep( 490000 );

	cout << "details of file are details of file" << '\n';
	usleep( 490000 );

	cout << "details of file are details of file" << '\n';
	usleep( 490000 );

	usleep( 100000 );

	return 0;
}
