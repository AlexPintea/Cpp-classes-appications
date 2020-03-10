#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

ofstream file;
string filename = "";
string file_code = "";

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

//	string empty; // to continue
//	getline( cin, empty ); // only if the case
}

// gets the file code
void get_file_code ()
{
	file_code = "";

	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
		file_code = file_code + temp + "\n";

	fi.close();
}









string choice = "";

string valid_choices[1000] = {  "1",     "2",      "3",      "4",     "exit" };
string choices[1000] = {        "if", "if else",  "for",   "while" };

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

// makes a file by filename
void make_file ()
{
	ofstream fo;
	fo.open( filename );
	fo.close();
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
	while ( choice.length() < 1 ) // only if the case
		getline( cin, choice );

	if ( !is_in_strings( valid_choices, choice ) )
	{
		cout << "Invalid choice. Retry.\n\n";
		choice = "";
		return;
	}


	// resets file code
	get_file_code();

	if ( file_code.length() < 1 )
		make_file();

	file.open( filename );
	file << file_code;


	// if
	if ( choice == "1" )
	{
		file << "\nif [[  ]]\nthen\n	# your code\nfi\n\n";
	}

	// if else
	if ( choice == "2" )
	{
		file << "\nif [[  ]]\nthen\n	# your code\nelse\n	# your code\nfi\n\n";
	}

	// for
	if ( choice == "3" )
	{
		file << "\nfor a in {0..3}\ndo\n	# your code\ndone\n\n";
	}

	// while
	if ( choice == "4" )
	{
		file << "\nif [[  ]]\ndo\n	# your code\ndone\n\n";
	}


	i=i+1;

	if ( choice == "exit" )
		return;

	cout << "\n\n\n";
	file.close();
}



int main ( int argc, char* argv[] )
{

	if ( argc > 1 )
		filename = argv[1];

	if ( filename == "" )
	{
		cout << "( info ) echo \"./sh [your filename]\" in your file to use ./sh directly.\n";
		cout << "Filename: ";
		getline( cin, filename );
		filename = filename + ".sh";

		cout << "\n\n";
	}

	int i=0;
	while ( choice != "exit" )
		get_choice( i );

	cout << "\nExited.\n";



	return 0;
}
