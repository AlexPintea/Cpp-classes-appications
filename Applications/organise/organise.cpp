#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

int length ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
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

// remove chars
void remove_chars ( string &a )
{
	int size = a.length();

	// replace chars with ' '
	for ( int i=0; i<size; i=i+1 )
	{
		if ( !( a[i] >= 'a' and a[i] <= 'z' ) and !( a[i] >= 'A' and a[i] <= 'Z' ) )
			a[i] = ' ';
		if ( a[i] >= 'A' and a[i] <= 'Z' )
			a[i] = a[i] + 32;
	}


	string result = "";

	// reduce ' '-s
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ')
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";


	// delete last ' '
	if ( result[ result.length() - 1 ] == ' ' )
		remove_char( result, result.length() - 1 );

	// delete initial ' '
	if ( result[ 0 ] == ' ' )
		remove_char( result, 0 );

	a = result;
}

// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
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

// clears a file
void clear_file ( string filename )
{
	ofstream f; // have to have ofstream
	f.open( filename );
	f.close();
}

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

void enter ()
{
	char enter;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> enter;
	cout << "\n";
}








// store ctgs entries
fstream ctg_file;

struct ctg 
{
	string name;
	int count;
	string items[1000];
} ctgs[1000], ctg_default;

int ctgs_iter = 0;

// make ctgs file
void make_ctgs_file ()
{
	ofstream f;
	f.open( "ctgs" );
	f << "0\nfiles 0";
	f.close();

	cout << "( info ) Ctgs file reset.\n\n";

	enter();

	string empty; // to continue
	getline( cin, empty );
}

// gets items of "ctgs" file
void get_ctgs ()
{
	ctg_file.open( "ctgs" );

	ctg_file >> ctgs_iter;

	// default ctg
	ctg_file >> ctg_default.name;
	ctg_file >> ctg_default.count;
	for ( int l=0; l<ctg_default.count; l=l+1 )
		ctg_file >> ctg_default.items[l];

	for ( int i=0; i<ctgs_iter; i=i+1 )
	{
		ctg_file >> ctgs[i].name;
		ctg_file >> ctgs[i].count;
		for ( int l=0; l<ctgs[i].count; l=l+1 )
			ctg_file >> ctgs[i].items[l];
	}

	ctg_file.close();
}

// sets items of "ctgs" file
void set_ctgs ()
{
	clear_file( "ctgs" );

	ctg_file.open( "ctgs" );

	ctg_file << ctgs_iter << "\n";

	// default ctg
	ctg_file << ctg_default.name << " ";
	ctg_file << ctg_default.count<< "    ";
	for ( int l=0; l<ctg_default.count; l=l+1 )
		ctg_file << ctg_default.items[l] << " ";
	ctg_file << "\n";

	for ( int i=0; i<ctgs_iter; i=i+1 )
	{
		ctg_file << ctgs[i].name << " ";
		ctg_file << ctgs[i].count<< "    ";
		for ( int l=0; l<ctgs[i].count; l=l+1 )
			ctg_file << ctgs[i].items[l] << " ";
		ctg_file << "\n";
	}


	ctg_file.close();
}

// add ctg to "ctgs" file
void add_ctg ( ctg a )
{
	for ( int i=0; i<ctgs_iter; i=i+1 )
		if ( ctgs[i].name == a.name )
		{
			cout << "[ added ] Ctg name was already added.\n";
			return;
		}


	// clears file "ctgs"
	clear_file ( "ctgs" );

	ctg_file.open( "ctgs" );

	ctg_file << ctgs_iter + 1 << "\n";

	// default ctg
	ctg_file << ctg_default.name << " ";
	cout << "\n\'" << ctg_default.name << "\' \n";
	ctg_file << ctg_default.count<< "    ";
	for ( int l=0; l<ctg_default.count; l=l+1 )
		ctg_file << ctg_default.items[l] << " ";
	ctg_file << "\n";

	for ( int i=0; i<ctgs_iter; i=i+1 )
	{
		ctg_file << ctgs[i].name << " ";
		ctg_file << ctgs[i].count<< "    ";
		for ( int l=0; l<ctgs[i].count; l=l+1 )
			ctg_file << ctgs[i].items[l] << " ";
		ctg_file << "\n";
	}

	// add a
	ctg_file << a.name << " ";
	ctg_file << a.count<< "    ";
	for ( int l=0; l<a.count; l=l+1 )
		ctg_file << a.items[l] << " ";	

	ctg_file.close();

	get_ctgs();

	cout << "Ctg \'" << a.name << "\' was added.\n";
}

