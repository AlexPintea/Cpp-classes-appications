#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

string filename;
string file = "";


// length of a string[]
int length ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
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

// reduce ' '
void reduce_spaces ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";

	a = result;
}

// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	text = text + " ";

	int size = text.length();

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


int main ()
{

	cout << "Filename in this folder: ";
	getline( cin, filename );


	// gets file
	ifstream fi;
	fi.open( filename );

	string temp;

	while ( getline( fi, temp ) )
		file = file + temp + "\n";

	fi.close();

	if ( file.length() < 1 )
	{
		cout << "File is not available.\n";
		return 0;
	}

	string filename_edited;
	cout << "Filename of file you want to make: ";
	getline( cin, filename_edited );

	reduce_spaces( file );

	string words[ 1000 ];

	move_words( file, words );

	int size_words = length( words );

	ofstream fo;
	fo.open( filename_edited );

	cout << "\n( edit ) Editing \"" << filename_edited << "\" using file: \'" << filename << "\':\n\n";
	for ( int i=0; i<size_words; i=i+1 )
	{
		cout << words[i] << " ";

		if ( words[i][0]  == '[' )
		{
			cout << " - replace with: ";
			string replace;
			getline( cin, replace );

			// reduce spaces
			reduce_spaces( replace );
			if ( replace[0] == ' ' )
				remove_char( replace, 0 );
			if ( replace[ replace.length() - 1 ] == ' ' )
				remove_char( replace, replace.length() - 1 );


			fo << replace << " ";
		}
		else
			fo << words[i] << " ";
	}

	fo.close();


	// show edited file
	file = "";

	fi.open( filename_edited );

	while ( getline( fi, temp ) )
		file = file + temp + "\n";

	fi.close();

	cout << "\n\n( done editing ) File \"" << filename_edited << "\" is now:\n\n";

	cout << file;

	cout << "\n( exited )\n";

	return 0;
}
