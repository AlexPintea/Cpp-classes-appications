#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string ext;
string filepath;
string files[ 90 ] = {};


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;


	return i;

}

void filename_ext ()
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			have_ext = true;

			break;
		}
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












bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
//		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
		if ( a[ l ] >= 'a' and a[ l ] <= 'z' )
			return false;

	return true;
}

void remove_empty_strings ( string a[] )
{
	string result[ 1000 ];
	int i = 0;
	for ( int l = 0; l < length( a ); l = l + 1 )
		if ( ! is_string_empty( a[ l ] ) )
		{
			result[ i ] = a[ l ];
			i = i + 1;
		}


	for ( int l = 0; l <= length( result ); l = l + 1 )
		a[ l ] = result[ l ];
}


void get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );



	for ( int i = 0; i < 90; i = i + 1 )
		files[ i ] = "";

	string temp;
	int l = 0;
	while ( getline( fi, temp ) )
	{
		if ( is_string_empty( temp ) )
			while ( getline( fi, temp ) ) if ( ! is_string_empty( temp ) ) break;

		files[ l ] = files[ l ] + temp + "\n";
		l = l + 1;
	}

	fi.close();

	remove_empty_strings( files );
}

string get_maker_file ( string filename )
{
	ifstream fi;
	fi.open( filename );


	string temp;
	string file = "";
	while ( getline( fi, temp ) )
		file = file + temp + "\n";

	file[ file.length() - 1 ] = ' ';

	fi.close();

	return file;
}


string upper ( string a )
{
	if ( a.length() <= 0 )
		return a;

	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;

	return a;
}





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




string get_title ( string a )
{
	string temps[ 1000 ] = {};

	move_words( a, temps );

	return upper( temps[ 0 ] );
}


void string_to_char (string a, char result[])
{
	int size = a.length();

	int i;

	for (i=0; i<size; i=i+1)
		result[i] = a[i];

	result[i] = '\0';
}
void command ( string command_string )
{
	char command_char[1000];
	string_to_char( command_string, command_char );
	system( command_char );
}



void set_file ()
{
	ofstream fo;
	ifstream fi;

	fo.open( filepath + upper( filename ) + ".html" );

	fo << get_maker_file( "maker_files/site_1" );
	fo << upper( filename );
	fo << get_maker_file( "maker_files/site_2" );
	fo << upper( filename );
	fo << get_maker_file( "maker_files/site_3" );

	for ( int i = 0; i < length( files ); i = i + 1 )
	{
		if ( i % 3 == 2 )
			fo << "\n";

		fo << "\n		<div id=\"" << get_title( files[ i ] ) << "\" style=\"position: relative; top: -45px;\"> </div>";

		if ( i == length( files ) - 1 and ( i - 1 ) % 3 != 2 )
		{
			fo << "\n		<div class=\"parallax\">\n			<div>\n				<h1> ";
			fo << get_title( files [ i ] );
			fo << " </h1>\n				<p>\n				" << files [ i ];
			fo << "				</p>\n			</div>\n		</div>\n\n\n\n\n";
			continue;
		}

		if ( i == length( files ) - 1 and ( i - 1 ) % 3 == 2 )
		{
			fo << "\n		<div class=\"file\">\n			<h1> ";
			fo << get_title( files [ i ] );
			fo << " </h1>\n			<p>\n			" << files [ i ];
			fo << "			</p>\n		</div>\n";
			fo << "\n		<div class=\"parallax\"> </div>\n";
			continue;
		}

		if ( i % 3 == 2 )
		{
			fo << "\n		<div class=\"parallax\">\n			<div>\n				<h1> ";
			fo << get_title( files [ i ] );
			fo << " </h1>\n				<p>\n				" << files [ i ];
			fo << "				</p>\n			</div>\n		</div>\n\n\n\n\n";
		}
		else
		{
			fo << "\n		<div class=\"file\">\n			<h1> ";
			fo << get_title( files [ i ] );
			fo << " </h1>\n			<p>\n			" << files [ i ];
			fo << "			</p>\n		</div>\n";
		}
	}
	fo << "\n		<nav>\n";

	for ( int i = 0; i < length( files ); i = i + 1 )
		fo << "			<a href=\"#" << get_title( files [ i ] ) << "\">" << get_title( files [ i ] ) << "</a>\n";
	fo << "		</nav>\n";

	fo << get_maker_file( "maker_files/site_4" );

	fo << upper( filename );

	fo << get_maker_file( "maker_files/site_5" );

	fo.close();

	command( "mkdir \"" + upper( filename ) + "\"\n" );
	command( "mkdir \"" + upper( filename ) + "/style\"\n" );
	command( "cp \"" + filepath + upper( filename ) + ".html" + "\" \"" +  upper( filename ) + "/index.html\"\n" );
	command( "cp \"maker_files/style.css\" \"" +  upper( filename ) + "/style/style.css\"\n" );
	command( "rm \"" + upper( filename ) + ".html\"\n" );
}


int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );
	filename_ext();
	get_file( filename );
	set_file();



	return 0;
}
