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

int length(long a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
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

int length(char a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(bool a[]) // does not return validly
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

// gets string data ( val.-s of certain datatypes ) into data[] as strings
void get_data ( string a, string data[] )
{
	int size = a.length();

	// empty data
	for ( int i=0; i<length( data ); i=i+1 )
		data[i] = "";

	int counter = 0;

	a = a + " ";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			counter = counter + 1;
		else
			data[ counter ] = data[ counter ] + a[i];
}



// int



// check if a string is an int
bool is_int ( string a )
{
	int size = a.length();

	if ( size >= 10 )
		return false;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}
// convert string to int
int string_to_int ( string a )
{
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
// check if multiple strngs are int
bool are_int( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( !is_int( a[i] ) )
			return false;

	return true;
}
// convert multiple strings to ints
void string_to_int ( string a[], int ints[] )
{
	int size = length(a);

	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( is_int( a[i] ) )
		{
			ints[ counter ] = string_to_int( a[i] );
			counter = counter + 1;
		}

	ints[ counter ] = 0;
}
// convert multiple strings ( stored in 1 string ) to ints
void string_to_int ( string a, int ints[] )
{
	string a_ints[100000];
	get_data( a, a_ints );

	int size = length(a_ints);

	for ( int i=0; i<size; i=i+1 )
		ints[i] = string_to_int( a_ints[i] );
}



// long ( only as int )



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
// check if multiple strngs are long
bool are_long( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( !is_long( a[i] ) )
			return false;

	return true;
}
// convert multiple strings to longs
void string_to_long ( string a[], long longs[] )
{
	int size = length(a);

	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( is_long( a[i] ) )
		{
			longs[ counter ] = string_to_long( a[i] );
			counter = counter + 1;
		}

	longs[ counter ] = 0;
}
// convert multiple strings ( stored in 1 string ) to longs
void string_to_long ( string a, long longs[] )
{
	string a_longs[100000];
	get_data( a, a_longs );

	int size = length(a_longs);

	for ( int i=0; i<size; i=i+1 )
		longs[i] = string_to_long( a_longs[i] );
}



// double



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
// check if multiple strngs are double
bool are_double( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( !is_double( a[i] ) )
			return false;

	return true;
}
// convert multiple strings to doubles
void string_to_double ( string a[], double doubles[] )
{
	int size = length(a);

	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( is_double( a[i] ) )
		{
			doubles[ counter ] = string_to_double( a[i] );
			counter = counter + 1;
		}

	doubles[ counter ] = 0;
}
// convert multiple strings ( stored in 1 string ) to doubles
void string_to_double ( string a, double doubles[] )
{
	string a_doubles[100000];
	get_data( a, a_doubles );

	int size = length(a_doubles);

	for ( int i=0; i<size; i=i+1 )
		doubles[i] = string_to_double( a_doubles[i] );
}



// float



// check if a string is a float
bool is_float ( string a )
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
// convert string to float
float string_to_float ( string a )
{
	float num_float = 0;

	int i = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		i = 1;
	}


	while ( a[i] != '.' )
	{
		num_float = num_float * 10 + ( a[i] - 48 );
		i = i + 1;
	}

	i = i + 1;
	int decimal_tens = 10;

	while ( a[i] )
	{
		float temp = a[i] - 48;
		num_float = num_float + temp / decimal_tens ;
		decimal_tens = decimal_tens * 10;
		i = i + 1;
	}

	if ( is_neg )
		num_float = -num_float;

	return num_float;
}
// check if multiple strngs are float
bool are_float( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( !is_float( a[i] ) )
			return false;

	return true;
}
// convert multiple strings to floats
void string_to_float ( string a[], float floats[] )
{
	int size = length(a);

	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( is_float( a[i] ) )
		{
			floats[ counter ] = string_to_float( a[i] );
			counter = counter + 1;
		}

	floats[ counter ] = 0;
}
// convert multiple strings ( stored in 1 string ) to floats
void string_to_float ( string a, float floats[] )
{
	string a_floats[100000];
	get_data( a, a_floats );

	int size = length(a_floats);

	for ( int i=0; i<size; i=i+1 )
		floats[i] = string_to_float( a_floats[i] );
}



// char



// check if a string is a char
bool is_char ( string a )
{
	int size = a.length();
	if ( size != 1 )
		return false;

	if ( ( a[0] >= '0' and a[0] <= '9' ) )
			return false;

	return true;
}
// convert string to char
char string_to_char ( string a )
{
	return a[0];
}
// check if multiple strngs are char
bool are_char( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( !is_char( a[i] ) )
			return false;

	return true;
}
// convert multiple strings to chars
void string_to_char ( string a[], char chars[] )
{
	int size = length(a);

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
	{
		for ( int l=0; l<a[i].length(); l=l+1 )
		{
			chars[iter] = a[i][l];
			iter = iter + 1;
		}

		if ( !are_char(a) )
		{
			chars[iter] = ' ';
			iter = iter + 1;
		}
	}
}
// convert string to chars
void string_to_char ( string a, char chars[] )
{
	string a_chars[100000];
	get_data( a, a_chars );

	int size = length(a_chars);

	for ( int i=0; i<size; i=i+1 )
		chars[i] = string_to_char( a_chars[i] );
}



// bool



// check if a string is a bool
bool is_bool ( string a )
{
	if ( ( a == "true" or a == "false" ) or ( a == "0" or a == "1" ) )
		return true;

	return false;
}
// convert string to bool
bool string_to_bool ( string a )
{
	if ( a == "true" or a == "1" )
		return true;

	return false;
}
// check if multiple strngs are bool
bool are_bool( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( !is_bool( a[i] ) )
			return false;

	return true;
}
// convert multiple strings to bools
void string_to_bool ( string a[], bool bools[] )
{
	int size = length(a);

	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( is_bool( a[i] ) )
		{
			bools[ counter ] = string_to_bool( a[i] );
			counter = counter + 1;
		}

	bools[ counter ] = 0;
}
// convert multiple strings ( stored in 1 string ) to bools
void string_to_bool ( string a, bool bools[] )
{
	string a_bools[100000];
	get_data( a, a_bools );

	int size = length(a_bools);

	for ( int i=0; i<size; i=i+1 )
		bools[i] = string_to_bool( a_bools[i] );
}

// datatype of string
string datatype ( string a )
{
	if ( is_int(a) )
		return "int";

	if ( is_long(a) )
		return "long";

	if ( is_double(a) )
		return "double";

	if ( is_char(a) )
		return "char";

	if ( is_bool(a) )
		return "bool";

	return "string";
}






//









// reduces ' '-s
void reduce_spaces ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ')
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";
	a = result;
}

// checks if a char is in a string
bool is_char_in_string ( string data, char a )
{
	for ( int i=0 ;i<data.length(); i=i+1 )
		if ( data[i] == a )
			return true;

	return false;
}

// removes a char in a string
void remove_char( string &a, int iter )
{
	if ( iter < 0 or iter >=a.length() )
		return;

	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
			result = result + a[i];

	a = result;
}

// moves string data ( val.-s of certain datatypes ) into data[] as strings
void move_data ( string a, string data[], string separators )
{
	int size = a.length();

	// empty data
	for ( int i=0; i<length( data ); i=i+1 )
		data[i] = "";

	// empty data
	for ( int i=0; i<size; i=i+1 )
		if ( is_char_in_string( separators, a[i] ) )
			a[i] = ' ';

	reduce_spaces( a );

	int counter = 0;

	while ( a[0] == ' ' )
		remove_char( a, 0 );

	size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			counter = counter + 1;
		else
			data[ counter ] = data[ counter ] + a[i];
}





// string





// get entered string
void get ( string &entered_string )
{
	entered_string = "";

	while ( entered_string == "" )
		getline( cin, entered_string );
}

// get entered strings with separator chars
void get ( string entered_strings[], string separators )
{
	string temp;

	get( temp );
	reduce_spaces( temp );

	move_data( temp, entered_strings, separators );
}

// get entered strings
void get ( string entered_strings[] )
{
	get( entered_strings, " " );
}

// sets a string
void set ( string a )
{
	cout << a;
}

// sets a string[] with a separator string
void set ( string a[], string separator )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		if ( i != size - 1 )
			cout << separator;
	}
}

