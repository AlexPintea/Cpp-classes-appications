// #include "lengths.cpp"
// #include "empty.cpp"
// #include "add.cpp"


// for []-s



// a[] and b[] have iters
bool is_in ( int a[], int b[], int size, int iter )
{
	for ( int i=0; i<size; i=i+1 )
		if ( iter >= a[i] and iter <= b[i] )
			return true;

	return false;
}






// a_is_in_b








// string



// checks if  a  is in  b   or   b  is in  a  for datatype "string"
bool a_is_in_b ( string a, string b )
{
	if (a == b)
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	return a_is_in_b( a, b );
}

// checks if  a  is in  b   or   b  is in  a  for datatype "string"[]
bool a_is_in_b ( string a[], string b[] )
{
	int size_a = length(a);
	int size_b = length(b);

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "string"[]
bool b_is_in_a ( string a[], string b[] )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}

// removes  b  in  a  for datatype "string"
string remove_b_in_a ( string &a, string b )
{
	if ( !b_is_in_a( a, b ) )
		return a;

	int size_a = a.length();
	int size_b = b.length();

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}


	for ( int i=0; i<size_a; i=i+1 )
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			result = result + a[i];

	a = result;

	return a;
}

// removes  a  in  b   or   b  in  a  for datatype "string"
void remove_a_in_b ( string &a, string &b )
{
	if ( length(a) > length(b) )
		remove_b_in_a ( a, b );
	else
		remove_b_in_a ( b, a );
}

// counts  b  in  a  for datatype "string"
int count_b_in_a ( string a, string b )
{
	if ( !b_is_in_a( a, b ) )
		return -1;

	int size_a = a.length();
	int size_b = b.length();

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	return size_iter;
}
// counts  b  in  a   or   a  in  b for datatype "string"
int count_a_in_b ( string a, string b )
{
	if ( a.length() > b.length() )
		return count_b_in_a ( a, b );
	else
		return count_b_in_a ( b, a );
}


// removes  b  in  a  for datatype "string"[]
void remove_b_in_a ( string a[], string b[] )
{
	if ( !b_is_in_a( a, b ) )
		return;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	for ( int i=0; i<size_a; i=i+1 )
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			add_string( result, a[i] );

	empty(a);

	int size_result = length(result);

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];
}

// removes  a  in  b   or   b  in  a  for datatype "string"[]
void remove_a_in_b ( string a[], string b[] )
{
	if ( length(a) > length(b) )
		remove_b_in_a ( a, b );
	else
		remove_b_in_a ( b, a );
}

// counts  b  in  a  for datatype "string"[]
int count_b_in_a ( string a[], string b[] )
{
	if ( !b_is_in_a( a, b ) )
		return -1;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	return size_iter;
}
// counts  b  in  a   or   a  in  b  for datatype "string"[]
int count_a_in_b ( string a[], string b[] )
{
	if ( length(a) > length(b) )
		return count_b_in_a ( a, b );
	else
		return count_b_in_a ( b, a );
}



// long ( same for int )



