#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;


ofstream file;

// number or parameters that the class has
int num_parameters;

string name, filename = "";
string parameters[100];
// the datatypes of variables are stored as strings, but those strings are coded 1 - 7, to correlate with datatypes
string types[100];


// length of a string
int length (string a)
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}


// length of a string[]
int length ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
}

// invert a string
string invert_string (string a)
{
	int len = a.length();
	string r = "";

	for (int i=len-1; i>=0; i=i-1)
	{
		r = r + a[i];
	}

	return r;
}

// convert an int to a string 
string int_string (int a)
{
	string r = "";

	while (a != 0)
	{		
		r = r + (char) (a%10 + 48);
		a=a/10;
	}

	r = invert_string(r);

	return r;
}

// replaces spaces in entered data, to make valid variable names
void replace_space (string &a)
{
	for (int i=0; i<a.length(); i=i+1)
		if ( a[i] == ' ' )
			a[i] = '_';
}

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

// makes a[0] into uppercase, if not already
string large_char (string a)
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}

// converts variable names such as 'parameter[10]' into 'parameter'
string remove_brackets ( string a )
{
	int size = length(a);
	string result = "";


	for ( int i=0; i<size; i=i+1 )
	{
		if ( a[i] != '[' )
			result = result + a[i];
		else
			break;
	}

	return result;	
}


// converts variable names such as 'parameter[10]' into 'parameter[]'
string brackets ( string a )
{
	a = remove_brackets (a);
	
	a = a + "[]";

	return a;
}

// checks if the property name is not altready taken
bool is_property_name_taken ( string name )
{
	int size = length( parameters );

	for ( int i=0; i<size; i=i+1 )
	{
		if ( parameters[i] == name or remove_brackets( parameters[i] ) == name or remove_brackets( name ) == parameters[i] )
			return true;
	}

	return false;
}

// makes length() inside the class 
void make_length ( string type_of_variable )
{
	file << "\n	int length ( ";
	
	file << type( type_of_variable ) << " data[] ) // returns length + 1, returning i - 1 does not help\n	{\n";

	if ( type_of_variable == "5" )
	{
		file << "		return data.length();\n	}\n";
	}
	else
	{
		file << "		int i = 0;\n";

		string ending = "\"\"";

		if ( type_of_variable == "1" or type_of_variable == "2" or type_of_variable == "6" or type_of_variable == "3" or type_of_variable == "4" or type_of_variable == "7" )
			ending = "\'\\0\'";

		file << "		while ( data[i] != " << ending << " )\n			i=i+1;\n\n		return i;\n	}\n";
	}
}

// makes copy() inside the class
void make_copy ( string type_of_variable )
{
	file << "	void copy ( ";

	file << type( type_of_variable ) << " source[], " << type( type_of_variable ) << " dest[] )\n	{\n";

	file << "		for ( int i=0; i<length(source); i=i+1)\n			dest[i] = source[i];\n	}\n\n";
}

// returns the last char of a string
char last_char ( string a )
{
	return a[ length(a) - 1 ];
}

// used to 'cout' through the file that is made
void enter_cout ( string a )
{
	file << "	cout << \"" << a << "\";" <<"\n";
}

// used to 'cout' through the file that is made
void enter_cout ( string a[] )
{
	file << "	cout";
	
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		file << " << \"" << a[i] << " \"";

	file << ";\n";
}



// give length 10 to a parameter[], if it does not have one
void give_length( string &parameter )
{
	int size = parameter.length();

	if ( parameter[ size - 1 ] == ']' and parameter[ size - 2 ] == '[' )
	{
		parameter[ size - 1 ] = '1';
		parameter = parameter + "0]";
	}
}

// show info
void show_info()
{
	
	cout << "Info:\n\n";

	cout << "( info ) Do not enter empty variable columns or datatypes.\n";
	cout << "( info ) If you want to store multiple items of the same type in one variable, type \"[]\" after variable name.\n";
	cout << "         If you know how many you want to store ( maximum ), type \"parameter_name[142]\" etc.\n\n";

	char enter;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> enter;

	cout << "\n";
}


