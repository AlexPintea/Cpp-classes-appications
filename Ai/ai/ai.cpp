#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string strings[ 10000 ];
int valid[ 100000 ];
int strings_iter = 0;



int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}


void clear_string ( string &a )
{
	string result = "";

	for ( int i = 1; i < a.length() - 1; i = i + 1 )
		result = result + a[ i ];

	a = result;
}







void get_string_valid ( string a, string &strings, string &valids )
{
	bool is_valid = 0;
	strings = "";
	valids = "";
	for ( int i = 0; i < a.length(); i = i + 1 )
	{
		if ( i > 0 )
			if ( a[ i ] == ' ' and a[ i - 1 ] == '"' and is_valid == 0 )
			{
				is_valid = 1;
				continue;
			}

		if ( is_valid )
			valids = valids + a[ i ];
		else
			strings = strings + a[ i ];
	}
}

void get_file ()
{
	ifstream fi;

	fi.open( "strings" );

	string temp;
	string valid_temp;
	while ( getline( fi, temp ) )
	{
		get_string_valid( temp, strings[ strings_iter ], valid_temp );

		if ( valid_temp == "1" )
			valid[ strings_iter ] = 1;
		else
			valid[ strings_iter ] = -1;

		strings_iter = strings_iter + 1;
	}


	for ( int i = 0; i < strings_iter; i = i + 1 )
		clear_string( strings[ i ] );

	fi.close();
}


void add_file ( string a, int b )
{
	ofstream fo;

	fo.open( "strings" );
	bool have_string = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( a == strings[ i ] )
		{
			fo << "\"" << a << "\" " << b;
			have_string = 1;
			continue;
		}
			
		fo << "\"" << strings[ i ] << "\" " << valid[ i ] << "\n";
	}


	if ( ! have_string )
		fo << "\"" << a << "\" " << b;


	fo.close();
}


// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}




// reduces ' '-s
void reduce_spaces ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ' and a[i] != '	' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";
	a = result;
}


int count_words ( string a[], string b[], bool order )
{
	int count = 0;

	int b_iter = 0;

	for ( int i = 0; i < length( a ); i = i + 1 )
		for ( int l = 0; l < length( b ); l = l + 1 )
		{
			if ( ! order )
			{
				if ( a[ i ] == b[ l ] )
					count = count + 1;
			}
			else
			{
				if ( a[ i ] == b[ l ] and l > b_iter )
				{
					count = count + 1;				
					b_iter = l;
				}
			}
		}
	return count;
}




int verify ( string a )
{
	string words[ 100000 ] = {};

	move_words( a, words );
	int maximum = -1;
	int valids_0 = 0;
	int valids_1 = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( a == strings[ i ] )
		{
			cout << "Validity certainty: precise.\n";
			return valid[ i ];
		}

		string words_temp[ 100000 ] = {};

		move_words( strings[ i ], words_temp );

		int count;
		count = count_words( words, words_temp, 0 );

		int count_order;
		count_order = count_words( words, words_temp, 1 );


		// cout << '"' << a << "\", \"" << strings[ i ] << "\" " << count << ' ' << count_order << "\n";

		if ( count >= maximum and count > 1 )
		{
			// cout << strings[ i ] << ' ' << valid[ i ] << "\n";

			maximum = count;
			if ( valid[ i ] == 1 )
				valids_1 = valids_1 + 1;
			else
				valids_0 = valids_0 + 1;




			if ( maximum - count_order < 5 )
			{
				if ( valid[ i ] == 1 )
					valids_1 = valids_1 + 2;
				else
					valids_0 = valids_0 + 2;
			}				
		}
	}


	if ( valids_1 > valids_0 )
		cout << "Validity certainty: " << valids_1 << " / " << valids_0 + valids_1 << "\n";


	if ( valids_1 < valids_0 )
		cout << "Validity certainty: " << valids_0 << " / " << valids_0 + valids_1 << "\n";


	if ( valids_1 == valids_0 )
		return 0;

	if ( valids_1 > valids_0 )
		return 1;

	if ( valids_1 < valids_0 )
		return -1;
}






void lower ( string &a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			a[ i ] = a[ i ] + 32;
}


int main ()
{
	get_file();
	string a;
	cout << "Statement: ";



	



	getline( cin, a );
	lower( a );
	reduce_spaces( a );
	cout << "\n";
	int is_valid = verify( a );

	if ( is_valid == 0 )
		cout << "Insufficient data.\n\n";

	if ( is_valid == 1 )
		cout << "Statement is valid.\n\n";

	if ( is_valid == -1 )
		cout << "Statement is invalid.\n\n";




	if ( is_valid != 0 )
	{
		int b;
		string l;
		cout << "Verifies? ( y / n ): ";
		getline( cin, l );
		if ( l == "" )
			getline( cin, l );

		if ( l == "y" and is_valid == -1 )
			b = -1;

		if ( l != "y" and is_valid == -1 )
			b = 1;

		if ( l == "y" and is_valid == 1 )
			b = 1;

		if ( l != "y" and is_valid == 1 )
			b = -1;

		add_file ( a, b );

	}
	else
	{
		string l;
		cout << "Valid statement? ( y / n ): ";
		getline( cin, l );
		if ( l == "" )
			getline( cin, l );

		if ( l == "y" )
			add_file( a, 1 );
		else
			add_file( a, -1 );					
	}



	return 0;
}
