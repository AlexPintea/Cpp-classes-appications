#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

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

// converts a string to a char array
void string_to_chars ( string a, char chars[] ) 
{
	int size = a.length();

	int i;

	for ( i=0; i<size; i=i+1 )
		chars[i] = a[i];
	chars[i] = '\0';
}

// linux command
void command_linux ( string command_string )
{
	char command_chars[1000];
	string_to_chars( command_string, command_chars );
	system( command_chars );
}

// inverts a string
string invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	return b;
}

string type ( string file )
{
	bool is_type = false;
	int type_iter;
	int size = file.length();
	for ( int i=size - 1; i>=0; i=i-1 )
		if ( file[i] == '.' )
		{
			is_type = true;
			type_iter = i;
			break;
		}
	if ( is_type == false )
		return "";

	string result = "";
	for ( int i=size - 1; i>type_iter; i=i-1 )
		result = result + file[i];

	return invert_string( result );
}

void unzip_unrar ( string filepath )
{
	// clears the file
	ofstream fo;
	fo.open( "unzip-ls" );
	fo.close();


	// sets "unzip-ls" to our filepath
	fo.open( "unzip-ls" );
	fo << filepath;
	fo.close();

	sleep( 4 );

	command_linux( "./unzip.sh" );

//	sleep( 0.1 );


//	string data_string;
//	string data[1000];
//	ifstream fi;
//	fi.open( "unzip-ls" );
//	fi >> data_string;
//	fi.close();
//	move_words( data_string, data );

//	for ( int i=0; i<length(data); i=i+1 )
//	{
//		if ( type( data[i] ) == "zip" )
//			command_linux( "unzip " + data[i] );

//		if ( type( data[i] ) == "rar" )
//			command_linux( "unrar " + data[i] );
//	}
}

int main ()
{
	unzip_unrar( "/home/account/Computer/Proiecte/Dupa_Scoala/Info/Cpp/Done/Cpp-classes-applications/Applications/unzip" );

	return 0;
}
