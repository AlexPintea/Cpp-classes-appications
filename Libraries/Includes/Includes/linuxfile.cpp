ofstream lnux_file;

class Linuxfile // in progress
{

	string name;
	string filename;
	string file;

	int times_copied;

	string name_to_filename(string name)
	{
		string filename = name + ".sh";
		return filename;
	}


	int length_linuxfile(int a)
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

	// inverts a string
	void invert_string_linuxfile( string &a )
	{
		int size = a.length();

		string b = "";

		for ( int i=size-1; i>=0; i=i-1 )
			b = b + a[i];

		a = b;
	}

	// is numeric char
	bool is_numeric_linuxfile( char a )
	{
		if ( a >= '0' and a <= '9' )
			return true;

		return false;
	}

	// converts an int to a string
	string int_to_string_linuxfile (int a)
	{
		int size = length_linuxfile(a);

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

			if ( is_numeric_linuxfile( a_char ) )
				result = result + a_char;
			a = a / 10;
		}

		if ( is_neg )
			result = result + '-';

		invert_string_linuxfile( result );

		return result;
	}

	void setFilename() // also find file in folder and rnme it
	{
		this->filename = name_to_filename(name);
	}

	string command_compile()
	{
		string command = "./" + this->filename;

		return command;
	}

	string command_make_executable ()
	{
		string command = "chmod -R 767 " + this->filename;

		return command;
	}

	void execute_command ( string command )
	{
		char result[100];
		int size = command.length();
		int i;
		for (i=0; i<size; i=i+1)
			result[i] = command[i];
	
		result[i] = '\0';

		system( result );
	}

  public:
	
	Linuxfile()
	{
		this->name = "";
		this->filename = "";
		this->file = "";
		this->times_copied = 1;
	}

	Linuxfile(string name) // check for existing files
	{
		this->name = name;
		this->filename = name_to_filename( name );
		this->file = "";
		this->times_copied = 1;
	}

	Linuxfile(string name, string file) // check for existing files
	{
		this->name = name;
		this->filename = name_to_filename( name );
		this->file = file;
		this->times_copied = 1;
	}

	string getName()
	{
		return this->name;
	}

	string getFilename()
	{
		return this->filename;
	}

	string getFile()
	{
		return this->file;
	}

	void setFile( string file )
	{
		this->file = file;
	}

	void setName( string data ) // check for existing files
	{
		this->name = data;
		setFilename();
	}

	void saveFile()
	{
		fstream file;
		lnux_file.open( this->filename );

		this->file = "";

		string entry;
		getline( file, entry ); // to continue
		while ( getline( file, entry ) )
			this->file = this->file + entry + "\n";

		lnux_file.close();
	}

	void clear ()
	{
		ofstream file;

		lnux_file.open( this->filename );
		lnux_file.close();

		this->file = "";
	}

	void make_executable ()
	{
		execute_command( command_make_executable () );
	}

	void compile ()
	{
		make_executable ();

		execute_command( command_compile() );
	}



	void empty_and_check ()
	{
		ofstream file;

		cout << "\nFile " << this->filename << " will be emptied to be checked. Do you want to continue? ( y/n ): ";
		char answer;
		cin >> answer;

		if ( answer == 'y' )
		{
			clear();

			lnux_file.open( this->filename );

			lnux_file << "echo File " << this->filename << " compiles. It will be emptied now.";

			lnux_file.close();

			execute_command( command_compile() );

			clear();
		}
		else
			cout << "Aborted checking file " << filename << ".\n\n";
	}


	void make_empty_linux_file ()
	{
		ofstream file;

		cout << "\nmake_empty_linux_file does not check for existing files of the same name.\nIf they exist, they will be deleted and replaced with an empty lnux_file.\nCheck for possibly existing file:  " << this->name << ".sh  in this folder.\nDo you want to continue? ( y/n ): ";
		char answer;
		cin >> answer;

		if (answer == 'y')
		{
			lnux_file.open( this->filename );

			make_executable();

			lnux_file << "echo Newly made file " << this->filename << " compiles. It will be emptied now.\n\n";

			lnux_file.close();

			this->file = "";

			compile();

			clear();
		}
		else
			cout << "Aborted creating empty file " << filename << ".\n\n";
	}


	void enter ( string data )
	{
		fstream file;

		this->saveFile();

		lnux_file.open( this->filename );

		if ( this->file != "" )
			lnux_file << "\n" << data;
		else
			lnux_file << data;

		lnux_file.close();

		this->saveFile();
	}
	
	void delete_file ()
	{
		cout << "Are you sure you want to delete file: " << this->filename << "? ( y/n ): ";
		char answer;
		cin >> answer;

		if ( answer == 'y' )
		{
			string command = "rm -R " + this->filename;

			execute_command( command );
		}
		else
			cout << "Aborted deleting file " << this->filename << ".\n";

		Linuxfile();
	}

	void copy_file_linuxfile()
	{
		string command = "cp -R " + this->filename + " " + this->name + " " + int_to_string_linuxfile( this->times_copied ) + ".sh";

		this->times_copied = this->times_copied + 1;

		execute_command( command );
	}

};






string name_to_filename(string name)
{
	string filename = name + ".sh";
	return filename;
}


void execute_command( string command )
{
	char result[100];
	int size = command.length();
	int i;
	for (i=0; i<size; i=i+1)
		result[i] = command[i];
	
	result[i] = '\0';

	system( result );
}

string command_compile( string filename )
{
	string command = "./" + filename;

	return command;
}

