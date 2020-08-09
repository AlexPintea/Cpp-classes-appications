#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

void makefile ( string filename )
{
	// makes the file
	ofstream fo;
	fo.open( "Makefile" );
	fo.close();	

	fo.open( "Makefile" );

	fo << filename << ": " << filename << ".o\n";
	fo << "	g++ " << filename << ".o -o " << filename << "\n";
	fo << "	rm -f " << filename << ".o\n\n";
	fo << filename << ".o: " << filename << ".cpp\n";
	fo << "	g++ -c " << filename << ".cpp\n\n";
	fo << "clean:\n";
	fo << "	rm -f " << filename << "\n";
	fo << "	rm -f " << filename << ".o";

	fo.close();	
}

int main ()
{

	return 0;
}
