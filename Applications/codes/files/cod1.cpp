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

//	string empty; // to continue
//	getline( cin, empty ); // only if the case
}











string choice = "";

string valid_choices[1000] = {  "1",     "2",      "3",      "4",      "5",      "6",      "7",     "exit" };
string choices[1000] = {     "task_1", "task_2", "task_3", "task_4", "task_5", "task_6", "task_7" };

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

	// task_1
	if ( choice == "1" )
	{
		// your cod
	}


	i=i+1;

	if ( choice == "exit" )
		return;

	cout << "printf \033c";
}

int main ()
{

	int i=0;
	while ( choice != "exit" )
		get_choice( i );

	cout << "\nExited.\n";
	return 0;
}
