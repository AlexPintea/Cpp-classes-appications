#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;
int main ()
{
	cout << "rhthm\n";
	ofstream fo;
	fo.open( "rhythms" );

	for ( int i1 = 0 ; i1 < 8; i1 = i1 + 1 )
	for ( int i2 = 0 ; i2 < 8; i2 = i2 + 1 )
	for ( int i3 = 0 ; i3 < 8; i3 = i3 + 1 )
	for ( int i4 = 0 ; i4 < 8; i4 = i4 + 1 )
		fo << i1 << i2 << i3 << i4 << '\n';

	fo.close();

	return 0;
}
