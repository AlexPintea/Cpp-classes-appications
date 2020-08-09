#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

ofstream file;

struct Subprogram 
{
	string name;
	int count;
	string types[1000];
	bool is_virtual;
	string return_type;
} subprogram[ 1000 ];
int subprogram_iter = 0;

// this converts the string encoding of types[] ( 1 - 7 ) to the actual data type strings
string type (string a)
{
	if ( a == "1" )
		return "int";
	if ( a == "2" )
		return "float";
	if ( a == "3" )
		return "double";
	if ( a == "4" )
		return "char";
	if ( a == "5" )
		return "string";
	if ( a == "6" )
		return "long";
	if ( a == "7" )
		return "bool";
	
	return a;
}

// gets subprograms for your class
void get_subprograms ()
{
	cout << "\nNum. of subprograms: ";
	cin >> subprogram_iter;

	cout << "\n\n";
	for ( int i=0; i<subprogram_iter; i=i+1 )
	{
		cout << "Name of subprogram " << i + 1 << ": ";
		cin >> subprogram[i].name;

		cout << "Parameter count of subprogram " << i + 1 << ": ";
		cin >> subprogram[i].count;

		if ( subprogram[i].count != 0 )
			cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now )\n";

		for ( int l=0; l<subprogram[i].count; l=l+1 )
		{
			cout << "Enter type of parameter " << l + 1 << " or subprogram " << i + 1 << ": ";
			cin >> subprogram[i].types[l];
			subprogram[i].types[l] = type( subprogram[i].types[l] );
		}

		cout << "Enter return type of subprogram ( type \"void\" if the case ) " << i + 1 << ": ";
		cin >> subprogram[i].return_type;
		subprogram[i].return_type = type( subprogram[i].return_type );

		string temp_choice;
		cout << "Virtual subprogram " << i + 1 << " ( y / n ): ";
		getline( cin, temp_choice );
		if ( i == 0 )
			getline( cin, temp_choice );

		if ( temp_choice == "y" )
			subprogram[i].is_virtual = true;
		else
			subprogram[i].is_virtual = false;

		cout << "\n\n";
	}

	int counter = 0;
	file << "\n\n";
	for ( int i=0; i<subprogram_iter; i=i+1 )
	{
		file << "	";
		if ( subprogram[i].is_virtual )
			file << "virtual ";
		file << subprogram[i].return_type << " " << subprogram[i].name << " ( ";
		for ( int l=0; l<subprogram[i].count; l=l+1 )
		{
			file << subprogram[i].types[l] << " parameter_" << counter;
			if ( l != subprogram[i].count - 1 )
				file << ", ";
			counter = counter + 1;
		}

		file << " )\n";
		file << "	{\n";
		file << "		// implementation\n";
		file << "	}\n\n";
	}

}

// makes a[0] into uppercase, if not already
string large_char (string a)
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}

// replaces ' ' with '_'
void replace_space ( string &a )
{
	for ( int i=0; i<a.length(); i=i+1 )
		if ( a[i] == ' ' )
			a[i] = '_';
}



int main ()
{
	string filename;
	cout << "Filename: ";
	getline( cin, filename );

	replace_space( filename );

	// makes / clears the file
	file.open( filename + ".cpp" );
	file.close();

	file.open( filename + ".cpp" );

	file << "#include <string>\n#include <fstream>\n#include <string.h>\n#include <iostream>\n\nusing namespace std;\n\n";

	file << "class " << large_char( filename ) << "\n";
	file << "{\n\n";
	file << "  public:\n\n";

	get_subprograms();

	file << "};\n\n\n";

	file << "int main ()\n";
	file << "{\n\n";
	file << "	return 0;\n";
	file << "}\n";

	file.close();

	return 0;
}
