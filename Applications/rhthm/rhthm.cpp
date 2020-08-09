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

	for ( int i1 = 0 ; i1 <= 1; i1 = i1 + 1 )
	for ( int i2 = 0 ; i2 <= 1; i2 = i2 + 1 )
	for ( int i3 = 0 ; i3 <= 1; i3 = i3 + 1 )
	for ( int i4 = 0 ; i4 <= 1; i4 = i4 + 1 )
	for ( int i5 = 0 ; i5 <= 1; i5 = i5 + 1 )
	for ( int i6 = 0 ; i6 <= 1; i6 = i6 + 1 )
	for ( int i7 = 0 ; i7 <= 1; i7 = i7 + 1 )
	for ( int i8 = 0 ; i8 <= 1; i8 = i8 + 1 )
		fo << i1 << i2 << i3 << i4 << i5 << i6 << i7 << i8 << '\n';

	fo.close();

	return 0;
}
