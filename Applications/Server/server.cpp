#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string db[ 90 ];
int db_iter = 0;


int length ( int a )
{
	if ( a == 0 ) return 1;

	int i = 0;

	while ( a != 0 )
	{
		i = i + 1;
		a = a / 10;
	}

	return i;
}


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

// check if a string is an int
bool is_int ( string a )
{
	int size = a.length();

	if ( size >= 10 )
		return false;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}
// convert string to int
int string_to_int ( string a )
{
	if ( a.length() == 1 )
		return a[0] - 48;

	int size = a.length();

	int iter = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		iter = 1;
	}

	int num_int = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_int = num_int * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_int = -num_int;

	return num_int;
}

// to continue
void continues ()
{
	char chars;
	cout << "\n[ ']' + Enter ] to continue: ";
	cin >> chars;
}



void get_db ()
{
	db_iter = 0;

	ifstream fi;

	fi.open( "server files/db_name" );

	string temp;
	while ( getline( fi, temp ) )
	{
		db[ db_iter ] = temp;
		db_iter = db_iter + 1;
	}

	fi.close();
}

void set_db ()
{
	ofstream fo;

	fo.open( "server files/db_name" );
	fo.close(); // clear file


	fo.open( "server files/db_name" );

	for ( int i = 0; i < db_iter; i = i + 1 )
		fo << db[ i ] << '\n';

	fo.close();
}


void show ()
{
	if ( db_iter == 0 )
	{
		cout << "Db-s invalid. \"add\" to add db-s.\n";
		return;
	}

	int maximum[ 10 ];

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = 0;

	for ( int i = 0; i < db_iter; i = i + 1 )
		if ( db[ i ].length() + length( i + 1 ) > maximum[ i % 5 ] )
			maximum[ i % 5 ] = db[ i ].length() + length( i + 1 );

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = maximum[ i ] + 2;

	cout << "Db-s:\n\n";
	for ( int i = 0; i < db_iter; i = i + 1 )
	{
		if ( i % 5 == 0 )
			cout << "  ";
		cout << i + 1 << ". " << db[ i ] << ' ';
		for ( int l = db[ i ].length() + length( i + 1 ); l < maximum[ i % 5 ]; l = l + 1 )
			cout << ' ';
		if ( i % 5 == 4 )
			cout << '\n';
	}

	if ( db_iter % 5 != 0 )
		cout << '\n';

	cout << "\n  ";
}


void add ()
{
	string name;

	cout << "Db name: ";
	getline( cin, name );

	if ( name == "" )
		getline( cin, name );

	db[ db_iter ] = name;
	db_iter = db_iter + 1;

	set_db();

	command_linux( "mkdir 'server files/" + name + '\'' );
	command_linux( "cp -R 'server files/class' 'server files/" + name + "'" );
}




void remove ()
{
	cout << "Remove db: ";

	int l;

	string choice;
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );


	if ( ! is_int( choice ) )
	{
		cout << "Invalid.\n";
		return;
	}
	else
	{
		int choice_num = string_to_int( choice ) - 1;

		if ( choice_num < 0 or choice_num >= db_iter )
		{
			cout << "Invalid.\n";
			return;
		}

		l = choice_num;
	}

	ofstream fo;

	fo.open( "server files/db_name" );
	fo.close(); // clear file

	fo.open( "server files/db_name" );

	for ( int i = 0; i < db_iter; i = i + 1 )
		if ( i != l )
			fo << db[ i ] << '\n';

	fo.close();

	get_db();

	command_linux( "rm -R 'server files/" + db[ l ] + '\'' );
}




void edit ()
{
	cout << "Edit db: ";

	int l;

	string choice;
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );


	if ( ! is_int( choice ) )
	{
		cout << "Invalid.\n";
		return;
	}
	else
	{
		int choice_num = string_to_int( choice ) - 1;

		if ( choice_num < 0 or choice_num >= db_iter )
		{
			cout << "Invalid.\n";
			return;
		}

		l = choice_num;
	}

	string name;
	cout << "Edit name \"" << db[ l ] << "\" of db: ";

	getline( cin, name );
	if ( name == "" )
		getline( cin, name );

	db[ l ] = name;

	set_db();
}


int main ()
{

	for ( int i = 0; i < 10000; i = i + 1 )	
	{
		cout << "\033c";
		get_db();
		cout << "\033c";
		show();

		cout << "add. Add Db  edit. Edit Db name  remove. Remove Db\n";
		cout << "\nChoice: ";


		string choice;
		getline( cin, choice );

		if ( is_int( choice ) )
		{
			int choice_num = string_to_int( choice ) - 1;

			if ( choice_num < 0 or choice_num >= db_iter )
				cout << "Invalid.\n";
			else
			{
				system( "printf \033c" );
				command_linux( "cd 'server files/" + db[ choice_num ] + "' && ./class" );
			}
		}


		if ( choice == "add" )
		{
			add();
			continues();
			continue;
		}

		if ( choice == "edit" )
		{
			edit();
			continues();
			continue;
		}

		if ( choice == "remove" )
		{
			remove();
			continues();
			continue;
		}
	}

	return 0;
}
