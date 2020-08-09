#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int length ( string a[] )
{
	int l = 0;
	while ( a[ l ].length() > 0 )
		l = l + 1;
	return l;
}
int length ( int a[] )
{
	int l = 0;

	while ( a[ l ] )
		l = l + 1;
	return l;
}
// checks if  a  is in  b   or   b  is in  a  for datatype "string"
bool a_is_in_b ( string a, string b )
{
	if (a == b)
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}
// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	return a_is_in_b( a, b );
}

int in_strings ( string a[], string b, bool is_in )
{
	if ( is_in == 1 )
	{
		for ( int l = 0; l < length( a ); l = l + 1 )
			if ( b == a[ l ] )
				return l;
	}
	else
	{
		for ( int l = 0; l < length( a ); l = l + 1 )
			if ( a_is_in_b( b, a[ l ] ) )
				return l;
	}

	return -1;
}
int have_strings ( string a[], string b[], bool is_in )
{
	for ( int l = 0; l < length( a ); l = l + 1 )
	{
		int a_iter = in_strings( b, a[ l ], is_in );
		if ( a_iter != -1 )
			return a_iter;
	}
	return -1;
}
int in_ints ( int a[], int b )
{
	for ( int l = 0; l < length( a ); l = l + 1 )
		if ( b == a[ l ] )
			return l;
	return -1;
}
void empty_strings ( string a[] )
{
	string b[ length( a ) ] = {};

	for ( int l = 0; l < length( a ); l = l + 1 )
		a[ l ] = b[ l ]; 
}
// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	text = text + " ";

	int size = text.length();
	empty_strings ( words );

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}
void continues ()
{

	char enter;
	cout << "[ ']' + Enter ] to continue: ";
	cin >> enter;
}









string usual[ 90 ];
int usual_iter = 0;

string names[ 90 ];
string strings[ 90 ];
int names_iter = 0;

void get_usuals ()
{
	usual_iter = 0;

	ifstream fi;

	fi.open( "strings" );

	string temp;
	while ( fi >> temp )
	{
		usual[ usual_iter ] = temp;
		usual_iter = usual_iter + 1;
	}

	fi.close();

	if ( usual_iter == 0 )
	{
		ofstream fo;
		fo.open( "strings" );
		fo.close();

		cout << "Add usual words!\n";
		continues();
	}
}
void get_names ()
{

	names_iter = 0;

	ifstream fi;

	fi.open( "names" );

	string name;
	string details;
	string temp;
	while ( getline( fi, name ) )
	{
		getline( fi, details );
		names[ names_iter ] = name;

		strings[ names_iter ] = details;
		names_iter = names_iter + 1;
	}

	fi.close();

	if ( names_iter == 0 )
	{
		ofstream fo;
		fo.open( "names" );
		fo.close();

		cout << "Add names!\n";
		continues();
	}
}




void remove_usual_strings ( string &a )
{
	string temps[ 90 ];

	move_words( a, temps );
	string result = "";
	for ( int i = 0; i < length( temps ); i = i + 1 )
	{
		if ( in_strings( usual, temps[ i ], 1 ) != -1 )
			continue;

		result = result + temps[ i ];
		if ( i != length( temps ) - 1 )
			result = result + ' ';
	}

	a = result;
}










void add_name ( string name, string name_string )
{

	remove_usual_strings( name_string );

	for ( int i = 0; i < names_iter; i = i + 1 )
		if ( name == names[ i ] )
		{
			cout << "\"" << names[ i ] << ": ";
			cout << strings[ i ] << "\" - ";
			cout << "Already added!\n";

			string choice;
			cout << "Update details? ( y / n ): ";
			getline ( cin, choice );
			if ( choice == "" )
				getline ( cin, choice );




			if ( choice == "y" )
			{
				strings[ i ] = name_string;

				ofstream fo;

				fo.open( "names" );
				fo.close(); // clear file

				fo.open( "names" );

				for ( int i = 0; i < names_iter; i = i + 1 )
				{
					fo << names[ i ] << "\n";
					fo << strings[ i ] << "\n";
				}
			}

			return;
		}

	names[ names_iter ] = name;
	strings[ names_iter ] = name_string;


	names_iter = names_iter + 1;

	ofstream fo;

	fo.open( "names" );
	fo.close(); // clear file


	fo.open( "names" );

	for ( int i = 0; i < names_iter; i = i + 1 )
	{
		fo << names[ i ] << "\n";
		fo << strings[ i ] << "\n";
	}

	fo.close();

	cout << "Added \"" << name << ": " << name_string << "\"!\n";
}

