#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

string conversions[ 1000 ];
int conversions_iter = 0;

string titles[ 1000 ];
string paragraphs[ 1000 ];
string title = "";

int conv = -1;

int paragraphs_iter = 0;

int l;

void string_to_char (string a, char result[])
{
	int size = a.length();

	int i;

	for (i=0; i<size; i=i+1)
		result[i] = a[i];

	result[i] = '\0';
}

void command_linux ( string command_string )
{
	char command_char[1000];
	string_to_char( command_string, command_char );
	system( command_char );
}

void remove_last_char ( string &p )
{
	string result = "";

	for ( int i = 0; i < p.length() - 1; i = i + 1 )
		result = result + p[ i ];

	p = result;
}

void get_conversions ()
{
	command_linux( "cd conversions && ls -p > ../conversion" );

	ifstream fi;
	fi.open( "conversion" );

	string temp;

	while ( getline( fi, temp ) )
	{
		remove_last_char( temp );
		conversions[ conversions_iter ] = temp;
		conversions_iter = conversions_iter + 1;
	}

	int a;

	fi.close();

	command_linux( "rm -r conversion" );
}

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

void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}

// is numeric char
bool is_numeric( char a )
{
	if ( a >= '0' and a <= '9' )
		return true;

	return false;
}

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

		if ( is_numeric( a_char ) )
			result = result + a_char;
		a = a / 10;
	}

	if ( is_neg )
		result = result + '-';

	invert_string( result );

	return result;
}

string reduce_spaces ( string p )
{
	int i1 = 0;
	int i2 = p.length() - 1;
	string result = "";

	for ( int i = 0; i < p.length(); i = i + 1 )
		if ( ! ( p[ i ] == ' ' or p[ i ] == '	' ) )
		{
			i1 = i;
			break;
		}

	for ( int i = p.length() - 1; i >= 0; i = i - 1 )
		if ( ! ( p[ i ] == ' ' or p[ i ] == '	' ) )
		{
			i2 = i;
			break;
		}

	for ( int i = i1; i <= i2; i = i + 1 )
		result = result + p[ i ];

//	cout << "(" << result << ") ";

	return p;
}

int valid_choice ( string choice )
{
	choice = reduce_spaces( choice );

	for ( int i = 0; i < conversions_iter; i = i + 1 )
		if ( choice == conversions[ i ] or choice == int_to_string( i + 1 ) )
			return i;

	return -1;
}

int convert_to_filetype ( string filename, string title[], string files[] )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	int l = 0;

	files[ 0 ] = "";

	while ( getline( fi, temp ) )
	{
		// skip empty
		bool is_empty = 1;
		for ( int i = 0; i < temp.length(); i = i + 1 )
			if ( temp[ i ] != ' ' and temp[ i ] != '	' and temp[ i ] != '\n' )
			{
				is_empty = 0;
				break;
			}

		if ( ! is_empty )
		{
			files[ l ] = files[ l ] + temp + "\n";
			continue;
		}

		if ( is_empty )
		{
			l = l + 1;
			files[ l ] = "";
			while ( getline( fi, temp ) )
			{
				for ( int i = 0; i < temp.length(); i = i + 1 )
					if ( temp[ i ] != ' ' and temp[ i ] != '	' and temp[ i ] != '\n' )
					{
						is_empty = 0;
						break;
					}
				
				if ( is_empty == 0 ) break;
			}
		}

		files[ l ] = files[ l ] + temp + "\n";
	}

	l = l + 1;


	fi.close();


	// remove last char
	for ( int i = 0; i < l; i = i + 1 )
	{
		string result = "";
		temp = files[ i ];
		for ( int m = 0; m < temp.length() - 1; m = m + 1 )
			result = result + temp[ m ];
		files[ i ] = result;
	}

	// extract title
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];

		int temp_iter = 0;

		while ( temp[ temp_iter ] == ' ' or temp[ temp_iter ] == '	' ) temp_iter = temp_iter + 1;

		if ( temp_iter >= l ) break;

		int iter_1 = -1;
		int iter_2 = -1;

		title[ i ] = "";

		if ( temp[ temp_iter ] == '"' )	
		{
			iter_1 = temp_iter;
			temp_iter = temp_iter + 1;
			while ( temp[ temp_iter ] and temp[ temp_iter ] != '"' )
				temp_iter = temp_iter + 1;

			if ( temp[ temp_iter ] == '"' )
				iter_2 = temp_iter;
		}
		else
			continue;

		files[ i ] = "";

		if ( iter_1 != -1 and iter_2 != -1 )
		{
			for ( int m = iter_1 + 1; m < iter_2; m = m + 1 )
				title[ i ] = title[ i ] + temp[ m ];

			for ( int m = iter_2 + 1; m < temp.length(); m = m + 1 )
				files[ i ] = files[ i ] + temp[ m ];			
		}
	}

	// replace '	' with ' ' and reduce ' '
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];
		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] == '	' )
				temp[ m ] = ' ';
		files[ i ] = temp;

		temp = title[ i ];
		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] == '	' )
				temp[ m ] = ' ';
		title[ i ] = temp;



		temp = files[ i ];
		string result = "";
		bool have_space = 0;

		for ( int m = 0; m < temp.length(); m = m + 1 )
		{
			result = result + temp[ m ];

			if ( temp[ m ] == ' ' )
				have_space = 1;

			while ( temp[ m ] == ' ' )
				m = m + 1;

			if ( have_space )
				m = m - 1;
			have_space = 0;
		}

		files[ i ] = result;


		temp = title[ i ];
		result = "";
		have_space = 0;

		for ( int m = 0; m < temp.length(); m = m + 1 )
		{
			result = result + temp[ m ];

			if ( temp[ m ] == ' ' )
				have_space = 1;

			while ( temp[ m ] == ' ' )
				m = m + 1;

			if ( have_space )
				m = m - 1;
			have_space = 0;
		}

		title[ i ] = result;
	}

	// trim for ' ', "\n " and // remove title '.'
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];
		string result = "";

		int iter_1 = -1;
		int iter_2 = -1;

		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '\n' )
			{
				iter_1 = m;
				break;
			}

		for ( int m = temp.length() - 1; m >= 0; m = m - 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '\n' )
			{
				iter_2 = m;
				break;
			}

		for ( int m = iter_1; m <= iter_2; m = m + 1 )
		{
			if ( temp[ m ] == '\n' )
			{
				// if ( m > 0 and temp[ m - 1 ] != '.' ) // adds '.' at end of line
				//	result = result + '.';
				result = result + '\n';
				while ( temp[ m ] and ( temp[ m ] == '\n' or temp[ m ] == ' ' ) )
					m = m + 1;
			}

			result = result + temp[ m ];
		}

		files[ i ] = result;

		temp = title[ i ];
		result = "";

		iter_1 = -1;
		iter_2 = -1;

		for ( int m = 0; m < temp.length(); m = m + 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '	' and temp[ m ] != '\n' )
			{
				iter_1 = m;
				break;
			}

		for ( int m = temp.length() - 1; m >= 0; m = m - 1 )
			if ( temp[ m ] != ' ' and temp[ m ] != '	' and temp[ m ] != '\n' )
			{
				iter_2 = m;
				break;
			}

		for ( int m = iter_1; m <= iter_2; m = m + 1 )
		{
			if ( temp[ m ] == '\n' )
			{
				// if ( m > 0 and temp[ m - 1 ] != '.' ) // adds '.' at end of line
				//	result = result + '.';
				result = result + '\n';
				while ( temp[ m ] and ( temp[ m ] == '\n' or temp[ m ] == ' ' ) )
					m = m + 1;
			}

			// remove '.', leave ".."
			// if ( m == iter_2 and temp[ m ] == '.' and temp[ m - 1 ] and temp[ m - 1 ] != '.' )
			// 	break;

			result = result + temp[ m ];
		}

		title[ i ] = result;
	}

	// make large first letter, // add '.' to files
	for ( int i = 0; i < l; i = i + 1 )
	{
		temp = files[ i ];
		if ( temp[ 0 ] >= 'a' and temp[ 0 ] <= 'z' )
			temp[ 0 ] = temp[ 0 ] - 32;
		for ( int m = 0; m < temp.length(); m = m + 1 )
		{
			if ( temp[ m ] == '\n' and m < temp.length() - 1 )
				if ( temp[ m + 1 ] >= 'a' and temp[ m + 1 ] <= 'z' )
					temp[ m + 1 ] = temp[ m + 1 ] - 32;
		}

		// if ( temp[ temp.length() - 1 ] != '.' )
		//	temp = temp + '.';
		// files[ i ] = temp;
			

		temp = title[ i ];
		if ( temp[ 0 ] >= 'a' and temp[ 0 ] <= 'z' )
			temp[ 0 ] = temp[ 0 ] - 32;
		title[ i ] = temp;
	}


	return l;
}

