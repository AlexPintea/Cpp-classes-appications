#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// length of a string[]
int length( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
		i=i+1;

	return i;
}

void replace_spaces( string &a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			a[i] = '_';
}

// is in string[]
bool is_in_strings ( string words[], string word )
{
	int size = length( words );

	for ( int i=0; i<size; i=i+1 )
		if ( word == words[i] )
			return true;

	return false;
}

// to continue
void continues ()
{
	char chars;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> chars;
	cout << "\n";

//	string empty; // to continue
//	getline( cin, empty ); // only if the case
}






// Classes






struct Class 
{
	string name;
	bool inherits = false;
	string inheritance = "";
	int num_inheritors = 0;
	string inheritors[1000];
} classes[1000];

int classes_iter = 0;

void make_classes_file ()
{
	ofstream fo;
	fo.open( "classes" );
	fo.close();

	fo.open( "classes" );
	fo << 0;
	fo.close();
}

void get_classes()
{
	classes_iter = -10;

	ifstream fi;
	fi.open( "classes" );

	fi >> classes_iter;

	if ( classes_iter == -10 )
	{
		classes_iter = 0;
		make_classes_file();
	}

	for ( int i=0; i<classes_iter; i=i+1 )
	{
		fi >> classes[i].name;

		fi >> classes[i].inherits;
		if ( classes[i].inherits )
			fi >> classes[i].inheritance;


		fi >> classes[i].num_inheritors;

		for ( int l=0; l<classes[i].num_inheritors; l=l+1 )
			fi >> classes[i].inheritors[l];
	}

	fi.close();
}


void set_classes()
{
	ofstream fo;
	fo.open( "classes" );

	fo << classes_iter << "\n";

	for ( int i=0; i<classes_iter; i=i+1 )
	{
		fo << classes[i].name << "    ";

		fo << classes[i].inherits;
		if ( classes[i].inherits )
			fo << "  " << classes[i].inheritance << "     ";
		else
			fo << "    ";

		fo << classes[i].num_inheritors << "  ";

		for ( int l=0; l<classes[i].num_inheritors; l=l+1 )
			fo << classes[i].inheritors[l] << " ";

		fo << "\n";
	}

	fo.close();

	get_classes();
}


bool is_class_added ( string a )
{
	for ( int i=0; i<classes_iter; i=i+1 )
		if ( a == classes[i].name )
			return true;

	return false;
}

void add_class( Class a )
{

	if ( is_class_added(a.name) )
	{
		cout << "Class name \"" << a.name << "\" already added.\n";
		return;
	}


	ofstream fo;
	fo.open( "classes" );

	fo << classes_iter + 1 << "\n";

	for ( int i=0; i<classes_iter; i=i+1 )
	{
		fo << classes[i].name << "    ";

		fo << classes[i].inherits;
		if ( classes[i].inherits )
			fo << "  " << classes[i].inheritance << "     ";
		else
			fo << "    ";

		fo << classes[i].num_inheritors << "  ";

		for ( int l=0; l<classes[i].num_inheritors; l=l+1 )
			fo << classes[i].inheritors[l] << " ";

		fo << "\n";
	}

	fo << a.name << "    ";

	fo << a.inherits << "    ";
	if ( a.inherits )
		fo << a.inheritance << "    ";


	fo << a.num_inheritors << "   ";

	for ( int l=0; l<a.num_inheritors; l=l+1 )
		fo << a.inheritors[l] << " ";


	fo.close();

	get_classes();

	cout << "Class \"" << a.name << "\" added.\n";
}

void remove_class( int iter )
{
	if ( iter < 0 or iter >= classes_iter )
	{
		cout << "Class num. invalid.\n";
		continues();
		return;
	}

	ofstream fo;
	fo.open( "classes" );

	fo << classes_iter - 1 << "\n";

	for ( int i=0; i<classes_iter; i=i+1 )
	{
		if ( iter == i )
			continue;

		fo << classes[i].name << "    ";

		if ( classes[i].inherits and classes[i].inheritance == classes[iter].name )
			fo << 0 << "    ";
		else
		{
			fo << classes[i].inherits << "    ";
			if ( classes[i].inherits )
				fo << classes[i].inheritance << "    ";
		}

		for ( int l=0; l<classes[i].num_inheritors; l=l+1 )
			if ( classes[iter].name == classes[i].inheritors[l] )	
				classes[i].num_inheritors = classes[i].num_inheritors - 1;

		fo << classes[i].num_inheritors << "   ";

		for ( int l=0; l<classes[i].num_inheritors; l=l+1 )
			if ( classes[iter].name != classes[i].inheritors[l] )
				fo << classes[i].inheritors[l] << " ";

		fo << "\n";
	}

	fo.close();

	get_classes();

	cout << "Class removed.\n";
	continues();
}

