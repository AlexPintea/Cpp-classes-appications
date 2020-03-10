#include <fstream>
#include <string>
#include <iostream>

using namespace std;

char allowed[15] = { ';', ')', '}', '(', '{', '\"', '\'', ',', '>', ' ', '	', '\n' };

bool is_in_allowed ( char a )
{
	for ( int i=0; i<15; i=i+1 )
		if ( a == allowed[i] )
			return true;

	return false;
}


// returns position of "//"
int pos_comment ( string a )
{
	for ( int i=0; i<a.length()-1; i=i+1 )
		if ( a[i] == '/' and a[i+1] == '/' )
			return i;

	return -1;
}

char last_before_comment ( string a, int comment_iter )
{
	int last_before = 0;

	for ( int i=0; i<comment_iter; i=i+1 )
		if ( a[i] != ' ' and a[i] != '	' )
			last_before = i;

	return a[ last_before ];
}

void verify ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	int line_num = 1;
	string file = "";
	while ( getline( fi, temp ) )
	{
		char last_char = temp[ temp.length() - 1 ];

		if ( temp.length() >= 2 )
		{
			int pos = pos_comment( temp );

			if ( pos == 0 )
			{
				line_num = line_num + 1;
				continue;
			}

			if ( pos != -1 )
				last_char = last_before_comment( temp, pos );
		}

		file = file + temp + "\n";

		if ( !is_in_allowed( last_char ) )
			cout << "Invalid line " << line_num << ".\n";

		if ( last_char == '\"' or last_char == '\'' )
			cout << "Possibly invalid line " << line_num << ".\n";

		line_num = line_num + 1;
	}

	if ( file.length() == 0 )
		cout << "Filename invalid. Retry.\n";

	fi.close();
}

int main ()
{
	string filename;
	cout << "Filename: ";

	getline( cin, filename );

	verify( filename );

	return 0;
}
