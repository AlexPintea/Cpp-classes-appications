#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


void remove_last ( string &l )
{
	int size = l.length();

	string result= "";

	for ( int i = 0; i < size - 1; i = i + 1 )
		result = result + l[ i ];

	l = result;
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string file = "";
	string temp;

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	remove_last( file );

	fi.close();

	return file;
}

void get_wh ( string file, long &wh, long &not_wh )
{
	int size = file.length();

	wh = 0;
	not_wh = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( file[ i ] == ' ' or file[ i ] == '\n' or file[ i ] == '	' )
			wh = wh + 1;
		else
			not_wh = not_wh + 1;
	}
}



int main ()
{
	string filename = "file";
	string file = get_file( filename );
	long wh;
	long not_wh;

	get_wh( file, wh, not_wh );

	cout << "Whitespace: " << wh << " bytes ( " << (float) wh / file.length() * 100 << "% )\n";
	cout << "Not whitespace: " << not_wh << " bytes ( " << (float) not_wh / file.length() * 100 << "% )\n";
	cout << "Filesize: " << file.length() + 1 << " bytes\n";


	return 0;
}