// sets a string[] with a separator string
void set ( string a[], int num_columns )
{
	int size = length(a);

	int max_length[ num_columns ];
	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length();

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		for ( int l=a[i].length(); l<max_length[ i % num_columns ]; l=l+1 )
			cout << " ";
		if ( i % num_columns == num_columns - 1 )
			cout << "\n";
	}
}

// sets a string[]
void set ( string a[] )
{
	set( a, " ");
}



// long (same as int)




// get entered long
void get ( long &entered_long )
{
	string temp;

	get( temp );

	if ( is_long( temp ) )
		entered_long = string_to_long( temp );
	else
		entered_long = -1;
}

// get entered longs with separator chars
void get ( long entered_longs[], string separators )
{
	string temp;

	get( temp );
	reduce_spaces( temp );

	string temp_strings[1000];
	move_data( temp, temp_strings, separators );

	string_to_long( temp_strings, entered_longs );
}

// get entered longs
void get ( long entered_longs[] )
{
	get ( entered_longs, " " );
}

// sets a long
void set ( long a )
{
	cout << a;
}

// sets a long[] with a separator string
void set ( long a[], string separator )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		if ( i != size - 1 )
			cout << separator;
	}
}

// sets a long[]
void set ( long a[] )
{
	set( a, " " );
}


