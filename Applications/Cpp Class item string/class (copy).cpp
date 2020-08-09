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

// replaces spaces in entered data, to make valid variable columns
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

// checks if a property is numeric
bool is_numeric( int i )
{
	if ( type( types[i] ) == "int" )
		return true;
	if ( type( types[i] ) == "float" )
		return true;
	if ( type( types[i] ) == "double" )
		return true;
	if ( type( types[i] ) == "long" )
		return true;
	if ( type( types[i] ) == "bool" )
		return true;

	return false;
}


// have a certain datatype
bool have_datatype( string datatype )
{
	for ( int i=0; i<num_parameters; i=i+1 )
		if ( type( types[i] ) == datatype )
			return true;

	return false;
}

// check if we have numeric datatypes
bool have_numeric()
{
	if( have_datatype( "int" ) or have_datatype( "float" ) or have_datatype( "double" ) or have_datatype( "long" ) or have_datatype( "bool" ) )
		return true;

	return false;
}


// makes a[0] into uppercase, if not already
string large_char (string a)
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}

// converts variable columns such as 'parameter[10]' into 'parameter'
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


// converts variable columns such as 'parameter[10]' into 'parameter[]'
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
	file << "\n	// length of a " << type( type_of_variable ) << "[]";
	file << "\n	int length ( ";
	
	file << type( type_of_variable ) << " data[] ) // returns length + 1, returning i - 1 does not help\n	{\n";

	file << "		int i = 0;\n";

	file << "		while ( data[i] )\n			i=i+1;\n\n		return i;\n	}\n";
}

// makes copy() inside the class
void make_copy ( string type_of_variable )
{
	file << "	// make a copy of a " << type( type_of_variable ) << "[]\n";
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






// empty words
void empty ( string words[] )
{
	int size = length( words );

	for ( int i=0; i<size; i=i+1 )
		words[i] = "";
}

// gets words of  string a  into  words[]  
void get_words( string a, string words[] )
{
	int size = a.length();
	empty( words );

	int counter = 0;

	a = a + " ";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			counter = counter + 1;
		else
			words[ counter ] = words[ counter ] + a[i];
}




// check if a string is an int
bool is_int ( string a )
{
	int size = a.length();

	if ( size >= 10 )
		return false;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}

// check if a string is an int
bool is_long ( string a )
{
	int size = a.length();

	if ( size > 19 and a[0] == '-' )
		return false;
	if ( size >= 19 and a[0] != '-' )
		return false;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}

// check if a string is a double
bool is_double ( string a )
{
	int size = a.length();
	bool have_decimals = false;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( !( ( a[i] >= '0' and a[i] <= '9' ) or a[i] == '.' or a[i] == '-' ) )
			return false;
		if ( a[i] == '.' )
			have_decimals = true;
	}

	if ( have_decimals )
		return true;

	return false;
}

// check if a string is a char
bool is_char ( string a )
{
	int size = a.length();
	if ( size != 1 )
		return false;

	if ( ( a[0] >= '0' and a[0] <= '9' ) )
			return false;

	return true;
}


// check if a string is a bool
bool is_bool ( string a )
{
	if ( a == "true" or a == "1" )
		return true;

	return false;
}

