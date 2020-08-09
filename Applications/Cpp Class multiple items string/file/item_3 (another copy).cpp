#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter", "parameter2[70]", "parameter1" };
string columns[4] = { "parameter", "parameter2[70]", "parameter1" };
string types[4] = { "int", "float", "bool" };

string name = "item_3";

class Item_3 {

	// "Item_3" has parameters: parameter, parameter2[70], parameter1 

	// Parameters:
	int parameter;
	int parameter2_count;
	float parameter2[70];
	bool parameter1;

	bool is_empty;

  public:


	// length of a float[]
	int length ( float data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] )
			i=i+1;

		return i;
	}


	// make a copy of a float[]
	void copy ( float source[], float dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	Item_3()
	{
		this->parameter = 0;
//		copy( {}, this->parameter2 ); // You edit this
		this->parameter1 = false;

		this->is_empty = true;
	}

	Item_3 ( int parameter, float parameter2[], bool parameter1 )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		this->parameter1 = parameter1;

		this->is_empty = true;
	}


	// Getters:
	int get_parameter() { return this->parameter; };
	void get_parameter2( float dest[] ) { copy( this->parameter2, dest ); };
	float get_parameter2( int i ) // get parameter2[i]
	{
		if ( i < parameter2_count and i >= 0 )
			return parameter2[i];
		else
		{
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[70]'. Its size is '" << parameter2_count << "'. 0 was returned.\n";
			return 0;
		}
	}
	int get_parameter2_count() { return this->parameter2_count; }
	bool get_parameter1() { return this->parameter1; };

	bool get_is_empty() { return this->is_empty; }

	void get ( int parameter, float parameter2[], bool parameter1 )
	{
		parameter = this->parameter;
		copy( this->parameter2, parameter2 );
		parameter1 = this->parameter1;
	}


	// Setters:
	void set_parameter( int data ) { this->parameter = data; this->is_empty = false;  };
	void set_parameter2( float data[] ) { copy( data, this->parameter2 ); this->is_empty = false;  };
	void set_parameter2( float data, int i ) // set parameter2[i] to data
	{
		if ( i < parameter2_count and i >= 0 )
			parameter2[i] = data;
		else
		{
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[70]'. Its size is '" << parameter2_count << "'. It was not modified.\n";
		}
	}
	void set_parameter2_count( int data ) { this->parameter2_count = data; }
	void set_parameter1( bool data ) { this->parameter1 = data; this->is_empty = false;  };

	void set ( int parameter, float parameter2[], bool parameter1 )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		this->parameter1 = parameter1;

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item_3 " << "{" << '\n';
		cout << "	int" << ' ' << "parameter = " << parameter << '\n';
		cout << "	int parameter2_count = " << parameter2_count << '\n';
		cout << "	float" << ' ' << "parameter2[70] = { ";
		for ( int i=0; i<parameter2_count; i=i+1 )
			cout << "'" << parameter2[i] << "' ";
		cout << "}\n";

		cout << "	bool" << ' ' << "parameter1 = " << parameter1 << '\n';
	 	cout << '}' << "\n\n";
	}

};



Item_3 item_entries[10000]; // entries
int iter = 0;


int delete_entries[10000]; // entries that are to be removed
int delete_iter = 0;

// Make entry
Item_3 make_entry ()
{
	Item_3 entry;

	cout << "\n";

	int counter = 0;

	cout << "Enter val. for \'parameter\' of type \'int\': ";

	int temp_int_0;

	cin >> temp_int_0;
	entry.set_parameter( temp_int_0 );

	float temp_1[10000] = {};

	counter = 0;
	cout << "Enter num. or val.-s you want to enter for \'parameter2[70]\' of type \'float\': ";
	cin >> counter;

	for ( int i=0; i<counter; i=i+1 )
	{
		cout << "Enter val. " << i + 1;
		cout << ": ";
		cin >> temp_1[i]; // null val.-s do not pass this
	}

	entry.set_parameter2( temp_1 );
	entry.set_parameter2_count ( counter );

	cout << "Enter val. for \'parameter1\' of type \'bool\' ( 1 / 0 ): ";

	string temp_string_2;
	cin >> temp_string_2;

	if ( temp_string_2[0] == '0' or temp_string_2 == "false" )
		entry.set_parameter1( 0 );
	else		entry.set_parameter1( 1 );

	cout << "\n\n";

	return entry;
}

