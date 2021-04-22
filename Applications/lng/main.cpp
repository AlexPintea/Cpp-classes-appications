#include <string>
#include <fstream>
#include <iostream>

using namespace std;

string real[ 50 ];
string user[ 50 ];
int iter = 0;

string data_path = "data/";
string function;
string include;

void get_user_real ()
{
	ifstream fi;

	fi.open( data_path + "data" );

	while ( fi >> real[ iter ] )
	{
		fi >> user[ iter ];
		iter = iter + 1;
	}

	fi.close();

	string swap;
	for ( int i = 0; i < iter - 1; i = i + 1 )
		for ( int l = i + 1; l < iter; l = l + 1 )
			if ( user[ i ] > user[ l ] )
			{
				swap = user[ i ];
				user[ i ] = user[ l ];
				user[ l ] = swap;

				swap = real[ i ];
				real[ i ] = real[ l ];
				real[ l ] = swap;				
			}
}

void get_function ()
{
	ifstream fi;
	fi.open( data_path + "function" );

	fi >> function;

	fi.close();
}

void get_include ()
{
	ifstream fi;
	fi.open( data_path + "include" );

	fi >> include;

	fi.close();
}

void info ( string file, string type, int pos, string strng )
{
	int size = file.length();

	if ( pos < 0 or pos >= size )
		return;

	int line = 0;

	int last_enter;

	for ( int i = 0; i <= pos; i = i + 1 )
		if ( file[ i ] == '\n' )
		{
			line = line + 1;
			last_enter = i;
		}
	line = line + 1;

	cout << "  (" << type << ") [" << line << ':' << pos - last_enter - 1 << "] " << strng << '\n';
}

void info ( string type, string strng )
{
	cout << "  (" << type << ") " << strng << '\n';
}

string get_file ( string filename )
{
	string file = "";
	string temp;

	ifstream fi;
	fi.open( filename );

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	return file;
}

bool have_at_pos ( string a, int pos, string b )
{
	int size_a = a.length();
	int size_b = b.length();

	if ( pos + size_b - 1 >= size_a or pos < 0 or pos > size_a )
		return 0;

	for ( int i = 0; i < size_b; i = i + 1 )
		if ( a[ pos + i ] != b[ i ] )
			return 0;

	return 1;
}


int is_commented ( string file, int pos )
{
	int size = file.length();

	if ( pos < 0 or pos >= size )
		return -1;

	int l = pos;
	while ( l > 0 and file[ l ] != '\n' )
	{
		if ( file[ l ] == '/' and file[ l - 1 ] == '/' )
			return 1;

		l = l - 1;
	}

	for ( int i = pos; i > 0; i = i - 1 )
		if ( file[ i ] == '*' and file[ i - 1 ] == '/' )
			return 1;

	return 0;
}


string add_includes ( string filename )
{
	string file = get_file( filename );

	int size = file.length();

	string remain = "";

	while ( remain != file )
	{
		if ( remain != "" )
			file = remain;
		remain = "";
		size = file.length();
		for ( int i = 0; i < size; i = i + 1 )
		{
			if ( have_at_pos( file, i, include ) and ! is_commented( file, i ) )
			{
				string incl = "";
				int l = i;
				while ( file[ l ] != '"' )
				{
					if ( l >= size )
					{
						info( file, "error", i, "Missing an ending '\"' for inclusion" );
						return "";
					}
					l = l + 1;
				}
				l = l + 1;
				while ( file[ l ] != '"' )
				{
					if ( l >= size )
					{
						info( file, "error", i, "Missing an ending '\"' for inclusion" );
						return "";
					}
					incl = incl + file[ l ];
					l = l + 1;
				}

				string incl_file = get_file( incl );

				if ( incl_file == "" )
				{
					info( file, "error", i, "File \"" + incl + "\" invalid for inclusion" );
					return "";
				}

				remain = remain + '\n' + incl_file + '\n';
				i = l;
			}
			else
				remain = remain + file[ i ];
		}
	}

	return file;
}

