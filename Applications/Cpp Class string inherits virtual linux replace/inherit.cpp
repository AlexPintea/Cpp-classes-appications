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

void replace_spaces_virtual( string &a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			a[i] = '&';
}

string add_spaces_virtual ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == '&' )
			a[i] = ' ';

	return a;
}

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
	int num_virtuals = 0;
	string virtuals[1000];
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


		fi >> classes[i].num_virtuals;

		for ( int l=0; l<classes[i].num_virtuals; l=l+1 )
		{
			classes[i].virtuals[l] = "";

			char temp;
			while ( fi >> temp )
				if ( temp == '[' )
					break;

			while ( fi >> temp )
				if ( temp != '[' )
					break;

			classes[i].virtuals[l] = classes[i].virtuals[l] + temp;

			while ( fi >> temp )
			{
				if ( temp == ']' )
					break;

				classes[i].virtuals[l] = classes[i].virtuals[l] + temp;
			}
		}
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

		fo << classes[i].num_virtuals << "  ";

		for ( int l=0; l<classes[i].num_virtuals; l=l+1 )
		{
			if ( classes[i].virtuals[l][0] != '[' )
				fo << '[';
			fo << classes[i].virtuals[l];
			if ( classes[i].virtuals[l][ classes[i].virtuals[l].length() - 1 ] != ']' )
				fo << "] ";
		}

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

bool show_remove = true;

void remove_class( int iter );

void add_class( Class a )
{
	get_classes();

	if ( is_class_added(a.name) )
	{
		for ( int i=0; i<classes_iter; i=i+1 )
			if ( a.name == classes[i].name )
			{
				show_remove = false;
				remove_class(i);
				show_remove = true;
			}
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

		fo << classes[i].num_virtuals << "  ";

		for ( int l=0; l<classes[i].num_virtuals; l=l+1 )
		{
			if ( classes[i].virtuals[l][0] != '[' )
				fo << '[';
			fo << classes[i].virtuals[l];
			if ( classes[i].virtuals[l][ classes[i].virtuals[l].length() - 1 ] != ']' )
				fo << "] ";
		}

		fo << "\n";
	}

	fo << a.name << "    ";

	fo << a.inherits << "    ";
	if ( a.inherits )
		fo << a.inheritance << "    ";


	fo << a.num_inheritors << "   ";

	for ( int l=0; l<a.num_inheritors; l=l+1 )
		fo << a.inheritors[l] << " ";

	fo << a.num_virtuals << "   ";

	for ( int l=0; l<a.num_virtuals; l=l+1 )
	{
		replace_spaces_virtual( a.virtuals[l] );
		
		if ( a.virtuals[l][0] != '[' )
			fo << '[';
		fo << a.virtuals[l];
		if ( a.virtuals[l][ a.virtuals[l].length() - 1 ] != ']' )
			fo << "] ";
	}

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



		fo << classes[i].num_virtuals << "  ";

		for ( int l=0; l<classes[i].num_virtuals; l=l+1 )
		{
			if ( classes[i].virtuals[l][0] != '[' )
				fo << '[';
			fo << classes[i].virtuals[l];
			if ( classes[i].virtuals[l][ classes[i].virtuals[l].length() - 1 ] != ']' )
				fo << "] ";
		}

		fo << "\n";
	}

	fo.close();

	get_classes();

	if ( show_remove )
	{
		cout << "Class removed.\n";
		continues();
	}
}