// checks if  a  is in  b   or   b  is in  a  for datatype "long"
bool a_is_in_b ( long a, long b )
{
	int a_digits[10];
	int b_digits[10];

	int size_a = length(a);
	int size_b = length(b);

	for ( int i=0; i<size_a; i=i+1 )
	{
		a_digits[ size_a - i - 1 ] = a%10;
		a=a/10;
	}

	for ( int i=0; i<size_b; i=i+1 )
	{
		b_digits[ size_b - i - 1 ] = b%10;
		b=b/10;
	}


	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a_digits[i] == b_digits[0])
			{
				bool verif = 1;

				for ( int r=1; r<size_b; r=r+1 )
					if ( a_digits[ r+i ] != b_digits[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b_digits[i] == a_digits[0])
			{
				bool verif = 1;

				for ( int r=1; r<size_a; r=r+1 )
					if ( b_digits[ r+i ] != a_digits[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "long"
bool b_is_in_a ( long a, long b )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}

// remove is done with string conversion



// removes  b  in  a  for datatype "long"
void remove_b_in_a ( long &a, long b )
{
	string a_digits = long_to_string( a );
	string b_digits = long_to_string( b );

	remove_b_in_a ( a_digits, b_digits );

	a = string_to_long( a_digits );
}

// removes  a  in  b   or   b  in  a  for datatype "long"
void remove_a_in_b ( long &a, long &b )
{
	string a_digits = long_to_string( a );
	string b_digits = long_to_string( b );

	if ( length(a) > length(b) )
		remove_b_in_a ( a_digits, b_digits );
	else
		remove_b_in_a ( b_digits, a_digits );
		
	a = string_to_long( a_digits );
	b = string_to_long( b_digits );
}

// counts  b  in  a  for datatype "long"
int count_b_in_a ( long a, long b )
{
	string a_digits = long_to_string( a );
	string b_digits = long_to_string( b );

	return count_b_in_a ( a_digits, b_digits );
}

// counts  b  in  a   or   a  in  b for datatype "string"
int count_a_in_b ( long a, long b )
{
	string a_digits = long_to_string( a );
	string b_digits = long_to_string( b );

	if ( length(a) > length(b) )
		return count_b_in_a ( a_digits, b_digits );
	else
		return count_b_in_a ( b_digits, a_digits );
}

// checks if  a  is in  b   or   b  is in  a  for datatype "long"[]
bool a_is_in_b ( long a[], long b[] )
{
	int size_a = length(a);
	int size_b = length(b);

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;				

				for ( int r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=1; r<size_a; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "long"[]
bool b_is_in_a ( long a[], long b[] )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}

// removes  b  in  a  for datatype "long"[]
void remove_b_in_a ( long a[], long b[] )
{
	if ( !b_is_in_a( a, b ) )
		return;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	long result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	for ( int i=0; i<size_a; i=i+1 )
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			add_long( result, a[i] );

	empty(a);

	int size_result = length(result);

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];
}

// removes  a  in  b   or   b  in  a  for datatype "long"[]
void remove_a_in_b ( long a[], long b[] )
{
	if ( length(a) > length(b) )
		remove_b_in_a ( a, b );
	else
		remove_b_in_a ( b, a );
}

// counts  b  in  a  for datatype "long"[]
int count_b_in_a ( long a[], long b[] )
{
	string a_longs[10000];
	string b_longs[10000];

	for ( int i=0; i<length(a); i=i+1 )
		a_longs[i] = long_to_string( a[i] );

	for ( int i=0; i<length(b); i=i+1 )
		b_longs[i] = long_to_string( b[i] );

	return count_b_in_a ( a_longs, a_longs );
}


// counts  b  in  a   or   a  in  b for datatype "long"[]
int count_a_in_b ( long a[], long b[] )
{
	if ( length(a) > length(b) )
		return count_b_in_a ( a, b );
	else
		return count_b_in_a ( b, a );
}



// int



// checks if  a  is in  b  for datatype "int"
bool a_is_in_b ( int a, int b )
{
	return a_is_in_b( a, b );
}

// checks if  b  is in  a  for datatype "int"
bool b_is_in_a ( int a, int b )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}

// removes  b  in  a  for datatype "int"
void remove_b_in_a ( int &a, int b )
{
	remove_b_in_a ( a, b );
}

// removes  a  in  b   or   b  in  a  for datatype "int"
void remove_a_in_b ( int &a, int &b )
{
	remove_a_in_b ( a, b );
}


// checks if  a  is in  b  for datatype "int"[]
bool a_is_in_b ( int a[], int b[] )
{
	return a_is_in_b ( a, b );
}

// counts  b  in  a  for datatype "int"
int count_b_in_a ( int a, int b )
{
	return count_b_in_a ( a, b );
}

// counts  b  in  a   or   a  in  b  for datatype "int"
int count_a_in_b ( int a, int b )
{
	return count_a_in_b ( a, b );
}


// checks if  b  is in  a  for datatype "int"[]
bool b_is_in_a ( int a[], int b[] )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}

// removes  b  in  a  for datatype "int"[]
void remove_b_in_a ( int a[], int b[] )
{
	remove_b_in_a ( a, b );
}

// removes  a  in  b   or   b  in  a  for datatype "int"[]
void remove_a_in_b ( int a[], int b[] )
{
	remove_a_in_b( a, b );
}

// counts  b  in  a  for datatype "int"[]
int count_b_in_a ( int a[], int b[] )
{
	return count_b_in_a ( a, b );
}

// counts  b  in  a   or   a  in  b  for datatype "int"[]
int count_a_in_b ( int a[], int b[] )
{
	return count_a_in_b ( a, b );
}



// double ( same as floats )



// checks if  a  is in  b  for datatype "double"
// cannot be done, conversions affect initial val. 

// checks if  a  is in  b  for datatype "double"[]
bool a_is_in_b ( double a[], double b[] )
{
	int size_a = length(a);
	int size_b = length(b);

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "double"[]
bool b_is_in_a ( double a[], double b[] )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}


// removes  b  in  a  for datatype "double"[]
void remove_b_in_a ( double a[], double b[] )
{
	if ( !b_is_in_a( a, b ) )
		return;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	double result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	for ( int i=0; i<size_a; i=i+1 )
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			add_double( result, a[i] );

	empty(a);

	int size_result = length(result);

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];
}

// removes  a  in  b   or   b  in  a  for datatype "double"[]
void remove_a_in_b ( double a[], double b[] )
{
	if ( length(a) > length(b) )
		remove_b_in_a ( a, b );
	else
		remove_b_in_a ( b, a );
}



// float



// checks if  a  is in  b  for datatype "float"
// cannot be done, conversions affect initial val. 

// checks if  a  is in  b  for datatype "float"[]
bool a_is_in_b ( float a[], float b[] )
{
	return a_is_in_b ( a, b );
}

// checks if  b  is in  a  for datatype "int"
bool b_is_in_a ( float a[], float b[] )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}


