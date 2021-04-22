#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string double_to_string ( double a )
{
	ofstream fo;
	fo.open( "convert" );

	fo << a;

	fo.close();


	string result;

	ifstream fi;
	fi.open( "convert" );

	fi >> result;

	fi.close();

	return result;
}


int main ()
{
	cout << double_to_string( 9.01 ) << "\n";
	return 0;
}
