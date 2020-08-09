#include "../Includes/include.cpp"
#include "dv_files/.dv.h"

int main ()
{
	make ( "dv.cpp" ); // always on top ( precedes all your code )
	// remake ( "dv.cpp" ); // remakes your makefile, file 'e', and does 'make'

	// 'make' and 'remake': commit every 10 compilations
	// 'make': makes you a deb file
	// 'remake': remakes makefile and file 'e', makes deb file

	// also separatly:

	// save ( "dv.cpp" ); // ( commits every 10 compilations )
	// makefile ( "dv.cpp" ); // remakes makefile
 	// make_file_e ( "dv.cpp" ); // remakes file 'e'
	// deb ( "dv.cpp" ); // makes deb file



	// your code
	cout << " Welcome to dv!\n\n";
	cout << " Dv is able to:\n";
	cout << "   Commit your project\n";
	cout << "   Make you a makefile\n";
	cout << "   Make a compilation file 'e' ( compile with './e' )\n";
	cout << "   Make a Deb file\n\n";

	return 0;
}
