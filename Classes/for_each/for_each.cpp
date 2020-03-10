#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

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



// verify for int
void half ( int &a )
{
	a = a / 2;
}




void for_each ( int a[], void (*f)(int&) )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		f( a[i] );
}

void for_each ( long a[], void (*f)(long&) )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		f( a[i] );
}

void for_each ( double a[], void (*f)(double&) )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		f( a[i] );
}

void for_each ( float a[], void (*f)(float&) )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		f( a[i] );
}

void for_each ( char a[], void (*f)(char&) )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		f( a[i] );
}

void for_each ( string a[], void (*f)(string&) )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		f( a[i] );
}


int main ()
{

	int a_ints[10] = { 2, 4, 6, 8 };

	for_each ( a_ints, half );

	for ( int i=0; i<length(a_ints); i=i+1 )
		cout << "\'" << a_ints[i] << "\'";
	cout << "\n";

	return 0;
}
