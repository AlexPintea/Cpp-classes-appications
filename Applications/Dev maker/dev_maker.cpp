#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


bool have_includes = 0;
bool have_choices = 0;


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}

int length ( char a[] )
{
	int i = 0;

	while ( a[ i ] )
		i = i + 1;

	return i;
}


// get file data
string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();

	return file;
}

// checks if  a  is in  b   or   b  is in  a  for datatype "string"
bool a_is_in_b ( string a, string b )
{
	if (a == b)
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a > size_b )
	{
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
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	return a_is_in_b( a, b );
}

// a[] and b[] have iters
bool is_in ( int a[], int b[], int size, int iter )
{
	for ( int i=0; i<size; i=i+1 )
		if ( iter >= a[i] and iter <= b[i] )
			return true;

	return false;
}

// replace  b  in  a  for datatype "string"
string replace_b_in_a ( string &a, string b, string replacement )
{
	if ( !b_is_in_a( a, b ) )
		return a;

	int size_a = a.length();
	int size_b = b.length();

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}


	for ( int i=0; i<size_a; i=i+1 )
	{
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			result = result + a[i];
		else
		{
			result = result + replacement;
			while ( is_in( iter_1, iter_2, size_iter, i ) )
				i = i + 1;
			i = i - 1;
		}
	}

	a = result;

	return a;
}

void command ( string command_string )
{
	char command_char[ 1000 ];
	for ( int i = 0; i < command_string.length(); i = i + 1 )
		command_char[ i ] = command_string[ i ];
	command_char[ command_string.length() ] = '\0'; 

	system( command_char );
}

void lower ( string &a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			a[ i ] = a[ i ] + 32;
}

string upper ( string a )
{
	if ( a == "" )
		return "";
	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = (char) ( (int) a[ 0 ] - 32 );
	return a;
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

void remove_char_length ( string &a )
{
	string result = "";
	int size = a.length();
	for ( int i = 0; i < size - 1; i = i + 1 )
		result = result + a[ i ];

	a = result;
}

bool is_folder ( string filename )
{
	string filepath;
	string ext;
	filename_ext_filepath( filename, ext, filepath );

	if ( ext != "" )
		filename = filename + '.' + ext;

	string command_file = "\"\nthen\n	echo \"1\" >> \"$PWD/cpp-sh\"\nelse\n	echo \"0\" >> \"$PWD/cpp-sh\"\nfi";
	if ( filepath == "" )
	{
		char command[1000] = "if test -d \"$PWD/";
		for ( int i = 0; i < filename.length(); i = i + 1 )
			command[ length( command ) ] = filename[ i ];
		for ( int i = 0; i < command_file.length(); i = i + 1 )
			command[ length( command ) ] = command_file[ i ];

		system( command );
	}
	else
	{
		char command[1000] = "if test -d \"";
		for ( int i = 0; i < filepath.length(); i = i + 1 )
			command[ length( command ) ] = filepath[ i ];
		for ( int i = 0; i < filename.length(); i = i + 1 )
			command[ length( command ) ] = filename[ i ];
		for ( int i = 0; i < command_file.length(); i = i + 1 )
			command[ length( command ) ] = command_file[ i ];

		system( command );
	}

	string result = get_file( "cpp-sh" );
	remove_char_length( result );

	system( "rm -R cpp-sh" );

	if ( result == "1" )
		return 1;
	return 0;
}


void replace_dev_file ( string replacement )
{
	string folder = upper( replacement );
	replacement = replacement + ".cpp";

	string file = "";
	string temp;

	// get file "dev.cpp"
	ifstream fi;
	fi.open ( folder + "/dev.cpp" );

	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	file[ file.length() - 1 ] = ' ';

	fi.close();

	// replace file "dev.cpp"
	replace_b_in_a ( file, "dev.cpp", replacement );

	// clear file "dev.cpp"
	ofstream fo;
	fo.open ( folder + "/dev.cpp" );
	fo.close(); // clear file


	// set file "dev.cpp"
	fo.open ( folder + "/dev.cpp" );

	fo << file;

	fo.close(); // clear file

	string command_string = "cp -R '" + folder + "/dev.cpp' '" + folder + '/' + replacement + "'";
	command ( command_string );

	command_string = "rm -R '" + folder + "/dev.cpp'";
	command ( command_string );

	command_string = "cd '" + folder + "' && g++ -L a.out '" + replacement + "' && ./a.out";
	command_string = command_string +  " && rm -R a.out\n";
	command ( command_string );

	fi.open ( folder + '/' + replacement );

	int file_iter = 0;
	file = "";
	while ( getline( fi, temp ) )
	{
		if ( ! have_includes and file_iter == 0 )
		{
			file = file + "#include <string>\n#include <fstream>\n#include <iostream>\n#include <string.h>\n\nusing namespace std;\n\n";
			file_iter = file_iter + 1;
			continue;
		}		


		if ( file_iter >= 5 and file_iter <= 7 )
		{
			file_iter = file_iter + 1;
			continue;
		}

		if ( file_iter == 8 )
		{
			file = file + "	make ( \"" + replacement + "\" ); // always on top ( precedes all your code )\n";
			file_iter = file_iter + 1;
			continue;
		}
		if ( file_iter == 9 )
		{
			file = file + "	// remake ( \"" + replacement + "\" ); // remakes your makefile, file 'e', and does 'make'\n\n";
			file_iter = file_iter + 1;
			continue;
		}

		file = file + temp + '\n';

		file_iter = file_iter + 1;
	}

	fi.close();

	fo.open ( folder + '/' + replacement );
	fo.close(); // clear file

	fo.open ( folder + '/' + replacement );
	fo << file;
	fo.close();
}



// moves strings of text to temps[]
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

bool have_main ( string l )
{
	string strings[ 10000 ];

	int strings_iter = move_strings( l, strings );

	bool is_datatype = 0;
	bool is_main = 0;

	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( strings[ i ] == "main" )
			is_main = 1;

		if ( strings[ i ] == "int" or strings[ i ] == "void" )
			is_datatype = 1;
	}

	if ( is_datatype and is_main )
		return 1;
	return 0;
}


