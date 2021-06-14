#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string strings[ 10000 ];
int strings_iter = 0;

int max_length = 0;


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}

void move_words ( string text, string words[] )
{
	for ( int i = 0; i < length( words ); i = i + 1 )
		words[ i ] = "";

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
 
void get_file_rows ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;

	while ( getline( fi, temp ) )
	{
		reduce_spaces( temp );
		strings[ strings_iter ] = temp;
		if ( temp.length() > max_length )
			max_length = temp.length();
		strings_iter = strings_iter + 1;
	}

	fi.close();
}

void empty ( string a[] )
{
	int size = length( a );

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = "";
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	return file;
}

void set_file ( string filename, string file )
{
	ofstream fo;
	fo.open( filename );
	fo.close(); // clear file

	fo.open( filename );

	fo << file;

	fo.close();
}



void align ( string filename, int alignment )
{
	ofstream fo;
	fo.open( "result" );
	fo.close();
	fo.open( "result" );

	if ( alignment == 1 )
	{
		for ( int i = 0; i < strings_iter; i = i + 1 )
			fo << strings[ i ] << '\n';
	}

	if ( alignment == 2 )
	{
		int num;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			num = ( max_length - strings[ i ].length() ) / 2;
			for ( int l = 0; l < num; l = l + 1 )
				fo << ' ';
			fo << strings[ i ] << '\n';
		}
	}

	if ( alignment == 3 )
	{
		int num;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			num = max_length - strings[ i ].length();
			for ( int l = 0; l < num; l = l + 1 )
				fo << ' ';
			fo << strings[ i ] << '\n';
		}
	}

	if ( alignment == 4 )
	{
		string temps[ 10000 ];
		string temp = "";
		int temps_iter;
		int average;
		int sum;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			empty( temps );
			move_words( strings[ i ], temps );
			temps_iter = length( temps );
			temp = "";
			sum = 0;
			for ( int l = 0; l < temps_iter; l = l + 1 )
				sum = sum + temps[ l ].length();
			average = ( max_length - sum ) / temps_iter;
			if ( average > 5 )
			{
				fo << strings[ i ] << '\n';
				continue;
			}
			for ( int l = 0; l < temps_iter - 1; l = l + 1 )
			{
				temp = temp + temps[ l ] + ' ';
				for ( int d = 0; d < average; d = d + 1 )
					temp = temp + ' ';
			}
			for ( int l = temp.length(); l < max_length - temps[ temps_iter - 1 ].length(); l = l + 1 )
					temp = temp + ' ';

			temp = temp + temps[ temps_iter - 1 ];

			fo << temp << '\n';
		}
	}

	if ( alignment == 5 )
	{
		int max_num = 0;

		ifstream fi;
		fi.open( filename );

		string temp;
		string temps[ 10000 ];
		int maximum[ 10000 ];
		while ( getline( fi, temp ) )
		{
			move_words( temp, temps );
			if ( length( temps ) > max_num )
				max_num = max_num + 1;

			for ( int i = 0; i < length( temps ); i = i + 1 )
				if ( temps[ i ].length() > maximum[ i ] )
					maximum[ i ] = temps[ i ].length();
		}

		fi.close();


		
		fi.open( filename );
		
		while ( getline( fi, temp ) )
		{
			move_words( temp, temps );
			
			for ( int i = 0; i < length( temps ); i = i + 1 )
			{
				fo << temps[ i ] << "  ";
				for ( int l = temps[ i ].length(); l < maximum[ i ]; l = l + 1 )
					fo << ' ';
			}

			fo << '\n';
		}

		fi.close();
	}


	fo.close();
}

string int_to_string ( int m )
{
	string result = "";

	while ( m != 0 )
	{
		result = result + (char) ( m % 10 );
		m = m / 10;
	}

	string temp = result;
	int size = temp.length();

	result = "";

	for ( int i = size - 1; i >= 0; i = i - 1 )
		result = result + temp[ i ];

	return result;
}

