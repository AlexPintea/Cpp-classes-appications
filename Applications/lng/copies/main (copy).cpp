#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string real[ 50 ];
string user[ 50 ];
int iter = 0;

string data_path = "data";


void get_user_real ()
{
	ifstream fi;

	fi.open( data_path + "/data" );

	while ( fi >> real[ iter ] )
	{
		fi >> user[ iter ];
		iter = iter + 1;
	}

	fi.close();

	string swap;
	for ( int i = 0; i < iter - 1; i = i + 1 )
		for ( int l = i + 1; l < iter; l = l + 1 )
			if ( user[ i ] > user[ l ] )
			{
				swap = user[ i ];
				user[ i ] = user[ l ];
				user[ l ] = swap;

				swap = real[ i ];
				real[ i ] = real[ l ];
				real[ l ] = swap;				
			}
}

string get_file ( string filename )
{
	string file = "";
	string temp;

	ifstream fi;
	fi.open( filename );

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	return file;
}

// a[] and b[] have iters
bool is_in ( int a[], int b[], int size, int iter )
{
	for ( int i=0; i<size; i=i+1 )
		if ( iter >= a[i] and iter <= b[i] )
			return true;

	return false;
}

bool is_char_empty ( char l )
{
	if ( l == ' ' or l == '\n' or l == '	' )
		return 1;
	return 0;
}

bool have_at_pos ( string a, int pos, string b )
{
	int size_a = a.length();
	int size_b = b.length();

	if ( pos + size_b - 1 >= size_a or pos < 0 or pos > size_a )
		return 0;

	for ( int i = 0; i < size_b; i = i + 1 )
		if ( a[ pos + i ] != b[ i ] )
			return 0;

	return 1;
}

string convert ( string filename )
{
	string a = get_file( filename );

	int size_a = a.length();

	string result = "";

	bool had_at_pos = 0;

	for ( int i = 0; i < size_a; i = i + 1 )
	{
		for ( int l = 0; l < iter; l = l + 1 )
			if ( have_at_pos( a, i, user[ l ] ) )
			{
				result = result + real[ l ];
				i = i + user[ l ].length() - 1;
				had_at_pos = 1;
				break;
			}

		if ( ! had_at_pos )
			result = result + a[ i ];
		else
			had_at_pos = 0;
	}

	return result;
}

void set_file ( string filename, string file )
{
	ofstream fo;

	fo.open( filename );
	fo.close(); // clear file

	fo.open( filename );

	fo << file;

	fo.close();
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

int main ()
{
	cout << "lng ";

	string filename = "user";
	string filepath;
	string ext;
	filename_ext_filepath( filename, ext, filepath );

	int kl;

	get_user_real();
	set_file( data_path + '/' + filename + ".cpp", convert( filename ) );

	return 0;
}
