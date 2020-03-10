#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

string filename;
ofstream file;

string choices[1000];
int choices_iter = 0;


void get_data ()
{
	cout << "Filename of your application: ";
	cin >> filename;

	filename = filename + ".cpp";

	cout << "\nNum. of features of your applications: ";
	cin >> choices_iter;

	for ( int i=0; i<choices_iter; i=i+1 )
	{
		cout << "Name of feature " << i + 1 << ": ";
		getline( cin, choices[i] );
		if ( choices[i] == "" )
			getline( cin, choices[i] );
	}
}


void set_data ()
{
	file.open( filename );


	ifstream fi;

	fi.open( "choice_parts/choices1" );
	string temp;
	while ( getline( fi, temp ) )
		file << temp << "\n";
	fi.close();

	// declare "valid_choices"[]
	file << "string valid_choices[1000] = { ";
	for ( int i=0; i<choices_iter; i=i+1 )
		file << "\"" << i + 1 << "\", ";
	file << " \"exit\" };\n";

	// declare "choices"[]
	file << "string choices[1000] = { ";
	for ( int i=0; i<choices_iter; i=i+1 )
	{
		file << "\"" << choices[i] << "\"";
		if ( i != choices_iter - 1 )
			file << ", ";
	}
	file << " };\n";

	fi.open( "choice_parts/choices2" );
	while ( getline( fi, temp ) )
		file << temp << "\n";
	fi.close();

	// choices ifs
	for ( int i=0; i<choices_iter; i=i+1 )
	{
		file << "	// " << choices[i] << "\n";
		file << "	if ( choice == \"" << i + 1 << "\" )\n";
		file << "	{\n";
		file << "		// your code\n";
		file << "	}\n\n\n";
	}

	fi.open( "choice_parts/choices_main" );
	while ( getline( fi, temp ) )
		file << temp << "\n";
	fi.close();


	file.close();
}

int main ()
{

	get_data();
	
	set_data();

	cout << "\nDone.\n";

	return 0;
}
