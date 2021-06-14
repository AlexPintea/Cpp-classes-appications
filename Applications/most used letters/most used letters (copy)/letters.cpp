#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

char chr[ 210 ];
long chr_frev[ 210 ];
int chr_iter = 0;

char letter[ 60 ];
long letter_frev[ 60 ];
int letter_iter = 0;

ifstream fi;
ofstream fo;


long get_frev ( char m )
{
	for ( int i = 0; i < chr_iter; i = i + 1 )
		if ( m == chr[ i ] )
			return chr_frev[ i ];

	return -1;
}

long get_letter_frev ( char m )
{
	if ( m >= 'A' and m <= 'Z' )
		m = m + 32;

	for ( int i = 0; i < chr_iter; i = i + 1 )
		if ( m == chr[ i ] )
			return chr_frev[ i ] + chr_frev[ i - 32 ];

	return -1;
}

int string_to_int ( string d )
{
	int size = d.length();

	int multiply = 1;

	int result = 0;

	for ( int m = 0; m < d.length(); m = m + 1 )
	{
		result = result + ( (char) ( (int) d[ m ] - 48 ) ) * multiply;
		multiply = multiply * 10;
	}

	return result;
}

void get_file ()
{
	fi.open( "data" );

	string temp = "";
	string frev = "";

	while ( getline( fi, temp ) )
	{
		chr[ chr_iter ] = temp[ 1 ];
		for ( int i = 4; i < temp.length(); i = i + 1 )
			frev = frev + temp[ i ];
		chr_frev[ chr_iter ] = string_to_int( frev );

		chr_iter = chr_iter + 1;
		frev = "";
	}

	fi.close();

	for ( int i = (int) 'a'; i <= (int) 'z'; i = i + 1 )
	{
		letter_frev[ letter_iter ] = get_letter_frev( (char) i );
		letter_iter = letter_iter + 1;
	}

	if ( chr_iter == 0 )
	{
		cout << "Letters welcomes you to the application.\n";

		fo.open( "data" );
		fo.close(); // make the file

		fo.open( "data" );

		for ( int i = 32; i < 127; i = i + 1 )
		{
			chr[ i - 32 ] = (char) i;
			chr_frev[ i - 32 ] = 0;
			fo << "'" << (char) i << "' " << 0 << '\n';
		}

		chr_iter = 126 - 32 + 1;

		fo.close();
	}
}

void sort ()
{
	for ( int i1 = 0; i1 < chr_iter - 1; i1 = i1 + 1 )
		for ( int i2 = i1 + 1; i2 < chr_iter; i2 = i2 + 1 )
		{
			if ( chr_frev[ i1 ] < chr_frev[ i2 ] )
			{
				long frev;
				char chrtr;

				frev = chr_frev[ i1 ];
				chr_frev[ i1 ] = chr_frev[ i2 ];
				chr_frev[ i2 ] = frev;

				chrtr = chr[ i1 ];
				chr[ i1 ] = chr[ i2 ];
				chr[ i2 ] = chrtr;
			}

			if ( letter_frev[ i1 ] < letter_frev[ i2 ] )
			{
				long frev;
				char lttr;

				frev = letter_frev[ i1 ];
				letter_frev[ i1 ] = letter_frev[ i2 ];
				letter_frev[ i2 ] = frev;

				lttr = letter[ i1 ];
				letter[ i1 ] = letter[ i2 ];
				letter[ i2 ] = lttr;
			}
		}
}

void add_string ( string p )
{
	int size = p.length();

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( p[ i ] < 32 or p[ i ] >= 127 )
			continue;

		chr_frev[ (int) p[ i ] - 32 ] = chr_frev[ (int) p[ i ] - 32 ] + 1;
	}

	sort();
}

void add_file ( string filename )
{
	fi.open( filename );

	string temp = "";
	while ( getline( fi, temp ) )
		add_string( temp );

	fi.close();

	if ( temp == "" )
		cout << "File added.\n";
	else
		cout << "File path invalid.\n";
}

void show_char ()
{
	for ( int i = 0; i < 127; i = i + 1 )
		cout << (char) i << ": " << i << '\n';
}

void set_file ()
{
	fo.open( "data" );
	fo.close(); // clear file

	fo.open( "data" );

	for ( int i = 0; i < chr_iter; i = i + 1 )
		fo << "'" << chr[ i ] << "' " << chr_frev[ i ] << '\n';

	fo.close();

	cout << "File \"data\" saved\n";
}

