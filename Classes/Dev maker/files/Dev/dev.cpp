#include "../../Includes/include.cpp"
#include "dev_files/.dev.h"

int main ()
{
	// Comment 'remake' and leave only 'make'

	// make ( "dev.cpp" ); // always on top ( precedes all your code )
	remake ( "dev.cpp" ); // remakes your makefile, file 'e', and does 'make'

	// 'make' and 'remake': commit every 10 compilations
	// 'make': makes you a deb file
	// 'remake': remakes makefile and file 'e', makes deb file

	// also separatly:

	// save ( "dev.cpp" ); // ( commits every 10 compilations )
	// makefile ( "dev.cpp" ); // remakes makefile
 	// make_file_e ( "dev.cpp" ); // remakes file 'e'
	// deb ( "dev.cpp" ); // makes deb file

	// your code
	cout << " Welcome to Dev!\n\n";
	cout << " Dev is able to:\n";
	cout << "   Commit your project\n";
	cout << "   Make you a makefile\n";
	cout << "   Make a compilation file 'e' ( compile with './e' )\n";
	cout << "   Make a Deb file\n\n";

	return 0;
}