// remove ctg of "ctgs" file
void remove_ctg ( int iter )
{
	// clear file "ctgs"
	clear_file( "ctgs" );

	ctg_file.open( "ctgs" );

	ctg_file << ctgs_iter - 1 << "\n";

	// default ctg
	ctg_file << ctg_default.name << " ";
	ctg_file << ctg_default.count<< "    ";
	for ( int l=0; l<ctg_default.count; l=l+1 )
		ctg_file << ctg_default.items[l] << " ";
	ctg_file << "\n";

	for ( int i=0; i<ctgs_iter; i=i+1 )
	{
		if ( i != iter )
		{
			ctg_file << ctgs[i].name << " ";
			ctg_file << ctgs[i].count<< "    ";
			for ( int l=0; l<ctgs[i].count; l=l+1 )
				ctg_file << ctgs[i].items[l] << " ";
			ctg_file << "\n";
		}
	}

	ctg_file.close();

	get_ctgs();
}

// add item to a ctg
void add_item( string filename, int iter )
{
	for ( int i=0; i<ctgs[iter].count; i=i+1 )
		if ( ctgs[iter].items[i] == filename )
		{
			cout << "[ added ] Filenmae was already added.\n";
			return;
		}

	int size = length( ctgs[iter].items );

	ctgs[iter].items[ size ] = filename;
	ctgs[iter].count = size + 1;

	clear_file( "ctgs" );
	set_ctgs();

	cout << "File \'" << filename << "\' was added to ctg: \'" << ctgs[ iter ].name << "\'.\n\n";
}

// add item to default ctg
void add_default_item( string filename )
{
	int size = length( ctg_default.items );

	ctg_default.items[ size ] = filename;
	ctg_default.count = size + 1;

	clear_file( "ctgs" );
	set_ctgs();
}

// remove filename of ctg
void remove_item ( string filename, int iter )
{
	int size = length( ctgs[iter].items );

	ctgs[iter].count = size - 1;

	string temp[1000];

	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( ctgs[iter].items[i] != filename )
		{
			temp[ counter ] = ctgs[iter].items[i];
			counter = counter + 1;
		}

	// empty ctgs[iter]
	for ( int i=0; i<size; i=i+1 )
		ctgs[iter].items[i] = "";

	// remake ctgs[iter]
	for ( int i=0; i<size - 1; i=i+1 )
		ctgs[iter].items[i] = temp[i];

	clear_file( "ctgs" );
	set_ctgs();

}

// remove filename of default ctg
void remove_default_item ( string filename )
{
	int size = length( ctg_default.items );

	ctg_default.count = size - 1;

	string temp[1000];

	int counter = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( ctg_default.items[i] != filename )
		{
			temp[ counter ] = ctg_default.items[i];
			counter = counter + 1;
		}

	// empty ctg_default
	for ( int i=0; i<size; i=i+1 )
		ctg_default.items[i] = "";

	// remake ctg_default
	for ( int i=0; i<size - 1; i=i+1 )
		ctg_default.items[i] = temp[i];

	clear_file( "ctgs" );
	set_ctgs();

}


// show ctg
void show_ctg ( int iter )
{
	cout << ctgs[iter].name << ": ";
	for ( int i=0; i<ctgs[iter].count; i=i+1 )
		cout << "\'" << ctgs[iter].items[i] << "\' ";
	cout << "\n";
}

// show default ctg
void show_default_ctg ()
{
	cout << ctg_default.name << ": ";
	for ( int i=0; i<ctg_default.count; i=i+1 )
		cout << "\'" << ctg_default.items[i] << "\' ";
	cout << "\n";
}

// show ctgs, filenames
void show_ctgs ()
{
	cout << "Ctgs:\n";
	for ( int i=0; i<ctgs_iter; i=i+1 )
	{
		cout << i + 1 << ". ";
		show_ctg ( i );
	}
	show_default_ctg();
	cout << "\n";
}



// Choices




string choice;