void show_classes()
{
	cout << "\nClasses\n";

	for ( int i=0; i<classes_iter; i=i+1 )
	{
		cout << i + 1 << ") " << classes[i].name;

		if ( !classes[i].inherits and classes[i].num_inheritors == 0 and classes[i].num_virtuals == 0 )
		{
			cout << "\n";
			continue;
		}

		cout << ":   ";
		if ( classes[i].inherits )
			cout << "   Inherits = " << classes[i].inheritance << "   ";

		if ( classes[i].num_inheritors != 0 )
		{
			cout << " Inheritors = ";
			for ( int l=0; l<classes[i].num_inheritors; l=l+1 )
			{
				cout << classes[i].inheritors[l];
				if ( l != classes[i].num_inheritors - 1 )
					cout << ", ";
			}
		}

		if ( classes[i].num_virtuals != 0 )
		{
			cout << " Virtuals = ";
			for ( int l=0; l<classes[i].num_virtuals; l=l+1 )
			{
				cout << add_spaces_virtual( classes[i].virtuals[l] );
				if ( l != classes[i].num_virtuals - 1 )
					cout << ", ";
			}
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
	if ( is_word( classes[iter].inheritors, inheritor_string ) )
	{
		cout << "Inheritor already added.\n";
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

void remove_string_iter ( string words[], int iter )
{
	int size = length( words );

	string result[1000];
	int size_result = 0;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( i != iter )
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







// Virtual







void add_virtual( int iter, string virtual_string )
{
	if ( is_word( classes[iter].virtuals, virtual_string ) )
	{
		cout << "Virtual already added.\n";
		continues();
		return;
	}


	int is_virtual = 0;
	for ( int i=0; i<virtual_string.length(); i=i+1 )
		if ( virtual_string[i] == '(' or virtual_string[i] == ')'  )
			is_virtual = is_virtual + 1;

	if ( is_virtual < 2 )
	{
		cout << "Invalid. Retry.\n";
		continues();
		return;
	}

	classes[ iter ].virtuals[ classes[ iter ].num_virtuals ] = virtual_string;
	classes[ iter ].num_virtuals = classes[ iter ].num_virtuals + 1;

	set_classes();

	cout << "Virtual added.\n";
	continues();
}

void remove_virtual ( int iter, string virtual_name )
{
	bool is_virtual_name = false;
	for ( int i=0; i<classes[ iter ].num_virtuals; i=i+1 )
		if ( classes[ iter ].virtuals[i] == virtual_name )
			is_virtual_name = true;

	if ( is_virtual_name == false )
	{
		cout << "Virtual not available for removal.\n";
		continues();
		return;		
	}

	remove_string( classes[ iter ].virtuals, virtual_name );

	classes[ iter ].num_virtuals = classes[ iter ].num_virtuals - 1;

	set_classes();

	cout << "Virtual removed.\n";
	continues();
}





// Scan class





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
			if ( text[i] != '	')
				words[ words_iter ] = words[ words_iter ] + text[i];
}

bool is_char ( string a, char b )
{
	for ( int i=0; i<a.length(); i=i+1 )
		if ( a[i] == b )
			return true;

	return false;
}

void scan_class ( string &filename )
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


		fi.open ( filename );

		temp = "";

		a.num_virtuals = 0;

		while ( getline( fi, temp ) )
		{
			move_words( temp, temps );

			if ( is_word( temps, a.name ) )
			{
				while ( getline( fi, temp ) )
				{
					if ( is_word( temps, name[ i + 1 ] ) ) 
						break;

					move_words( temp, temps );

					if ( is_word( temps, "virtual" ) and is_word( temps, "=" ) )
					{
						int k=0;
						a.virtuals[ a.num_virtuals ] = "["; 
						while ( temps[k] != "=" )
						{
							if ( temps[k] != "virtual" )
								a.virtuals[ a.num_virtuals ] = a.virtuals[ a.num_virtuals ] + temps[k] + ' ';
							k = k + 1;
						}

						a.virtuals[ a.num_virtuals ][ a.virtuals[ a.num_virtuals ].length() - 1 ] = ']';

						replace_spaces_virtual( a.virtuals[ a.num_virtuals ] );

						a.num_virtuals = a.num_virtuals + 1;
					}
				}
			}
		}

		fi.close();

		add_class(a);
	}
}









string valid_choices[1000] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "exit" };
string choices[1000]= { "Add Class", "Add Inheritance", "Add Inheritor", "Remove Class", "Remove Inheritance", "Remove Inheritor", "Show Classes", "Add Virtual", "Remove Virtual" };


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
	cout << "printf \033c";

	cout << "Choices:";

	for ( int i=0; i<length( choices ); i=i+1 )
	{
		if ( i % 3 == 0 )
			cout << "\n    ";
		cout << valid_choices[i] << ". " << choices[i];
		spaces( i );
	}

	cout << "\n\n  exit. Exits to file \"class\"\n\n";

	cout << "Your choice: ";
	getline( cin, choice );
//	if ( i == 0 ) // only if the case
//		getline( cin, choice );

	if ( choice == "" )
	{
		cout << "printf \033c";
		return;
	}

	if ( !is_word( valid_choices, choice ) )
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
		cout << "\nChoices for classes:\n1. Enter class name and inheritance.\n";
		cout << "2. Scan a file.\n\n";

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

		bool have_more = false;
		for ( int l=0; l<a.num_inheritors - 1; l=l+1 )
			for ( int k = l + 1; k<a.num_inheritors; k=k+1 )
				if ( a.inheritors[k] == a.inheritors[l] )
				{
					have_more = true;
					remove_string_iter(  a.inheritors, k );
					a.num_inheritors = a.num_inheritors - 1;
				}

		if ( have_more )
			cout << "Removed inheritors with same name.\n";

		
		cout << "Virtuals num.:";
		cin >> a.num_virtuals;

		if ( a.num_virtuals > 0 )
			cout << "Example: \"void b ( int a )\"\n";

		if ( a.num_virtuals < 0 )
		{
			cout << "Invalid virtuals num.\n";
			continues();
			return;
		}

		for ( int i=0; i<a.num_virtuals; i=i+1 )
		{
			cout << "Virtual num. " << i + 1 << ": ";
			getline( cin, a.virtuals[i] );
			while ( a.virtuals[i] == "" )
				getline( cin, a.virtuals[i] );
		}

		add_class(a);
		continues();
	}

	if ( choice == "2" )
	{
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


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
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


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
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


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
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


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
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


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
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


		show_classes();
		continues();
	}


	if ( choice == "8" )
	{
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


		show_classes();

		int iter;
		cout << "Num. of class to add completly virtual to: ";
		cin >> iter;

		iter = iter - 1;

		if ( iter < 0 or iter >= classes_iter )
		{
			cout << "Class num. invalid. Retry.\n";
			continues();
			return;
		}

		string virtual_string;
		cout << "Comp. Virtual name to add ( Example: \"void b ( int a )\" ): ";
		getline( cin, virtual_string );
		getline( cin, virtual_string );

		replace_spaces_virtual( virtual_string );

		add_virtual( iter, virtual_string );

	}

	if ( choice == "9" )
	{
		if ( classes_iter <= 0 )
		{
			cout << "Classes not made yet.\n";
			continues();
			return;
		}


		show_classes();

		int iter;
		cout << "Num. of class to remove completly virtual of: ";
		cin >> iter;

		iter = iter - 1;

		if ( iter < 0 or iter >= classes_iter )
		{
			cout << "Class num. invalid. Retry.\n";
			continues();
			cout << "printf \033c";
			return;
		}

		int virtual_choice;
		for ( int l=0 ;l<classes[iter].num_virtuals; l=l+1 )
			cout << l + 1 << ") " << add_spaces_virtual( classes[iter].virtuals[l] ) << "\n";

		cout << "\nNum. of virtual: ";
		cin >> virtual_choice;

		virtual_choice = virtual_choice - 1;

		if ( virtual_choice < 0 or virtual_choice >= classes[iter].num_virtuals )
		{
			cout << "Invalid virtual num. Retry.\n";
			continues();
			cout << "printf \033c";
			return;
		}

		string virtual_string = classes[ iter ].virtuals[ virtual_choice ];

		remove_virtual( iter, virtual_string );
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

	cout << "\nExited to file \"class\".\n";
	return 0;
}
