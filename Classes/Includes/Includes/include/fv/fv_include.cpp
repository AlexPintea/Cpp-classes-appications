#include "../../includes.cpp"

#include "../../fv.cpp"

int main ()
{
	set_fv( "string", "string is a size" );
	cout << get_fv( "string" ) << '\n';

	set_fv( "double", 9.5 );
	cout << get_fv( "double" ) << '\n';

	return 0;
}
