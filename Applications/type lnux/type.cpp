#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string file = "";

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + "\n";
	fi.close();

	return file;
}

string get_file_filename ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + "\\n";
	fi.close();

	return file;
}

bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}


int main ()
{
	cout << "Choices:  1. Add String  2. Add File\n";
	string choice;
	cout << "Choice: ";
	getline( cin, choice );


	string a = "";

	if ( choice != "2" )
	{
		cout << "String ( empty means done ):\n";
	
		string temp = "details";
		while ( ! is_string_empty( temp ) )
		{
			getline( cin, temp );
			if ( is_string_empty( temp ) )
				break;

			a = a + temp + "\\n";
		}
	}

	if ( choice == "2" )
	{
		cout << "Filename: ";
		getline( cin, a );

		a = get_file_filename( a );
	}

	ofstream fo;
	fo.open( "result.cpp" );

	fo << get_file( "type files/type" );

	fo << "int main ()\n";
	fo << "{\n";
	fo << "	string a = \"" << a << "\";\n\n";

	for ( int i = 0; i < a.length(); i = i + 1 )
		fo << "	cout << \"\\033c\" << get_string( a, " << i << " ) << \'\\n\';\n	usleep( 150000 );\n\n";
	fo << "	usleep( 210000 );\n\n";

	fo << "	return 0;\n";
	fo << "}\n";

	fo.close();

	return 0;
}
