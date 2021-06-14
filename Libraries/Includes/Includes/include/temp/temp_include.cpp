#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"
#include "../../empty.cpp" // length
#include "../../convert.cpp"

#include "../../temp.cpp"

using namespace std;

int main ()
{
	temp( "a", "b" );
	temp( "a", 9 );

	cout << temp( "a" ) << '\n';

	return 0;
}
