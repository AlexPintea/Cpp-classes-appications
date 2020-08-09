// #include "lengths.cpp"
// #include "empty.cpp"




// int[]






// is in int[]
bool is_in_ints ( int ints[], int a )
{
	int size = length( ints );

	for ( int i=0; i<size; i=i+1 )
		if ( ints[i] == a )
			return true;

	return false;
}


// count of  a  in  int[]  
int frev_int ( int ints[], int a )
{
	int size = length( ints );

	int count = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( ints[i] == a )
			count = count + 1;

	return count;
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

// add  a  to  ints[]  at position 0 
void add_int_0 ( int ints[], int a ) { add_int( ints, a, 0 ); }

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

// add  a[]  to  ints[]  at position 0 
void add_ints_0 ( int ints[], int a[] ) { add_ints( ints, a, 0 ); }

// long[]



// is in long[]
bool is_in_longs ( long longs[], long a )
{
	int size = length( longs );

	for ( int i=0; i<size; i=i+1 )
		if ( longs[i] == a )
			return true;

	return false;
}

// count of  a  in  long[]  
int frev_long ( long longs[], long a )
{
	int size = length( longs );

	int count = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( longs[i] == a )
			count = count + 1;

	return count;
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

// add  a  to  longs[]  at position 0 
void add_long_0 ( long longs[], long a ) { add_long( longs, a, 0 ); }

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

// add  a[]  to  longs[]  at position 0 
void add_longs_0 ( long longs[], long a[] ) { add_longs( longs, a, 0 ); }


// double[]




// is in double[]
bool is_in_doubles ( double doubles[], double a )
{
	int size = length( doubles );

	for ( int i=0; i<size; i=i+1 )
		if ( doubles[i] == a )
			return true;

	return false;
}

// count of  a  in  double[]  
int frev_double ( double doubles[], double a )
{
	int size = length( doubles );

	int count = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( doubles[i] == a )
			count = count + 1;

	return count;
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

// add  a  to  doubles[]  at position 0 
void add_double_0 ( double doubles[], double a ) { add_double( doubles, a, 0 ); }

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

// add  a[]  to  doubles[]  at position 0 
void add_doubles_0 ( double doubles[], double a[] ) { add_doubles( doubles, a, 0 ); }




// float[]




// is in float[]
bool is_in_floats ( float floats[], float a )
{
	int size = length( floats );

	for ( int i=0; i<size; i=i+1 )
		if ( floats[i] == a )
			return true;

	return false;
}
// count of  a  in  float[]  
int frev_float ( float floats[], float a )
{
	int size = length( floats );

	int count = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( floats[i] == a )
			count = count + 1;

	return count;
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

// add  a  to  floats[]  at position 0 
void add_float_0 ( float floats[], float a ) { add_float( floats, a, 0 ); }

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



// add  a[]  to  floats[]  at position 0 
void add_floats_0 ( float floats[], float a[] ) { add_floats( floats, a, 0 ); }




// char[]




// is in char[]
bool is_in_chars ( char chars[], char a )
{
	int size = length( chars );

	for ( int i=0; i<size; i=i+1 )
		if ( chars[i] == a )
			return true;

	return false;
}

// count of  a  in  char[]  
int frev_char ( char chars[], char a )
{
	int size = length( chars );

	int count = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( chars[i] == a )
			count = count + 1;

	return count;
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


// add  a  to  chars[]  at position 0 
void add_char_0 ( char chars[], char a ) { add_char( chars, a, 0 ); }


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

// add  a[]  to  chars[]  at position 0 
void add_chars_0 ( char chars[], char a[] ) { add_chars( chars, a, 0 ); }




// string[]




// is in string[]
bool is_in_strings ( string strings[], string a )
{
	int size = length( strings );

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] == a )
			return true;

	return false;
}

// count of  a  in  string[]  
int frev_string ( string strings[], string a )
{
	int size = length( strings );

	int count = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] == a )
			count = count + 1;

	return count;
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

// add  a  to  strings[]  at position 0 
void add_string_0 ( string strings[], string a ) { add_string( strings, a, 0 ); }


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

// add  a[]  to  strings[]  at position 0 
void add_strings_0 ( string strings[], string a[] ) { add_strings( strings, a, 0 ); }



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
