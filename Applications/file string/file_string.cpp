#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filenames[ 10000 ];
int filenames_iter = 0;

string choice;
string file = "";
string phrase = "";
string remain;
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




void remove_last_char ( string &a )
{
	string result = "";

	for ( int i = 0; i < a.length() - 1; i = i + 1 )
		result = result + a[ i ];

	a = result;
}

string reduce_string ( string &a )
{
	int size = a.length();

	string result = "";

	int l;
	for ( int i=0; i<size; i=i+1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
		{
			l = i;
			break;
		}

	for ( int i=l; i<size; i=i+1 )
	{
		if ( phrase != "" )
			if ( a[ i ] == phrase[ 0 ] )
			{
				bool have_phrase = 1;
				int a_iter = i;
				for ( int d = 0; d < phrase.length(); d = d + 1 )
				{
					if ( phrase[ d ] != a[ a_iter ] )
					{
						have_phrase = 0;
						break;
					}
					a_iter = a_iter + 1;
				}

				if ( have_phrase )
				{
					result = result + phrase;
					break;
				}
			}
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + ' ';
	}

	if ( result[ result.length() - 1 ] == ' ' or result[ result.length() - 1 ] == '\n' or result[ result.length() - 1 ] == '	' )
		remove_last_char( result );
	// for ( int i = 0; i < result.length(); i = i + 1 )
	//	if ( result[ i ] >= 'A' and result[ i ] <= 'Z' )
	//		result[ i ] = result[ i ] + 32;

	return result;
}


bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}

void set_file ()
{
	ifstream fi;

	for ( int l = 0; l < filenames_iter; l = l + 1 )
	{
		fi.open( filenames[ l ] );

		string temp;
		if ( choice == "1" )
		{
			while ( fi >> temp )
			{
				files[ files_iter ] = temp;
				files_iter = files_iter + 1;
			}
		}
		if ( choice == "2" )
		{
			while ( getline( fi, temp ) )
			{

				if ( is_string_empty( temp ) )
					continue;
				files[ files_iter ] = reduce_string( temp );
				files_iter = files_iter + 1;
			}
		}

		if ( choice == "3" )
		{
			while ( getline( fi, temp ) )
			{
				if ( is_string_empty( temp ) )
					continue;
				file = file + temp + '\n';
			}

			fi.close();

			for ( int i = 0; i < file.length(); i = i + 1 )
				if ( file[ i ] == '\n' )
					file[ i ] = ' ';

			for ( int i = 0; i < file.length(); i = i + 1 )
				if ( file[ i ] == phrase[ 0 ])
				{
					bool have_phrase = 1;
					int file_iter = i;
					for ( int d = 0; d < phrase.length(); d = d + 1 )
					{
						if ( phrase[ d ] != file[ file_iter ] )
						{
							have_phrase = 0;
							break;
						}
						file_iter = file_iter + 1;
					}

					if ( have_phrase )
					{
						insert_char( file, '\n', i + phrase.length() );
					}
				}


			ofstream fo;
			fo.open( "lines" );

			fo << file;
			fo.close();

			fi.open( "lines" );

			while ( getline( fi, temp ) )
			{

				if ( is_string_empty ( temp ) )
					continue;
				files[ files_iter ] = reduce_string( temp );
				files_iter = files_iter + 1;
			}
		}

		fi.close();
	}

	ofstream fo;
	fo.open( "result" );

	if ( remain == "1" )
	{
		fo << "\"";
		for ( int i = 0; i < files_iter; i = i + 1 )
			fo << files[ i ] << "\\n";
		fo << "\"";
	}

	if ( remain == "2" )
	{
		fo << "[ ";
		for ( int i = 0; i < files_iter; i = i + 1 )
		{
			fo << '"' << files[ i ] << '"';
			if ( i != files_iter - 1 )
				fo << ", ";
		}
		fo << " ]";
	}

	if ( remain == "3" )
	{
		fo << "[ ";
		for ( int i = 0; i < files_iter; i = i + 1 )
		{
			fo << files[ i ];
			if ( i != files_iter - 1 )
				fo << ", ";
		}
		fo << " ]";
	}

	fo.close();
}


int main ()
{
	cout << "file string\n";
	cout << "Filenames ( empty means done ):\n";
	string temp;
	getline( cin, temp );
	if ( temp == "" )
		getline( cin, temp );
	while ( ! is_string_empty( temp ) )
	{
		filenames[ filenames_iter ] = temp;
		filenames_iter = filenames_iter + 1;
		getline( cin, temp );
	}

	cout << "Choices:  1. Spaces  2. Lines  3. Phrase lines\n";
	cout << "Choice: ";

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );
	
	if ( choice == "3" )
	{
		string delimited;
		cout << "Phrase delimited by '.' ( y / n ): ";
		getline( cin, delimited );
		if ( delimited == "" )
			getline( cin, delimited );

		if ( delimited != "y" )
		{
			cout << "Phrase delimited with: ";
			getline( cin, phrase );
			if ( phrase == "" )
				getline( cin, phrase );	
		}
		else
			phrase = ".";
	}


	cout << "Choices:  1. String  2. String List ( with \"\" )  2. Double List ( with , )\n";
	cout << "Choice: ";

	getline( cin, remain );
	if ( remain == "" )
		getline( cin, remain );

	set_file();

	return 0;
}
