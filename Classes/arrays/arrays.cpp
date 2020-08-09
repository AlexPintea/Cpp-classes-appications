#include <string.h>
#include <iostream>
#include <string>

using namespace std;



// lengths



int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
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

int length(long a[])
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

int length(bool a[])  // does not return validly
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

int length (string a)
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





// int[]





int empty_int[10000] = {};

// empties an int[]
void empty ( int a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_int[i];
}

// is in int[]
bool is_in_ints ( int ints[], int a )
{
	int size = length( ints );

	for ( int i=0; i<size; i=i+1 )
		if ( ints[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_int_at ( int ints[], int iter )
{
	int size = length( ints );

	int remaining_ints[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_ints[ iter_remaining ] = ints[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( ints );

	for ( int i=0; i<iter_remaining; i=i+1 )
		ints[i] = remaining_ints[i];

}

// removes all ints-s  at iters[]  of int[]  ints  
void remove_ints_at ( int ints[], int iters[] )
{
	int size = length( ints );

	int ints_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				ints_removed[iter] = ints[i];
				iter = iter + 1;
			}

	empty( ints );

	for ( int i=0; i<iter; i=i+1 )
		ints[i] = ints_removed[i];
}

// removes all ints-s  of remove[]  of int[]  ints  
void remove_ints ( int ints[], int remove[] )
{
	int size = length( ints );

	int ints_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( remove, ints[i] ) )
			{
				ints_removed[iter] = ints[i];
				iter = iter + 1;
			}

	empty( ints );

	for ( int i=0; i<iter; i=i+1 )
		ints[i] = ints_removed[i];
}

// removes all ints-s  a  of int[]  ints  
void remove_int ( int ints[], int a )
{
	int size = length( ints );
	int iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( ints[i] != a )
		{
			iters[ iter ] = ints[i];
			iter = iter + 1;
		}

	empty( ints );

	for ( int i=0; i<iter; i=i+1 )
		ints[i] = iters[i];
}

// removes ints with position ( >= a1 and <= a2 )
void remove_ints_in_pos ( int ints[], int a1, int a2 )
{
	int size = length( ints );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	int remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( i >= a1 and i <= a2 ) )
		{
			remaining[ size_remaining ] = ints[i];
			size_remaining = size_remaining + 1;
		}

	empty( ints );

	for ( int i=0; i<size_remaining; i=i+1 )
		ints[i] = remaining[i];
}

// leave only ints with position ( >= a1 and <= a2 )  
void leave_ints_in_pos ( int ints[], int a1, int a2 )
{
	int size = length( ints );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	int remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i >= a1 and i <= a2 )
		{
			remaining[ size_remaining ] = ints[i];
			size_remaining = size_remaining + 1;
		}

	empty( ints );

	for ( int i=0; i<size_remaining; i=i+1 )
		ints[i] = remaining[i];
}

// removes ints ( >= a1 and <= a2 )  
void remove_ints_in ( int ints[], int a1, int a2 )
{
	int size = length( ints );

	int remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( ints[i] >= a1 and ints[i] <= a2 ) )
		{
			remaining[ size_remaining ] = ints[i];
			size_remaining = size_remaining + 1;
		}

	empty( ints );

	for ( int i=0; i<size_remaining; i=i+1 )
		ints[i] = remaining[i];
}

// leave only ints ( >= a1 and <= a2 )  
void leave_ints_in ( int ints[], int a1, int a2 )
{
	int size = length( ints );

	int remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( ints[i] >= a1 and ints[i] <= a2 )
		{
			remaining[ size_remaining ] = ints[i];
			size_remaining = size_remaining + 1;
		}

	empty( ints );

	for ( int i=0; i<size_remaining; i=i+1 )
		ints[i] = remaining[i];
}


// add  int  to  int[]  
void add_int ( int ints[], int a )
{
	int size = length( ints );

	ints[ size ] = a;
}

// add  int[]  to   int[]  
void add_ints ( int ints[], int add[] )
{
	int size_ints = length( ints );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		ints[ size_ints + i ] = add[i];
}

// add  int  to  int[]  at a certain position
void add_int ( int ints[], int a, int position )
{
	int size = length( ints );

	if ( position == size )
		add_int( ints, a );

	if ( position < 0 or position >= size )
		return;

	int result[1000];
	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
	{
		if ( position == i )
		{
			result[ counter ] = a;
			counter = counter + 1;
		}

		result[ counter ] = ints[i];
		counter = counter + 1;
	}

	size = size + 1;

	for ( int i=0; i<size; i=i+1 )
		ints[i] = result[i];
}

