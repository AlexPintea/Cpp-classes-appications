#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename = "";
int num = 0;
string strings[ 10000 ];
int strings_iter = 0;

int length ( int a[] )
{
	int i = 0;


	while ( a[ i ] != 0 )
		i = i + 1;
	return i;
}

int get_strings ()
{
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

void get_filename ()
{
	ifstream fi;
	fi.open( "cmbne/filename" );

	fi >> filename;

	fi.close();
}

void set_filename ()
{
	string file = "";
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( fi >> temp )
		file = file + temp + '\n';

	ofstream fo;
	fo.open( "cmbne/filename" );
	fo.close(); // clear file

	fo.open( "cmbne/filename" );

	fo << filename;

	fo.close();
}





void get_num ()
{
	ifstream fi;
	fi.open( "cmbne/num" );

	fi >> num;

	fi.close();
}
void set_num ()
{
	ofstream fo;
	fo.open( "cmbne/num" );
	fo.close(); // clear file

	fo.open( "cmbne/num" );

	fo << num;

	fo.close();
}


bool have_filename() { if ( strings_iter != 0 ) return 1; return 0; }
bool have_num() { if ( num > 0 ) return 1; return 0; }


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
	if ( ! have_filename() or ! have_num() )
		return -1;

	if ( i % 9 == 0 and i != 0 )
		return strings_iter - 1;

	int num_iter = 0;


	int file_iter = get_file_iter();

	int file_last_iter = get_last_file_iter();

	// cout << file_iter << ' ' << file_last_iter << '\n';

	if ( file_last_iter == file_iter or file_last_iter == 0 or have_iter == 0 )
		file_iter = get_file_length() + file_last_iter;

	if ( have_iter == 0 )
	{
		ofstream fo;
		fo.open( "cmbne/iter" );
		fo << ( file_iter + 10 + file_iter ) % strings_iter << '\n';
		fo << ( file_iter + 90 + file_last_iter ) % strings_iter;
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
		num_iter = num_iter + i + filename.length() % ( l + 1 );
	}

	num_iter = num_iter + ( i + num + filename.length() + file_iter + 90 ) % ( i + num + filename.length() + 9 );
	num_iter = ( num_iter + file_iter + file_iter ) % strings_iter;
	have_iter = 1;
	return num_iter;
}





bool is_nums ( int a[], int size, int b )
{
	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return 1;
	return 0;
}


int main ()
{
	get_filename();
	get_num();
	get_strings();
	string choice;

	for ( int i = 0; i < 10000; i = i + 1 )
	{
		cout << "choice";
		cout << "\033c";
		if ( ! have_filename() )
			cout << "Filename \"" << filename << "\" invalid / empty.\n";
		if ( ! have_num() )
			cout << "Num " << num << " invalid.\n";

		if ( get_iter( i ) != -1 )
		{
			int num_iters[ 10000 ];
			int num_iter = 0;
			int string_iter = 0;
			for ( int l = 0; l < num; l = l + 1 )
			{
				// cout << '\n' << "num_iter: " << num_iter << '\n';
				string_iter = get_iter( i + l + get_file_iter() + l );
				// cout << "string_iter: " << string_iter << '\n';

				int a = 1;
				while ( is_nums( num_iters, num_iter, string_iter ) )
				{
					string_iter = get_iter( i + a + l + get_file_iter() );
					a = a + l;
					// cout << "string_iter nums: " << string_iter << '\n';
				}

				num_iters[ num_iter ] = string_iter;
				num_iter = num_iter + 1;
				cout << strings[ string_iter ] << ' ';
			}
			for ( int l = 0; l < num_iter; l = l + 1 )
				num_iters[ l ] = 0;

			cout << "\n\n";
			num_iter = 0;
		}

		cout << "Choices:  1. Set file  2. Set num\n";
		cout << "Choice: ";



		getline( cin, choice );


		if ( choice == "1" )
		{
			cout << "Filename: ";
			getline( cin, filename );
			if ( filename == "" )
				getline( cin, filename );
			set_filename();
			get_strings();
		}

		if ( choice == "2" )
		{
			int num_temp = 0;
			cout << "Num: ";
			cin >> num_temp;
			if ( num_temp > 0 )
			{
				num = num_temp;
				set_num();
			}
			else
				cout << "Invalid num.\n";
		}
	}

	return 0;
}
