#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string filepath;
string ext;
string strings[ 10000 ];
int frev[ 10000 ];
int strings_iter = 0;


string max_strings[ 10000 ];
int max_iter = 0;

string line[ 10000 ];
int line_iter = 0;


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

int in_strings ( string a[], string b )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return i;
	return -1;
}

int in_string_frev ( string a, string b )
{
	string temps[ 10000 ];
	move_words( a, temps );

	int frevs = 0;

	int size = length( temps );
	for ( int i = 0; i < size; i = i + 1 )
		if ( temps[ i ] == b )
			frevs = frevs + 1;

	return frevs;
}


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


string file = "";
string files[ 10000 ];
int files_iter = 0;

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

	// for ( int i = 0; i < result.length(); i = i + 1 )
	//	if ( result[ i ] >= 'A' and result[ i ] <= 'Z' )
	//		result[ i ] = result[ i ] + 32;

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

void set_file ()
{
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	filename_ext();

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


string get_max_frev_string ( string a )
{
	string max_string = "";
	int frevs = 0;
	int l;

	for ( int i = 0; i < max_iter; i = i + 1 )
	{
		l = in_string_frev( a, max_strings[ i ] );

		if ( l > frevs )
		{
			frevs = l;
			max_string = max_strings[ i ];
		}
	}

	return max_string;
}




string common[ 10000 ];
int common_iter = 0;

void get_common ()
{
	ifstream fi;

	fi.open( "common" );

	string temp;
	while ( fi >> temp )
	{
		common[ common_iter ] = temp;
		common_iter = common_iter + 1;
	}

	fi.close();
}



bool is_common ( string a )
{
	for ( int i = 0; i < common_iter; i = i + 1 )
		if ( common[ i ] == a )
			return 1;
	return 0;
}

void get_max_strings ()
{
	string temp_string;
	int temp_frev;

	for ( int i = 0; i < strings_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < strings_iter; l = l + 1 )
			if ( frev[ i ] < frev[ l ] )
			{
				temp_string = strings[ i ];
				temp_frev = frev[ i ];
		
				strings[ i ] = strings[ l ];
				frev[ i ] = frev[ l ];

				strings[ l ] = temp_string;
				frev[ l ] = temp_frev;
			}


	for ( int i = 0; i <= strings_iter / 2; i = i + 1 )
	{
		max_strings[ max_iter ] = strings[ i ];
		max_iter = max_iter + 1;
	}
}

string lower ( string a )
{
	string result = "";
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			result = result + (char) ( a[ i ] + 32 );
		else
			result = result + a[ i ];
	return result;
}



string remove_chars ( string a )
{
	string result = "";



	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( ( a[ i ] >= 'a' and a[ i ] <= 'z' ) or ( a[ i ] >= '0' and a[ i ] <= '9' ) )
			result = result + a[ i ];

	return result;

}



void add_string ( string a )
{
	a = remove_chars( lower( a ) );
	if ( a == "" ) return;

	int l = in_strings( strings, a );

	if ( l != -1 )
		frev[ l ] = frev[ l ] + 1;
	else
	{
		strings[ strings_iter ] = a;
		frev[ strings_iter ] = 1;
		strings_iter = strings_iter + 1;	
	}
}


void get_file ()
{
	set_file();
	get_common();

	string temp;
	string temps[ 10000 ];

	for ( int i = 0; i < line_iter; i = i + 1 )
	{
		move_words( line[ i ], temps );
		for ( int i = 0; i < length( temps ); i = i + 1 )
		{
			if ( is_common( temps[ i ] ) )
				continue;
			add_string( temps[ i ] );
		}
	}


	get_max_strings();


	ofstream fo;
	if ( ext != "" )
		fo.open( filepath + filename + " result." + ext );
	else
		fo.open( filepath + filename + " result" );

	for ( int i = 0; i < max_iter; i = i + 1 )
	{
		bool have_line = 0;
		for ( int l = 0; l < line_iter; l = l + 1 )
			if ( get_max_frev_string( line[ l ] ) == max_strings[ i ] )
			{
				have_line = 1;
				break;
			}


		if ( ! have_line )
			continue;

		fo << max_strings[ i ] << ":\n\n";

		for ( int l = 0; l < line_iter; l = l + 1 )
			if ( get_max_frev_string( line[ l ] ) == max_strings[ i ] )
				fo << line[ l ] << '\n';

		fo << "\n\n";
	}

	bool have_remaining = 0;
	for ( int l = 0; l < line_iter; l = l + 1 )
		if ( get_max_frev_string( line[ l ] ) == "" )
		{

			have_remaining = 1;
			break;
		}

	if ( ! have_remaining )
	{
		fo.close();
		return;
	}

	fo << "Remaining:\n\n";

	for ( int i = 0; i < line_iter; i = i + 1 )
		if ( get_max_frev_string( line[ i ] ) == "" )
			fo << line[ i ] << '\n';

	fo << "\n\n";

	fo.close();
}


int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	get_file();

	return 0;
}
