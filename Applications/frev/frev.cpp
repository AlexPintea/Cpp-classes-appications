#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filenames[ 1000 ];
int filenames_iter = 0;

string files[ 10000 ];
string results[ 10000 ];
int frev[ 10000 ];
int files_iter = 0;



int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}

bool is_string_empty( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
}

int in_files ( string a )
{
	for ( int i = 0; i < files_iter; i = i + 1 )
		if ( a == files[ i ] )
			return i;
	return -1;
}


int in_strings ( string a[], string b, int size )
{
	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return i;
	return -1;
}


// inverts a string
void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}

// is numeric char
bool is_numeric( char a )
{
	if ( a >= '0' and a <= '9' )
		return true;

	return false;
}

// converts an int to a string
string int_to_string (int a)
{
	int size = length(a);

	bool is_neg = false;
	if ( a < 0 )
	{
		is_neg = true;
		a = -a;
	}

	string result = "";

	for (int i=0; i<size; i=i+1)
	{	
		char a_char = (char) (a % 10 + 48);

		if ( is_numeric( a_char ) )
			result = result + a_char;
		a = a / 10;
	}

	if ( is_neg )
		result = result + '-';

	invert_string( result );

	return result;
}

void set_file ()
{
	string files_filename[ 10000 ];
	int frev_filename[ 10000 ];
	int files_filename_iter = 0;
	int is_in_files_filename;


	ifstream fi;
	int is_in_files;
	string temp;
	for ( int i = 0; i < filenames_iter; i = i + 1 )
	{
		results[ i ] = "\n\nResults in file \"" + filenames[ i ] + "\":\n";
		files_filename_iter = 0;

		fi.open( filenames[ i ] );
		while ( fi >> temp )
		{
			is_in_files = in_files( temp );
			if ( is_in_files != -1 )
				frev[ is_in_files ] = frev[ is_in_files ] + 1;
			else
			{
				files[ files_iter ] = temp;
				frev[ files_iter ] = 1;
				files_iter = files_iter + 1;
			}

			is_in_files_filename = in_strings( files_filename, temp, files_filename_iter );
			if ( is_in_files_filename != -1 )
				frev_filename[ is_in_files_filename ] = frev_filename[ is_in_files_filename ] + 1;
			else
			{
				files_filename[ files_filename_iter ] = temp;
				frev_filename[ files_filename_iter ] = 1;
				files_filename_iter = files_filename_iter + 1;
			}
		}
		fi.close();

		for ( int l = 0; l < files_filename_iter - 1; l = l + 1 )
			for ( int d = l + 1; d < files_filename_iter; d = d + 1 )
				if ( frev_filename[ d ] > frev_filename[ l ] )
				{
					temp = files_filename[ l ];
					is_in_files = frev_filename[ l ];

					files_filename[ l ] = files_filename[ d ];
					frev_filename[ l ] = frev_filename[ d ];

					files_filename[ d ] = temp;
					frev_filename[ d ] = is_in_files;
				}

		for ( int l = 0; l < files_filename_iter; l = l + 1 )
			results[ i ] = results[ i ] + '	' + int_to_string( l + 1 ) + ". " + files_filename[ l ] + " - frev: " + int_to_string( frev_filename[ l ] ) + '\n';

	}

	for ( int i = 0; i < files_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < files_iter; l = l + 1 )
			if ( frev[ l ] > frev[ i ] )
			{
				is_in_files = frev[ i ];
				temp = files[ i ];

				frev[ i ] = frev[ l ];
				files[ i ] = files[ l ];

				frev[ l ] = is_in_files;
				files[ l ] = temp;				
			}
	ofstream fo;
	fo.open( "result" );

	fo << "Results of:\n";
	for ( int i = 0; i < filenames_iter; i = i + 1 )
		fo << " \"" << filenames[ i ] << "\"\n";
	fo << "\n\n";

	for ( int i = 0; i < files_iter; i = i + 1 )
		fo << i + 1 << ". " << files[ i ] << " - frev: " << frev[ i ] << '\n';

	if ( filenames_iter != 1 )
		for ( int i = 0; i < filenames_iter; i = i + 1 )
			fo << results[ i ];

	fo << '\n';
	fo.close();
}


int main ()
{
	cout << "Filenames ( empty means done ):\n";
	string temp;
	getline( cin, temp );
	while ( ! is_string_empty( temp ) )
	{
		filenames[ filenames_iter ] = temp;
		filenames_iter = filenames_iter + 1;
		getline( cin, temp );
	}
	set_file();
	return 0;
}
