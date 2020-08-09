#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../files.cpp"
#include "../../empty.cpp" // length
#include "../../last.cpp" // length
#include "../../convert.cpp" // length, empty

#include "../../lnux.cpp"

int main ()
{
 	cout << path() << '\n';
 	cout << user() << '\n';

	cout << is_file( "lnux_include.cpp" ) << '\n';
	cout << is_folder( "files" ) << '\n';


	cout << "Filesize: " << size( "lnux_include.cpp" ) << '\n';
	cout << size( "files" ) << '\n';
	cout << get_file_count( "files" ) << '\n';

	string filenames[ 1000 ];
	get_filenames( "files", filenames );

	for ( int i = 0; i < length( filenames ); i = i + 1 )
		cout << filenames[ i ] << ' ';
	cout << '\n';

	return 0;
}
