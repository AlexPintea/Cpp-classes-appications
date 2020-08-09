#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

ofstream file;
fstream entry_files;

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


// filenames of entry files
string entry_files_strings[10000];
int files_iter = 0;

// get  entry_files  filenames into  entry_files_strings[]  
void get_entry_files() 
{
	entry_files.open( "entry_files" );

	entry_files >> files_iter;

	for ( int i=0; i<files_iter; i=i+1 )
		entry_files >> entry_files_strings[i];

	entry_files.close();
}

// save  entry_files_strings[]  into   entry_files  
void set_entry_files( string name ) 
{
	entry_files.open( "entry_files" );
	entry_files.close();
	entry_files.open( "entry_files" );

	entry_files << files_iter + 1 << "\n";

	for ( int i=0; i<files_iter; i=i+1 )
		entry_files << entry_files_strings[i] << " ";
	entry_files << name;

	entry_files.close();
}

// edit a class file
void edit_class_file()
{
	entry_files.open( "entry_files" );

	cout << "Entry Files:\n";

	for ( int i=0; i<files_iter; i=i+1 )
		cout << i + 1 << ". " << entry_files_strings[i] << "  ";

	cout << "\n\n";

	int choice;
	cout << "Enter num. of file you want to edit: ";
	cin >> choice;
	cout << "\n\n";


	string entry_file = entry_files_strings[ choice - 1 ];




	entry_files.close();
}



