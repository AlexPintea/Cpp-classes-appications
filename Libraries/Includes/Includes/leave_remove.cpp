// #include "lengths.cpp"
// #include "empty.cpp"



// char




// leave chars in a char[] to leave only $#$%!#
void leave_chars ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) or ( a[i] >= '0' and a[i] <= '9' ) ) )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}

void leave_data ( char a[] );

// remove chars in a char[] to leave only 
void remove_chars ( char a[] )
{
	leave_data(a);
}

// leaves numerics in a char[]
void leave_numerics ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= '0' and a[i] <= '9' )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}

// remove numerics in a char[]
void remove_numerics ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( a[i] >= '0' and a[i] <= '9' ) )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}

// leaves data in a char[] ( a, b, 1, 4, 2 etc. )
void leave_data ( char a[] )
{
	int size = length(a);

	char result[1000] = {};
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( ( a[i] >= '0' and a[i] <= '9' ) or ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) )
		{
			result[ iter ] = a[i];
			iter = iter + 1;
		}

	empty (a);

	int size_result = length( result );

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];

}


// remove data in a char[] ( a, b, 1, 4, 2 etc )
void remove_data ( char a[] )
{
	leave_chars(a);
}




// string





// leave chars in a string to leave only $#$%!#
string leave_chars ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) or ( a[i] >= '0' and a[i] <= '9' ) ) )
			result = result + a[i];

	a = result;

	return a;
}

string leave_data ( string &a );

// leaves numerics in a string
string leave_numerics ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= '0' and a[i] <= '9' )
			result = result + a[i];

	a = result;

	return a;
}

// remove numerics in a string
string remove_numerics ( string &a )
{
	int size = a.length();

	string result = "";
	
	for ( int i=0; i<size; i=i+1 )
		if ( !( a[i] >= '0' and a[i] <= '9' ) )
			result = result + a[i];
	a = result;

	return a;
}

// leaves data in a string ( a, b, 1, 4, 2 etc. )
string leave_data ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( ( a[i] >= '0' and a[i] <= '9' ) or ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) )
			result = result + a[i];

	a = result;

	return a;
}

// remove data in a string ( a, b, 1, 4, 2 etc )
string remove_data ( string &a )
{
	return leave_chars(a);
}