// add  int[]  to   int[]  at a certain position
void add_ints ( int ints[], int add[], int position )
{
	int size_ints = length( ints );
	int size_add = length(add);

	if ( position == size_ints )
		add_ints( ints, add );

	if ( position < 0 or position >= size_ints )
		return;

	int result[1000];
	int counter = 0;
	for ( int i=0; i<size_ints; i=i+1 )
	{
		if ( position == i )
			for ( int l=0; l<size_add; l=l+1 )
			{
				result[ counter ] = add[l];
				counter = counter + 1;
			}

		result[ counter ] = ints[i];
		counter = counter + 1;
	}

	size_ints = size_ints + size_add;

	for ( int i=0; i<size_ints; i=i+1 )
		ints[i] = result[i];
}



// long[]



long empty_long[10000] = {};

// empties a long[]
void empty ( long a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_long[i];
}

// is in long[]
bool is_in_longs ( long longs[], long a )
{
	int size = length( longs );

	for ( int i=0; i<size; i=i+1 )
		if ( longs[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_long_at ( long longs[], int iter )
{
	int size = length( longs );

	long remaining_longs[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_longs[ iter_remaining ] = longs[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( longs );

	for ( int i=0; i<iter_remaining; i=i+1 )
		longs[i] = remaining_longs[i];
}

// removes all longs-s  at iters[]  of long[]  longs  
void remove_longs_at ( long longs[], int iters[] )
{
	int size = length( longs );

	long longs_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				longs_removed[iter] = longs[i];
				iter = iter + 1;
			}

	empty( longs );

	for ( int i=0; i<iter; i=i+1 )
		longs[i] = longs_removed[i];
}

// removes all longs-s  at remove[]  of long[]  longs  
void remove_longs ( long longs[], long remove[] )
{
	int size = length( longs );

	long longs_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_longs( remove, longs[i] ) )
			{
				longs_removed[iter] = longs[i];
				iter = iter + 1;
			}

	empty( longs );

	for ( int i=0; i<iter; i=i+1 )
		longs[i] = longs_removed[i];
}

// removes all longs-s  a  of long[]  longs  
void remove_long ( long longs[], long a )
{
	int size = length( longs );
	long iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( longs[i] != a )
		{
			iters[ iter ] = longs[i];
			iter = iter + 1;
		}

	empty( longs );

	for ( int i=0; i<iter; i=i+1 )
		longs[i] = iters[i];
}


// removes longs with position ( >= a1 and <= a2 )  
void remove_longs_in_pos ( long longs[], int a1, int a2 )
{
	int size = length( longs );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	long remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( i >= a1 and i <= a2 ) )
		{
			remaining[ size_remaining ] = longs[i];
			size_remaining = size_remaining + 1;
		}

	empty( longs );

	for ( int i=0; i<size_remaining; i=i+1 )
		longs[i] = remaining[i];
}

// leave only longs with position ( >= a1 and <= a2 )  
void leave_longs_in_pos ( long longs[], int a1, int a2 )
{
	int size = length( longs );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	long remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i >= a1 and i <= a2 )
		{
			remaining[ size_remaining ] = longs[i];
			size_remaining = size_remaining + 1;
		}

	empty( longs );

	for ( int i=0; i<size_remaining; i=i+1 )
		longs[i] = remaining[i];
}

// removes longs ( >= a1 and <= a2 )  
void remove_longs_in ( long longs[], long a1, long a2 )
{
	int size = length( longs );

	long remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( longs[i] >= a1 and longs[i] <= a2 ) )
		{
			remaining[ size_remaining ] = longs[i];
			size_remaining = size_remaining + 1;
		}

	empty( longs );

	for ( int i=0; i<size_remaining; i=i+1 )
		longs[i] = remaining[i];
}

// leave only longs ( >= a1 and <= a2 )  
void leave_longs_in ( long longs[], long a1, long a2 )
{
	int size = length( longs );

	long remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( longs[i] >= a1 and longs[i] <= a2 )
		{
			remaining[ size_remaining ] = longs[i];
			size_remaining = size_remaining + 1;
		}

	empty( longs );

	for ( int i=0; i<size_remaining; i=i+1 )
		longs[i] = remaining[i];
}