// make a class file
void make_class_file()
{
	


	// Getting data




	cout << "Enter a filename that does not exist in this folder.\n";

	cout << "Name: ";
	std::getline(cin, name);
	std::getline(cin, name);



	// save file name in  entry_files
	set_entry_files( name );



	filename = name + ".cpp";
	cout << "You are editing: " << filename << "\n\n";

	file.open(filename);

	cout << "Enter num. or parameters: ";
	cin >> num_parameters;
	cout << "\n\n";
	
	cout << "Do not enter empty variable names or types.\n";

	cout << "Parameters:\n\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		string parameter;
		int attempts = 0;

		cout << "Name of parameter " << i + 1 << ": ";
		getline(cin, parameter);

		while ( is_property_name_taken ( parameter ) )
		{
			cout << "Parameter name: \"" << remove_brackets( parameter ) << "\" is taken.\n";

			cout << "Name of parameter " << i + 1 << ": ";
			getline(cin, parameter);
		}

		parameters[i] = parameter;

		if ( i ==0 )
			getline(cin, parameters[i]);

		replace_space( parameters[i] );
		cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool\n";
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

	file << "int types[" << num_parameters + 1 << "] = { ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << types[i];
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
					file << "\'\'";
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

	file << "\n		 this->is_empty = true;\n";
	
	file << "	}\n\n";



	// Getters 



	file << "\n	// Getters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "	void get_" << remove_brackets( parameters[i] ) << "";
			file << "( " << type( types[i] ) << " dest[] ) { copy( this->" << remove_brackets( parameters[i] ) << ", dest ); };\n";
		}
		else
		{
			file << "	" << type( types[i] ) << " get_" << remove_brackets( parameters[i] ) << "";
			file << "() { return this->" << parameters[i] << "; };\n";
		}
	}
	
	file << "\n	bool get_is_empty() { return this->is_empty; }\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			file << "\n	int get_" << remove_brackets( parameters[i] ) << "_count() { return this->" << remove_brackets( parameters[i] ) << "_count; }\n";
	}



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
			file << "	void set_" << remove_brackets( parameters[i] ) << "( " << type( types[i] );
			file << " data[] ) { copy( data, this->" << remove_brackets( parameters[i] ) << " );";
			file << " this->is_empty = false; ";
			file << " };\n";
		}
		else
		{
			file << "	void set_" << parameters[i] << "( " << type( types[i] );
			file << " data ) { this->" << parameters[i] << " = data;";
			file << " this->is_empty = false; ";
			file << " };\n";
		}
	}
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			file << "\n	void set_" << remove_brackets( parameters[i] ) << "_count( int data ) { this->" << remove_brackets( parameters[i] ) << "_count = data; }\n";
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




	file << "\n" << large_char(name) << " item_entries[10000];\n";
	file << "int iter = 0;\n\n";
	file << "\nint delete_entries[10000]; // the entries that are to be removed\n";
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
			file << "	" << type( types[i] ) << " temp[10000] = {};\n\n";

			file << "	counter = 0;\n";
			file << "	cout << \"Enter num. or val.-s you want to enter for \\'" << parameters[i] << "\\' of type \\'" << type( types[i] ) << "\\': \";\n";
			file << "	cin >> counter;\n\n";
			file << "	for ( int i=0; i<counter; i=i+1 )\n";
			file << "	{\n";
			file << "		cout << \"Enter val. \" << i + 1 << \": \";\n";
			file << "		cin >> temp[i]; // null val.-s do not pass this\n";
			file << "	}\n\n";

			file << "	entry.set_" << remove_brackets( parameters[i] ) << "( temp );\n";
			file << "	entry.set_" << remove_brackets( parameters[i] ) << "_count ( counter );\n";
		}
		else
		{
			file << "	cout << \"Enter val. for \\'" << parameters[i] << "\\' of type \\'" << type( types[i] ) << "\\'";

			if ( type( types[i] ) == "bool" )
				file << " ( 1 / 0 )";

		 	file << ": \";\n\n";
			file << "	" << type( types[i] ) << " temp_" << type( types[i] ) << ";\n\n";

			file << "	cin >> temp_" << type( types[i] ) << ";\n";
 
			file << "	entry.set_" << parameters[i] << "( temp_" << type( types[i] ) << " );\n";
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

	file << "	for ( int i=0; i<iter; i=i+1 )\n";
	file << "	{\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "		" << type(types[i]) << " temp[10000];\n";

			file << "		item_entries[i].get_" << remove_brackets(parameters[i]) << "( temp );\n";

			file << "		int size_of_temp = item_entries[i].get_" << remove_brackets(parameters[i]) << "_count();\n";
			file << "		entries << \"  \" << size_of_temp << \"  \";\n\n";

			file << "		for ( int i=0; i<size_of_temp; i=i+1 )\n";
			file << "			entries << temp[i] << \' \';\n";
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

	file << "	int counter;\n\n";

	file << "	for ( int i=0; i<iter; i=i+1 )\n	{\n";	

	for ( int i=0; i<num_parameters; i=i+1 )
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "		" << type( types[i] ) << " temp[10000] = {};\n\n";

			file << "		counter = 0;\n";
			file << "		entries >> counter;\n\n";
			file << "		for ( int i=0; i<counter; i=i+1 )\n";
			file << "		{\n";
			file << "			entries >> temp[i]; // null val.-s do not pass this\n";
			file << "		}\n\n";

			file << "		item_entries[i].set_" << remove_brackets( parameters[i] ) << "( temp );\n";
			file << "		item_entries[i].set_" << remove_brackets( parameters[i] ) << "_count ( counter );\n";
		}
		else
		{
			file << "		" << type( types[i] ) << " temp_" << type( types[i] ) << ";\n\n";

			file << "		entries >> temp_" << type( types[i] ) << ";\n";

			file << "		item_entries[i].set_" << parameters[i] << "( temp_" << type( types[i] ) << " );\n";
		}

	file << "	}\n";

	file << "	entries.close();\n";

	file << "}\n\n\n";



	// Check if a certain entry is to be removed ( done when you save = when you exit )



	file << "// Is to be removed\n";

	file << "bool is_in_delete_entries (int a)\n{\n";

	file << "	for ( int i=0; i<delete_iter; i=i+1 )\n";

	file << "		if ( delete_entries[i] == a )\n";

	file << "			return true;\n\n";

	file << "	return false;\n";

	file << "}\n\n\n";





	// Show a certain entry





	file << "// Show entry\n";

	file << "void show_entry( int i )\n{\n";

	file << "	if ( i >= iter )\n";
	file << "	{\n";
	file << "		cout << \"Entry num. \'\" << i + 1 << \"\' is not valid.\\n\" ;\n";
	file << "		return;\n";
	file << "	}\n";

	file << "	if ( is_in_delete_entries(i) )\n";
	file << "	{\n";
	file << "		cout << \"Entry num. \'\" << i + 1 << \"\' is to be removed.\\n\" ;\n";
	file << "		return;\n";
	file << "	}\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "		" << type(types[i]) << " temp[10000];\n";

			file << "		item_entries[i].get_" << remove_brackets(parameters[i]) << "( temp );\n";

			file << "		int size_of_temp = item_entries[i].get_" << remove_brackets(parameters[i]) << "_count();\n";
			file << "		cout << \"  \" << size_of_temp << \"  \";\n\n";

			file << "		for ( int i=0; i<size_of_temp; i=i+1 )\n";
			file << "			cout << temp[i] << \' \';\n";
			file << "		cout << \"  \";\n\n";
		}
		else
		{
			file << "		cout << item_entries[i].get_" << parameters[i] << "() << \" \";\n\n";
		}

	}


	file << "	cout << \"\\n\";\n";

	file << "\n}\n\n";








	file << "\n\n";

	file << "int main()\n{\n";

	file << "	get_entries();\n\n";

	file << "	string choice = \"\";\n\n";

	// for now, it is done with a for
	file << "	for ( int i=0; i<100000; i=i+1 )\n";

