#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// length of a string[]
int length( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
		i=i+1;

	return i;
}


// is in string[]
bool is_in_strings ( string words[], string word )
{
	int size = length( words );

	for ( int i=0; i<size; i=i+1 )
		if ( word == words[i] )
			return true;

	return false;
}

// to continue
void continues ()
{
	char chars;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> chars;
	cout << "\n";

	string empty; // to continue
	getline( cin, empty );
}

// makes a[0] into uppercase, if not already
string large_char (string a)
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}




string part;
string your_part;
string main_part = "\nint main ()\n{\n\n	your_cod();\n\n	int i=0;\n	while ( choice != \"exit\" )\n		get_choice( i );\n\n	cout << \"\\nExited.\\n\";\n	return 0;\n}";

void get_parts()
{
	part = "";
	your_part = "void your_cod ()\n";

	ifstream f;
	f.open( "cod.cpp" );

	string temp;

	// gets part until your cod
	while ( getline( f, temp ) )
	{
		if ( temp != "void your_cod ()" )
			part = part + temp + "\n";
		else
			break;
	}

	// gets your cod
	while ( getline( f, temp ) )
	{
		if ( temp != "	// your cod ( do not remove this comment. type only above it in your_cod () )" )
			your_part = your_part + temp + "\n";
		else
			break;
	}

//	your_part = your_part + "\n	// your cod ( do not remove this comment. type only above it in your_cod () )\n}\n\n";

	f.close();
}

// remake
void remake( string data )
{
	get_parts();

	// clears the file
	ofstream f;
	f.open( "cod.cpp" );
	f.close();

	f.open( "cod.cpp" );
	string temp;
	
	f << part;

	f << your_part;


	// adds your data
	f << "\n" << data;

	f << "\n	// your cod ( do not remove this comment. type only above it in your_cod () )\n}\n\n";

	f << main_part;

	f.close();

}

string choice = "";

string valid_choices[1000] = { "1",     "2",     "3",     "4",     "5",     "6",     "7",     "exit" };
string choices[1000] = {     "Make an if", "Make an if / else", "Make a for", "Make a struct", "Make a class", "Make a var.", "Make a comment" };

// makes columns with your choices
void spaces ( int iter )
{
	int size = length( choices );

	int max_length = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i % 4 == iter % 4 )
		{
			string temp = valid_choices[i] + ". " + choices[i];

			if ( temp.length() > max_length )
				max_length = temp.length();
		}

	max_length = max_length + 2;

	string entry = valid_choices[iter] + ". " + choices[iter];
	int entry_size = entry.length();

	for ( int i=entry_size; i<max_length; i=i+1 )
		cout << " ";
}


// gets choice
void get_choice ( int &i )
{
	cout << "Choices:";

	for ( int i=0; i<length( choices ); i=i+1 )
	{
		if ( i % 4 == 0 )
			cout << "\n    ";
		cout << valid_choices[i] << ". " << choices[i];
		spaces( i );
	}

	cout << "\n\n  exit. Exits\n\n";

	cout << "Your choice: ";
	getline( cin, choice );
//	if ( i == 0 ) // only if the case
//		getline( cin, choice );

	if ( !is_in_strings( valid_choices, choice ) )
	{
		cout << "Invalid choice. Retry.\n\n";
		choice = "";
		return;
	}

	// Make an if
	if ( choice == "1" )
	{
		string data = "	if ( true ) // you edit this\n	{\n\n	}\n";

		remake( data );

		continues();
	}

	// Make an if / else
	if ( choice == "2" )
	{
		string data = "	if ( true ) // you edit this\n	{\n\n	}\n	else\n	{\n\n	}\n";

		remake( data );

		continues();
	}

	// Make a for
	if ( choice == "3" )
	{
		string data = "	for ( int i=0; i<10; i=i+1 ) // you edit this\n	{\n\n	}\n";

		remake( data );

		continues();
	}

	// Make a struct
	if ( choice == "4" )
	{
		string data = "	struct struct_name // you edit this\n	{\n\n	};\n";

		remake( data );

		continues();
	}

	// Make a class
	if ( choice == "5" )
	{
		string data = "	class class_name // you edit this\n	{\n\n	};\n";

		remake( data );

		continues();
	}

	// Make a var,
	if ( choice == "6" )
	{
		string data = "	int var;\n";

		remake( data );

		continues();
	}

	// Make a comment
	if ( choice == "7" )
	{
		string data = "	// you edit this\n";

		remake( data );

		continues();
	}

	i=i+1;

	if ( choice == "exit" )
		return;
}


void your_cod ()
{
	// your cod ( do not remove this comment. type only above it in your_cod () )
}


int main ()
{

	your_cod();

	int i=0;
	while ( choice != "exit" )
		get_choice( i );

	cout << "\nExited.\n";
	return 0;
}
