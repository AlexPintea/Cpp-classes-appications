#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../empty.cpp" // length

#include "../../lists.cpp"




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

	add_int( ints, 72, 2 );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	int ints_add[20] = { 109, 4 };
	add_ints( ints, ints_add );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	add_ints( ints, ints_add, 2 );
	for ( int i=0; i<length( ints ); i=i+1 )
		cout << "\'" << ints[i] << "\' ";
	cout << endl;

	// also leave, remove_ints_in
	remove_ints_in_pos( ints, 0, 3 );
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

	add_long( longs, 72, 2 );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;

	long longs_add[20] = { 109, 4 };
	add_longs( longs, longs_add );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;

	add_longs( longs, longs_add, 2 );
	for ( int i=0; i<length( longs ); i=i+1 )
		cout << "\'" << longs[i] << "\' ";
	cout << endl;


	// also leave, remove_longs_in
	remove_longs_in_pos( longs, 0, 3 );
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

	add_double( doubles, 1.2, 2 );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;

	double doubles_add[20] = { 109, 4 };
	add_doubles( doubles, doubles_add );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;

	add_doubles( doubles, doubles_add, 2 );
	for ( int i=0; i<length( doubles ); i=i+1 )
		cout << "\'" << doubles[i] << "\' ";
	cout << endl;



	// also leave, remove_doubles_in
	remove_doubles_in_pos( doubles, 0, 3 );
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

	add_float( floats, 72, 2 );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;

	float floats_add[20] = { 109, 4 };
	add_floats( floats, floats_add );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;

	add_floats( floats, floats_add, 2 );
	for ( int i=0; i<length( floats ); i=i+1 )
		cout << "\'" << floats[i] << "\' ";
	cout << endl;


	// also leave, remove_floats_in
	remove_floats_in_pos( floats, 0, 3 );
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

	add_char( chars, 'b', 2 );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;

	char chars_add[20] = { 'b', 'l' };
	add_chars( chars, chars_add );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;

	add_chars( chars, chars_add, 2 );
	for ( int i=0; i<length( chars ); i=i+1 )
		cout << "\'" << chars[i] << "\' ";
	cout << endl;


	// also leave, remove_chars_in
	remove_chars_in_pos( chars, 0, 3 );
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

	add_string( strings, "ab", 2 );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;

	string strings_add[20] = { "b", "string" };
	add_strings( strings, strings_add );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;

	add_strings( strings, strings_add, 2 );
	for ( int i=0; i<length( strings ); i=i+1 )
		cout << "\'" << strings[i] << "\' ";
	cout << endl;


	// also leave, remove_strings_in
	remove_strings_in_pos( strings, 0, 3 );
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
	// also leave, remove_chars_string_in
	cout << remove_chars_string_in_pos( char_string, 1, 2 ) << endl;
	cout << add_char_string( char_string, 'r' ) << endl;
	cout << add_char_string( char_string, 'p', 1 ) << endl;
	char chars_string_add[20] = { 'e', 'm' };
	cout << add_chars_string( char_string, chars_string_add ) << endl;
	cout << add_chars_string( char_string, chars_string_add, 3 ) << endl;


	return 0;
}

