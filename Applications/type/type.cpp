#include <iostream>
#include <unistd.h>
#include <fstream>

using namespace std;

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


// to continue
void enter( string reason )
{
	char enter;
	cout << "[ \']\' + Enter ] to " << reason << ": ";
	cin >> enter;
	cout << "\n";
}


int counter = 0;

string typed = "";

// show the timer 
void show_count() 
{ 
	cout << "printf \033c";

	cout << "Remaining: " << 10 - counter << "s\n";
}

// counts
void count() 
{ 
	for ( int i=0; i<10; i=i+1 )
	{ 	
		show_count(); 

		sleep( 1 ); 

		counter = counter + 1; 
	} 
} 


int main ()
{

	cout << "You have 10 s to type. Close \"your_typing\" file. Save before time is done.\n\n";

	enter( "type" );

	// make / clear and open file "your_typing"
	ofstream fo;
	fo.open( "your_typing" );
	fo.close();
	char command[] = "gedit your_typing";
	system( command );


	count();

	cout << "printf \033c";
	cout << "Remaining: done\n";
	string data = "";
	ifstream fi;
	fi.open( "your_typing" );

	string temp;
	while ( getline( fi, temp ) )
		data = data + temp;

	fi.close();

	cout << "In 10s you typed: " << data << "\n";

	cout << "\n- meaning that you typed:\n";
	cout << "    - " << (double) data.length() / 10 << " chars/s.\n";
	string words[ 1000 ];
	move_words( data, words );
	cout << "    - " << length( words ) << " words.\n";
	
	bool are_words = false;
	int num_vowel = 0;
	int num_cons = 0;
	for ( int i=0; i<data.length(); i=i+1 )
	{
		if ( data[i] >= 'A' and data[i] <= 'Z' )
			data[i] = data[i] + 32;

		if ( data[i] == 'a' or data[i] == 'e' or data[i] == 'i' or data[i] == 'u' or data[i] == 'i' or data[i] == 'y' )
			num_vowel = num_vowel + 1;
		else
			num_cons = num_cons + 1;
	}

	// checks if you actually typed words
	if ( num_vowel > num_cons / 10 )
		are_words = true;


	if ( are_words == false )
		cout << "Even so, you might not have typed actual words.\n";

	cout << "\n";

	return 0;
}
