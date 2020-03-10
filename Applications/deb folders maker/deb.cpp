#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void command( string a )
{
	char result[100];
	int size = a.length();
	int i;
	for (i=0; i<size; i=i+1)
		result[i] = a[i];
	
	result[i] = '\0';

	system( result );
}


string name;

int main ()
{
	cout << "Enter application name: ";
	getline(cin, name);
	cout << endl;

	// makes / clears file
	ofstream deb_sh;
	deb_sh.open( "deb-sh" );
	deb_sh.close();

	deb_sh.open( "deb-sh" );
	deb_sh << name;
	deb_sh.close();	

	command( "./deb.sh" );

	cout << "Place your files in \"" << name << "\" folder.\n";
	cout << "Make sure to modify file \"" << name << "/DEBIAN/config\".\n";
	cout << "In order to make \'" << name << ".deb\': dpkg-deb --build " << name << "\n";

	return 0;
}