// ints


// get entered int
void get ( int &entered_int )
{
	get( entered_int );
}

// get entered ints with separator chars
void get ( int entered_ints[], string separators )
{
	get( entered_ints, separators );
}

// get entered ints
void get ( int entered_ints[] )
{
	get ( entered_ints, " " );
}

// sets a int
void set ( int a )
{
	cout << a;
}

// sets a int[] with a separator string
void set ( int a[], string separator )
{
	set( a, separator );
}

// sets a int[]
void set ( int a[] )
{
	set( a, " " );
}




// doubles ( same as floats )




// get entered double
void get ( double &entered_double )
{
	string temp;

	get( temp );

	if ( is_double( temp ) )
		entered_double = string_to_double( temp );
	else
		entered_double = -1;
}

// get entered doubles with separator chars
void get ( double entered_doubles[], string separators )
{
	string temp;

	get( temp );
	reduce_spaces( temp );

	string temp_strings[1000];
	move_data( temp, temp_strings, separators );

	string_to_double( temp_strings, entered_doubles );
}

// get entered doubles
void get ( double entered_doubles[] )
{
	get ( entered_doubles, " " );
}

// sets a double
void set ( double a )
{
	cout << a;
}

// sets a double[] with a separator string
void set ( double a[], string separator )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		if ( i != size - 1 )
			cout << separator;
	}
}

// sets a double[]
void set ( double a[] )
{
	set( a, " " );
}


// floats


// get entered float
void get ( float &entered_float )
{
	get( entered_float );
}

// get entered floats with separator chars
void get ( float entered_floats[], string separators )
{
	get( entered_floats, separators );
}

// get entered floats
void get ( float entered_floats[] )
{
	get ( entered_floats, " " );
}

// sets a float
void set ( float a )
{
	cout << a;
}

// sets a float[] with a separator string
void set ( float a[], string separator )
{
	set( a, separator );
}

// sets a float[]
void set ( float a[] )
{
	set( a, " " );
}




// chars




// get entered char
void get ( char &entered_char )
{
	string temp;

	get( temp );

	if ( is_char( temp ) )
		entered_char = string_to_char( temp );
	else
		entered_char = -1;
}

// get entered chars with separator chars
// ISO forbids this

// get entered chars
// ISO forbids this

// sets a char
void set ( char a )
{
	cout << a;
}

