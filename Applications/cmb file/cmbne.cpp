#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filenames[ 1000 ];
int num = 0;
string strings[ 10000 ];
int strings_iter = -1;

int length ( string a[] )
{
	int i = 0;


	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}

int get_strings ( string filename )
{
	strings_iter = 0;
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}

	fi.close();
}

void get_filenames ()
{
	num = 0;
	ifstream fi;
	fi.open( "cmbne/filename" );

	string temp;
	while ( getline( fi, temp ) )
	{
		filenames[ num ] = temp;
		num = num + 1;
	}

	fi.close();
}

void add_filename ( string filename )
{
	filenames[ num ] = filename;
	num = num + 1;

	ofstream fo;
	fo.open( "cmbne/filename" );
	fo.close(); // clear file

	fo.open( "cmbne/filename" );

	for ( int i = 0; i < num; i = i + 1 )
		fo << filenames[ i ] << '\n';

	fo.close();
}





void show_filenames ()
{
	for ( int i = 0; i < num; i = i + 1 )
		cout << "  " << i + 1 << ". " << filenames[ i ] << '\n';
	cout << '\n';
}


void remove_filename ( int a )
{
	ofstream fo;
	fo.open( "cmbne/filename" );
	fo.close(); // clear file

	fo.open( "cmbne/filename" );

	for ( int i = 0; i < num; i = i + 1 )
		if ( i != a )
			fo << filenames[ i ] << '\n';

	fo.close();
	get_filenames();
}





bool have_filename() { if ( num > 0 ) return 1; return 0; }


int get_file_iter ()
{
	int file_iter;
	ifstream fi;
	fi.open( "cmbne/iter" );
	fi >> file_iter;
	fi.close();

	return file_iter;
}

int get_last_file_iter ()
{
	int file_iter;
	ifstream fi;
	fi.open( "cmbne/iter" );
	fi >> file_iter;
	fi >> file_iter;
	fi.close();

	return file_iter;
}

int get_file_length ()
{
	string file;
	int file_iter = 0;
	ifstream fi;
	fi.open( "cmbne/iter" );
	getline( fi, file );
	file_iter = file_iter + file.length();
	getline( fi, file );
	file_iter = file_iter + file.length();
	fi.close();

	return file_iter;
}


bool have_iter = 0;
int get_iter ( int i )
{
	if ( ! have_filename() )
		return -1;

	if ( i % 9 == 0 and i != 0 )
		return strings_iter - 1;

	int num_iter = 0;


	int file_iter = get_file_iter();
	int filename_iter = 0;
	int file_last_iter = get_last_file_iter();

	// cout << file_iter << ' ' << file_last_iter << '\n';

	if ( file_last_iter == file_iter or file_last_iter == 0 or have_iter == 0 )
		file_iter = get_file_length() + file_last_iter;

	if ( have_iter == 0 )
	{
		ofstream fo;
		fo.open( "cmbne/iter" );
		fo << ( file_iter + 10 + file_iter ) % 10 << '\n';
		fo << ( file_iter + 90 + file_last_iter ) % 10;
		fo.close();
	}
	else
	{
		ofstream fo;
		fo.open( "cmbne/iter" );
		fo << i << '\n';
		fo << file_iter;
		fo.close();
	}

	for ( int l = 0; l < i; l = l + 1)
	{
		num_iter = num_iter + num + file_iter % ( l + 2 );
		num_iter = num_iter + i + filenames[ filename_iter ].length() % ( l + 1 );
	}

	num_iter = num_iter + ( i + num + filenames[ filename_iter ].length() + file_iter + 90 ) % ( ( i + filenames[ filename_iter ].length() + file_iter / 2 + 9 ) );

	if ( strings_iter == -1 ) strings_iter = length( filenames );

	num_iter = ( num_iter + file_iter + file_iter ) % strings_iter;
	have_iter = 1;
	return num_iter;
}

bool is_strings ( string a[], int size, string b )
{
	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return 1;
	return 0;
}

void continues ()
{
	char enter;
	cout << "[ ']' + Enter ] to continue: ";
	cin >> enter;
}










int get_file_num ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	int file_iter = 0;
	while ( fi >> temp )
		file_iter = file_iter + 1;

	return file_iter;
}













int main ()
{
	get_filenames();
	string choice;

	for ( int i = 0; i < num; i = i + 1 )
		if ( get_file_num( filenames[ i ] ) == 0 )
			remove_filename( i );

	for ( int i = 1; i < 10000; i = i + 1 )
	{

		cout << "choice";
		cout << "\033c";
		if ( ! have_filename() )
			cout << "Filenames invalid / empty.\n";
		if ( get_iter( i ) != -1 )
		{
			string num_iters[ 10000 ];
			int num_iter = 0;
			int string_iter = 0;
			for ( int l = 0; l < num; l = l + 1 )
			{
				get_strings( filenames[ l ] );
				// cout << '\n' << "num_iter: " << num_iter << '\n';
				string_iter = get_iter( i + l + get_file_iter() + l );
				// cout << "string_iter: " << string_iter << '\n';

				int a = 1;
				while ( is_strings( num_iters, num_iter, strings[ string_iter ] ) )
				{
					string_iter = get_iter( i + a + l + get_file_iter() );
					a = a + l;
					// cout << "string_iter nums: " << string_iter << '\n';
				}

				num_iters[ num_iter ] = strings[ string_iter ];
				num_iter = num_iter + 1;
				cout << strings[ string_iter ] << ' ';
			}
			for ( int l = 0; l < num_iter; l = l + 1 )
				num_iters[ l ] = "";

			cout << "\n\n";
			num_iter = 0;
		}

		cout << "Choices:  1. Add file  2. Remove file  3. Show files\n";
		cout << "Choice: ";

		getline( cin, choice );

		cout << "\033c";

		if ( choice == "1" )
		{
			string filename;
			cout << "Filename to add: ";
			getline( cin, filename );
			if ( filename == "" )
				getline( cin, filename );
			if ( get_file_num( filename ) != 0 )
			{
				add_filename( filename );
				cout << "File added.\n\n";
			}
			else
				cout << "File empty / invalid.\n\n";
			continues();
			continue;
		}

		if ( choice == "2" )
		{
			cout << "Files:\n";
		
			show_filenames();

			int num_temp = 0;
			cout << "File to remove: ";
			cin >> num_temp;
			num_temp = num_temp - 1;
			if ( num_temp >= 0 and num_temp < num )
			{
				string filename = filenames[ num_temp ];
				remove_filename( num_temp );
				cout << "File \"" << filename << "\" removed.\n\n";
			}
			else
				cout << "Invalid num.\n\n";
			continues();
			continue;
		}

		if ( choice == "3" )
		{
			cout << "Files:\n";
		
			show_filenames();	
			continues();
			continue;
		}
	}

	return 0;
}
