#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string typos[ 1000 ];
int typos_iter = 0;

int length ( string p[] )
{
	int i = 0;

	while ( p[ i ].length() > 0 )
		i = i + 1;

	return i;
}

void get_words ( string a, string words[] )
{
	int size = a.length();

	int words_size = length( words );
	for ( int p = 0; p < words_size; p = p + 1 )
		words[ p ] = "";

	int counter = 0;

	a = a + " ";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			counter = counter + 1;
		else
			words[ counter ] = words[ counter ] + a[i];
}


bool is_in_strings ( string words[], string word )
{
	int size = length( words );

	for ( int i=0; i<size; i=i+1 )
		if ( word == words[i] )
			return true;

	return false;
}






void sort_and_reduce_duplicates ()
{
	for ( int i1 = 0; i1 < typos_iter - 1; i1 = i1 + 1 )
		for ( int i2 = i1 + 1; i2 < typos_iter; i2 = i2 + 1 )
		{
			if ( typos[ i1 ] > typos[ i2 ] )
			{
				string temp = typos[ i1 ];
				typos[ i1 ] = typos[ i2 ];
				typos[ i2 ] = temp;
			}

			string typ1[ 1000 ];
			string typ2[ 1000 ];

			get_words( typos[ i1 ], typ1 );
			get_words( typos[ i2 ], typ2 );

			if ( typ1[ 0 ] == typ2[ 0 ] )
			{
				for ( int i = 1; i < length( typ2 ); i = i + 1 )
					if ( ! is_in_strings( typ1, typ2[ i ] ) )
					typos[ i1 ] = typos[ i1 ] + ' ' + typ2[ i ];

				for ( int i = i2; i < typos_iter - 1; i = i + 1 )
					typos[ i ] = typos[ i + 1 ];

				typos_iter = typos_iter - 1;
			}
		}
}

void set_file ()
{
	sort_and_reduce_duplicates();

	ofstream fo;

	fo.open( "data" );

	for ( int i = 0; i < typos_iter; i = i + 1 )
		fo << typos[ i ] << '\n';
	
	fo.close();
}

void get_file ()
{
	ifstream fi;

	fi.open( "data" );

	string temp;

	while ( getline( fi, temp ) )
	{
		typos[ typos_iter ] = temp;
		typos_iter = typos_iter + 1;
	}

	fi.close();

	if ( typos_iter == 0 )
	{
		cout << "You are welcomed to the application.\n";

		ofstream fo;
		fo.open( "data" );
		fo.close(); // make / clear "data" file
	}

	sort_and_reduce_duplicates();

	set_file();
}





string lower ( string p )
{
	int size = p.length();

	for ( int i = 0; i < size; i = i + 1 )
		if ( p[ i ] >= 'A' and p[ i ] <= 'Z' )
			p[ i ] = p[ i ] + 32;

	return p;
}

// checks if  a  is in  b   or   b  is in  a  for datatype "string"
bool a_is_in_b ( string a, string b )
{
	if (a == b)
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	return a_is_in_b( a, b );
}

// a[] and b[] have iters
bool is_in ( int a[], int b[], int size, int iter )
{
	for ( int i=0; i<size; i=i+1 )
		if ( iter >= a[i] and iter <= b[i] )
			return true;

	return false;
}

// replace  b  in  a  for datatype "string"
string replace_b_in_a ( string &a, string b, string replacement )
{
	if ( !b_is_in_a( a, b ) )
		return a;

	int size_a = a.length();
	int size_b = b.length();

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}


	for ( int i=0; i<size_a; i=i+1 )
	{
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			result = result + a[i];
		else
		{
			result = result + replacement;
			while ( is_in( iter_1, iter_2, size_iter, i ) )
				i = i + 1;
			i = i - 1;
		}
	}

	a = result;

	return a;
}

void upper_sentances ( string &file )
{
	bool have_sentance = 0;
	int size = file.length();

	int p = 0;

	while ( file[ p ] == ' ' or file[ p ] == '	' or file[ p ] == '\n' )
		p = p + 1;

	if ( file[ p ] >= 'a' and file[ p ] <= 'z' )
			file[ p ] = file[ p ] - 32;

	for ( int i = p + 1; i < size; i = i + 1 )
	{
		if ( file[ i ] == '.' or file[ i ] == '?' or file[ i ] == '!' )
			have_sentance = 1;

		if ( have_sentance and file[ i ] >= 'a' and file[ i ] <= 'z' )
		{
			have_sentance = 0;
			file[ i ] = file[ i ] - 32;
		}

		if ( have_sentance and file[ i ] >= 'A' and file[ i ] <= 'Z' )
			have_sentance = 0;
	}
}

