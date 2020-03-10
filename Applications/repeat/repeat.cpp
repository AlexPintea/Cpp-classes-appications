#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

string usual_words[ 1000 ] = {
"a", "is", "this", "thi", "", "", "", "", "", "", "", "", ""
};

string filename;
string file = "";
string words[ 1000 ];

// length of a string[]
int length ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
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
		if ( !( a[i] >= 'a' and a[i] <= 'z' ) and !( a[i] >= 'A' and a[i] <= 'Z' ) )
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
	int size = length( words );

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


// used in determine is a word is in a   string[]  
bool is_in_words( string a[], string word )
{
	int size = length( a );

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == word )
			return true;

	return false;
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

// used in determine how many time a word is in a string[]  
int count ( string a[], string word )
{
	int size = length( a );
	int iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == word )
			iter = iter + 1;

	return iter;
}

// swaps strings
void swap ( string &a, string &b )
{
	string aux = a;
	a = b;
	b = aux;
}

// swaps ints
void swap ( int &a, int &b )
{
	int aux = a;
	a = b;
	b = aux;
}


// orders words by count
void order_words_by_count ( string words[], int counts[] )
{
	int size = length( words );

	for ( int i=0; i<size-1; i=i+1 )
		for ( int l=i+1; l<size; l=l+1 )
			if ( counts[l] > counts[i] )
			{
				swap( words[l], words[i] );
				swap( counts[l], counts[i] );
			}
}

int main ()
{

	cout << "Filename in this folder: ";
	getline( cin, filename );


	// gets file
	ifstream fi;
	fi.open( filename );

	string temp;

	while ( getline( fi, temp ) )
		file = file + temp + "\n";

	fi.close();

	if ( file.length() < 1 )
	{
		cout << "File is not available.\n";
		return 0;
	}
	
	// removes usual words, plurals etc.
	remove_chars( file );
	move_words( file, words );
	for ( int i=0; i<length( words ); i=i+1 )
	{
		if ( words[i][ words[i].length() -1 ] == 's' )
			remove_plural( words[i] );

		if ( words[i].length() < 3 )
		{
			remove_word( words, words[i] );
			i = i - 1;
		}

		if ( is_in_words( usual_words, words[i] ) )
		{
			remove_word( words, words[i] );
			i = i - 1;
		}
	}

	// count how many times a word appears in the text, and store 
	int count_words[ 1000 ];
	string remaining_words[ 1000 ];
	int iter = 0; 

	int count_word;
	
	for ( int i=0; i<length( words ); i=i+1 )
		if ( !is_in_words( remaining_words, words[i] ) )
		{
			count_words[ iter ] = count( words, words[i] );
			remaining_words[ iter ] = words[i];
			iter = iter + 1;
		}

	// order words by their count
	order_words_by_count( remaining_words, count_words );


	// show the 10 (or less) most used words
	int max_size = 10;

	if ( length( remaining_words ) < 10 )
		max_size = length( remaining_words );

	cout << "Words used a lot:\n";
	for ( int i=0; i<max_size; i=i+1 )
		cout << i + 1 << ") \"" << remaining_words[i] << "\" - used " << count_words[i] << " times.\n";
	
	return 0;
}
