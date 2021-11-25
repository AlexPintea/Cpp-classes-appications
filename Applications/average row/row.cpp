#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int l;

string filenames[ 1000 ];
int filenames_iter = 0;
float average = 0;
int count = 0;

int length ( string p[] )
{
	int i = 0;

	while ( p[ i ].length() > 0 )
		i = i + 1;

	return i;
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

void get_files ( string filepath, string files[] )
{
	command_linux( "path=\"$PWD\" && cd '" + filepath + "' && printf \"$PWD\\n\" > \"$path/files_for_you\" && ls -R -p >> \"$path/files_for_you\"" );

	ifstream fi;

	fi.open( "files_for_you" );

	string path;
	string temp;
	string folder;
	int files_iter = 0;

	getline( fi, folder );

	while ( getline( fi, temp ) )
	{
		if ( temp == "files_for_you" )
			continue;

		files[ files_iter ] = temp;
		files_iter = files_iter + 1;
	}


	fi.close();

	command_linux( "rm -r files_for_you" );
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

void get_average ()
{
	ifstream fi;
	fi.open( "averg" );

	fi >> average;
	fi >> count;

	fi.close();
}

float mlt ( float l1, int l2 )
{
	float sum = 0;

	for ( int i = 0; i < l2; i = i + 1 )
		sum = sum + l1;

	return sum;
}

void set_average ()
{
	ifstream fi;

	for ( int i = 0; i < filenames_iter; i = i + 1 )
	{
		string filename = filenames[ i ];
		string filepath;
		string ext;

		filename_ext_filepath ( filename, ext, filepath );

		string temp;

		if ( ext == "cpp" )
		{
			fi.open( filenames[ i ] );

			while ( getline ( fi, temp ) )
			{
				if ( average == 0.0 or count == 0 )
				{
					average = temp.length();
					count = 1;
					continue;
				}

				average = (float) ( mlt( average, count ) + temp.length() ) / ( count + 1 );
				count = count + 1;
			}

			int l;

			fi.close();
		}
	}

	ofstream fo;
	fo.open( "averg" );

	fo << average << ' ';
	fo << count;

	fo.close();
}

int main ()
{
	cout << "Folder for files: ";
	// /home/account/Computer/Proiecte/Dupa_Scoala/Info/Cpp-libraries-applications/Applications/average row

	string folder;

	getline( cin, folder );
	if ( folder == "" )
		getline( cin, folder );

	get_files( folder, filenames );
	filenames_iter = length( filenames );

	get_average();

	cout << "Previous average: ";

	cout << average << '\n';

	set_average();

	cout << "Improved average: ";	

	cout << average << '\n';

	cout << "Exited.\n";

	return 0;
}
