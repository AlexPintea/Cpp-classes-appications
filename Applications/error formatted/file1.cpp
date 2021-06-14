#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

void color ( string a, string l, string f, string b )
{
	string line = "\\e[";

	if ( l == "b" )
	{
		line = line + "1;";
	}

	if ( l == "d" )
	{
		line = line + "2;";
	}

	if ( l == "i" )
	{
		line = line + "3;";
	}

	if ( l == "u" )
	{
		line = line + "4;";
	}

	if ( l == "l" )
	{
		line = line + "9;";
	}





	if ( f == "bk" )
	{
		line = line + "30m";
	}

	if ( f == "r" )
	{
		line = line + "31m";
	}

	if ( f == "g" )
	{
		line = line + "32m";
	}

	if ( f == "y" )
	{
		line = line + "33m";
	}

	if ( f == "b" )
	{
		line = line + "34m";
	}

	if ( f == "p" )
	{
		line = line + "35m";
	}

	if ( f == "cy" )
	{
		line = line + "36m";
	}

	if ( f == "gr" )
	{
		line = line + "37m";
	}

	if ( f == "w" )
	{
		line = line + "39m";
	}



	if ( b == "bk" )
	{
		line = line + "\\e[40m%s\\e[0m";
	}

	if ( b == "r" )
	{
		line = line + "\\e[41m%s\\e[0m";
	}

	if ( b == "g" )
	{
		line = line + "\\e[42m%s\\e[0m";
	}

	if ( b == "y" )
	{
		line = line + "\\e[43m%s\\e[0m";
	}

	if ( b == "b" )
	{
		line = line + "\\e[44m%s\\e[0m";
	}

	if ( b == "p" )
	{
		line = line + "\\e[45m%s\\e[0m";
	}

	if ( b == "cy" )
	{
		line = line + "\\e[46m%s\\e[0m";
	}

	if ( b == "gr" )
	{
		line = line + "\\e[47m%s\\e[0m";
	}

	if ( b == "w" )
	{
		line = line + "\\e[49m%s\\e[0m";
	}



	ofstream fo;

	fo.open( "color.sh" );

	fo << "color=$( less -FX \"color\" )\n";
	fo << "rm -R \"color\"\n";
	fo << "text=$( less -FX \"text\" )\n";
	fo << "rm -R \"text\"\n\n";
	fo << "printf $color \"$text\"\n";
	fo << "rm -R \"color.sh\"\n\n";

	fo.close();

	system( "chmod 767 color.sh" );

	fo.open( "color" );
	fo << line;
	fo.close();
	fo.open( "text" );
	fo << a;
	fo.close();

	system( "./color.sh" );
}

// Formats:

// b - bold
// d - dim
// i - itlic
// u - underline
// l - line


// Colors:

// bk
// r
// g
// y
// b
// p
// cy
// gr
// w


string set_string ( string a, string l1, string l2 )
{
	int size = a.length();

	if ( size == 0 ) return a;

	string result = "";
	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( ( a[ i ] == ' ' or a[ i ] == '\n' or a[ i ] == '	' ) and ( i > 0 and i < size - 1 ) )
		{
			if ( a[ i + 1 ] == ' ' or a[ i + 1 ] == '\n' or a[ i + 1 ] == '	' )
				if ( a[ i - 1 ] == ' ' or a[ i - 1 ] == '\n' or a[ i - 1 ] == '	' )
				{
					result = result + a[ i ];
					continue;
				}

			if ( a[ i - 1 ] != ' ' and a[ i - 1 ] != '\n' and a[ i - 1 ] != '	' )
				result = result + l2;
			result = result + a[ i ];
			if ( a[ i + 1 ] != ' ' and a[ i + 1 ] != '\n' and a[ i + 1 ] != '	' )
				result = result + l1;
			continue;
		}

		if ( ( a[ i ] == ' ' or a[ i ] == '\n' or a[ i ] == '	' ) and i > 0 )
		{
			result = result + l2 + a[ i ];	
			continue;
		}

		result = result + a[ i ];
	}


	if ( a[ 0 ] != ' ' and a[ 0 ] != '\n' and a[ 0 ] != '	' )
		result = l1 + result;

	if ( a[ size - 1 ] != ' ' and a[ size - 1 ] != '\n' and a[ size - 1 ] != '	' )
		result = result + l2;

	return result;
}

string set_string_line ( string a, string l1, string l2 )
{
	int size = a.length();

	if ( size == 0 ) return a;

	string result = "";

	int l;
	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
		{
			l = i;
			break;
		}

		result = result + a[ i ];
	}		


	int p;
	for ( int i = size - 1; i >= 0; i = i - 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
		{
			p = i;
			break;
		}


	result = result + l1;
	for ( int i = l; i <= p; i = i + 1 )
		result = result + a[ i ];
	result = result + l2;

	for ( int i = p + 1; i < size; i = i + 1 )
		result = result + a[ i ];


	return result;
}

string set_string_char ( string a, string l1, string l2 )
{
	int size = a.length();

	if ( size == 0 )
		return a;

	string result = "";
	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( a[ i ] == ' ' or a[ i ] == '\n' or a[ i ] == '	' )
		{
			result = result + a[ i ];
			continue;
		}

		result = result + l1 + a[ i ] + l2;
	}

	return result;
}

string upper ( string a )
{
	int size = a.length();

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] >= 'a' and a[ i ] <= 'z' )
			a[ i ] = a[ i ] - 32;

	return a;
}

string large_char (string a)
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}



int main ()
{

	system( "printf \\\\033c" );
	color( "!!!", "b", "w", "r" );
	color( " ", "b", "w", "w" );
		color( set_string_char ( upper ( "fle" ), " -", "- " ), "b", "w", "r" );
	color( " ", "b", "w", "w" );
	color( "!!!", "b", "w", "r" );
	system( "printf \"\n\n\"" );
	color( set_string_line ( "fle fle\nfle\nfle\nfle\n\nfle\n", " -", "- " ), "b", "w", "cy" );
	system( "printf \"\n\n\"" );
	system( "printf \"\n\n\"" );
	system( "sleep 0.5" );
	system( "./file2" );
	return 0;
}
