#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

ofstream file;
string name = "application", filename;

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

void string_to_char (string a, char result[])
{
	int size = a.length();

	int i;

	for (i=0; i<size; i=i+1)
		result[i] = a[i];

	result[i] = '\0';
}

void command_linux ( string command_string )
{
	char command_char[1000];
	string_to_char( command_string, command_char );
	system( command_char );
}

void enter()
{
	char enter;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> enter;
	cout << "\n";
}


void includes ()
{
	file << "#include <string>\n#include <fstream>\n#include <string.h>\n#include <iostream>\n\nusing namespace std;\n\n";
}

void mains ()
{
	file << "\n\nint main()\n{\n	// your code\n\n	return 0;\n}";
}

void variable ()
{
	cout << "Variable name: ";
	string var_name;
	getline( cin, var_name );

	cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now )\n";
	cout << "Variable type: ";
	string var_type;
	getline( cin, var_type );
	var_type = type( var_type );

	file << "\n" << var_type << " " << var_name << ";\n";
}

void variables ()
{
	cout << "Stop with \"/done\".\n";
	for ( int i=0; i<10000; i=i+1 )
	{
		cout << "Variable name: ";
		string var_name;
		getline( cin, var_name );
		if ( var_name == "/done" )
			break;

		cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now )\n";
		cout << "Variable type: ";
		string var_type;
		getline( cin, var_type );
		var_type = type( var_type );

		file << "\n" << var_type << " " << var_name << ";\n";
		cout << "\n";
	}

	cout << "\nStopped.\n";
}

void subprogram ()
{
	cout << "Subprogram name: ";
	string subprogram_name;
	getline( cin, subprogram_name );
	cout << "\n";

	cout << "Enter num. of parameters: ";
	int num_parameters;
	cin >> num_parameters;

	string parameters[1000];
	string parameter_types[1000];

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		cout << "Parameter " << i + 1 << " name: ";
		getline( cin, parameters[i] );
		if ( i == 0 )
			getline( cin, parameters[i] );

		cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now )\n";
		cout << "Parameter " << i + 1 << " type: ";
		string var_type;
		getline( cin, var_type );
		parameter_types[i] = type( var_type );
		cout << "\n";
	}

	cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now )\n";
	cout << "Return type: ";
	string return_type;
	getline( cin, return_type );
	return_type = type( return_type );

	file << "\n" << return_type << " " << subprogram_name << " ( ";
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << parameter_types[i] << " " << parameters[i];
		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << ")\n";
	file << "{\n";
	file << "	// your code\n";
	file << "}\n\n";
	cout << "\n";
}

void structs ()
{
	cout << "Struct name: ";
	string struct_name;
	getline( cin, struct_name );
	cout << "\n";

	cout << "Enter num. of parameters: ";
	int num_parameters;
	cin >> num_parameters;

	string parameters[1000];
	string parameter_types[1000];

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		cout << "Parameter " << i + 1 << " name: ";
		getline( cin, parameters[i] );
		if ( i == 0 )
			getline( cin, parameters[i] );

		cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now )\n";
		cout << "Parameter " << i + 1 << " type: ";
		string var_type;
		getline( cin, var_type );
		parameter_types[i] = type( var_type );
		cout << "\n";
	}

	file << "\nstruct " << struct_name << "\n{\n";
	for ( int i=0; i<num_parameters; i=i+1 )
		file << "	" << parameter_types[i] << " " << parameters[i] << ";\n";

	file << "};\n\n";
	cout << "\n";
}

string choice = "";

void show_choices()
{
	cout << "\nChoices:  1. variable   2. subprogram   3. class   4. struct\n";
	cout << "          5. variables  exit. Exit\n\n";

	cout << "Your choice: ";

	getline( cin, choice );

	if ( choice != "1" and choice != "2" and choice != "3" and choice != "4" and choice != "5" and choice != "exit" )
	{
		cout << "Invalid choice. Retry.\n\n";
		return;
	}

	if ( choice == "1" )
		variable();
	if ( choice == "2" )
		subprogram();
	if ( choice == "3" )
	{
		cout << "\n( info ) Class is made outside your file.\n\n";
		enter();
		system( "./class" );
		cout << "Class done\n\n";
		enter();

		string empty; // to continue
		getline( cin, empty );
	}
	if ( choice == "4" )
		structs();
	if ( choice == "5" )
		variables();
}




int main ()
{
	cout << "( info ) Does not check for same variable names. What you enter stays.\n\n";

	enter();

	string empty; // to continue
	getline( cin, empty );
	while ( name == "application" )
	{
		cout << "Enter name of application ( \"application\" is invalid ): ";
		getline( cin, name );
	}

	filename = name + ".cpp";

	cout << "\nYou are editing \'" << filename << "\'.\n";

	file.open( filename );

	includes();

	while ( choice != "exit" )
		show_choices();

	mains();

	file.close();

	cout << "\nApplication done\n\n";

	return 0;
}