int main ()
{
	string filename;
	cout << "Filename: ";

	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );



	get_file_rows( filename );

	if ( strings_iter != 0 )
	{
		cout << "Choices:  1. Left  2. Center  3. Right  4. Middle  5. table\n";
		cout << "          6. Upper 7. Lower   8. Mark \n";
		cout << "Choice: ";

		string choice;

		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		if ( choice == "1" ) // left
		{
			align( filename, 1 );
		}
		if ( choice == "2" ) // center
		{
			align( filename, 2 );
		}
		if ( choice == "3" ) // right
		{
			align( filename, 3 );
		}
		if ( choice == "4" ) // middle
		{
			align( filename, 4 );
		}
		if ( choice == "5" ) // table
		{
			align( filename, 5 );
		}
		if ( choice == "6" ) // upper
		{
			cout << "Choices: 1. Only first letter of sentances  2. Every letter\n";
			cout << "Choice: ";

			getline( cin, choice );
			if ( choice == "" )
				getline( cin, choice );

			string file = get_file( filename );
			int size = file.length();

			if ( choice == "1" ) // only first letter
			{
				bool have_sentance = 0;

				for ( int i = 0; i < size; i = i + 1 )
				{
					if ( file[ i ] == '.' or file[ i ] == '?' or file[ i ] == '!' )
						have_sentance = 1;

					if ( have_sentance and file[ i ] >= 'a' and file[ i ] <= 'z' )
					{
						have_sentance = 0;
						file[ i ] = file[ i ] - 32;
					}

					if ( have_sentance and file[ i ] >= 'A' and file[ i ] <= 'Z' )
						have_sentance = 0;
				}
			}
			if ( choice == "2" ) // every letter
			{
				for ( int i = 0; i < size; i = i + 1 )
					if ( file[ i ] >= 'a' and file[ i ] <= 'z' )
						file[ i ] = file[ i ] - 32;
			}

			set_file( filename, file );
		}
		if ( choice == "7" ) // lower
		{
			cout << "Choices: 1. Only those that are not first letter of sentance  2. Every letter\n";
			cout << "Choice: ";

			getline( cin, choice );
			if ( choice == "" )
				getline( cin, choice );

			string file = get_file( filename );
			int size = file.length();

			if ( choice == "1" ) // only first letter
			{
				bool have_sentance = 0;

				for ( int i = 0; i < size; i = i + 1 )
				{
					if ( file[ i ] == '.' or file[ i ] == '?' or file[ i ] == '!' )
						have_sentance = 1;

					if ( ! have_sentance and file[ i ] >= 'A' and file[ i ] <= 'Z' )
						file[ i ] = file[ i ] + 32;

					if ( have_sentance and ( ( file[ i ] >= 'a' and file[ i ] <= 'z' ) or ( file[ i ] >= 'A' and file[ i ] <= 'Z' ) ) )
						have_sentance = 0;
				}
			}
			if ( choice == "2" ) // every letter
			{
				for ( int i = 0; i < size; i = i + 1 )
					if ( file[ i ] >= 'A' and file[ i ] <= 'Z' )
						file[ i ] = file[ i ] + 32;
			}

			set_file( filename, file );
		}
		if ( choice == "8" ) // 
		{
			cout << "Choices: 1. Numbers  2. Same mark\n";
			cout << "Choice: ";

			getline( cin, choice );
			if ( choice == "" )
				getline( cin, choice );

			string mark;

			if ( choice == "1" ) // numbers
			{
				int iter = 1;
				cout << "First number: ";

				cin >> iter;

				cout << "Mark ( any word / character, goes after number ): ";

				getline( cin, mark );
				if ( mark == "" )
					getline( cin, mark );

				string file = "";

				int max_size = 0;

				for ( int i = 0; i < strings_iter; i = i + 1 )
					if ( int_to_string( iter + i ).length() > max_size )
						max_size = int_to_string( iter + i ).length();

				for ( int i = 0; i < strings_iter; i = i + 1 )
				{
					file = file + int_to_string( iter + i ) + mark;

					for ( int p = 0; p < max_size - int_to_string( iter + i ).length(); p = p + 1 )
						file = file + ' ';

					file = file + strings[ i ] + '\n';
				}

				set_file( filename, file );
			}
			if ( choice == "2" ) // same mark
			{
				cout << "Mark ( any word / character ): ";

				getline( cin, mark );
				if ( mark == "" )
					getline( cin, mark );

				string file = "";

				for ( int i = 0; i < strings_iter; i = i + 1 )
					file = file + mark + ' ' + strings[ i ] + '\n';

				set_file( filename, file );
			}
		}
	}
	else
		cout << "Empty / Invalid file.\n";
	

	return 0;
}
