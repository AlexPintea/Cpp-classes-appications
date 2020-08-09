#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;



// desktop files do not actually "gnome-terminal -e filename"



string large_char ( string a )
{
	if ( a[0] >= 'a' and a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}

void make_desktop ( string filename )
{

	// makes / clears the file
	ofstream file;
	file.open( filename + ".desktop" );
	file.close();


	file.open( filename + ".desktop" );

	file << "[Desktop Entry]\n";
	file << "Name=" << large_char( filename ) << "\n";
	file << "Exec=gnome-terminal -e " << filename << "\n";
	file << "Icon=utilities-terminal\n";
	file << "Type=Application";


	file.close();	
}

int main ()
{
	string filename;
	cout << "Filename: ";
	getline( cin, filename );

	make_desktop( filename );

	return 0;
}
