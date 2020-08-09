#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string scrpts[ 10000 ];
string names[ 10000 ];
string details[ 10000 ];
int scrpts_iter = 0;

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

bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
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

string upper ( string a )
{
	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;
	return a;
}

string lower ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
	{
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			a[ i ] = a[ i ] + 32;
	}

	return a;
}

// removes a char in a string
void remove_char( string &a, int iter )
{
	if ( iter < 0 or iter >=a.length() )
		return;

	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
			result = result + a[i];

	a = result;
}

string reduce_spaces ( string &a )
{
	int size = a.length();
	string result = "";
	int l;


	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '	' )
		{
			l = i;
			break;
		}

	for ( int i = l; i < size; i = i + 1 )
		if ( a[i] != ' ' and a[i] != '	' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + ' ';

	size = result.length();
	for ( int i = size - 1; i >= 0; i = i - 1 )
	{
		if ( result[ i ] != ' ' and result[ i ] != '	' )
			break;
		remove_char( result, i );
	}
	a = result;

	return a;
}

// replaces spaces in entered data, to make valid variable names
string replace_space ( string a )
{
	for (int i = 0; i < a.length(); i = i + 1)
		if ( a[ i ] == ' ' )
			a[ i ] = '_';

	return a;
}


int is_scrpt ( string a )
{
	for ( int i = 0; i < scrpts_iter; i = i + 1 )
		if ( scrpts[ i ] == replace_space( lower( reduce_spaces( a ) ) ) )
			return i;
	return -1;
}

int is_name ( string a )
{
	for ( int i = 0; i < scrpts_iter; i = i + 1 )
		if ( names[ i ] == a )
			return i;
	return -1;
}

void filename_ext_filepath ( string &filename, string &ext, string &filepath )
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
		if ( filename[ i ] == '.' )
		{
			have_ext = true;
			break;
		}

	if ( ! have_ext )
		return;

	int d = 0;
	for ( int i = filename.length() - 1; i >= 0; i = i - 1 )
		if ( filename[ i ] != '/' )
			d = i;
		else
			break;

	filepath = "";
	for ( int i = 0; i < d; i = i + 1 )
		filepath = filepath + filename[ i ];

	string file_name = "";
	int l = 0;
	for ( int i = d; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}

		file_name = file_name + filename[ i ];
	}

	for ( int i = l; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' ) continue;	

		ext = ext + filename[ i ];
	}

	filename = file_name;
}

void get_scrpts ()
{
	scrpts_iter = 0;

	ifstream fi;
	fi.open( "scrpts/scrpts" );

	string temp = "scrpt";
	while ( getline( fi, temp ) )
	{
		names[ scrpts_iter ] = temp;
		getline( fi, temp );
		scrpts[ scrpts_iter ] = temp;

		details[ scrpts_iter ] = "";
		while ( ! is_string_empty( temp ) )
		{
			getline( fi, temp );
			details[ scrpts_iter ] = details[ scrpts_iter ] + temp + '\n';
		}
		scrpts_iter = scrpts_iter + 1;
	}

	fi.close();
}

void show ()
{
	if ( scrpts_iter == 0 )
	{
		cout << "Scrpts invalid. \"add\" to add scrpts.\n";
		return;
	}
	int maximum[ 10 ];

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = 0;

	for ( int i = 0; i < scrpts_iter; i = i + 1 )
		if ( names[ i ].length() + length( i + 1 ) > maximum[ i % 5 ] )
			maximum[ i % 5 ] = names[ i ].length() + length( i + 1 );

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = maximum[ i ] + 2;

	cout << "Scrpts:\n\n";
	for ( int i = 0; i < scrpts_iter; i = i + 1 )
	{
		if ( i % 5 == 0 )
			cout << "  ";
		cout << i + 1 << ". " << names[ i ] << ' ';
		for ( int l = names[ i ].length() + length( i + 1 ); l < maximum[ i % 5 ]; l = l + 1 )
			cout << ' ';
		if ( i % 5 == 4 )
			cout << '\n';
	}

	if ( scrpts_iter % 5 != 0 )
		cout << '\n';

	cout << "\n  ";
}



void show_details ()
{
	if ( scrpts_iter == 0 )
	{
		cout << "Scrpts invalid. \"add\" to add scrpts.\n";
		return;
	}
	cout << '\n';
	

	for ( int i = 0; i < scrpts_iter; i = i + 1 )
	{
		cout << i + 1 << ". " << names[ i ] << ' ';
		cout << "( " << scrpts[ i ] << " )\n";
		cout << details[ i ] << "\n\n";
	}
}

