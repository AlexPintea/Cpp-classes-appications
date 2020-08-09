#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


void get_filenames ( string folder, string strings[] )
{
	ofstream fo;
	fo.open( "files-ls" );
	fo.close(); // clear file

	fo.open( "files-ls" );
	fo << folder;
	fo.close();

	int strings_iter = 0;

	char command_linux[] = "./code.sh";
	system ( command_linux );

	ifstream fi;
	fi.open( "files-ls" );
	string temp;
	string temps[ 10000 ];
	int temps_iter = 0;

	while ( getline( fi, temp ) )
	{
		temps[ temps_iter ] = temp;
		temps_iter = temps_iter + 1;
	}

	fi.close();	



	string result;
	for ( int i = 0; i < temps_iter; i = i + 1 )
	{
		temp = temps[ i ];
		bool have_char = 0;
		for ( int l = 0; l < temp.length(); l = l + 1 )
			if ( temp[ l ] == ',' )
			{
				have_char = 1;
				break;
			}

		result = "";
		if ( have_char )
			temp[ temp.length() - 1 ] = '\0';
		result = temp;

		if ( have_char )
		{
			strings[ strings_iter ] = strings[ strings_iter ] + result;			
			strings_iter = strings_iter + 1;
			strings[ strings_iter ] = "";
		}
		else
			strings[ strings_iter ] = strings[ strings_iter ] + result;			
	}
}




int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}

int main ()
{
	string folder;
	string filenames[ 10000 ];

	cout << "Files path: ";
	getline( cin, folder );
	if ( folder == "" )
		getline( cin, folder );

	get_filenames( folder, filenames );
	for ( int i = 0; i < length( filenames ); i = i + 1 )
		cout << '\'' << filenames[ i ] << "'\n";		

	return 0;
}