// removes  b  in  a  for datatype "float"[]
void remove_b_in_a ( float a[], float b[] )
{
	remove_b_in_a ( a, b );
}

// removes  a  in  b   or   b  in  a  for datatype "float"[]
void remove_a_in_b ( float a[], float b[] )
{
	if ( length(a) > length(b) )
		remove_b_in_a ( a, b );
	else
		remove_b_in_a ( b, a );
}



// char



// checks if  a  is in  b   or   b  is in  a  for datatype "char" ( actually checks for a == b )
bool a_is_in_b ( char a, char b )
{
	if ( a == b )
		return true;

	return false;
}

// checks if  b  is in  a  for datatype "char" ( actually checks for a == b )
bool b_is_in_a ( char a, char b )
{
	if ( a == b )
		return true;

	return false;
}

// checks if  a  is in  b  for datatype "char"[]
int a_is_in_b ( char a[], char b[] )
{
	int size_a = length(a);
	int size_b = length(b);

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "char"[]
bool b_is_in_a ( char a[], char b[] )
{
	if ( length(a) < length(b) )
		return false;

	return a_is_in_b( a, b );
}

// removes  b  in  a  for datatype "char"[]
void remove_b_in_a ( char a[], char b[] )
{
	if ( !b_is_in_a( a, b ) )
		return;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	char result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	for ( int i=0; i<size_a; i=i+1 )
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			add_char( result, a[i] );

	empty( a );

	int size_result = length(result);

	for ( int i=0; i<size_result; i=i+1 )
		a[i] = result[i];
}

// removes  a  in  b   or   b  in  a  for datatype "char"[]
void remove_a_in_b ( char a[], char b[] )
{
	if ( length(a) > length(b) )
		remove_b_in_a ( a, b );
	else
		remove_b_in_a ( b, a );
}

// counts  b  in  a  for datatype "char"[]
int count_b_in_a ( char a[], char b[] )
{
	if ( !b_is_in_a( a, b ) )
		return -1;

	int size_a = length(a);
	int size_b = length(b);

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	long result[1000] = {};

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}

	return size_iter;
}

// counts  b  in  a   or   a  in  b  for datatype "char"[]
int count_a_in_b ( char a[], char b[] )
{
	if ( length(a) > length(b) )
		return count_a_in_b ( a, b );
	else
		return count_a_in_b ( b, a );
}


