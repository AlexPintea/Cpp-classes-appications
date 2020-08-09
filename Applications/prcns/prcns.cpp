#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string file = "";
string strings[ 10000 ];
int strings_iter = 0;

double nums[ 10000 ];
string num_strings[ 10000 ];
int num_iters[ 10000 ];
int nums_iter = 0;

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
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

// converts a double to a string
string double_to_string ( double a )
{
	bool is_neg = false;
	if ( a < 0 )
		is_neg = true;

	int iter = length( (long) a );

	while ( (float) a - (long) a != 0.0 ) // 3 decimals maximum since float
		a = a * 10;



	int a_as_int;

	if ( is_neg )
		a_as_int = -(long) a;
	else
		a_as_int = (long) a;



	int size = length(a_as_int);

	int num_digits[170];
	for ( int i=0; i<size; i=i+1 )
	{
		num_digits[ size - i - 1 ] = (int) (a_as_int%10);
		a_as_int = a_as_int / 10;
	}


	string result = "";
	if ( is_neg )
		result = result + '-';
	for ( int i=0; i<size; i=i+1 )
	{
		if ( i == iter )
			result = result + '.';

		result = result + (char) ( num_digits[i] + 48 );
	}

	return result;
}

// check if a string is a long
bool is_long ( string a )
{
	int size = a.length();

	if ( size > 19 and a[0] == '-' )
		return false;
	if ( size >= 19 and a[0] != '-' )
		return false;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}
// convert string to long
long string_to_long ( string a )
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

	long num_long = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_long = num_long * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_long = -num_long;

	return num_long;
}

// check if a string is a double
bool is_double ( string a )
{
	int size = a.length();
	bool have_decimals = false;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( !( ( a[i] >= '0' and a[i] <= '9' ) or a[i] == '.' or a[i] == '-' ) )
			return false;
		if ( a[i] == '.' )
			have_decimals = true;
	}

	if ( have_decimals )
		return true;

	return false;
}
// convert string to double
double string_to_double ( string a )
{
	if ( a.length() == 1 )
		return a[0] - 48;

	if ( is_long( a ) )
		return string_to_long(a);


	double num_double = 0;

	int i = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		i = 1;
	}


	while ( a[i] != '.' )
	{
		num_double = num_double * 10 + ( a[i] - 48 );
		i = i + 1;
	}

	i = i + 1;
	int decimal_tens = 10;

	while ( a[i] )
	{
		double temp = a[i] - 48;
		num_double = num_double + temp / decimal_tens ;
		decimal_tens = decimal_tens * 10;
		i = i + 1;
	}

	if ( is_neg )
		num_double = -num_double;

	return num_double;
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

int in_ints ( int a[], int size, int b )
{
	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return i;

	return -1;
}













bool pos ( string a )
{
	if ( a[ 0 ] != '-' )
		return 1;
	return 0;
}

string reduce_length ( string a )
{
	if ( a.length() <= 4 ) return a;

	string result = "";
	for ( int i = 0; i < 4; i = i + 1 )
		result = result + a[ i ];
	return result;
}

bool is_numeric ( string a )
{
	int size = a.length();

	for ( int i = 0; i < size; i = i + 1 )
		if ( ! (  ( a[ i ] >= '0' and a[ i ] <= '9' ) or a[ i ] == '.' ) )
			return 0;
	return 1;
}

string reduce_num ( string a )
{
	if ( ! is_numeric( a ) ) return a;
	int size = a.length();

	string result = "";
	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] >= '0' and a[ i ] <= '9' or a[ i ] == '.' )
			result = result + a[ i ];
	return result;
}







void get_file ()
{
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + "\n";

	fi.close();


	fi.open( filename );

	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}

	fi.close();


	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		string a = reduce_num( strings[ i ] );

		if ( is_double( a ) or is_long( a ) )
		{
			if ( ! pos( a ) ) continue;
			nums[ nums_iter ] = string_to_double( a );
			if ( nums[ nums_iter ] == 0 ) continue;		
			num_strings[ nums_iter ] = a;
			num_iters[ nums_iter ] = i;
			nums_iter = nums_iter + 1;
		}
	}

	double sum = 0;


	for ( int i = 0; i < nums_iter; i = i + 1 )
		sum = sum + nums[ i ];

	for ( int i = 0; i < nums_iter; i = i + 1 )
		nums[ i ] = nums[ i ] / sum;

	for ( int i = 0; i < nums_iter; i = i + 1 )
	{
		double num = nums[ i ];
		for ( int l = 0; l < 100; l = l + 1 )
			nums[ i ] = nums[ i ] + num;
	}


	ofstream fo;
	fo.open( "result" );
	fo.close(); // clear file

	fo.open( "result" );

	int l = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( num_iters[ l ] == i )
		{
			fo << '(' << strings[ i ] << ") ";
			fo << "- ( " << nums[ l ] << " / 100 )\n";
			l = l + 1;
		}
		else
			fo << strings[ i ] << ' ';
	}

	cout << "Results.\n";
	fo.close();
}






int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	get_file();
	return 0;
}
