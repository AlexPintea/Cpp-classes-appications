#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// length of a string[]
int length( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
		i = i + 1;

	return i;
}

// is in string[]
int is_in_strings ( string words[], string word )
{
	int size = length( words );

	for ( int i = 0; i < size; i = i + 1 )
		if ( word == words[i] )
			return i;

	return -1;
}

// to continue
void continues ()
{
	char chars;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> chars;
	cout << "\n";
}









string choice = "";

string valid_choices[1000] = { "1", "exit" };
string choices[1000] = { "name", "Exits" };

// makes columns with your choices
void spaces ( int iter )
{
	int size = length( choices );

	int max_length = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i % 4 == iter % 4 )
		{
			string temp = valid_choices[i] + ". " + choices[i];

			if ( temp.length() > max_length )
				max_length = temp.length();
		}

	max_length = max_length + 2;

	string entry = valid_choices[iter] + ". " + choices[iter];
	int entry_size = entry.length();

	for ( int i=entry_size; i<max_length; i=i+1 )
		cout << " ";
}

bool is_numeric( string a )
{
	int size = a.length();
	for ( int i = 0; i < size; i = i + 1 )
		if ( ! ( ( a[ i ] >= '0' and a[ i ] <= '9' ) or a[ i ] == '.' ) )
			return 0;
	return 1;
}

int move_strings ( string text, string temps[] )
{
	text = text + " ";

	int size = text.length();

	for ( int i = 0; i < length( temps ); i = i + 1 )
		temps[ i ] = "";
	
	int temps_iter = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( text[i] == ' ' )
		{
			temps_iter = temps_iter + 1;
			temps[ temps_iter ] = "";
		}
		else
			temps[ temps_iter ] = temps[ temps_iter ] + text[i];
	return temps_iter;
}

// reduces ' '-s
void reduce_spaces ( string &a )
{
	int size = a.length();

	string result = "";

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '	'  and a[ i ] != '.' )
			result = result + a[ i ];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";
	a = result;
}



string lower ( string a )
{
	int size = a.length();

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] >= 'a' and a[ i ] <= 'z' )
			a[ i ] = a[ i ] - 32;

	return a;
}




int strings ( string a[], string b[] )
{
	int size_a = length( a );
	int size_b = length( b );

	string result[ 10000 ];
	int result_iter = 0;
	for ( int i = 0; i < size_a; i = i + 1 )
		for ( int l = 0; l < size_b; l = l + 1 )
			if ( lower( a[ i ] ) == lower( b[ l ] ) and is_in_strings( result, lower( a[ i ] ) ) == -1 )
			{
				result[ result_iter ] = lower( a[ i ] );
				result_iter = result_iter + 1;
			}

	return result_iter;
}

string choice_strings ( string a[], string a_valid[], string choice_string )
{
	int size = length( a );
	int size_valid = length( a_valid );

	if ( size > size_valid )
	{
		cout << "Sizes invalid.\n";
		return "-1";
	}

	int nums[ 10000 ];

	string temps[ 10000 ];
	string temps_choice[ 10000 ];
	int temps_iter = move_strings( choice_string, temps );

	for ( int i = 0; i < size_valid; i = i + 1 )
		if ( lower( a_valid[ i ] ) == lower( choice_string ) )
			return a_valid[ i ];

	reduce_spaces( choice_string );
	if ( is_numeric( choice_string ) )
		return choice_string;

	for ( int i = 0; i < size; i = i + 1 )
	{
		int l = move_strings( a[ i ], temps_choice );
		nums[ i ] = strings( temps_choice, temps );
	}

	for ( int i = size; i < size + size_valid; i = i + 1 )
	{
		int l = move_strings( a_valid[ i ], temps_choice );
		nums[ i ] = strings( temps_choice, temps );
	}

	int max_num = 0;
	int max_iter = -1;
	bool identic = 0;
	for ( int i = 0; i < size + size_valid; i = i + 1 )
	{
		if ( nums[ i ] == max_num )
			identic = 1;

		if ( nums[ i ] > max_num )
		{
			max_num = nums[ i ];

			if ( i >= size )
				max_iter = i - size;
			else
				max_iter = i;

			identic = 0;
		}
	}

	if ( max_num == 0 or identic == 1 )
		return "-1";

	return a_valid[ max_iter ];
}


// gets choice
void get_choice ( int &i )
{
	cout << "Choices: ";

	for ( int i = 0; i < length( choices ); i = i + 1 )
	{
		if ( valid_choices[ i ] == "exit" )
			continue;

		if ( i % 4 == 0 )
			cout << "\n    ";
		cout << valid_choices[ i ] << ". " << choices[ i ];
		spaces( i );
	}

	cout << "\n\n  exit. Exits\n\n";

	cout << "Your choice: ";
	// cout << "Your choice (" << i + 1 << "): "; // choice num.
	getline( cin, choice );
	if ( choice == "" ) // only if the case
		getline( cin, choice );

	choice = choice_strings( choices, valid_choices, choice );

	if ( is_in_strings( valid_choices, choice ) == -1 )
	{
		cout << "Invalid choice. Retry.\n\n";
		choice = "";
	}


	// name
	if ( choice == "1" )
	{
		cout << "choice 1\n";
	}


	i = i + 1;

	if ( choice == "exit" )
		return;


	continues();

	cout << "printf \033c";
}






int main ()
{
	int i=0;
	while ( choice != "exit" )
		get_choice( i );

	cout << "\nExited.\n";
	return 0;
}

