#include <string.h>
#include <stdio.h>

long round_num ( double a )
{
	if ( (long) a == a )
		return (long) a;

	int is_neg = 0;
	if ( a < 0 )
	{
		is_neg = 1;
		a = - a;
	}

	if ( a - (int) a > (int) a + 1 - a )
	{
		a = (int) a + 1;
		if ( is_neg )
			a = - a;
		return (int) a;
	}

	a = (int) a;
	if ( is_neg == 1 )
		a = - a;

	return (int) a;
}

long round_asc ( double a )
{
	if ( (long) a == a )
		return (long) a;

	a = (int) a + 1;


	return (int) a;
}

long round_desc ( double a )
{
	if ( (long) a == a )
		return (long) a;

	if ( a < 0 )
		a = (int) a - 1;
	else
		a = (int) a;

	return (int) a;
}



int main ()
{
	
	float a = 1.54;
	long a_long = round_num( a );
	printf( "%d\n", a_long );	

	float b = -1.9;
	long b_long = round_asc( b );
	printf( "%d\n", b_long );	

	float l = -1.4;
	long l_long = round_desc( l );
	printf( "%d\n", l_long );	

	return 0;
}
