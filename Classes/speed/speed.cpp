#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


// check if an num. is prime
bool prime ( int a )
{
	if ( a == 0 or a == 1 )
		return false;

	if ( a == 2 )
		return true;

	if ( a % 2 == 0 )
		return false;

	for ( int d = 3; d * d < a; d = d + 2 )
		if ( a % d == 0 )
			return false;

	return true;			
}

int main ()
{
	cout << "speed ";

	cout << prime( 5 );

	cout << '\n';

	


	return 0;
}
