#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string files[ 1000 ];
int files_iter = 0;

void clear_dots ( string &path )
{
	int size = path.length();

	path[ size - 1 ] = '/';

	string result = "";

	for ( int i = 1; i < size; i = i + 1 )
		result = result + path[ i ];

	path = result;
}

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

bool is_string_empty ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;

	return 1;
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


void get_files ( string filepath )
{
	command_linux( "path=\"$PWD\" && cd '" + filepath + "' && printf \"$PWD\\n\" > \"$path/files\" && ls -R -p >> \"$path/files\"" );

	ifstream fi;

	fi.open( "files" );

	string path;
	string temp;
	string folder;

	getline( fi, folder );

	while ( getline( fi, path ) )
	{
		clear_dots( path );

		temp = "not empty";
		while ( 1 )
		{
			getline( fi, temp );
			if ( is_string_empty( temp ) )
				break;
			if ( temp[ temp.length() - 1 ] != '/' )
			{
				files[ files_iter ] = folder + path + temp;
				files_iter = files_iter + 1;
			}
		}
	} 

	fi.close();

	command_linux( "rm -r files" );
}

int main ()
{
	get_files( "/home/account/C apl/unzip/zips" );

	string path;
	string ext;
	string temp;
	string extract;

	for ( int i = 0; i < files_iter; i = i + 1 )
	{
		temp = files[ i ];

		filename_ext_filepath( temp, ext, path );

		extract = "";
		if ( ext == "zip" or ext == "zip" or ext == "gz" or ext == "tar" or ext == "xz" )
			extract = "unzip";

		if ( ext == "rar" )
			extract = "unrar";

		if ( extract == "" )
			continue;

			command_linux( "cd \"" + path + "\" && mkdir \"" + temp + "\" && mv \"" + temp + ".zip\" \"" + temp + '/' + temp + ".zip\" && cd \"" + temp + "\" && unzip \"" + temp + ".zip\" && cd ../ && mv \"" + temp + '/' + temp + ".zip\" \"" + temp + ".zip\"" );
	}

	return 0;
}
