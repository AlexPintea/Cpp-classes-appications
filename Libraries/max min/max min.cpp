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



// maximum




int int_max ( int a, int b )
{
	if ( a > b )
		return a;

	return b;
}

long long_max ( long a, long b )
{
	if ( a > b )
		return a;

	return b;
}

float float_max ( float a, float b )
{
	if ( a > b )
		return a;

	return b;
}

double double_max ( double a, double b )
{
	if ( a > b )
		return a;

	return b;
}

bool bool_max ( bool a, bool b )
{
	if ( a > b )
		return a;

	return b;
}

char char_max ( char a, char b )
{
	if ( a > b )
		return a;

	return b;
}

string string_max ( string a, string b )
{
	if ( a > b )
		return a;

	return b;
}



// maximum[]



bool int_max ( int a[], int b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool long_max ( long a[], long b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool float_max ( float a[], float b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool double_max ( double a[], double b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool bool_max ( bool a[], bool b[] ) // does not return validly, due to  int length( bool a[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool char_max ( char a[], bool b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool string_max ( string a[], string b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}



// minimum




int int_min ( int a, int b )
{
	if ( a < b )
		return a;

	return b;
}

long long_min ( long a, long b )
{
	if ( a < b )
		return a;

	return b;
}

float float_min ( float a, float b )
{
	if ( a < b )
		return a;

	return b;
}

double double_min ( double a, double b )
{
	if ( a < b )
		return a;

	return b;
}

bool bool_min ( bool a, bool b )
{
	if ( a < b )
		return a;

	return b;
}

char char_min ( char a, char b )
{
	if ( a < b )
		return a;

	return b;
}

string string_min ( string a, string b )
{
	if ( a < b )
		return a;

	return b;
}



// minimum[]



bool int_min ( int a[], int b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool long_min ( long a[], long b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool float_min ( float a[], float b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool double_min ( double a[], double b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool bool_min ( bool a[], bool b[] ) // does not return validly, due to  int length( bool a[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool char_min ( char a[], bool b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool string_min ( string a[], string b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}


int main()
{

	return 0;
}