void replace_choices_file ( string filename )
{
	string folder = upper( filename );
	filename = filename + ".cpp";

	string command_string = "rm -R '" + folder + "/dev.cpp'";
	command ( command_string );

	command_string = "cp -R 'files/choices/temp.cpp' '" + folder + '/' + filename + "'";
	command ( command_string );

	command_string = "rm -R 'files/choices/temp.cpp' && rm -R 'files/choices/a.out'";
	command ( command_string );

	ifstream fi;
	fi.open( folder + '/' + filename );

	string temp;
	string file = "";
	int file_iter = 0;
	while ( getline( fi, temp ) )
	{
		if ( ! have_includes and file_iter == 0 )
		{
			file = file + "#include <string>\n#include <fstream>\n#include <iostream>\n#include <string.h>\n\nusing namespace std;\n\n";
			file_iter = file_iter + 1;
			continue;
		}		

		if ( have_includes )
		{
			if ( file_iter >= 3 and file_iter <= 41 )
			{
				file_iter = file_iter + 1;
				continue;
			}

			if ( file_iter >= 74 and file_iter <= 82 )
			{
				file_iter = file_iter + 1;
				continue;
			}

			if ( file_iter >= 107 and file_iter < 123 )
			{
				file_iter = file_iter + 1;
				continue;
			}
		}

		file = file + temp + '\n';
		file_iter = file_iter + 1;
	}

	fi.close();




	ofstream fo;
	fo.open( folder + '/' + filename );
	fo.close(); // clear file

	fo.open( folder + '/' + filename );
	fo << file;
	fo.close();

	cout << "\033c";
	cout << "";

	command_string = "cd '" + folder + "' && g++ -L a.out '" + filename + "' && ./a.out";
	command ( command_string );





	file = "";
	fi.open( folder + '/' + filename );

	while ( getline( fi, temp ) )
	{
		if ( b_is_in_a( temp, "always on top ( precedes all your code )" ) )
		{
			file = file + "	make ( \"" + filename + "\" ); // always on top ( precedes all your code )\n";
			continue;
		}

		if ( b_is_in_a( temp, "remakes your makefile, file 'e', and does 'make'" ) )
		{
			file = file + "	// remake ( \"" + filename + "\" ); // remakes your makefile, file 'e', and does 'make'\n";
			continue;
		}

		file = file + temp + '\n';
	}

	fi.close();


	fo.open( folder + '/' + filename );
	fo.close(); // clear file

	fo.open( folder + '/' + filename );
	fo << file;
	fo.close();
}

void make ()
{
	cout << "\033c";
	cout << "Application name: ";
	string filename;
	getline( cin, filename );
	while ( filename == "" )
		getline( cin, filename );

	string choice;
	cout << "Include \"includes\" ( y / n ): ";
	getline( cin, choice );
	while ( choice == "" )
		getline( cin, choice );

	if ( choice == "y" )
	{
		have_includes = 1;
	}

	cout << "Add Choices ( y / n ): ";
	getline( cin, choice );
	while ( choice == "" )
		getline( cin, choice );

	if ( choice == "y" )
	{
		have_choices = 1;
		string command_string = "cd files/choices && g++ -L a.out choices.cpp && ./a.out";
		command ( command_string );
	}

	string ext;
	string filepath;
	filename_ext_filepath ( filename, ext, filepath );
	reduce_spaces ( filename );
	lower ( filename );

	if ( is_folder ( upper( filename ) ) )
	{
		cout << "\nApplication folder '" << upper( filename ) << "' already made.\nRemake it ( y / n ): ";

		getline( cin, choice );
		while ( choice == "" )
			getline( cin, choice );

		if ( choice != "y" )
		{
			cout << "Aborted.\n";
			return;
		}

		command ( "rm -R '" + upper( filename ) + "'" );
	}

	cout << "\033c";
	command ( "cp -R 'files/Dev' '" + upper( filename ) + "'" );

	if ( have_choices )
		replace_choices_file ( filename );
	else
		replace_dev_file ( filename );

	cout << "Application '" << upper( filename ) << "\' was made.\n";
}






int main ()
{
	make();

	return 0;
}
