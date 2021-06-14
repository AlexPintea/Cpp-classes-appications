#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


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


int main ()
{
	return 0;
}
