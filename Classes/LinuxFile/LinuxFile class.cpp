#include <string.h>
#include <fstream>
#include <iostream>

using namespace std;

ofstream file;

class LinuxFile // in progress
{

	string name;
	string filename;
	string file;

	string name_to_filename(string name)
	{
		string filename = name + ".sh";
		return filename;
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
	
	LinuxFile()
	{
		this->name = "";
		this->filename = "";
		this->file = "";
	}

	LinuxFile(string name) // check for existing files
	{
		this->name = name;
		this->filename = name_to_filename( name );
		this->file = "";
	}

	LinuxFile(string name, string file) // check for existing files
	{
		this->name = name;
		this->filename = name_to_filename( name );
		this->file = file;
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
		file.open( this->filename );

		this->file = "";

		string entry;
		while ( getline( file, entry ) )
			this->file = this->file + entry + "\n";

		file.close();
	}

	void clear ()
	{
		ofstream file;

		file.open( this->filename );
		file.close();

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

			file.open( this->filename );

			file << "echo File " << this->filename << " compiles. It will be emptied now.";

			file.close();

			execute_command( command_compile() );

			clear();
		}
		else
			cout << "Aborted checking file " << filename << ".\n\n";
	}


	void make_empty_linux_file ()
	{
		ofstream file;

		cout << "\nmake_empty_linux_file does not check for existing files of the same name.\nIf they exist, they will be deleted and replaced with an empty file.\nCheck for possibly existing file:  " << this->name << ".sh  in this folder.\nDo you want to continue? ( y/n ): ";
		char answer;
		cin >> answer;

		if (answer == 'y')
		{
			file.open( this->filename );

			make_executable();

			file << "echo Newly made file " << this->filename << " compiles. It will be emptied now.\n\n";

			file.close();

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

		file.open( this->filename );

		file << "\n" << data;

		file.close();

		this->saveFile();
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

	file.open( filename );
	file.close();
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

int length ( string a[] )
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
	int size = length(filenames);

	for ( int i=0; i<size; i=i+1 )
	{
		make_executable( filenames[i] );

		compile( filenames[i] );
	}
}

void compile ( LinuxFile linuxFiles[] )
{
	string filenames[100];

	int i=0;

	while ( linuxFiles[i].getFilename() != "" )
	{
		linuxFiles[i].compile();
		i=i+1;
	}

}

void enter ( string filename, string data )
{
	ofstream file;

	file.open( filename );

	file << "\n" << data;

	file.close();
}

void make_empty_linux_file ( string filenames[] )
{
	int size = length(filenames);

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

			file.open( filenames[i] );
			file.close();

			make_executable( filenames[i] );
		}
	else
		cout << "Abort making files.\n\n";
}

void make_empty_linux_file ( LinuxFile linuxFiles[] )
{
	string filenames[100];

	cout << "\n\nMake sure you do not have any of these files already in this folder:\n";

	int i=0;

	while ( linuxFiles[i].getFilename() != "" )
	{
		filenames[i] = linuxFiles[i].getFilename();
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

			file.open( linuxFiles[i].getFilename() );
			file.close();

			make_executable( linuxFiles[i].getFilename() );
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

		file.open( filename );

		file << "echo File " << filename << " compiles. It will be emptied now.";

		file.close();

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

	cout << "\nmake_empty_linux_file does not check for existing files of the same name.\nIf they exist, they will be deleted and replaced with an empty file.\nCheck for possibly existing file:  " << name << ".sh  in this folder.\nDo you want to continue? ( y/n ): ";
	char answer;
	cin >> answer;

	if (answer == 'y')
	{
		string filename = name + ".sh";

		file.open( filename );

		make_executable( filename );

		file << "echo Newly made file " << filename << " compiles. It will be emptied now.\n\n";

		file.close();

		compile( filename );

		clear( filename );
	}
	else
		cout << "Aborted creating empty file " << filename << ".\n\n";
}



int main () 
{
	// make copy, mrge, (folder), flnme endng, rnme, dlte files

	make_empty_linux_file ( "file2" );
	empty_and_check ( "file1.sh" );
	compile ( "file.sh" );

	string filenames[3] = { "1.sh", "2.sh" };

	make_empty_linux_file( filenames );

	enter( "1.sh", "echo File 1.sh compiled." );
	enter( "2.sh", "echo File 2.sh compiled." );

	compile ( filenames );

	cout << endl << endl;




	LinuxFile linux_file;
	// vazut cum se face initializare cu name

	linux_file.setName( "linux_file" );

	linux_file.make_empty_linux_file();

	



	LinuxFile linux_file1, linux_file2;

	linux_file1.setName( "linux_file1" );
	linux_file2.setName( "linux_file2" );

	linux_file1.enter( "echo linux_file1\ncompiles." );
	linux_file2.enter( "echo linux_file2\ncompiles." );

	cout << linux_file1.getFile() << endl;
	cout << linux_file2.getFile() << endl;

	linux_file1.enter( "echo linux_file1 compiles" );
	linux_file2.enter( "echo linux_file2 compiles" );

	LinuxFile linuxFiles[3] = { linux_file1, linux_file2 };

	compile( linuxFiles );



	make_empty_linux_file( linuxFiles );

	

	return 0;	
}