void show_classes()
{
	cout << "\nClasses\n";

	for ( int i=0; i<classes_iter; i=i+1 )
	{
		cout << i + 1 << ") " << classes[i].name;

		if ( !classes[i].inherits and classes[i].num_inheritors == 0 )
		{
			cout << "\n";
			continue;
		}

		cout << ":   ";
		if ( classes[i].inherits )
			cout << "  Inherits = " << classes[i].inheritance << "   ";

		if ( classes[i].num_inheritors == 0 )
		{
			cout << "\n";
			continue;
		}

		cout << "  Inheritors = ";
		for ( int l=0; l<classes[i].num_inheritors; l=l+1 )
		{
			cout << classes[i].inheritors[l];
			if ( l != classes[i].num_inheritors - 1 )
				cout << ", ";
		}
		cout << "\n";
	}

	cout << "\n";
}






// Inheritance / Inheritors






void add_inheritance( int iter, string inheritance_string )
{
	if ( classes[ iter ].inherits == true )
	{
		string choice_replace;
		cout << "Class \"" << classes[iter].name << "\" inherits \'" << classes[iter].inheritance << "\'. Replace ( y / n ): " ;
		getline( cin, choice_replace );

		if ( choice_replace != "y" )
		{
			cout << "Aborted.\n";
			continues();
			return;
		}
	}

	classes[ iter ].inherits = true;
	classes[ iter ].inheritance = inheritance_string;

	set_classes();

	cout << "Inheritance added.\n";
	continues();
}

void add_inheritor( int iter, string inheritor_string )
{
	if ( iter < 0 or iter >= classes_iter )
	{
		cout << "Class num. invalid.\n";
		continues();
		return;
	}

	classes[ iter ].inheritors[ classes[ iter ].num_inheritors ] = inheritor_string;
	classes[ iter ].num_inheritors = classes[ iter ].num_inheritors + 1;

	set_classes();

	cout << "Inheritor added.\n";
	continues();
}


void remove_string ( string words[], string word )
{
	int size = length( words );

	string result[1000];
	int size_result = 0;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( words[i] != word )
		{
			result[ size_result ] = words[i];
			size_result = size_result + 1;
		}
	}
	result[ size_result ] = "";

	for ( int i=0; i<size; i=i+1 )
		words[i] = "";

	for ( int i=0; i<size_result; i=i+1 )
		words[i] = result[i];
}

void remove_inheritance ( int iter )
{

	if ( classes[ iter ].inherits == false )
	{
		cout << "Class does not inherit. Removal not necessary.\n";
		continues();
		return;
	}

	classes[ iter ].inherits = false;
	classes[ iter ].inheritance = "";

	set_classes();

	cout << "Inheritance removed.\n";
	continues();
}

void remove_inheritor ( int iter, string inheritor_name )
{
	bool is_inheritor_name = false;
	for ( int i=0; i<classes[ iter ].num_inheritors; i=i+1 )
		if ( classes[ iter ].inheritors[i] == inheritor_name )
			is_inheritor_name = true;

	if ( is_inheritor_name == false )
	{
		cout << "Inheritor not available for removal.\n";
		continues();
		return;		
	}

	remove_string( classes[ iter ].inheritors, inheritor_name );

	classes[ iter ].num_inheritors = classes[ iter ].num_inheritors - 1;

	set_classes();

	cout << "Inheritor removed.\n";
	continues();
}






// Scan class





bool is_word ( string words[], string word )
{
	for ( int i=0; i<length( words ); i=i+1 )
		if ( words[i] == word )
			return true;

	return false;
}

