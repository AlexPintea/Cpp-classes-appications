#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename_1;
string filename_2;




void filename_ext ( string filename, string ext, string filepath )
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


void insert_char ( string &a, char b, int pos )
{
	if ( pos < 0 or pos >= a.length() )
		return;

	string result = "";

	for ( int i = 0; i < a.length(); i = i + 1 )
	{
		if ( i == pos )
			result = result + b;
		result = result + a[ i ];
	}

	a = result;
}


string reduce_string ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
	{
		if ( a[ i ] == '.' )
			continue;
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";
	}

	for ( int i = 0; i < result.length(); i = i + 1 )
		if ( result[ i ] >= 'A' and result[ i ] <= 'Z' )
			result[ i ] = result[ i ] + 32;

	return result;
}

bool is_string_empty( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
}



void remove_char ( string &a )
{
	string result = "";

	int l;

	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
		{
			l = i;

			break;
		}

	for ( int i = l; i < a.length(); i = i + 1 )
		result = result + a[ i ];

	a = result;
}


void set_file ( string &filename )
{
	ifstream fi;
	fi.open( filename );


	string line[ 10000 ];
	int line_iter = 0;

	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	string ext;
	string filepath;
	filename_ext( filename, ext, filepath );

	for ( int i = 0; i < file.length(); i = i + 1 )
		if ( file[ i ] == '.' and i != file.length() - 1 )
			insert_char( file, '\n', i + 1 );

	ofstream fo;
	fo.open( filename + " lines" );
	fo.close(); // clears file

	fo.open( filename + " lines" );
	fo << file;
	fo.close();

	fi.open( filename + " lines" );

	while ( getline( fi, temp ) )
	{
		if ( is_string_empty ( temp ) )
			continue;
		line[ line_iter ] = reduce_string( temp );
		remove_char( line[ line_iter ] );
		line_iter = line_iter + 1;
	}

	fi.close();


	fo.open( filename + " lines" );
	fo.close(); // clears file

	fo.open( filename + " lines" );

	for ( int i = 0; i < line_iter; i = i + 1 )
		fo << line[ i ] << '\n';

	fo.close();
}



int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() )
		i = i + 1;
	return i;
}

void move_words ( string text, string words[] )
{
	for ( int i = 0; i < length( words ); i = i + 1 )
		words[ i ] = "";

	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}


int common ( string a, string b )
{
	string a_temps[ 10000 ];	
	string b_temps[ 10000 ];
	move_words( a, a_temps );
	move_words( b, b_temps );

	int a_iter = length( a_temps );
	int b_iter = length( b_temps );
	int common = 0;
	for ( int i = 0; i < a_iter; i = i + 1 )
		for ( int l = 0; l < b_iter; l = l + 1 )
			if ( a_temps[ i ] == b_temps[ l ] )
				common = common + 1;
	return common;
}




void get_files ()
{
	set_file( filename_1 );
	set_file( filename_2 );

	string file_1[ 10000 ];
	int file_1_iter = 0;

	string file_2[ 10000 ];
	int file_2_iter = 0;

	ifstream fi;
	string temp;
	fi.open( filename_1 + " lines" );

	while ( getline( fi, temp ) )
	{
		file_1[ file_1_iter ] = temp;
		file_1_iter = file_1_iter + 1;
	}
	fi.close();

	fi.open( filename_2 + " lines" );

	while ( getline( fi, temp ) )
	{
		file_2[ file_2_iter ] = temp;
		file_2_iter = file_2_iter + 1;
	}
	fi.close();

	int common_files = 0;
	int common_lines = 0;
	int common_strings;
	for ( int i = 0; i < file_1_iter; i = i + 1 )
		for ( int l = 0; l < file_2_iter; l = l + 1 )
		{
			common_strings = common( file_1[ i ], file_2[ l ] );
			common_files = common_files + common_strings;
			if ( common_strings != 0 )
				common_lines = common_lines + 1;
		}

	cout << common_files << " are common in " << common_lines << " lines of both files.\n";
}
int main ()
{
	cout << "Filename 1: ";
	getline( cin, filename_1 );
	if ( filename_1 == "" )
		getline( cin, filename_1 );

	cout << "Filename 2: ";
	getline( cin, filename_2 );
	if ( filename_2 == "" )
		getline( cin, filename_2 );
	get_files();
	return 0;
}