// Was removed
bool is_in_delete_entries ( int a )
{
	for ( int i=0; i<delete_iter; i=i+1 )
		if ( delete_entries[i] == a )
			return true;

	return false;
}


// Add entry
void add_entry ( Item_3 entry )
{
	item_entries[ iter ] = entry;
	iter = iter +1;
}


void get_entries(); // to reset entries when adding// Add entries
void add_entries ()
{
	ofstream entries;
	entries.open("item_3_entries");
	entries.close();
	entries.open("item_3_entries");

	entries << iter - delete_iter << '\n';

	for ( int i=0; i<num_parameters; i=i+1 )
		entries << columns[i] << " ";
	entries << "\n";

	for ( int i=0; i<num_parameters; i=i+1 )
		entries << types[i] << " ";
	entries << "\n";

	int size_of_temp;

	for ( int i=0; i<iter; i=i+1 )
	{
		if ( is_in_delete_entries( i ) )
			continue;

		entries << item_entries[i].get_parameter() << " ";

		float temp_1[10000];
		item_entries[i].get_parameter2( temp_1 );
		size_of_temp = item_entries[i].get_parameter2_count();
		entries << "  " << size_of_temp << "  ";

		for ( int i=0; i<size_of_temp; i=i+1 )
			entries << temp_1[i] << ' ';
		entries << "  ";

		entries << item_entries[i].get_parameter1() << " ";

		if ( i != iter - 1)
			entries << '\n';
	}

	entries.close();

	get_entries();

	delete_iter = 0;
}


// Get entries
void get_entries()
{
	fstream entries;
	entries.open( "item_3_entries" );

	entries >> iter;

	for ( int i=0; i<num_parameters; i=i+1 )
		entries >> columns[i];

	for ( int i=0; i<num_parameters; i=i+1 )
		entries >> types[i];

	int counter;

	for ( int i=0; i<iter; i=i+1 )
	{
		int temp_int_0;

		entries >> temp_int_0;
		item_entries[i].set_parameter( temp_int_0 );
		float temp_1[10000] = {};

		counter = 0;
		entries >> counter;

		for ( int i=0; i<counter; i=i+1 )
		{
			entries >> temp_1[i]; // null val.-s do not pass this
		}

		item_entries[i].set_parameter2( temp_1 );
		item_entries[i].set_parameter2_count ( counter );
		bool temp_bool_2;

		entries >> temp_bool_2;
		item_entries[i].set_parameter1( temp_bool_2 );
	}

	entries.close();
}


// Show entry
void show_entry( int i )
{
	if ( i < 0 or i >= iter )
	{
		cout << "Entry num. '" << i + 1 << "' is not valid.\n" ;
		return;
	}

	if ( is_in_delete_entries(i) )
	{
		cout << "Entry num. '" << i + 1 << "' was removed.\n" ;
		return;
	}

	int size_of_temp;

	cout << item_entries[i].get_parameter() << " ";

	float temp_1[10000];
	item_entries[i].get_parameter2( temp_1 );
	size_of_temp = item_entries[i].get_parameter2_count();
	cout << "  [ size: ";
	cout << size_of_temp << " = ( ";

	for ( int i=0; i<size_of_temp; i=i+1 )
		cout << temp_1[i] << ' ';
	cout << ") ]  ";

	cout << item_entries[i].get_parameter1() << " ";

	cout << "\n";
}

// Show column names ( modifiable )
void show_columns ()
{
	cout << "\n";
	for ( int i=0; i<num_parameters; i=i+1 )
		cout << columns[i] << " ";
	cout << "\n";
}

// Rename column
void rename_column ( int a, string name )
{
	if ( columns[a][ columns[a].length() - 1] == ']' )
		columns[a] = name + "[]";
	else
		columns[a] = name;
}