// add  long  to  long[]  
void add_long ( long longs[], long a )
{
	int size = length( longs );

	longs[ size ] = a;
}

// add  long[]  to   long[]  
void add_longs ( long longs[], long add[] )
{
	int size_longs = length( longs );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		longs[ size_longs + i ] = add[i];
}

// add  long  to  long[]  at a certain position
void add_long ( long longs[], long a, int position )
{
	int size = length( longs );

	if ( position == size )
		add_long( longs, a );

	if ( position < 0 or position >= size )
		return;

	long result[1000];
	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
	{
		if ( position == i )
		{
			result[ counter ] = a;
			counter = counter + 1;
		}

		result[ counter ] = longs[i];
		counter = counter + 1;
	}

	size = size + 1;

	for ( int i=0; i<size; i=i+1 )
		longs[i] = result[i];
}

// add  long[]  to   long[]  at a certain position
void add_longs ( long longs[], long add[], int position )
{
	int size_longs = length( longs );
	int size_add = length(add);

	if ( position == size_longs )
		add_longs( longs, add );

	if ( position < 0 or position >= size_longs )
		return;

	long result[1000];
	int counter = 0;
	for ( int i=0; i<size_longs; i=i+1 )
	{
		if ( position == i )
			for ( int l=0; l<size_add; l=l+1 )
			{
				result[ counter ] = add[l];
				counter = counter + 1;
			}

		result[ counter ] = longs[i];
		counter = counter + 1;
	}

	size_longs = size_longs + size_add;

	for ( int i=0; i<size_longs; i=i+1 )
		longs[i] = result[i];
}



// double[]



double empty_double[10000] = {};

// empties a double[]
void empty ( double a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_double[i];
}

// is in double[]
bool is_in_doubles ( double doubles[], double a )
{
	int size = length( doubles );

	for ( int i=0; i<size; i=i+1 )
		if ( doubles[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_double_at ( double doubles[], int iter )
{
	int size = length( doubles );

	double remaining_doubles[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_doubles[ iter_remaining ] = doubles[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( doubles );

	for ( int i=0; i<iter_remaining; i=i+1 )
		doubles[i] = remaining_doubles[i];
}

// removes all doubles-s  at iters[]  of double[]  doubles  
void remove_doubles_at ( double doubles[], int iters[] )
{
	int size = length( doubles );

	double doubles_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				doubles_removed[iter] = doubles[i];
				iter = iter + 1;
			}

	empty( doubles );

	for ( int i=0; i<iter; i=i+1 )
		doubles[i] = doubles_removed[i];
}

// removes all doubles-s  of remove[]  of double[]  doubles  
void remove_doubles ( double doubles[], double remove[] )
{
	int size = length( doubles );

	double doubles_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_doubles( remove, doubles[i] ) )
			{
				doubles_removed[iter] = doubles[i];
				iter = iter + 1;
			}

	empty( doubles );

	for ( int i=0; i<iter; i=i+1 )
		doubles[i] = doubles_removed[i];
}

// removes all doubles-s  a  of double[]  doubles  
void remove_double ( double doubles[], double a )
{
	int size = length( doubles );
	double iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( doubles[i] != a )
		{
			iters[ iter ] = doubles[i];
			iter = iter + 1;
		}

	empty( doubles );

	for ( int i=0; i<iter; i=i+1 )
		doubles[i] = iters[i];
}

// removes doubles with position ( >= a1 and <= a2 )  
void remove_doubles_in_pos ( double doubles[], int a1, int a2 )
{
	int size = length( doubles );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	double remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( i >= a1 and i <= a2 ) )
		{
			remaining[ size_remaining ] = doubles[i];
			size_remaining = size_remaining + 1;
		}

	empty( doubles );

	for ( int i=0; i<size_remaining; i=i+1 )
		doubles[i] = remaining[i];
}

// leave only doubles with position ( >= a1 and <= a2 )  
void leave_doubles_in_pos ( double doubles[], int a1, int a2 )
{
	int size = length( doubles );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	double remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i >= a1 and i <= a2 )
		{
			remaining[ size_remaining ] = doubles[i];
			size_remaining = size_remaining + 1;
		}

	empty( doubles );

	for ( int i=0; i<size_remaining; i=i+1 )
		doubles[i] = remaining[i];
}

// removes doubles ( >= a1 and <= a2 )  
void remove_doubles_in ( double doubles[], double a1, double a2 )
{
	int size = length( doubles );

	double remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( doubles[i] >= a1 and doubles[i] <= a2 ) )
		{
			remaining[ size_remaining ] = doubles[i];
			size_remaining = size_remaining + 1;
		}

	empty( doubles );

	for ( int i=0; i<size_remaining; i=i+1 )
		doubles[i] = remaining[i];
}

