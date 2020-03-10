#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

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

// converts a string to a char array
void string_to_chars ( string a, char chars[] ) 
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		chars[i] = a[i];
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



// file



int counter = 0;
string file = "";


// makes file that stores our counter
void make_count_file ()
{
	ofstream f;
	f.open( "count" );
	f << 0;
	f.close();
}

void get_count()
{
	fstream f;
	f.open( "count" );
	f >> counter;
	f.close();
}

// increases and saves counter if "count" file
void count()
{
	get_count();

	fstream f;
	make_count_file();
	make_count_file();

	f.open( "count" );
	counter = counter + 1;
	f << counter;
	f.close();
}


void save ( string filename )
{
	string choice;
	cout << "Want to commit? ( y / n ): ";
	cin >> choice;

	if ( choice[0] == 'y' )
	{
		fstream f;
		f.open( filename );
		string temp;
		getline( f, temp ); // to continue
		while ( getline( f, temp ) )
			file = file + temp + "\n";
		f.close();

		count();

		ofstream f_ofstream;
		string save_filename = filename + "_" + int_to_string( counter );
		f_ofstream.open( save_filename );
		f_ofstream << file;
		f_ofstream.close();
	}
}


int main ()
{
	save( "lnux1.cpp" );

	return 0;
}
