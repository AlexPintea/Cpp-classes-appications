#include <string>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

fstream usual_words;




// Intermediary




// clear file
void clear ( string filename )
{
	// remake file
	ofstream f;
	f.open( filename );
	f.close();
	f.open( filename );
	f.close();
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

// determine nr of digits in a number
int int_size (int a)
{
	int i=0;

	while (a!=0)
	{
		i=i+1;
		a=a/10;
	}

	return i;
}

// converts an int to a string
string int_to_string (int a)
{
	int size = int_size(a);

	string result = "                       ";

	for (int i=0; i<size; i=i+1)
	{		
		result[ size - i - 1 ] = a % 10 + 48;
		a = a / 10;
	}

	string result_clear = "";

	for (int i=0; i<size; i=i+1)
		if ( result[i] != ' ' )
			result_clear = result_clear + result[i];

	result = result_clear;

	return result;
}

// Show \"[ ']' + Enter ] to continue
void enter()
{
	char enter;
	cout << "\n[ \']\' + Enter ] to continue: ";
	cin >> enter;
	cout << "\n";
}




// File count ( to make filenames )





// file count to make filenames
int file_count = 0;

// gets the  file_count  of file  count_file  
void get_file_count ()
{
	fstream count_file;
	count_file.open( "count_file" );

	count_file >> file_count;

	count_file.close();
}


// increases file count
void increase_file_count ()
{
	get_file_count();

	clear( "count_file" );

	ofstream count_file;
	count_file.open( "count_file" );

	// increase  file_count
	file_count = file_count + 1;

	clear( "count_file" );

	count_file << file_count;

	count_file.close();
}



// returns the increased   file_count  as a string
string count()
{
	increase_file_count();

	return int_to_string( file_count );
}





// Word modifiying







// empty words
void empty_words( string words[] )
{
	int length_words = length( words );

	for ( int i=0; i<length_words; i=i+1 )
		words[i] = "";
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

bool is_numeric ( char a );

// leave digits
void leave_digits ( string &a )
{
	int size = a.length();

	if ( size == 1  and is_numeric( a[0] ) )
		return;

	// replace chars with ' '
	for ( int i=0; i<size; i=i+1 )
		if ( !( a[i] >= '0' and a[i] <= '9' ) )
			a[i] = ' ';


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


// word count
int word_count ( string text )
{
	// removes chars
	remove_chars( text );

	int counter = 0;
	int size = text.length();

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
			counter = counter + 1;

	return counter + 1;
}

// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	// empties words
	empty_words( words );

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

// show words
void show_words( string words[] )
{
	int words_iter = length( words );
	
	for ( int i=0; i<words_iter; i=i+1 )
	{
		cout << '\'' << words[i] << "\'";
		if ( i != words_iter - 1 )
			cout << ", ";
	}
}






// Usual words







string usual_words_strings[10000]; // usual words
int usual_iter = 0;

// get usual words
void get_usual_words()
{
	usual_words.open( "usual_words" );
	
	usual_words >> usual_iter;

	for ( int i=0; i<usual_iter; i=i+1 )
	{
		usual_words >> usual_words_strings[i];
		remove_chars( usual_words_strings[i] );
	}
	usual_words.close();
}

// set usual words
void set_usual_words()
{
	get_usual_words();
	clear ( "usual_words" );
	usual_words.open( "usual_words" );
	
	usual_words << usual_iter << "\n";

	for ( int i=0; i<usual_iter; i=i+1 )
		usual_words << usual_words_strings[i] << " ";
	
	usual_words.close();
	get_usual_words();
}

// makes sure not to add the same word
bool is_usual_word( string word )
{
	get_usual_words();
	remove_chars( word );

	for ( int i=0; i<usual_iter; i=i+1 )
	{
		if ( usual_words_strings[i] == word )
			return true;
	}

	return false;
}

// copy string1[] to string2[]
void copy ( string string1[], string string2[] )
{
	empty_words( string2 );

	int size = length( string1 );

	for ( int i=0; i<size; i=i+1 )
		string2[i] = string1[i];
}

// used in determine is a word is in a   string[]  
bool is_in_words( string a[], string word )
{
	int size = length( a );

	for ( int i=0; i<size; i=i+1 )
	{
		if ( a[i] == word )
		{
			return true;
		}
	}

	return false;
}

// count appearances of a word in a   string[]    
int count_appearances( string words[], string word )
{
	int size = length( words );
	int counter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( words[i] == word )
			counter = counter + 1;

	return counter;
}

string copies_removed[1000];

// remove word copies
void remove_copies( string words[] )
{
	int size = length( words );

	int removed_iter = 0;
	empty_words( copies_removed );

	for ( int i=0; i<size; i=i+1 ) // last word does not pass this
		if ( !is_in_words ( copies_removed, words[i] ) )
		{
			copies_removed[ removed_iter ] = words[i];
			removed_iter = removed_iter + 1;
		}


	// delete initial words[]
	empty_words( words );

	// set    words[]   to   cleared_words[]    
	for ( int i=0; i<removed_iter; i=i+1 )
		if ( copies_removed[i] != "" )
			words[i] = copies_removed[i];

	empty_words( copies_removed );
}

// clear usual words
void clear_usual_words( string words[] )
{
	int size = length( words );

	// make temp.  cleared_words[]
	string cleared_words[100000];
	int cleared_size = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( !is_usual_word( words[i] ) and !is_in_words( cleared_words, words[i] ) and words[i].length() > 2 )
		{
			cleared_words[ cleared_size ] = words[i];
			cleared_size = cleared_size + 1;
		}

	// delete initial words[]
	empty_words( words );

	// set    words[]   to   cleared_words[]    
	for ( int i=0; i<cleared_size; i=i+1 )
		words[i] = cleared_words[i];

	empty_words( cleared_words );
}

// add usual word
void add_usual_word( string word )
{
	get_usual_words();

	if ( word == "" )
	{
		cout << "[ empty ] Entered word is empty / is not a word, so it was not added.\n";
		return;
	}

	// check if it was not already added
	if ( is_usual_word( word ) )
	{
		cout << "[ already added ] Word \'" << word << "\' was already added to usual words.\n";
		return;
	}

	clear ( "usual_words" );
	usual_words.open( "usual_words" );
	
	usual_words << usual_iter + 1 << "\n";

	for ( int i=0; i<usual_iter; i=i+1 )
		usual_words << usual_words_strings[i] << " ";
	usual_words << word << " ";
	
	usual_words.close();
	get_usual_words();

	cout << "( added ) Word \'" << word << "\' was added to usual words.\n";
}

void remove_word( string words[], string word );

// remove usual word
void remove_usual_word( string word )
{
	get_usual_words();

	if ( word == "" )
	{
		cout << "[ empty ] Entered word is empty / is not a word, it is not a usual word.\n";
		return;
	}

	// check if it is a usual word
	if ( !is_usual_word( word ) )
	{
		cout << "[ !usual ] Word \'" << word << "\' is not a usual word. Removal is not necessary.\n";
		return;
	}

	clear ( "usual_words" );
	usual_words.open( "usual_words" );
	
	usual_words << usual_iter - 1 << "\n";

	for ( int i=0; i<usual_iter + 1; i=i+1 )
		if ( usual_words_strings[i] != word )
			usual_words << usual_words_strings[i] << " ";

	remove_word( usual_words_strings, word );
	
	usual_words.close();
	get_usual_words();

	cout << "( removed ) Usual word \'" << word << "\' was removed.\n";
}

// show usual words
void show_usual_words()
{
	cout << "Usual words: ";
	show_words( usual_words_strings );
	cout << ".\n";
}


// make  usual_words
void make_usual_words_file()
{
	ofstream usual_words_ofstream;
	usual_words_ofstream.open( "usual_words" );
	cout << "( usual words file ) Usual words file was reset to \"0\"\n";
	usual_words_ofstream << 0 << "\n";
	usual_words_ofstream.close();
}



// Edit words




// if last char is 's', add the word also with that char deleted ( "this" and also "thi" )
string usual[30] = {
"that", "this", "thi", ""
};

string inner[30] = { 
"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" ,
"in", "un", "ly", "able" 
};

// checks if  a  is in  word  
bool is_in_string ( string a, string word )
{
	int size = word.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[0] == word[i] )
		{
			int l;

			for ( l=1; l<a.length(); l=l+1 )
			{
				if ( a[l] != word[ i + l ] )
					break;
			}

			if ( l == a.length() )
				return true;
		}

	return false;
}

// is numeric
bool is_numeric ( char a )
{
	if ( a >= '0' and a <= '9' )
		return true;

	return false;
}


// numeric char to int
int numeric_char_to_int( char a )
{
	if ( a == '0' ) return 0;
	if ( a == '1' ) return 1;
	if ( a == '2' ) return 2;
	if ( a == '3' ) return 3;
	if ( a == '4' ) return 4;
	if ( a == '5' ) return 5;
	if ( a == '6' ) return 6;
	if ( a == '7' ) return 7;
	if ( a == '8' ) return 8;
	if ( a == '9' ) return 9;

	return -1;
}

// checks if a strin has a digit in it
bool has_numeric ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( is_numeric( a[i] ) )
			return true;

	return false;
}

// convert string to int
int string_to_int ( string a )
{
	int size = a.length();

	int iter = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		iter = 1;
	}

	int num_int = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_int = num_int * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_int = -num_int;

	return num_int;
}

