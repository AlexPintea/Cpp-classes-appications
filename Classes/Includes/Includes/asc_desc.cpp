// #include "lengths.cpp"



bool is_asc ( long a )
{
	int digit_1 = 10;
	int digit_2 = 10;

	while ( a != 0 )
	{
		digit_2 = digit_1;
		digit_1 = a % 10;
		a = a / 10;

		if ( digit_2 < digit_1 )
			return false;
	}

	return true;
}

bool is_desc ( long a )
{
	int digit_1 = -1;
	int digit_2 = -1;

	while ( a != 0 )
	{
		digit_2 = digit_1;
		digit_1 = a % 10;
		a = a / 10;

		if ( digit_2 > digit_1 )
			return false;
	}

	return true;
}


bool is_asc ( int a )
{
	return is_asc( (long) a );
}

bool is_desc ( int a )
{
	return is_desc( (long) a );
}




bool is_asc ( string a )
{
	int size = a.length();

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] < a[i-1] )
			return false;

	return true;
}

bool is_desc ( string a )
{
	int size = a.length();

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] > a[i-1] )
			return false;

	return true;
}









bool is_asc ( long a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] < a[i-1] )
			return false;

	return true;
}

bool is_desc ( long a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] > a[i-1] )
			return false;

	return true;
}


bool is_asc ( int a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] < a[i-1] )
			return false;

	return true;
}

bool is_desc ( int a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] > a[i-1] )
			return false;

	return true;
}


bool is_asc ( float a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] > a[i-1] )
			return false;

	return true;
}

bool is_desc ( float a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] < a[i-1] )
			return false;

	return true;
}


bool is_asc ( double a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] > a[i-1] )
			return false;

	return true;
}

bool is_desc ( double a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] < a[i-1] )
			return false;

	return true;
}


bool is_asc ( char a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] > a[i-1] )
			return false;

	return true;
}

bool is_desc ( char a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] < a[i-1] )
			return false;

	return true;
}


bool is_asc ( string a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] > a[i-1] )
			return false;

	return true;
}

bool is_desc ( string a[] )
{
	int size = length( a );

	for ( int i=1; i<size; i=i+1 )
		if ( a[i] < a[i-1] )
			return false;

	return true;
}
