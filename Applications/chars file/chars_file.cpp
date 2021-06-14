#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string common[ 150 ];
char chr[ 150 ];
int iter = 0;

string strings[ 1000 ];
int strings_frev[ 1000 ];
int strings_iter = 0;

// get file data
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

	return file;
}

int length ( string m[] )
{
	int p = 0;

	while ( m[ p ].length() > 0 )
		p = p + 1;

	return p;
}


// checks if  a  is in  b   or   b  is in  a  for datatype "string"
bool a_is_in_b ( string a, string b )
{
	if (a == b)
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	return a_is_in_b( a, b );
}

// a[] and b[] have iters
bool is_in ( int a[], int b[], int size, int iter )
{
	for ( int i=0; i<size; i=i+1 )
		if ( iter >= a[i] and iter <= b[i] )
			return true;

	return false;
}

// replace  b  in  a  for datatype "string"
string replace_b_in_a ( string &a, string b, char replacement )
{
	if ( !b_is_in_a( a, b ) )
		return a;

	int size_a = a.length();
	int size_b = b.length();

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}


	for ( int i=0; i<size_a; i=i+1 )
	{
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			result = result + a[i];
		else
		{
			result = result + replacement;
			while ( is_in( iter_1, iter_2, size_iter, i ) )
				i = i + 1;
			i = i - 1;
		}
	}

	a = result;

	return a;
}

// replace  b  in  a  for datatype "string"
string replace_b_in_a ( string &a, char b, string replacement )
{
	int size_a = a.length();

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b )
			result = result + replacement;
		else
			result = result + a[i];

	a = result;

	return a;
}

int is_in_strings ( string o[], string p )
{
	int size = length( o );

	for ( int i = 0; i < size; i = i + 1 )
		if ( o[ i ] == p )
			return i;

	return -1;
}

// converts a string to a char array
void string_to_chars ( string a, char chars[] ) 
{
	int size = a.length();

	int i;

	for ( i=0; i<size; i=i+1 )
		chars[i] = a[i];
	chars[i] = '\0';
}

// linux command
void command_linux ( string command_string )
{
	char command_chars[1000];
	string_to_chars( command_string, command_chars );
	system( command_chars );
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




void encode_file ( string filename )
{
	ifstream fi;

	fi.open ( filename );

	string temp;
	int i;

	while ( fi >> temp )
	{
		i = is_in_strings( strings, temp );

		if ( i != -1 )
			strings_frev[ i ] = strings_frev[ i ] + 1;
		else
		{
			strings[ strings_iter ] = temp;
			strings_iter = strings_iter + 1;
		}
	}

	fi.close();

	if ( strings_iter == 0 )
	{
		cout << "Filename invalid.\n";
		return;
	}

	string swap_string;
	int swap_int;

	for ( int i1 = 0; i1 < strings_iter - 1; i1 = i1 + 1 )
		for ( int i2 = 0; i2 < strings_iter - 1; i2 = i2 + 1 )
			if ( strings_frev[ i1 ] > strings_frev[ i2 ] )
			{
				swap_string = strings[ i1 ];
				strings[ i1 ] = strings[ i2 ];
				strings[ i2 ] = swap_string;

				swap_int = strings_frev[ i1 ];
				strings_frev[ i1 ] = strings_frev[ i2 ];
				strings_frev[ i2 ] = swap_int;
			}


	int l = 0;

	for ( int i = 0; i < 129; i = i + 1 )
	{
		if ( strings[ l ].length() == 1 )
		{
			l = l + 1;
			continue;
		}

		common[ i ] = strings[ l ];
		chr[ i ] = (char) i + 127;

		l = l + 1;
	}

	ofstream fo;

	fo.open( "data" );
	fo.close();

	fo.open( "data" );

	for ( int i = 0; i < 129; i = i + 1 )
	{
		if ( common[ i ] == "" )
			continue;

		fo << common[ i ] << ' ';
		fo << chr[ i ] << '\n';
	}

	fo.close();

	string file = get_file( filename );

	for ( int i = 0; i < 129; i = i + 1 )
		replace_b_in_a ( file, common[ i ], chr[ i ] );

	fo.open( "file_data" );
	fo.close();

	fo.open( "file_data" );

	fo << file;

	fo.close();

	command_linux( "zip data_folder data file_data" );
	command_linux( "rm -r file_data" );
	command_linux( "rm -r data" );

	string ext;
	string filepath;

	filename_ext_filepath( filename, ext, filepath );

	if ( filepath == "" )
		command_linux( "mv data_folder.zip '" + filename + ".zip'" );
	else
		command_linux( "mv data_folder.zip '" + filepath + filename + ".zip'" );

	if ( filepath == "" )
		cout << "File converted to \"" + filename + ".zip\"\n";
	else
		cout << "File converted to \"" + filename + ".zip\" ( " + filepath + " )\n";
}

void decode_file ( string filename )
{
	command_linux ( "mkdir data_folder && cp '" + filename + "' data_folder && cd data_folder && unzip '" + filename + "' && cd ../ && mv data_folder/data data && mv data_folder/file_data file_data && rm -r data_folder" );

	ifstream fi;

	fi.open ( "data" );

	while ( fi >> common[ iter ] )
	{
		fi >> chr[ iter ];
		iter = iter + 1;
	}

	fi.close();

	string file = get_file( "file_data" );

	for ( int i = 0; i < iter; i = i + 1 )
		replace_b_in_a ( file, chr[ i ], common[ i ] );

	string ext;
	string filepath;

	filename_ext_filepath ( filename, ext, filepath );

	ofstream fo;
	fo.open( "result" );
	fo.close();

	fo.open( "result" );

	fo << file;

	fo.close();

	// filepath + '/' + filename + ".txt"

	command_linux ( "mv result '" + filepath + '/' + filename + ".txt'" );
}

int main ()
{
	cout << "Choices:  1. Encode file  2. Decode file\n";

	cout << "Choice: ";

	string choice;

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "1" or choice == "2" )
	{
		cout << "Filename: ";

		string filename;

		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		if ( choice == "1" ) // add file
		{
			encode_file( filename );
		}

		if ( choice == "2" )
		{
			decode_file( filename );
		}
	}

	cout << "Exited\n";

	return 0;
}
