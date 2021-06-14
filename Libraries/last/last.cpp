#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

// invert a string
string invert_string (string a)
{
	int len = a.length();
	string r = "";

	for (int i=len-1; i>=0; i=i-1)
	{
		r = r + a[i];
	}
	cout << "\n";

	return r;
}


// to continue
void continues ()
{
	char chars;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> chars;
	cout << "\n";

	string empty; // to continue
	getline( cin, empty );
}
// replaces spaces in entered data, to make valid variable names
void replace_space (string &a)
{
	for (int i=0; i<a.length(); i=i+1)
		if ( a[i] == ' ' )
			a[i] = '_';
}

// removes a char in a string
void remove_char( string &a, int iter )
{
	if ( iter < 0 or iter >=a.length() )
		return;

	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
			result = result + a[i];

	a = result;
}

// remove chars
void remove_chars ( string &a )
{
	int size = a.length();

	// replace chars with ' '
	for ( int i=0; i<size; i=i+1 )
	{
		if ( !( a[i] >= 'a' and a[i] <= 'z' ) and !( a[i] >= 'A' and a[i] <= 'Z' ) and !( a[i] >= '0' and a[i] <= '9' ) )
			a[i] = ' ';
		if ( a[i] >= 'A' and a[i] <= 'Z' )
			a[i] = a[i] + 32;
	}


	string result = "";

	// reduce ' '-s
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ')
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";


	// delete last ' '
	if ( result[ result.length() - 1 ] == ' ' )
		remove_char( result, result.length() - 1 );

	// delete initial ' '
	if ( result[ 0 ] == ' ' )
		remove_char( result, 0 );

	a = result;
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

// reduce ' '
void reduce_spaces ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";

	a = result;
}

// removes plurals
void remove_plural( string &word )
{
	string plural_removed = "";
	int size = word.length();

	for ( int i=0; i<size - 2; i=i+1 )
		plural_removed = plural_removed + word[i];

	if ( word[size - 2] != 'e' )
 		plural_removed = plural_removed + word[size - 2];

	word = plural_removed;
}

// remove a  word  in  words[]  
void remove_word ( string words[], string word )
{
	string word_removed[10000];
	int iter = 0;

	int size = 0;
	while ( words[ size ].length() > 0 )
		size = size + 1;


	for ( int i=0; i<size; i=i+1 )
		if ( words[i] != word )
		{
			word_removed[ iter ] = words[i];
			iter = iter + 1;
		}

	for ( int i=0; i<size; i=i+1 )
		words[i] = "";

	for ( int i=0; i<iter; i=i+1 )
		words[i] = word_removed[i];
}

bool is_numeric ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= '0' and a[i] <= '9' ) or a[i] == '.' ) )
			return false;

	return true;
}

bool has_decimals ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == '.' )
			return true;

	return false;
}

string datatype ( string a )
{
	if ( is_numeric( a ) )
	{
		if ( has_decimals( a ) )
		{
			return "double";
		}
		else
		{
			if ( a.length() <= 9 )
			{	
				if ( a == "1" or a == "0" )
					return "bool";
				else
					return "int";
			}
			else
				return "long";
		}
	}
	else
	{
		if ( a.length() == 1 )
			return "char";
		else
		{
			if ( a == "true" or a == "false" )
				return "bool";
			else
				return "string";
		}
	}

	return "-1";
}


int main ()
{
	return 0;
}