// removes  a  in  word  
void remove_inner ( string a , string &word )
{
	int size = word.length();
	int iter; // a[0]
	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( a[0] == word[i] )
		{
			int l;
			int l_copy = i;

			for ( l=1; l<a.length(); l=l+1 )
			{
				if ( a[l] != word[ i + l ] )
					break;
			}

			if ( l == a.length() )
				iter = l_copy;
		}

	for ( int i=0; i<size; i=i+1 )
		if ( i < iter or i > iter + a.length() - 1 )
			result = result + word[i];

	word = result;
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

	empty_words( words );

	for ( int i=0; i<iter; i=i+1 )
		words[i] = word_removed[i];
}

// removes plurals and more
void edit_words( string words[] )
{
	string remove_words[10000];
	int iter = 0;
	int size = length( words );

	for ( int i=0; i<size; i=i+1 )
	{
		int length_word = words[i].length();

		// remove  inner  
		for ( int l=0; l<length( inner ); l=l+1 )
			if ( is_in_string( inner[l], words[i] ) )
				remove_inner( inner[l], words[i] );


		// remove plural
		if ( words[i][ length_word - 1 ] == 's' )
			remove_plural( words[i] );


		// remove  usual  
		for ( int l=0; l<length( usual ); l=l+1 )
			if ( usual[l] == words[i] )
			{
				remove_words[iter] = usual[l];
				iter = iter + 1;
			}
	}

	for ( int i=0; i<iter; i=i+1 )
		remove_word( words, remove_words[i] );	
}




// Sort




