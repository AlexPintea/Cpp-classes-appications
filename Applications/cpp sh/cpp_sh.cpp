#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

fstream cpp_sh_file;
string cpp_sh = "sh/cpp-sh";


string filename = "cpp_sh.cpp";

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

void clear_file ( string filename )
{
	ofstream fo;
	fo.open( filename );
	fo.close();
}

void make_file ( string filename )
{
	clear_file( filename );
}

void make_file_with_string ( string filename, string file )
{
	ofstream fo;
	fo.open( filename );
	fo << file;
	fo.close();
}

void set_file ( string filename, string text )
{
	clear_file( filename );

	ofstream fo;
	fo.open( filename );
	fo << text;
	fo.close();
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + "\n";

	fi.close();

	return file;
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

string get ( string sh_file )
{
	sh_file = "sh/" + sh_file + "/" + sh_file + ".sh";

	command_linux( "bash " + sh_file );

	sleep(0.1);

	string file = get_file( cpp_sh );
	remove_char( file, file.length() - 1 );
	return file;
}


string get ( string sh_file, string parameters )
{
	sh_file = "sh/" + sh_file + "/" + sh_file + ".sh";

	// set "cpp-sh" to the parameters
	set_file( cpp_sh, parameters );

	command_linux( "bash " + sh_file );

	sleep(0.1);

	string file = get_file( cpp_sh );
	remove_char( file, file.length() - 1 );
	return file;
}





string get_filepath()
{
	// also makes the file
	clear_file( cpp_sh );
 	string filepath = get ( "filepath" );

	return filepath;
}





bool is_folder( string folder_filepath )
{
	bool is_folder = true;

	// makes a file for empty folders
	make_file( folder_filepath + "/file" ); 

	string files = get ( "is_folder", folder_filepath );

	if ( files[0] <= 31 or files[0] >= 127 ) // add conditions if necessary
		is_folder = false;

	return is_folder;
}

bool is_file_or_folder ( string file_filepath )
{
	bool is_file = false;
	string files = get ( "size", file_filepath );
	if ( files[0] >= '0' and files[0] <= '9' )
		is_file = true;

	return is_file;
}

bool is_file ( string file_filepath )
{
	return !( is_file_or_folder( file_filepath ) and is_folder( file_filepath ) );
}






void rm ( string folder_or_file_filepath )
{
	if ( !is_file_or_folder( folder_or_file_filepath ) )
	{
		cout << "Path invalid.\n";
		return;
	}

	command_linux( "rm -R " + folder_or_file_filepath );

	cout << "Folder Deleted.\n";
}


// inverts a string
void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}

// filepath without folder / file name
string get_filepath_of ( string folder_or_file_filepath )
{
	bool passed = false;
	string filepath = "";
	for ( int i=folder_or_file_filepath.length(); i>=0; i=i-1 )
	{
		if ( passed )
			filepath = filepath + folder_or_file_filepath[i];
		if ( folder_or_file_filepath[i] == '/' )
			passed = true;
	}
	invert_string( filepath );

	return filepath;
}

void mv ( string folder_or_file_filepath, string last_filename )
{
	if ( !is_file_or_folder( folder_or_file_filepath ) )
	{
		cout << "Path invalid.\n";
		return;
	}


	// filepath without folder name
	string filepath = get_filepath_of ( folder_or_file_filepath );

	command_linux( "mv " + folder_or_file_filepath + " " + filepath + '/' + last_filename );

	cout << "Folder Renamed.\n";
}

// check if a string is a long
bool is_long ( string a )
{
	int size = a.length();

	if ( size > 19 and a[0] == '-' )
		return false;
	if ( size >= 19 and a[0] != '-' )
		return false;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}


// convert string to long
long string_to_long ( string a )
{
	if ( a.length() == 1 )
		return a[0] - 48;

	int size = a.length();

	int iter = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		iter = 1;
	}

	long num_long = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_long = num_long * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_long = -num_long;

	return num_long;
}


// convert string to double
double string_to_double ( string a )
{
	if ( a.length() == 1 )
		return a[0] - 48;

	if ( is_long( a ) )
		return string_to_long(a);


	double num_double = 0;

	int i = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		i = 1;
	}


	while ( a[i] != '.' )
	{
		num_double = num_double * 10 + ( a[i] - 48 );
		i = i + 1;
	}

	i = i + 1;
	int decimal_tens = 10;

	while ( a[i] )
	{
		double temp = a[i] - 48;
		num_double = num_double + temp / decimal_tens ;
		decimal_tens = decimal_tens * 10;
		i = i + 1;
	}

	if ( is_neg )
		num_double = -num_double;


	return num_double;
}


double size ( string folder_or_file_filepath )
{
	if ( !is_file_or_folder( folder_or_file_filepath ) )
	{
		cout << "Path invalid.\n";
		return -1;
	}

	if ( is_folder( folder_or_file_filepath ) )
	{
		string files = get ( "size_folder", folder_or_file_filepath );

		string result = "";
		for ( int i=0; i<files.length(); i=i+1 )
			if ( files[i] != ' ' )
				result = result + files[i];
			else
				break;

		sleep(0.9);

		return string_to_double( result ) / 4 - 1;
	}

	// else, if file
	string files = get ( "size", folder_or_file_filepath );

	return string_to_double( files );
}


string get_user ()
{
	string user = get( "user" );

	int i=0;
	while ( user[i] >= 32 and user[i] <= 127 )
		i=i+1;
	i=i+1;

	string result = "";
	for ( int b=i; b<user.length(); b=b+1 )
		result = result + user[b];

	return result;
}








int main ()
{

	command_linux( "mkdir folder" );
	command_linux( "mkdir sh/folder" );
	make_file_with_string( "file", "this is in the file" );
	

	string filepath = get_filepath();
	cout << filepath << "\n";

 	string user = get_user();
	cout << user << "\n";

	sleep(1);

	cout << is_folder( "folder" ) << "\n";

	sleep(1);

	cout << is_folder( "file" ) << "\n";

	sleep(1);

	cout << is_file( "file" ) << "\n";

	sleep(1);

	cout << is_file( "folder" ) << "\n";

	sleep(1);

	mv( "sh/folder", "folder1" );

	sleep(1);

	cout << size( "file" ) << "\n";

	sleep(1);

	cout << size( "folder" ) << "\n";

	sleep(1);

	
	rm( "file" );
	rm( "sh/folder1" );
	rm( "folder" );

	return 0;
}
