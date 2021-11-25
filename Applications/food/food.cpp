#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


struct food 
{
	string title = "";
	string mentions[ 50 ];
	int mentions_iter = 0;
	string incredients[ 50 ];
	int incredients_iter = 0;
	string preparation = "";
};

food foods[ 1000 ];
int foods_iter = 0;

string title = "";
string author = "";

// )title: fle, fle, fle, fle
// incredients
// incredients
// incredients
// ]incredients
// 
// preparation
// preparation
// (

string get_data_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	return file;
}

int length ( string p[] )
{
	int i = 0;

	while ( p[ i ].length() > 0 )
		i = i + 1;

	return i;
}

string reduce_spaces ( string p )
{
	int i1 = 0;
	int i2 = p.length() - 1;
	string result = "";

	for ( int i = 0; i < p.length(); i = i + 1 )
		if ( ! ( p[ i ] == ' ' or p[ i ] == '	' ) )
		{
			i1 = i;
			break;
		}

	for ( int i = p.length() - 1; i >= 0; i = i - 1 )
		if ( ! ( p[ i ] == ' ' or p[ i ] == '	' ) )
		{
			i2 = i;
			break;
		}

	for ( int i = i1; i <= i2; i = i + 1 )
		result = result + p[ i ];

//	cout << "(" << result << ") ";

	return p;
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

bool is_string_empty( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
}

void get_food ( string filename )
{
	ifstream fi;
	fi.open( filename );

	while ( is_string_empty( title ) )
		getline( fi, title );

	while ( is_string_empty( author ) )
		getline( fi, author );

	string temp;

	int l;

	while ( getline( fi, temp ) )
	{
		if ( temp[ 0 ] == ')' )
		{
			int i = 1;

			while ( temp[ i ] != ':' )
			{
				foods[ foods_iter ].title = foods[ foods_iter ].title + temp[ i ];
				i = i + 1;
			}
			i = i + 1;

			string remaining = "";

			for ( int p = i; p < temp.length(); p = p + 1 )
				remaining = remaining + temp[ p ];

			move_strings( remaining, foods[ foods_iter ].mentions, ", " );
			foods[ foods_iter ].mentions_iter = length( foods[ foods_iter ].mentions );

			for ( int p = 0; p < foods[ foods_iter ].mentions_iter; p = p + 1 )
			{
				foods[ foods_iter ].mentions[ p ] = reduce_spaces( foods[ foods_iter ].mentions[ p ] );
			}

			while ( getline( fi, temp ) )
			{
				if ( is_string_empty( temp ) )
					break;

				reduce_spaces( temp );
				foods[ foods_iter ].incredients[ foods[ foods_iter ].incredients_iter ] = temp;
				foods[ foods_iter ].incredients_iter = foods[ foods_iter ].incredients_iter + 1;
			}

			while ( getline( fi, temp ) )
			{
				if ( temp == "(" )
					break;
				foods[ foods_iter ].preparation = foods[ foods_iter ].preparation + temp + '\n';
			}
//			remove_char( foods[ foods_iter ].preparation, foods[ foods_iter ].preparation.length() - 1 ); 
			foods_iter = foods_iter + 1;
		}
	}

	fi.close();
}

void set_food ( string filename )
{
	ofstream fo;

	fo.open( filename );

	fo << get_data_file( "data/before" );
	fo << title << "\n\n";
	fo << get_data_file( "data/title author" );
	fo << author << "\n\n";
	fo << get_data_file( "data/before food" );

	for ( int i = 0; i < foods_iter; i = i + 1 )
	{
		fo << "\\fakesection{" << foods[ i ].title << "}\n\n";
		fo << "\\colorbox{Blue}{\\textcolor{white}{\\heading " << foods[ i ].title << "}}\n\n";

		fo << "\\lisible\n";
		fo << "\\vspace{16pt}\n";
		fo << "\\begin{multicols}{2}\n";
		fo << "\\begin{enumerate}[font={\\Large\\color{Blue!50!black}\\nums}]\n";

		for ( int p = 0; p < foods[ i ].incredients_iter; p = p + 1 )
		{
			fo << "\\item ";
			fo << foods[ i ].incredients[ p ] << "\n";
		}

		for ( int p = 0; p < foods[ i ].mentions_iter; p = p + 1 )
		{
			fo << "\\item ";
			if ( p != 0 )
				fo << "  ";
			else
				fo << " ";

			fo << foods[ i ].mentions[ p ] << "\n";
		}

		fo << "\\end{enumerate}\n";
		fo << "\\end{multicols}\n";
		fo << "\\AddToShipoutPictureBG*{\\includegraphics[width=\\paperwidth,height=\\paperheight]{style.jpg}}\n";
		fo << "\\vspace{11pt}\n";

		fo << "\\noindent \\textcolor{white}{ " << foods[ i ].preparation << "}\n\n";

		fo << "\\vspace{10pt}\n\\newpage\n";
	}

	fo << "\\end{document}";
	fo.close();
}

int main ()
{
	get_food( "food" );
	set_food( "result.tex" );
	cout << "food ";

	int p;

	return 0;
}
