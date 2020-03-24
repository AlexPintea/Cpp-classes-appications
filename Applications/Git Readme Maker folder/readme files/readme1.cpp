#include <fstream>

using namespace std;

ofstream file;

void readme ( string text )
{
	// make / clear the file
	file.open( "../README.txt" );
	file.close();

	file.open( "../README.txt" );
	file << text;
	file.close();
}


int main () 
{

		

	return 0;
}
