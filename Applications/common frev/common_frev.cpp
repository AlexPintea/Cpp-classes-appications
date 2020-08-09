#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;
int length ( string a[] )
{
	int i = 0;
	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;

}
int in_strings ( string a[], string b )
{
	int size = length( a );

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return i;
	return -1;
}
int count_in_strings ( string a[], string b )
{
	int size = length( a );

	int count = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			count = count + 1;
	return count;
}

string common[ 10000 ];
long frev[ 10000 ];
int common_iter = 0;

void get_file ()
{
	ifstream fi;
	fi.open( "common" );

	string temp;

	while ( fi >> temp )
	{
		common[ common_iter ] = temp;
		fi >> frev[ common_iter ];
		common_iter = common_iter + 1;
	}

	fi.close();
}

void set_file ()
{
	string swap_common;
	long swap_frev;
	for ( int i = 0; i < common_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < common_iter; l = l + 1 )
			if ( frev[ i ] < frev[ l ] )
			{
				swap_common = common[ i ];
				swap_frev = frev[ i ];

				common[ i ] = common[ l ];
				frev[ i ] = frev[ l ];

				common[ l ] = swap_common;
				frev[ l ] = swap_frev;
			}

	ofstream fo;
	fo.open( "common" );
	fo.close(); // clear file
	fo.open( "common" );

	for ( int i = 0; i < common_iter; i = i + 1 )
		fo << common[ i ] << ' ' << frev[ i ] << '\n';

	fo.close();
}

void add_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string strings[ 10000 ];
	int strings_iter = 0;

	string temp;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();

	string remain[ 10000 ];
	int remain_frev[ 10000 ];
	int remain_iter = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( in_strings( remain, strings[ i ] ) == -1 )
		{
			remain[ remain_iter ] = strings[ i ];
			remain_frev[ remain_iter ] = count_in_strings( strings, strings[ i ] );
			remain_iter = remain_iter + 1;
		}

	for ( int i = 0; i < remain_iter; i = i + 1 )
	{
		int l = in_strings( common, remain[ i ] );
		if ( l != -1 )
			frev[ l ] = frev[ l ] + remain_frev[ i ];
		else
		{
			common[ common_iter ] = remain[ i ];
			frev[ common_iter ] = remain_frev[ i ];
			common_iter = common_iter + 1;
		}
	}
	set_file();
}

void show_common ()
{
	for ( int i = 0; i < common_iter; i = i + 1 )
	{
		cout << common[ i ] << ' ' << frev[ i ];
		if ( i != common_iter - 1 )	
			cout << ", ";
	}
	cout << '\n';
}



void continues ()
{
	char enter;
	cout << "[ ']' + Enter ] to continue: ";
	cin >> enter;
}


long get_file_num ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	long num = 0;
	while ( fi >> temp )
		num = num + 1;

	fi.close();

	return num;
}


void add_files ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;

	long file_iter = 0;

	ofstream fo;

	fo.open( "files" );

	while ( fi >> temp )
	{
		fo << temp << ' ';
		file_iter = file_iter + 1;

		if ( file_iter > 9000 )
		{
			fo.close();
			add_file( "files" );
			fo.open( "files" );
		}
	}

	fo.close();

	fi.close();
}



int main ()
{
	get_file();

	for ( int i = 0; i < 10000; i = i + 1 )
	{
		cout << "choice";
		cout << "\033c";
		cout << "Choices:  1. Add File  2. Show commons  3. Exits\n";
		string choice;
		cout << "Choice: ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		if ( choice != "1" and choice != "2" and choice != "3" )
			continue;

		if ( choice == "1" )
		{
			cout << "Filename: ";

			string filename;

			getline( cin, filename );
			if ( filename == "" )
				getline( cin, filename );

			if ( get_file_num( filename ) > 9000 )
				add_files( filename );
			else
				add_file( filename );
			cout << "File added!\n";
		}

		if ( choice == "2" )
		{
			show_common();
		}

		if ( choice == "3" )
		{
			cout << "Exited.\n";
			break;
		}

		continues();
	}

	return 0;
}
