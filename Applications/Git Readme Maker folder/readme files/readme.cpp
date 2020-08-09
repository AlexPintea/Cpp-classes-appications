#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

string name, filename = "", reason, prog[100], description, datas[10];
int num_prog;
char response;

ofstream file;
fstream data;


void fill_in_data (char response)
{
	if ( response == 'y' )
	{
		for ( int i=0; i<3; i=i+1 )
		{
			getline( data, datas[i] );
			file << datas[i] << "\n";
		}
	}
	if ( response == 'n' )
	{
		cout << "Please find \"data.txt\" in this folder and type in 1 means of contact and other details on each line. Only the 1st 3 will be used.\n";
		cout << "Have you filled in \"data.txt\"? ( y/n )";
		cin >> response;
		fill_in_data( response );
	}
}

void large_first (string &a)
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;
}

int main () 
{
	data.open( "data.txt" );

	cout << "Enter name of application: ";
	getline( cin, name );
	cout << "\n";

	large_first( name );

	filename = filename + "Readme " + name + ".md";
	file.open( filename );

	file << "## " << name << "\n\n";

	cout << "Num. of programming languages used: ";
	cin >> num_prog;
	cout << "\n";

	for ( int i=0; i<num_prog; i=i+1 )
	{
		cout << "Name of programming language " << i + 1 << ": ";
		cin >> prog[i];
		large_first( prog[i] );
	}

	cout << "\nReason ( \"dealing with code\" ): ";
	getline( cin, reason );
	getline( cin, reason );
	cout << "\n";

	file << "__" << name << "__ mostly concerns itself with __" << reason << "__.\n\n" ;


	file << "It was made using:\n";

	for ( int i=0; i<num_prog; i=i+1 )
	{
		file << "- " << prog[i] << "\n";
	}

	cout << "Description ( long ): ";
	getline( cin, description );
	cout << "\n";

	file << "\n## > About\n";
	file << description << "\n\n";

	cout << "Have you filled in \"data.txt\"? ( y/n )";
	cin >> response;
	fill_in_data( response );

	file.close();
	data.close();

	return 0;
}