// Sort
void sort ( int i, int order )
{
	if ( order != 0 )
		order = 1;

	if ( i == 0 )
	{
		for ( int a=0; a<iter-1; a=a+1 )
			for ( int b=a+1; b<iter; b=b+1 )
			{
				if ( item_entries[a].get_parameter() <  item_entries[b].get_parameter() and order == 1 )
				{
					Item_3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter() >  item_entries[b].get_parameter() and order == 0 )
				{
					Item_3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}
			}
	}
	if ( i == 1 )
	{
		for ( int a=0; a<iter-1; a=a+1 )
			for ( int b=a+1; b<iter; b=b+1 )
			{
				if ( item_entries[a].get_parameter2_count() <  item_entries[b].get_parameter2_count() and order == 1 )
				{
					Item_3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter2_count() >  item_entries[b].get_parameter2_count() and order == 0 )
				{
					Item_3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}
			}
	}
	if ( i == 2 )
	{
		for ( int a=0; a<iter-1; a=a+1 )
			for ( int b=a+1; b<iter; b=b+1 )
			{
				if ( item_entries[a].get_parameter1() <  item_entries[b].get_parameter1() and order == 1 )
				{
					Item_3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter1() >  item_entries[b].get_parameter1() and order == 0 )
				{
					Item_3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}
			}
	}
}


// Show "[ ']' + Enter ] to continue"
void enter()
{
	char enter;
	cout << "\n[ ']' + Enter ] to continue: ";
	cin >> enter;
	cout << "\n";
}


int shown_entries[100000]; // entries that were shown in  get_entry_item( item )  
int shown_iter = 0;

// Was shown
bool shown( int a )
{
	for ( int i=0; i<shown_iter; i=i+1 )
		if ( shown_entries[i] == a )
			return true;
	return false;
}

// Get entry item - for numeric datatypes
void get_entry_item( long item )
{
	for ( int i=0; i<iter; i=i+1 )
		if ( item_entries[i].get_parameter() == item and !shown(i) )
		{
			show_entry(i);
			shown_entries[ shown_iter ] = i;
			shown_iter = shown_iter + 1;
		}

	for ( int i=0; i<iter; i=i+1 )
	{
		int size = item_entries[i].get_parameter2_count();
		for ( int a=0; a<size; a=a+1 )
			if ( item_entries[i].get_parameter2(a) == item and !shown(i) )
			{
				show_entry(i);
				shown_entries[ shown_iter ] = i;
				shown_iter = shown_iter + 1;
			}

	}

	for ( int i=0; i<iter; i=i+1 )
		if ( item_entries[i].get_parameter1() == item and !shown(i) )
		{
			show_entry(i);
			shown_entries[ shown_iter ] = i;
			shown_iter = shown_iter + 1;
		}

	shown_iter = 0;
}

// Swap entries
void swap ( int a, int b )
{
	if ( a >= 0 and a < iter  and  b >= 0 and b < iter )
	{
		Item_3 copy = item_entries[a];
		item_entries[a] = item_entries[b];
		item_entries[b] = copy;
		cout << "Entries were swapped and saved.\n";

	}
	else
		cout << "Could not swap / move: invalid entry num.\n";
}

// length of a string[]
int length ( string a[] )
{
	int i=0;
	while ( a[i].length() > 0 )
		i=i+1;
	return i;
}

// convert string to int
int string_to_int ( string a )
{
	int size = a.length();

	int iter = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		iter = 1;
	}

	int num_int = 0;
	for ( int i=iter; i<size; i=i+1 )
		num_int = num_int * 10 + ( a[i] - 48 );
	if ( is_neg )
		num_int = -num_int;

	return num_int;
}