// leave only doubles ( >= a1 and <= a2 )  
void leave_doubles_in ( double doubles[], double a1, double a2 )
{
	int size = length( doubles );

	double remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( doubles[i] >= a1 and doubles[i] <= a2 )
		{
			remaining[ size_remaining ] = doubles[i];
			size_remaining = size_remaining + 1;
		}

	empty( doubles );

	for ( int i=0; i<size_remaining; i=i+1 )
		doubles[i] = remaining[i];
}


// add  double  to  double[]  
void add_double ( double doubles[], double a )
{
	int size = length( doubles );

	doubles[ size ] = a;
}

// add  double[]  to   double[]  
void add_doubles ( double doubles[], double add[] )
{
	int size_doubles = length( doubles );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		doubles[ size_doubles + i ] = add[i];
}

// add  double  to  double[]  at a certain position
void add_double ( double doubles[], double a, int position )
{
	int size = length( doubles );

	if ( position == size )
		add_double( doubles, a );

	if ( position < 0 or position >= size )
		return;

	double result[1000];
	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
	{
		if ( position == i )
		{
			result[ counter ] = a;
			counter = counter + 1;
		}

		result[ counter ] = doubles[i];
		counter = counter + 1;
	}

	size = size + 1;

	for ( int i=0; i<size; i=i+1 )
		doubles[i] = result[i];
}

// add  double[]  to   double[]  at a certain position
void add_doubles ( double doubles[], double add[], int position )
{
	int size_doubles = length( doubles );
	int size_add = length(add);

	if ( position == size_doubles )
		add_doubles( doubles, add );

	if ( position < 0 or position >= size_doubles )
		return;

	double result[1000];
	int counter = 0;
	for ( int i=0; i<size_doubles; i=i+1 )
	{
		if ( position == i )
			for ( int l=0; l<size_add; l=l+1 )
			{
				result[ counter ] = add[l];
				counter = counter + 1;
			}

		result[ counter ] = doubles[i];
		counter = counter + 1;
	}

	size_doubles = size_doubles + size_add;

	for ( int i=0; i<size_doubles; i=i+1 )
		doubles[i] = result[i];
}



// float[]



float empty_float[10000] = {};

// empties a float[]
void empty ( float a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_float[i];
}

// is in float[]
bool is_in_floats ( float floats[], float a )
{
	int size = length( floats );

	for ( int i=0; i<size; i=i+1 )
		if ( floats[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_float_at ( float floats[], int iter )
{
	int size = length( floats );

	float remaining_floats[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_floats[ iter_remaining ] = floats[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( floats );

	for ( int i=0; i<iter_remaining; i=i+1 )
		floats[i] = remaining_floats[i];
}

// removes all floats-s  at iters[]  of float[]  floats  
void remove_floats_at ( float floats[], int iters[] )
{
	int size = length( floats );

	float floats_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				floats_removed[iter] = floats[i];
				iter = iter + 1;
			}

	empty( floats );

	for ( int i=0; i<iter; i=i+1 )
		floats[i] = floats_removed[i];
}

// removes all floats-s  in remove[]  of float[]  floats  
void remove_floats ( float floats[], float remove[] )
{
	int size = length( floats );

	float floats_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_floats( remove, floats[i] ) )
			{
				floats_removed[iter] = floats[i];
				iter = iter + 1;
			}

	empty( floats );

	for ( int i=0; i<iter; i=i+1 )
		floats[i] = floats_removed[i];
}

// removes all floats-s  a  of float[]  floats  
void remove_float ( float floats[], float a )
{
	int size = length( floats );
	float iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( floats[i] != a )
		{
			iters[ iter ] = floats[i];
			iter = iter + 1;
		}

	empty( floats );

	for ( int i=0; i<iter; i=i+1 )
		floats[i] = iters[i];
}

// removes floats with position ( >= a1 and <= a2 )  
void remove_floats_in_pos ( float floats[], int a1, int a2 )
{
	int size = length( floats );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	float remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( i >= a1 and i <= a2 ) )
		{
			remaining[ size_remaining ] = floats[i];
			size_remaining = size_remaining + 1;
		}

	empty( floats );

	for ( int i=0; i<size_remaining; i=i+1 )
		floats[i] = remaining[i];
}

// leave only floats with position ( >= a1 and <= a2 )  
void leave_floats_in_pos ( float floats[], int a1, int a2 )
{
	int size = length( floats );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	float remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i >= a1 and i <= a2 )
		{
			remaining[ size_remaining ] = floats[i];
			size_remaining = size_remaining + 1;
		}

	empty( floats );

	for ( int i=0; i<size_remaining; i=i+1 )
		floats[i] = remaining[i];
}

// removes floats ( >= a1 and <= a2 )  
void remove_floats_in ( float floats[], float a1, float a2 )
{
	int size = length( floats );

	float remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( floats[i] >= a1 and floats[i] <= a2 ) )
		{
			remaining[ size_remaining ] = floats[i];
			size_remaining = size_remaining + 1;
		}

	empty( floats );

	for ( int i=0; i<size_remaining; i=i+1 )
		floats[i] = remaining[i];
}

