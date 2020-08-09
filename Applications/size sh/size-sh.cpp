#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


void string_to_char (string a, char result[])
{
	int size = a.length();

	int i;

	for (i=0; i<size; i=i+1)
		result[i] = a[i];

	result[i] = '\0';
}

void command ( string command_string )
{
	char command_char[1000];
	string_to_char( command_string, command_char );
	system( command_char );
}



string filename;

void get_count ()
{
	ofstream fo;
	fo.open( "size-sh" );
	fo.close();  // clear file


	fo.open( "size-sh" );
	fo << filename;
	fo.close();
	command( "./size.sh" );

	ifstream fi;
	fi.open( "size-sh" );

	double size;
	fi >> size;

	fi.close();
	cout << "Filesize: " << size / 1000 << "\n";

	cout << "Aproximated count: " << (long) ( size / ( 5 + 2 + 1.4 ) ) << "\n";


	fi.open( filename );

	string temp;
	int count = 0;
	while ( fi >> temp )
		count = count + 1;

	fi.close();

	cout << "File count: " << count << "\n";
}


int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );
	get_count();
	return 0;
}
