#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"

#include "../../strings.cpp"

int main ()
{
	cout << even( "142" ) << '\n';
	cout << odd( "142" ) << '\n';
	cout << pos( "142" ) << '\n';
	cout << neg( "142" ) << '\n';

	cout << add( '9', '5' ) << '\n';
	cout << add( '5', '0' ) << '\n';
	cout << add( '9', '1' ) << '\n';


	cout << sub( '9', '5' ) << '\n';
	cout << sub( '5', '0' ) << '\n';
	cout << sub( '9', '1' ) << '\n';

	cout << add( "99.01", "1.09" ) << '\n';
	cout << sub( "9.5", "41" ) << '\n';


	return 0;
}
