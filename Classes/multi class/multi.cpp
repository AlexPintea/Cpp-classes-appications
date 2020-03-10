#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
#define get_name(Variable) ( #Variable )

using namespace std;

// Multi_string
class Multi_String 
{
	string multi_string;



	// Leave types



	// leave chars in a string to leave only $#$%!#
	string leave_chars ( string a )
	{
		int size = a.length();

		string result = " ";

		for ( int i=0; i<size; i=i+1 )
		{
			if ( !( ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) or ( a[i] >= '0' and a[i] <= '9' ) ) and a[i] != ' ' )
				result = result + a[i];
			if ( a[i] == ' ' and result[ result.length() - 1 ] != ' ' )
				result = result + ' ';
		}

		return result;
	}

	// leaves numerics in a string
	string leave_numerics ( string a )
	{
		int size = a.length();

		string result = " ";

		for ( int i=0; i<size; i=i+1 )
		{
			if ( a[i] >= '0' and a[i] <= '9' )
				result = result + a[i];
			if ( a[i] == ' ' and result[ result.length() - 1 ] != ' ' )
				result = result + ' ';
		}

		return result;
	}

	// leaves words in a string ( a, b, l,  etc. )
	string leave_words ( string a )
	{
		int size = a.length();

		string result = " ";

		for ( int i=0; i<size; i=i+1 )
		{
			if ( ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) )
				result = result + a[i];
			if ( a[i] == ' ' and result[ result.length() - 1 ] != ' ' )
				result = result + ' ';
		}

		return result;
	}




	// Check if an entry in in the string




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

	// check if an entry in in the multi_string, return where if the cae
	int is_in_multi_string ( string name, string type )
	{
		string name_type = name + " " + type;

		for ( int i=0; i<this->multi_string.length() ;i=i+1 )
			if ( this->multi_string[i] == name_type[0] )
			{
				bool is_name_type = true;

				for ( int l=1; l<name_type.length(); l=l+1 )
					if ( this->multi_string[ l + i ] != name_type[l] )
					{
						is_name_type = false;
						break;
					}

				if ( is_name_type )
					return i;
			}

		return false;
	}



	// Convert long string



	// inverts a string
	void invert_string( string &a )
	{
		int size = a.length();

		string b = "";

		for ( int i=size-1; i>=0; i=i-1 )
			b = b + a[i];

		a = b;
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

			if ( a_char >= '0' and a_char <= '9' )
				result = result + a_char;
			a = a / 10;
		}

		if ( is_neg )
			result = result + '-';

		invert_string( result );

		return result;
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



	
	// Convert bool string



	
	string bool_to_string( bool a )
	{
		if ( a == 1 )
			return "true";

		return "flase";
	}

	bool string_to_bool ( string a )
	{
		if ( a == "1" or a == "true" )
			return true;

		return false;
	}



	// Convert double string



	// length of a long
	int length(long a)
	{
		if (a == 0)
			return 1;

		int i=0;

		while ( a != '\0' )
		{
			i=i+1;
			a=a/10;
		}

		return i;
	}


	// length of a string[]
	int length ( string a[] )
	{

		int i=0;

		while ( a[i].length() > 0 )
		{
			i=i+1;
		}

		return i;
	}

	// digits of a long
	void digits ( long a, char num_digits[] )
	{
		int size = length(a);

		for ( int i=0; i<size; i=i+1 )
		{
			num_digits[ size - i - 1 ] = (int) (a%10) + 48;
			a = a / 10;
		}
	}

	// converts a double to a string with a certain precision
	string double_to_string ( double a )
	{
		bool is_neg = false;
		if ( a < 0 )
			is_neg = true;

		int iter = length( (long) a );

		while ( ( (float) a - (long) a ) != 0.0 )
			a = a * 10;


		long a_as_long;

		if ( is_neg )
			a_as_long = -(long) a;
		else
			a_as_long = (long) a;


		char digits_a[1000];
		digits( a_as_long, digits_a );

		string result = "";
		if ( is_neg )
			result = result + '-';
		for ( int i=0; i<length( a_as_long ); i=i+1 )
		{
			if ( i == iter )
				result = result + '.';

			result = result + digits_a[i];
		}

		return result;
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


  public:

	Multi_String ()
	{
		this->multi_string = "";
	}

	Multi_String ( string data )
	{
		this->multi_string = data;
	}


	// set / get multi_string


	void set_multi_string( string data )
	{
		this->multi_string = data;
	}

	string get_multi_string()
	{
		return this->multi_string;
	}



	// Make type entries


	void make_types ()
	{
		string data = this->multi_string;
		this->multi_string = "";

		this->multi_string = this->multi_string + "words string  " + leave_words( data ) + "\n";
		this->multi_string = this->multi_string + "numerics double  " + leave_numerics( data ) + "\n";
		this->multi_string = this->multi_string + "chars char  " + leave_chars( data ) + "\n";
	}



	// Add an entry



	void add ( string a[], string name )
	{
		if ( is_in_multi_string( name, "string" ) )
		{
			cout << "Could not store \"" << name << " string\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " string   ";

		int i=0;
		while ( a[i].length() > 0 )
		{
			this->multi_string = this->multi_string + a[i] + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( string a, string name ) // only stores with 1 ' ' sep.
	{
		if ( is_in_multi_string( name, "string" ) )
		{
			cout << "Could not store \"" << name << " long\", name and type are already set.\n";
			return;
		}

		for ( int i=1; i<a.length(); i=i+1 ) // only stores with 1 ' ' sep.
			if ( a[i] == ' ' and a[i-1] == ' ' )
			{
				remove_char( a, i );
				i = i - 1;
			}

		string a_strings[10];
		a_strings[0] = a;
		add( a_strings, name );
	}

	void add ( long a[], string name )
	{
		if ( is_in_multi_string( name, "long" ) )
		{
			cout << "Could not store \"" << name << " long\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " long   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + long_to_string( a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( long a, string name )
	{
		if ( is_in_multi_string( name, "long" ) )
		{
			cout << "Could not store \"" << name << " long\", name and type are already set.\n";
			return;
		}

		long a_longs[10];
		a_longs[0] = a;
		a_longs[1] = '\0';
		add( a_longs, name );
	}

	void add ( int a[], string name )
	{
		if ( is_in_multi_string( name, "int" ) )
		{
			cout << "Could not store \"" << name << " int\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " int   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + long_to_string( (long) a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( int a, string name )
	{
		if ( is_in_multi_string( name, "int" ) )
		{
			cout << "Could not store \"" << name << " int\", name and type are already set.\n";
			return;
		}

		int a_ints[10];
		a_ints[0] = a;
		a_ints[1] = '\0';
		add( a_ints, name );
	}

	void add ( bool a[], string name )
	{
		if ( is_in_multi_string( name, "bool" ) )
		{
			cout << "Could not store \"" << name << " bool\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " bool   ";

		int i=0;
		while ( a[i] ) // does not store "false"
		{
			this->multi_string = this->multi_string + bool_to_string( a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( bool a, string name )
	{
		if ( is_in_multi_string( name, "bool" ) )
		{
			cout << "Could not store \"" << name << " bool\", name and type are already set.\n";
			return;
		}

		bool a_bools[10];
		a_bools[0] = a; // does not store "false" 
		a_bools[1] = '\0';
		add( a_bools, name );
	}



	void add ( double a[], string name )
	{
		if ( is_in_multi_string( name, "double" ) )
		{
			cout << "Could not store \"" << name << " double\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " double   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + double_to_string( a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( double a, string name )
	{
		if ( is_in_multi_string( name, "double" ) )
		{
			cout << "Could not store \"" << name << " double\", name and type are already set.\n";
			return;
		}

		double a_doubles[10];
		a_doubles[0] = a;
		a_doubles[1] = '\0';
		add( a_doubles, name );
	}


	void add ( float a[], string name )
	{
		if ( is_in_multi_string( name, "float" ) )
		{
			cout << "Could not store \"" << name << " float\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " float   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + double_to_string( (float) a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( float a, string name )
	{
		if ( is_in_multi_string( name, "float" ) )
		{
			cout << "Could not store \"" << name << " float\", name and type are already set.\n";
			return;
		}

		float a_floats[10];
		a_floats[0] = a;
		a_floats[1] = '\0';
		add( a_floats, name );
	}


	void add ( char a[], string name )
	{
		if ( is_in_multi_string( name, "char" ) )
		{
			cout << "Could not store \"" << name << " char\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " char   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + a[i] + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( char a, string name )
	{
		if ( is_in_multi_string( name, "char" ) )
		{
			cout << "Could not store \"" << name << " char\", name and type are already set.\n";
			return;
		}

		char a_chars[10];
		a_chars[0] = a;
		a_chars[1] = '\0';
		add( a_chars, name );
	}



	// Get an entry



	void get ( string name, string type, string result[] )
	{
		// clears the result
		for ( int i=0; i<length( result ); i=i+1 )
			result[i] = '\0';

		string name_type = name + ' ' + type;

		int iter = is_in_multi_string( name, type );

		int i=iter; // multi_string
		for ( int l=0; l<2; l=l )
		{
			if ( this->multi_string[i] == ' ' )
				l = l + 1;
			i = i + 1;
		}
		i = i + 1;
		
		int result_counter = 0;
		string temp = "";
		while ( this->multi_string[i] != '\n' )
		{
			temp = temp + this->multi_string[i];
			i = i + 1;
			if ( this->multi_string[i] == ' ' )
			{
				remove_char( temp, 0 );

				result[ result_counter ] = temp;
				result_counter = result_counter + 1;
				temp = "";
			}
		}
	}

	void get ( string name, string type, string &result )
	{
		string result_strings[10];
		get( name, type, result_strings );

		result = "";
		for ( int i=0; i<length( result_strings ); i=i+1 )
			result = result + result_strings[i] + " ";
	}

	void get ( string name, string type, long result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length( result_string ); i=i+1 )
			result[i] = string_to_long( result_string[i] );
	}

	void get ( string name, string type, long &result )
	{
		long result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}

	void get ( string name, string type, int result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length( result_string ); i=i+1 )
			result[i] = (int) string_to_long( result_string[i] );
	}

	void get ( string name, string type, int &result )
	{
		int result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}

	void get ( string name, string type, bool result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length( result_string ); i=i+1 )
			result[i] = string_to_bool( result_string[i] );
	}

	void get ( string name, string type, bool &result )
	{
		bool result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}

	void get ( string name, string type, double result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length( result_string ); i=i+1 )
			result[i] = string_to_double( result_string[i] );
	}

	void get ( string name, string type, double &result )
	{
		double result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}


	void get ( string name, string type, float result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length( result_string ); i=i+1 )
			result[i] = (float) string_to_double( result_string[i] );
	}

	void get ( string name, string type, float &result )
	{
		float result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}


	void get ( string name, string type, char result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length( result_string ); i=i+1 )
			result[i] = result_string[i][0];
	}

	void get ( string name, string type, char &result )
	{
		char result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}



	// Remove an entry



	void del ( string name_of_store, string type )
	{
		string data = this->multi_string;
		this->multi_string = "";

		name_of_store = name_of_store + " " + type;

		for ( int i=0; i<data.length(); i=i+1 )
		{
			if ( data[i] == name_of_store[0] and data[i-1] == '\n' )
			{
				bool is_name = true;

				for ( int l=1; l<name_of_store.length(); l=l+1 )
					if ( data[ l + i ] != name_of_store[l] )
					{
						is_name = false;
						break;
					}

				if ( is_name )
					while ( data[i] != '\n' )
						i = i + 1;
			}

			this->multi_string = this->multi_string + data[i];
		}


		// remove '\n' of removed
		for ( int i=1; i<this->multi_string.length(); i=i+1 )
			if ( this->multi_string[i-1] == '\n' and this->multi_string[i] == '\n' )
			{
				remove_char( this->multi_string, i );
				i = i - 1;
			}
	}



	// Show multi_string



	void show_multi_string ()
	{
		cout << "\n" << this->multi_string << "\n";
	}




	// Save multi_string in a file



	void save( string filename )
	{
		// make / clear the file
		ofstream fo;
		fo.open( filename );
		fo.close();

		fo.open( filename );
		fo << this->multi_string;
		fo.close();
	}

	void get_saved( string filename )
	{
		ifstream fi;
		fi.open( filename );

		this->multi_string = "";

		string temp;
		while ( getline( fi, temp ) )
			this->multi_string = this->multi_string + temp + "\n";

		fi.close();
		
	}

};










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









int main ()
{

	Multi_String multi_1;


	// give it a string and it makes type string[]
	multi_1.set_multi_string( "this is @=24 that is 1 is that 27 is text ^@" );
	multi_1.make_types();


	long a_long[1000] = { 1, 9, 3, 2, 4 };
	multi_1.add( a_long, get_name(a_long) );
	multi_1.add( a_long, get_name(a_long) );
//	multi_1.del( "a", "long" );

	int a_int[1000] = { 10, 9, 3, 2, 4 };
	multi_1.add( a_int, get_name(a_int) );
	multi_1.add( a_int, get_name(a_int) );
//	multi_1.del( "a", "a_int" );

	bool a_bool[1000] = { 1, 0, 1, 1, 1 }; // does not store "false"
	multi_1.add( a_bool, get_name(a_bool) );
	multi_1.add( a_bool, get_name(a_bool) );
//	multi_1.del( "a", "bool" );

	double a_double[1000] = { 1.07, 9.1, -3.024, 2.01, 4.10 };
	multi_1.add( a_double, get_name(a_double) );
	multi_1.add( a_double, get_name(a_double) );
//	multi_1.del( "a", "double" );

	float a_float[1000] = { 1.7, 9.1, 3.024, 2.01, 4.10 };
	multi_1.add( a_float, get_name(a_float) );
	multi_1.add( a_float, get_name(a_float) );
//	multi_1.del( "a", "a_float" );

	char a_char[1000] = { 'a', 'b', 'l', 'r' };
	multi_1.add( a_char, get_name(a_char) );
	multi_1.add( a_char, get_name(a_char) );
//	multi_1.del( "a", "a_int" );

	string a_string[1000] = { "ab", "b", "l", "r" };
	multi_1.add( a_string, get_name(a_string) );
	multi_1.add( a_string, get_name(a_string) );
//	multi_1.del( "a", "string" );



	cout << "\n";
	long long_a = 19999;
	multi_1.add( long_a, get_name( long_a ) );
	multi_1.get( "long_a", "long", long_a );
	cout << long_a << "\n";
//	multi_1.del( "long_a", "long" );

	int int_a = 142;
	multi_1.add( int_a, get_name( int_a ) );
	multi_1.get( "int_a", "int", int_a );
	cout << int_a << "\n";
//	multi_1.del( "int_a", "int" );

	bool bool_a = 1;
	multi_1.add( bool_a, get_name( bool_a ) ); // does not store "false"
	multi_1.get( "bool_a", "bool", bool_a );
	cout << bool_a << "\n";
//	multi_1.del( "bool_a", "bool" );

	double double_a = 1.42;
	multi_1.add( double_a, get_name( double_a ) );
	multi_1.get( "double_a", "double", double_a );
	cout << double_a << "\n";
//	multi_1.del( "double_a", "double" );

	float float_a = -14.2;
	multi_1.add( float_a, get_name( float_a ) );
	multi_1.get( "float_a", "float", float_a );
	cout << float_a << "\n";
//	multi_1.del( "float_a", "float" );

	char char_a = 'b';
	multi_1.add( char_a, get_name( char_a ) );
	multi_1.get( "char_a", "char", char_a );
	cout << char_a << "\n";
//	multi_1.del( "char_a", "char" );

	string string_a = "String of      \"a\"."; // only stores with 1 ' ' sep.
	multi_1.add( string_a, get_name( string_a ) );
	multi_1.get( "string_a", "string", string_a );
	cout << string_a << "\n";
//	multi_1.del( "string_a", "string" );



	cout << "\n";
	long result_long[1000];
	multi_1.get( "a_long", "long", result_long );
	for ( int i=0; i<length( result_long ); i=i+1 )
			cout << "\'" << result_long[i] << "\' ";
	cout << "\n";

	int result_int[1000];
	multi_1.get( "a_int", "int", result_int );
	for ( int i=0; i<length( result_int ); i=i+1 )
			cout << "\'" << result_int[i] << "\' ";
	cout << "\n";

	double result_double[1000];
	multi_1.get( "a_double", "double", result_double );
	for ( int i=0; i<length( result_double ); i=i+1 )
			cout << "\'" << result_double[i] << "\' ";
	cout << "\n";

	float result_float[1000];
	multi_1.get( "a_float", "float", result_float );
	for ( int i=0; i<length( result_float ); i=i+1 )
			cout << "\'" << result_float[i] << "\' ";
	cout << "\n";

	char result_char[1000];
	multi_1.get( "a_char", "char", result_char );
	for ( int i=0; i<length( result_char ); i=i+1 )
			cout << "\'" << result_char[i] << "\' ";
	cout << "\n";

	string result_string[1000];
	multi_1.get( "a_string", "string", result_string );
	for ( int i=0; i<length( result_string ); i=i+1 )
			cout << "\'" << result_string[i] << "\' ";
	cout << "\n";


	multi_1.save( get_name( multi_1 ) );
	multi_1.get_saved( get_name( multi_1 ) );


	multi_1.show_multi_string();


	return 0;
}
