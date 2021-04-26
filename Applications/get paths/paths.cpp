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

void get_paths ( string filepath, string paths, int option )
{
	command_linux( "path=\"$PWD\" && cd '" + filepath + "' && printf \"$PWD\\n\" > \"$path/files\" && ls -R -p >> \"$path/files\"" );

	ifstream fi;
	ofstream fo;

	fi.open( "files" );
	fo.open( paths );

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
			if ( option == 1 && temp[ temp.length() - 1 ] != '/' )
			{
				files[ files_iter ] = folder + path + temp;
				fo << files[ files_iter ] << '\n';
				files_iter = files_iter + 1;
			}
			if ( option == -1 && temp[ temp.length() - 1 ] == '/' )
			{
				files[ files_iter ] = folder + path + temp;
				fo << files[ files_iter ] << '\n';
				files_iter = files_iter + 1;
			}
			if ( option == 0 )
			{
				files[ files_iter ] = folder + path + temp;
				fo << files[ files_iter ] << '\n';
				files_iter = files_iter + 1;
			}
		}
	} 

	fi.close();
	fo.close();

	command_linux( "rm -r files" );
}

int main ()
{
	get_paths( "/home/account/C apl/unzip/zips", "paths", 1 );

	return 0;
}