int word_pos ( string words[], string word )
{
	for ( int i=0; i<length( words ); i=i+1 )
		if ( words[i] == word )
			return i;

	return -1;
}


// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	int size_empty = length(words);
	for ( int i=0; i<size_empty; i=i+1 )
		words[i] = "";

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

bool is_char ( string a, char b )
{
	for ( int i=0; i<a.length(); i=i+1 )
		if ( a[i] == b )
			return true;

	return false;
}

void scan_class ( string filename )
{
	bool is_class_name = false;


	string name[1000];
	string inheritance[1000];
	int name_iter = 0;


	ifstream fi;

	// makes file with '_' instead of ' '
	if ( is_char( filename, ' ' ) )
	{
		fi.open( filename );

		string temp;
		string file = "";
		while ( getline( fi, temp ) )
			file = file + temp + "\n";

		fi.close();

		replace_spaces( filename );

		// makes the file
		ofstream fo;
		fo.open( filename );
		fo.close();

		fo.open( filename );
		fo << file;
		fo.close();
	}

	fi.open( filename );

	string temp;
	string temps[1000];
	while ( getline( fi, temp ) )
	{
		move_words( temp, temps );

		if ( is_word( temps, "class" ) )
		{
			name[ name_iter ] = temps[ word_pos( temps, "class" ) + 1 ];

			if ( is_word( temps, "public" ) )
				inheritance[ name_iter ] = temps[ word_pos( temps, "public" ) + 1 ];
			else
				inheritance[ name_iter ] = "";

			name_iter = name_iter + 1;
		}
	}

	fi.close();

	if ( name_iter == 0 )
	{
		cout << "File does not have valid classes / Filename not valid.\n";
		continues();
		return;
	}

	for ( int i=0; i<name_iter; i=i+1 )
	{
		Class a;
		a.name = name[i];
		a.inherits = false;
		if ( inheritance[i] != "" )
		{
			a.inherits = true;
			a.inheritance = inheritance[i];
		}

		add_class(a);
	}
}









string valid_choices[1000] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "exit" };
string choices[1000]= { "Add Class", "Add Inheritance", "Add Inheritor", "Remove Class", "Remove Inheritance", "Remove Inheritor", "Show Classes" };


string choice = "";


// makes columns with your choices
void spaces ( int iter )
{
	int size = length( choices );

	int max_length = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( i % 3 == iter % 3 )
		{
			string temp = valid_choices[i] + ". " + choices[i];

			if ( temp.length() > max_length )
				max_length = temp.length();
		}

	max_length = max_length + 2;

	string entry = valid_choices[iter] + ". " + choices[iter];
	int entry_size = entry.length();

	for ( int i=entry_size; i<max_length; i=i+1 )
		cout << " ";
}


