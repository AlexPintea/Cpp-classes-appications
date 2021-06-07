#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int l;

string data_files[ 1000 ]; // files that have vertical lists
int data_files_iter = 0;

string completion_files[ 1000 ]; // files that have [] with filenames of data files so that they can be replaced with any entry in the data file lists
int completion_files_iter = 0;

string used_data[ 1000 ]; // determine which data was used for every filename so that it does nto get repeted
string used_filename [ 1000 ];
int used_iter = 0;

void remove_extension ( string &a )
{
	int m = 0;

	while ( a[ m ] != '.' )
		m = m + 1;

	string result = "";
	for ( int o = 0; o < m; o = o + 1 )
		result = result + a[ o ];

	a = result;
}

void get_files ()
{
	ifstream fi;
	system( "cd completion && ls -p > \"../files\"" );
	fi.open( "files" );

	while ( getline( fi, completion_files[ completion_files_iter ] ) )
		completion_files_iter = completion_files_iter + 1;

	fi.close();

	system( "cd data && ls -p > \"../files\"" );
	fi.open( "files" );

	while ( getline( fi, data_files[ data_files_iter ] ) )
		data_files_iter = data_files_iter + 1;

	fi.close();

	system( "rm -r \"files\"" );

	for ( int i = 0; i < completion_files_iter; i = i + 1 )
		remove_extension( completion_files[ i ] );
	for ( int i = 0; i < data_files_iter; i = i + 1 )
		remove_extension( data_files[ i ] );
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();

	if ( file == "" )
	{
		cout << "File \"" << filename << "\" invalid.\n";
		return "";
	}

	file[ file.length() - 1 ] = '\0';

	return file;
}

bool paranthesis_are_closed ( string file )
{
	bool have = 0;

	for ( int i = 0; i < file.length(); i = i + 1 )
	{
		if ( file[ i ] == '[' )
		{
			if ( have == 0 )
				have = 1;
			else
				return 0;
		}

		if ( file[ i ] == ']' )
		{
			if ( have == 1 )
				have = 0;
			else
				return 0;
		}
	}

	if ( have == 1 )
		return 0;

	return 1;
}

void add_used ( string data, string filename )
{
	used_data[ used_iter ] = data;
	used_filename[ used_iter ] = filename;
	used_iter = used_iter + 1;
}

bool was_used ( string data, string filename )
{
	for ( int i = 0; i < used_iter; i = i + 1 )
		if ( used_data[ i ] == data && used_filename[ i ] == filename )
			return 1;

	return 0;
}

string get_data ( string filename )
{
	string data[ 1000 ];
	int data_iter = 0;

	ifstream fi;
	fi.open( "data/" + filename + ".txt" );

	while ( fi >> data[ data_iter ] )
		data_iter = data_iter + 1;

	int iter = 0; // get any value, and verify if was_used using above

	return data[ iter ];
}

string get_finalised ( int iter )
{
	string file = get_file( "completion/" + completion_files[ iter ] + ".txt" );
	if ( file == "" )
		return "";

	if ( paranthesis_are_closed( file ) == 0 )
	{
		cout << "Formatting of file \"" << completion_files[ iter ] << "\" invalid.\n";
		return "";	
	}

	string result = "";

	for ( int i = 0; i < file.length(); i = i + 1 )	
	{
		if ( file[ i ] == '[' )
		{
			string data = "";
			int e = i + 1;
			while ( file[ e ] != ']' )
			{
				data = data + file[ e ];
				e = e + 1;
			}

			i = e;

			result = result + get_data( data );
		}
		else
			result = result + file[ i ];
	}

	return result;
}

int main ()
{
	get_files();

	cout << get_finalised( 0 );

	return 0;
}
