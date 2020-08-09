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


void remove_class( int iter );

void add_class( Class a )
{

	get_classes();

	if ( is_class_added(a.name) )
	{
		for ( int i=0; i<classes_iter; i=i+1 )
			if ( a.name == classes[i].name )
				remove_class(i);
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

	cout << "Class \"" << a.name << "\" added to inheritances.\n";
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


	string name;
	string inheritance;


	ifstream fi;

	fi.open( filename );

	string temp;
	string temps[1000];
	while ( getline( fi, temp ) )
	{
		move_words( temp, temps );

		if ( is_word( temps, "class" ) )
		{
			name = temps[ word_pos( temps, "class" ) + 1 ];

			if ( is_word( temps, "public" ) )
				inheritance = temps[ word_pos( temps, "public" ) + 1 ];
			else
				inheritance = "";
		}
	}

	fi.close();


	Class a;
	a.name = name;
	a.inherits = false;
	if ( inheritance != "" )
	{
		a.inherits = true;
		a.inheritance = inheritance;
	}


	fi.open ( filename );

	temp = "";

	a.num_virtuals = 0;

	while ( getline( fi, temp ) )
	{
		move_words( temp, temps );

		if ( is_word( temps, "virtual" ) )
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
	
	fi.close();

	add_class(a);



	for ( int i=0; i<classes_iter; i=i+1 )
		if ( classes[i].name == inheritance and classes[i].num_virtuals != 0 )
		{
			fi.open( filename );

			string file = "";
	
			temp = "";
			while ( getline( fi, temp ) )
			{
				if ( temp[0] == '}' and temp[1] == ';' )
					break;

				file = file + temp + "\n";
			}

			fi.close();			

			// clears the file
			ofstream fo;
			fo.open( filename );
			fo.close();


			fo.open( filename );
			
			fo << file;

			for ( int l=0; l<classes[i].num_virtuals; l=l+1 )
			{
				fo << "	" << add_spaces_virtual( classes[i].virtuals[l] ) << "\n";
				fo << "	{\n";
				fo << "		// inherited, please implement\n";
				fo << "	}\n\n";
			}

			fo << "\n};\n\n\nint main()\n{\n\n	return 0;\n}\n";

			fo.close();
		}

}