// check if a string fits only in the datatype "string"
bool is_only_string ( string a )
{
	if ( is_int(a) )
		return false;

	if ( is_long(a) )
		return false;

	if ( is_double(a) )
		return false;

	if ( is_char(a) )
		return false;

	if ( is_bool(a) )
		return false;

	// if your string is actually a datatype
	// if ( a == "int" or a == "double" or a == "char" or a == "bool" )
		// return false;

	return true;
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


// get data 1
void get_data_1( string &name, string parameters[], string types[], int &num_parameters )
{
	cout << "Enter a filename that does not exist in this folder.\n";

	cout << "Name: ";
	std::getline(cin, name);



	cout << "You are editing: " << name << ".cpp\n\n";

	cout << "Enter num. or parameters: ";
	cin >> num_parameters;
	cout << "\n\n";
	
	cout << "( info ) Do not enter empty variable columns or types.\n";
	cout << "( info ) If you want to store multiple items of the same type in one variable, type \"[]\" after variable name.\n";
	cout << "         If you know how many you want to store ( maximum ), type \"parameter_name[142]\" etc.\n\n";

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

}


// get data 2
void get_data_2 ( string &name, string parameters[], string types[], int &num_parameters )
{
	cout << "Enter a filename that does not exist in this folder.\n";

	cout << "Name: ";
	std::getline(cin, name);


	cout << "You are editing: " << name << ".cpp\n\n";

	string parameter_string; 
	cout << "( info ) Do not enter empty variable columns or types.\n";
	cout << "( info ) If you want to store multiple items of the same type in one variable, type \"[]\" after variable name.\n";
	cout << "         If you know how many you want to store ( maximum ), type \"parameter_name[142]\" etc.\n\n";

	cout << "Enter parameter names now ( \" name age \" etc. ) : ";
	std::getline(cin, parameter_string);
	get_words( parameter_string, parameters );

	cout << "\n";

	string type_string; 
	cout << "( info ) If you want a parameter to be either \"true\" or \"false\", type it so.\n";
	cout << "( info ) If a parameter stores multiple items ( has \"[]\" ) type in only one such item.\n";
	cout << "Enter parameter types now ( \" Aname 17 \" etc. ) : ";
	std::getline(cin, type_string);
	get_words( type_string, types );

	num_parameters = length( parameters );

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( is_only_string(types[i]) )
			types[i] = "string";

		if ( is_int(types[i]) )
			types[i] = "int";

		if ( is_long(types[i]) )
			types[i] = "long";

		if ( is_double(types[i]) )
			types[i] = "double";

		if ( is_char(types[i]) )
			types[i] = "char";

		if ( is_bool(types[i]) )
			types[i] = "bool";
	}
	
	for ( int i=0; i<num_parameters; i=i+1 )
		give_length( parameters[i] );
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



void set_data( string &name, string parameters[], string types[], int &num_parameters )
{

	
	filename = name + ".cpp";
	file.open( filename );

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

			if ( types[i].length() == 1 )
			{
				// if it was made with  get_data_1()  
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
			{
				if ( types[i] == "int" or types[i] == "long" or types[i] == "double" or types[i] == "char" or types[i] == "string" or types[i] == "bool" )
				{
					// if it was made with  get_data_2()  
					if ( types[i] == "int" or types[i] == "long" or types[i] == "double" )
						file << 0;
					if ( types[i] == "char" )
						file << "\' \'";
					if ( types[i] == "string" )
						file << "\"\"";
					if ( types[i] == "bool" )
						file << "false";
				}
				else
					file << "NULL";
			}

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




	// Variables and iterators used a lot




	file << "\n" << large_char(name) << " item_entries[10000]; // entries\n";
	file << "int iter = 0;\n\n";
	file << "\nint delete_entries[10000]; // entries that are to be removed\n";
	file << "int delete_iter = 0;\n\n";



	// Make entry by getting data through 'cin'



	file << "// Make entry\n";

	file << large_char(name) << " make_entry ()\n{\n";

	file << "	" << large_char(name) << " entry;\n\n";
	
	file << "	cout << \"\\n\";\n\n";

	file << "	int counter = 0;\n\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "	" << type( types[i] ) << " temp_" << i << "[10000] = {};\n\n";

			file << "	counter = 0;\n";

			// bool is treated as a string, to validate both  0 or 1  and  "true" or"false" 
			if ( type( types[i] ) == "bool" )
			{
				file << "	cout << \"Enter num. or val.-s you want to enter for \\'" << parameters[i] << "\\' of type \\'" << type( types[i] ) << "\\': \";\n";
				file << "	cin >> counter;\n\n";
				file << "	for ( int i=0; i<counter; i=i+1 )\n";
				file << "	{\n";
				file << "		string temp;\n";
				file << "		cout << \"Enter val. \" << i + 1 << \" ( 1 / 0 ) : \";\n";
				file << "		cin >> temp; // null val.-s do not pass this\n";
				file << "		if ( temp[0] == \'0\' or temp == \"false\" )\n";
				file << "			temp_" << i << "[i] = 0;\n";
				file << "		else";
				file << "			temp_" << i << "[i] = 1;\n";
				file << "		temp = \"\";\n";
				file << "	}\n\n";

				file << "	entry.set_" << remove_brackets( parameters[i] ) << "( temp_" << i << " );\n";
				file << "	entry.set_" << remove_brackets( parameters[i] ) << "_count ( counter );\n";				
			}
			else
			{
				file << "	cout << \"Enter num. or val.-s you want to enter for \\'" << parameters[i] << "\\' of type \\'" << type( types[i] ) << "\\': \";\n";
				file << "	cin >> counter;\n\n";
				file << "	for ( int i=0; i<counter; i=i+1 )\n";
				file << "	{\n";
				file << "		cout << \"Enter val. \" << i + 1;\n";
				if ( type( types[i] ) == "string" )
					file << "		cout << \" ( spaces not allowed )\";\n";
				file << "		cout << \": \";\n";
				file << "		cin >> temp_" << i << "[i]; // null val.-s do not pass this\n";
				file << "	}\n\n";

				file << "	entry.set_" << remove_brackets( parameters[i] ) << "( temp_" << i << " );\n";
				file << "	entry.set_" << remove_brackets( parameters[i] ) << "_count ( counter );\n";
			}
		}
		else
		{
			file << "	cout << \"Enter val. for \\'" << parameters[i] << "\\' of type \\'" << type( types[i] ) << "\\'";

			if ( type( types[i] ) == "bool" )
				file << " ( 1 / 0 )";
			if ( type( types[i] ) == "string" )
				file << " ( spaces not allowed )";

		 	file << ": \";\n\n";

			// bool is treated as a string, to validate both  0 or 1  and  "true" or "false" 
			if ( type( types[i] ) == "bool" )
			{
				file << "	string temp_string_" << i << ";\n";

				file << "	cin >> temp_string_" << i << ";\n\n";

				file << "	if ( temp_string_" << i << "[0] == \'0\' or temp_string_" << i << " == \"false\" )\n";
				file << "		entry.set_" << parameters[i] << "( 0 );\n";
				file << "	else";
				file << "		entry.set_" << parameters[i] << "( 1 );\n";
			}
			else
			{
				file << "	" << type( types[i] ) << " temp_" << type( types[i] ) << "_" << i << ";\n\n";

				file << "	cin >> temp_" << type( types[i] ) << "_" << i << ";\n";
	 
				file << "	entry.set_" << parameters[i] << "( temp_" << type( types[i] ) << "_" << i << " );\n";
			}
		}

		if ( i != num_parameters - 1 )
		file << "\n";
	}

	file << "\n	cout << \"\\n\\n\";\n\n";

	file << "	return entry;\n";

	file << "}\n\n";




	// Add an entry to item_entries[]




	file << "// Add entry\n";

	file << "void add_entry ( " << large_char(name) << " entry )\n{\n";
	file << "	item_entries[ iter ] = entry;\n";
	file << "	iter = iter +1;\n";
	file << "}\n\n\n";




	// Add entries to file - save  item_entries[]  into  class_entries  




	file << "// Add entries\n";

	file << "void add_entries ()\n{\n";

	file << "	ofstream entries;\n	entries.open(\"" << name << "_entries\");\n";
	file << "	entries.close();\n	entries.open(\"" << name << "_entries\");\n\n";

	file << "	entries << iter << \'\\n\';\n\n";

	file << "	for ( int i=0; i<num_parameters; i=i+1 )\n";
	file << "		entries << columns[i] << \" \";\n";
	file << "	entries << \"\\n\";\n\n";

	file << "	for ( int i=0; i<num_parameters; i=i+1 )\n";
	file << "		entries << types[i] << \" \";\n";
	file << "	entries << \"\\n\";\n\n";

	file << "	int size_of_temp;\n\n";
	file << "	for ( int i=0; i<iter; i=i+1 )\n";
	file << "	{\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "		" << type(types[i]) << " temp_" << i <<  "[10000];\n";

			file << "		item_entries[i].get_" << remove_brackets(parameters[i]) << "( temp_" << i << " );\n";

			file << "		size_of_temp = item_entries[i].get_" << remove_brackets(parameters[i]) << "_count();\n";
			file << "		entries << \"  \" << size_of_temp << \"  \";\n\n";

			file << "		for ( int i=0; i<size_of_temp; i=i+1 )\n";
			file << "			entries << temp_" << i << "[i] << \' \';\n";
			file << "		entries << \"  \";\n\n";
		}
		else
		{
			file << "		entries << item_entries[i].get_" << parameters[i] << "() << \" \";\n\n";
		}
	}

	file << "		if ( i != iter - 1)\n";
	file << "			entries << \'\\n\';\n";

	file << "	}\n";

	file << "\n	entries.close();\n";

	file << "}\n\n\n";




	// Get  class_entries  entries into  item_entries[]  




	file << "// Get entries\n";

	file << "void get_entries()\n{\n";

	file << "	fstream entries;\n	entries.open( \"" << name << "_entries\" );\n\n";

	file << "	entries >> iter;\n\n";

	file << "	for ( int i=0; i<num_parameters; i=i+1 )\n";
	file << "		entries >> columns[i];\n\n";

	file << "	for ( int i=0; i<num_parameters; i=i+1 )\n";
	file << "		entries >> types[i];\n\n";

	file << "	int counter;\n\n";

	file << "	for ( int i=0; i<iter; i=i+1 )\n	{\n";	

	for ( int i=0; i<num_parameters; i=i+1 )
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "		" << type( types[i] ) << " temp_" << i << "[10000] = {};\n\n";

			file << "		counter = 0;\n";
			file << "		entries >> counter;\n\n";
			file << "		for ( int i=0; i<counter; i=i+1 )\n";
			file << "		{\n";
			file << "			entries >> temp_" << i << "[i]; // null val.-s do not pass this\n";
			file << "		}\n\n";

			file << "		item_entries[i].set_" << remove_brackets( parameters[i] ) << "( temp_" << i << " );\n";
			file << "		item_entries[i].set_" << remove_brackets( parameters[i] ) << "_count ( counter );\n";
		}
		else
		{
			file << "		" << type( types[i] ) << " temp_" << type( types[i] ) << "_" << i << ";\n\n";

			file << "		entries >> temp_" << type( types[i] ) << "_" << i << ";\n";

			file << "		item_entries[i].set_" << parameters[i] << "( temp_" << type( types[i] ) << "_" << i << " );\n";
		}

	file << "	}\n\n";

	file << "	entries.close();\n";

	file << "}\n\n\n";



	// Check if a certain entry was removed



	file << "// Was removed\n";

	file << "bool is_in_delete_entries ( int a )\n{\n";

	file << "	for ( int i=0; i<delete_iter; i=i+1 )\n";

	file << "		if ( delete_entries[i] == a )\n";

	file << "			return true;\n\n";

	file << "	return false;\n";

	file << "}\n\n\n";





	// Show a certain entry




	file << "// Show entry\n";

	file << "void show_entry( int i )\n{\n";

	file << "	if ( i < 0 or i >= iter )\n";
	file << "	{\n";
	file << "		cout << \"Entry num. \'\" << i + 1 << \"\' is not valid.\\n\" ;\n";
	file << "		return;\n";
	file << "	}\n\n";

	file << "	if ( is_in_delete_entries(i) )\n";
	file << "	{\n";
	file << "		cout << \"Entry num. \'\" << i + 1 << \"\' was removed.\\n\" ;\n";
	file << "		return;\n";
	file << "	}\n\n";

	file << "	int size_of_temp;\n\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{

			file << "	" << type(types[i]) << " temp_" << i << "[10000];\n";

			file << "	item_entries[i].get_" << remove_brackets(parameters[i]) << "( temp_" << i << " );\n";

			file << "	size_of_temp = item_entries[i].get_" << remove_brackets(parameters[i]) << "_count();\n";
			file << "	cout << \"  [ size: \";\n";
			file << "	cout << size_of_temp << \" = ( \";\n\n";

			file << "	for ( int i=0; i<size_of_temp; i=i+1 )\n";
			file << "		cout << temp_" << i << "[i] << \' \';\n";
			file << "	cout << \") ]  \";\n\n";
		}
		else
		{
			file << "	cout << item_entries[i].get_" << parameters[i] << "() << \" \";\n\n";
		}

	}


	file << "	cout << \"\\n\";\n";

	file << "}\n\n";





	// Show columns




	file << "// Show column names ( modifiable )\n";
	file << "void show_columns ()\n{\n";
	file << "	cout << \"\\n\";\n";
	file << "	for ( int i=0; i<num_parameters; i=i+1 )\n";
	file << "		cout << columns[i] << \" \";\n";
	file << "	cout << \"\\n\";\n}\n\n";





	// Rename column





	file << "// Rename column\n";
	file << "void rename_column ( int a, string name )\n{\n";
	file << "	if ( columns[a][ columns[a].length() - 1] == \']\' )\n";
	file << "		columns[a] = name + \"[]\";\n";
	file << "	else\n";
	file << "		columns[a] = name;\n";
	file << "}\n\n";




	// Sort




	file << "// Sort\n";
	file << "void sort ( int i, int order )\n";
	file << "{\n";
	file << "	if ( order != 0 )\n";
	file << "		order = 1;\n\n";

	for ( int l=0; l<num_parameters; l=l+1 )
	{
		file << "	if ( i == " << l << " )\n";
		file << "	{\n";
		if ( last_char( parameters[l] ) == ']' )
		{
			file << "		for ( int a=0; a<iter-1; a=a+1 )\n";
			file << "			for ( int b=a+1; b<iter; b=b+1 )\n";
			file << "			{\n";
			file << "				if ( item_entries[a].get_" << remove_brackets( parameters[l] ) << "_count() <  item_entries[b].get_" << remove_brackets( parameters[l] ) << "_count() and order == 1 )\n";
			file << "				{\n";
			file << "					" << large_char( name ) << " copy = item_entries[a];\n";
			file << "					item_entries[a] = item_entries[b];\n";
			file << "					item_entries[b] = copy;\n";
			file << "				}\n\n";
			file << "				if ( item_entries[a].get_" << remove_brackets( parameters[l] ) << "_count() >  item_entries[b].get_" << remove_brackets( parameters[l] ) << "_count() and order == 0 )\n";
			file << "				{\n";
			file << "					" << large_char( name ) << " copy = item_entries[a];\n";
			file << "					item_entries[a] = item_entries[b];\n";
			file << "					item_entries[b] = copy;\n";
			file << "				}\n";
			file << "			}\n";
		}
		else
		{
			file << "		for ( int a=0; a<iter-1; a=a+1 )\n";
			file << "			for ( int b=a+1; b<iter; b=b+1 )\n";
			file << "			{\n";
			file << "				if ( item_entries[a].get_" <<  parameters[l]  << "() <  item_entries[b].get_" <<  parameters[l]  << "() and order == 1 )\n";
			file << "				{\n";
			file << "					" << large_char( name ) << " copy = item_entries[a];\n";
			file << "					item_entries[a] = item_entries[b];\n";
			file << "					item_entries[b] = copy;\n";
			file << "				}\n\n";
			file << "				if ( item_entries[a].get_" <<  parameters[l]  << "() >  item_entries[b].get_" <<  parameters[l]  << "() and order == 0 )\n";
			file << "				{\n";
			file << "					" << large_char( name ) << " copy = item_entries[a];\n";
			file << "					item_entries[a] = item_entries[b];\n";
			file << "					item_entries[b] = copy;\n";
			file << "				}\n";
			file << "			}\n";
		}
		file << "	}\n";
	}
	file << "}\n\n\n";






	// [ ']' + Enter ] to continue


	


	file << "// Show \"[ ']' + Enter ] to continue\"\n";
	file << "void enter()\n";
	file << "{\n";
	file << "	char enter;\n";
	file << "	cout << \"\\n[ \']\' + Enter ] to continue: \";\n";
	file << "	cin >> enter;\n";
	file << "	cout << \"\\n\";\n";
	file << "}\n\n";



	// Item ( Get entry / entries by property val. )



	file << "\nint shown_entries[100000]; // entries that were shown in  get_entry_item( item )  \n";
	file << "int shown_iter = 0;\n\n";

	file << "// Was shown\n";
	file << "bool shown( int a )\n";
	file << "{\n";
	file << "	for ( int i=0; i<shown_iter; i=i+1 )\n";
	file << "		if ( shown_entries[i] == a )\n";
	file << "			return true;\n";
	file << "	return false;\n";
	file << "}\n\n";

	// make only if we have numeric datatypes
	if ( have_numeric() )
	{
		file << "// Get entry item - for numeric datatypes\n";
		file << "void get_entry_item( long item )\n";
		file << "{\n";
		for ( int i=0; i<num_parameters; i=i+1 )
			if ( is_numeric(i) )
			{
				if ( last_char( parameters[i] ) == ']' )
				{
					file << "	for ( int i=0; i<iter; i=i+1 )\n";
					file << "	{\n";
					file << "		int size = item_entries[i].get_" << remove_brackets( parameters[i] ) << "_count();\n";
					file << "		for ( int a=0; a<size; a=a+1 )\n";
					file << "			if ( item_entries[i].get_" << remove_brackets( parameters[i] ) << "(a) == item and !shown(i) )\n";
					file << "			{\n";
					file << "				show_entry(i);\n";
					file << "				shown_entries[ shown_iter ] = i;\n";
					file << "				shown_iter = shown_iter + 1;\n";
					file << "			}\n\n";	
					file << "	}\n\n";
				}
				else 
				{
					file << "	for ( int i=0; i<iter; i=i+1 )\n";
					file << "		if ( item_entries[i].get_" << remove_brackets( parameters[i] ) << "() == item and !shown(i) )\n";
					file << "		{\n";
					file << "			show_entry(i);\n";
					file << "			shown_entries[ shown_iter ] = i;\n";
					file << "			shown_iter = shown_iter + 1;\n";
					file << "		}\n\n";				
				}
			}
		file << "	shown_iter = 0;\n";
		file << "}\n\n";
	}

	

	// make only if we have "string" datatype
	if ( have_datatype( "string" ) )
	{
		file << "// Get entry item - for \"string\" datatype\n";
		file << "void get_entry_item( string item )\n";
		file << "{\n";
		for ( int i=0; i<num_parameters; i=i+1 )
			if ( type( types[i] ) == "string" )
			{
				if ( last_char( parameters[i] ) == ']' )
				{
					file << "	for ( int i=0; i<iter; i=i+1 )\n";
					file << "	{\n";
					file << "		int size = item_entries[i].get_" << remove_brackets( parameters[i] ) << "_count();\n";
					file << "		for ( int a=0; a<size; a=a+1 )\n";
					file << "			if ( item_entries[i].get_" << remove_brackets( parameters[i] ) << "(a) == item and !shown(i) )\n";
					file << "			{\n";
					file << "				show_entry(i);\n";
					file << "				shown_entries[ shown_iter ] = i;\n";
					file << "				shown_iter = shown_iter + 1;\n";
					file << "			}\n\n";	
					file << "	}\n\n";
				}
				else 
				{
					file << "	for ( int i=0; i<iter; i=i+1 )\n";
					file << "		if ( item_entries[i].get_" << remove_brackets( parameters[i] ) << "() == item and !shown(i) )\n";
					file << "		{\n";
					file << "			show_entry(i);\n";
					file << "			shown_entries[ shown_iter ] = i;\n";
					file << "			shown_iter = shown_iter + 1;\n";
					file << "		}\n\n";				
				}
			}
		file << "	shown_iter = 0;\n";
		file << "}\n\n";
	}


	// make only if we have "char" datatype
	if ( have_datatype( "char" ) )
	{
		file << "// Get entry item - for \"char\" datatype\n";
		file << "void get_entry_item( char item )\n";
		file << "{\n";
		for ( int i=0; i<num_parameters; i=i+1 )
			if ( type( types[i] ) == "char" )
			{
				if ( last_char( parameters[i] ) == ']' )
				{
					file << "	for ( int i=0; i<iter; i=i+1 )\n";
					file << "	{\n";
					file << "		int size = item_entries[i].get_" << remove_brackets( parameters[i] ) << "_count();\n";
					file << "		for ( int a=0; a<size; a=a+1 )\n";
					file << "			if ( item_entries[i].get_" << remove_brackets( parameters[i] ) << "(a) == item and !shown(i) )\n";
					file << "			{\n";
					file << "				show_entry(i);\n";
					file << "				shown_entries[ shown_iter ] = i;\n";
					file << "				shown_iter = shown_iter + 1;\n";
					file << "			}\n\n";	
					file << "	}\n\n";
				}
				else 
				{
					file << "	for ( int i=0; i<iter; i=i+1 )\n";
					file << "		if ( item_entries[i].get_" << remove_brackets( parameters[i] ) << "() == item and !shown(i) )\n";
					file << "		{\n";
					file << "			show_entry(i);\n";
					file << "			shown_entries[ shown_iter ] = i;\n";
					file << "			shown_iter = shown_iter + 1;\n";
					file << "		}\n\n";				
				}
			}
		file << "	shown_iter = 0;\n";
		file << "}\n\n\n";
	}




	// Swap



	file << "// Swap entries\n";
	file << "void swap ( int a, int b )\n";
	file << "{\n";
	file << "	if ( a >= 0 and a < iter  and  b >= 0 and b < iter )\n";
	file << "	{\n";
	file << "		" << large_char( name ) << " copy = item_entries[a];\n";
	file << "		item_entries[a] = item_entries[b];\n";
	file << "		item_entries[b] = copy;\n";
	file << "	}\n";
	file << "	else\n";
	file << "		cout << \"Could not swap / move: invalid entry num.\\n\";\n";
	file << "}\n\n";




	// Move




	file << "// Move entries\n";
	file << "void move ( int entry_num, int direction, int iterations )\n";
	file << "{\n";
	file << "	int swap_entry_num;\n\n";
	file << "	if ( direction == 0 )\n";
	file << "	{\n";
	file << "		swap_entry_num = entry_num - iterations;\n";
	file << "		if ( swap_entry_num < 0)\n";
	file << "			swap_entry_num = 0;\n";
	file << "		for ( int i=entry_num; i>swap_entry_num; i=i-1 )\n";
	file << "			swap( i, i - 1 );\n";
	file << "	}\n\n";
	file << "	if ( direction == 1 )\n";
	file << "	{\n";
	file << "		swap_entry_num = entry_num + iterations;\n";
	file << "		if ( swap_entry_num >= iter)\n";
	file << "			swap_entry_num = iter - 1;\n";
	file << "		for ( int i=entry_num; i<swap_entry_num; i=i+1 )\n";
	file << "			swap( i, i + 1 );\n";
	file << "	}\n\n";
	file << "}\n";



	// Show entries


	file << "void show_entries()\n";
	file << "{\n";
	file << "	if ( iter == 0 )\n";
	file << "		return;\n\n";
	file << "	cout << \"Entries:\\n\";\n\n";
	file << "	show_columns();\n\n";
	file << "	for ( int i=0; i<iter; i=i+1 )\n";
	file << "	{\n";
	file << "		cout << \"(\" << i + 1 << \")   \";\n";
	file << "		show_entry( i );\n";
	file << "	}\n";
	file << "}\n";









	file << "\n\n";

	file << "int main()\n{\n";


	file << "	// Show datatype info\n";
	file << "	cout << \"Enter only valid datatypes for:\\n\";\n";
	file << "	item_entries[0].info();\n";
	file << "	enter();\n\n";


	file << "	// Get entry\n";
	file << "	get_entries();\n\n";


	file << "	// Operation choice\n";
	file << "	string choice = \"\";\n\n";

	// for now, it is done with a for
	file << "	// for now, it is done with a for\n";
	file << "	for ( int i=0; i<100000; i=i+1 )\n";

	//	file << "	while ( choice != \"exit\" )\n";
	file << "	{\n\n";

	file << "	";
	enter_cout( "\\n\\n" );

	file << "		cout << \"Operation num. \" << i + 1 << \" ( enter valid datatypes ) \\n\";\n";
	file << "	";
	
	// show codes for operations
	enter_cout( "Operations:\\n" );
	file << "	";
	enter_cout( "  1. Add entry       2. Show entry     3. Show entries - complete  4. Show entries  5. Remove entry\\n" );
	file << "	";
	enter_cout( "  6. Remove entries  7. Clear entries  8. Sort ( show / save )     9. Move          10. Swap\\n" );
	file << "	";
	enter_cout( "   or\\n" );
	file << "	";
	enter_cout( "  item. Show entries that have [item]    name. Name / Rename a column    save. Save    exit. Exit\\n" );

	file << "\n\n";

	file << "	";

	// codes for operations
	enter_cout( "\\nEnter your choice: " );
	file << "		cin >> choice;\n\n";

	file << "		if ( choice != \"1\" and choice != \"2\" and choice != \"3\" and choice != \"4\" and choice != \"5\" and choice != \"6\" and choice != \"7\" and choice != \"8\" and choice != \"9\" and choice != \"10\" and choice != \"item\" and choice != \"name\" and choice != \"save\" and choice != \"exit\" and choice != \"\" )\n";
	file << "		{\n";
	file << "			cout << \"Invalid Choice. Retry.\";\n";
	file << "			continue;\n";
	file << "		}\n\n";
	file << "		// Add entry\n";
	file << "		if ( choice == \"1\" )\n";
	file << "		{\n";
	file << "			" << large_char(name) << " entry;\n";
	file << "			entry = make_entry();\n";
	file << "			entry.info();\n";
	file << "			add_entry(entry);\n";
	file << "			add_entries();\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Show entry\n";
	file << "		if ( choice == \"2\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			int i;\n";
	file << "			cout << \"Enter num. of entry: \";\n";
	file << "			cin >> i;\n";
	file << "			show_columns();\n";
	file << "			show_entry(i - 1);\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Show entries - complete\n";
	file << "		if ( choice == \"3\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			show_entries();\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Show entries\n";
	file << "		if ( choice == \"4\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			int entry_iter;\n";
	file << "			cout << \"Stop with -1\\n\";\n";
	file << "			while ( entry_iter != -1 )\n";
	file << "			{\n";
	file << "				cout << \"Enter num. of entry: \";\n";
	file << "				cin >> entry_iter;\n\n";
	file << "				if ( entry_iter == -1 )\n";
	file << "					break;\n\n";
	file << "				show_entry( entry_iter - 1 );\n";
	file << "			}\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Remove entry\n";
	file << "		if ( choice == \"5\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			show_entries();\n";
	file << "			int i;\n";
	file << "			cout << \"Enter num. of entry: \";\n";
	file << "			cin >> i;\n\n";
	file << "			cout << \"\\nEntry that was deleted\\n\";\n";
	file << "			show_columns();\n";
	file << "			delete_entries[ delete_iter ] = i - 1;\n";
	file << "			delete_iter = delete_iter + 1;\n\n";
	file << "			add_entries();\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Remove entries\n";
	file << "		if ( choice == \"6\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			show_entries();\n";
	file << "			int entry_iter;\n";
	file << "			cout << \"Stop with -1\\n\";\n";
	file << "			while ( entry_iter != -1 )\n";
	file << "			{\n";
	file << "				cout << \"Enter num. of entry to remove: \";\n";
	file << "				cin >> entry_iter;\n\n";
	file << "				if ( entry_iter == -1 )\n";
	file << "					break;\n\n";
	file << "				delete_entries[ delete_iter ] = entry_iter;\n";
	file << "				delete_iter = delete_iter + 1;\n";
	file << "			}\n";
	file << "			cout << \"Entries that were deleted\\n\";\n";
	file << "			show_columns();\n";
	file << "			for ( int i=0; i<delete_iter; i=i+1 )\n";
	file << "				show_entry( delete_iter );\n\n";
	file << "			add_entries();\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Clear entries\n";
	file << "		if ( choice == \"7\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			iter = 0;\n";
	file << "			add_entries();\n";
	file << "			cout << \"Entries were cleared.\\n\";\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Sort ( show / save )\n";
	file << "		if ( choice == \"8\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			cout << \"1. \\'Show\\'  but not save entries       \";\n";
	file << "			cout << \"2. \\'Save\\'  but not show entries\\n\\n\";\n";
	file << "			cout << \"Enter your choice: \";\n\n";
	file << "			int sort_choice;\n";
	file << "			cin >> sort_choice;\n\n";
	file << "			if ( sort_choice != 1 and sort_choice != 2 )\n";
	file << "				cout << \"Sorting aborted.\\n\";\n";
	file << "			else\n";
	file << "			{\n";
	file << "				" << large_char( name ) << " copy_items[10000];\n";
	file << "				for ( int i=0; i<num_parameters; i=i+1 )\n";
	file << "					copy_items[i] = item_entries[i];\n\n";
	file << "				cout << \"Enter num. of column you want to sort by: \";\n";
	file << "				int column_num;\n";
	file << "				cin >> column_num;\n\n";
	file << "				if ( column_num > num_parameters )\n";
	file << "					cout << \"Column num. is not valid. Sorting aborted.\\n\";\n";
	file << "				else\n";
	file << "				{\n";
	file << "					cout << \"Enter order ( 0. asc  1. desc ) : \";\n";
	file << "					int order;\n";
	file << "					cin >> order;\n\n";
	file << "					if ( sort_choice == 1 )\n";
	file << "					{\n";
	file << "						sort( column_num - 1, order );\n";
	file << "						show_columns();\n";
	file << "						for ( int i=0; i<iter; i=i+1 )\n";
	file << "							show_entry(i);\n";
	file << "						for ( int i=0; i<iter; i=i+1 )\n";
	file << "							item_entries[i] = copy_items[i];\n";
	file << "					}\n\n";
	file << "					if ( sort_choice == 2 )\n";
	file << "					{\n";
	file << "						sort( column_num - 1, order );\n";
	file << "						add_entries();\n";
	file << "						cout << \"Entries were sorted and saved.\\n\";\n";
	file << "					}\n";
	file << "				}\n";
	file << "			}\n\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Move\n";
	file << "		if ( choice == \"9\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			int entry_num;\n";
	file << "			cout << \"Enter entry num. you want to move: \";\n";
	file << "			cin >> entry_num;\n";
	file << "			int direction;\n";
	file << "			cout << \"Enter direction ( 0. asc  1. desc ): \";\n";
	file << "			cin >> direction;\n";
	file << "			if ( !( direction == 0 or direction == 1 ) )\n";
	file << "				cout << \"Move aborted: invalid direction.\\n\";\n";
	file << "			else\n";
	file << "			{\n";
	file << "				int iterations;\n";
	file << "				cout << \"Enter how many times you want to move: \";\n";
	file << "				cin >> iterations;\n";
	file << "				move ( entry_num - 1, direction, iterations );\n";
	file << "				add_entries();\n";
	file << "				cout << \"Entry was moved.\\n\";\n";
	file << "			}\n\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Swap\n";
	file << "		if ( choice == \"10\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			int a, b;\n";
	file << "			cout << \"Enter entry num. or entry 1 you want to swap: \";\n";
	file << "			cin >> a;\n";
	file << "			cout << \"Enter entry num. or entry 2 you want to swap: \";\n";
	file << "			cin >> b;\n\n";
	file << "			swap( a - 1, b - 1 );\n\n";
	file << "			add_entries();\n";
	file << "			cout << \"Entries were swapped and saved.\\n\";\n\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Show entries that have [item]\n";
	file << "		if ( choice == \"item\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "			{\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "				continue;\n";
	file << "			}\n\n";
	file << "			string type;\n";
	// have to check for each possibility, since we do not define for a datatype we do not have
	if ( have_numeric() and have_datatype( "char" ) and have_datatype( "string" ) )
	{
		file << "			cout << \"Enter type of parameter ( 0. numeric   1. text ): \";\n";
		file << "			cin >> type;\n\n";
		file << "			if ( type == \"0\" )\n";
		file << "			{\n";
		file << "				long item_parameter;\n";
		file << "				cout << \"Get item by parameter val.: \";\n";
		file << "				cin >> item_parameter;\n";
		file << "				show_columns();\n\n";
		file << "				get_entry_item( item_parameter );\n";
		file << "			}\n";
		file << "			else\n";
		file << "			{\n";
		file << "				string item_parameter = \"\";\n";
		file << "				cout << \"Get item by parameter val.: \";\n";
		file << "				cin >> item_parameter;\n";
		file << "				show_columns();\n\n";
		file << "				if ( item_parameter.length() == 1 )\n";
		file << "					get_entry_item( item_parameter[0] );\n";
		file << "				else\n";
		file << "					get_entry_item( item_parameter );\n";
		file << "			}\n";
	}
	if ( !have_numeric() and have_datatype( "char" ) and have_datatype( "string" ) )
	{
		file << "			string item_parameter = \"\";\n";
		file << "			cout << \"Get item by parameter val.: \";\n";
		file << "			cin >> item_parameter;\n";
		file << "			show_columns();\n\n";
		file << "			if ( item_parameter.length() == 1 )\n";
		file << "				get_entry_item( item_parameter[0] );\n";
		file << "			else\n";
		file << "				get_entry_item( item_parameter );\n";
	}
	if ( have_numeric() and !have_datatype( "char" ) and have_datatype( "string" ) )
	{
		file << "			cout << \"Enter type of parameter ( 0. numeric   1. text ): \";\n";
		file << "			cin >> type;\n\n";
		file << "			if ( type == \"0\" )\n";
		file << "			{\n";
		file << "				long item_parameter;\n";
		file << "				cout << \"Get item by parameter val.: \";\n";
		file << "				cin >> item_parameter;\n";
		file << "				show_columns();\n\n";
		file << "				get_entry_item( item_parameter );\n";
		file << "			}\n";
		file << "			else\n";
		file << "			{\n";
		file << "				string item_parameter = \"\";\n";
		file << "				cout << \"Get item by parameter val.: \";\n";
		file << "				cin >> item_parameter;\n";
		file << "				show_columns();\n\n";
		file << "				get_entry_item( item_parameter );\n";
		file << "			}\n";
	}
	if ( have_numeric() and have_datatype( "char" ) and !have_datatype( "string" ) )
	{
		file << "			cout << \"Enter type of parameter ( 0. numeric   1. text ): \";\n";
		file << "			cin >> type;\n\n";
		file << "			if ( type == \"0\" )\n";
		file << "			{\n";
		file << "				long item_parameter;\n";
		file << "				cout << \"Get item by parameter val.: \";\n";
		file << "				cin >> item_parameter;\n";
		file << "				show_columns();\n\n";
		file << "				get_entry_item( item_parameter );\n";
		file << "			}\n";
		file << "			else\n";
		file << "			{\n";
		file << "				string item_parameter = \"\";\n";
		file << "				cout << \"Get item by parameter val.: \";\n";
		file << "				cin >> item_parameter;\n";
		file << "				show_columns();\n\n";
		file << "				get_entry_item( item_parameter[0] );\n";
		file << "			}\n";
	}
	if ( have_numeric() and !have_datatype( "char" ) and !have_datatype( "string" ) )
	{
		file << "			long item_parameter;\n";
		file << "			cout << \"Get item by parameter val.: \";\n";
		file << "			cin >> item_parameter;\n";
		file << "			show_columns();\n\n";
		file << "			get_entry_item( item_parameter );\n";
	}
	if ( !have_numeric() and have_datatype( "char" ) and !have_datatype( "string" ) )
	{
		file << "			long item_parameter = \"\";\n";
		file << "			cout << \"Get item by parameter val.: \";\n";
		file << "			cin >> item_parameter;\n";
		file << "			show_columns();\n\n";
		file << "			get_entry_item( item_parameter[0] );\n";
	}
	if ( !have_numeric() and !have_datatype( "char" ) and have_datatype( "string" ) )
	{
		file << "			long item_parameter = \"\";\n";
		file << "			cout << \"Get item by parameter val.: \";\n";
		file << "			cin >> item_parameter;\n";
		file << "			show_columns();\n\n";
		file << "			get_entry_item( item_parameter );\n";
	}
	file << "\n			enter();\n";
	file << "		}\n\n";

	file << "		// Name / rename a column\n";
	file << "		if ( choice == \"name\" )\n";
	file << "		{\n";
	file << "			int num_column;\n";
	file << "			string name;\n";
	file << "			cout << \"Enter num. of column you want to rename: \";\n";
	file << "			cin >> num_column;\n\n";
	file << "			cout << \"Renaming column \" << num_column << \" of type \'\" << types[num_column - 1] << \"\', var. name \'\" << parameters[num_column - 1] << \"\' and previous name \'\" << columns[num_column - 1] << \"\' to: \";\n";
	file << "			cin >> name;\n\n";
	file << "			rename_column( num_column - 1, name );\n\n";
	file << "			add_entries();\n";
	file << "			enter();\n";
	file << "		}\n\n";

	file << "		// Save\n";
	file << "		if ( choice == \"save\" )\n";
	file << "		{\n";
	file << "			add_entries();\n";
	file << "			cout << \"Entries were saved (they are by default when any modifications are made).\";\n";
	file << "			enter();\n";
	file << "		}\n\n";


	file << "		// Exit\n";
	file << "		if ( choice == \"exit\" )\n";
	file << "			break;\n\n";


	file << "		choice = \"\";\n";
	file << "\n	}\n\n";



	// save the file
	file << "	// Save\n";
	file << "	add_entries();\n\n";



	// Make entries file



	ofstream item_file;
	string item_file_name = name + "_entries";
	item_file.open( item_file_name );
	item_file << "0\n";
	for ( int i=0; i<num_parameters; i=i+1 )
		item_file << parameters[i] << " ";
	item_file.close();


	file << "	return 0;\n";
	file << "}\n";
	file.close();
}


// gets your choice
int get_choice()
{
	cout << "Make class: \n";
	cout << "  1. Explicitly define each datatype         ( advanced )\n";
	cout << "  2. Enter data and datatype will be defined (   easy   )\n\n";

	string choice;
	cout << "Choice ( 1 / 2 ): ";
	getline( cin, choice );

	if ( choice == "1" )
		return 1;
	if ( choice == "2" )
		return 2;

	cout << "( info ) Choice not valid. Retry.\n\n";
	return 0;
}



int main ()
{

	int choice = 0;

	while ( choice == 0 )
		choice = get_choice();


	if ( choice == 1 )
		get_data_1( name, parameters, types, num_parameters );
	if ( choice == 2 )
		get_data_2( name, parameters, types, num_parameters );

	set_data( name, parameters, types, num_parameters );





	cout << "\n\nClass is complete.\n\n";


	return 0;

}
