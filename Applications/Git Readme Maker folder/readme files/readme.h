#include <fstream>

using namespace std;

ofstream file;

void readme ( string text )
{
	// make / clear the file
	file.open( "Readme.md" );
	file.close();

	file.open( "Readme.md" );
	file << text;
	file.close();
}
