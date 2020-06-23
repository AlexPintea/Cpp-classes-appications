#include <string>
#include <string.h>
#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int length ( int a[] )
{
	int i = 0;

	while ( a[ i ] )
		i = i + 1;

	return i;
}

int length ( double a[] )
{
	int i = 0;

	while ( a[ i ] )
		i = i + 1;

	return i;
}

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
int order ( double a[] )
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

bool is_in ( int a[], int b )
{
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ] == b )
			return true;

	return false;
}

void invert ( int a[] )
{
	
	int size = length( a );
	int b[ size + 1 ];

	for ( int i = 0; i < size; i = i + 1 )
		b[ size - i - 1 ] = a[ i ];

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];
}






// check for even, odd, positive and negative
bool even ( int a ){ if ( a % 2 == 0 ) return true; return false; }
bool odd ( int a ) { if ( a % 2 == 1 ) return true; return false; }
bool pos ( double a ) { if ( a >= 0 ) return true; return false; }
bool neg ( double a ) { if ( a < 0 ) return true; return false; }



// leaves even or odd num-s in an []
void leave_even_odd ( int a[], bool is_even )
{
	int size = length( a );

	int b[ 1000 ];
	int l = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( is_even )
		{
			if ( even( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
		}
		else
			if ( odd( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
	}

	size = l;

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];

	a[ size ] = 0;
}
// leave / remove  even / odd
void leave_even ( int a[] ) { leave_even_odd( a, 1 ); }
void leave_odd ( int a[] ) { leave_even_odd( a, 0 ); }
void remove_odd ( int a[] ) { leave_even_odd( a, 1 ); }
void remove_even ( int a[] ) { leave_even_odd( a, 0 ); }


// count even / odd
int count_even_odd ( int a[], bool is_even )
{
	int size = length( a );

	int count = 0;

	if ( is_even )
	{
		for ( int i = 0; i < size; i = i + 1 )
			if ( even( a[ i ] ) )
				count = count + 1;
	}
	else
	{
		for ( int i = 0; i < size; i = i + 1 )
			if ( odd( a[ i ] ) )
				count = count + 1;
	}

	return count;
}
int count_even( int a[] ) { return count_even_odd( a, 1 ); }
int count_odd( int a[] ) { return count_even_odd( a, 0 ); }


// leaves even or odd num-s in a num.
int leave_even_odd ( int &a, bool is_even )
{
	int digits[ 90 ];
	int i = 0;

	if ( is_even )
		while ( a != 0 )
		{
			if ( ( a % 10 ) % 2 == 1 )
			{
				a = a / 10;
				continue;
			}

			digits[ i ] = a % 10;
			i = i + 1;

			a = a / 10;
		}
	else
		while ( a != 0 )
		{
			if ( ( a % 10 ) % 2 == 0 )
			{
				a = a / 10;
				continue;
			}

			digits[ i ] = a % 10;
			i = i + 1;

			a = a / 10;
		}
	
	invert( digits );

	int size = i;

	int b = 0;
	for ( int i = 0; i < size; i = i + 1 )
		b = b * 10 + digits[ i ];

	a = b;

	return a;
}
// leave / remove  even / odd
void leave_even ( int a ) { leave_even_odd( a, 1 ); }
void leave_odd ( int a ) { leave_even_odd( a, 0 ); }
void remove_odd ( int a ) { leave_even_odd( a, 1 ); }
void remove_even ( int a ) { leave_even_odd( a, 0 ); }


// count even / odd
int count_even_odd ( int a, bool is_even )
{
	int digits[ 90 ];
	int i = 0;
	while ( a != 0 )
	{
		digits[ i ] = a % 10;
		i = i + 1;
		
		a = a / 10;
	}
	digits[ i ]	= 0;

	return count_even_odd( digits, is_even );
}
int count_even( int a ) { return count_even_odd( a, 1 ); }
int count_odd( int a ) { return count_even_odd( a, 0 ); }



// leaves pos or neg num-s in an []
void leave_pos_neg ( double a[], bool is_pos )
{
	int size = length( a );

	double b[ 1000 ];
	int l = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( is_pos )
		{
			if ( pos( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
		}
		else
			if ( neg( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
	}

	size = l;

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];

	a[ size ] = 0;
}
// leave / remove  pos / neg
void leave_pos ( double a[] ) { leave_pos_neg( a, 1 ); }
void leave_neg ( double a[] ) { leave_pos_neg( a, 0 ); }
void remove_neg ( double a[] ) { leave_pos_neg( a, 1 ); }
void remove_pos ( double a[] ) { leave_pos_neg( a, 0 ); }

// leaves pos or neg num-s in an []
void leave_pos_neg ( int a[], bool is_pos )
{
	int size = length( a );

	int b[ 1000 ];
	int l = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( is_pos )
		{
			if ( pos( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
		}
		else
			if ( neg( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
	}

	size = l;

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];

	a[ size ] = 0;
}
// leave / remove  pos / neg
void leave_pos ( int a[] ) { leave_pos_neg( a, 1 ); }
void leave_neg ( int a[] ) { leave_pos_neg( a, 0 ); }
void remove_neg ( int a[] ) { leave_pos_neg( a, 1 ); }
void remove_pos ( int a[] ) { leave_pos_neg( a, 0 ); }

// count pos / neg
int count_pos_neg ( int a[], bool is_pos )
{
	int size = length( a );

	int count = 0;

	if ( is_pos )
	{
		for ( int i = 0; i < size; i = i + 1 )
			if ( pos( a[ i ] ) )
				count = count + 1;
	}
	else
	{
		for ( int i = 0; i < size; i = i + 1 )
			if ( neg( a[ i ] ) )
				count = count + 1;
	}

	return count;
}
int count_pos( int a[] ) { return count_pos_neg( a, 1 ); }
int count_neg( int a[] ) { return count_pos_neg( a, 0 ); }






// check if an num. is prime
bool prime ( int a )
{
	if ( a == 0 or a == 1 )
		return false;

	if ( a == 2 )
		return true;

	if ( even( a ) )
		return false;

	for ( int d = 3; d * d < a; d = d + 2 )
		if ( a % d == 0 )
			return false;

	return true;			
}


// leave / remove  prime
void leave_remove_prime ( int a[], bool is_prime )
{
	int size = length( a );

	int b[ 1000 ];
	int l = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( is_prime )
		{
			if ( prime( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
		}
		else
			if ( prime( a[ i ] ) )
			{
				b[ l ] = a[ i ];
				l = l + 1;
			}
	}


	size = l;

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];

	a[ size ] = 0;	
}
void leave_prime ( int a[] ){ leave_remove_prime( a, 1 ); }
void remove_prime ( int a[] ){ leave_remove_prime( a, 0 ); }

// count prime
int count_prime ( int a[] )
{
	int size = length( a );

	int count = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( prime( a[ i ] ) )
			count = count + 1;

	return count;
}
int count_without_prime( int a[] ) { return length( a ) - count_prime( a ); }




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
// greatest common multiple
int gc ( int a, int b ) { return a * b / lc( a, b ); }


// check if a num. is a "perf. square"
bool sq ( int a )
{
	int square = (int) sqrt( a );

	if ( square * square == a )
		return true;

	return false;
}



// returns 1st / last digit of a num.
int fd ( int a ) { while ( a > 9 ) a = a / 10; return a; }
int ld ( int a ) { return a % 10; }



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




// Perm / Arn / Comb
int perm ( int a )
{
	int p = 1;
	for ( int i = 1; i <= a; i = i + 1 )
		p = p * i;

	return p;
}
int arn ( int n, int k ) 
{
	int p = 1;
	for ( int i = n - k + 1; i <= n; i = i + 1 )
		p = p * i;

	return p;
}
int comb ( int n, int k ) { return arn( n, k ) / perm( k ); }





// Traingle
bool triangle ( double a1, double a2, double a3 )
{
	if ( a1 + a2 > a3 and a3 + a1 > a2 and a3 + a2 > a1 )
		return true;

	return false;
}


bool pitagora ( double a1, double a2, double a3 )
{
	if ( ! triangle( a1, a2, a3 ) )
		return false;

	double a[ 5 ] = { a1, a2, a3 };
	order( a );

	if ( a[0]*a[0] + a[1]*a[1] == a[2]*a[2] )
		return true;
	
	return false;
}



// Means
double gmean ( int a , int b )
{
	return sqrt( a * b );
}

double amean ( double a[] )
{
	int size = length( a );

	double s = 0;

	for ( int i = 0; i < size; i = i + 1 )
		s = s + a[ i ];

	return s / size;
}

double amean ( int a[] )
{
	int size = length( a );

	double s = 0;

	for ( int i = 0; i < size; i = i + 1 )
		s = s + a[ i ];

	return s / size;
}




int main()
{
	


	// Even / Odd / Pos / Neg, Digits




	int a = 21;
	cout << "Even: " << even( a ) << ' ';
	cout << "Odd: " << odd( a ) << "\n";

	cout << "Pos: " << pos( a ) << ' ';
	cout << "Neg: " << neg( a ) << "\n";

	int evens[ 14 ] = { 1, 2, 3, 4, 5, 6, 7, 9 };
	cout << "Count Even: " << count_even( evens ) << "\n";

	cout << "Leave Even: ";
	leave_even ( evens );
	for ( int i = 0; i < length( evens ); i = i + 1 )
		cout << evens[ i ] << ' ';
	cout << "\n";


	int positives[ 14 ] = { -1, -2, 3, -4, 5, -6, 7, 9 };
	cout << "Count Pos: " << count_pos( positives ) << "\n";

	cout << "Leave Pos: ";
	leave_pos ( positives );
	for ( int i = 0; i < length( positives ); i = i + 1 )
		cout << positives[ i ] << ' ';
	cout << "\n\n";

	cout << "Digits: " << fd( 142 ) << ' ' << ld( 94 ) << "\n";




	// Prime



	
	cout << "Prime: ";
	cout << prime( a ) << "\n";

	int primes[ 14 ] = { 1, 2, 3, 4, 5, 6, 7, 9 };
	cout << "Count Prime: " << count_prime( primes ) << "\n";

	cout << "Leave Prime: ";
	leave_prime ( primes );
	for ( int i = 0; i < length( primes ); i = i + 1 )
		cout << primes[ i ] << ' ';
	cout << "\n\n";




	// Divisors




	cout << "Prime Divisors: ";
	int pd[ 90 ];
	prime_divisors( 96, pd );
	for ( int i = 0; i < length( pd ); i = i + 1 )
		cout << pd[ i ] << ' ';
	cout << "\n";

	cout << "Divisors: ";
	int d[ 90 ];
	divisors( 24, d );
	for ( int i = 0; i < length( d ); i = i + 1 )
		cout << d[ i ] << ' ';
	cout << "\n";

	cout << "Least common Divisor: ";
	cout << lc ( 64, 92 ) << ' ';
	cout << "Greatest common Multiple: ";
	cout << gc ( 32, 16 ) << "\n\n";




	// Square




	cout << "Is Square: ";
	cout << sq( 49 ) << "\n\n";




	// Perm / Arm / Comb




	cout << "Perm: ";
	cout << perm( 4 ) << ' ';
	cout << "Arn: ";
	cout << arn( 10, 2 ) << ' ';
	cout << "Comb: ";
	cout << comb( 10, 2 ) << "\n\n";




	// Triangle




	cout << "Triangle: " << triangle( 2, 5, 4 ) << " ";
	cout << "Pitagora: " << pitagora( 0.3, 0.4, 0.5 ) << "\n\n";




	// Means




	cout << "Gmean: " << gmean( 10, 9 ) << ' ';	
	cout << "Amean: " << amean( evens ) << "\n\n";	

	return 0;
}
