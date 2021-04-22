#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;


	return i;

}

void get_file ( string filename, string files[], string title[] )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	int l = 0;

	files[ 0 ] = "";

	while ( getline( fi, temp ) )
	{
		// skip empty
		bool is_empty = 1;
		for ( int i = 0; i < temp.length(); i = i + 1 )
			if ( temp[ i ] != ' ' and temp[ i ] != '	' and temp[ i ] != '\n' )
			{
				is_empty = 0;
				break;
			}

		if ( ! is_empty )
		{
			files[ l ] = files[ l ] + temp + "\n";
			continue;
		}

		if ( is_empty )
		{
			l = l + 1;
			files[ l ] = "";
			while ( getline( fi, temp ) )
			{
				for ( int i = 0; i < temp.length(); i = i + 1 )
					if ( temp[ i ] != ' ' and temp[ i ] != '	' and temp[ i ] != '\n' )
					{
						is_empty = 0;
						break;
					}
				
				if ( is_empty == 0 ) break;
			}
		}

		files[ l ] = files[ l ] + temp + "\n";
	}

	l = l + 1;


	fi.close();


	// remove last char
	for ( int i = 0; i < l; i = i + 1 )
	{
		string result = "";
		temp = files[ i ];
		for ( int m = 0; m < temp.length() - 1; m = m + 1 )
			result = result + temp[ m ];
		files[ i ] = result;
	}

	// extract title
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];

		int temp_iter = 0;

		while ( temp[ temp_iter ] == ' ' or temp[ temp_iter ] == '	' ) temp_iter = temp_iter + 1;

		if ( temp_iter >= l ) break;

		int iter_1 = -1;
		int iter_2 = -1;

		title[ i ] = "";

		if ( temp[ temp_iter ] == '"' )	
		{
			iter_1 = temp_iter;
			temp_iter = temp_iter + 1;
			while ( temp[ temp_iter ] and temp[ temp_iter ] != '"' )
				temp_iter = temp_iter + 1;

			if ( temp[ temp_iter ] == '"' )
				iter_2 = temp_iter;
		}
		else
			continue;

		files[ i ] = "";

		if ( iter_1 != -1 and iter_2 != -1 )
		{
			for ( int m = iter_1 + 1; m < iter_2; m = m + 1 )
				title[ i ] = title[ i ] + temp[ m ];

			for ( int m = iter_2 + 1; m < temp.length(); m = m + 1 )
				files[ i ] = files[ i ] + temp[ m ];			
		}
	}

	// replace '	' with ' ' and reduce ' '
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];
		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] == '	' )
				temp[ m ] = ' ';
		files[ i ] = temp;

		temp = title[ i ];
		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] == '	' )
				temp[ m ] = ' ';
		title[ i ] = temp;



		temp = files[ i ];
		string result = "";
		bool have_space = 0;

		for ( int m = 0; m < temp.length(); m = m + 1 )
		{
			result = result + temp[ m ];

			if ( temp[ m ] == ' ' )
				have_space = 1;

			while ( temp[ m ] == ' ' )
				m = m + 1;

			if ( have_space )
				m = m - 1;
			have_space = 0;
		}

		files[ i ] = result;


		temp = title[ i ];
		result = "";
		have_space = 0;

		for ( int m = 0; m < temp.length(); m = m + 1 )
		{
			result = result + temp[ m ];

			if ( temp[ m ] == ' ' )
				have_space = 1;

			while ( temp[ m ] == ' ' )
				m = m + 1;

			if ( have_space )
				m = m - 1;
			have_space = 0;
		}

		title[ i ] = result;
	}

	// trim for ' ', "\n " and // remove title '.'
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];
		string result = "";

		int iter_1 = -1;
		int iter_2 = -1;

		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '\n' )
			{
				iter_1 = m;
				break;
			}

		for ( int m = temp.length() - 1; m >= 0; m = m - 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '\n' )
			{
				iter_2 = m;
				break;
			}

		for ( int m = iter_1; m <= iter_2; m = m + 1 )
		{
			if ( temp[ m ] == '\n' )
			{
				if ( m > 0 and temp[ m - 1 ] != '.' )
					result = result + '.';
				result = result + '\n';
				while ( temp[ m ] and ( temp[ m ] == '\n' or temp[ m ] == ' ' ) )
					m = m + 1;
			}

			result = result + temp[ m ];
		}

		files[ i ] = result;

		temp = title[ i ];
		result = "";

		iter_1 = -1;
		iter_2 = -1;

		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '	' and temp[ m ] != '\n' )
			{
				iter_1 = m;
				break;
			}

		for ( int m = temp.length() - 1; m >= 0; m = m - 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '	' and temp[ m ] != '\n' )
			{
				iter_2 = m;
				break;
			}

		for ( int m = iter_1; m <= iter_2; m = m + 1 )
		{
			if ( temp[ m ] == '\n' )
			{
				if ( m > 0 and temp[ m - 1 ] != '.' )
					result = result + '.';
				result = result + '\n';
				while ( temp[ m ] and ( temp[ m ] == '\n' or temp[ m ] == ' ' ) )
					m = m + 1;
			}

			// remove '.', leave ".."
			// if ( m == iter_2 and temp[ m ] == '.' and temp[ m - 1 ] and temp[ m - 1 ] != '.' )
			// 	break;

			result = result + temp[ m ];
		}

		title[ i ] = result;
	}

	// make large first letter, // add '.' to files
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];
		if ( temp[ 0 ] >= 'a' and temp[ 0 ] <= 'z' )
			temp[ 0 ] = temp[ 0 ] - 32;
		for ( int m = 0; m < temp.length(); m = m + 1 )
		{
			if ( temp[ m ] == '\n' and m < temp.length() - 1 )
				if ( temp[ m + 1 ] >= 'a' and temp[ m + 1 ] <= 'z' )
					temp[ m + 1 ] = temp[ m + 1 ] - 32;
		}

		// if ( temp[ temp.length() - 1 ] != '.' )
		//	temp = temp + '.';
		// files[ i ] = temp;
			

		temp = title[ i ];
		if ( temp[ 0 ] >= 'a' and temp[ 0 ] <= 'z' )
			temp[ 0 ] = temp[ 0 ] - 32;
		title[ i ] = temp;
	}

}






int main ()
{
	string files[ 150 ] = {};
	string title[ 150 ] = {};

	get_file( "file", files, title );

	for ( int i = 0; i < length( files ); i = i + 1 )
	{
		cout << '"' << title[ i ] << "\"\n";
		cout << "'" << files[ i ] << "'\n";
	}

	return 0;
}
