#include <string>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;








// inverts a string
void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}

bool is_numeric ( char a )
{
	if ( a == '0' ) return true;
	if ( a == '1' ) return true;
	if ( a == '2' ) return true;
	if ( a == '3' ) return true;
	if ( a == '4' ) return true;
	if ( a == '5' ) return true;
	if ( a == '6' ) return true;
	if ( a == '7' ) return true;
	if ( a == '8' ) return true;
	if ( a == '9' ) return true;
	
	return false;
}

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

// convert string to int
int string_to_int ( string a )
{
	if ( a.length() == 1 )
		return a[0] - 48;

	int size = a.length();

	int iter = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		iter = 1;
	}

	int num_int = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_int = num_int * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_int = -num_int;

	return num_int;
}




string css[ 100000 ];

void set_css ( string &line )
{
	while ( b_is_in_a( line, "css_" ) )
	{
		int l;
		for ( int i = 0; i < line.length() - 4; i = i + 1 )
			if ( line[ i ] == 'c' and line[ i + 1 ] == 's' and line[ i + 2 ] == 's' and line[ i + 3 ] == '_' )
			{
				l = i + 4;
				break;
			}

		string num_string = "";

		while ( is_numeric( line[ l ] ) )
		{
			num_string = num_string + line[ l ];
			l = l + 1;
		}

		int num = string_to_int( num_string );

		replace_b_in_a ( line, "css_" + num_string, css[ num ] );
	}
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string file = "";

	string temp;
	while ( getline( fi, temp ) )
	{
		set_css( temp );
		file = file + temp + "\n";
	}

	fi.close();

	return file;
}

void set_file ( string filename, string file )
{
	ofstream fo;
	fo.open( filename );
	fo.close();

	fo.open( filename );

	fo << file;

	fo.close();
}





void have_css ()
{
	css[0] = "border: 2px solid color;";
}




 

int main ()
{
	have_css();

	string filename_1;
	cout << "Css filename: ";
	getline( cin, filename_1 );

	string filename_2;
	cout << "Result filename: ";
	getline( cin, filename_2 );

	set_file( filename_2, get_file( filename_1 ) );

	return 0;
}
