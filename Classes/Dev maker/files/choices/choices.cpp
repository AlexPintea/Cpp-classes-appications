#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

string filename;
ofstream file;

string choices[1000];
int choices_iter = 0;



bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}

// to continue
void continues ()
{
	char chars;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> chars;
}

void get_data ()
{
	// cout << "Filename of your application: ";
 	// cin >> filename;
	filename = "temp";

	filename = filename + ".cpp";

	string temp = "temp";
	cout << "\nAdd Choices ( empty means done )\n";
	while ( ! is_string_empty( temp ) )
	{
		cout << "Name of choice " << choices_iter + 1 << ": ";
		getline( cin, temp );

		if ( is_string_empty( temp ) )
			break;

		choices[ choices_iter ] = temp;
		choices_iter = choices_iter + 1;
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
	file << "\"exit\" };\n";

	// declare "choices"[]
	file << "string choices[1000] = { ";
	for ( int i=0; i<choices_iter; i=i+1 )
		file << "\"" << choices[i] << "\", ";
	file << "\"Exits\" };\n";

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

	cout << "Done with choices.\n\n";
	cout << "Your application will be compiled.\n";
	cout << "Enter \"exit\" to exit it.\n\n";
	continues();

	return 0;
}
