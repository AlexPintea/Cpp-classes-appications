#include <string.h>
#include <stdio.h>
#include <math.h>

int length_double ( double a[] )
{
	int i = 0;

	while ( a[ i ] )
		i = i + 1;

	return i;
}

int order_double ( double a[] )
{
	int size = length_double( a );

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
int length_int ( int a[] )
{
	int i = 0;

	while ( a[ i ] )
		i = i + 1;

	return i;
}

int order_int ( int a[] )
{
	int size = length_int( a );

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

int is_in ( int a[], int b )
{
	for ( int i = 0; i < length_int( a ); i = i + 1 )
		if ( a[ i ] == b )
			return 1;

	return 0;
}
void invert ( int a[] )
{
	
	int size = length_int( a );
	int b[ size + 1 ];

	for ( int i = 0; i < size; i = i + 1 )
		b[ size - i - 1 ] = a[ i ];

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];
}
void int_to_double ( int a[], double b[] )
{
	int l;
	for ( l = 0; l < length_int( a ); l = l + 1 )
		b[ l ] = (double) a[ l ];
	b[ l ] = 0;
}
void double_to_int ( double a[], int b[] )
{
	int l;
	for ( l = 0; l < length_double( a ); l = l + 1 )
		b[ l ] = (int) a[ l ];
	b[ l ] = 0;
}





// check for even, odd, positive && negative
int even ( int a ){ if ( a % 2 == 0 ) return 1; return 0; }
int odd ( int a ) { if ( a % 2 == 1 ) return 1; return 0; }
int pos ( double a ) { if ( a >= 0 ) return 1; return 0; }
int neg ( double a ) { if ( a < 0 ) return 1; return 0; }



// leaves even or odd num-s in an []
void leave_even_odd ( int a[], int is_even )
{
	int size = length_int( a );

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
int count_even_odd ( int a[], int is_even )
{
	int size = length_int( a );

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
int leave_digits_even_odd ( int a, int is_even )
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
void leave_digits_even ( int a ) { leave_digits_even_odd( a, 1 ); }
void leave_digits_odd ( int a ) { leave_digits_even_odd( a, 0 ); }
void remove_digits_odd ( int a ) { leave_digits_even_odd( a, 1 ); }
void remove_digits_even ( int a ) { leave_digits_even_odd( a, 0 ); }




// count even / odd
int count_digits_even_odd ( int a, int is_even )
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
int count_digits_even( int a ) { return count_digits_even_odd( a, 1 ); }
int count_digits_odd( int a ) { return count_digits_even_odd( a, 0 ); }



// leaves pos or neg num-s in an []
void leave_pos_neg ( double a[], int is_pos )
{
	int size = length_double( a );

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



// count pos / neg
int count_pos_neg ( double a[], double is_pos )
{
	int size = length_double( a );

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
int count_pos( double a[] ) { return count_pos_neg( a, 1 ); }
int count_neg( double a[] ) { return count_pos_neg( a, 0 ); }






// check if an num. is prime
int prime ( int a )
{
	if ( a == 0 ) return 0;
	if ( a == 1 ) return 0;

	if ( a == 2 )
		return 1;

	if ( even( a ) )
		return 0;

	for ( int d = 3; d * d < a; d = d + 2 )
		if ( a % d == 0 )
			return 0;

	return 1;			
}


// leave / remove  prime
void leave_remove_prime ( int a[], int is_prime )
{
	int size = length_int( a );

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
	int size = length_int( a );

	int count = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( prime( a[ i ] ) )
			count = count + 1;

	return count;
}
int count_without_prime( int a[] ) { return length_int( a ) - count_prime( a ); }




// least common divisor
int lc ( int a, int b )
{
	while ( a != 0 && b != 0 )
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

	order_int( d );
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








double amean ( double a[] )
{
	int size = length_double( a );

	double s = 0;

	for ( int i = 0; i < size; i = i + 1 )
		s = s + a[ i ];

	return s / size;
}


// Det
double det_2 ( double a[2][2] ) { return a[0][0]*a[1][1] - a[0][1]*a[1][0]; }

// 00 01 02
// 10 11 12
// 20 21 22

double det_3 ( double a[3][3] )
{
	double m1 = a[0][0]*a[1][1]*a[2][2] + a[0][2]*a[1][0]*a[2][1] + a[0][1]*a[1][2]*a[2][0];
	double m2 = a[0][2]*a[1][1]*a[2][0] + a[0][0]*a[1][2]*a[2][1] + a[1][0]*a[2][2]*a[0][1];

	return m1 - m2;
}



// Base
int base2 ( int a )
{
	int reminders[ 1000 ] = {};
	
	int count = 0;

	while ( a > 1 )
	{
		reminders[ count ] = a % 2;
		count = count + 1;

		a = a / 2;
	}

	reminders[ count ] = a;
	count = count + 1;


	int result = 0;
	for ( int i = count - 1; i >= 0; i = i - 1 )
		result = result * 10 + reminders[ i ];
	
	return result;
}


void base16 ( int a, char base_16[] )
{
	int reminders[ 1000 ] = {};
	
	int count = 0;

	while ( a > 15 )
	{
		reminders[ count ] = a % 16;
		count = count + 1;

		a = a / 16;
	}

	reminders[ count ] = a;
	count = count + 1;

	
	char base16_chars[ 21 ] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };

	base_16[ count ] = 0;
	for ( int i = count - 1; i >= 0; i = i - 1 )
		base_16[ i ] = base16_chars[ reminders[ i ] ];
}



// Traingle
int triangle ( double a1, double a2, double a3 )
{
	if ( a1 + a2 > a3 && a3 + a1 > a2 && a3 + a2 > a1 )
		return 1;

	return 0;
}

int pitagora ( double a1, double a2, double a3 )
{
	if ( ! triangle( a1, a2, a3 ) )
		return 0;

	double a[ 5 ] = { a1, a2, a3 };

	if ( a[0]*a[0] + a[1]*a[1] == a[2]*a[2] )
		return 1;
	
	if ( a[1]*a[1] + a[2]*a[2] == a[0]*a[0] )
		return 1;
	
	if ( a[2]*a[2] + a[0]*a[0] == a[1]*a[1] )
		return 1;
	
	return 0;
}

int isoscel ( double a1, double a2, double a3 )
{
	if ( ! triangle( a1, a2, a3 ) )
		return 0;

	if ( a1 == a2 ) 
		return 1;

	if( a3 == a1 ) 
		return 1;

	if ( a2 == a3 )
		return 1;

	return 0;
}

int echilateral ( double a1, double a2, double a3 )
{
	if ( ! triangle( a1, a2, a3 ) )
		return 0;

	if ( a1 == a2 && a2 == a3 )
		return 1;

	return 0;	
}




int main()
{
	printf( "%s", "mhmcs\n\nsqrt, amean && dets invalid.\n\n" );
	// sqrt, amean && dets invalid





	// Even / Odd / Pos / Neg, Digits




	int a = 21;
	printf( "%s%d%s", "Even: ", even( a ), " " );
	printf( "%s%d%s", "Odd: ", odd( a ), "\n" );

	printf( "%s%d%s", "Pos: ", pos( a ), " " );
	printf( "%s%d%s", "Neg: ", neg( a ), "\n" );

	int evens[ 14 ] = { 1, 2, 3, 4, 5, 6, 7, 9 };
	printf( "%s%d%s", "Count Even: ", count_even( evens ), "\n" );

	printf( "%s", "Leave Even: " );
	leave_even ( evens );
	for ( int i = 0; i < length_int( evens ); i = i + 1 )
		printf( "%d%s", evens[ i ], " " );
	printf( "%s", "\n" );




	int positives[ 14 ] = { -1, -2, 3, -4, 5, -6, 7, 9 };
	double positives_double[14];
	int_to_double( positives, positives_double );
	printf( "%s%d%s", "Count Pos: ", count_pos( positives_double ), "\n" ); // only for double

	printf( "%s", "Leave Pos: " );
	leave_pos ( positives_double );
	double_to_int( positives_double, positives );
	for ( int i = 0; i < length_int( positives ); i = i + 1 ) // only for int
		printf( "%d%s", positives[ i ], " " );
	printf( "%s", "\n\n" );

	printf( "%s%d%s%d%s", "Digits: ", fd( 142 ), " ", ld( 94 ), "\n" );




	// Prime



	
	printf( "%s", "Prime: " );
	printf( "%d%s", prime( a ), "\n" );

	int primes[ 14 ] = { 1, 2, 3, 4, 5, 6, 7, 9 };
	printf( "%s%d%s", "Count Prime: ", count_prime( primes ), "\n" );

	printf( "%s", "Leave Prime: " );
	leave_prime ( primes );
	for ( int i = 0; i < length_int( primes ); i = i + 1 )
		printf( "%d%s", primes[ i ], " " );
	printf( "%s", "\n\n" );




	// Divisors




	printf( "%s", "Prime Divisors: " );
	int pd[ 90 ];
	prime_divisors( 96, pd );
	for ( int i = 0; i < length_int( pd ); i = i + 1 )
		printf( "%d%s", pd[ i ], " " );
	printf( "%s", "\n" );

	printf( "%s", "Divisors: " );
	int d[ 90 ];
	divisors( 24, d );
	for ( int i = 0; i < length_int( d ); i = i + 1 )
		printf( "%d%s", d[ i ], " " );
	printf( "%s", "\n" );

	printf( "%s", "Least common Divisor: " );
	printf( "%d%s", lc ( 64, 92 ), " " );
	printf( "%s", "Greatest common Multiple: " );
	printf( "%d%s", gc ( 32, 16 ), "\n\n" );




	// Perm / Arm / Comb




	printf( "%s", "Perm: " );
	printf( "%d%s", perm( 4 ), " " );
	printf( "%s", "Arn: " );
	printf( "%d%s", arn( 10, 2 ), " " );
	printf( "%s", "Comb: " );
	printf( "%d%s", comb( 10, 2 ), "\n\n" );




	// Means



//	double evens_double[ 14 ];
//	int_to_double( evens, evens_double );
//	printf( "%s%d%s", "Amean: ", amean( evens_double ), "\n\n" );




	// Det




	double a2[10][10] = { 1, 2,
						3, 4 }; // 4 - 6 = -2

//	printf( "%s%d%s", "Det of a2: ", det_2( a2 ), "\n" );


	double a3[21][21] = { 1, 2, 3,
						  4, 0, 1, 
						  0, 1, 4 }; // 12 - ( 1 + 32 ) = -21

//	printf( "%s%d%s", "Det of a3: ", det_3( a3 ), "\n\n" );




	// Base




	printf( "%s%d%s", "Base2: ", base2( 10 ), "\n" );
	char base_16[ 142 ];
	base16( 90, base_16 );
	printf( "%s%s%s", "Base16: ", base_16, "\n\n" );




	// Triangle




//	printf( "%s%d%s", "Triangle: ", triangle( 2, 5, 4 ), " " );
//	printf( "%s%d%s", "Pitagora: ", pitagora( 0.3, 0.4, 0.5 ), " " );
//	printf( "%s%d%s", "Isoscel: ", isoscel( 4, 5, 4 ), " " );
//	printf( "%s%d%s", "Echilateral: ", echilateral( 2, 5, 4 ), "\n" );




	return 0;
}
