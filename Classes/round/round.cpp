#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

long round ( double &a )
{
	if ( (long) a == a )
		return (long) a;

	bool is_neg = false;
	if ( a < 0 )
	{
		is_neg = true;
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
	if ( is_neg )
		a = - a;
	return (int) a;
}

long round_asc ( double &a )
{
	if ( (long) a == a )
		return (long) a;

	a = (int) a + 1;

	return (int) a;
}

long round_desc ( double &a )
{
	if ( (long) a == a )
		return (long) a;

	if ( a < 0 )
		a = (int) a - 1;
	else
		a = (int) a;

	return (int) a;
}

long round ( float &a )
{
	double a_double = a;
	round (a_double);
	a = a_double;
}

long round_asc ( float &a )
{
	double a_double = a;
	round_asc (a_double);
	a = a_double;
}

long round_desc ( float &a )
{
	double a_double = a;
	round_desc (a_double);
	a = a_double;
}

int main ()
{
	
	float a = 1.54;
	round( a );
	cout << a << "\n";	

	float b = -1.9;
	round_asc( b );
	cout << b << "\n";	

	float l = -1.4;
	round_desc( l );
	cout << l << "\n";	

	return 0;
}