void show_choices ()
{
	cout << "\nChoices:  1. Make a file   2. Ctg a file   3. !Ctg a file    4. Edit a file   5. Rename file\n";
	cout <<"          6. Add ctg       7. Show ctgs    8. Remove ctg     9. Rename ctg\n";
	cout << "          delete. Delete file                 exit. Exit\n\n";

	cout << "Your choice: ";
	getline( cin, choice );
	cout << "\n";

	if ( choice != "1" and choice != "2" and choice != "3" and choice != "4" and choice != "5" and choice != "6" and choice != "7" and choice != "8" and choice != "9" and choice != "delete" and choice != "exit" )
	{
		cout << "\n( info ) Invalid choice. Retry.\n";
		return;
	}

	// Make a file
	if ( choice == "1" )
	{

		show_ctgs();

		cout << "Enter filename: ";
		string filename;
		getline( cin, filename );
//		remove_chars( filename );
		string temp[1000];
		move_words( filename, temp );
		filename = temp[0];

		if ( filename == "" )
		{
			cout << "\n( info ) Invalid filename. Aborted.\n";
			return;
		}


		bool have_file = false;
		for ( int l=0; l<ctg_default.count; l=l+1 )
			if ( filename == ctg_default.items[l] )
			{
				have_file = true;
				break;
			}

		if ( have_file == true )
		{
			cout << "( info ) Filename not available. Aborted.\n";
			return;
		}


		if ( filename == "" )
		{
			cout << "Filename was empty. Retry.\n\n";
			enter();

			string empty; // to continue
			getline( cin, empty );

			return;
		}

		add_default_item( filename );

		string command = "gedit " + filename;

		cout << "\n( info ) Editing is done within an editor. Save and close when done.\n";
		cout << "( info ) If you want to rename / delete the file, use this software.\n\n";

		enter();

		command_linux( command );

		ofstream f;
		f.open( filename );
		f.close();

		string empty; // to continue
		getline( cin, empty );
	}

	// Ctg a file
	if ( choice == "2" )
	{
		show_ctgs();

		cout << "Enter filename: ";
		string filename;
		getline( cin, filename );

		bool have_file = false;
		for ( int l=0; l<ctg_default.count; l=l+1 )
			if ( filename == ctg_default.items[l] )
			{
				have_file = true;
				break;
			}

		if ( have_file == false )
		{
			cout << "( info ) Filename is not valid. Aborted.\n";
			return;
		}

		cout << "Enter ctg num. to get into: ";
		int ctg_iter;
		cin >> ctg_iter;
		cout << "\n";

		if ( !( ctg_iter >= 1 and ctg_iter <= ctgs_iter ) )
		{
			cout << "\n( info ) Invalid file num. Aborted.\n";
			return;
		}

		ctg_iter = ctg_iter - 1;

		add_item( filename, ctg_iter );

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

	// !Ctg a file
	if ( choice == "3" )
	{
		show_ctgs();

		cout << "Enter filename: ";
		string filename;
		getline( cin, filename );

		bool have_file = false;
		for ( int i=0; i<ctgs_iter; i=i+1 )
			for ( int l=0; l<ctgs[i].count; l=l+1 )
				if ( filename == ctgs[i].items[l] )
				{
					have_file = true;
					break;
				}

		if ( have_file == false )
		{
			cout << "( info ) Filename is not valid. Aborted.\n";
			return;
		}

		cout << "Enter ctg num. to remove out of: ";
		int ctg_iter;
		cin >> ctg_iter;
		cout << "\n";

		if ( !( ctg_iter >= 1 and ctg_iter <= ctgs_iter ) )
		{
			cout << "\n( info ) Invalid file num. Aborted.\n";
			return;
		}

		ctg_iter = ctg_iter - 1;

		have_file = false;
		for ( int i=0; i<ctgs[ ctg_iter ].count; i=i+1 )
			if ( filename == ctgs[ ctg_iter ].items[i] )
			{
				have_file = true;
				break;
			}

		if ( have_file == false )
		{
			cout << "( info ) Filename is not valid within this ctg. Aborted.\n";

			string empty; // to continue
			getline( cin, empty );

			return;
		}

		remove_item( filename, ctg_iter );
		cout << "File \'" << filename << "\' was removed of ctg: \'" << ctgs[ ctg_iter ].name << "\'.\n\n";

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

	// Edit a file
	if ( choice == "4" )
	{
		show_ctgs();

		cout << "Enter filename: ";
		string filename;
		getline( cin, filename );

		bool have_file = false;
		for ( int l=0; l<ctg_default.count; l=l+1 )
			if ( filename == ctg_default.items[l] )
			{
				have_file = true;
				break;
			}

		if ( have_file == false )
		{
			cout << "( info ) Filename is not valid. Aborted.\n";
			return;
		}

		string command = "gedit " + filename;

		cout << "\n( info ) Editing is done within an editor. Save and close when done.\n";
		cout << "( info ) If you want to rename / delete the file, use this software.\n\n";

		enter();

		command_linux( command );

		cout << "Continue when done editing.\n\n";

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

	// Rename a file
	if ( choice == "5" )
	{
		show_ctgs();

		cout << "Enter filename: ";
		string filename;
		getline( cin, filename );

		bool have_file = false;
		for ( int l=0; l<ctg_default.count; l=l+1 )
			if ( filename == ctg_default.items[l] )
			{
				have_file = true;
				break;
			}

		if ( have_file == false )
		{
			cout << "( info ) Filename is not valid. Aborted.\n";
			return;
		}

		cout << "Enter filename to modify to: ";
		string last_filename;
		getline( cin, last_filename );
//		remove_chars( last_filename );
		string temp[1000];
		move_words( last_filename, temp );
		last_filename = temp[0];

		if ( last_filename == "" )
		{
			cout << "\n( info ) Invalid filename. Aborted.\n";
			return;
		}

		// for default ctg
		for ( int l=0; l<ctg_default.count; l=l+1 )
			if ( filename == ctg_default.items[l] )
				ctg_default.items[l] = last_filename;

		// for ctgs
		for ( int i=0; i<ctgs_iter; i=i+1 )
			for ( int l=0; l<ctgs[i].count; l=l+1 )
				if ( filename == ctgs[i].items[l] )
					ctgs[i].items[l] = last_filename;

		set_ctgs();


		// actuallly renaming the file
		string file = "";
		fstream f;
		f.open( filename );

		string temp_string;
		while ( getline ( f, temp_string ) )
			file = file + temp_string + "\n";

		f.close();

		string command = "rm -R " + filename;
		command_linux( command );

		ofstream f_ofstream;
		f_ofstream.open( last_filename );
		f_ofstream<< file;
		f_ofstream.close();

		cout << "File was renamed.\n\n";

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

	// Add ctg
	if ( choice == "6" )
	{

		show_ctgs();


		cout << "Enter ctg name: ";
		string ctg_name;
		getline( cin, ctg_name );
//		remove_chars( ctg_name );
		string temp[1000];
		move_words( ctg_name, temp );
		ctg_name = temp[0];

		if ( ctg_name == "" )
		{
			cout << "\n( info ) Invalid ctg name. Aborted.\n";
			return;
		}

		bool have_ctg = false;
		for ( int l=0; l<ctgs_iter; l=l+1 )
			if ( ctg_name == ctgs[l].name )
			{
				have_ctg = true;
				break;
			}

		if ( have_ctg == true )
		{
			cout << "( info ) Ctg name not vailable. Aborted.\n";
			return;
		}


		if ( ctg_name == "" )
		{
			cout << "Ctg name is not valid / was empty. Retry.\n\n";
			enter();

			string empty; // to continue
			getline( cin, empty );

			return;
		}

		ctg last;
		last.name = ctg_name;
		last.count = 0;

		add_ctg( last );

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

	// Show ctgs
	if ( choice == "7" )
	{
		show_ctgs();

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

	// Remove ctg
	if ( choice == "8" )
	{
		show_ctgs();

		cout << "Enter ctg num. you want to remove: ";
		int ctg_iter;
		cin >> ctg_iter;
		cout << "\n";

		if ( !( ctg_iter >= 1 and ctg_iter <= ctgs_iter ) )
		{
			cout << "\n( info ) Invalid file num. Aborted.\n";
			return;
		}

		remove_ctg( ctg_iter - 1 );

		cout << "Ctg was removed\n";

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

	// Rename ctg
	if ( choice == "9" )
	{
		show_ctgs();

		cout << "Enter ctg num. you want to rename: ";
		int ctg_iter;
		cin >> ctg_iter;
		cout << "\n";

		if ( !( ctg_iter >= 1 and ctg_iter <= ctgs_iter ) )
		{
			cout << "\n( info ) Invalid file num. Aborted.\n";
			return;
		}

		ctg_iter = ctg_iter - 1;

		cout << "Enter ctg name: ";
		string ctg_name;
		getline( cin, ctg_name );
		getline( cin, ctg_name );
//		remove_chars( ctg_name );
		string temp[1000];
		move_words( ctg_name, temp );
		ctg_name = temp[0];

		if ( ctg_name == "" )
		{
			cout << "\n( info ) Invalid ctg name. Aborted.\n";
			return;
		}

		ctgs[ ctg_iter ].name = ctg_name;

		set_ctgs();

		enter();

		string empty; // to continue
		getline( cin, empty );
	}


	// Delete a file
	if ( choice == "delete" )
	{
		show_ctgs();

		cout << "Enter filename: ";
		string filename;
		getline( cin, filename );

		bool have_file = false;
		for ( int l=0; l<ctg_default.count; l=l+1 )
			if ( filename == ctg_default.items[l] )
			{
				have_file = true;
				break;
			}

		if ( have_file == false )
		{
			cout << "( info ) Filename is not valid. Aborted.\n";
			return;
		}

		for ( int i=0; i<ctgs_iter; i=i+1 )
			for ( int l=0; l<ctgs[i].count; l=l+1 )
				if ( filename == ctgs[i].items[l] )
					remove_item( filename, i );

		remove_default_item( filename );

		string command = "rm -R " + filename;

		command_linux ( command );

		cout << "File \'" << filename << "\' deleted.\n\n";

		enter();

		string empty; // to continue
		getline( cin, empty );
	}

}








int main ()
{
	// get / make ctgs
	get_ctgs();
	if ( ctg_default.count == 0 and ctgs_iter == 0 )\
	{
		make_ctgs_file();
		get_ctgs();
	}
	while ( choice != "exit" )
		show_choices();

	cout << "Exited.\n\n";

	return 0;
}