// gets choice
void get_choice ()
{
	cout << "Choices:";

	for ( int i=0; i<length( choices ); i=i+1 )
	{
		if ( i % 3 == 0 )
			cout << "\n    ";
		cout << valid_choices[i] << ". " << choices[i];
		spaces( i );
	}

	cout << "\n\n  exit. Exits\n\n";

	cout << "Your choice: ";
	getline( cin, choice );
//	if ( i == 0 ) // only if the case
//		getline( cin, choice );

	if ( choice == "" )
	{
		cout << "printf \033c";
		return;
	}

	if ( !is_in_strings( valid_choices, choice ) )
	{
		cout << "Invalid choice. Retry.\n\n";
		choice = "";
		continues();
		cout << "printf \033c";
		return;
	}



	if ( choice == "1" )
	{

		string choice_get;
		cout << "\n1. Enter class name and inheritance.\n";
		cout << "2. Scan a file.\n";

		cout << "Your choice: ";
		getline( cin, choice_get );

		if ( choice_get == "2" )
		{
			string filename;
			cout << "Filename in this folder ( spaces are to be removed ): ";
			getline( cin, filename );

			scan_class ( filename );

			continues();
			cout << "printf \033c";
			return;
		}

		if ( choice_get != "1" )
		{
			cout << "Invalid choice. Retry.\n";	
			continues();

			cout << "printf \033c";
			return;
		}

		Class a;

		cout << "Class name: ";
		getline( cin, a.name );
		replace_spaces( a.name );



		if ( is_class_added(a.name) )
		{
			cout << "Class name already added.\n";
			continues();

			cout << "printf \033c";
			return;
		}



		cout << "Class inherits ( y / n ): ";

		string choice_inherits;
		getline( cin, choice_inherits );
		if ( choice_inherits == "y" )
			a.inherits = true;
		if ( a.inherits )
		{
			cout << "Class it inherits: ";
			getline( cin, a.inheritance );
			replace_spaces( a.inheritance );
		}

		string choice_inheritors;
		cout << "Class has inheritors ( y / n ): ";
		getline( cin, choice_inheritors );
		if ( choice_inheritors != "y" )
		{
			add_class(a);
			cout << "Class \"" << a.name << "\" added.\n";
			continues();

			cout << "printf \033c";
			return;
		}

		cout << "Class inheritors num.: ";
		cin >> a.num_inheritors;

		for ( int l=0; l<a.num_inheritors; l=l+1 )
		{
			cout << "Inheritor " << l + 1 << " name: ";
			getline( cin, a.inheritors[l] );
			if ( a.inheritors[l] == "" )
				getline( cin, a.inheritors[l] );

			replace_spaces( a.inheritors[l] );
		}

		add_class(a);
		continues();
	}

	if ( choice == "2" )
	{
		show_classes();

		int iter;
		cout << "Num. of class to add inheritance to: ";
		cin >> iter;

		iter = iter - 1;

		if ( iter < 0 or iter >= classes_iter )
		{
			cout << "Class num. invalid. Retry.\n";
			continues();
			return;
		}

		string name_inheritance;
		cout << "Name of inheritance: ";
		getline( cin, name_inheritance );
		if ( name_inheritance == "" )
			getline( cin, name_inheritance );

		replace_spaces( name_inheritance );

		add_inheritance( iter, name_inheritance );
	}

	if ( choice == "3" )
	{
		show_classes();

		int iter;
		cout << "Num. of class to add inheritor to: ";
		cin >> iter;

		iter = iter - 1;

		if ( iter < 0 or iter >= classes_iter )
		{
			cout << "Class num. invalid. Retry.\n";
			continues();
			return;
		}

		string name_inheritor = "";
		cout << "Name of inheritor: ";
		getline( cin, name_inheritor );
		if ( name_inheritor == "" )
			getline( cin, name_inheritor );
		replace_spaces( name_inheritor );

		add_inheritor( iter, name_inheritor );
	}

	if ( choice == "4" )
	{
		show_classes();

		int iter;
		cout << "Num. of class to remove: ";
		cin >> iter;

		iter = iter - 1;

		if ( iter < 0 or iter >= classes_iter )
		{
			cout << "Class num. invalid. Retry.\n";
			continues();
			return;
		}

		remove_class ( iter );
	}


	if ( choice == "5" )
	{
		show_classes();

		int iter;
		cout << "Num. of class to remove inheritance of: ";
		cin >> iter;

		iter = iter - 1;

		if ( iter < 0 or iter >= classes_iter )
		{
			cout << "Class num. invalid. Retry.\n";
			continues();
			return;
		}

		remove_inheritance ( iter );
	}

	if ( choice == "6" )
	{
		show_classes();

		int iter;
		cout << "Num. of class to remove inheritor of: ";
		cin >> iter;

		iter = iter - 1;

		if ( iter < 0 or iter >= classes_iter )
		{
			cout << "Class num. invalid. Retry.\n";
			continues();
			return;
		}

		string name_inheritor = "";
		cout << "Name of inheritor to remove: ";
		getline( cin, name_inheritor );
		if ( name_inheritor == "" )
			getline( cin, name_inheritor );
		replace_spaces( name_inheritor );

		remove_inheritor ( iter, name_inheritor );
	}



	if ( choice == "7" )
	{
		show_classes();
		continues();
	}


	if ( choice == "exit" )
		return;

	cout << "printf \033c";
}

int main ()
{
	get_classes();

	while ( choice != "exit" )
		get_choice();

	cout << "\nExited.\n";
	return 0;
}
