#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

fstream num;

int num_parameters;

string name, filename = "";
string parameters[100];
string types[100];

// a class in cpp
class Square{ 
	int l;
  public:
	void set_l(int a) { l=a; };
	int get_l() { return l; };
};

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

string type(string a)
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
		return "boolean";
	
	return a;
}

int main ()
{
	ofstream file;

	cout << "Enter name: ";
	std::getline(cin, name);



	// find id
	num.open("num.txt");
	int id;
	num >> id;
	num.close();
	// empties "num.txt"
	num.open("num.txt", std::ofstream::out | std::ofstream::trunc);
	num.close();
	// reopens "num.txt" and increases the id in it
	num.open("num.txt");
	num << id + 1;
	num.close();



	filename = name + "_" + int_string( id ) + ".cpp";
	cout << "You are editing: " << filename << "\n\n";

	file.open(filename);

	file << "#include <string>\n#include <string.h>\n#include <iostream>\n\n\n";

	file << "class " << name << " {\n";

	cout << "Enter num. or parameters: ";
	cin >> num_parameters;
	cout << "\n\n";
	
	cout << "Parameters:\n\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		cout << "Name of parameter " << i + 1 << ": ";
		getline(cin, parameters[i]);

		if ( i ==0 )
			getline(cin, parameters[i]);

		replace_space( parameters[i] );
		cout << "1. int  2. float  3. double  4. char  5. string  6. long  7. bool   or   custom (enter it now)\n";
		cout << "Type of parameter " << i + 1 << ": ";
		getline(cin, types[i]);
		replace_space( types[i] );
		cout << "\n";
	}

	file << "\n	// \"" << name << "\" has parameters: ";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << parameters[i] << " ";
	}

	file << "\n\n	// Parameters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "	" << type( types[i] ) << " " << parameters[i] << ";\n";
	}

	file << "\n  public:\n\n	// Getters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "	" << type( types[i] ) << " get_" << parameters[i] << "() { return " << parameters[i] << "; };\n";
	}
	

	file << "\n	// Setters:\n";

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		file << "	void set_" << parameters[i] << "( " << type( types[i] ) << " data ) { " << parameters[i] << " = data; };\n";
	}

	file << "};";
	file.close();

	return 0;
}