// moves words of string  text  into  words[]  
void move_words ( string text, string words[] )
{
	for ( int i=0; i<length(words); i=i+1 )
		words[i] = "";

	// remove multiple ' '-s
	string text_spaces = "";
	for ( int i=0; i<text.length(); i=i+1 )
		if ( text[i] != ' ' )
			text_spaces = text_spaces + text[i];
		else
			if ( text_spaces[ text_spaces.length() - 1 ] != ' ' )
				text_spaces = text_spaces + " ";
	text = text_spaces;

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

// get simmilars
void get_simmilars( string parameters_1[], string filenames_2[], string parameters_2[] )
{
	int simmilar_iter;

	int counter = 0;

	ifstream fi;
	fi.open( "simmilar" );
	fi >> simmilar_iter;

	string temp_string;

	for ( int i=0; i<simmilar_iter; i=i+1 )
	{
		getline( fi, temp_string );
		if ( i == 0 )
			getline( fi, temp_string );

		string temp[ 10 ];
		move_words( temp_string, temp );

		if ( temp[0] == name + "_entries"  )
		{
			parameters_1[ counter ] = temp[ 1 ];
			filenames_2[ counter ] = temp[ 2 ];
			parameters_2[ counter ] = temp[ 3 ];
			counter = counter + 1;
		}
		if ( temp[2] == name + "_entries"  )
		{
			parameters_1[ counter ] = temp[ 3 ];
			filenames_2[ counter ] = temp[ 0 ];
			parameters_2[ counter ] = temp[ 1 ];
			counter = counter + 1;
		}
	}

	fi.close();
}

string parameters_1[1000];
string filenames_2[1000];
string parameters_2[1000];

// used in determine simmilarity
bool is_in_simmilars( string param1, string filename2, string param2 )
{
	int size = length( parameters_1 );

	for ( int i=0; i<size; i=i+1 )
		if ( parameters_1[i] == param1 and filenames_2[i] == filename2 and parameters_2[i] == param2 )
			return true;

	return false;
}
// used in determine simmilarity
string get_entry_of_file ( string filename, int entry_num )
{
	ifstream f;
	f.open( filename );
	int num;
	string entry;	f >> num;

	for ( int i=0; i<num; i=i+1 )
	{
		getline( f, entry );
		if ( i == 0 );
			getline( f, entry );
		if ( i == entry_num );
		{
			f.close();
			return entry;
		}
	}
	f.close();

	return "-1";
}
// Simmilar
void show_simmilar( int entry_pos )
{
	string choice;
	cout << "Show simmilars? ( y / n ): ";
	cin >> choice;

	string empty;
	string parameter;
	string val[1000];
	int val_iter;
	string remaining_files[1000];
	int iters[1000];
	int counter = 0;
	if ( choice == "y" )
	{
		ifstream f;
		f.open( name + "_entries" );
		string file_val[ 1000 ];
		for ( int i=0; i<3 + entry_pos; i=i+1 )
		{
			getline( f, empty );
	//		cout << i << "       " << empty << "\n";
		}
		for ( int l=0; l<num_parameters; l=l+1 )
		{
			f >> file_val[l];
			if ( parameters[l][ parameters[l].length() - 1 ] == ']' )
			{
				for ( int k=0; k<string_to_int( file_val[l] ); k=k+1 )
					f >> empty;
			}

			val[val_iter] = file_val[l];

	//		cout << "val iter " << val_iter << ": " << val[val_iter] << "\n";

			val_iter = val_iter + 1;
		}
		f.close();
     
		f.open( "entry_files" );
		int num_files;
		f >> num_files;
		string files[1000];
		for ( int i=0; i<num_files; i=i+1 )
			f >> files[i];
		f.close();

		cout << "\n\n" << length( files ) << "\n\n";

		get_simmilars( parameters_1, filenames_2, parameters_2 );

		cout << "\n\n" << length( parameters_1 ) << "\n\n";

		for ( int i=0; i<num_files; i=i+1 )
		{
			int current_num_entries;
			int current_parameters_size;
			string current_parameters_string;
			string current_parameters[1000];
			string current_types[1000];
			
			ifstream fi;
			fi.open( files[i] + "_entries" );
			fi >> current_num_entries;


			getline( fi, empty );



			getline( fi, current_parameters_string );

			cout << "\n" << files[i] << "_entries: \"" << current_parameters_string << "\"\n";

			move_words( current_parameters_string, current_parameters );
			current_parameters_size = length( current_parameters );
			for ( int l=0; l<current_parameters_size; l=l+1 )
				fi >> current_types[l];

			string current_val;
			int counter_iter = 0;
			for ( int l=0; l<current_parameters_size; l=l+1 )
				for ( int a=0; a<current_num_entries; a=a+1 )
				{

					counter_iter = counter_iter % current_parameters_size;

					fi >> current_val;
					if ( current_parameters[counter_iter][ current_parameters[counter_iter].length() - 1 ] == ']' )
						for ( int k=0; k<string_to_int( current_val ); k=k+1 )
							fi >> empty;

					cout << " 	" << ( current_parameters[counter_iter][ current_parameters[counter_iter].length() - 1 ] == ']' )
<< "  " << current_val << "\n";

					for ( int k=0; k<num_parameters; k=k+1 )
						if ( is_in_simmilars( columns[k], files[i] + "_entries", current_parameters[l] ) )
						{
							if ( val[k] == current_val )
							{
								iters[ counter ] = a;
								remaining_files[ counter ] = files[i] + "_entries";
								counter = counter + 1;
							}
						}
					counter_iter = counter_iter + 1;
				}
			fi.close();
		}
	}
	for ( int i=0; i<counter; i=i+1 )
		cout << "Simmilarity in file \'" << remaining_files[i] << "\': " << get_entry_of_file( remaining_files[i], iters[i] ) << "\n" ;
}
// Move entries
void move ( int entry_num, int direction, int iterations )
{
	int swap_entry_num;

	if ( direction == 0 )
	{
		swap_entry_num = entry_num - iterations;
		if ( swap_entry_num < 0)
			swap_entry_num = 0;
		for ( int i=entry_num; i>swap_entry_num; i=i-1 )
			swap( i, i - 1 );
	}

	if ( direction == 1 )
	{
		swap_entry_num = entry_num + iterations;
		if ( swap_entry_num >= iter)
			swap_entry_num = iter - 1;
		for ( int i=entry_num; i<swap_entry_num; i=i+1 )
			swap( i, i + 1 );
	}

}
void show_entries()
{
	if ( iter == 0 )
		return;

	cout << "- Entries";

	show_columns();

	for ( int i=0; i<iter; i=i+1 )
	{
		cout << "(" << i + 1 << ")   ";
		show_entry( i );
	}
}


int main()
{
	// Show datatype info
	cout << "Enter only valid datatypes for:\n";
	item_entries[0].info();
	enter();

	// Get entry
	get_entries();

	// Operation choice
	string choice = "";

	// for now, it is done with a for
	for ( int i=0; i<100000; i=i+1 )
	{

		cout << "\n\n";
		cout << "Operation num. " << i + 1 << " ( enter valid datatypes ) \n";
		cout << "Operations:\n";
		cout << "  1. Add entry       2. Show entry     3. Show entries - complete  4. Show entries  5. Remove entry\n";
		cout << "  6. Remove entries  7. Clear entries  8. Sort ( show / save )     9. Move          10. Swap\n";
		cout << "   or\n";
		cout << "  item. Show entries that have [item]    save. Save    exit. Exit\n";


		cout << "\nEnter your choice: ";
		cin >> choice;

		// Add entry
		if ( choice == "1" )
		{
			Item_3 entry;
			entry = make_entry();
			entry.info();
			add_entry(entry);
			add_entries();
			enter();
		}

		// Show entry
		if ( choice == "2" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			int i;
			cout << "Enter num. of entry: ";
			cin >> i;
			show_columns();
			show_entry( i - 1 );
			show_simmilar( i - 1 );
			enter();
		}

		// Show entries - complete
		if ( choice == "3" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			show_entries();
			enter();
		}

		// Show entries
		if ( choice == "4" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			int entry_iter;
			cout << "Stop with -1\n";
			while ( entry_iter != -1 )
			{
				cout << "Enter num. of entry: ";
				cin >> entry_iter;

				if ( entry_iter == -1 )
					break;

				show_entry( entry_iter - 1 );
			}
			entry_iter = 0;
			enter();
		}

		// Remove entry
		if ( choice == "5" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			show_entries();
			int i;
			cout << "Enter num. of entry: ";
			cin >> i;

			delete_entries[ delete_iter ] = i - 1;
			delete_iter = delete_iter + 1;

			add_entries();
			cout << "\nEntry was deleted\n";
			enter();
		}

		// Remove entries
		if ( choice == "6" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			show_entries();
			int entry_iter;
			cout << "Stop with -1\n";
			while ( entry_iter != -1 )
			{
				cout << "Enter num. of entry to remove: ";
				cin >> entry_iter;

				if ( entry_iter == -1 )
					break;

				if ( entry_iter <= 0 or entry_iter > iter )
				{
					cout << "Entry num. is invalid.\n";
					entry_iter = 0;
					continue;
				}

				delete_entries[ delete_iter ] = entry_iter - 1;
				delete_iter = delete_iter + 1;
			}
			entry_iter = 0;
			add_entries();
			enter();
		}

		// Clear entries
		if ( choice == "7" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			iter = 0;
			add_entries();
			cout << "Entries were cleared.\n";
			enter();
		}

		// Sort ( show / save )
		if ( choice == "8" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			cout << "1. \'Show\'  but not save entries       ";
			cout << "2. \'Save\'  but not show entries\n\n";
			cout << "Enter your choice: ";

			int sort_choice;
			cin >> sort_choice;

			if ( sort_choice != 1 and sort_choice != 2 )
				cout << "Sorting aborted.\n";
			else
			{
				Item_3 copy_items[10000];
				for ( int i=0; i<num_parameters; i=i+1 )
					copy_items[i] = item_entries[i];

				cout << "Enter num. of column you want to sort by: ";
				int column_num;
				cin >> column_num;

				if ( column_num > num_parameters )
					cout << "Column num. is not valid. Sorting aborted.\n";
				else
				{
					cout << "Enter order ( 0. asc  1. desc ) : ";
					int order;
					cin >> order;

					if ( sort_choice == 1 )
					{
						sort( column_num - 1, order );
						show_columns();
						for ( int i=0; i<iter; i=i+1 )
							show_entry(i);
						for ( int i=0; i<iter; i=i+1 )
							item_entries[i] = copy_items[i];
					}

					if ( sort_choice == 2 )
					{
						sort( column_num - 1, order );
						add_entries();
						cout << "Entries were sorted and saved.\n";
					}
				}
			}

			enter();
		}

		// Move
		if ( choice == "9" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			int entry_num;
			cout << "Enter entry num. you want to move: ";
			cin >> entry_num;
			int direction;
			cout << "Enter direction ( 0. asc  1. desc ): ";
			cin >> direction;
			if ( !( direction == 0 or direction == 1 ) )
				cout << "Move aborted: invalid direction.\n";
			else
			{
				int iterations;
				cout << "Enter how many times you want to move: ";
				cin >> iterations;
				move ( entry_num - 1, direction, iterations );
				add_entries();
				cout << "Entry was moved.\n";
			}

			enter();
		}

		// Swap
		if ( choice == "10" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			int a, b;
			cout << "Enter entry num. or entry 1 you want to swap: ";
			cin >> a;
			cout << "Enter entry num. or entry 2 you want to swap: ";
			cin >> b;

			swap( a - 1, b - 1 );

			add_entries();
			enter();
		}

		// Show entries that have [item]
		if ( choice == "item" )
		{
			if ( iter == 0 )
			{
				cout << "Entries are empty.\n";
				choice = "";
				continue;
			}

			string type;
			long item_parameter;
			cout << "Get item by parameter val.: ";
			cin >> item_parameter;
			show_columns();

			get_entry_item( item_parameter );

			enter();
		}

//		Commented for simmilarities

//		// Name / rename a column
//		if ( choice == "name" )
//		{
//			int num_column;
//			string name;
//			cout << "Enter num. of column you want to rename: ";
//			cin >> num_column;

//			cout << "Renaming column " << num_column << " of type '" << types[num_column - 1] << "', var. name '" << parameters[num_column - 1] << "' and previous name '" << columns[num_column - 1] << "' to: ";
//			cin >> name;

//			rename_column( num_column - 1, name );

//			add_entries();
//			enter();
//		}

		// Save
		if ( choice == "save" )
		{
			add_entries();
			cout << "Entries were saved (they are by default when any modifications are made).";
			enter();
		}

		// Exit
		if ( choice == "exit" )
		{
			cout << "Exited.\n";
			break;
		}

		choice = "";

	}

	// Save
	add_entries();

	return 0;
}