// swaps strings  a  and  b  
void swap (string &a, string &b)
{
	string aux;

	aux = a;
	a = b;
	b = aux;
}

// sort by freq
void sort_by_freq (string a[]) 
{
	int size = length(a);
	int freq[ size + 1 ];

	for (int i=0; i<size; i=i+1)
		freq[i] = count_appearances(a, a[i]);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{
			if ( freq[i] == freq [k] && a[i] < a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( freq[i] < freq[k] )
			{
				swap(freq[i], freq[k]);
				swap(a[i], a[k]);
			}
		}
}





// Words files





fstream save_files;
string save_file_strings[10000];
int files_iter = 0;

// get filenames of save files
void get_save_files()
{
	save_files.open( "save_files" );

	save_files >> files_iter;

	for ( int i=0; i<files_iter; i=i+1 )
		save_files >> save_file_strings[i];

	save_files.close();
}

// save filenames in file  save_files  
void set_save_files()
{
	clear( "save_files" );

	save_files.open( "save_files" );

	save_files << files_iter << "\n";

	for ( int i=0; i<files_iter; i=i+1 )
		save_files << save_file_strings[i] << " ";

	save_files.close();
}

// make file   save_files   
void make_save_files()
{
	ofstream save_files_ofstream;
	save_files_ofstream.open( "save_files" );
	cout << "( save file ) Save files file was reset to \"0\"\n";
	save_files_ofstream << 0 << "\n";
	save_files_ofstream.close();
}

// show save files
void show_save_files()
{
	get_save_files();

	if ( length( save_file_strings ) <= 0 )
	{
		cout << "Save files not made yet. [enter] or [help] to make save files.\n";
		return;
	}

	cout << "Save files: ";

	show_words( save_file_strings );

	cout << "\n";
}

// add to   save_files   and then to   save_file_strings[]
void add_save_files( string filename )
{
	get_save_files();
	save_files.open( "save_files" );

	save_files << files_iter + 1 << "\n";

	for ( int i=0; i<files_iter; i=i+1 )
		save_files << save_file_strings[i] << " ";
	save_files << filename << " ";	


	save_files.close();
	get_save_files();
}






// Correlate






// check if a file is considered for correlations
bool is_considered ( int file_num )
{
	int size = save_file_strings[ file_num ].length();

	if ( save_file_strings[ file_num ][0] == '(' and save_file_strings[ file_num ][ size - 1 ] == ')' )
		return 0;
	else
		return 1;
}

// consider / do not consider a save file
void consider ( int file_num )
{
	int size = save_file_strings[ file_num ].length();

	if ( !is_considered( file_num ) )
	{
		string temp = "";

		for ( int i=1; i<size-1; i=i+1 )
			temp = temp + save_file_strings[ file_num ][i];

		save_file_strings[ file_num ] = temp;
	}
	else
		save_file_strings[ file_num ] = "(" +  save_file_strings[ file_num ] + ")";
}


// get words correlated with a word
void get_correlated( string word, string correlated_words[] )
{
	int counter = 0;

	for ( int i=0; i<files_iter; i=i+1 )
	{
		if ( is_considered( i ) )
		{
			// get words of a save file
			fstream f;
			f.open( save_file_strings[i] );

			string saved_words[1000];
			int iter;
			f >> iter;







			for ( int l=0; l<iter; l=l+1 )
				f >> saved_words[l];

			f.close();



			// add words of file, if they correlate
			if ( is_in_words( saved_words, word ) )
			{
				int size = length( saved_words ); 

				for ( int l=0; l<size; l=l+1 )
					if ( !is_in_words( correlated_words, saved_words[l] ) and saved_words[l] != word )
					{
						correlated_words[ counter ] = saved_words[l];
						counter = counter + 1;				
					}

			}


			// empty  saved_words  
			empty_words( saved_words );
		}
	}
}

// add correlated  a  to  b  
void add_correlated( string a[], string b[] )
{
	int iter = 0;

	for ( int i = length(b); i<length(a) + length(b); i=i+1 )
	{
		b[i] = a[iter];
		iter = iter + 1; 
	}
}


// Usual words in save files
// ( each word in words correlates to either more contextual save files 
// or to more files that are not contextual with the file it is in )
// words are added to usual words if the case.


// counts words that in both  a[]  and  b[]  
int common_words_count ( string a[], string b[] )
{
	int size_a = length( a );
	int size_b = length( b );

	int counter = 0;

	for ( int i=0; i<size_a; i=i+1 )
		for ( int l=0; l<size_b; l=l+1 )
			if ( a[i] == b[i] )
				counter = counter + 1;

	return counter;
}

// is more usual or more contextual
void compare_usual_senseful ( string words[] )
{

	int size_words = length( words );

	for ( int l=0; l<size_words; l=l+1 )
	{
		string word = words[l]; // for every word

		int context_iter = 0; // word makes sense in context
		int usual_iter = 0; // word might be usual

		for ( int i=0; i<files_iter; i=i+1 )
		{

			if ( is_considered( i ) )
			{
				// get words of a save file
				fstream f;
				f.open( save_file_strings[i] );

				string saved_words[1000];
				int iter;
				f >> iter;

				for ( int l=0; l<iter; l=l+1 )
					f >> saved_words[l];

				f.close();



				// add words of file, if they correlate
				if ( is_in_words( saved_words, word ) )
				{
					// files correlate if they > 5 common words
					if ( common_words_count( words, saved_words ) > 5 )
						context_iter = context_iter + 1;
					else
						usual_iter = usual_iter + 1;
				}


				// empty  saved_words  
				empty_words( saved_words );
			}
		}

		// word is usual, since it is in more files that are not related to its file
		// compared to in how many related files it is in.
		if ( context_iter + 2 < usual_iter )
		{
			add_usual_word( word );
			remove_word( words, word );
		}

	}
}


// Choices



string choices[30] = { "add", "adds", "remove", "removes", "enter", "[enter]", "sense", "[sense]", "help", "[help]", "show", "files", "copy", "save", "exit", "return", "edit" };

// makes sure that entered choice is valid
bool is_choice ( string &choice )
{
	if ( choice == "[enter]" )
	{
		cout << "(info) Enter \'enter\' for choice \'[enter]\'.\n";
		choice = "enter";
		return true;
	}

	if ( choice == "[help]" )
	{
		cout << "(info) Enter \'help\' for choice \'[help]\'.\n";
		choice = "help";
		return true;
	}

	if ( choice == "[sense]" )
	{
		cout << "(info) Enter \'sense\' for choice \'[sense]\'.\n";
		choice = "sense";
		return true;
	}

	if ( choice == "[edit]" )
	{
		cout << "(info) Enter \'edit\' for choice \'[edit]\'.\n";
		choice = "edit";

		string a;
		enter(); // to be visible
		getline(cin, a);

		return true;
	}

	if ( choice == "[return]" )
	{
		cout << "(info) Enter \'return\' for choice \'[return]\'.\n";
		choice = "return";

		string a;
		enter(); // to be visible
		getline(cin, a);

		return true;
	}

	int size = length( choices );

	for ( int i=0; i<size; i=i+1 )
		if ( choices[i] == choice )
			return true;

	return false;
}




// Edit save files




// get words of save file
void get_save_file_words( int file_num, string saved_words[] )
{
	fstream f;
	f.open( save_file_strings[ file_num ] );

	int iter;
	f >> iter;

	for ( int l=0; l<iter; l=l+1 )
		f >> saved_words[l];
	f.close();
}


// checks if a word is in a save flie
bool is_save_file_word ( int file_num, string word )
{
	string saved_words[10000];

	get_save_file_words( file_num, saved_words );

	int iter = length( saved_words );

	for ( int i=0; i<iter; i=i+1 )
		if ( saved_words[i] == word )
			return true;

	return false;
}

// add a word to a save file
void add_save_file_word( int file_num, string word )
{
	fstream f;
	f.open( save_file_strings[ file_num ] );

	string saved_words[10000];

	get_save_file_words( file_num, saved_words );

	int iter = length( saved_words );
	saved_words[ iter ] = word;
	iter = iter + 1;
	f << iter << "\n";

	for ( int l=0; l<iter; l=l+1 )
		f << saved_words[l] << " ";
	f.close();
}

// remove a word of a save file
void remove_save_file_word( int file_num, string word )
{
	fstream f;
	f.open( save_file_strings[ file_num ] );

	string saved_words[10000];

	get_save_file_words( file_num, saved_words );

	int iter = length( saved_words );
	remove_word( saved_words, word);
	iter = iter - 1;

	clear( save_file_strings[ file_num ] );

	f << iter << "\n";

	for ( int l=0; l<iter; l=l+1 )
		f << saved_words[l] << " ";
	f.close();
}



void edit_save_files ()
{
	string choice = "";

	cout << "Edit save files:\n";
	cout << "  add. Add save word          adds. Add save words\n";
	cout << "  remove.  Remove save word   removes. Remove save words\n";
	cout << "  show. Show words of a save file\n";
	cout << "  files. Consider / Do not consider a save file for correlations\n";
	cout << "  copy. Make a copy of a save file \n\n";
	cout << "[return] Return\n\n";

	cout << "Choice: ";
	string choices[1000];
	getline( cin, choice );

	remove_chars( choice );
	move_words( choice, choices );

	choice = choices[0];

	cout << "\n";

	if ( !is_choice( choice ) or choice == "exit" )
	{
		cout << "Choice was not valid. Retry.";
		enter();
		return;
	}

	// Add save file word
	if ( choice == "add" )
	{
		if ( length( save_file_strings ) == 0 )
		{
			cout << "Save files were not made yet.";
			enter();
			return;
		}

		int file_num = 1; // if there is only 1 save file
		if ( length( save_file_strings ) != 1 ) // if there are more ( else )
		{
			cout << "Save files: \n";

			for ( int i=0; i<files_iter; i=i+1 )
				cout << i + 1 << ". " << save_file_strings[i] << "  ";
			cout << "\n\n";

			cout << "File you want to add to ( 1 - " << files_iter << " ): ";

			// checks if the string has numerics
			string file_num_string;
			string file_num_strings[10000];
			getline( cin, file_num_string );
			leave_digits( file_num_string );
			move_words( file_num_string, file_num_strings );
			if ( has_numeric( file_num_string ) )
				file_num = string_to_int( file_num_strings[0] );
			else
			{
				cout << "Choice was not numeric.\n";
				enter();
				return;
			}
		}


		if ( file_num <= 0 or file_num > files_iter )
		{
			cout << "Invalid file num.\n";
			enter();
			return;
		}

		file_num = file_num - 1;

		string saved_words[10000];
		
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\"";
		if ( file_num == 0 and length( save_file_strings ) == 1 )
			cout << " ( the only one made for now )";
		cout << ": ";
		show_words( saved_words );
		cout << "\n";

		string word;
		string words[1000];

		cout << "Word to add: ";
		getline( cin, word );

		remove_chars( word );
		move_words( word, words );

		word = words[0];


		if ( is_save_file_word( file_num, word ) )
		{
			cout << "Word is already in save file.\n";
			enter();
			return;
		}

		add_save_file_word( file_num, word );
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\" are now: ";
		show_words( saved_words );
		cout << "\n";

		enter();
	}

	// Add save file words
	if ( choice == "adds" )
	{
		if ( length( save_file_strings ) == 0 )
		{
			cout << "Save files were not made yet.";
			enter();
			return;
		}

		int file_num = 1; // if there is only 1 save file
		if ( length( save_file_strings ) != 1 ) // if there are more ( else )
		{
			cout << "Save files: \n";

			for ( int i=0; i<files_iter; i=i+1 )
				cout << i + 1 << ". " << save_file_strings[i] << "  ";
			cout << "\n\n";

			cout << "File you want to add to ( 1 - " << files_iter << " ): ";

			// checks if the string has numerics
			string file_num_string;
			string file_num_strings[10000];
			getline( cin, file_num_string );
			leave_digits( file_num_string );
			move_words( file_num_string, file_num_strings );
			if ( has_numeric( file_num_string ) )
				file_num = string_to_int( file_num_strings[0] );
			else
			{
				cout << "Choice was not numeric.\n";
				enter();
				return;
			}
		}


		if ( file_num <= 0 or file_num > files_iter )
		{
			cout << "Invalid file num.\n";
			enter();
			return;
		}

		file_num = file_num - 1;

		string saved_words[10000];
		
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\"";
		if ( file_num == 0 and length( save_file_strings ) == 1 )
			cout << " ( the only one made for now )";
		cout << ": ";
		show_words( saved_words );
		cout << ".\n\n";




		string word;
		cout << "Add words. Stop by entering: /done\n";

		for ( int i=0; i<10000; i=i+1 )
		{

			word = "";
			string words[1000];

			cout << "Enter word " << i + 1 << " to add: ";
			getline( cin, word );

			if ( word == "/done" )
				break;

			remove_chars( word );
			move_words( word, words );

			word = words[0];

			if ( is_save_file_word( file_num, word ) )
			{
				cout << "Word is already in save file.\n";
				continue;
			}

			add_save_file_word( file_num, word );
			get_save_file_words( file_num, saved_words );

		}



		cout << "Words of file \"" << save_file_strings[ file_num ] << "\" are now: ";
		show_words( saved_words );
		cout << "\n";

		enter();
	}

	// Remove save file word
	if ( choice == "remove" )
	{
		if ( length( save_file_strings ) == 0 )
		{
			cout << "Save files were not made yet.";
			enter();
			return;
		}

		int file_num = 1; // if there is only 1 save file
		if ( length( save_file_strings ) != 1 ) // if there are more ( else )
		{
			cout << "Save files: \n";

			for ( int i=0; i<files_iter; i=i+1 )
				cout << i + 1 << ". " << save_file_strings[i] << "  ";
			cout << "\n\n";

			cout << "File you want to edit through removal ( 1 - " << files_iter << " ): ";

			// checks if the string has numerics
			string file_num_string;
			string file_num_strings[10000];
			getline( cin, file_num_string );
			leave_digits( file_num_string );
			move_words( file_num_string, file_num_strings );
			if ( has_numeric( file_num_string ) )
				file_num = string_to_int( file_num_strings[0] );
			else
			{
				cout << "Choice was not numeric.\n";
				enter();
				return;
			}
		}


		if ( file_num <= 0 or file_num > files_iter )
		{
			cout << "Invalid file num.\n";
			enter();
			return;
		}

		file_num = file_num - 1;

		string saved_words[10000];
		
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\"";
		if ( file_num == 0 and length( save_file_strings ) == 1 )
			cout << " ( the only one made for now )";
		cout << ": ";
		show_words( saved_words );
		cout << "\n";

		string word;
		string words[1000];

		cout << "Word to remove: ";
		getline( cin, word );

		remove_chars( word );
		move_words( word, words );

		word = words[0];

		if ( !is_save_file_word( file_num, word ) )
		{
			cout << "Word is not in save file.\n";
			enter();
			return;
		}

		remove_save_file_word( file_num, word );
		empty_words( saved_words );
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\" are now: ";
		show_words( saved_words );
		cout << "\n";

		enter();
	}

	// Remove save file words
	if ( choice == "removes" )
	{
		if ( length( save_file_strings ) == 0 )
		{
			cout << "Save files were not made yet.";
			enter();
			return;
		}

		int file_num = 1; // if there is only 1 save file
		if ( length( save_file_strings ) != 1 ) // if there are more ( else )
		{
			cout << "Save files: \n";

			for ( int i=0; i<files_iter; i=i+1 )
				cout << i + 1 << ". " << save_file_strings[i] << "  ";
			cout << "\n\n";

			cout << "File you want to edit through removal ( 1 - " << files_iter << " ): ";

			// checks if the string has numerics
			string file_num_string;
			string file_num_strings[10000];
			getline( cin, file_num_string );
			leave_digits( file_num_string );
			move_words( file_num_string, file_num_strings );
			if ( has_numeric( file_num_string ) )
				file_num = string_to_int( file_num_strings[0] );
			else
			{
				cout << "Choice was not numeric.\n";
				enter();
				return;
			}
		}


		if ( file_num <= 0 or file_num > files_iter )
		{
			cout << "Invalid file num.\n";
			enter();
			return;
		}

		file_num = file_num - 1;

		string saved_words[10000];
		
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\"";
		if ( file_num == 0 and length( save_file_strings ) == 1 )
			cout << " ( the only one made for now )";
		cout << ": ";
		show_words( saved_words );
		cout << "\n\n";






		string word;
		cout << "Add words to remove. Stop by entering: /done\n";

		for ( int i=0; i<10000; i=i+1 )
		{
			word = "";
			string words[1000];

			cout << "Enter word " << i + 1 << " to remove: ";
			getline( cin, word );

			if ( word == "/done" )
				break;

			remove_chars( word );
			move_words( word, words );

			word = words[0];

			if ( !is_save_file_word( file_num, word ) )
			{
				cout << "Word is not in save file.\n";
				continue;
			}

			remove_save_file_word( file_num, word );
			empty_words( saved_words );
			get_save_file_words( file_num, saved_words );

		}





		cout << "Words of file \"" << save_file_strings[ file_num ] << "\" are now: ";
		show_words( saved_words );
		cout << "\n";

		enter();
	}

	// Show save file words
	if ( choice == "show" )
	{
		if ( length( save_file_strings ) == 0 )
		{
			cout << "Save files were not made yet.";
			enter();
			return;
		}

		int file_num = 1; // if there is only 1 save file
		if ( length( save_file_strings ) != 1 ) // if there are more ( else )
		{
			cout << "Save files: \n";

			for ( int i=0; i<files_iter; i=i+1 )
				cout << i + 1 << ". " << save_file_strings[i] << "  ";
			cout << "\n\n";

			cout << "File you want to show ( 1 - " << files_iter << " ): ";

			// checks if the string has numerics
			string file_num_string;
			string file_num_strings[10000];
			getline( cin, file_num_string );
			leave_digits( file_num_string );
			move_words( file_num_string, file_num_strings );
			if ( has_numeric( file_num_string ) )
				file_num = string_to_int( file_num_strings[0] );
			else
			{
				cout << "Choice was not numeric.\n";
				enter();
				return;
			}
		}


		if ( file_num <= 0 or file_num > files_iter )
		{
			cout << "Invalid file num.\n";
			enter();
			return;
		}

		file_num = file_num - 1;

		string saved_words[10000];
		
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\"";
		if ( file_num == 0 and length( save_file_strings ) == 1 )
			cout << " ( the only one made for now )";
		cout << ": ";
		show_words( saved_words );
		cout << "\n";

		enter();
	}

	// Consideration of files
	if ( choice == "files" )
	{
		if ( length( save_file_strings ) == 0 )
		{
			cout << "Save files were not made yet.";
			enter();
			return;
		}


		int file_num = 1; // if there is only 1 save file
		if ( length( save_file_strings ) != 1 ) // if there are more ( else )
		{
			cout << "Save files: \n";

			for ( int i=0; i<files_iter; i=i+1 )
				cout << i + 1 << ". " << save_file_strings[i] << "  ";
			cout << "\n\n";

			cout << "File you want to not consider / consider ( 1 - " << files_iter << " ): ";

			// checks if the string has numerics
			string file_num_string;
			string file_num_strings[10000];
			getline( cin, file_num_string );
			leave_digits( file_num_string );
			move_words( file_num_string, file_num_strings );
			if ( has_numeric( file_num_string ) )
				file_num = string_to_int( file_num_strings[0] );
			else
			{
				cout << "Choice was not numeric.\n";
				enter();
				return;
			}
		}


		if ( file_num <= 0 or file_num > files_iter )
		{
			cout << "Invalid file num.\n";
			enter();
			return;
		}

		file_num = file_num - 1;

		string saved_words[10000];
		
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\"";
		if ( file_num == 0 and length( save_file_strings ) == 1 )
			cout << " ( the only one made for now )";
		cout << ": ";
		show_words( saved_words );
		cout << "\n\n";

		consider( file_num );

		set_save_files();

		if ( !is_considered( file_num ) )
			cout << "File is not to be considered for correlations.\n";
		else
			cout << "File is to be considered for correlations.\n";

		cout << "Save files are now [ \"()\" are not considered for correlations ]:\n";
		show_words( save_file_strings );
		cout << "\n";

		enter();
	}

	// Copy a save file
	if ( choice == "copy" )
	{
		if ( length( save_file_strings ) == 0 )
		{
			cout << "Save files were not made yet.";
			enter();
			return;
		}

		int file_num = 1; // if there is only 1 save file
		if ( length( save_file_strings ) != 1 ) // if there are more ( else )
		{
			cout << "Save files: \n";

			for ( int i=0; i<files_iter; i=i+1 )
				cout << i + 1 << ". " << save_file_strings[i] << "  ";
			cout << "\n\n";

			cout << "File you want to copy ( 1 - " << files_iter << " ): ";

			// checks if the string has numerics
			string file_num_string;
			string file_num_strings[10000];
			getline( cin, file_num_string );
			leave_digits( file_num_string );
			move_words( file_num_string, file_num_strings );
			if ( has_numeric( file_num_string ) )
				file_num = string_to_int( file_num_strings[0] );
			else
			{
				cout << "Choice was not numeric.\n";
				enter();
				return;
			}
		}


		if ( file_num <= 0 or file_num > files_iter )
		{
			cout << "Invalid file num.\n";
			enter();
			return;
		}

		file_num = file_num - 1;

		string saved_words[10000];
		
		get_save_file_words( file_num, saved_words );

		cout << "Words of file \"" << save_file_strings[ file_num ] << "\"";
		if ( file_num == 0 and length( save_file_strings ) == 1 )
			cout << " ( the only one made for now )";
		cout << ": ";
		show_words( saved_words );
		cout << "\n\n";


		string filename_copy = save_file_strings[ file_num ] + "_" + count();
		ofstream f;
		f.open( filename_copy );

		int iter = length( saved_words );
		f << iter << "\n";
		for ( int i=0; i<iter; i=i+1 )
			f << saved_words[i] << " ";

		add_save_files( filename_copy );

		cout << "File \'" << save_file_strings[ file_num ] << "\' was copied to \'" << filename_copy << "\'.\n";

		f.close();

		enter();
	}

	// Return
	if ( choice == "return" )
		return;
}





int main()
{
	get_usual_words();
	// make the  usual_words  file if not already made
	if ( usual_iter == 0 )
		make_usual_words_file();


	get_save_files();
	// make the  save_files  file if not already made
	if ( files_iter == 0 )
		make_save_files();




	string choice = "";
	


	cout << "When you enter text, make sure to stay on 1 topic.\n( for [help] and [enter] operations )\n\n";
	cout << "When you enter words, enter each one is on its own. \n\n";
	cout << "Do not enter code. Enter only what is necessary. \n\n";
	cout << "(1), (2), etc. shows your choice num.\n";
	enter();



	for ( int i=0; i<10000; i=i+1 )
	{
		cout << "\nEnter your choice:        (" << i+1 << ") \n";
		cout << "  add. Add usual word          adds. Add usual words\n";
		cout << "  remove.  Remove usual word   removes. Remove usual words\n";
		cout << "  [help].  Enter text, enter which words make sense to improve\n";
		cout << "  [enter]. Enter text and get words that make sense\n";
		cout << "  [sense]. Enter a word and get correlated words\n";
		cout << "  files.   Show save file filenames\n";
		cout << "  show. Show usual words\n";
		cout << "  copy. Make a copy of \"usual_words\" file \n";
		cout << "  save. Save usual words ( done anyways )\n";
		cout << "  exit. Exit\n\n";
		cout << "[edit]. Edit save files ( more choices )\n";

		cout << "\nChoice: ";
		string choices[1000];
		getline( cin, choice );
		getline( cin, choice );

		remove_chars( choice );
		move_words( choice, choices );

		choice = choices[0];

		cout << "\n";

		if ( !is_choice( choice ) or choice == "return" or choice == "[return]" )
		{
			cout << "Choice was not valid. Retry.";
			enter();
			continue;
		}

		// Enter text and get words that make sense
		if ( choice == "enter" )
		{
			string words[1000]; // words

			string text = "";

			cout << "Enter text: ";
			getline( cin, text );

			remove_chars( text );

			if ( !( text[0] >= 'a' and text[0] <= 'z' ) )
			{
				cout << "Enter words in your text.\n";
			}
			else
			{
				move_words( text, words );

				sort_by_freq( words );

				remove_copies( words );

				edit_words( words );

				clear_usual_words( words );

				if ( length( words ) > 0 )
				{
					cout << "Words that make sense in context: ";

					show_words( words );
					cout << "\n";

					// make file to save words
					string filename = words[0] + count();
					cout << "File " << filename << " saved words.\n";


					// save words in a file
					ofstream words_file;
					words_file.open( filename );
					words_file << length( words ) << "\n";
					for ( int i=0; i<length( words ); i=i+1 )
						words_file << words[i] << " ";
					words_file.close();


					// add filename to  save_files 
					add_save_files( filename );
					show_save_files();


					// get correlated words

					string correlated_words[10000];

					for ( int i=0; i<length( words ); i=i+1 )
					{
						string correlated[10000];
						get_correlated( words[i], correlated );
						add_correlated( correlated, correlated_words );
						empty_words( correlated );
					}

				//	remove_copies( correlated_words );

					if ( length( correlated_words ) == 0 )
						cout << "Correlated words not available.\n";
					else
					{
						cout << "Correlated words: ";
						show_words( correlated_words );
						cout << ".\n";
					}
				}
				else
				{
					cout << "Entered words do not make sense.\n";
				}


				empty_words( words );

				}

			enter();
		}

		// Add word to usual words
		if ( choice == "help" )
		{
			string words[1000]; // words

			string text = "";

			cout << "Enter text: ";
			getline( cin, text );

			remove_chars( text );

			if ( !( text[0] >= 'a' and text[0] <= 'z' ) )
			{
				cout << "Enter words in your text.\n";
			}
			else
			{

				move_words( text, words );

				sort_by_freq( words );

				remove_copies( words );

				edit_words( words );

				clear_usual_words( words );

				if ( length( words ) > 0 )
				{
					cout << "\n( info ) Until now, certain usual words were removed to leave:\n";
					show_words( words );
					cout << "\nof the text you entered.\n\n";


					string help_words[10000];
					cout << "Enter words that make sense with the context.\n( anything but \"as\", \"in\", \"and\" etc. that correlates to the topic )\n\n";


					string words_that_make_sense[1000]; // words
					int make_sense_iter = 0;


					string word;
					cout << "Stop by entering: /done\n";

					for ( int i=0; i<10000; i=i+1 )
					{
						word = "";
						cout << "Enter contextual word " << i + 1 << ": ";
						cin >> word;

						if ( word == "/done" )
							break;

						words_that_make_sense[ make_sense_iter ] = word;
						make_sense_iter = make_sense_iter + 1;
					}

					for ( int i=0; i<length( words ); i=i+1 )
					{
						bool makes_sense = false;

						for ( int l=0; l<make_sense_iter; l=l+1 )
							if ( words[i] == words_that_make_sense[l] )
								makes_sense = true;

						if ( makes_sense == false )
							add_usual_word( words[i] );
					}

					set_usual_words();



					edit_words( words );

					clear_usual_words( words );

					compare_usual_senseful( words );

					if ( length( words ) > 0 )
					{
						cout << "Words that make sense in context: ";

						show_words( words );
						cout << "\n";


						// make file to save words
						string filename = words[0] + count();
						cout << "File " << filename << " saves words.\n";


						// save words in a file
						ofstream words_file;
						words_file.open( filename );
						words_file << length( words ) << "\n";
						for ( int i=0; i<length( words ); i=i+1 )
							words_file << words[i] << " ";
						words_file.close();


						// add filename to  save_files 
						add_save_files( filename );
						show_save_files();

						empty_words( words_that_make_sense );

					}
					else
					{
						cout << "Entered words do not make sense anymore.\n";
					}
				}
				else
				{
						cout << "Entered words do not make sense already.\n";
				}

				empty_words( words );

			}

			enter();
		}



		// Correlate word with save files
		if ( choice == "sense" )
		{
			if ( length( usual_words_strings ) == 0 )
			{
				cout << "( info ) Usual words are empty.  \n";
			}
			if ( length( save_file_strings ) == 0 )
			{
				cout << "[ empty ] Correlated words are empty.\n";
				enter();
				continue;
			}

			string word;
			string words[1000];

			cout << "Enter word to correlate with: ";
			getline( cin, word );

			remove_chars( word );
			move_words( word, words );


			string correlated[10000];
			get_correlated( words[0], correlated );

			cout << "\nCorrelated words: ";
			show_words( correlated );
			cout << "\n";

			enter();
		}



		// Add word to usual words
		if ( choice == "add" )
		{
			if ( length( usual_words_strings ) != 0 )
			{
				show_usual_words();
				cout << "\n";
			}
			else
				cout << "Usual words are empty.\n\n";

			string word;
			string words[1000];

			cout << "Enter word to add to usual words: ";
			getline( cin, word );

			remove_chars( word );
			move_words( word, words );

			add_usual_word( words[0] );

			enter();
		}

		// Add words to usual words
		if ( choice == "adds" )
		{

			if ( length( usual_words_strings ) != 0 )
			{
				show_usual_words();
				cout << "\n";
			}
			else
				cout << "Usual words are empty.\n\n";

			string word;

			cout << "Stop by entering: /done\n";

			for ( int i=0; i<10000; i=i+1 )
			{
				word = "";
				cout << "Enter word " << i + 1 << " to add to usual words: ";


				getline( cin, word );
	
				if ( word == "/done" )
					break;


				string words_strings[1000];

				remove_chars( word );
				move_words( word, words_strings );

				add_usual_word( words_strings[0] );
				empty_words( words_strings );
			}

			set_usual_words();

			enter();
		}

		// Remove usual word
		if ( choice == "remove" )
		{
			if ( length( usual_words_strings ) != 0 )
			{
				show_usual_words();
				cout << "\n";
			}
			else
			{
				cout << "Usual words are empty.\n";
				enter();
				continue;
			}

			string word;

			cout << "Enter usual word you want to remove: ";
			getline( cin, word );

			string words_strings[1000];

			remove_chars( word );
			move_words( word, words_strings );

			remove_usual_word( words_strings[0] );
			

			enter();
		}

		// Remove usual words
		if ( choice == "removes" )
		{
			if ( length( usual_words_strings ) != 0 )
			{
				show_usual_words();
				cout << "\n";
			}
			else
			{
				cout << "Usual words are empty.\n";
				enter();
				continue;
			}

			string word;

			cout << "Stop by entering: /done\n";

			for ( int i=0; i<10000; i=i+1 )
			{
				word = "";
				cout << "Enter usual word " << i + 1 << " to remove: ";
				getline( cin, word );

				if ( word == "/done" )
					break;

				string words_strings[1000];

				remove_chars( word );
				move_words( word, words_strings );

				remove_usual_word( words_strings[0] );
			}

			set_usual_words();

			enter();
		}

		// Show usual words
		if ( choice == "show" )
		{
			if ( length( usual_words_strings ) != 0 )
			{
				show_usual_words();
				cout << "\n";
			}
			else
			{
				cout << "Usual words are empty.\n";
				enter();
				continue;
			}


			enter();
		}

		// Make a copy of "usual_words" file
		if ( choice == "copy" )
		{
			if ( length( usual_words_strings ) != 0 )
			{
				show_usual_words();
				cout << "\n";
			}
			else
			{
				cout << "Usual words are empty.\n";
				enter();
				continue;
			}

			get_usual_words();

			ofstream copy;
			string copy_filename = "usual_words_" + count();

			copy.open( copy_filename );
			
			copy << usual_iter << "\n";

			for ( int i=0; i<usual_iter; i=i+1 )
				copy << usual_words_strings[i] << " ";

			copy.close();

			cout << "Usual words were copied to \'" << copy_filename << "\'.\n";

			enter();
		}


		// Save usual words ( done anyways )
		if ( choice == "save" )
		{
			set_usual_words();
			cout << "Usual words were saved.\n";
			enter();
		}

		// Show save files
		if ( choice == "files" )
		{
			show_save_files();
			enter();
		}

		// Edit save files
		if ( choice == "edit" )
			edit_save_files();


		// Exit
		if ( choice == "exit" )
			break;

		choice = "";

	}

	// save
	set_usual_words();

	cout << "Exited\n";

	return 0;
}
