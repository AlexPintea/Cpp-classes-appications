#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int n;
string feature[ 90 ];
string name;

void string_to_char (string a, char result[])
{
	int size = a.length();

	int i;

	for (i=0; i<size; i=i+1)
		result[i] = a[i];

	result[i] = '\0';
}

void command_linux ( string command_string )
{
	char command_char[1000];
	string_to_char( command_string, command_char );
	system( command_char );
}

void set_file()
{
	ofstream fo;
	fo.open( name + ".sh" );

	fo << "printf \"" << name << ": \\n\"\n";

	for ( int i = 0; i < n; i = i + 1 )
		fo << "printf \"" << i + 1 << ". " << feature[ i ] << "\\n\"\n";
	fo << "\n\n";

	fo << "printf \"\\nChoice: \"\n";
	fo << "read choice\n\n";

	for ( int i = 0; i < n; i = i + 1 )
	{
		fo << "if [ $choice = \"" << i + 1 << "\" ]\n";
		fo << "then\n";
		fo << "	code=\"\"\n";
		fo << "fi\n\n";
	}

	fo.close();
	command_linux( "chmod 767 \"" + name + ".sh\"" );
}


int main ()
{
	cout << "Name: ";
	getline( cin, name );


	cout << "Features: ";
	cin >> n;

	for ( int i = 0; i < n; i = i + 1 )
	{
		cout << "Feature " << i + 1 << ": ";
		getline( cin, feature[ i ] );
		if ( feature[ i ] == "" )
			getline( cin, feature[ i ] );
	}
	set_file();

	return 0;
}
