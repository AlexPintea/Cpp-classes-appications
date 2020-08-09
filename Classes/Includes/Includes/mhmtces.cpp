#include <math.h>

// #include "lengths.cpp"

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

int gc ( int a[] )
{
	int p = 1;

	for ( int i = 0; i < length( a ); i = i + 1 )
		for ( int l = 0; l < a[ i ]; l = l + 1 )
			p = p + p;
	return p / lc( a );
}



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








// Means
double gmean ( int a , int b )
{
	return sqrt( a * b );
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

double amean ( int a[] )
{
	int size = length( a );
	if ( size == 0 )
		return 0;

	double s = 0;

	for ( int i = 0; i < size; i = i + 1 )
		s = s + a[ i ];

	return s / size;
}




// Equation
class Equation
{

  private:

	float a;
	float b;
	float c;


  public:

	Equation (){}

	Equation ( float a, float b, float c )
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}


	// Getters


	float get_a () { return this->a; }
	float get_b () { return this->b; }
	float get_c () { return this->c; }


	// Setters


	void set_a ( float a ) { this->a = a; }
	void set_b ( float b ) { this->b = b; }
	void set_c ( float c ) { this->c = c; }



	// result
	void result ( float res[] )
	{
		float sqrt_d = sqrt( b * b - 4 * a * c );

		res[ 0 ] = ( -b + sqrt_d ) / ( 2 * a );
		res[ 1 ] = ( -b - sqrt_d ) / ( 2 * a );
	}

	float extreme_y ()
	{
		float d = b * b - 4 * a * c;

		return d / ( 4 * a );
	}

	float extreme_x () { return -b / ( 2 * a ); }


	void axis_x ( float res[] ) { result( res ); }
	float axis_y () { return c; }
};




// Det
float det ( float a[2][2] ) { return a[0][0]*a[1][1] - a[0][1]*a[1][0]; }

// 00 01 02
// 10 11 12
// 20 21 22

float det ( float a[3][3] )
{
	float m1 = a[0][0]*a[1][1]*a[2][2] + a[0][2]*a[1][0]*a[2][1] + a[0][1]*a[1][2]*a[2][0];
	float m2 = a[0][2]*a[1][1]*a[2][0] + a[0][0]*a[1][2]*a[2][1] + a[1][0]*a[2][2]*a[0][1];

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


string base16 ( int a )
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

	string result = "";
	for ( int i = count - 1; i >= 0; i = i - 1 )
		result = result + base16_chars[ reminders[ i ] ];
	
	return result;
}




// Interval
class Interval
{
  private:

	float l;
	float r;
	bool closed_l = true;
	bool closed_r = true;

  public:

	Interval () {}

	Interval ( float l, float r ) 
	{
		if ( l > r ) return;

		this->l = l;
		this->r = r;
	}

	Interval ( float l, float r, bool closed ) 
	{
		if ( l > r ) return;

		this->l = l;
		this->r = r;

		this->closed_r = closed;
		this->closed_l = closed;
	}

	Interval ( float l, float r, bool closed_l, bool closed_r ) 
	{
		if ( l > r ) return;

		this->l = l;
		this->r = r;

		this->closed_l = closed_l;
		this->closed_r = closed_r;
	}



	// Getters



	float get_l () { return this->l; }
	float get_r () { return this->r; }
	float get_closed_l () { return this->closed_l; }
	float get_closed_r () { return this->closed_r; }



	// Setters



	void set_l ( float l ) { this->l = l; }
	void set_r ( float r ) { this->r = r; }
	void set_closed_l ( float closed_l ) { this->closed_l = closed_l; }
	void set_closed_r ( float closed_r ) { this->closed_r = closed_r; }
	void set_closed ( float closed ) 
	{
		this->closed_l = closed;
		this->closed_r = closed;
	}



	bool is_in ( float m )
	{
		if ( this->closed_l ) { if ( m < l ) return false; }
		else { if ( m <= l ) return false; }
		
		if ( this->closed_r ) { if ( m > r ) return false; }
		else { if ( m >= r ) return false; }

		return true;
	}


	void info () 
	{
		cout << "l = " << this->l << ", r = " << this->r << ", closed l = " << this->closed_l << ", closed r = "  << this->closed_r;
	}
};


