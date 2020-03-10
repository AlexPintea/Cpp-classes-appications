#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

int main ()
{
	string filename;
	cout << "Enter name of file ( !' ' ): ";
	getline( cin, filename );

	ofstream fo;
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

	return 0;
}
