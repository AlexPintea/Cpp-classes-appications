#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

ofstream file;


void replace_space(string &a) 
{
	for (int i=0; i<a.length(); i=i+1)
		if ( a[i] == ' ' )
			a[i] = '_';
}

void large_first(string &a)
{
	if ( a[0] >= 'a' &&  a[0] <= 'z' )
		a[0] = a[0] - 32;
}

void small_first(string &a)
{
	if ( a[0] >= 'A' &&  a[0] <= 'Z' )
		a[0] = a[0] + 32;
}

void linux_command(string command)
{
	char result[100];
	int size = command.length();
	int i;
	for (i=0; i<size; i=i+1)
		result[i] = command[i];
	
	result[i] = '\0';

	system( result );
}

int main () 
{
	string name;

	cout << "Enter file name: ";
	getline(cin, name);
	replace_space(name);
	
	string filename = name + ".sh";

	file.open( filename );
	
	string description;
	cout << "Enter about: ";
	getline(cin, description);
	
	large_first(name);
	large_first(description);

	file << "# " << name << " = " << description << "\n\n";

	file << "echo Name = " << name << "\n";
	file << "echo About = " << description << "\n\n";
	file << "echo \n\n";


	cout << "Enter num. of entries ( >= 1 and <= 90 ): ";
	int entries_num;
	cin >> entries_num;

	string entries[100];

	for ( int i=0; i<entries_num; i=i+1 )
	{
		cout << "Enter entry " << i+1 << ": ";
		getline( cin, entries[i] );
			if ( i == 0 )
				getline( cin, entries[i] );
	}

	for ( int i=0; i<entries_num; i=i+1 )
	{
		file << "echo " << entries[i] << "\n";
	}

	file.close();

	cout << "\n";

	string command = "./" + filename;

	string permission = "chmod -R 767 " + filename;

	linux_command( permission );
	linux_command( command );

	return 0;	
}