Interval interval_union ( Interval interval1, Interval interval2 )
{
	if ( interval1.get_l() > interval2.get_l() and interval1.get_l() - interval2.get_r() > 0 )
		return interval1;

	if ( interval2.get_l() > interval1.get_l() and interval2.get_l() - interval1.get_r() > 0 )
		return interval1;

	float min_l = interval1.get_l();
	bool closed_l = interval1.get_closed_l();
	if ( interval2.get_l() < min_l )
	{
		min_l = interval2.get_l();
		closed_l = interval2.get_closed_l();
	}

	float max_r = interval1.get_r();
	bool closed_r = interval1.get_closed_r();
	if ( interval2.get_r() > max_r )
	{
		max_r = interval2.get_r();
		closed_r = interval2.get_closed_r();
	}
	return Interval( min_l, max_r, closed_l, closed_r );
}




Interval interval_common ( Interval interval1, Interval interval2 )
{
	if ( interval1.get_l() > interval2.get_l() and interval1.get_l() - interval2.get_r() > 0 )
		return interval1;

	if ( interval2.get_l() > interval1.get_l() and interval2.get_l() - interval1.get_r() > 0 )
		return interval1;

	float max_l = interval1.get_l();
	bool closed_l = interval1.get_closed_l();
	if ( interval2.get_l() > max_l )
	{
		max_l = interval2.get_l();
		closed_l = interval2.get_closed_l();
	}

	float min_r = interval1.get_r();
	bool closed_r = interval1.get_closed_r();
	if ( interval2.get_r() < min_r )
	{
		min_r = interval2.get_r();
		closed_r = interval2.get_closed_r();
	}
	return Interval( max_l, min_r, closed_l, closed_r );
}



class Prg_Ar
{

  private:

	double a0;
	double r;

  public:

	Prg_Ar ( double a0, double r )
	{
		this->a0 = a0;
		this->r = r;
	}

	double get_a0 () { return this->a0; }
	double get_r () { return this->r; }

	double set_a0 ( double a0 ) { this->a0 = a0; }
	double set_r ( double r ) { this->r = r; }


	double get_a ( int i )
	{
		return a0 + i * r;
	}


	// l x ( ( l + 1 ) x r / 2 + a0 ) 

	double get_sum ( int l )
	{
		double sum = 0;
		for ( int i = 0; i < l; i = i + 1 )
			sum = sum + get_a( i );
		return sum;
	}

	double get_sum ( int a, int b )
	{
		if ( a >= b )
			return get_sum( a ) - get_sum( b );
		else
			return get_sum( b ) - get_sum( a );
	}

	double get_prg ( int l, double a[] )
	{
		for ( int i = 0; i < l; i = i + 1 )
			a[ i ] = this->get_a( i );
	}

	double get_prg ( int a, int b, double prg[] )
	{
		int l = 0;
		for ( int i = a; i < b; i = i + 1 )
		{
			prg[ l ] = this->get_a( i );
			l = l + 1;
		}
	}

	void info ()
	{
		cout << "a[ l ] = " << this->a0 << " + " << this->r << "l\n";
	}
};





class Prg_Gmer
{

  private:

	double a0;
	double r;

  public:

	Prg_Gmer ( double a0, double r )
	{
		this->a0 = a0;
		this->r = r;
	}

	double get_a0 () { return this->a0; }
	double get_r () { return this->r; }

	double set_a0 ( double a0 ) { this->a0 = a0; }
	double set_r ( double r ) { this->r = r; }


	double get_a ( int l )
	{
		int a = this->a0;
		for ( int i = 0; i < l; i = i + 1 )
			a = a * r;
		return a;
	}


	double get_sum ( int l )
	{
		double sum = 0;
		for ( int i = 0; i < l; i = i + 1 )
			sum = sum + get_a( i );
		return sum;
	}

	double get_sum ( int a, int b )
	{
		if ( a >= b )
			return get_sum( a ) - get_sum( b );
		else
			return get_sum( b ) - get_sum( a );
	}

	double get_prg ( int l, double a[] )
	{
		for ( int i = 0; i < l; i = i + 1 )
			a[ i ] = this->get_a( i );
	}

	double get_prg ( int a, int b, double prg[] )
	{
		int l = 0;
		for ( int i = a; i < b; i = i + 1 )
		{
			prg[ l ] = this->get_a( i );
			l = l + 1;
		}
	}

	void info ()
	{
		cout << "a[ l ] = " << this->a0 << '(' <<  this->r << " at l)\n";
	}
};
