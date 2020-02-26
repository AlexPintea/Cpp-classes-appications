#include <string.h>
#include <iostream>
#include <string>

using namespace std;



// lengths



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

int length(int a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(long a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(float a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(double a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(bool a[])  // does not return validly
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(char a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length (string a)
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length ( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
}





// int[]





int empty_int[10000] = {};

// empties an int[]
void empty ( int a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_int[i];
}

// is in int[]
bool is_in_ints ( int ints[], int a )
{
	int size = length( ints );

	for ( int i=0; i<size; i=i+1 )
		if ( ints[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_int_at ( int ints[], int iter )
{
	int size = length( ints );

	int remaining_ints[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_ints[ iter_remaining ] = ints[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( ints );

	for ( int i=0; i<iter_remaining; i=i+1 )
		ints[i] = remaining_ints[i];
}

// removes all ints-s  a  of int[]  ints  
void remove_ints_at ( int ints[], int iters[] )
{
	int size = length( ints );

	int ints_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				ints_removed[iter] = ints[i];
				iter = iter + 1;
			}

	empty( ints );

	for ( int i=0; i<iter; i=i+1 )
		ints[i] = ints_removed[i];
}

// removes all ints-s  a  of int[]  ints  
void remove_ints ( int ints[], int remove[] )
{
	int size = length( ints );

	int ints_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( remove, ints[i] ) )
			{
				ints_removed[iter] = ints[i];
				iter = iter + 1;
			}

	empty( ints );

	for ( int i=0; i<iter; i=i+1 )
		ints[i] = ints_removed[i];
}

// removes all ints-s  a  of int[]  ints  
void remove_int ( int ints[], int a )
{
	int size = length( ints );
	int iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( ints[i] != a )
		{
			iters[ iter ] = ints[i];
			iter = iter + 1;
		}

	empty( ints );

	for ( int i=0; i<iter; i=i+1 )
		ints[i] = iters[i];
}


// add  int  to  int[]  
void add_int ( int ints[], int a )
{
	int size = length( ints );

	ints[ size ] = a;
}

// add  int[]  to   int[]  
void add_ints ( int ints[], int add[] )
{
	int size_ints = length( ints );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		ints[ size_ints + i ] = add[i];
}



// long[]



long empty_long[10000] = {};

// empties a long[]
void empty ( long a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_long[i];
}

// is in long[]
bool is_in_longs ( long longs[], long a )
{
	int size = length( longs );

	for ( int i=0; i<size; i=i+1 )
		if ( longs[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_long_at ( long longs[], int iter )
{
	int size = length( longs );

	long remaining_longs[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_longs[ iter_remaining ] = longs[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( longs );

	for ( int i=0; i<iter_remaining; i=i+1 )
		longs[i] = remaining_longs[i];
}

// removes all longs-s  a  of long[]  longs  
void remove_longs_at ( long longs[], int iters[] )
{
	int size = length( longs );

	long longs_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				longs_removed[iter] = longs[i];
				iter = iter + 1;
			}

	empty( longs );

	for ( int i=0; i<iter; i=i+1 )
		longs[i] = longs_removed[i];
}

// removes all longs-s  a  of long[]  longs  
void remove_longs ( long longs[], long remove[] )
{
	int size = length( longs );

	long longs_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_longs( remove, longs[i] ) )
			{
				longs_removed[iter] = longs[i];
				iter = iter + 1;
			}

	empty( longs );

	for ( int i=0; i<iter; i=i+1 )
		longs[i] = longs_removed[i];
}

// removes all longs-s  a  of long[]  longs  
void remove_long ( long longs[], long a )
{
	int size = length( longs );
	long iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( longs[i] != a )
		{
			iters[ iter ] = longs[i];
			iter = iter + 1;
		}

	empty( longs );

	for ( int i=0; i<iter; i=i+1 )
		longs[i] = iters[i];
}


// add  long  to  long[]  
void add_long ( long longs[], long a )
{
	int size = length( longs );

	longs[ size ] = a;
}

// add  long[]  to   long[]  
void add_longs ( long longs[], long add[] )
{
	int size_longs = length( longs );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		longs[ size_longs + i ] = add[i];
}



// double[]



double empty_double[10000] = {};

// empties a double[]
void empty ( double a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_double[i];
}

// is in double[]
bool is_in_doubles ( double doubles[], double a )
{
	int size = length( doubles );

	for ( int i=0; i<size; i=i+1 )
		if ( doubles[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_double_at ( double doubles[], int iter )
{
	int size = length( doubles );

	double remaining_doubles[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_doubles[ iter_remaining ] = doubles[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( doubles );

	for ( int i=0; i<iter_remaining; i=i+1 )
		doubles[i] = remaining_doubles[i];
}

// removes all doubles-s  a  of double[]  doubles  
void remove_doubles_at ( double doubles[], int iters[] )
{
	int size = length( doubles );

	double doubles_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				doubles_removed[iter] = doubles[i];
				iter = iter + 1;
			}

	empty( doubles );

	for ( int i=0; i<iter; i=i+1 )
		doubles[i] = doubles_removed[i];
}

// removes all doubles-s  a  of double[]  doubles  
void remove_doubles ( double doubles[], double remove[] )
{
	int size = length( doubles );

	double doubles_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_doubles( remove, doubles[i] ) )
			{
				doubles_removed[iter] = doubles[i];
				iter = iter + 1;
			}

	empty( doubles );

	for ( int i=0; i<iter; i=i+1 )
		doubles[i] = doubles_removed[i];
}

// removes all doubles-s  a  of double[]  doubles  
void remove_double ( double doubles[], double a )
{
	int size = length( doubles );
	double iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( doubles[i] != a )
		{
			iters[ iter ] = doubles[i];
			iter = iter + 1;
		}

	empty( doubles );

	for ( int i=0; i<iter; i=i+1 )
		doubles[i] = iters[i];
}


// add  double  to  double[]  
void add_double ( double doubles[], double a )
{
	int size = length( doubles );

	doubles[ size ] = a;
}

// add  double[]  to   double[]  
void add_doubles ( double doubles[], double add[] )
{
	int size_doubles = length( doubles );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		doubles[ size_doubles + i ] = add[i];
}



// float[]



float empty_float[10000] = {};

// empties a float[]
void empty ( float a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_float[i];
}

// is in float[]
bool is_in_floats ( float floats[], float a )
{
	int size = length( floats );

	for ( int i=0; i<size; i=i+1 )
		if ( floats[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_float_at ( float floats[], int iter )
{
	int size = length( floats );

	float remaining_floats[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_floats[ iter_remaining ] = floats[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( floats );

	for ( int i=0; i<iter_remaining; i=i+1 )
		floats[i] = remaining_floats[i];
}

// removes all floats-s  a  of float[]  floats  
void remove_floats_at ( float floats[], int iters[] )
{
	int size = length( floats );

	float floats_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				floats_removed[iter] = floats[i];
				iter = iter + 1;
			}

	empty( floats );

	for ( int i=0; i<iter; i=i+1 )
		floats[i] = floats_removed[i];
}

// removes all floats-s  a  of float[]  floats  
void remove_floats ( float floats[], float remove[] )
{
	int size = length( floats );

	float floats_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_floats( remove, floats[i] ) )
			{
				floats_removed[iter] = floats[i];
				iter = iter + 1;
			}

	empty( floats );

	for ( int i=0; i<iter; i=i+1 )
		floats[i] = floats_removed[i];
}

// removes all floats-s  a  of float[]  floats  
void remove_float ( float floats[], float a )
{
	int size = length( floats );
	float iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( floats[i] != a )
		{
			iters[ iter ] = floats[i];
			iter = iter + 1;
		}

	empty( floats );

	for ( int i=0; i<iter; i=i+1 )
		floats[i] = iters[i];
}


// add  float  to  float[]  
void add_float ( float floats[], float a )
{
	int size = length( floats );

	floats[ size ] = a;
}

// add  float[]  to   float[]  
void add_floats ( float floats[], float add[] )
{
	int size_floats = length( floats );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		floats[ size_floats + i ] = add[i];
}



// char[]



char empty_char[10000] = {};

// empties a char[]
void empty ( char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_char[i];
}

// is in char[]
bool is_in_chars ( char chars[], char a )
{
	int size = length( chars );

	for ( int i=0; i<size; i=i+1 )
		if ( chars[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_char_at ( char chars[], int iter )
{
	int size = length( chars );

	char remaining_chars[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_chars[ iter_remaining ] = chars[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( chars );

	for ( int i=0; i<iter_remaining; i=i+1 )
		chars[i] = remaining_chars[i];
}

// removes all chars-s  a  of char[]  chars  
void remove_chars_at ( char chars[], int iters[] )
{
	int size = length( chars );

	char chars_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				chars_removed[iter] = chars[i];
				iter = iter + 1;
			}

	empty( chars );

	for ( int i=0; i<iter; i=i+1 )
		chars[i] = chars_removed[i];
}

// removes all chars-s  a  of char[]  chars  
void remove_chars ( char chars[], char remove[] )
{
	int size = length( chars );

	char chars_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_chars( remove, chars[i] ) )
			{
				chars_removed[iter] = chars[i];
				iter = iter + 1;
			}

	empty( chars );

	for ( int i=0; i<iter; i=i+1 )
		chars[i] = chars_removed[i];
}

// removes all chars-s  a  of char[]  chars  
void remove_char ( char chars[], char a )
{
	int size = length( chars );
	char iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( chars[i] != a )
		{
			iters[ iter ] = chars[i];
			iter = iter + 1;
		}

	empty( chars );

	for ( int i=0; i<iter; i=i+1 )
		chars[i] = iters[i];
}


// add  char  to  char[]  
void add_char ( char chars[], char a )
{
	int size = length( chars );

	chars[ size ] = a;
}

// add  char[]  to   char[]  
void add_chars ( char chars[], char add[] )
{
	int size_chars = length( chars );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		chars[ size_chars + i ] = add[i];
}




// string[]



string empty_string[10000] = {};

// empties a string[]
void empty ( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_string[i];
}

// is in string[]
bool is_in_strings ( string strings[], string a )
{
	int size = length( strings );

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_string_at ( string strings[], int iter )
{
	int size = length( strings );

	string remaining_strings[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_strings[ iter_remaining ] = strings[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( strings );

	for ( int i=0; i<iter_remaining; i=i+1 )
		strings[i] = remaining_strings[i];
}

// removes all strings-s  a  of string[]  strings  
void remove_strings_at ( string strings[], int iters[] )
{
	int size = length( strings );

	string strings_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				strings_removed[iter] = strings[i];
				iter = iter + 1;
			}

	empty( strings );

	for ( int i=0; i<iter; i=i+1 )
		strings[i] = strings_removed[i];
}

// removes all strings-s  a  of string[]  strings  
void remove_strings ( string strings[], string remove[] )
{
	int size = length( strings );

	string strings_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_strings( remove, strings[i] ) )
			{
				strings_removed[iter] = strings[i];
				iter = iter + 1;
			}

	empty( strings );

	for ( int i=0; i<iter; i=i+1 )
		strings[i] = strings_removed[i];
}

// removes all strings-s  a  of string[]  strings  
void remove_string ( string strings[], string a )
{
	int size = length( strings );
	string iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] != a )
		{
			iters[ iter ] = strings[i];
			iter = iter + 1;
		}

	empty( strings );

	for ( int i=0; i<iter; i=i+1 )
		strings[i] = iters[i];
}


// add  string  to  string[]  
void add_string ( string strings[], string a )
{
	int size = length( strings );

	strings[ size ] = a;
}

// add  string[]  to   string[]  
void add_strings ( string strings[], string add[] )
{
	int size_strings = length( strings );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		strings[ size_strings + i ] = add[i];
}



// char string



string empty_char_string = "";

// empties a string
void empty( string &a )
{
	a = empty_char_string;
}

// is in string
bool is_char_in_string ( string char_string, char a )
{
	int size = char_string.length();

	for ( int i=0; i<size; i=i+1 )
		if ( char_string[i] == a )
			return true;

	return false;
}

// removes char at  iter  of a string
string remove_char_string_at ( string &a, int iter )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
			result = result + a[i];

	a = result;

	return a;
}

// removes all chars at  iters[]    
string remove_chars_string_at ( string &a, int iters[] )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			result = result + a[i];

	a = result;

	return a;
}

// removes all char-s  b  of string  a  
string remove_chars_string ( string &a, char b[] )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( !is_char_in_string( b, a[i] ) )
			result = result + a[i];

	a = result;

	return a;
}

// removes all char-s  b  of string  a  
string remove_char_string ( string &a, char b )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != b )
			result = result + a[i];

	a = result;

	return a;
}



// add  char  to  string  
string add_char_string ( string &a, char b )
{
	a = a + b;

	return a;
}

// add  char[]  to  string  
string add_chars_string ( string &a, char b[] )
{
	int size = length(b);

	for ( int i=0; i<size; i=i+1 )
		a = a + b[i];

	return a;
}




int main()
{


	// ints


	cout << "// ints:\n";
	int ints[20] = { 142, 1, 90, 3, 4, 3, 1, 3, 1 };

	cout << is_in_ints( ints, 1 ) << endl;

	remove_int_at( ints, 1 );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	int ints_remove_at[20] = { 1, 4 };
	remove_ints_at( ints, ints_remove_at );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	remove_int( ints, 1 );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	int ints_remove [20] = { 142, 3 };
	remove_ints( ints, ints_remove );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	add_int( ints, 1 );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	int ints_add[20] = { 109, 4 };
	add_ints( ints, ints_add );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;




	cout << endl;



	// longs


	cout << "// longs:\n";
	long longs[20] = { 1999942, 19999, 90, 3, 4, 3, 99991, 3, 1 };

	cout << is_in_longs( longs, 1 ) << endl;

	remove_long_at( longs, 1 );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;

	int longs_remove_at[20] = { 1, 4 };
	remove_longs_at( longs, longs_remove_at );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;

	remove_long( longs, 1 );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;

	long longs_remove [20] = { 142, 3 };
	remove_longs( longs, longs_remove );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;

	add_long( longs, 1 );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;

	long longs_add[20] = { 109, 4 };
	add_longs( longs, longs_add );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;




	cout << endl;



	// doubles



	cout << "// doubles:\n";
	double doubles[20] = { 199.42, 19.04, 9.0, 3, 4, 0.3, 99.991, 3, 1 };

	cout << is_in_doubles( doubles, 1 ) << endl;

	remove_double_at( doubles, 1 );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;

	int doubles_remove_at[20] = { 1, 4 };
	remove_doubles_at( doubles, doubles_remove_at );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;

	remove_double( doubles, 9 );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;

	double doubles_remove [20] = { 142, 3 };
	remove_doubles( doubles, doubles_remove );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;

	add_double( doubles, 0.3 );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;

	double doubles_add[20] = { 109, 4 };
	add_doubles( doubles, doubles_add );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;




	cout << endl;



	// floats



	cout << "// floats:\n";
	float floats[20] = { 199.9942, 1.9999, 9.0, 3, 1.4, 3, 99991, 3, 1.9 };

	cout << is_in_floats( floats, 1 ) << endl;

	remove_float_at( floats, 1 );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;

	int floats_remove_at[20] = { 1, 4 };
	remove_floats_at( floats, floats_remove_at );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;

	remove_float( floats, 1 );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;

	float floats_remove [20] = { 142, 3 };
	remove_floats( floats, floats_remove );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;

	add_float( floats, 1 );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;

	float floats_add[20] = { 109, 4 };
	add_floats( floats, floats_add );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;




	cout << endl;



	// chars



	cout << "// chars:\n";
	char chars[20] = { 'a', 'b', 'l', 'a', 'r', 'b', 'l' };

	cout << is_in_chars( chars, 1 ) << endl;

	remove_char_at( chars, 1 );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;

	int chars_remove_at[20] = { 1, 4 };
	remove_chars_at( chars, chars_remove_at );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;

	remove_char( chars, 'l' );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;

	char chars_remove [20] = { 'a', 'b' };
	remove_chars( chars, chars_remove );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;

	add_char( chars, 'a' );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;

	char chars_add[20] = { 'b', 'l' };
	add_chars( chars, chars_add );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;




	cout << endl;



	// string



	cout << "// strings:\n";
	string strings[20] = { "string_1", "a", "string_2", "!%$@", "string_3", "41\"12", "16752", "b" };

	cout << is_in_strings( strings, "a" ) << endl;

	remove_string_at( strings, 1 );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;

	int strings_remove_at[20] = { 1, 4 };
	remove_strings_at( strings, strings_remove_at );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;

	remove_string( strings, "string_2" );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;

	string strings_remove [20] = { "a", "b", };
	remove_strings( strings, strings_remove );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;

	add_string( strings, "a" );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;

	string strings_add[20] = { "b", "string" };
	add_strings( strings, strings_add );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;




	cout << endl;	



	// char strings


	cout << "// char strings:\n";
	string char_string = "aaerblm";
	cout << is_char_in_string( char_string, 'a' ) << endl;
	cout << remove_char_string_at( char_string, 1 ) << endl;
	int chars_string_remove_at[20] = { 1, 2 };
	cout << remove_chars_string_at( char_string, chars_string_remove_at ) << endl;
	cout << remove_char_string( char_string, 'r' ) << endl;
	char chars_string_remove[20] = { 'e', 'm' };
	cout << remove_chars_string( char_string, chars_string_remove ) << endl;
	cout << add_char_string( char_string, 'r' ) << endl;
	char chars_string_add[20] = { 'e', 'm' };
	cout << add_chars_string( char_string, chars_string_add ) << endl;


	return 0;
}

