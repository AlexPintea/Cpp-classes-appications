#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"
#include "../../empty.cpp"

#include "../../remove.cpp"

int main ()
{




	string a[ 10 ] = { "a", "ab", "abl", "l", "al" };

	remove_common( a, "remove_common" );



	for ( int i = 0; i < length( a ); i = i + 1 )
		cout << a[ i ] << ' ';
	cout << '\n';
	return 0;
}