string command_make_executable ( string filename )
{
	string command = "chmod -R 767 " + filename;

	return command;
}










void clear (string filename)
{
	ofstream file;

	lnux_file.open( filename );
	lnux_file.close();
}

void make_executable ( string filename )
{
	execute_command( command_make_executable ( filename ) );
}

void compile ( string filename )
{
	make_executable ( filename );

	execute_command( command_compile( filename ) );
}

int length_linuxfile ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
}

void compile ( string filenames[] )
{
	int size = length_linuxfile(filenames);

	for ( int i=0; i<size; i=i+1 )
	{
		make_executable( filenames[i] );

		compile( filenames[i] );
	}
}

void compile ( Linuxfile Linuxfiles[] )
{
	string filenames[100];

	int i=0;

	while ( Linuxfiles[i].getFilename() != "" )
	{
		Linuxfiles[i].compile();
		i=i+1;
	}

}

void enter ( string filename, string data )
{
	ofstream file;

	lnux_file.open( filename );

	lnux_file << "\n" << data;

	lnux_file.close();
}

void make_empty_linux_file ( string filenames[] )
{
	int size = length_linuxfile(filenames);

	cout << "\n\nMake sure you do not have any of these files already in this folder:\n";

	
	for ( int i=0; i<size; i=i+1 )
		cout << filenames[i] << " ";
	cout << "\n";

	cout << "Are those files  not  in this folder? ( y/n ): ";
	char answer;
	cin >> answer;

	if (answer == 'y')
		for ( int i=0; i<size; i=i+1 )
		{
			ofstream file;

			lnux_file.open( filenames[i] );
			lnux_file.close();

			make_executable( filenames[i] );
		}
	else
		cout << "Abort making files.\n\n";
}

void make_empty_linux_file ( Linuxfile Linuxfiles[] )
{
	string filenames[100];

	cout << "\n\nMake sure you do not have any of these files already in this folder:\n";

	int i=0;

	while ( Linuxfiles[i].getFilename() != "" )
	{
		filenames[i] = Linuxfiles[i].getFilename();
		cout << filenames[i] << " ";
		i=i+1;
	}

	cout << "\n";

	int size = i;

	cout << "Are those files  not  in this folder? ( y/n ): ";
	char answer;
	cin >> answer;

	if ( answer == 'y')
		for ( int i=0; i<size; i=i+1 )
		{
			ofstream file;

			lnux_file.open( Linuxfiles[i].getFilename() );
			lnux_file.close();

			make_executable( Linuxfiles[i].getFilename() );
		}
	else
		cout << "Abort making files.\n\n";
}




void empty_and_check ( string filename )
{
	ofstream file;

	cout << "\nFile " << filename << " will be emptied to be checked. Do you want to continue? ( y/n ): ";
	char answer;
	cin >> answer;

	if ( answer == 'y' )
	{
		clear( filename );

		lnux_file.open( filename );

		lnux_file << "echo File " << filename << " compiles. It will be emptied now.";

		lnux_file.close();

		execute_command( command_compile( filename ) );

		clear( filename );
	}
	else
		cout << "Aborted checking file " << filename << ".\n\n";
}


void make_empty_linux_file ( string name )
{
	ofstream file;

	string filename = name_to_filename( name );

	cout << "\nmake_empty_linux_file does not check for existing files of the same name.\nIf they exist, they will be deleted and replaced with an empty lnux_file.\nCheck for possibly existing file:  " << name << ".sh  in this folder.\nDo you want to continue? ( y/n ): ";
	char answer;
	cin >> answer;

	if (answer == 'y')
	{
		string filename = name + ".sh";

		lnux_file.open( filename );

		make_executable( filename );

		lnux_file << "echo Newly made file " << filename << " compiles. It will be emptied now.\n\n";

		lnux_file.close();

		compile( filename );

		clear( filename );
	}
	else
		cout << "Aborted creating empty file " << filename << ".\n\n";
}





void delete_file (string filename)
{
	cout << "Are you sure you want to delete file: " << filename << "? ( y/n ): ";
	char answer;
	cin >> answer;

	if ( answer == 'y' )
	{
		string command = "rm -R " + filename;

		execute_command( command );
	}
	else
		cout << "Aborted deleting file " << filename << ".\n";
}

void delete_file (string filenames[])
{
	cout << "Are you sure you want to delete files: "; 

	int size = length_linuxfile( filenames );
	for ( int i=0; i<size; i=i+1 )
	{
		cout << filenames[i];
		if ( i != size - 1 )
			cout << " ";
	}

	cout << "? ( y/n ): ";


	char answer;
	cin >> answer;

	if ( answer == 'y' )
		for ( int i = 0; i < length_linuxfile( filenames ); i = i + 1 )
			execute_command( "rm -R " + filenames[ i ] );
	else
		cout << "Aborted deleting files: "; 

	for ( int i=0; i<size; i=i+1 )
	{
		cout << filenames[i];
		if ( i != size - 1 )
			cout << " ";
	}

	cout << ".\n";
}


void copy_file_linuxfile( string name )
{
	string command = "cp -R " + name + ".sh " + name + " (copy)" + ".sh";

	execute_command( command );
}


void copy_file_linuxfile( string names[] )
{
	int size = length_linuxfile(names);

	for (int i=0; i<size; i=i+1)
	{
		string command = "cp -R " + names[i] + ".sh " + names[i] + " (copy)" + ".sh";

		execute_command( command );
	}
}


