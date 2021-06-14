#include "../../includes.cpp"

#include "../../length.cpp"

#include "../../multi.cpp"

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
