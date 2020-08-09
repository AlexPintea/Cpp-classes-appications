#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;



// file



int counter = 0;

// clears a file
void clear_file ( string filename )
{
	ofstream f; // have to have ofstream
	f.open( filename );
	f.close();
}

// makes file that stores our counter
void make_count_file ()
{
	ofstream f;
	f.open( "counter" );
	f << 0;
	f.close();
}

// get the count stored in the "counter" file
void get_count()
{
	fstream f;
	f.open( "counter" );
	f >> counter;
	f.close();
}

// increases and saves counter if "count" file
int count()
{
	get_count();

	fstream f;
	make_count_file();
	clear_file ( "counter" );
	make_count_file();

	f.open( "counter" );
	counter = counter + 1;
	f << counter;
	f.close();

	return counter;
}

// increases counter by data and saves counter if "count" file
int count( int data )
{
	get_count();

	fstream f;
	make_count_file();
	clear_file ( "counter" );
	make_count_file();

	f.open( "counter" );
	counter = counter + data;
	f << counter;
	f.close();

	return counter;
}

// deecreases and saves counter if "count" file
int count_reverse()
{
	get_count();

	fstream f;
	make_count_file();
	clear_file ( "counter" );
	make_count_file();

	f.open( "counter" );
	counter = counter - 1;
	f << counter;
	f.close();

	return counter;
}

// decreases counter by data and saves counter if "count" file
int count_reverse( int data )
{
	get_count();

	fstream f;
	make_count_file();
	clear_file ( "counter" );
	make_count_file();

	f.open( "counter" );
	counter = counter - data;
	f << counter;
	f.close();

	return counter;
}

// reset counter
void reset ()
{
	counter = 0;

	make_count_file();
	clear_file( "counter" );
	make_count_file();
}

// set counter
void set_counter ( int data )
{
	counter = data;

	fstream f;
	make_count_file();
	clear_file ( "counter" );
	make_count_file();

	f.open( "counter" );
	f << counter;
	f.close();
}

int main ()
{
	cout << "\'" << count() << "\'\n";

	return 0;
}
