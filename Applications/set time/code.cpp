#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void set_time ( string a, double time )
{
	ofstream fo;
	fo.open( "sh" );
	fo << a;
	fo.close();
	fo.open( "time" );
	fo << time;
	fo.close();
	system( "./ code.sh" );	// should be bsh
}

void set_time ( string a )
{
	set_time( a, 0.15 );
}

int main ()
{
	set_time( "aaaaa" );

	return 0;
}