// leave only floats ( >= a1 and <= a2 )  
void leave_floats_in ( float floats[], float a1, float a2 )
{
	int size = length( floats );

	float remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( floats[i] >= a1 and floats[i] <= a2 )
		{
			remaining[ size_remaining ] = floats[i];
			size_remaining = size_remaining + 1;
		}

	empty( floats );

	for ( int i=0; i<size_remaining; i=i+1 )
		floats[i] = remaining[i];
}



// add  float  to  float[]  
void add_float ( float floats[], float a )
{
	int size = length( floats );

	floats[ size ] = a;
}

// add  float[]  to   float[]  
void add_floats ( float floats[], float add[] )
{
	int size_floats = length( floats );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		floats[ size_floats + i ] = add[i];
}

// add  float  to  float[]  at a certain position
void add_float ( float floats[], float a, int position )
{
	int size = length( floats );

	if ( position == size )
		add_float( floats, a );

	if ( position < 0 or position >= size )
		return;

	float result[1000];
	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
	{
		if ( position == i )
		{
			result[ counter ] = a;
			counter = counter + 1;
		}

		result[ counter ] = floats[i];
		counter = counter + 1;
	}

	size = size + 1;

	for ( int i=0; i<size; i=i+1 )
		floats[i] = result[i];
}

// add  float[]  to   float[]  at a certain position
void add_floats ( float floats[], float add[], int position )
{
	int size_floats = length( floats );
	int size_add = length(add);

	if ( position == size_floats )
		add_floats( floats, add );

	if ( position < 0 or position >= size_floats )
		return;

	float result[1000];
	int counter = 0;
	for ( int i=0; i<size_floats; i=i+1 )
	{
		if ( position == i )
			for ( int l=0; l<size_add; l=l+1 )
			{
				result[ counter ] = add[l];
				counter = counter + 1;
			}

		result[ counter ] = floats[i];
		counter = counter + 1;
	}

	size_floats = size_floats + size_add;

	for ( int i=0; i<size_floats; i=i+1 )
		floats[i] = result[i];
}



// char[]



char empty_char[10000] = {};

// empties a char[]
void empty ( char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_char[i];
}

