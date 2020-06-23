#include <fstream>
#include <string>
#include <iostream>

using namespace std;

// complete with most common words / strings, in descending order of their length ( >= 2 ).
string strings_for_chars[50] = { "are", "to", "is", "yes", "fi", "am", "th", "if" };

ifstream fi;
ofstream fo;

// length of a string[]
int length ( string a[] )
{
	int i = 0;

	while ( a[i].length() > 0 )
		i = i + 1;

	return i;	
}

// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a == b )
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a < size_b )
		return 0;


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

	return 1;
}




// Replace string / char




// replaces a string with a char
void replace_string_char ( string &a, string b, char replacement )
{
	// if a == b, add '' to a, to make it 'a'
	bool equal = false;
	if ( a == b )
	{
		a = "\'" + a + "\'";
		equal = true;
	}



	int size_a = a.length();
	int size_b = b.length();

	if ( size_a < size_b )
		return;

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
	{
		if (a[i] == b[0])
		{
			int iter = i;
			bool verif = 1;

			for ( int r=0; r<size_b; r=r+1 )
				if ( a[ r+i ] != b[r] )
					verif = 0;

			if (verif == 1)
			{
				result = result + replacement;
				i = i + size_b;
			}
		}

		result = result + a[i];
	}



	// if a == b remove '' of 'a'
	if ( equal )
	{
		a = "";
		for ( int i=1; i<result.length() - 1; i=i+1 )
			a = a + result[i];
	}
	else
		a = result;
}

// replaces a char with a string
void replace_char_string ( string &a, char b, string replacement )
{
	if (a == "" + b)
	{
		a = replacement;
		return;
	}

	int size_a = a.length();

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
	{
		if (a[i] == b )
			result = result + replacement;
		else
			result = result + a[i];
	}

	a = result;
}




// Encode / decode a string




// encodes a string
string encode_string ( string a )
{
	int size = a.length();
	int strings_for_chars_size = length( strings_for_chars );

	for ( int i=0; i<strings_for_chars_size; i=i+1 )
		if ( b_is_in_a( a, strings_for_chars[i] ) )
		{
			replace_string_char( a, strings_for_chars[i], (char) ( i + 127 ) );
		}

	return a;
}

// decodes a string
string decode_string ( string a )
{
	int size = a.length();
	int strings_for_chars_size = length( strings_for_chars );

	for ( int i=0; i<size; i=i+1 )
		for ( int l=0; l<strings_for_chars_size; l=l+1 )
			if ( 256 + (int) a[i] == l + 127 ) // (int) a[i] is neg.
				replace_char_string( a, a[i], strings_for_chars[l] );

	return a;	
}




// Encode / decode files




// encodes a file
void encode_file ( string fi_filename, string fo_filename )
{
	fi.open( fi_filename );
	fo.open( fo_filename );
	
	string temp;
	while ( getline( fi, temp ) )
		fo << encode_string( temp ) << '\n';

	fo.close();	
	fi.close();
}

// decodes a file
void decode_file ( string fi_filename, string fo_filename )
{
	fi.open( fi_filename );
	fo.open( fo_filename );
	
	string temp;
	while ( getline( fi, temp ) )
		fo << decode_string( temp ) << '\n';

	fo.close();	
	fi.close();
}



int main ()
{
	fo.open( "strings_for_chars" );
	for ( int i=127; i<=159; i=i+1 )
		fo << "\'" << (char) i << "\' (" << i << ") for \"" << strings_for_chars[ i - 127 ] << "\"\n";
	fo.close();

	encode_file( "fi_file", "fi_file_encoded" );
	
	decode_file( "fi_file_encoded", "fi_file_decoded" );

	cout << "Done. ";

	return 0;
}
