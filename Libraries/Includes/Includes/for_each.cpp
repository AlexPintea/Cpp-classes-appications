// #include "lengths.cpp"


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


