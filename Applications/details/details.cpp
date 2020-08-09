#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string names[ 100000 ];
string strings[ 100000 ];
int file_iter = 0;



int length ( string a[] )
{
	int l;

	while ( a[ l ].length() > 0 )
		l = l + 1;
	return l;
}


bool is_string_empty ( string a )
{



	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a [ l ] != ' ' and a [ l ] != '\n' and a [ l ] != '	' )
			return 0;
	return 1;
}

int in_strings ( string a[], string b )
{
	for ( int l = 0; l < length( a ); l = l + 1 )
		if ( a[ l ] == b )
			return l;

	return -1;
}

void continues ()
{
	char enter;
	cout << "[ ']' + Enter ] to continue: ";

	cin >> enter;
}


void get_file ()
{
	file_iter = 0;

	ifstream fi;
	fi.open( "strings" );

	string name_temp;
	string string_temp;
	while ( getline( fi, name_temp ) )
	{
		names[ file_iter ] = name_temp;

		string_temp = name_temp;
		strings[ file_iter ] = "";
		while ( getline( fi, string_temp ) )
		{
			if ( is_string_empty( string_temp ) )
				break;
			strings[ file_iter ] = strings[ file_iter ] + string_temp + "\n";
		}

		file_iter = file_iter + 1;
	}

	fi.close();
}

void set_file ()
{
	ofstream fo;

	fo.open( "strings" );
	fo.close(); // clear file

	fo.open( "strings" );

	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		fo << names[ i ] << "\n";
		fo << strings[ i ] << "\n";
	}

	fo.close();
}


void add ( string a, string b )
{
	int l = in_strings( names, a );
	if ( l != -1 )
	{
		strings[ l ] = b;
		set_file();
		cout << "Details edited.\n";
		return;
	}

	names[ file_iter ] = a;
	strings[ file_iter ] = b;
	file_iter = file_iter + 1;

	set_file();


	cout << "\"" << a << "\" added!\n";
}



void edit ( int name_iter, string a )
{
	strings[ name_iter ] = a;

	set_file();

	cout << "\"" << names[ name_iter ] << "\" edited!\n";
}

void remove ( int remove_iter )
{
	ofstream fo;

	fo.open( "strings" );
	fo.close(); // clear file

	fo.open( "strings" );

	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		if ( i == remove_iter )
			continue;
		fo << names[ i ] << "\n";
		fo << strings[ i ] << "\n";
	}


	fo.close();
	get_file();


	cout << "\"" << names[ remove_iter ] << "\" removed!\n";
}


void show ()
{

	cout << "\033c";
	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		cout << "\"" << names[ i ] << "\"\n";
		cout << strings[ i ] << "\n";
	}
}

int main ()
{
	get_file();

	if ( file_iter == 0 )
		cout << "0 to show.\n";
	else
		show();

	string choice = "";
	cout << "Choices: edit. Edit  [ any string ]. Exits\n";
	cout << "Choice: ";

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "edit" )
		for ( int i = 0; i < 100000; i = i + 1 )
		{
			cout << "Choices: ";
			cout << "\033c";

			choice = "";
			cout << "Choices: 1. Add  2. Remove  3. Edit  show. Show  exit. Exits\n";
			cout << "Choice: ";

			getline( cin, choice );
			if ( choice == "" )
				getline( cin, choice );

			if ( choice == "1" )
			{
				string name_string;
				string details_string;
				string details = "";
				cout << "Name: ";
				getline( cin, name_string );
				if ( name_string == "" )
					getline( cin, name_string );

				int l = in_strings( names, name_string );
				if ( l != -1 )
				{
					cout << "\n\"" << name_string << "\" already added!\n";
					cout << "Its details are:\n";
					cout << strings[ l ] << "\n";
					cout << "Edit its details? ( y / n ): ";

					string choice;
					getline( cin, choice );

					if ( choice == "" )
						getline( cin, choice );

					if ( choice != "y" )
					{
						cout << "Details remain.\n";
						continues();
						continue;
					}
				}

				cout << "Details:\n";

				getline( cin, details_string );
				while ( ! is_string_empty( details_string ) )
				{
					details = details + details_string + "\n";
					getline( cin, details_string );
				}

				add( name_string, details );
				continues();
			}

			if ( choice == "2" )
			{
				if ( file_iter == 0 )
				{
					cout << "0 to remove.\n";
					continues();
					continue;
				}

				for ( int i = 0; i < file_iter; i = i + 1 )
					cout << i + 1 << ". " << names[ i ] << "\n";

				int choice_int;

				cout << "\nRemove: ";
				cin >> choice_int;

				choice_int = choice_int - 1;

				if ( choice_int < 0 or choice_int >= file_iter )
					cout << "invalid.\n";
				else
					remove( choice_int );
				continues();
			}

			if ( choice == "3" )
			{
				if ( file_iter == 0 )
				{
					cout << "0 to edit.\n";
					continues();
					continue;
				}

				for ( int i = 0; i < file_iter; i = i + 1 )
					cout << i + 1 << ". " << names[ i ] << "\n";

				int choice_int;
				cout << "\nEdit: ";
				cin >> choice_int;

				choice_int = choice_int - 1;

				if ( choice_int < 0 or choice_int >= file_iter )
					cout << "invalid.\n";
				else
				{
					string edit_string;
					cout << "Edit \"" << names[ choice_int ] << "\" details to: ";
					getline( cin, edit_string );
					if ( edit_string == "" )
						getline( cin, edit_string );
					edit( choice_int, edit_string );
				}
				continues();			
			}

			if ( choice == "show" )
			{
				if ( file_iter == 0 )
				{
					cout << "0 to show.\n";
					continues();
					continue;
				}
				show();
				continues();
			}

			if ( choice == "exit" )
			{

				cout << "Exited\n";
				break;
			}
		}

	return 0;
}
