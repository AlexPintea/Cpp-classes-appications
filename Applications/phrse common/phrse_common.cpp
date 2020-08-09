#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string common[ 10000 ];
int common_iter = 0;

void get_common ()
{
	ifstream fi;
	fi.open( "common" );

	string temp;
	while ( fi >> temp )
	{
		common[ common_iter ] = temp;
		common_iter = common_iter + 1;
	}

	fi.close();
}



int move_strings ( string text, string temps[] )
{
	text = text + " ";

	int size = text.length();

	int temps_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			temps_iter = temps_iter + 1;
			temps[ temps_iter ] = "";
		}
		else
			temps[ temps_iter ] = temps[ temps_iter ] + text[i];
	return temps_iter;
}


bool is_common ( string a )
{
	for ( int i = 0; i < common_iter; i = i + 1 )
		if ( common[ i ] == a )
			return 1;
	return 0;
}








void set_file ()
{
	string strings[ 10000 ];
	int strings_iter = 0;

	string temps[ 10000 ];
	int temps_iter = 0;


	ofstream fo;
	fo.open( "result" );
	fo.close(); // clear file


	fo.open( "result" );

	ifstream fi;
	fi.open( filename );

	string temp;
	int common_temp;
	while ( getline( fi, temp ) )
	{
		common_temp = 0;
		temps_iter = move_strings( temp, temps );
		for ( int i = 0; i < temps_iter; i = i + 1 )
			if ( is_common( temps[ i ] ) )
				common_temp = common_temp + 1;

		if ( common_temp < temps_iter / 2 )
			fo << temp << '\n';
	}

	fi.close();

	fo.close();
}


int main ()
{
	get_common();

	cout << "Filename: ";

	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	set_file();

	return 0;
}