void add_usual ( string a )
{
	for ( int i = 0; i < usual_iter; i = i + 1 )
		if ( a == usual[ i ] )
		{
			cout << "Usual: \'" << a << "\' already added!\n";
			return;
		}

	usual[ usual_iter ] = a;
	usual_iter = usual_iter + 1;

	ofstream fo;

	fo.open( "strings" );
	fo.close(); // clear file

	fo.open( "strings" );

	for ( int i = 0; i < usual_iter; i = i + 1 )
		fo << usual[ i ] << ' ';

	fo.close();
	cout << "Added usual '" << a << "'!\n";
}













void remove_usual ( string a )
{
	int l = in_strings( usual, a, 1 ); 
	if ( l != -1 )
	{
		ofstream fo;

		fo.open( "strings" );
		fo.close(); // clear file

		fo.open( "strings" );

		for ( int i = 0; i < usual_iter; i = i + 1 )
			if ( i != l )
				fo << usual[ i ] << ' ';

		get_usuals();			
	}
	else
		cout << "Usual \"" << a << "\" invalid.\n";

	cout << "Removed usual '" << a << "'!\n";
}

void remove_name ( int name_iter ) 
{
	ofstream fo;

	fo.open( "names" );
	fo.close(); // clear file


	fo.open( "names" );

	name_iter = name_iter - 1;

	for ( int i = 0; i < names_iter; i = i + 1 )
	{

		if ( i == name_iter )
			continue;


		for ( int i = 0; i < names_iter; i = i + 1 )
		{
			fo << names[ i ] << "\n";
			fo << strings[ i ] << "\n";
		}
	}

	fo.close();

	cout << "Removed \"" << names[ name_iter ] << ": " << strings[ name_iter ] << "\"!\n";
	get_names();

}











void show_usuals ()
{
	if ( usual_iter == 0 )
	{
		cout << "Usuals invalid. Add Usuals.\n";
		return;
	}

	for ( int i = 0; i < usual_iter; i = i + 1 )
		cout << '\'' << usual[ i ] << "' ";
	cout << "\n";
	
}

void show_names ()
{
	if ( names_iter == 0 )
	{
		cout << "Names invalid. Add Names.\n";
		return;
	}

	for ( int i = 0; i < names_iter; i = i + 1 )
	{
		cout << names[ i ] << ": ";
		cout << strings[ i ] << "\n";
	}
}









void identify ( string a )
{
	int common[ 90 ];
	int common_iter = 0;

	for ( int i = 0; i < names_iter; i = i + 1 )
		if ( a_is_in_b ( names[ i ], a ) )
		{
			if ( in_ints( common, i + 1 ) != -1 )
				continue;

			common[ common_iter ] = i + 1;
			common_iter = common_iter + 1;

			cout << names[ i ] << ": ";
			cout << strings[ i ] << "\n";
		}


	string words[ 90 ];
	move_words( a, words );

	string temps[ 90 ];
	int l;
	for ( int i = 0; i < names_iter; i = i + 1 )
	{
		move_words( strings[ i ], temps );

		l = have_strings( temps, words, 0 );

		if ( l != -1 and in_ints( common, i + 1 ) == -1 )
		{
			cout << l << ' ' << in_ints( common, i + 1 ) << "\n";

			common[ common_iter ] = i + 1;
			common_iter = common_iter + 1;

			cout << names[ i ] << ": ";
			cout << strings[ i ] << "\n";
			continue;
		}
	}	

	cout << common_iter << ' ';

	if ( common_iter != 0 )
	{
		string temps[ 90 ];
		string words[ 90 ];
		for ( int i = 0; i < common_iter; i = i + 1 )
			for ( int l = 0; l < names_iter; l = l + 1 )
			{
				if ( in_ints( common, l + 1 ) != -1 )
					continue;

				move_words( strings[ common[ i ] ], temps );
				move_words( strings[ l ], words );

				if ( have_strings( words, temps, 1 ) != -1 )
				{
					cout << "  Also: ";
					cout << "\"" << names[ l ] << ": ";
					cout << strings[ l ] << "\"\n";
				}
			}
	}

}


