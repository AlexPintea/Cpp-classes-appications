// #include "lengths.cpp"


int empty_int[10000] = {};

// empties an int[]
void empty ( int a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_int[i];
}


long empty_long[10000] = {};

// empties a long[]
void empty ( long a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_long[i];
}


double empty_double[10000] = {};

// empties a double[]
void empty ( double a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_double[i];
}


float empty_float[10000] = {};

// empties a float[]
void empty ( float a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_float[i];
}


char empty_char[10000] = {};

// empties a char[]
void empty ( char a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_char[i];
}


string empty_string[10000] = {};

// empties a string[]
void empty ( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = empty_string[i];
}


