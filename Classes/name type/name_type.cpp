#include <string>
#include <iostream>
#include <typeinfo>
#define get_name(Variable) ( #Variable )
#define get_type(Variable) ( typeid( Variable ).name()  )

using namespace std;

// length of a char[]
int length( const char a[] )
{
	int i=0;

	while ( a[i] )
		i=i+1;

	return i;
}

// length of a string[]
int length ( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
		i=i+1;

	return i;
}

// empty a char[]
void empty( char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = '\0';
}

// check if a char[] has digits
bool numerics ( const char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= '0' and a[i] <= '9' )
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

// leave digits
void leave_digits ( char a[], string &result )
{
	int size = length( a );

	if ( size == 1  and ( a[0] >= '0' and a[0] <= '9' ) )
		return;

	// replace chars with ' '
	for ( int i=0; i<size; i=i+1 )
		if ( !( a[i] >= '0' and a[i] <= '9' ) )
			a[i] = ' ';


	result = "";

	// reduce ' '-s
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ')
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";


	// delete last ' '
	if ( result[ result.length() - 1 ] == ' ' )
		remove_char( result, result.length() - 1 );

	// delete initial ' '
	if ( result[ 0 ] == ' ' )
		remove_char( result, 0 );
}


// move nums of   string text   into   nums[]
void move_nums ( string text, string nums[] )
{
	int size = text.length();

	text = text + ' ';

	int nums_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			nums_iter = nums_iter + 1;
			nums[ nums_iter ] = "";
		}
		else
			nums[ nums_iter ] = nums[ nums_iter ] + text[i];
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





// Name, size, type





// gets type
string type ( const char a[] )
{
	int size = length(a);

	if ( size <= 0 )
		return "empty / invalid variable";

	string result;

	if ( a[ size - 1 ] == 'i' )
		result = result + "int";

	if ( a[ size - 1 ] == 's' )
		result = result + "short int";

	if ( a[ size - 1 ] == 'l' )
		result = result + "long";

	if ( a[ size - 1 ] == 'd' )
		result = result + "double";

	if ( a[ size - 1 ] == 'f' )
		result = result + "float";

	if ( a[ size - 1 ] == 'c' )
		result = result + "char";

	if ( a[ size - 1 ] == 'b' )
		result = result + "bool";

	if ( a[ size - 1 ] == 'e' )
		result = result + "long double";

	if ( a[ size - 1 ] == 'x' )
		result = result + "long long";

	if ( size > 1 )
		if ( a[ size - 2 ] == 'P' )
			result = "( pointer ) " + result;

	return result;
}

// gets size as a string
string size ( const char a[] )
{
	int size = length(a);

	string result = "";

	if ( numerics(a) )
	{
		char a_chars[ 104 ];

		for ( int i=0; i<size; i=i+1 )
			a_chars[i] = a[i];

		string sizes[ 104 ];
		string digits;
		leave_digits( a_chars, digits );



		move_nums( digits, sizes );

	
		for ( int i=0; i<length( sizes ); i=i+1 )
			result = result + '[' + sizes[i] + ']';
	}

	return result;
}

// gets size as an int[]
void size ( const char a[], int size_ints[] )
{
	int size = length(a);

	if ( numerics(a) )
	{
		char a_chars[ 104 ];

		for ( int i=0; i<size; i=i+1 )
			a_chars[i] = a[i];

		string sizes[ 104 ];
		string digits;
		leave_digits( a_chars, digits );

		move_nums( digits, sizes );

		for ( int i=0; i<length( sizes ); i=i+1 )
			size_ints[i] = string_to_int( sizes[i] );
	}

}

// gets size as long[] ( to make sure )
void size ( const char a[], long size_longs[] )
{
	int size = length(a);

	if ( numerics(a) )
	{
		char a_chars[ 104 ];

		for ( int i=0; i<size; i=i+1 )
			a_chars[i] = a[i];

		string sizes[ 104 ];
		string digits;
		leave_digits( a_chars, digits );

		move_nums( digits, sizes );

		for ( int i=0; i<length( sizes ); i=i+1 )
			size_longs[i] = string_to_long( sizes[i] );
	}

}

// gets type and size
string type_size ( const char a[] )
{
	int size = length(a);

	string result;

	result = result + type(a);

	if ( numerics(a) )
	{
		char a_chars[ 104 ];

		for ( int i=0; i<size; i=i+1 )
			a_chars[i] = a[i];

		string sizes[ 104 ];
		string digits;
		leave_digits( a_chars, digits );



		move_nums( digits, sizes );

		result = result + ' ';
		for ( int i=0; i<length( sizes ); i=i+1 )
			result = result + '[' + sizes[i] + ']';
	}

	return result;
}

// gets type and name
string type_name ( const char a[] )
{
	int size = length(a);

	string result;

	result = result + type(a) + ' ' + get_name(a);

	return result;
}

// gets name and size
string name_size ( const char a[] )
{
	int size = length(a);

	string result;

	result = result + get_name(a);

	if ( numerics(a) )
	{
		char a_chars[ 104 ];

		for ( int i=0; i<size; i=i+1 )
			a_chars[i] = a[i];

		string sizes[ 104 ];
		string digits;
		leave_digits( a_chars, digits );



		move_nums( digits, sizes );

	
		for ( int i=0; i<length( sizes ); i=i+1 )
			result = result + '[' + sizes[i] + ']';
	}

	return result;
}

// gets type, name, size
string type_name_size ( const char a[] )
{
	int size = length(a);

	string result;

	result = result + type(a) + ' ' + get_name(a);

	if ( numerics(a) )
	{
		char a_chars[ 104 ];

		for ( int i=0; i<size; i=i+1 )
			a_chars[i] = a[i];

		string sizes[ 104 ];
		string digits;
		leave_digits( a_chars, digits );



		move_nums( digits, sizes );

	
		for ( int i=0; i<length( sizes ); i=i+1 )
			result = result + '[' + sizes[i] + ']';
	}

	return result;
}




int main ()
{
	int a[104][70][29];

	cout << get_type(a) << "\n";
	cout << get_name(a) << "\n";
	cout << type( get_type(a) ) << "\n";
	cout << size( get_type(a) ) << "\n";



	//  int is enough for sizes:
	//	bool b[7299999]; // as much as an [] can have ( add 1, and its Segm. fault )
	//	int a_int = 7299999;
	//	cout << a_int << "\n\n"; // could be stored in an int. 

	// get sizes as int
	int sizes[190];

	size( get_type(a), sizes );

	int i=0; 
	while ( sizes[i] ) 
	{
		cout << sizes[i] << " ";
		i=i+1;
	} 
	cout << "\n";



	cout << type_size( get_type(a) ) << "\n";
	cout << type_name( get_type(a) ) << "\n";
	cout << name_size( get_type(a) ) << "\n";
	cout << type_name_size( get_type(a) ) << "\n";


	return 0;
}
