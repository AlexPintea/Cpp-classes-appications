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
	cout << "\n";

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

	cout << endl;

	if ( is_bool(a) )
		return false;

	// if your string is actually a datatype
	// if ( a == "int" or a == "double" or a == "char" or a == "bool" )
		// return false;

	return true;
}





// get data 1
void get_data_1( string &name, string parameters[], string types[], int &num_parameters )
{
	cout << "Enter a filename that does not exist in this folder.\n";

	cout << "Name: ";
	std::getline(cin, name);

	replace_space( name );

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

	replace_space( name );

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






// set the data into our cpp file
void set_data( string name, string parameters[], string types[], int num_parameters )
{

	filename = name + ".cpp";
	file.open(filename);

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

	file << "\n		this->is_empty = false;\n";
	
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
