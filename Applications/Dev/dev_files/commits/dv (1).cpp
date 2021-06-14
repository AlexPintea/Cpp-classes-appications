#include "../Includes/include.cpp"
#include "dv_files/.dv.h"

int main ()
{
	make ( "dv.cpp" ); // always on top ( precedes all your code )
	// commits every 10 compilations
	// makes: 'Makefile', file 'e' and deb

	// also

	// save ( "dv.cpp" ); // ( commits every 10 compilations )
	// makefile ( "dv.cpp" );
 	// make_file_e ( "dv.cpp" );
	// deb ( "dv.cpp" );	



	// your code
	cout << "Welcome to dv!\n\n";
	cout << "Dv is able to:\n";
	cout << "  Commit your project\n";
	cout << "  Make you a makefile\n";
	cout << "  Make a compilation file 'e' ( compile with './e' )\n";
	cout << "  Make a Deb file\n\n";

	return 0;
}
