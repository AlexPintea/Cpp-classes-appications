#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

void upper ( string &a )
{
	int size = a.length();

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] >= 'a' and a[ i ] <= 'z' )
			a[ i ] = a[ i ] - 32;
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



// reduce ' '
string reduce_spaces ( string &a )
{
	int size = a.length();
	string result = "";
	int l;


	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '	' )
		{
			l = i;
			break;
		}

	for ( int i = l; i < size; i = i + 1 )
		if ( a[i] != ' ' and a[i] != '	' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + ' ';

	size = result.length();
	for ( int i = size - 1; i >= 0; i = i - 1 )
	{
		if ( result[ i ] != ' ' and result[ i ] != '	' )
			break;
		remove_char( result, i );
	}
	a = result;

	return a;
}




string strings ( string a, string l1, string l2, string l3 )
{
	int size = a.length();
	string result = "";
	for ( int i = 0; i < size; i = i + 1 )
	{
		result = result + l1 + a[ i ] + l2;
		if ( i != size - 1 )
			result = result + l3;
	}
	return result;
}

string strings_1 ( string &a ) { return strings( a, "(", ")", "-" ); }
string strings_2 ( string &a ) { return strings( a, "[ ", " ]", "-" ); }
string strings_3 ( string &a ) { return strings( a, "{/", "/}", "-" ); }
string strings_4 ( string &a ) { return strings( a, "( ", " )", "  " ); }
string strings_5 ( string &a ) { return strings( a, "-", "-", "/" ); }


string get_num ( string a, int l )
{
	int size = a.length();


	if ( l < size / 4 ) return "10000";
	if ( l < size / 3 and l >= size / 4 ) return "21000";
	if ( l < size / 2 and l >= size / 3 ) return "90000";
	if ( l >= size / 3 and l <= size / 2 ) return "150000";
	if ( l >= size / 4 and l <= size / 3 ) return "100000";
	if ( l >= size / 2 )
	{
		if ( l <= size / 2 + size / 4 ) return "150000";
		if ( l <= size / 2 + size / 3 ) return "210000";
		return "259000";
	}

	return "-1";
}

string get_file ()
{
	ifstream fi;
	fi.open( "sldn files/sldn" );

	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();

	return file;
}











int main ()
{
	string a;
	cout << "String: ";
	getline( cin, a );
	string filename = a + ".cpp";
	reduce_spaces( a );
	upper( a );
	cout << "\nChoices:\n";
	cout << "  1. " << strings_1( a ) << '\n';
	cout << "  2. " << strings_2( a ) << '\n';
	cout << "  3. " << strings_3( a ) << '\n';
	cout << "  4. " << strings_4( a ) << '\n';
	cout << "  5. " << strings_5( a ) << '\n';
	cout << " strings. Strings\n\n";

	string choice;
	cout << "Choice: ";

	getline( cin, choice );

	if ( choice == "1" ) { a = strings_1( a ); }
	if ( choice == "2" ) { a = strings_2( a ); }
	if ( choice == "3" ) { a = strings_3( a ); }
	if ( choice == "4" ) { a = strings_4( a ); }
	if ( choice == "5" ) { a = strings_5( a ); }

	if ( choice == "strings" or ! ( choice >= "1" and choice <= "5" ) ) 
	{
		string l1;
		string l2;
		string l3;
		cout << "String 1: ";
		getline( cin, l1 );

		cout << "String 2: ";
		getline( cin, l2 );

		cout << "String 3: ";
		getline( cin, l3 );
		a = strings( a, l1, l2, l3 );
	}

	a = "   " + a;

	string file = get_file();

	ofstream fo;
	fo.open( filename );

	fo << file;

	fo << "int main ()\n";
	fo << "{\n";
	fo << "	string a = \"" << a << "\";\n\n";

	for ( int i = a.length() - 1; i >= 0; i = i - 1 )
		fo << "	cout << \"\\033c\\n\" << get_string( a, " << i << " ) << \"\\n\\n\";\n	usleep( " << get_num ( a, a.length() - 1 - i ) << " );\n";

	fo << "	usleep( 950000 );\n\n";

	fo << "	return 0;\n";
	fo << "}\n";

	fo.close();
	return 0;
}
