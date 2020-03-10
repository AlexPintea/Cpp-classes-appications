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


string filename_strings[1000];
int file_iter = 0;

int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}


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


// used in determine if a word is in a   string[]  
bool is_in_words( string a[], string word )
{
	int size = length( a );

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == word )
			return true;

	return false;
}

// used in determine position of a word in a   string[]  
int pos_in_words( string a[], string word )
{
	int size = length( a );

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == word )
			return i;

	return -1;
}


// empties a string[]
void empty( string a[] )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
		a[i] = "";
}

// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{

	empty( words );

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





// Files





// inverts a string
void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}

// converts an int to a string
string int_to_string (int a)
{
	int size = length(a);

	bool is_neg = false;
	if ( a < 0 )
	{
		is_neg = true;
		a = -a;
	}

	string result = "";

	for (int i=0; i<size; i=i+1)
	{	
		char a_char = (char) (a % 10 + 48);

		result = result + a_char;
		a = a / 10;
	}

	if ( is_neg )
		result = result + '-';

	invert_string( result );

	return result;
}


int file_count ( string counter_filename )
{
	int file_counter = 0;

	ifstream fi;
	fi.open( counter_filename );
	fi >> file_counter;
	if ( file_counter == 0 )
	{
		fi.close();

		// make the file if not already made
		ofstream fo;
		fo.open( counter_filename );
		fo << 1;
		fo.close();

		return 1;
	}
	fi.close();


	file_counter = file_counter + 1;


	// clear counter_file
	ofstream f;
	f.open( counter_filename );
	f.close();


	f.open( counter_filename );
	f << file_counter;
	f.close();

	return file_counter;
}

// gets files
void get_filenames ()
{
	// get filenames
	ifstream fi;
	fi.open( "your_files/filenames" );
	fi >> file_iter;

	if ( file_iter == 0 )
	{
		fi.close();

		// make the file if not already made
		ofstream fo;
		fo.open( "your_files/filenames" );
		fo << 0;
		fo.close();

		return;
	}

	for ( int i=0; i<file_iter; i=i+1 )
		fi >> filename_strings[i];
	fi.close();
}



// gets files
void get_files( string &files )
{
	get_filenames();


	files = "";


	// gets files
	string temp;
	ifstream fi;
	for ( int i=0; i<file_iter; i=i+1 )
	{
		fi.open( "your_files/" + filename_strings[i] );

		while ( getline( fi, temp ) )
			files = files + temp + "\n";

		fi.close();
	}
}


// add file
void add_file ( string filename )
{
	// clears the file
	ofstream fo;
	fo.open( "your_files/filenames" );
	fo.close();

	fo.open( "your_files/filenames" );

	fo << file_iter + 1 << "\n";
	for ( int i=0; i<file_iter; i=i+1 )
		fo << filename_strings[i] << " ";
	fo << filename;

	fo.close();

	get_filenames();
}






int main ()
{



	// Now



	// gets previous files now ( and their filenames ) to not count twice the current file
	string files;
	get_files( files );

	cout << "Your text: ";
	getline( cin, file );
	cout << "\n";

	int file_counter = file_count( "your_files/counter" );
	filename = "your_files/your_text_" + int_to_string( file_counter );
	add_file(  "your_text_" + int_to_string( file_counter )  );

	ofstream fo;
	fo.open( filename );
	fo << file;
	fo.close();
	

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

	cout << "Words you used a lot now:\n";
	for ( int i=0; i<max_size; i=i+1 )
		cout << i + 1 << ") \"" << remaining_words[i] << "\" - used " << count_words[i] << " times.\n";
	cout << "\n";




	// Files




	// removes usual words, plurals etc.
	remove_chars( files );
	move_words( files, words );
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



	
	for ( int i=0; i<length( words ); i=i+1 )
		if ( is_in_words( remaining_words, words[i] ) )
		{
			int l = pos_in_words( remaining_words, words[i] );
			count_words[ l ] = count_words[ l ] + 1;
		}
		else
		{
			count_words[ iter ] = count( words, words[i] );
			remaining_words[ iter ] = words[i];
			iter = iter + 1;
		}


	// order words by their count
	order_words_by_count( remaining_words, count_words );


	// show the 10 (or less) most used words
	max_size = 10;

	if ( length( remaining_words ) < 10 )
		max_size = length( remaining_words );

	cout << "Words you use a lot:\n";
	for ( int i=0; i<max_size; i=i+1 )
		cout << i + 1 << ") \"" << remaining_words[i] << "\" - used " << count_words[i] << " times.\n";
	cout << "\n";

	
	
	return 0;
}
