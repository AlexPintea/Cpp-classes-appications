#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string choice;
string file = "";
string phrase;
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

	int l;
	for ( int i=0; i<size; i=i+1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
		{
			l = i;
			break;
		}

	for ( int i=l; i<size; i=i+1 )
	{
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



void set_file ()
{
	ifstream fi;
	fi.open( filename );

	string temp;
	if ( choice == "1" or choice == "2" )
	{
		while ( fi >> temp )
		{
			files[ files_iter ] = temp;
			files_iter = files_iter + 1;
		}
	}
	else
	{
		while ( getline( fi, temp ) )
			file = file + temp + '\n';
	}

	fi.close();

	ofstream fo;
	if ( choice == "3" )
	{
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


		fo.open( filename );

		fo << file;
		fo.close();

		fi.open( filename );

		while ( getline( fi, temp ) )
		{
			if ( is_string_empty ( temp ) )
				continue;
			files[ files_iter ] = reduce_string( temp );
			files_iter = files_iter + 1;
		}

		fi.close();
	}

	fo.open( filename );



	if ( choice == "1" )
	{
		for ( int i = 0; i < files_iter; i = i + 1 )
			fo << files[ i ] << ' ';		
	}

	if ( choice == "2" or choice == "3" )
	{
		for ( int i = 0; i < files_iter; i = i + 1 )
			fo << files[ i ] << '\n';		
	}

	fo.close();
}




int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );


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





	set_file();

	return 0;
}
