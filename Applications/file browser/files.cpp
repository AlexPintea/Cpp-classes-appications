#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

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


void ls ()
{
	string command = "ls";

	command_linux( command );
}

void clear ()
{
	string command = "clear";

	command_linux( command );
}


string choice = "";

void show_choices()
{
	clear();

	cout << " 1. Move up  Enter folder name  exit. Exit  \n";
	ls();
	cout << "\nEnter choice: ";
	cin >> choice;
	
	if ( choice == "1" )
	{
		string command = "cd ..";
		command_linux( command );
	}

	if ( choice == "exit" )
		return;
}

int main ()
{

	while ( choice != "exit" )
		show_choices();

	cout << "\nExited.\n\n";

	return 0;
}