int main ()
{



	// Getting data




	show_info();

	cout << "Enter a filename that does not exist in this folder.\n";

	cout << "Name: ";
	std::getline(cin, name);
	std::getline(cin, name);

	replace_space( name );

	filename = name + ".cpp";
	cout << "You are editing: " << filename << "\n\n";

	file.open(filename);

	cout << "Enter num. or parameters: ";
	cin >> num_parameters;
	cout << "\n\n";
	
	cout << "Do not enter empty variable columns or types.\n";

	cout << "Parameters:\n\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		string parameter;
		int attempts = 0;

		cout << "Name of parameter " << i + 1 << ": ";
		getline(cin, parameter);
		if ( i == 0 )
			getline(cin, parameter);

		while ( is_property_name_taken ( parameter ) )
		{
			cout << "Parameter name: \"" << remove_brackets( parameter ) << "\" is taken.\n";

			cout << "Name of parameter " << i + 1 << ": ";
			getline(cin, parameter);
		}

		give_length( parameter );

		parameters[i] = parameter;

		replace_space( parameters[i] );
		cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom ( enter now )\n";
		cout << "Type of parameter " << i + 1 << ": ";
		getline(cin, types[i]);
		replace_space( types[i] );
		cout << "\n";
	}





	// Getting the data into our cpp file




	// including classes
	file << "#include <string>\n#include <fstream>\n#include <string.h>\n#include <iostream>\n\nusing namespace std;\n\n";

	// parameters that might help to have in that file
	file << "int num_parameters = " << num_parameters << ";\n";
	file << "string parameters[" << num_parameters + 1 << "] = { ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "\"" << parameters[i] << "\"";
		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << "};\n";

	file << "string columns[" << num_parameters + 1 << "] = { ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "\"" << parameters[i] << "\"";
		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << "};\n";

	file << "string types[" << num_parameters + 1 << "] = { ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "\"" << type( types[i] ) << "\"";
		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << "};\n\n";





	// Class





	// class name
	file << "class " << large_char(name) << " {\n";

	// a comment in the class about the class parameters
	file << "\n	// \"" << large_char(name) << "\" has parameters: ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << parameters[i];

		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << "\n\n	// Parameters:\n";

	// parameters are instantiated
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			file << "	int " << remove_brackets( parameters[i] ) << "_count;\n";
		file << "	" << type( types[i] ) << " " << parameters[i] << ";\n";
	}

	file << "\n	bool is_empty;\n";

	file << "\n  public:\n\n";


	// make length() for certain data types
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			make_length( types[i] );
	}

	file << "\n\n";


	// make copy() for certain data types
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			make_copy( types[i] );
	}
	
	// Class()
	file << "	" << large_char(name) << "()\n	{\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) != ']' )
		{
			file << "		this->" << parameters[i] << " = ";

			if ( type( types[i] ) != types[i] )
			{
				if ( types[i] == "1" or types[i] == "2" or types[i] == "6" or types[i] == "3" )
					file << 0;
				if ( types[i] == "4" )
					file << "\' \'";
				if ( types[i] == "5" )
					file << "\"\"";
				if ( types[i] == "7" )
					file << "false";
			}
			else
				file << "null";

			file << ";\n";
		}
		else
			file << "//		copy( {}, this->" << remove_brackets( parameters[i] ) << " ); // You edit this\n";

	}
	
	file << "\n		this->is_empty = true;\n";

	file << "	}\n\n";

	// Class( parameters )
	file << "	" << large_char(name) << " ( ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << type( types[i] ) << " ";
		if ( last_char( parameters[i] ) == ']' )
			file << brackets( parameters[i] );
		else
			file << parameters[i];

		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << ")\n	{\n";
	
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) != ']' )
			file << "		this->" << parameters[i] << " = " << parameters[i] << ";\n";
		else
			file << "		copy( " << remove_brackets( parameters[i] ) << ", this->" << remove_brackets( parameters[i] ) << " );\n";

	}

	file << "\n		this->is_empty = true;\n";
	
	file << "	}\n\n";



	// Getters 



	file << "\n	// Getters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			// get it entirely
			file << "	void get_" << remove_brackets( parameters[i] ) << "";
			file << "( " << type( types[i] ) << " dest[] ) { copy( this->" << remove_brackets( parameters[i] ) << ", dest ); };\n";

			// get an item of it  ( parameter[i] )
			file << "	" << type( types[i] ) << " get_" << remove_brackets( parameters[i] ) << "( int i ) // get " << remove_brackets( parameters[i] ) << "[i]\n";
			file << "	{\n";
			file << "		if ( i < " << remove_brackets( parameters[i] ) << "_count and i >= 0 )\n";
			file << "			return " << remove_brackets( parameters[i] ) << "[i];\n"; 
			file << "		else\n";
			file << "		{\n";
			file << "			cout << \"\\n(get) Item at \'\" << i << \"\' (\"<< i+1 << \"-th) is not available in \'" << parameters[i] << "\'. Its size is \'\" << " << remove_brackets( parameters[i] ) << "_count << \"\'. 0 was returned.\\n\";\n";
			file << "			return 0;\n"; 
			file << "		}\n";
			file << "	}\n";

			// get its count
			file << "	int get_" << remove_brackets( parameters[i] ) << "_count() { return this->" << remove_brackets( parameters[i] ) << "_count; }\n";
		}
		else
		{
			file << "	" << type( types[i] ) << " get_" << remove_brackets( parameters[i] ) << "";
			file << "() { return this->" << parameters[i] << "; };\n";
		}
	}
	
	file << "\n	bool get_is_empty() { return this->is_empty; }\n";






	file << "\n";

	// get every property of the class
	file << "	void get ( ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			file << type( types[i] ) << " " << brackets( parameters[i] );
		else
			file << type( types[i] ) << " " << parameters[i];

		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << ")\n	{\n";
	
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			file << "		copy( this->" << remove_brackets( parameters[i] ) << ", " << remove_brackets( parameters[i] ) << " );\n";
		else
			file << "		" << parameters[i] << " = this->" << parameters[i] << ";\n";
	}
	
	file << "	}\n\n";




	// Setters




	file << "\n	// Setters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			// set it entirely
			file << "	void set_" << remove_brackets( parameters[i] ) << "( " << type( types[i] );
			file << " data[] ) { copy( data, this->" << remove_brackets( parameters[i] ) << " );";
			file << " this->is_empty = false; ";
			file << " };\n";

			// set an item of it  ( parameter[i] )
			file << "	void set_" << remove_brackets( parameters[i] ) << "( " << type( types[i] ) << " data, int i ) // set " << remove_brackets( parameters[i] ) << "[i] to data\n";
			file << "	{\n";
			file << "		if ( i < " << remove_brackets( parameters[i] ) << "_count and i >= 0 )\n";
			file << "			" << remove_brackets( parameters[i] ) << "[i] = data;\n"; 
			file << "		else\n";
			file << "		{\n";
			file << "			cout << \"\\n(set) Item at \'\" << i << \"\' (\"<< i+1 << \"-th) is not available in \'" << parameters[i] << "\'. Its size is \'\" << " << remove_brackets( parameters[i] ) << "_count << \"\'. It was not modified.\\n\";\n";
			file << "		}\n";
			file << "	}\n";

			// set its count
			file << "	void set_" << remove_brackets( parameters[i] ) << "_count( int data ) { this->" << remove_brackets( parameters[i] ) << "_count = data; }\n";
		}
		else
		{
			file << "	void set_" << parameters[i] << "( " << type( types[i] );
			file << " data ) { this->" << parameters[i] << " = data;";
			file << " this->is_empty = false; ";
			file << " };\n";
		}
	}

	file << "\n";

	file << "	void set ( ";

	// set every property of the class
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << type( types[i] ) << " ";

		if ( last_char( parameters[i] ) == ']' )
			file << brackets( parameters[i] );
		else
			file << parameters[i];

		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << ")\n	{\n";

	
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			file << "		copy( " << remove_brackets( parameters[i] ) << ", this->" << remove_brackets( parameters[i] ) << " );\n";
		else
			file << "		this->" << parameters[i] << " = " << parameters[i] << ";\n";
	}

	file << "\n	 	this->is_empty = false;\n";

	file << "	}\n\n";



	// info() - get info about the class parameters, their types and val.-s 



	file << "	// Info:\n";

	file << "	void info()\n	{\n";

	file << "		cout << \"\\nclass " << large_char(name) << " \"" << " << \"{\"" <<  " << \'\\n\';";

	file << "\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "		cout << \"	int " << remove_brackets( parameters[i] ) << "_count = \" << " << remove_brackets( parameters[i] ) << "_count << \'\\n\';\n";
			file << "		cout << \"	" << type( types[i] ) << "\" << \' \' << \"" << parameters[i] << " = { \";\n";
			file << "		for ( int i=0; i<" << remove_brackets( parameters[i] ) << "_count; i=i+1 )\n";
			file << "			cout << \"\'\" << " << remove_brackets( parameters[i] ) << "[i] << \"\' \";\n";
			file << "		cout << \"}\\n\";\n";
		}
		else
			file << "		cout << \"	" << type( types[i] ) << "\" << \' \' << \"" << parameters[i] << " = \" << " << parameters[i] << " << \'\\n\';";

		file << "\n";
	}
	
	file << "	 	cout << " << "\'}\'" <<  " << \"\\n\\n\";";


	file << "\n";

	file << "	}\n\n";

	file << "};\n\n\n";

	file << "int main ()\n";
	file << "{\n\n";
	file << "	return 0;\n";
	file << "}\n";

	file.close();

	cout << "\n\nClass is complete.\n\n";

	return 0;
}
