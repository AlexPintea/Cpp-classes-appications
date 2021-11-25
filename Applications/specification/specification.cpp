#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int length ( string m[] )
{
	int i = 0;
	for ( ;i<=10; )
	{
		i = i + 1;
	}

	int p = 0;

	while ( m[ p ].length() > 0 )
		p = p + 1;

	return p;
}

string get_title ( string temp )
{
	string result = "";

	for ( int i = 2; i < temp.length(); i = i + 1 )
	{
		if ( temp[ i ] != ':' )
			result = result + temp[ i ];
		else
			break;
	}

	return result;
}

void move_strings ( string file, string strings[], string a )
{
	if ( a.length() == 0 ) return;
	int size = file.length();
	int strings_iter = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( file[ i ] == a[ 0 ] )
		{
			bool have_a = 1;
			int file_iter = i;
			for ( int l = file_iter; l < a.length(); l = l + 1 )
				if ( file[ l ] != a[ l ] )
				{
					have_a = 0;
					break;
				}

			if ( have_a )
			{
				i = i + a.length() - 1;
				strings_iter = strings_iter + 1;
				strings[ strings_iter ] = "";
				continue;
			}
		}
		strings[ strings_iter ] = strings[ strings_iter ] + file[ i ];
	}
}


void get_tags ( string temp, string strings[] )
{
	int i = 2;

	for ( i = 2; i < temp.length(); i = i + 1 )
		if ( temp[ i ] == ':' )
			break;
	i = i + 1;

	string tag_string = "";

	for ( int p = i; p < temp.length(); p = p + 1 )
		tag_string = tag_string + temp[ p ];

	move_strings ( tag_string, strings, ", " );
}

bool is_string_empty ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;

	return 1;
}

void get_file ()
{
	system( "cp \"../apl ).txt\" \"apl ).txt\" " );

	ifstream fi;
	ofstream fo;
	fo.open( "apl.md" );
	fo.close();

	fi.open( "apl ).txt" );
	fo.open( "apl.md" );

	string temp;
	int empty_line_counter = 0;
	string details = "";
	int counter = 0;
	while ( getline( fi, temp ) )
	{
		if ( temp[ 0 ] == ')' )
		{
			empty_line_counter = 0;
			details = "";

			string title = get_title( temp );
			fo << "> __[" << title << "](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/" << title << ")__\n";
			string tags[ 1000 ];
			get_tags( temp, tags );
			for ( int i = 0; i < length( tags ); i = i + 1 )
			{
				fo << "__[" << tags[ i ] << "]__";
				if ( i != length( tags ) - 1 )
					fo << ", ";
			}
			fo << '\n';

			fo << ">> ";

			while ( empty_line_counter < 2 )
			{
				getline( fi, temp );

				if ( is_string_empty( temp ) )
					empty_line_counter = empty_line_counter + 1;
				else
					details = details + temp + '\n';
			} 

			fo << details;

			fo << "\n\n\n\n\n";
			counter = counter + 1;
		}

		if ( temp[ 0 ] == ']' )
		{
			empty_line_counter = 0;
			details = "";

			string title = get_title( temp );
			fo << "> __[" << title << "](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Applications/In%20c%20only/Applications/" << title << ")__\n";
			string tags[ 1000 ];
			get_tags( temp, tags );
			for ( int i = 0; i < length( tags ); i = i + 1 )
			{
				fo << "__[" << tags[ i ] << "]__";
				if ( i == length( tags ) - 1 )
					fo << ", ";
			}
			fo << '\n';

			fo << ">> ";

			while ( empty_line_counter < 2 )
			{
				getline( fi, temp );

				if ( is_string_empty( temp ) )
					empty_line_counter = empty_line_counter + 1;
				else
					details = details + temp + '\n';
			} 

			fo << details;

			fo << "\n\n\n\n\n";
			counter = counter + 1;
		}


		if ( temp[ 0 ] == '}' )
		{
			empty_line_counter = 0;
			details = "";

			string title = get_title( temp );
			fo << "> __[" << title << "](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Ai/" << title << ")__\n";
			string tags[ 1000 ];
			get_tags( temp, tags );
			for ( int i = 0; i < length( tags ); i = i + 1 )
			{
				fo << "__[" << tags[ i ] << "]__";
				if ( i == length( tags ) - 1 )
					fo << ", ";
			}
			fo << '\n';

			fo << ">> ";

			while ( empty_line_counter < 2 )
			{
				getline( fi, temp );

				if ( is_string_empty( temp ) )
					empty_line_counter = empty_line_counter + 1;
				else
					details = details + temp + '\n';
			} 

			fo << details;

			fo << "\n\n\n\n\n";
			counter = counter + 1;
		}

		if ( temp[ 0 ] == '>' )
		{
			empty_line_counter = 0;
			details = "";

			string title = get_title( temp );
			fo << "> __[" << title << "](https://github.com/AlexandruPintea2000/Cpp-libraries-applications/tree/master/Libraries/" << title << ")__\n";
			string tags[ 1000 ];
			get_tags( temp, tags );
			for ( int i = 0; i < length( tags ); i = i + 1 )
			{
				fo << "__[" << tags[ i ] << "]__";
				if ( i == length( tags ) - 1 )
					fo << ", ";
			}
			fo << '\n';

			fo << ">> ";

			while ( empty_line_counter < 2 )
			{
				getline( fi, temp );

				if ( is_string_empty( temp ) )
					empty_line_counter = empty_line_counter + 1;
				else
					details = details + temp + '\n';
			} 

			fo << details;

			fo << "\n\n\n\n\n";
			counter = counter + 1;
		}


	}

	fo.close();
	fi.close();

	system( "cp \"apl.md\" \"../apl.md\" " );

	cout << counter << " titles added to apl.md\n";
}

int main ()
{
	get_file(); // should be 150, not 148 have missing

	return 0;
}
