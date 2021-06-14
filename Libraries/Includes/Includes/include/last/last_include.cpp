#include "../../includes.cpp"

#include "../../length.cpp"

#include "../../last.cpp"

int main ()
{
	string a = "   string 	 	 file size.,file string.,size.,string file.,size.,   ";
	string strings[ 10000 ];

	move_strings( a, strings, ".," );

	for ( int i = 0; i < length( strings ); i = i + 1 )
		cout << strings[ i ] << '\n';

	reduce_spaces( a );

	cout << '"' << a << "\"\n";

	return 0;
}