string convert ( string filename )
{
	string a = add_includes( filename );

	int size_a = a.length();

	string result = "";

	bool had_at_pos = 0;

	for ( int i = 0; i < size_a; i = i + 1 )
	{
		for ( int l = 0; l < iter; l = l + 1 )
			if ( have_at_pos( a, i, user[ l ] ) )
			{
				result = result + real[ l ];
				i = i + user[ l ].length() - 1;
				had_at_pos = 1;
				break;
			}

		if ( ! had_at_pos )
			result = result + a[ i ];
		else
			had_at_pos = 0;
	}

	return result;
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

void insert_char_before_pos ( string &a, int pos, char insert )
{
	int size = a.length();

	if ( pos < 0 or pos >= size )
		return;

	string result = "";

	for ( int i = 0; i < size; i = i + 1 )
		if ( pos != i )
			result = result + a[ i ];
		else
			result = result + insert + a[ i ];

	a = result;
}


string get_string ( string a, int i1, int i2 )
{
	int size = a.length();

	if ( i1 < 0 or i2 < 0 or i1 >= size or i2 >= size or i1 == i2 )
		return "";

	if ( i1 > i2 )
	{
		int swap = i1;
		i1 = i2;
		i2 = swap;
	}

	string result = "";

	for ( int i = i1; i <= i2; i = i + 1 )
		result = result + a[ i ];

	return result;
}

void remove_string ( string &a, string b )
{
	int size_a = a.length();
	int size_b = b.length();

	string result = "";

	for ( int i = 0; i < size_a; i = i + 1 )
		if ( have_at_pos( a, i, b ) )
			i = i + size_b - 1;
		else
			result = result + a[ i ];

	a = result;
}

bool add_main ( string filename )
{
	string file = get_file( filename );

	int size = file.length();

	int paranthesis = -1;

	string functions = "";
	string remain = "";


	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( have_at_pos( file, i, function ) and ! is_commented( file, i ) )
			for ( int l = i; l < size; l = l + 1 )
			{
				if ( file[ l ] == '{' )
				{
					if ( paranthesis == -1 )
						paranthesis = 1;
					else
						paranthesis = paranthesis + 1;
				}

				if ( file[ l ] == '}' )
					paranthesis = paranthesis - 1;

				if ( paranthesis == 0 )
				{
					paranthesis = -1;
					functions = functions + "\n\n" + get_string( file, i, l );
					i = l;
					break;
				}
				else
					if ( l == size - 1 )
					{
						info( file, "error", i, "Missing an ending '}' function paranthesis" );
						return 0;
					}
			}
		else
			remain = remain + file[ i ];
	}


	remove_string( functions, function );
	functions = functions + "\n\n";

	ofstream fo;
	fo.open( filename );
	fo.close(); // clear file

	fo.open( filename );

	fo << get_file( data_path + "inclusions" );

	fo << functions;

	fo << "int main ()\n{\n";

	fo << remain;

	fo << "\n\n	return 0;\n}";

	fo.close();

	return 1;
}

void command ( string command_string )
{
	char command_char[ command_string.length() ];
	for ( int i = 0; i < command_string.length(); i = i + 1 )
		command_char[ i ] = command_string[ i ];
	command_char[ command_string.length() ] = '\0'; 

	system( command_char );
}

int main ()
{
//	cout << "lng ";

	string filename = "user";
	string file = get_file( filename );
	if ( file == "" )
	{
		info( "error", "Provided file \"" + filename + "\" is invalid" );
		return 0;
	}
	string filepath;
	string ext;
	filename_ext_filepath( filename, ext, filepath );

	get_user_real();
	get_function();
	get_include();
	set_file( "a.cpp", convert( filename ) );
	if( ! add_main( "a.cpp" ) ) return 0;

	command( "g++ a.cpp && ./a.out && rm a.cpp" );

	return 0;
}