// is in char[]
bool is_in_chars ( char chars[], char a )
{
	int size = length( chars );

	for ( int i=0; i<size; i=i+1 )
		if ( chars[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_char_at ( char chars[], int iter )
{
	int size = length( chars );

	char remaining_chars[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_chars[ iter_remaining ] = chars[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( chars );

	for ( int i=0; i<iter_remaining; i=i+1 )
		chars[i] = remaining_chars[i];
}

// removes all chars-s  at iters[]  of char[]  chars  
void remove_chars_at ( char chars[], int iters[] )
{
	int size = length( chars );

	char chars_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				chars_removed[iter] = chars[i];
				iter = iter + 1;
			}

	empty( chars );

	for ( int i=0; i<iter; i=i+1 )
		chars[i] = chars_removed[i];
}

// removes all chars-s  of remove[]  of char[]  chars  
void remove_chars ( char chars[], char remove[] )
{
	int size = length( chars );

	char chars_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_chars( remove, chars[i] ) )
			{
				chars_removed[iter] = chars[i];
				iter = iter + 1;
			}

	empty( chars );

	for ( int i=0; i<iter; i=i+1 )
		chars[i] = chars_removed[i];
}

// removes all chars-s  a  of char[]  chars  
void remove_char ( char chars[], char a )
{
	int size = length( chars );
	char iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( chars[i] != a )
		{
			iters[ iter ] = chars[i];
			iter = iter + 1;
		}

	empty( chars );

	for ( int i=0; i<iter; i=i+1 )
		chars[i] = iters[i];
}


// removes chars with position ( >= a1 and <= a2 )  
void remove_chars_in_pos ( char chars[], int a1, int a2 )
{
	int size = length( chars );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	char remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( i >= a1 and i <= a2 ) )
		{
			remaining[ size_remaining ] = chars[i];
			size_remaining = size_remaining + 1;
		}

	empty( chars );

	for ( int i=0; i<size_remaining; i=i+1 )
		chars[i] = remaining[i];
}

// leave only chars with position ( >= a1 and <= a2 )  
void leave_chars_in_pos ( char chars[], int a1, int a2 )
{
	int size = length( chars );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	char remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i >= a1 and i <= a2 )
		{
			remaining[ size_remaining ] = chars[i];
			size_remaining = size_remaining + 1;
		}

	empty( chars );

	for ( int i=0; i<size_remaining; i=i+1 )
		chars[i] = remaining[i];
}

// removes chars ( >= a1 and <= a2 )  
void remove_chars_in ( char chars[], char a1, char a2 )
{
	int size = length( chars );

	char remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( chars[i] >= a1 and chars[i] <= a2 ) )
		{
			remaining[ size_remaining ] = chars[i];
			size_remaining = size_remaining + 1;
		}

	empty( chars );

	for ( int i=0; i<size_remaining; i=i+1 )
		chars[i] = remaining[i];
}

// leave only chars ( >= a1 and <= a2 )  
void leave_chars_in ( char chars[], char a1, char a2 )
{
	int size = length( chars );

	char remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( chars[i] >= a1 and chars[i] <= a2 )
		{
			remaining[ size_remaining ] = chars[i];
			size_remaining = size_remaining + 1;
		}

	empty( chars );

	for ( int i=0; i<size_remaining; i=i+1 )
		chars[i] = remaining[i];
}


// add  char  to  char[]  
void add_char ( char chars[], char a )
{
	int size = length( chars );

	chars[ size ] = a;
}

// add  char[]  to   char[]  
void add_chars ( char chars[], char add[] )
{
	int size_chars = length( chars );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		chars[ size_chars + i ] = add[i];
}

// add  char  to  char[]  at a certain position
void add_char ( char chars[], char a, int position )
{
	int size = length( chars );

	if ( position == size )
		add_char( chars, a );

	if ( position < 0 or position >= size )
		return;

	char result[1000];
	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
	{
		if ( position == i )
		{
			result[ counter ] = a;
			counter = counter + 1;
		}

		result[ counter ] = chars[i];
		counter = counter + 1;
	}

	size = size + 1;

	for ( int i=0; i<size; i=i+1 )
		chars[i] = result[i];
}

// add  char[]  to   char[]  at a certain position
void add_chars ( char chars[], char add[], int position )
{
	int size_chars = length( chars );
	int size_add = length(add);

	if ( position == size_chars )
		add_chars( chars, add );

	if ( position < 0 or position >= size_chars )
		return;

	char result[1000];
	int counter = 0;
	for ( int i=0; i<size_chars; i=i+1 )
	{
		if ( position == i )
			for ( int l=0; l<size_add; l=l+1 )
			{
				result[ counter ] = add[l];
				counter = counter + 1;
			}

		result[ counter ] = chars[i];
		counter = counter + 1;
	}

	size_chars = size_chars + size_add;

	for ( int i=0; i<size_chars; i=i+1 )
		chars[i] = result[i];
}



// string[]



string empty_string[10000] = {};

// empties a string[]
void empty ( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_string[i];
}

// is in string[]
bool is_in_strings ( string strings[], string a )
{
	int size = length( strings );

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] == a )
			return true;

	return false;
}

