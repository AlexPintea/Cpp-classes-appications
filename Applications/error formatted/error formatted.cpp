#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string get_file ( string filename )
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

string get_string ( string p )
{
	string result = "";

	for ( int i = 0; i < p.length(); i = i + 1 )
	{
		if ( p[ i ] == '\n' )
		{
			result = result + "\\n";
			continue;
		}

		result = result + p[ i ];
	}

	return result;
}

void alarm ( string title, string text )
{
	ofstream fo;
	fo.open ( "file1.cpp" );

	string file = get_file( "data/part" );

	fo << file;
	fo << "	system( \"printf \\\\\\\\033c\" );\n";
	fo << "	color( \"!!!\", \"b\", \"w\", \"r\" );\n";
	fo << "	color( \" \", \"b\", \"w\", \"w\" );\n";
	fo << "		color( set_string_char ( upper ( \"" + get_string( title ) + "\" ), \" -\", \"- \" ), \"b\", \"w\", \"r\" );\n";
	fo << "	color( \" \", \"b\", \"w\", \"w\" );\n";
	fo << "	color( \"!!!\", \"b\", \"w\", \"r\" );\n";
	fo << "	system( \"printf \\" << "\"\\n\\n\\" << "\"\" );\n";
	fo << "	color( set_string_line ( \"" + get_string( text ) + "\", \" -\", \"- \" ), \"b\", \"w\", \"cy\" );\n";
	fo << "	system( \"printf \\" << "\"\\n\\n\\" << "\"\" );\n";
	fo << "	system( \"printf \\" << "\"\\n\\n\\" << "\"\" );\n";
	fo << "	system( \"sleep 0.5\" );\n";
	fo << "	system( \"./file2\" );\n";
	fo << "	return 0;\n";
	fo << "}\n";

	fo.close();

	fo.open ( "file2.cpp" );

	fo << file;
	fo << "	system( \"printf \\\\\\\\033c\" );\n";
	fo << "	system( \"printf \\" << "\"\\n\\n\\" << "\"\" );\n";
	fo << "	color( set_string_line ( \"" + get_string( text ) + "\", \" -\", \"- \" ), \"b\", \"w\", \"cy\" );\n";
	fo << "	system( \"printf \\" << "\"\\n\\n\\" << "\"\" );\n";
	fo << "	system( \"printf \\" << "\"\\n\\n\\" << "\"\" );\n";
	fo << "	system( \"sleep 0.5\" );\n";
	fo << "	system( \"./file1\" );\n";
	fo << "	return 0;\n";
	fo << "}\n";

	fo.close();

	system( "cd data && cp ../file2.cpp file2.cpp && g++ -L a.out file2.cpp && mv a.out file2 && cp ../file1.cpp file1.cpp && g++ -L a.out file1.cpp && mv a.out file1 && ./file1 && cd ../ " );
}

int main ()
{
	cout << "\\033C";
	alarm( "fle", "fle fle\nfle\nfle\nfle\n\nfle\n" );	

	return 0;
}
