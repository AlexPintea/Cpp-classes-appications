#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string file[ 10000 ];
int file_iter = 0;

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();
	return file;
}

void get_file ( string filename, string strings[] )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
	{
		strings[ file_iter ] = temp;
		file_iter = file_iter + 1;
	}

	fi.close();
}


string upper ( string a )
{
	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;
	return a;
}


void filename_ext_filepath ( string &filename, string &ext, string &filepath )
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
		if ( filename[ i ] == '.' )
		{
			have_ext = true;
			break;
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





bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}















int main ()
{
	cout << "Choices:  1. Add String  2. Add File\n";
	string choice;
	cout << "Choice: ";
	getline( cin, choice );


	string filename;

	if ( choice != "2" )
	{
		cout << "Name: ";
		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		cout << "Details ( empty means done ):\n";
	
		string temp = "details";
		while ( ! is_string_empty( temp ) )
		{
			getline( cin, temp );
			if ( is_string_empty( temp ) )
				break;

			file[ file_iter ] = temp;
			file_iter = file_iter + 1;
		}
	}

	if ( choice == "2" )
	{
		string ext;
		string filepath;

		cout << "Filename: ";
		getline( cin, filename );

		get_file( filename, file );

		filename_ext_filepath( filename, ext, filepath );
	}

	ofstream fo;
	fo.open( "result.cpp" );

	fo << get_file( "type files/type" );

	fo << "int main ()\n";
	fo << "{\n";
	fo << "	cout << \"Welcome to " << upper( filename ) << "!\\n\\n\";\n\n";
	fo << "	usleep( 900000 );\n\n";
	fo << "	cout << \"Details:\\n\";\n\n";
	fo << "	usleep( 540000 );\n\n";

	for ( int i = 0; i < file_iter; i = i + 1 )
		fo << "	cout << \"" << file[ i ] << "\" << \'\\n\';\n	usleep( 490000 );\n\n";

	fo << "	usleep( 100000 );\n\n";

	fo << "	return 0;\n";
	fo << "}\n";

	fo.close();

	return 0;
}
