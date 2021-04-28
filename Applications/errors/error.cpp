#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void show_error ( string filename )
{
	ifstream fi;
	fi.open( "error/" + filename );

	string temp;
	while ( getline( fi, temp ) )
		cout << temp << '\n';

	fi.close();
}

int main ()
{
	show_error( "error1" );
	show_error( "error2" );

	return 0;
}
