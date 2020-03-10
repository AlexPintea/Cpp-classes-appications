#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

void make_file ( string filename )
{
	ofstream fo;
	fo.open( filename );
	fo.close();
}



int main ()
{

	string filename;
	cout << "Filename: ";
	getline( cin, filename );
	getline( cin, filename );

	string choice;
	cout << "Make the file ( y / n ): ";
	getline( cin, choice );

	if ( choice == "1" )
		make_file( filename );

	

	return 0;
}
