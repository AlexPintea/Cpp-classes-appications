#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string ext;
string filepath;
string file;


void filename_ext ()
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			have_ext = true;

			break;
		}
	}

	if ( ! have_ext )
		return;

	int d = 0;
	for ( int i = filename.length() - 1; i >= 0; i = i - 1 )
		if ( filename[ i ] != '/' )
			d = i;
		else
			break;

	filepath = "";
	for ( int i = 0; i < d; i = i + 1 )
		filepath = filepath + filename[ i ];

	string file_name = "";
	int l = 0;
	for ( int i = d; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}

		file_name = file_name + filename[ i ];
	}

	for ( int i = l; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' ) continue;	

		ext = ext + filename[ i ];
	}

	filename = file_name;
}
 

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );


	string temp;
	string files = "";
	while ( getline( fi, temp ) )
		files = files + temp + "\n";

	files[ files.length() - 1 ] = ' ';

	fi.close();

	return files;
}

string upper ( string a )
{
	if ( a.length() <= 0 )
		return a;

	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;

	return a;
}

void set_file ()
{
	ofstream fo;
	ifstream fi;

	fo.open( upper( filename ) + ".html" );

	fo << get_file( "maker files/site_1" );
	fo << upper( filename );
	fo << "</span> </h1>\n		</div>\n\n		<div class=\"file\"> <p> " << file;



	fo << get_file( "maker files/site_2" );

	fo.close();
}


int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );
	filename_ext();
	file = get_file( filename );
	if ( file == "" )
		cout << "\"" << filename << "\" invalid.";
	else

		set_file();



	return 0;
}