void typo ( string &m )
{
	string typo = "";

	string typ[ 1000 ];

	m = lower( m );

	for ( int i = 0; i < typos_iter; i = i + 1 )
	{
		get_words( typos[ i ], typ );

		// cout << typ[ 0 ] << ' ' << typ[ 1 ] << " \n";

		for ( int p = 1; p < length( typ ); p = p + 1 )
			replace_b_in_a( m, typ[ p ], typ[ 0 ] );
	}

	upper_sentances( m );
}

void add_file ( string filename )
{
	ifstream fi;

	fi.open( filename );	

	string temp;
	string file = "";

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	if ( file == "" )
	{
		cout << "File not available.\n";
		return;
	}

	typo( file );

	ofstream fo;

	fo.open( filename );
	fo.close(); // clear file

	fo.open( filename );

	fo << file;

	fo.close();

	cout << "File was comlpeted.\n";
}

void show_typos ()
{
	if ( typos_iter == 0 )
	{
		cout << "When you add your typos, you can see them here.\n";
		return;
	}

	cout << "Available typos: \n";

	string typ[ 1000 ];

	for ( int i = 0; i < typos_iter; i = i + 1 )
	{
		get_words( typos[ i ], typ );

		cout << typ[ 0 ];

		if ( i != typos_iter - 1 ) 
			cout << ", ";
	}

	cout << "\n\n";
}

void show_words_and_typos ()
{
	if ( typos_iter == 0 )
	{
		cout << "When you add your typos, you can see them here.\n";
		return;
	}

	cout << "Available words and typos: \n";

	string typ[ 1000 ];

	for ( int i = 0; i < typos_iter; i = i + 1 )
	{
		get_words( typos[ i ], typ );

		cout << typ[ 0 ] << ": ";

		for ( int p = 1; p < length( typ ); p = p + 1 )
		{
			cout << typ[ p ];
			if ( p != length( typ ) - 1 ) 
				cout << ", ";
		}

		cout << '\n';
	}

	cout << "\n";
}

void show_words_for_typo ( string typo, int &counter, string wrds[] )
{
	string typ[ 1000 ];

	counter = 0;

	for ( int i = 0; i < typos_iter; i = i + 1 )
	{
		get_words( typos[ i ], typ );

		if ( is_in_strings( typ, typo ) )
		{
			cout << typ[ 0 ] << ' ';
			wrds[ counter ] = typ[ 0 ];
			counter = counter + 1;
		}
	}

	cout << "\n";
}


bool remove_typo_for_word ( string typo, string word )
{
	string typ[ 1000 ];

	for ( int i = 0; i < typos_iter; i = i + 1 )
	{
		get_words( typos[ i ], typ );

		if ( typ[ 0 ] == word )
		{
			typos[ i ] = "";

			for ( int p = 0; p < length( typ ); p = p + 1 )
			{
				if ( typ[ p ] == typo and p != 0 )
					continue;

				typos[ i ] = typos[ i ] + typ[ p ];
			}

			set_file();

			return 1;
		}
	}

	return 0;
}








int main ()
{
	get_file();

	cout << "Choices:  1. Add file  2. Add typo  3. Remove typo  4. Show typos\n";
	cout << "Choice: ";

	string choice;

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "1" )
	{
		cout << "Filename: ";

		string filename;

		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		add_file( filename );
	}

	if ( choice == "2" )
	{
		show_typos();

		string wrd;
		string typo;

		cout << "Well-typed word: ";

		cin >> wrd;

		cout << "Typos ( only separated by space ): ";

		getline( cin, typo );
		if ( typo == "" )
			getline( cin, typo );

		typos[ typos_iter ] = wrd + ' ' + typo;
		typos_iter = typos_iter + 1;

		set_file();
		cout << "Saved typos.\n";
	}

	if ( choice == "3" )
	{
		show_words_and_typos();

		cout << "Typo you want to remove: ";

		string typo;
		string wrds[ 1000 ];
		int counter;

		cin >> typo;

		show_words_for_typo ( typo, counter, wrds );

		if ( counter == 0 )
			cout << "Not available.\n";

		if ( counter == 1 )
			remove_typo_for_word( typo, wrds[ 0 ] );

		if ( counter > 1 )
		{
			for ( int i = 0; i < counter; i = i + 1 )
			{
				cout << "Remove typo '" << typo << "' for word \"" << wrds[ i ] << "\" ( y / n ): ";

				getline( cin, choice );
				if ( choice == "" )
					getline( cin, choice );

				if ( choice == "y" )
					remove_typo_for_word( typo, wrds[ i ] );
			}
		}

		cout << "Saved typos.\n";
	}

	if ( choice == "4" )
	{
		show_words_and_typos();
	}

	cout << "Finalied. ";
	cout << "Enough. ";
	cout << "Exited.\n";

	// replaces any string, not just words, to preserve formatting

	return 0;
}
