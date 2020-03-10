#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;


string get_file_data ( string filename );
void set_file_data ( string filename, string data );

// make a file
void make_file ( string filename )
{
	string previous_file_data = get_file_data( filename );

	if ( previous_file_data != "" )
		return;

	ofstream f; // have to have ofstream
	f.open( filename );
	f.close();
}

// clear a file
void clear_file ( string filename )
{
	string previous_file_data = get_file_data( filename );

	if ( previous_file_data == "" )
		return;

	ofstream f; // have to have ofstream
	f.open( filename );
	f.close();
}

// rename a file
void rename_file ( string filename_1, string filename_2 )
{
	string file_data = get_file_data( filename_1 );

	make_file( filename_2 );

	set_file_data ( filename_2, file_data );
}

// get copy filename
void get_copy_filename ( string &filename, string copy_string )
{
	bool verif = false;
	for ( int i=0; i<filename.length(); i=i+1 )
		if ( filename[i] == '.' )
			verif = true;

	if ( verif )
	{
		// filename 1
		string filename_1 = "";
		string filename_2 = "";
		int i=0;
		while ( filename[i] != '.' )
		{
			filename_1 = filename_1 + filename[i];
			i=i+1;
		}
		i=i+1;
		for ( int l=i; l<filename.length(); l=l+1 )
			filename_2 = filename_2 + filename[l];

		filename = filename_1 + " " + copy_string + "." + filename_2;
	}
	else
		filename = filename + " " + copy_string;

}

// copy a file
void copy_file ( string filename )
{
	string file_data = get_file_data( filename );

	get_copy_filename( filename, "(copy)" );

	make_file( filename );

	set_file_data ( filename, file_data );
}

// copy a file including a counterr in the filename
void copy_file_count ( string filename )
{
	// counter in file
	int counter = 0;
	ifstream fi;
	fi.open( "counter" );
	fi >> counter;
	fi.close();
	if ( counter == 0 )
		make_file( "counter" );

	counter = counter + 1;

	fstream fo;
	fo.open( "counter" );
	fo << counter;
	fo.close();

	// counter as string
	string counter_string = "";
	while ( counter != 0 )
	{
		counter_string = counter_string + (char) ( counter%10 + 48 );
		counter = counter / 10;
	}
	string inverted_counter_string = "";
	for ( int i=counter_string.length() - 1; i>=0; i=i-1 )
		inverted_counter_string = inverted_counter_string + counter_string[i];
	counter_string = inverted_counter_string;


	// make copied file


	string file_data = get_file_data( filename );

	get_copy_filename( filename, "(" + counter_string + ")" );

	make_file( filename );

	set_file_data ( filename, file_data );
}

// get file data
string get_file_data ( string filename )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();

	return file;
}

// set file data
void set_file_data ( string filename, string data )
{
	// set file data
	ofstream fo;
	fo.open( filename );

	fo << data;

	fo.close();

}

// add to a file
void add_to_file ( string filename, string data )
{
	string file_data = get_file_data( filename );

	file_data = file_data + data;

	set_file_data( filename, file_data );
}

// add line to a file
void add_line_to_file ( string filename, string data )
{
	string file_data = get_file_data( filename );

	file_data = file_data + "\n" + data;

	set_file_data( filename, file_data );
}

// add word to a file
void add_word_to_file ( string filename, string data )
{
	string file_data = get_file_data( filename );

	file_data = file_data + " " + data;

	set_file_data( filename, file_data );
}



// File that stores a counter



int file_count ( string name )
{
	string counter_filename = name + "_counter";

	int file_counter = 0;

	ifstream fi;
	fi.open( counter_filename );
	fi >> file_counter;
	if ( file_counter == 0 )
	{
		fi.close();

		// make the file if not already made
		ofstream fo;
		fo.open( counter_filename );
		fo << 1;
		fo.close();


		return 1;
	}
	fi.close();


	file_counter = file_counter + 1;


	// clears the file
	clear_file( counter_filename );


	ofstream fo;
	fo.open( counter_filename );
	fo << file_counter;
	fo.close();

	return file_counter;
}




int main ()
{

	cout << file_count( "files" ); // makes file "files_counter"

	make_file( "file_1" );

	add_to_file( "file_1", "data\n\n\n" );

	copy_file_count ( "file_1" );

//	clear_file( "file_1" );

	return 0;
}
