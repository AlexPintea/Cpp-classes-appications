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


int main ()
{
	color( "text\na", "b", "bk", "r" );

	return 0;
}
