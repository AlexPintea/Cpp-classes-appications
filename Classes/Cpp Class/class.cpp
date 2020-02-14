#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

ofstream file;

int num_parameters;

string name, filename = "";
string parameters[100];
string types[100];





// det length of not primry type
// info sa fie cu ce are val.-s
// getteri la arr sa fie void


int length (string a)
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}


int length ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
}

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

void replace_space (string &a)
{
	for (int i=0; i<a.length(); i=i+1)
		if ( a[i] == ' ' )
			a[i] = '_';
}

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

string large_char (string a)
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}

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

string brackets ( string a )
{
	a = remove_brackets (a);
	
	a = a + "[]";

	return a;
}

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

void make_length ( string type_of_variable )
{
	file << "\n	int length ( ";
	
	file << type( type_of_variable ) << " data[] )\n	{\n";

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

void make_copy ( string type_of_variable )
{
	file << "	void copy ( ";

	file << type( type_of_variable ) << " source[], " << type( type_of_variable ) << " dest[] )\n	{\n";

	file << "		for ( int i=0; i<length(source); i=i+1)\n			dest[i] = source[i];\n	}\n\n";
}

char last_char ( string a )
{
	return a[ length(a) - 1 ];
}

int main ()
{
	cout << "Enter a filename that does not exist in this folder.\n";

	cout << "Name: ";
	std::getline(cin, name);


	filename = name + ".cpp";
	cout << "You are editing: " << filename << "\n\n";

	file.open(filename);

	file << "#include <string>\n#include <string.h>\n#include <iostream>\n\nusing namespace std;\n\n";

	file << "class " << large_char(name) << " {\n";

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
		cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom (enter it now)\n";
		cout << "Type of parameter " << i + 1 << ": ";
		getline(cin, types[i]);
		replace_space( types[i] );
		cout << "\n";
	}

	file << "\n	// \"" << large_char(name) << "\" has parameters: ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << parameters[i];

		if ( i != num_parameters - 1 )
			file << ",";
		file << " ";
	}

	file << "\n\n	// Parameters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "	" << type( types[i] ) << " " << parameters[i] << ";\n";
	}

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			make_length( types[i] );
	}

	file << "\n\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
			make_copy( types[i] );
	}

	file << "\n  public:\n\n";

	
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
			file << "		copy( {}, this->" << remove_brackets( parameters[i] ) << " );\n";
	}
	
	file << "	}\n\n";


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
	
	file << "	}\n\n";


 
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
	




	file << "\n";

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






	file << "\n	// Setters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		if ( last_char( parameters[i] ) == ']' )
		{
			file << "	void set_" << remove_brackets( parameters[i] ) << "( " << type( types[i] );
			file << " data[] ) { copy( data, this->" << remove_brackets( parameters[i] ) << " ); };\n";
		}
		else
		{
			file << "	void set_" << parameters[i] << "( " << type( types[i] );
			file << " data ) { this->" << parameters[i] << " = data; };\n";
		}
	}


	file << "\n";

	file << "	void set ( ";

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
	
	file << "	}\n\n";

	file << "	// Info:\n";

	file << "	void info()\n	{\n";

	file << "		cout << \"\\nclass " << large_char(name) << " \"" << " << \'{\'" <<  " << \'\\n\';";

	file << "\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "		cout << \"	" << type( types[i] ) << "\" << \' \' << \"" << parameters[i] << "\" << \'\\n\';";
		file << "\n";
	}
	
	file << "	 	cout << " << "\'}\'" <<  " << \"\\n\\n\";";


	file << "\n";

	file << "	}\n\n";

	file << "};";




//	file << "\n\n";

//	file << "int main()\n{\n";

	

	file.close();

	return 0;
}