void add ()
{
	string scrpt;
	cout << "Name: ";
	getline( cin, scrpt );
	if ( scrpt == "" )
		getline( cin, scrpt );
	scrpt = upper( scrpt );

	while ( is_name( scrpt ) != -1 )
	{
		cout << "\nScrpt name \"" << scrpt << "\" already taken.\n";
		cout << "Name: ";
		getline( cin, scrpt );

		if ( scrpt == "" )
			getline( cin, scrpt );

		scrpt = upper( scrpt );
	}

	string filename;
	string ext;
	string filepath;

	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	// filename_ext_filepath( filename, ext, filepath );

 	// if ( ext != "" )
	//	filename = filename + '.' + ext;

	while ( is_scrpt( filename ) != -1 )
	{
		cout << "\nScrpt filename \"" << filename << "\" already taken.\n";
		cout << "Filename: ";
		getline( cin, filename );

		if ( filename == "" )
			getline( cin, filename );

		filename = replace_space( lower( reduce_spaces( filename ) ) );
	}

	string detail = "";
	string temp = "details";
	cout << "Details ( empty means done ):\n";
	while ( ! is_string_empty( temp ) )
	{
		getline( cin, temp );
		if ( is_string_empty( temp ) )
			break;

		detail = detail + temp + '\n';
	}

	names[ scrpts_iter ] = upper( scrpt );
	details[ scrpts_iter ] = detail;
	scrpts[ scrpts_iter ] = replace_space( lower( reduce_spaces( scrpt ) ) );
	scrpts_iter = scrpts_iter + 1;

	ofstream fo;
	fo.open( "scrpts/scrpts" );
	fo.close(); // clear file

	command_linux( "cp -R " + filename + " scrpts/" + scrpts[ scrpts_iter ] );

	fo.open( "scrpts/scrpts" );

	for ( int i = 0; i < scrpts_iter; i = i + 1 )
	{
		fo << names[ i ] << '\n';
		fo << scrpts[ i ] << '\n';
		fo << details[ i ] << "\n\n";
	}

	fo.close();
}

void remove ()
{
	if ( scrpts_iter == 0 )
	{
		cout << "Scrpts invalid. \"add\" to add scrpts.\n";
		return;
	}

	cout << "Remove scrpt: ";

	string choice;

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	int choice_num;
	if ( ! is_int( choice ) )
	{
		cout << "Invalid.\n";
		return;
	}
	else
	{
		choice_num = string_to_int( choice ) - 1;

		if ( choice_num < 0 or choice_num >= scrpts_iter )
		{
			cout << "Invalid.\n";
			return;
		}
		else
		{
			ofstream fo;
			fo.open( "scrpts/scrpts" );
			fo.close(); // clear file

			fo.open( "scrpts/scrpts" );
			for ( int i = 0; i < scrpts_iter; i = i + 1 )
			{
				if ( i == choice_num )
					continue;
				fo << names[ i ] << '\n';
				fo << scrpts[ i ] << '\n';
				fo << details[ i ] << "\n\n";
			}

			fo.close();

			get_scrpts();
		}
	}
}


void edit ()
{
	if ( scrpts_iter == 0 )
	{
		cout << "Scrpts invalid. \"add\" to add scrpts.\n";
		return;
	}

	cout << "Edit scrpt: ";

	string choice;

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	int choice_num;
	if ( ! is_int( choice ) )
	{
		cout << "Invalid.\n";
		return;
	}
	else
	{
		choice_num = string_to_int( choice ) - 1;

		if ( choice_num < 0 or choice_num >= scrpts_iter )
		{
			cout << "Invalid.\n";
			return;
		}
		else
		{
			cout << "Edit \"" << scrpts[ choice_num ] << "\":\n\n Name: ";

			string name;
			getline( cin, name );
			if ( name == "" )
				getline( cin, name );

			name = upper( name );

			while ( is_name( name ) != -1 )
			{
				cout << "\nScrpt name \"" << name << "\" already taken.\n";
				cout << "Name: ";
				getline( cin, name );

				if ( name == "" )
					getline( cin, name );

				name = upper( name );
			}

			cout << " Details ( empty means done ):\n";

			string detail = "";
			string temp = "details";

			while ( ! is_string_empty( temp ) )
			{
				cout << ' ';
				getline( cin, temp );
				if ( is_string_empty( temp ) )
					break;

				detail = detail + temp + '\n';
			}


			ofstream fo;
			fo.open( "scrpts/scrpts" );
			fo.close(); // clear file

			fo.open( "scrpts/scrpts" );
			for ( int i = 0; i < scrpts_iter; i = i + 1 )
			{
				if ( i == choice_num )
				{
					fo << name << '\n';
					fo << scrpts[ i ] << '\n';
					fo << detail << '\n';
					continue;
				}

				fo << names[ i ] << '\n';
				fo << scrpts[ i ] << '\n';
				fo << details[ i ] << "\n\n";
			}

			fo.close();

			get_scrpts();
		}
	}
}

// to continue
void continues ()
{
	char chars;
	cout << "\n[ ']' + Enter ] to continue: ";
	cin >> chars;
}

int main ()
{
	for ( int i = 0; i < 10000; i = i + 1 )
	{
		get_scrpts();
		cout << "\033c";
		show();

		cout << "add. Add Scrpt  edit. Edit Scrpt  remove. Remove Scrpt  show. Show Details\n";
		cout << "\nChoices: ";

		string choice;
		getline( cin, choice );

		if ( is_int( choice ) )
		{
			int choice_num = string_to_int( choice ) - 1;

			if ( choice_num < 0 or choice_num >= scrpts_iter )
				cout << "Invalid.\n";
			else
			{
				system( "printf \033c" );
				command_linux( "./scrpts/" + scrpts[ choice_num ] );
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

		if ( choice == "show" )
		{
			show_details();
			continues();
			continue;
		}
	}

	return 0;
}
