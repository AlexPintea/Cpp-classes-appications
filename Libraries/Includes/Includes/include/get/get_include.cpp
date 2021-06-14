#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"
#include "../../empty.cpp" // length
#include "../../convert.cpp" // empty, last
#include "../../lists.cpp"

#include "../../get.cpp"

int main ()
{

	string a[70] = { "a", "ab", "string", "a_string", "strings", "a string", "string b" };	
	string strings[70] = { "a", "ab", "string", "a_string" };	
//	set_num( strings, 2, 1 );
	set_columns( a, strings, 2, 1 );






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
