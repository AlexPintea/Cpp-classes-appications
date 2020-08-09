#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


void set_file ( string filename )
{
	ifstream fi;
	fi.open( filename );
	string temp;
	string file = "";
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();

	cout << "\033cFile: \"file\":\n\n";
	cout << file;
}


int main ()
{
	while ( 1 == 1 )
		set_file( "file" );

	return 0;
}
