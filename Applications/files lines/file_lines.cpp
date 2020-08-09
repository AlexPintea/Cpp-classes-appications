#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


void set_file ( string filename )
{
	ofstream fo;
	fo.open( "result.cpp" );
	fo.close(); // clear file

	fo.open( "result.cpp" );

	ifstream fi;
	fi.open( "files_lines/file_lines" );
	string temp;

	while ( getline( fi, temp ) )
		fo << temp << '\n';

	fi.close();

	fo << "\n\nint main ()\n{\n	while ( 1 == 1 )\n		set_file( \"" << filename << "\" );\n\n	return 0;\n}";

	fo.close();
}


int main ()
{
	string filename;
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );
	set_file( filename );
	return 0;
}