float get_usage ( char m )
{
	int sum = 0;

	for ( int i = 0; i < chr_iter; i = i + 1 )
		sum = sum + chr_frev[ i ];

	if ( sum == 0 )
		return 0;

	return get_frev( m ) / sum * 100;
}

float get_letter_usage ( char m )
{
	int sum = 0;

	for ( int i = 0; i < chr_iter; i = i + 1 )
		sum = sum + chr_frev[ i ];

	return get_letter_frev( m ) / sum * 100;
}


void ch ( char m )
{
	fo << "['" << m << "': " << get_usage( m ) << "] ";
}

void bh ( char m, char p )
{
	fo << "{ ['" << m << "': " << get_usage( m ) << "] ['" << p << "': " << get_usage( p ) << "'] } ";
}

void lt ( char m )
{
	fo << "['" << m << "': " << get_letter_usage( m ) << "] ";
}

void set_result ()
{
	fo.open( "result" );
	fo.close(); // make the file

	fo.open( "result" );

	fo << "Most used char: \n";
	for ( int i = 0; i < chr_iter; i = i + 1 )
	{
		fo << "'" << chr[ i ] << "': " << chr_frev[ i ];

		if ( i != chr_iter - 1 )
			fo << ", ";
	}

	fo << "\n\n";

	fo << "Most used letters ( uppercase and lowercase ): 'n'";
	for ( int i = 0; i < letter_iter; i = i + 1 )
	{
		fo << "'" << letter[ i ] << "': " << letter_frev[ i ];

		if ( i != chr_iter - 1 )
			fo << ", ";
	}


	bh( '`', '~' ); bh( '1', '!' ); bh( '2', '@' ); bh( '3', (char) 35 ); bh( '4', (char) 36 ); bh( '5', '%' );
	bh( '6', (char) 94 ); bh( '7', '&' ); bh( '8', '*' ); bh( '9', '(' ); bh( '0', ')' ); bh( '-', '_' ); 
	bh( '=', '+' ); bh( 'm', '~' );
	fo << "\n\n";
	ch( 'q' ); ch( 'w' ); ch( 'e' ); ch( 'r' ); ch( (char) 116 ); ch( 'y' ); ch( 'u' ); ch( 'i' ); ch( 'o' ); 
	ch( 'p' ); bh( '[', '{' ); bh( ']', '}' ); bh( '\\', (char) 124 );
	fo << "\n\n";
	ch( 'a' ); ch( 's' ); ch( 'd' ); ch( 'f' ); ch( 'g' ); ch( 'h' ); ch( 'j' ); ch( 'k' ); ch( 'l' ); 
	bh( ';', ':' ); bh( '\'', '"' );
	fo << "\n\n";
	ch( 'z' ); ch( 'x' ); ch( 'c' ); ch( 'v' ); ch( 'b' ); ch( 'n' ); ch( 'm' ); ch( ',' ); ch( '<' ); 
	bh( '.', '>' ); bh( '/', '?' );
	

	fo << "\n\n";

	fo.close();

	cout << "File \"result\" saved\n";
}






int main ()
{
	// show_char();

	get_file();

	cout << "Choices: 1. Add file  2. Add sentance\n";
	cout << "Choice: ";	
	string choice = "";

	cout << "\n'" << chr[ 0 ] << chr[ 1 ] << chr[ 2 ] << chr[ 3 ] << chr[ 4 ] << "'\n";

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );


	if ( choice == "1" )
	{
		string filename;

		cout << "Filename: ";

		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		add_file( filename );
		cout << "\n'" << chr[ 0 ] << chr[ 1 ] << chr[ 2 ] << chr[ 3 ] << chr[ 4 ] << "'\n";
		set_file();
		cout << "\n'" << chr[ 0 ] << chr[ 1 ] << chr[ 2 ] << chr[ 3 ] << chr[ 4 ] << "'\n";
		set_result();
		cout << "\n'" << chr[ 0 ] << chr[ 1 ] << chr[ 2 ] << chr[ 3 ] << chr[ 4 ] << "'\n";
	}

	if ( choice == "2" )
	{
		string sentance;

		cout << "Sentance: ";

		getline( cin, sentance );
		if ( sentance == "" )
			getline( cin, sentance );

		add_string( sentance );

		set_file();
		set_result();
		cout << "Saved.\n";
	}

	cout << "Exited.\n";
	// could: 2. Add string, add the frev for lower and upper letters
	// use cheaper matierls for lttrs that are used less
	// make sure you have \n too

	return 0;
}