// sets a char[] with a separator string
// ISO forbids this

// sets a char[]
// ISO forbids this




// bools
// are not available





// set_get




// clears
void clear ( int num )
{
	for ( int i=0; i<num; i=i+1 )
		cout << "\b";
}

// get a string
void set_get ( string set, string &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	getline( cin, get );
	if ( get == "" )
		getline( cin, get );
}

// get a long
void set_get ( string set, long &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_long( get_string ) )
		get = string_to_long( get_string );
	else
		get = -1; // if get_string was !long
}

// get a int
void set_get ( string set, int &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_int( get_string ) )
		get = string_to_int( get_string );
	else
		get = -1; // if get_string was !int
}

// get a double
void set_get ( string set, double &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_double( get_string ) )
		get = string_to_double( get_string );
	else
		get = -1; // if get_string was !double
}

// get a float
void set_get ( string set, float &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_float( get_string ) )
		get = string_to_float( get_string );
	else
		get = -1; // if get_string was !float
}

// get a char
void set_get ( string set, char &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_char( get_string ) )
		get = string_to_char( get_string );
	else
		get = -1; // if get_string was !char
}

// get a bool
void set_get ( string set, bool &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_bool( get_string ) )
		get = string_to_bool( get_string );
	else
		get = -1; // if get_string was !bool
}


int main ()
{

	// set_get

	int a_int;
	set_get( "a_int", a_int );
	cout << a_int << "\n\n";

	long a_long;
	set_get( "a_long", a_long );
	cout << a_long << "\n\n";

	double a_double;
	set_get( "a_double", a_double );
	cout << a_double << "\n\n";

	float a_float;
	set_get( "a_float", a_float );
	cout << a_float << "\n\n";

	char a_char;
	set_get( "a_char", a_char );
	cout << a_char << "\n\n";

	bool a_bool;
	set_get( "a_bool", a_bool );
	cout << a_bool << "\n\n";


	// strings


	string entered_strings_2[70] = { "a", "ab", "string", "a_string", "strings", "a string", "string b" };	
	set( entered_strings_2, 3 );
	set( "\n\n" );


	string entered_string;
	set( "Enter a string: " );
	get( entered_string );
	set( entered_string );
	set( "\n" );

	string entered_strings[10];
	set( "Enter a string[] with items separated by \' \': " );
	get( entered_strings );
	set( entered_strings, ", " );
	set( "\n" );

	string entered_strings_1[10];	
	set( "Enter a string[] with items separated by \"-,./\" etc.: " );
	get( entered_strings_1, "~!@#$%^&()_+[];',./{}: \"|<>?\"\'" );
	set( entered_strings_1, ", " );
	set( "\n" );
	

	// long ( same as int )


	long entered_long;
	set( "Enter a long num.: " );
	get( entered_long );
	set( entered_long );
	set( "\n" );

	long entered_longs[10];
	set( "Enter a long[]: " );
	get( entered_longs );
	set( entered_longs, ", " );
	set( "\n" );

	long entered_longs_1[10];
	set( "Enter a long[] with items separated by \"-,./\" etc.: " );
	get( entered_longs_1, "~!@#$%^&()_+[];',./{}: \"|<>?\"\'" );
	set( entered_longs_1, ", " );
	set( "\n" );


	// double ( same as float )


	double entered_double;
	set( "Enter a double num.: " );
	get( entered_double );
	set( entered_double );
	set( "\n" );

	double entered_doubles[10];
	set( "Enter a double[]: " );
	get( entered_doubles );
	set( entered_doubles, ", " );
	set( "\n" );

	double entered_doubles_1[10];
	set( "Enter a double[] with items separated by \"-,./\" etc.: " );
	get( entered_doubles_1, "~!@#$%^&()_+[];',./{}: \"|<>?\"\'" );
	set( entered_doubles_1, ", " );
	set( "\n" );


	// char


	char entered_char;
	set( "Enter a char: " );
	get( entered_char );
	set( entered_char );
	set( "\n" );

	return 0;
}
