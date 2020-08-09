#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string filename;
string ext;
string filepath;
string choice;

ofstream file;

void filename_ext_filepath ( string &filename, string &ext, string &filepath )
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

void set_file()
{
	filename_ext_filepath( filename, ext, filepath );

	ifstream fi;


	if ( choice == "1" )
		fi.open( "file_choices/file_choices" );
	else
		fi.open( "file_choices/files_choices" );

	file.open( filepath + filename + ".cpp" );

	string temp;
	while ( getline( fi, temp ) )
		file << temp << '\n';

	file.close();

	fi.close();

	cout << "File \"" << filename << ".cpp\" done.";
	if ( filepath != "" )
		cout << " ( Filepath: \"" << filepath << "\" )";
	cout << '\n';
}


int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )	
		getline( cin, filename );

	cout << "Choices:  1. File  2. Files\n";
	cout << "Choice: ";

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	set_file();
	return 0;
}
