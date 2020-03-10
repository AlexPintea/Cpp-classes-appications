#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

int length ( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
		i=i+1;

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

void espeak ( string data )
{
	command_linux( "espeak " + data );
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


void fors ()
{
	for ( int i=0; i<10000; i=i+1 )
		for ( int l=0; l<10700; l=l+1 )
			int a = 0;
}

int main ()
{
	string filename;
	cout << "Enter filename: ";
	getline( cin, filename );

	ifstream fi;
	fi.open( filename );

	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + "\n";

//	file = "\"" + file + "\"";

	fi.close();

	string words[1000];
	move_words( file, words );

	int size = length( words );

	for ( int i=0; i<size; i=i+1 )
	{
		fors();
		espeak( words[i] );
	}	
	return 0;
}