void filename_ext_filepath ( string &filename, string &ext, string &filepath )
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
		if ( filename[ i ] == '.' )
		{
			have_ext = true;
			break;
		}

	if ( ! have_ext )
		return;

	int d = 0;
	for ( int i = filename.length() - 1; i >= 0; i = i - 1 )
		if ( filename[ i ] != '/' )
			d = i;
		else
			break;

	filepath = "";
	for ( int i = 0; i < d; i = i + 1 )
		filepath = filepath + filename[ i ];

	string file_name = "";
	int l = 0;
	for ( int i = d; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}

		file_name = file_name + filename[ i ];
	}

	for ( int i = l; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' ) continue;	

		ext = ext + filename[ i ];
	}

	filename = file_name;
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	if ( file != "" )
		remove_last_char( file );
	else
		return "";

	fi.close();

	return file;
}

void set_file ( string filename )
{
	ofstream fo;

	string ext;
	string filepath;

	filename_ext_filepath( filename, ext, filepath );

	title = filename;

	filename = filepath + filename + '.' + get_file( "conversions/" + conversions[ conv ] + "/extension" );

	fo.open( filename );

	fo << get_file( "conversions/" + conversions[ conv ] + "/before_filename" ) << '\n';
	fo << title;
	fo << get_file( "conversions/" + conversions[ conv ] + "/after_filename" ) << '\n';

	for ( int i = 0; i < paragraphs_iter; i = i + 1 )
	{
		fo << get_file( "conversions/" + conversions[ conv ] + "/before_title" ) << '\n';
		fo << titles[ i ];
		fo << get_file( "conversions/" + conversions[ conv ] + "/title_paragraph" ) << '\n';
		fo << paragraphs[ i ];
		fo << get_file( "conversions/" + conversions[ conv ] + "/follows_paragraph" ) << '\n';
	}

	fo << get_file( "conversions/" + conversions[ conv ] + "/follows" ) << '\n';

	fo.close();
}

int main ()
{
	get_conversions();
	string choice = "";

	string filename = "";

	cout << "\033cFilename: ";

	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	do
	{
		cout << "\033cChosen filename: '" << filename << "'\n\n";
		cout << "Choices: ";
		for ( int i = 0; i < conversions_iter; i = i + 1 )
			cout << i + 1 << ". " << conversions[ i ] << "  ";
		cout << "\nYour choice: ";

		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		conv = valid_choice( choice );
	}
	while ( conv == -1 );

	paragraphs_iter = convert_to_filetype( filename, titles, paragraphs );

	set_file( filename );

	
	int u;

	return 0;
}
