#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;


long long rndes;
long a[9];



long rnd ( long mins, long maxs )
{
	ifstream fi;
	fi.open( "rnd_file" );

	fi >> rndes;

	if ( rndes == 9000000000000000000 )
		rndes = 0;

	for ( int i=0; i<9; i=i+1 )
		fi >> a[i];

	fi.close();

	if ( a[0] == 0 )
		for ( int i=0; i<9; i=i+1 )
			a[i] = ( mins + maxs + i ) % ( maxs - mins ) + mins; 

	for ( int i=1; i<=7; i=i+1 )
		a[i] =( a[i] + maxs - mins / i + rndes ) % ( maxs - mins ) + mins;

	for ( int i=1; i<=4; i=i+1 )
		a[i] = ( maxs - a[i] ) % ( maxs - mins ) + mins;


	rndes = rndes + 1;


	ofstream fo;
	fo.open( "rnd_file" );
	fo.close();


	fo.open( "rnd_file" );

	fo << rndes << "\n";
	for ( int i=0; i<9; i=i+1 )
		fo << a[ i ] << "\n";

	fo.close();

	return a[ rndes % 9 ];
}


double rnd ( double mins, double maxs )
{
	double rnds = rnd( (long) mins, (long) maxs );

	for ( int i=0; i<3; i=i+1 )
		rnds = rnds / 10 + rnd( (long) mins, (long) maxs );

	return rnds;
}

float rnd ( float mins, float maxs )
{
	return (float) rnd( (double) mins, (double) maxs );
}

int rnd ( int mins, int maxs )
{
	return (int) rnd( (long) mins, (long) maxs );
}

char rnd ( char mins, char maxs )
{
	return (char) rnd( (int) mins, (int) maxs );
}

bool rnd ()
{
	int rnds = rnd( 1, 9 );

	if ( rnds % 2 == 0 )
		return true;

	return false;
}

void rnd ( int l, long mins, long maxs, long longs[] )
{
	for ( int i=0; i<l; i=i+1 )
		longs[i] = rnd( mins, maxs );
	longs[l] = '\0';
}

void rnd ( int l, int mins, int maxs, int ints[] )
{
	for ( int i=0; i<l; i=i+1 )
		ints[i] = rnd( mins, maxs );
	ints[l] = '\0';
}

void rnd ( int l, double mins, double maxs, double doubles[] )
{
	for ( int i=0; i<l; i=i+1 )
		doubles[i] = rnd( mins, maxs );
	doubles[l] = '\0';
}

void rnd ( int l, float mins, float maxs, float floats[] )
{
	for ( int i=0; i<l; i=i+1 )
		floats[i] = rnd( mins, maxs );
	floats[l] = '\0';
}

void rnd ( int l, char mins, char maxs, char chars[] )
{
	for ( int i=0; i<l; i=i+1 )
		chars[i] = rnd( mins, maxs );
	chars[l] = '\0';
}

string rnd ( int l, char mins, char maxs )
{
	string rnds = "";

	for ( int i=0; i<l; i=i+1 )
		rnds = rnds + rnd( mins, maxs );

	return rnds;
}

void rnd ( int l, char mins, char maxs, string &strings )
{
	strings = "";

	for ( int i=0; i<l; i=i+1 )
		strings = strings + rnd( mins, maxs );
}







int main ()
{

	cout << rnd( 1.04, 9.7 );

	return 0;
}
