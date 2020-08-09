#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
string filename;

string string_1;
string file;




int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
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
string replace_b_in_a ( string &a, string b, string replacement )
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

bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '	' and a[ l ] != '\n' )
			return false;
	return true;
}




string strings[ 1000 ];
string files[ 1000 ];
int strings_iter = 0;
int files_iter = 0;

void set_files ()
{
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( is_string_empty( strings[ i ] ) )
				continue;		

		files[ files_iter ] = file;


		replace_b_in_a( files[ files_iter ], string_1, strings[ i ] );
		files_iter = files_iter + 1;
	}
















	ofstream fo; 
	fo.open( filename );

	fo << file << "\n";

	for ( int i = 0; i < files_iter; i = i + 1 )
		fo << files[ i ] << "\n";

	fo.close();
}



bool get_file ()
{
	ifstream fi;
	fi.open( filename );

	file = "";
	string temp;

	getline( fi, string_1 ); 

	bool repeat = true;
	while ( getline( fi, temp ) )
	{ 
		if ( repeat )
		{
			if ( temp[ 0 ] == '(' and temp[ 1 ] == '(' and temp[ 2 ] == '(' and temp[ 3 ] == '(' and temp[ 4 ] == '(' )
			{		
				repeat = false;
				continue;
			}

			strings[ strings_iter ] = temp;

			strings_iter = strings_iter + 1;			
		}
		else
			file = file + temp + "\n";
	}




	fi.close();
	if ( repeat )
	{
		cout << "File invalid.\n";
		return false;
	}

	return true;
}




int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( get_file() ) 
		set_files();

	return 0;
}