void show_common ()
{
	string common[ 90 ];
	int common_iter = 0;

	string words[ 90 ];

	string temps[ 90 ];

	for ( int i = 0; i < names_iter; i = i + 1 )
	{
		int l = in_strings( names, names[ i ], 0 );

		if ( l != i and in_strings( common, names[ l ], 0 ) == -1 )
		{
			if ( names[ i ].length() > names[ l ].length() )
				common[ common_iter ] = names[ l ];
			else
 				common[ common_iter ] = names[ i ];
			common_iter = common_iter + 1;
			continue;

		}

		move_words( strings[ i ], temps );

		for ( l = 0; l < names_iter; l = l + 1 )
		{
			int l_iter = have_strings( temps, words, 0 );

			if ( l_iter != -1 and in_strings( common, words[ l_iter ], 0 ) == -1 )
			{
				common[ common_iter ] = names[ i ];
				common_iter = common_iter + 1;
			}
		}
	}

	for ( int l = 0; l < common_iter; l = l + 1 )
	{
		cout << common[ l ] << ":\n";

		for ( int i = 0; i < names_iter; i = i + 1 )
		{
			if ( a_is_in_b( names[ i ], common[ l ] ) )
			{
				cout << "  " << names[ i ] << ": ";
				cout << strings[ i ] << "\n";

				continue;
			}

			move_words( strings[ i ], temps );

			if ( in_strings( temps, common[ l ], 0 ) != -1 )
			{
				cout << "  " << names[ i ] << ": ";
				cout << strings[ i ] << "\n";
			}
		}
	}
}

void remove_usuals ()
{
	for ( int i = 0; i < names_iter; i = i + 1 )
		remove_usual_strings ( strings[ i ] );

	ofstream fo;

	fo.open( "names" );
	fo.close(); // clear file


	fo.open( "names" );

	for ( int i = 0; i < names_iter; i = i + 1 )
	{
		fo << names[ i ] << "\n";
		fo << strings[ i ] << "\n";
	}

	fo.close();

	cout << "Removed usuals.\n";
}









int main ()
{
	cout << "\033c";
	get_usuals();
	get_names();
	string choice;


	for ( int i = 0; i < 90; i = i + 1 )
	{
		cout << "Choice: ";
		cout << "\033c";
		cout << "Choices:\n";
		cout << "  1. Add usual    2. Add name    3. Remove usual  4. Remove name    5. Identify\n";
		cout << "  6. Show usuals  7. Show names  a. Common        9. Remove usuals\n";
		cout << " exit. Exits\n\n";

		cout << "Choice: ";


		getline( cin, choice );
//		if ( choice == "" )
//			getline( cin, choice );

		if ( choice == "1" )
		{
			string usual;
			cout << "Usual: ";
			cin >> usual;

			add_usual( usual );

			continues();
		}

		if ( choice == "2" )
		{
			string name;
			string string_name;
			cout << "Name: ";
			getline( cin, name );
			if ( name == "" )
				getline( cin, name );

			cout << "Details: ";
			getline( cin, string_name );
			if ( string_name == "" )
				getline( cin, string_name );

			add_name( name, string_name );

			continues();
		}



		if ( choice == "3" )
		{
			for ( int i = 0; i < usual_iter; i = i + 1 )
				cout << '\'' << usual[ i ] << "' ";
			cout << "\n";

			string remove_usual_string;
			cout << "Usual to remove: ";
			cin >> remove_usual_string;

			remove_usual( remove_usual_string );

			continues();
		}

		if ( choice == "4" )
		{
			for ( int i = 0; i < names_iter; i = i + 1 )
			{
				cout << i + 1 << ". " << names[ i ] << ": ";
				cout << strings[ i ] << "\n";
			}

			int remove_name_string;
			cout << "Name to remove: ";
			cin >> remove_name_string;

			remove_name( remove_name_string );

			continues();
		}

		if ( choice == "5" )
		{
			string identify_string;
			cout << "Identify: ";
			getline( cin, identify_string );
			if ( identify_string == "" )
				getline( cin, identify_string );

			identify( identify_string );

			continues();
		}


		if ( choice == "6" )
		{
			show_usuals();
			continues();
		}

		if ( choice == "7" )
		{
			show_names();
			continues();
		}

		if ( choice == "a" )
		{
			show_common();
			continues();
		}



		if ( choice == "9" )
		{
			remove_usuals();
			continues();
		}

		if ( choice == "exit" )
		{
			cout << "Exited.\n";
			break;
		}
	}

	return 0;
}
