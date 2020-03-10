#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// Compile with:  clear && g++ -o your_file your_file.cpp && ./your_file
// Do not remove files: ".filename", ".count", ".commit"
// If you want to reset the counter, modify file ".count"


// this saves your file every 10 compilations
void save ( string filename )
{
	// clear file ".filename"
	ofstream f; 
	f.open( ".filename" );
	f.close();

	f.open( ".filename" );
	f << filename;
	f.close();

	char command[] = "./.commit";
	system( command );
}

int main ()
{

	cout << "\nCompiled\n";

	// if you rename, modify
	save ( "your_file.cpp" );

	return 0;
}
