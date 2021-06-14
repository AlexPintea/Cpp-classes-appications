// #include "lengths.cpp"
// #include "last.cpp"



// datatypes to a string



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
// converts an int[] to a string[]
void int_to_string ( int a[], string ints[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		ints[i] = int_to_string( a[i] );
}


// converts an long to a string
string long_to_string (long a)
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
// converts an long[] to a string[]
string long_to_string (long a[], string longs[])
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		longs[i] = long_to_string( a[i] );

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



// converts a double to a string with a certain precision ( deprecated, but the only that returns >= 4 decimals )
string double_to_string ( double a, int precision )
{
	// save initial val. of a
	double a_2 = a;

	// makes a positive if necessary
	bool is_neg = false;
	if ( a < 0 )
	{
		is_neg = true;
		a = -a;
	}

	// int part of a ( a_int.a_decimals ) as string
	string a_int = int_to_string( (int) a );

	a = a - (int) a;

	if ( a == 0 )
		return long_to_string( (long) a_2 );

	// to make a_decimals an int and store certain 0-s close to the '.' ( 1.000 )
	string empty = ""; // for 0-s
	for ( int i=0; i<precision; i=i+1 )
	{
		a = a * 10;
		if ( (int) a == 0 )
			empty = empty + '0';
	}

	// decimals part of a ( a_int.a_decimals ) as string
	string a_decimals = int_to_string( (int) a );

	// make 1.9 into 2 as long
	if ( a_decimals[0] == '9' and empty.length() == 0 )
	{
		a_int[ a_int.length() - 1 ] = a_int[ a_int.length() - 1 ] + 1;

		if ( is_neg )
			a_2 = a_2 - 1;
		else
			a_2 = a_2 + 1;

		return long_to_string( (long) a_2 );
	}

	// add 0-s to a_decimals
    a_decimals = empty + a_decimals;

	// make 2.09 into 2.1
	int nines_iter = -1;
	for ( int i=0; i<a_decimals.length()-1; i=i+1 )
		if ( a_decimals[i+1] == '9' )
		{
			a_decimals[i] = a_decimals[i] + 1;
			nines_iter = i;
			break;
		}

	string a_decimals_clear = "";
	if ( nines_iter != -1 )
	{
		for ( int i=0; i<=nines_iter; i=i+1 )
			a_decimals_clear = a_decimals_clear + a_decimals[i];

		a_decimals = a_decimals_clear;
	}

	// to make sure
	if ( a_decimals == "0" )
		return long_to_string( (long) a_2 );

	// make the result
	string result = a_int + "." + a_decimals;

	// add a '-' if necessary
	if ( is_neg )
		result = "-" + result;

	// clear 0-s of 1.200000
	int counter = 0;
	for ( int i=result.length()-1; i>0; i=i-1 )
	{
		if ( result[i] == '0' )
			counter = counter + 1;
		else
			break;
	}

	string result_clear = "";

	for ( int i=0; i<result.length() - counter; i=i+1 )
		if ( is_numeric( result[i] ) or result[i] == '.' or result[i] == '-' )
			result_clear = result_clear + result[i];

	return result_clear;
}
// converts a double[] to a string[]
void double_to_string ( double a[], string doubles[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		doubles[i] = double_to_string( a[i] );
}

// converts a float to a string
string float_to_string ( float a )
{
	return double_to_string( (double) a );
}
// converts a float to a string with a certain precision
string float_to_string ( float a, int precision )
{
	return double_to_string( (double) a, precision );
}
// converts a float[] to a string[]
void float_to_string ( float a[], string floats[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		floats[i] = float_to_string( a[i], 3 );
}

// converts a bool to a string
string bool_to_string ( bool a )
{
	if ( a == 1 )
		return "true";

	return "false";
}

// converts a char to a string
string char_to_string (char a)
{
	string result = "";

	result = result + a;

	return result;
}
// converts an char[] to a string[]
void char_to_string ( char a[], string chars[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		chars[i] = char_to_string( a[i] );
}



// datatypes[] to a string



// converts ints to a string
string int_to_string (int a[])
{
	string result = "";

	for ( int i=0; i<length(a); i=i+1 )
		result = result + int_to_string( a[i] ) + " ";

	return result;
}

// converts longs to a string
string longs_to_string (long a[])
{
	string result = "";

	for ( int i=0; i<length(a); i=i+1 )
		result = result + long_to_string( a[i] ) + " ";

	return result;
}

// converts doubles to a string
string doubles_to_string (double a[])
{
	string result = "";

	for ( int i=0; i<length(a); i=i+1 )
		result = result + double_to_string( a[i] ) + " ";

	return result;
}

// converts chars to a string
string chars_to_string (char a[])
{
	string result = "";

	for ( int i=0; i<length(a); i=i+1 )
		result = result + a[i];

	return result;
}



// datatypes to chars



// converts an int to a char array
void int_to_chars ( int a, char digits[] ) 
{
	int size = length(a);

	for (int i=0; i<size; i=i+1)
	{
		char a_char = (char) ( a % 10 + 48 );

		if ( is_numeric( a_char ) )
			digits[ size - i - 1 ] = a_char;

		a = a / 10;
	}
}

// converts a long to a char array
void long_to_chars ( long a, char digits[] ) 
{
	string a_string = long_to_string(a);

	int size = a_string.length();

	for ( int i=0; i<size; i=i+1 )
		if ( is_numeric( a_string[i] ) )
			digits[i] = a_string[i];
}

// converts a double to a char array
void double_to_chars ( double a, char digits[] ) 
{
	string a_string = double_to_string(a);

	int size = a_string.length();

	for ( int i=0; i<size; i=i+1 )	
		if ( is_numeric( a_string[i] ) or a_string[i] == '.' )
			digits[i] = a_string[i];
}

// converts a bool to a char array
void bool_to_chars ( bool a, char digits[] ) 
{
	if ( a == 1 )
		digits[0] = '1';
	else
		digits[0] = '0';
}


// converts a string to a char array
void string_to_chars ( string a, char chars[] ) 
{
	int size = a.length();

	int i;

	for ( i=0; i<size; i=i+1 )
		chars[i] = a[i];
	chars[i] = '\0';
}






// Validations and string_to_[datatype] convertions






void get_string_data( string a, string data[] );



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
	get_string_data( a, a_ints );

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
	get_string_data( a, a_longs );

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
	get_string_data( a, a_doubles );

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
	if ( a.length() == 1 )
		return a[0] - 48;

	if ( is_long( a ) )
		return string_to_long(a);


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
	get_string_data( a, a_floats );

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
	get_string_data( a, a_chars );

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
	get_string_data( a, a_bools );

	int size = length(a_bools);

	for ( int i=0; i<size; i=i+1 )
		bools[i] = string_to_bool( a_bools[i] );
}


// unsigned



// check if a string is unsigned
bool is_unsigned( string a )
{
	if ( a[0] == '-' )
		return false;

	if ( !is_int(a) and !is_long(a) and !is_double(a))
		return false;

	return true;
}



// string



// check if a string fits only in the datatype "string"
bool is_only_string ( string a )
{
	if (  is_int(a) )
		return false;

	if (  is_long(a) )
		return false;

	if ( is_double(a) )
		return false;

	if ( is_char(a) )
		return false;

	if ( is_bool(a) )
		return false;

	// if your string is actually a datatype
	// if ( a == "int" or a == "double" or a == "char" or a == "bool" )
		// return false;

	return true;
}

// gets string data ( val.-s of certain datatypes ) into data[] as strings
void get_string_data ( string a, string data[] )
{
	int size = a.length();
	empty( data );

	int counter = 0;

	a = a + " ";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			counter = counter + 1;
		else
			data[ counter ] = data[ counter ] + a[i];
}

// datatypes of a string
void datatypes ( string a, string data_types[] )
{
	empty( data_types );

	string data[100000];	
	get_string_data( a, data );

	int size = length( data );

	for ( int i=0; i<size; i=i+1 )
		data_types[i] = datatype( data[i] );
}








