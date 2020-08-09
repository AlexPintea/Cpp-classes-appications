#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


int length ( double a[] )
{
	int i = 0;

	while ( a[ i ] != 0 )
		i = i + 1;
	return i;
}

int length ( int a[] )
{
	int i = 0;

	while ( a[ i ] != 0 )
		i = i + 1;
	return i;
}

bool is_in ( int a[], int b )
{
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ] == b )
			return true;

	return false;
}

int in_ints ( int a[], int b )
{
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ] == b )
			return i;

	return -1;
}




void empty ( int a[] )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = 0;
}

void empty ( double a[] )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = 0;
}

bool even ( int a ) { if ( a % 2 == 0 ) return 1; return 0; }
bool odd ( int a ) { if ( a % 2 == 1 ) return 1; return 0; }
bool pos ( int a ) { if ( a >= 0 ) return 1; return 0; }
bool neg ( int a ) { if ( a < 0 ) return 1; return 0; }

double doubles[ 10000 ];
int double_iter = 0;


int order ( int a[] )
{
	int size = length( a );

	for ( int i = 0; i < size - 1; i = i + 1 )	
		for ( int l = i + 1; l < size; l = l + 1 )
		{
			if ( a[ l ] < a[ i ] )
			{
				double b = a[ l ];
				a[ l ] = a[ i ];
				a[ i ] = b;
			}
		}

}

// prime divisors of a num.
void prime_divisors ( int a, int d[] )
{
	int i = 0;
	int dv = 2;

	while ( a != 1 )
	{
		while ( a % dv == 0 )
		{
			d[ i ] = dv;
			a = a / dv;
			i = i + 1;
		}

		dv = dv + 1;
	}
}

// all divisirs of a num
int divisors ( int a, int d[] )
{
	int dv = 2;
	int b = a;


	d[ 0 ] = 1;
	int i = 1;

	while ( a != 1 )
	{
		int p = 0;
		while ( a % dv == 0 )
		{
			p = p + 1;
			int prd = 1;
			for ( int l = 0; l < p; l = l + 1 )
				prd = prd * dv;

			if ( ! is_in( d, prd ) )
			{
				d[ i ] = prd;
				i = i + 1;
			}

			a = a / dv;
			if ( ! is_in( d, a ) )
			{
				d[ i ] = a;
				i = i + 1;
			}
		}

		dv = dv + 1;
	}

	if ( ! is_in( d, b ) )
	{
		d[ i ] = b;
		d[ i + 1 ] = 0;
	}
	else
		d[ i ] = 0;

	order( d );
}

// least common divisor
int lc ( int a, int b )
{
	while ( a != 0 and b != 0 )
	{
		if ( a > b )
			a = a % b;
		else
			b = b % a;
	}

	if ( a == 0 )
		return b;
	else
		return a;
}

void remove_num ( int a[], int i )
{
	int b[ 10000 ];
	int b_num = 0;
	for ( int l = 0; l < length( a ); l = l + 1 )
		if ( l != i )
		{
			b[ b_num ] = a[ l ];
			b_num = b_num + 1;
		}

	for ( int l = 0; l < b_num; l = l + 1 )
		a[ l ] = b[ l ];

	a[ b_num ] = 0;
}


int lc ( int a[] )
{
	int size = length( a );
	int b[ 10000 ];
	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = a[ l ];

	while ( length( b ) != 1 )
	{
		b[ 0 ] = lc( b[ 0 ], b[ 1 ] );
		remove_num( b, 1 );
	}

	return b[ 0 ];
}

void get_frev ( int a[], int nums[], int frev[] )
{
	int size = length( a );
	int nums_iter = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		int l = in_ints( nums, a[ i ] );
		if ( l != -1 )
			frev[ l ] = frev[ l ] + 1;
		else
		{
			nums[ nums_iter ] = a[ i ];
			frev[ nums_iter ] = 1;
			nums_iter = nums_iter + 1;
		}
	}
}

int gc ( int a[] )
{
	// invalid

	int dv[ 10000 ];
	int frev[ 10000 ];
	int dv_iter = 0;

	int prime_dv_temp[ 10000 ];
	int dv_temp[ 10000 ];
	int frev_temp[ 10000 ];

	for ( int i = 0; i < length( a ); i = i + 1 )
	{
		prime_divisors( a[ i ], prime_dv_temp );
		get_frev( prime_dv_temp, dv_temp, frev_temp );

		for ( int l = 0; l < length( dv_temp ); l = l + 1 )
		{
			int d = in_ints( dv, dv_temp[ l ] );
			if ( d != -1 )
			{
				if ( frev_temp[ l ] > frev[ d ] )
					frev[ d ] = frev_temp[ l ];
			}
			else
			{
				dv[ dv_iter ] = dv_temp[ l ];
				frev[ dv_iter ] = frev_temp[ l ];
				dv_iter = dv_iter + 1;
			}
		}
	}

	cout << dv_iter << '\n';

	int p = 1;
	int p_temp;
	for ( int i = 0; i < dv_iter; i = i + 1 )
	{
		p_temp = p;
		for ( int l = 0; l < frev[ i ]; l = l + 1 )
			p = p + p_temp;
	}

	return p;
}

double amean ( double a[] )
{
	int size = length( a );
	if ( size == 0 )
		return 0;
	double s = 0;

	for ( int i = 0; i < size; i = i + 1 )
		s = s + a[ i ];

	return s / size;
}



int main ()
{
	cout << "0 means done:\n";

	double a = 10;

	while ( a != 0 )
	{
		cin >> a;
		if ( a == 0 )
			break;
		doubles[ double_iter ] = a;
		double_iter = double_iter + 1;
	}
	if ( double_iter != 0 )
		cout << "\nFor: ";

	for ( int i = 0; i < double_iter; i = i + 1 )
	{
		cout << doubles[ i ];
		if ( i != double_iter - 1 ) cout << ", ";
	}
	
	cout << '\n';
	int d[ 10000 ];
	int longs = 1;
	for ( int i = 0; i < double_iter; i = i + 1 )
	{
		cout << '\n';
		empty( d );
		cout << '\'' << doubles[ i ] << "\' is: ";
		if ( doubles[ i ] == (long) doubles[ i ] )
		{
			if ( pos( doubles[ i ] ) ) cout << "pos, ";
			else  cout << "neg, ";

			if ( even( doubles[ i ] ) ) cout << "even, ";
			else  cout << "odd, ";

			divisors( (int) doubles[ i ], d );
			cout << "divisors: ( ";
			for ( int l = 0; l < length( d ); l = l + 1 )
				cout << d[ l ] << ' ';
			cout << "), ";

			if ( length( d ) == 2 )
				cout << "prime, ";
			empty( d );

			prime_divisors( (int) doubles[ i ], d );
			cout << "prime divisors: ( ";
			for ( int l = 0; l < length( d ); l = l + 1 )
				cout << d[ l ] << ' ';
			cout << ')';		
		}
		else
			longs = 0;

		cout << '\n';
	}




	if ( double_iter > 1 )
	{
		cout << "\nAverage: " << amean( doubles ) << '\n';
		if ( longs )
		{
		// int a[] = { 10, 5, 25, 95, 15 };
		// cout << "\nlc: " << lc( a ) << '\n';
		// cout << "\ngc: " << gc( a ) << '\n';
		}
	}
	cout << '\n';
	return 0;
}