// removes val. at  iter  
void remove_string_at ( string strings[], int iter )
{
	int size = length( strings );

	string remaining_strings[1000];
	int iter_remaining = 0;


	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
		{
			remaining_strings[ iter_remaining ] = strings[i];
			iter_remaining = iter_remaining + 1;
		}

	empty( strings );

	for ( int i=0; i<iter_remaining; i=i+1 )
		strings[i] = remaining_strings[i];
}

// removes all strings-s  at iters[]  of string[]  strings  
void remove_strings_at ( string strings[], int iters[] )
{
	int size = length( strings );

	string strings_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			{
				strings_removed[iter] = strings[i];
				iter = iter + 1;
			}

	empty( strings );

	for ( int i=0; i<iter; i=i+1 )
		strings[i] = strings_removed[i];
}

// removes all strings-s  of remove[]  of string[]  strings  
void remove_strings ( string strings[], string remove[] )
{
	int size = length( strings );

	string strings_removed[1000];
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_strings( remove, strings[i] ) )
			{
				strings_removed[iter] = strings[i];
				iter = iter + 1;
			}

	empty( strings );

	for ( int i=0; i<iter; i=i+1 )
		strings[i] = strings_removed[i];
}

// removes all strings-s  a  of string[]  strings  
void remove_string ( string strings[], string a )
{
	int size = length( strings );
	string iters[1000];

	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] != a )
		{
			iters[ iter ] = strings[i];
			iter = iter + 1;
		}

	empty( strings );

	for ( int i=0; i<iter; i=i+1 )
		strings[i] = iters[i];
}

// removes strings with position ( >= a1 and <= a2 )  
void remove_strings_in_pos ( string strings[], int a1, int a2 )
{
	int size = length( strings );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	string remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( i >= a1 and i <= a2 ) )
		{
			remaining[ size_remaining ] = strings[i];
			size_remaining = size_remaining + 1;
		}

	empty( strings );

	for ( int i=0; i<size_remaining; i=i+1 )
		strings[i] = remaining[i];
}

// leave only strings with position ( >= a1 and <= a2 )
void leave_strings_in_pos ( string strings[], int a1, int a2 )
{
	int size = length( strings );

	if ( !( a1 >= 0 and a2 < size ) )
		return;

	string remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i >= a1 and i <= a2 )
		{
			remaining[ size_remaining ] = strings[i];
			size_remaining = size_remaining + 1;
		}

	empty( strings );

	for ( int i=0; i<size_remaining; i=i+1 )
		strings[i] = remaining[i];
}

// removes strings ( >= a1 and <= a2 )  
void remove_strings_in ( string strings[], string a1, string a2 )
{
	int size = length( strings );

	string remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !( strings[i] >= a1 and strings[i] <= a2 ) )
		{
			remaining[ size_remaining ] = strings[i];
			size_remaining = size_remaining + 1;
		}

	empty( strings );

	for ( int i=0; i<size_remaining; i=i+1 )
		strings[i] = remaining[i];
}

// leave only strings ( >= a1 and <= a2 )  
void leave_strings_in ( string strings[], string a1, string a2 )
{
	int size = length( strings );

	string remaining[1000];
	int size_remaining = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] >= a1 and strings[i] <= a2 )
		{
			remaining[ size_remaining ] = strings[i];
			size_remaining = size_remaining + 1;
		}

	empty( strings );

	for ( int i=0; i<size_remaining; i=i+1 )
		strings[i] = remaining[i];
}


// add  string  to  string[]  
void add_string ( string strings[], string a )
{
	int size = length( strings );

	strings[ size ] = a;
}

// add  string[]  to   string[]  
void add_strings ( string strings[], string add[] )
{
	int size_strings = length( strings );
	int size_add = length(add);

	for ( int i=0; i<size_add; i=i+1 )
		strings[ size_strings + i ] = add[i];
}

// add  string  to  string[]  at a certain position
void add_string ( string strings[], string a, int position )
{
	int size = length( strings );

	if ( position == size )
		add_string( strings, a );

	if ( position < 0 or position >= size )
		return;

	string result[1000];
	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
	{
		if ( position == i )
		{
			result[ counter ] = a;
			counter = counter + 1;
		}

		result[ counter ] = strings[i];
		counter = counter + 1;
	}

	size = size + 1;

	for ( int i=0; i<size; i=i+1 )
		strings[i] = result[i];
}