//	file << "	while ( choice != \"exit\" )\n";
	file << "	{\n";

	file << "	";
	enter_cout( "\\n\\n" );

	file << "		cout << \"Operation num. \" << i + 1 << \"\\n\";\n";
	file << "	";
	
	// show codes for operations
	enter_cout( "Operations:\\n" );

	file << "	";
	enter_cout( "	1. Add entry\\n" );
	file << "	";
	enter_cout( "	2. Show entry\\n" );
	file << "	";
	enter_cout( "	3. Show entries - complete\\n" );
	file << "	";
	enter_cout( "	4. Show entries\\n" );
	file << "	";
	enter_cout( "	5. Remove entry\\n" );
	file << "	";
	enter_cout( "	6. Remove entries\\n" );
	file << "	";
	enter_cout( "	7. Clear entries\\n" );
	file << "	";
	enter_cout( "	exit. Exit\\n" );

	file << "\n\n";

	file << "	";

	// codes for operations
	enter_cout( "\\nEnter your choice: " );
	file << "		cin >> choice;\n\n";

	file << "		if ( choice == \"1\" )\n";
	file << "		{\n";
	file << "			" << large_char(name) << " entry;\n";
	file << "			entry = make_entry();\n";
	file << "			entry.info();\n";
	file << "			add_entry(entry);\n";
	file << "		}\n\n";

	file << "		if ( choice == \"2\" )\n";
	file << "		{\n";
	file << "			int i;\n";
	file << "			cout << \"Enter num. of entry: \";\n";
	file << "			cin >> i;\n";
	file << "			show_entry(i - 1);\n";
	file << "		}\n\n";

	file << "		if ( choice == \"3\" )\n";
	file << "		{\n";
	file << "			if ( iter == 0 )\n";
	file << "				cout << \"Entries are empty.\\n\";\n";
	file << "			else\n";
	file << "				for ( int i=0; i<iter; i=i+1 )\n";
	file << "					show_entry(i);\n";
	file << "		}\n\n";

	file << "		if ( choice == \"4\" )\n";
	file << "		{\n";
	file << "			int int_entries;\n";
	file << "			cout << \"Enter num.-s or entries ( 142, 1542 etc. ): \";\n";
	file << "			cin >> int_entries;\n\n";
	file << "			int digits[10], num = 0;\n";
	file << "			while ( int_entries != 0 )\n";
	file << "			{\n";
	file << "				digits[ num ] = int_entries % 10;\n";
	file << "				num = num + 1;\n";
	file << "				int_entries = int_entries / 10;\n";
	file << "			}\n\n";
	file << "			for ( int i=num-1; i>=0; i=i-1 )\n";
	file << "				show_entry( digits[i] - 1 );\n";
	file << "		}\n\n";


	file << "		if ( choice == \"5\" )\n";
	file << "		{\n";
	file << "			int i;\n";
	file << "			cout << \"Enter num. of entry: \";\n";
	file << "			cin >> i;\n";
	file << "			delete_entries[ delete_iter ] = i - 1;\n";
	file << "			delete_iter = delete_iter + 1;\n";
	file << "			cout << \"Entry is to be deleted when you \\'exit\\'.\";\n";
	file << "		}\n\n";


	file << "		if ( choice == \"6\" )\n";
	file << "		{\n";
	file << "			int int_entries;\n";
	file << "			cout << \"Enter num.-s or entries ( 142, 1542 etc. ): \";\n";
	file << "			cin >> int_entries;\n\n";
	file << "			while ( int_entries != 0 )\n";
	file << "			{\n";
	file << "				delete_entries[ delete_iter ] = int_entries % 10 - 1;\n";
	file << "				delete_iter = delete_iter + 1;\n";
	file << "				int_entries = int_entries / 10;\n";
	file << "			}\n";
	file << "			cout << \"Entries are to be deleted when you \\'exit\\'.\";\n";
	file << "		}\n\n";

	file << "		if ( choice == \"7\" )\n";
	file << "		{\n";
	file << "			iter = 0;\n";
	file << "			cout << \"Entries are to be deleted when you \\'exit\\'.\";\n";
	file << "		}\n\n";


	file << "		if ( choice == \"exit\" )\n";
	file << "		{\n";
	file << "			break;\n";
	file << "		}\n\n";
	file << "		choice = \"\";\n";
	file << "\n	}\n\n";

	// save the file
	file << "	add_entries();\n\n";

	file << "	return 0;\n";
	file << "\n}\n";
	file.close();
}






int main ()
{
	get_entry_files();

	string choice = "";

	cout << "Operations:\n\n";

	cout << "1. Make class file\n";
	cout << "2. Edit a class file\n";
	cout << "exit. Exit\n\n";

	cout << "Enter your choice: ";

	cin >> choice;

	if ( choice == "1" )
		make_class_file();

	if ( choice == "2" )
		edit_class_file();

	return 0;
}

