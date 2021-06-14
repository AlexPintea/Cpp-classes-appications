#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"
#include "../../empty.cpp" // length

#include "../../convert.cpp"

int main ()
{

	// if you have "Segmentation fault", chars that are not common or even system faults - recompile
	cout << "if you have \"Segmentation fault\", chars that are not common or even system faults - recompile\n\n";



	// [datatype]_to_string



	cout << "( info ) [datatype]_to_string\n";

	cout << int_to_string( -142 ) << "\n"; //
	cout << long_to_string( -1999999 ) << "\n"; //
//	cout << double_to_string( -1.0207, 3 ) << "\n"; //
	cout << double_to_string( -1.0207 ) << "\n"; //
//	cout << float_to_string( -109254.014, 3 ) << "\n"; //
	cout << float_to_string( -109254.014 ) << "\n"; //
	cout << bool_to_string( true ) << "\n"; //
	cout << char_to_string( 'a' ) << "\n"; //

	cout << "\n";



	// datatype[]_to_string and datatype[]_to_string[]



	cout << "( info ) datatype[]_to_string and datatype[]_to_string[]\n";

	string string_a;
	string strings_a[10];

	int ints_a[10] = { 142, 107, 201 };
	string_a = int_to_string( ints_a ); //
	int_to_string( ints_a, strings_a ); // 
	cout << string_a << "\n";
	for ( int i=0; i<length(strings_a); i=i+1 )
		cout << strings_a[i] << " ";
	empty( strings_a );
	cout << "\n";

	long longs_a[10] = { 999999999, 207, 1 };
	string_a = longs_to_string( longs_a ); //
	long_to_string( longs_a, strings_a );  //
	cout << string_a << "\n";
	for ( int i=0; i<length(strings_a); i=i+1 )
		cout << strings_a[i] << " ";
	empty( strings_a );
	cout << "\n";

	double doubles_a[10] = { 99999.9999, 2.07, 0.3 };
	string_a = doubles_to_string( doubles_a ); //
	double_to_string( doubles_a, strings_a );  //
	cout << string_a << "\n";
	for ( int i=0; i<length(strings_a); i=i+1 )
		cout << strings_a[i] << " ";
	empty( strings_a );
	cout << "\n";

	char chars_a[10] = { 'a', 'b' };
	string_a = chars_to_string( chars_a ); //
	char_to_string( chars_a, strings_a );  //
	cout << string_a << "\n";
	for ( int i=0; i<length(strings_a); i=i+1 )
		cout << strings_a[i] << " ";
	empty( strings_a );
	cout << "\n";

	cout << "\n";



	// [datatype]_to_char[]



	cout << "( info ) [datatype]_to_char[]\n";

	char digits[10];
	int_to_chars( 142, digits ); //
	for ( int i=0; i<length( digits ); i=i+1 )
		cout << digits[i] << " ";
	cout << "\n";

	empty( digits );
	long_to_chars( 19999942, digits ); //
	for ( int i=0; i<length( digits ); i=i+1 )
		cout << digits[i] << " ";
	cout << "\n";

	empty( digits );
	double_to_chars( 190.42, digits ); //
	for ( int i=0; i<length( digits ); i=i+1 )
		cout << digits[i] << " ";
	cout << "\n";

	empty( digits );
	bool_to_chars( true, digits ); //
	for ( int i=0; i<length( digits ); i=i+1 )
		cout << digits[i] << " ";
	cout << "\n";

	empty( digits );
	string_to_chars( "a string", digits ); //
	for ( int i=0; i<length( digits ); i=i+1 )
		cout << digits[i] << " ";
	cout << "\n";


	cout << "\n";



	// is_[datatype] and string_to_[datatype]



	cout << "( info ) is_[datatype] and string_to_[datatype]\n";

	string a_int = "-99999999";
	if (  is_int(a_int) ) //
	{
		int a = string_to_int( a_int ); //
		cout << a << "\n";
	}

	string a_long = "-999999999999999999";
	if (  is_long(a_long) ) //
	{
		long a = string_to_long( a_long ); //
		cout << a << "\n";
	}

	string a_double = "99999.9999999999999999999999999999999";
	if ( is_double(a_double) ) //
	{
		double a = string_to_double( a_double ); //
		cout << a << "\n";
	}

	string a_char = "a";
	if ( is_char(a_char) ) //
	{
		char a = string_to_char( a_char ); //
		cout << a << "\n";
	}

	string a_bool = "false";
	if ( is_bool(a_bool) ) //
	{
		bool a = string_to_bool( a_bool ); //
		cout << a << "\n";
	}


	string a_string = "a is a string";
	if (  is_only_string(a_string) ) //
		cout << a_string << "\n";

	cout << "\n";



	// string_to_datatype[]



	cout << "( info ) string_to_datatype[]\n";

	string a;

	a = "142 107 90 15";
	int int_a[10];
	string_to_int( a, int_a );
	for ( int i=0; i<4; i=i+1 )
		cout << int_a[i] << " ";
	cout << "\n";

	a = "1492 10447 903 1";
	long long_a[10];
	string_to_long( a, long_a );
	for ( int i=0; i<4; i=i+1 )
		cout << long_a[i] << " ";
	cout << "\n";

	a = "14.92 10.447 9.03 0.1";
	double double_a[10];
	string_to_double( a, double_a );
	for ( int i=0; i<4; i=i+1 )
		cout << double_a[i] << " ";
	cout << "\n";

	a = "14.2 10.47 9.3 0.91";
	float float_a[10];
	string_to_float( a, float_a );
	for ( int i=0; i<4; i=i+1 )
		cout << float_a[i] << " ";
	cout << "\n";

	a = "a b l m";
	char char_a[10];
	string_to_char( a, char_a );
	for ( int i=0; i<4; i=i+1 )
		cout << char_a[i] << " ";
	cout << "\n";

	a = "1 0 true false";
	bool bool_a[10];
	string_to_bool( a, bool_a );
	for ( int i=0; i<4; i=i+1 )
		cout << bool_a[i] << " ";
	cout << "\n";


	cout << "\n";

	// Datatypes of a string

	cout << "( info ) datatypes of a string (also have for every datatype)\n";
	string a_data = "-124 -999999999999999999 -1.207 a true string_this_is", data_types[10000];
	datatypes( a_data, data_types ); //
	for ( int i=0; i<length( data_types ); i=i+1 )
		cout << data_types[i] << " ";
	cout << "\n\n";


	// are_datatype[] string[]_to_datatype[]


	cout << "( info ) are_datatype[] and string[]_to_datatype[]\n";
	string int_strings[10] = { "142", "50", "47" };
	int ints[90];
	if ( are_int( int_strings ) ) //
	{
		string_to_int( int_strings, ints ); //

		for ( int i=0; i<length( ints ); i=i+1 )
			cout << ints[i] << " ";
		cout << "\n";
	}


	string long_strings[10] = { "999999999", "109999999999" };
	long longs[90];
	if ( are_long( long_strings ) ) //
	{
		string_to_long( long_strings, longs ); //

		for ( int i=0; i<length( longs ); i=i+1 )
			cout << longs[i] << " ";
		cout << "\n";
	}


	string double_strings[10] = { "1.207", "4.09" };
	double doubles[90];
	if ( are_double( double_strings ) ) //
	{
		string_to_double( double_strings, doubles ); //

		for ( int i=0; i<length( doubles ); i=i+1 )
			cout << doubles[i] << " ";
		cout << "\n";
	}


	string bool_strings[10] = { "true", "0" };
	bool bools[90];
	if ( are_bool( bool_strings ) ) //
	{
		string_to_bool( bool_strings, bools ); //
		cout << bools[0] << " " << bools[1] << "\n";
	}

	string char_strings1[10] = { "a", "b" };
	char chars1[90];
	if ( are_char( char_strings1 ) ) //
	{
		string_to_char( char_strings1, chars1 ); //

		for ( int i=0; i<length( chars1 ); i=i+1 )
			cout << chars1[i] << " ";
		cout << "\n";
	}

	string char_strings2[10] = { "string1", "string2" };
	char chars2[90];
	// do not check for are_chars, if not the case
	string_to_char( char_strings2, chars2 ); //
	for ( int i=0; i<length( chars2 ); i=i+1 )
		cout << chars2[i] << " ";
	cout << "\n";


	return 0;
}

