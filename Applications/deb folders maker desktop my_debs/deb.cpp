#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void command( string a )
{
	char result[1000];
	int size = a.length();
	int i;
	for (i=0; i<size; i=i+1)
		result[i] = a[i];
	
	result[i] = '\0';

	system( result );
}

string filepath;
string name;

string get_name ( string filepath )
{
	string result = "";
	for ( int i=0; i<filepath.length(); i=i+1 )
	{
		result = result + filepath[i];

		if ( filepath[i] == '/' )
			result = "";
	}

	return result;
}

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
	file.open( name + ".desktop" );
	file.close();


	file.open( name + ".desktop" );

	file << "[Desktop Entry]\n";
	file << "Name=" << large_char( filename ) << "\n";
	file << "Exec=gnome-terminal -e /usr/my_debs/" << filename << "\n";
	file << "Icon=utilities-terminal\n";
	file << "Type=Application";


	file.close();	
}


int main ()
{
	cout << "Enter application filepath: ";
	getline(cin, filepath);
	cout << endl;


	name = get_name( filepath );

	command( "cp \"" + filepath + "\" \"/usr/my_debs/" + name + "\"" );

	cout << name << "\n\n";

	make_desktop( name );

	// makes / clears file
	ofstream deb_sh;
	deb_sh.open( "deb-sh" );
	deb_sh.close();

	deb_sh.open( "deb-sh" );
	deb_sh << name;
	deb_sh.close();	

	command( "./deb.sh" );

	return 0;
}
