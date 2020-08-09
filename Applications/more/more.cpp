#include <fstream>
#include <string>
#include <iostream>
#include <string.h>


using namespace std;

string name;
string parameters[1000];
double boundery_1[1000];
double boundery_2[1000];
int num_param;

int num_iter;




string names[1000];
int names_iter = 0;

int length ( string a[] )
{
	int i=0;
	
	while ( a[i].length() > 0 )
		i = i + 1;

	return i;
}

bool is_string_in_string ( string a[], string b )
{
	int size = length( a );

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == b )
			return true;

	return false;
}

void replace_spaces ( string &a )
{
	for ( int i=0; i<a.length(); i=i+1 )
		if ( a[i] == ' ' )
			a[i] = '_';
}

void continues()
{
	char enter;
	cout << "[ \']' + Enter ] to continue: ";
	cin >> enter;

	cout << "\n";
}

void get_data ()
{
	do
	{
		cout << "Establish name: ";
		cin >> name;
		replace_spaces( name );
	} while ( is_string_in_string( names, name ) or name == "" );	

	names[ names_iter ] = name;
	names_iter = names_iter + 1;

	char command_make_name_folder[] = "mkdir  interaction/";
	for ( int i=0; i<name.length(); i=i+1 )
		command_make_name_folder[ 19 + i ] = name[i];
	command_make_name_folder[ 19 + name.length() ] = '\0';
	system( command_make_name_folder );

	num_param = 0;
	while ( num_param == 0 )
	{
		cout << "Num. of parameters: ";
		cin >> num_param;
	}

	string temp;
	for ( int i=0; i<num_param; i=i+1 )
	{
		do
		{
			cout << "Name of parameter " << i + 1 << ": ";
			getline( cin, temp );
			if ( temp == "" )
				getline( cin, temp );
		} while ( is_string_in_string( parameters, temp ) );

		parameters[i] = temp;

		replace_spaces( parameters[i] );


		cout << "Boundery 1: ";
		cin >> boundery_1[i];

		cout << "Boundery 2 ( greater Boundery 1 ): ";
		cin >> boundery_2[i];

		if ( boundery_2[i] <= boundery_1[i] )
		{
			cout << "Boundery 2 is " << boundery_1[i] + 1 << ".\n";
			boundery_2[i] = boundery_1[i] + 1;
		}
	}

	cout << "Num. of iterations: ";
	cin >> num_iter;
}

void set_data ()
{
	ifstream fi;
	fi.open( "files/command" );

	string command_file;
	getline( fi, command_file );

	fi.close();


	int iter = 0;
	int num_int = 0;
	if ( command_file.length() >= 1 )
	{

		while ( command_file[ iter ] != ' ' )
			iter = iter + 1;

		string num = "";	
		for ( int i=0; i<iter; i=i+1 )
			num = num + command_file[i];

		for ( int i=0; i<num.length(); i=i+1 )
			num_int = num_int * 10 + num[i] - 48;
	}
	num_int = num_int + 1;


	ofstream fo;

	fo.open( "files/command" );

	fo << num_int << "   ";
	if ( command_file.length() >= 1 )
	{
		for ( int i=iter; i<command_file.length(); i=i+1 )
			fo << command_file[i];
		fo << " ";
	}

	fo << name << "  ";
	fo << num_param << "  ";
	for ( int i=0; i<num_param; i=i+1 )
	{
		fo << parameters[i] << ' ';
		fo << boundery_1[i] << ' ';
		fo << boundery_2[i] << "    ";
	}
	fo << num_iter << ' ';

	fo.close();
}











int main ()
{

	// clears the "command" file
	ofstream fo;
	fo.open( "files/command" );
	fo.close();

	// clears "interaction" folder
	char command_remove_folder[] = "rm -R interaction";
	char command_make_folder[] = " mkdir interaction";
	system( command_remove_folder );
	system( command_make_folder );

	cout << "printf \033c";

	while ( true )
	{
		get_data();
		set_data();


	
		string choice;
		cout << "Make another ( y / n ): ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		if ( choice != "y" )
		{
			cout << "printf \033c";

			cout << "Exited. Continue to define interactions.\n\n";

			continues();

			char command[70] = "printf \033c && g++ -o files/more_1 files/more_1.cpp && ./files/more_1";
			system( command );

			break;
		}

		for ( int i=0; i<=num_param; i=i+1 )
			parameters[i] = "";

		num_param = 0;

		cout << "printf \033c";
	}


	return 0;
}
