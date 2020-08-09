#include <typeinfo>
#define get_name(Variable) ( #Variable )
#define get_type(Variable) ( typeid( Variable ).name()  )


// #include "lengths.cpp"


// check if a char[] has digits
bool numerics ( const char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= '0' and a[i] <= '9' )
			return true;

	return false;
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




// Name, size, type





// gets type
string type ( const char a[] )
{
	int size = length(a);

	if ( size <= 0 )
		return "empty / invalid variable";

	string result;

	if ( a[ size - 1 ] == 'v' )
		result = result + "void";

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
string type_name ( const char a[], string name )
{
	int size = length(a);

	string result;

	result = result + type(a) + ' ' + name;

	return result;
}

// gets name and size
string name_size ( const char a[], string name )
{
	int size = length(a);

	string result;

	result = result + name;

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
string type_name_size ( const char a[], string name )
{
	int size = length(a);

	string result;

	result = result + type(a) + ' ' + name;

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




// Subprogram




string subprogram_parameter_types ( const char types[] )
{
	string types_string = "( ";

	if ( length( types ) < 4 )
		return "";

	for ( int i=2; i<length( types ) - 1; i=i+1 )
	{
		const char temp[10] = { types[i] };
		types_string = types_string + type( temp );

		if ( i != length( types ) - 2 )
			types_string = types_string + ", ";
		else
			types_string = types_string + " )";
	}

	return types_string;
}

string subprogram_name_parameter_types ( const char types[], string name )
{
	string types_string = "( ";

	if ( length( types ) < 4 )
		return "";

	for ( int i=2; i<length( types ) - 1; i=i+1 )
	{
		const char temp[10] = { types[i] };
		types_string = types_string + type( temp );

		if ( i != length( types ) - 2 )
			types_string = types_string + ", ";
		else
			types_string = types_string + " )";
	}

	return name + " " + types_string;
}

string subprogram_return_type ( const char types[] )
{
	if ( length( types ) <= 2 )
		return "";

	const char temp[10] = { types[1] };
	string types_string = type( temp );

	return types_string;
}

string subprogram_return_type_name ( const char types[], string name )
{
	if ( length( types ) <= 2 )
		return "";

	const char temp[10] = { types[1] };
	string types_string = type( temp );

	return types_string + ' ' + name;
}


string subprogram_return_type_name_parameter_types ( const char types[], string name )
{
	string types_string = "( ";

	if ( length( types ) <= 2 )
		return "";

	return subprogram_return_type( types ) + ' ' + name + ' ' + subprogram_parameter_types( types );
}




long verif_int_double ( int a, double b )
{
	
}