// add  string[]  to   string[]  at a certain position
void add_strings ( string strings[], string add[], int position )
{
	int size_strings = length( strings );
	int size_add = length(add);

	if ( position == size_strings )
		add_strings( strings, add );

	if ( position < 0 or position >= size_strings )
		return;

	string result[1000];
	int counter = 0;
	for ( int i=0; i<size_strings; i=i+1 )
	{
		if ( position == i )
			for ( int l=0; l<size_add; l=l+1 )
			{
				result[ counter ] = add[l];
				counter = counter + 1;
			}

		result[ counter ] = strings[i];
		counter = counter + 1;
	}

	size_strings = size_strings + size_add;

	for ( int i=0; i<size_strings; i=i+1 )
		strings[i] = result[i];
}



// char string



string empty_char_string = "";

// empties a string
void empty( string &a )
{
	a = empty_char_string;
}

// is in string
bool is_char_in_string ( string char_string, char a )
{
	int size = char_string.length();

	for ( int i=0; i<size; i=i+1 )
		if ( char_string[i] == a )
			return true;

	return false;
}

// removes char at  iter  of a string
string remove_char_string_at ( string &a, int iter )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
			result = result + a[i];

	a = result;

	return a;
}

// removes all chars at  iters[]    
string remove_chars_string_at ( string &a, int iters[] )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( !is_in_ints( iters, i ) )
			result = result + a[i];

	a = result;

	return a;
}

// removes all char-s  b  of  char remove[]    
string remove_chars_string ( string &a, char remove[] )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( !is_char_in_string( remove, a[i] ) )
			result = result + a[i];

	a = result;

	return a;
}

// removes all char-s  b  of string  a  
string remove_char_string ( string &a, char b )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != b )
			result = result + a[i];

	a = result;

	return a;
}

// removes chars with position ( >= a1 and <= a2 )  
string remove_chars_string_in_pos ( string &a, int a1, int a2 )
{
	int size = a.length();

	if ( !( a1 >= 0 and a2 < size ) )
		return a;

	string remaining = "";

	for ( int i=0; i<size; i=i+1 )
		if ( !( i >= a1 and i <= a2 ) )
			remaining = remaining + a[i];

	a = remaining;

	return a;
}

// leave only chars with position ( >= a1 and <= a2 )  
string leave_chars_string_in_pos ( string &a, int a1, int a2 )
{
	int size = a.length();

	if ( !( a1 >= 0 and a2 < size ) )
		return a;

	string remaining = "";

	for ( int i=0; i<size; i=i+1 )
		if ( i >= a1 and i <= a2 )
			remaining = remaining + a[i];

	a = remaining;

	return a;
}

// removes chars ( >= a1 and <= a2 )  
string remove_chars_string_in ( string &a, char a1, char a2 )
{
	int size = a.length();

	string remaining = "";

	for ( int i=0; i<size; i=i+1 )
		if ( !( a[i] >= a1 and a[i] <= a2 ) )
			remaining = remaining + a[i];

	a = remaining;

	return a;
}

// leave only chars ( >= a1 and <= a2 )  
string leave_chars_string_in ( string &a, char a1, char a2 )
{
	int size = a.length();

	string remaining = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 and a[i] <= a2 )
			remaining = remaining + a[i];

	a = remaining;

	return a;
}


// add  char  to  string  
string add_char_string ( string &a, char b )
{
	a = a + b;

	return a;
}

// add  char[]  to  string  
string add_chars_string ( string &a, char b[] )
{
	int size = length(b);

	for ( int i=0; i<size; i=i+1 )
		a = a + b[i];

	return a;
}

// add  char  to  string  at a certain position
string add_char_string ( string &a, char b, int position )
{
	int size = a.length();

	if ( position == size )
		add_char_string( a, b );

	if ( position < 0 or position >= size )
		return a;

	string result = "";
	for ( int i=0; i<size; i=i+1 )
	{
		if ( position == i )
			result = result + b;

		result = result + a[i];
	}

	a = result;

	return a;
}

// add  char[]  to  string  at a certain position
string add_chars_string ( string &a, char add[], int position )
{
	int size_string = a.length();
	int size_add = length(add);

	if ( position == size_string )
		add_chars_string( a, add );

	if ( position < 0 or position >= size_string )
		return a;

	string result = "";
	for ( int i=0; i<size_string; i=i+1 )
	{
		if ( position == i )
			for ( int l=0; l<size_add; l=l+1 )
				result = result + add[l];

		result = result + a[i];
	}

	a = result;

	return a;
}





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

