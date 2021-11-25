#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

struct percept
{
	string features[ 1000 ];
	int rates[ 1000 ];
	int iter = 0;
	int added = 0;
	int treshold = 0;
} p;

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

int length ( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
}

// is in string[]
bool is_in_strings ( string strings[], string a )
{
	int size = length( strings );

	for ( int i=0; i<size; i=i+1 )
		if ( strings[i] == a )
			return true;

	return false;
}

void get_data()
{
	ifstream fi;
	fi.open( "data" );

	fi >> p.added;
	fi >> p.treshold;

	while ( fi >> p.features[ p.iter ] )
	{
		fi >> p.rates[ p.iter ];
		p.iter = p.iter + 1;
	}

	fi.close();
}

void set_data ()
{
	ofstream fo;
	fo.open( "data" );

	fo << p.added << ' ' << p.treshold << '\n';

	for ( int i = 0; i < p.iter; i = i + 1 )
		fo << p.features[ i ] << ' ' << p.rates[ i ] << '\n';

	fo.close();
}

void add_feature ( string f, int correct ) // increment rate
{
	int add = 0;

	if ( correct == 1 )
		add = 1;
	else
		add = -1;

	for ( int i = 0; i < p.iter; i = i + 1 )
		if ( p.features[ i ] == f )
		{
			p.rates[ i ] = p.rates[ i ] + add;
			return;
		}

	p.features[ p.iter ] = f;
	p.rates[ p.iter ] = add;
	p.iter = p.iter + 1;
}

void add_features ( string strings[], int correct )
{
	for ( int i = 0; i < length( strings ); i = i + 1 )
		add_feature( strings[ i ], correct );
}

void verif_features ( string strings[] ) // decrement rate
{
	for ( int i = 0; i < p.iter; i = i + 1 )
		if ( ! is_in_strings( strings, p.features[ i ] ) )
			p.rates[ i ] = p.rates[ i ] - 1;
}

int get_rate ( string f )
{
	for ( int i = 0; i < p.iter; i = i + 1 )
		if ( p.features[ i ] == f )
			return p.rates[ i ];

	return 0;
}

int total ( string strings[] )
{
	int l = p.added;

	for ( int i = 0; i < length( strings ); i = i + 1 )
		l = l + get_rate( strings[ i ] );

	return l;
}

int result ( int total )
{
	if ( total >= p.treshold )
		return 1;
	return 0;
}

void adjust_treshold ( int total, int correct )
{
	if ( correct == 1 )
	{
		if ( total > p.treshold )
			p.treshold = p.treshold - 1;
		if ( total < p.treshold )
			p.treshold = p.treshold + 1;
	}
	else
	{
		if ( total >= p.treshold )
			p.treshold = total - 1;
	//		p.treshold = p.treshold - 1;
	}
}

void verif ()
{
	get_data();

	cout << "Sentance: ";
	string sentance;

	getline( cin, sentance );

	string strings[1000];

	move_words( sentance, strings );

	cout << "1. Give answer  2. Get answer\nChoice: ";
	string choice = "";
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "1" ) // add knowledge
	{
		cout << "1. Negt  2. Pstv\nChoice: ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );
		
		if ( choice == "1" )
		{
			adjust_treshold( total( strings ), 1 );
			add_features( strings, 1 );
		}

		if ( choice == "2" )
		{
			adjust_treshold( total( strings ), 0 );
			add_features( strings, 0 );
		}

		if ( choice == "1" or choice == "2" )
			cout << "Choice added. Rated modified.\n";
		else
			cout << "Choice invalid.\n";

		choice = "1";
	}

	if ( choice == "2" ) // determine result based on previoius knowledge
	{
		if ( result( total( strings ) ) == 1 )
			cout << "Sentance is negt.\n";
		else
			cout << "Sentance is pstv.\n";
	}

	if ( choice != "1" and choice != "2" )
		cout << "Choice invalid.\n";

	set_data();

}

int main ()
{
	cout << "main ";
	cout << "percptrn ";

	verif();

	return 0;
}
