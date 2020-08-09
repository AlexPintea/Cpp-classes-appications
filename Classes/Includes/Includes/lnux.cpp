// #include "lengths.cpp"



void num_digits ( int a, char result[] )
{
	int i=0;
	int size = length(a);

	while (a != 0)
	{
		result[ size - i - 1 ] = a%10 + 48;
		i=i+1;
		a=a/10;
	}
}


void remove_char_length ( string &a )
{
	string result = "";
	int size = a.length();
	for ( int i = 0; i < size - 1; i = i + 1 )
		result = result + a[ i ];

	a = result;
}
void command_linux ( string command_string )
{
	char command_char[1000];
	for ( int i = 0; i < command_string.length(); i = i +1 )
		command_char[ i ] = command_string[ i ];
	command_char[ command_string.length() ] = '\0';
	system( command_char );
}



bool is_folder( string filename );

void mkdir ( string name )
{
	if ( is_folder( name ) )
		return;

	string command = "mkdir " + name;

	command_linux( command );
}

void chown ( string name )
{
	string command = "chown -R " + name;

	command_linux( command );
}

void chmod ( string name, int permission )
{
	char digits[10];
	int size = length(permission);
	num_digits( permission, digits );

	for (int i=0; i<size; i=i+1)
	{
		if ( digits[i] > 7 )
		{
			cout << "Entered num. is not a valid linux permission\n";
			return;
		}
	}

	string command = "chmod -R " + int_to_string( permission ) + " " + name;

	command_linux( command );
}

void rm ( string name )
{
	string command = "rm -R " + name;

	command_linux( command );
}


void cp ( string filepath1, string filepath2 )
{
	string command = "cp -R " + filepath1 + " " + filepath2;

	command_linux( command );
}

void ls ()
{
	string command = "ls";

	command_linux( command );
}

string path ()
{
	system( "echo $PWD >> \"$PWD/cpp-sh\"" );

	string filepath = get_file( "cpp-sh" );
	remove_char_length( filepath );
	system( "rm -R cpp-sh" );

	return filepath;
}

string user ()
{
	system( "echo $USER >> \"$PWD/cpp-sh\"" );

	string user = get_file( "cpp-sh" );
	remove_char_length( user );

	system( "rm -R cpp-sh" );

	return user;
}

bool have_char ( string a, char b )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] == b )
			return 1;
	return 0;
}

void get_filenames ( string folder, string strings[] )
{
	if ( have_char( folder, '/' ) )
		folder = path() + folder;

	ofstream fo;
	fo.open( "files-ls" );
	fo.close(); // clear file

	fo.open( "files-ls" );
	fo << folder;
	fo.close();

	int strings_iter = 0;

	char command_linux[] = "IFS= read -r filepath < \"files-ls\"\ncd $filepath\nls_data=$( ls -m )\ncd ../\nrm -R files-ls\nfor value in $ls_data\ndo\n	echo $value >> files-ls\ndone";
	system ( command_linux );

	ifstream fi;
	fi.open( "files-ls" );
	string temp;
	string temps[ 10000 ];
	int temps_iter = 0;

	while ( getline( fi, temp ) )
	{
		temps[ temps_iter ] = temp;
		temps_iter = temps_iter + 1;
	}

	fi.close();	



	string result;
	for ( int i = 0; i < temps_iter; i = i + 1 )
	{
		temp = temps[ i ];
		bool have_char = 0;
		for ( int l = 0; l < temp.length(); l = l + 1 )
			if ( temp[ l ] == ',' )
			{
				have_char = 1;
				break;
			}

		result = "";
		if ( have_char )
			temp[ temp.length() - 1 ] = '\0';
		result = temp;

		if ( have_char )
		{
			strings[ strings_iter ] = strings[ strings_iter ] + result;			
			strings_iter = strings_iter + 1;
			strings[ strings_iter ] = "";
		}
		else
			strings[ strings_iter ] = strings[ strings_iter ] + result;			
	}
}

bool is_file ( string filename )
{
	string filepath;
	string ext;
	filename_ext_filepath( filename, ext, filepath );

	if ( ext != "" )
		filename = filename + '.' + ext;

	string command_file = "\"\nthen\n	echo \"1\" >> \"$PWD/cpp-sh\"\nelse\n	echo \"0\" >> \"$PWD/cpp-sh\"\nfi";
	if ( filepath == "" )
	{
		char command[1000] = "if test -f \"$PWD/";
		for ( int i = 0; i < filename.length(); i = i + 1 )
			command[ length( command ) ] = filename[ i ];
		for ( int i = 0; i < command_file.length(); i = i + 1 )
			command[ length( command ) ] = command_file[ i ];

		system( command );
	}
	else
	{
		char command[1000] = "if test -f \"";
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


long get_file_count ( string folder )
{
	if ( ! is_folder( folder ) )
		return -1;

	string strings[ 1000 ];
	get_filenames( folder, strings );

	return length( strings );
}

long size ( string filename )
{
	string filepath;
	string ext;

	string command_size_file = "\nSIZE=$( stat -c%s \"$FILE\" )\necho $SIZE >> \"$PWD/cpp-sh\"";
	string command_size_folder = "\nSIZE=$( du -s \"$FILE\" )\necho $SIZE >> \"$PWD/cpp-sh\"";

	if ( is_file( filename ) )
	{
		char command[ 1000 ] = "FILE=";
		for ( int i = 0; i < filename.length(); i = i + 1 )
			command[ length( command ) ] = filename[ i ];
		for ( int i = 0; i < command_size_file.length(); i = i + 1 )
			command[ length( command ) ] = command_size_file[ i ];

		system( command );
	}
	if ( is_folder( filename ) )
	{
		char command[ 1000 ] = "FILE=";
		for ( int i = 0; i < filename.length(); i = i + 1 )
			command[ length( command ) ] = filename[ i ];
		for ( int i = 0; i < command_size_folder.length(); i = i + 1 )
			command[ length( command ) ] = command_size_folder[ i ];

		system( command );
	}

	long file_size = 0;
	ifstream fi;
	fi.open( "cpp-sh" );
	fi >> file_size;

	fi.close();

//	system( "rm -R cpp-sh" );

	if ( is_folder( filename ) )
	{
		file_size = ( file_size - 4 ) / 4;
		long file_count = get_file_count( filename );
		if ( file_size > file_count ) return file_size;
		else return file_count;
	}

	return file_size;
}

void clear () { command_linux( "print \033c" ); }

void clear_leave () { command_linux( "clear" ); }

// modify intensity
void xrandr ( string name, int bright_int, int bright_decimals )
{
	string command = "xrandr --output " + name + " --brightness ";
	command = command + int_to_string( bright_int ) + "." + int_to_string( bright_decimals );

	command_linux( command );
}


