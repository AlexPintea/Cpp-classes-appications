#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter[10]", "parameter2[10]", "parameter1[10]" };
string columns[4] = { "parameter[10]", "parameter2[10]", "parameter1[10]" };
string types[4] = { "int", "float", "float" };

class Item 3 {

	// "Item 3" has parameters: parameter[10], parameter2[10], parameter1[10] 

	// Parameters:
	int parameter_count;
	int parameter[10];
	int parameter2_count;
	float parameter2[10];
	int parameter1_count;
	float parameter1[10];

	bool is_empty;

  public:


	// length of a int[]
	int length ( int data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] )
			i=i+1;

		return i;
	}

	// length of a float[]
	int length ( float data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] )
			i=i+1;

		return i;
	}

	// length of a float[]
	int length ( float data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] )
			i=i+1;

		return i;
	}


	// make a copy of a int[]
	void copy ( int source[], int dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	// make a copy of a float[]
	void copy ( float source[], float dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	// make a copy of a float[]
	void copy ( float source[], float dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	Item 3()
	{
//		copy( {}, this->parameter ); // You edit this
//		copy( {}, this->parameter2 ); // You edit this
//		copy( {}, this->parameter1 ); // You edit this

		this->is_empty = true;
	}

	Item 3 ( int parameter[], float parameter2[], float parameter1[] )
	{
		copy( parameter, this->parameter );
		copy( parameter2, this->parameter2 );
		copy( parameter1, this->parameter1 );

		this->is_empty = true;
	}


	// Getters:
	void get_parameter( int dest[] ) { copy( this->parameter, dest ); };
	int get_parameter( int i ) // get parameter[i]
	{
		if ( i < parameter_count and i >= 0 )
			return parameter[i];
		else
		{
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter[10]'. Its size is '" << parameter_count << "'. 0 was returned.\n";
			return 0;
		}
	}
	int get_parameter_count() { return this->parameter_count; }
	void get_parameter2( float dest[] ) { copy( this->parameter2, dest ); };
	float get_parameter2( int i ) // get parameter2[i]
	{
		if ( i < parameter2_count and i >= 0 )
			return parameter2[i];
		else
		{
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[10]'. Its size is '" << parameter2_count << "'. 0 was returned.\n";
			return 0;
		}
	}
	int get_parameter2_count() { return this->parameter2_count; }
	void get_parameter1( float dest[] ) { copy( this->parameter1, dest ); };
	float get_parameter1( int i ) // get parameter1[i]
	{
		if ( i < parameter1_count and i >= 0 )
			return parameter1[i];
		else
		{
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter1[10]'. Its size is '" << parameter1_count << "'. 0 was returned.\n";
			return 0;
		}
	}
	int get_parameter1_count() { return this->parameter1_count; }

	bool get_is_empty() { return this->is_empty; }

	void get ( int parameter[], float parameter2[], float parameter1[] )
	{
		copy( this->parameter, parameter );
		copy( this->parameter2, parameter2 );
		copy( this->parameter1, parameter1 );
	}


	// Setters:
	void set_parameter( int data[] ) { copy( data, this->parameter ); this->is_empty = false;  };
	void set_parameter( int data, int i ) // set parameter[i] to data
	{
		if ( i < parameter_count and i >= 0 )
			parameter[i] = data;
		else
		{
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter[10]'. Its size is '" << parameter_count << "'. It was not modified.\n";
		}
	}
	void set_parameter_count( int data ) { this->parameter_count = data; }
	void set_parameter2( float data[] ) { copy( data, this->parameter2 ); this->is_empty = false;  };
	void set_parameter2( float data, int i ) // set parameter2[i] to data
	{
		if ( i < parameter2_count and i >= 0 )
			parameter2[i] = data;
		else
		{
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[10]'. Its size is '" << parameter2_count << "'. It was not modified.\n";
		}
	}
	void set_parameter2_count( int data ) { this->parameter2_count = data; }
	void set_parameter1( float data[] ) { copy( data, this->parameter1 ); this->is_empty = false;  };
	void set_parameter1( float data, int i ) // set parameter1[i] to data
	{
		if ( i < parameter1_count and i >= 0 )
			parameter1[i] = data;
		else
		{
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter1[10]'. Its size is '" << parameter1_count << "'. It was not modified.\n";
		}
	}
	void set_parameter1_count( int data ) { this->parameter1_count = data; }

	void set ( int parameter[], float parameter2[], float parameter1[] )
	{
		copy( parameter, this->parameter );
		copy( parameter2, this->parameter2 );
		copy( parameter1, this->parameter1 );

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item 3 " << "{" << '\n';
		cout << "	int parameter_count = " << parameter_count << '\n';
		cout << "	int" << ' ' << "parameter[10] = { ";
		for ( int i=0; i<parameter_count; i=i+1 )
			cout << "'" << parameter[i] << "' ";
		cout << "}\n";

		cout << "	int parameter2_count = " << parameter2_count << '\n';
		cout << "	float" << ' ' << "parameter2[10] = { ";
		for ( int i=0; i<parameter2_count; i=i+1 )
			cout << "'" << parameter2[i] << "' ";
		cout << "}\n";

		cout << "	int parameter1_count = " << parameter1_count << '\n';
		cout << "	float" << ' ' << "parameter1[10] = { ";
		for ( int i=0; i<parameter1_count; i=i+1 )
			cout << "'" << parameter1[i] << "' ";
		cout << "}\n";

	 	cout << '}' << "\n\n";
	}

};



Item 3 item_entries[10000]; // entries
int iter = 0;


int delete_entries[10000]; // entries that are to be removed
int delete_iter = 0;

// Make entry
Item 3 make_entry ()
{
	Item 3 entry;

	cout << "\n";

	int counter = 0;

	int temp_0[10000] = {};

	counter = 0;
	cout << "Enter num. or val.-s you want to enter for \'parameter[10]\' of type \'int\': ";
	cin >> counter;

	for ( int i=0; i<counter; i=i+1 )
	{
		cout << "Enter val. " << i + 1;
		cout << ": ";
		cin >> temp_0[i]; // null val.-s do not pass this
	}

	entry.set_parameter( temp_0 );
	entry.set_parameter_count ( counter );

	float temp_1[10000] = {};

	counter = 0;
	cout << "Enter num. or val.-s you want to enter for \'parameter2[10]\' of type \'float\': ";
	cin >> counter;

	for ( int i=0; i<counter; i=i+1 )
	{
		cout << "Enter val. " << i + 1;
		cout << ": ";
		cin >> temp_1[i]; // null val.-s do not pass this
	}

	entry.set_parameter2( temp_1 );
	entry.set_parameter2_count ( counter );

	float temp_2[10000] = {};

	counter = 0;
	cout << "Enter num. or val.-s you want to enter for \'parameter1[10]\' of type \'float\': ";
	cin >> counter;

	for ( int i=0; i<counter; i=i+1 )
	{
		cout << "Enter val. " << i + 1;
		cout << ": ";
		cin >> temp_2[i]; // null val.-s do not pass this
	}

	entry.set_parameter1( temp_2 );
	entry.set_parameter1_count ( counter );

	cout << "\n\n";

	return entry;
}

// Add entry
void add_entry ( Item 3 entry )
{
	item_entries[ iter ] = entry;
	iter = iter +1;
}


// Add entries
void add_entries ()
{
	ofstream entries;
	entries.open("item 3_entries");
	entries.close();
	entries.open("item 3_entries");

	entries << iter << '\n';

	for ( int i=0; i<num_parameters; i=i+1 )
		entries << columns[i] << " ";
	entries << "\n";

	for ( int i=0; i<num_parameters; i=i+1 )
		entries << types[i] << " ";
	entries << "\n";

	int size_of_temp;

	for ( int i=0; i<iter; i=i+1 )
	{
		int temp_0[10000];
		item_entries[i].get_parameter( temp_0 );
		size_of_temp = item_entries[i].get_parameter_count();
		entries << "  " << size_of_temp << "  ";

		for ( int i=0; i<size_of_temp; i=i+1 )
			entries << temp_0[i] << ' ';
		entries << "  ";

		float temp_1[10000];
		item_entries[i].get_parameter2( temp_1 );
		size_of_temp = item_entries[i].get_parameter2_count();
		entries << "  " << size_of_temp << "  ";

		for ( int i=0; i<size_of_temp; i=i+1 )
			entries << temp_1[i] << ' ';
		entries << "  ";

		float temp_2[10000];
		item_entries[i].get_parameter1( temp_2 );
		size_of_temp = item_entries[i].get_parameter1_count();
		entries << "  " << size_of_temp << "  ";

		for ( int i=0; i<size_of_temp; i=i+1 )
			entries << temp_2[i] << ' ';
		entries << "  ";

		if ( i != iter - 1)
			entries << '\n';
	}

	entries.close();
}


// Get entries
void get_entries()
{
	fstream entries;
	entries.open( "item 3_entries" );

	entries >> iter;

	for ( int i=0; i<num_parameters; i=i+1 )
		entries >> columns[i];

	for ( int i=0; i<num_parameters; i=i+1 )
		entries >> types[i];

	int counter;

	for ( int i=0; i<iter; i=i+1 )
	{
		int temp_0[10000] = {};

		counter = 0;
		entries >> counter;

		for ( int i=0; i<counter; i=i+1 )
		{
			entries >> temp_0[i]; // null val.-s do not pass this
		}

		item_entries[i].set_parameter( temp_0 );
		item_entries[i].set_parameter_count ( counter );
		float temp_1[10000] = {};

		counter = 0;
		entries >> counter;

		for ( int i=0; i<counter; i=i+1 )
		{
			entries >> temp_1[i]; // null val.-s do not pass this
		}

		item_entries[i].set_parameter2( temp_1 );
		item_entries[i].set_parameter2_count ( counter );
		float temp_2[10000] = {};

		counter = 0;
		entries >> counter;

		for ( int i=0; i<counter; i=i+1 )
		{
			entries >> temp_2[i]; // null val.-s do not pass this
		}

		item_entries[i].set_parameter1( temp_2 );
		item_entries[i].set_parameter1_count ( counter );
	}

	entries.close();
}


// Was removed
bool is_in_delete_entries ( int a )
{
	for ( int i=0; i<delete_iter; i=i+1 )
		if ( delete_entries[i] == a )
			return true;

	return false;
}


// Show entry
void show_entry( int i )
{
	if ( i >= iter )
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

	int temp_0[10000];
	item_entries[i].get_parameter( temp_0 );
	size_of_temp = item_entries[i].get_parameter_count();
	cout << "  [ size: ";
	cout << size_of_temp << " = ( ";

	for ( int i=0; i<size_of_temp; i=i+1 )
		cout << temp_0[i] << ' ';
	cout << ") ]  ";

	float temp_1[10000];
	item_entries[i].get_parameter2( temp_1 );
	size_of_temp = item_entries[i].get_parameter2_count();
	cout << "  [ size: ";
	cout << size_of_temp << " = ( ";

	for ( int i=0; i<size_of_temp; i=i+1 )
		cout << temp_1[i] << ' ';
	cout << ") ]  ";

	float temp_2[10000];
	item_entries[i].get_parameter1( temp_2 );
	size_of_temp = item_entries[i].get_parameter1_count();
	cout << "  [ size: ";
	cout << size_of_temp << " = ( ";

	for ( int i=0; i<size_of_temp; i=i+1 )
		cout << temp_2[i] << ' ';
	cout << ") ]  ";

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
				if ( item_entries[a].get_parameter_count() <  item_entries[b].get_parameter_count() and order == 1 )
				{
					Item 3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter_count() >  item_entries[b].get_parameter_count() and order == 0 )
				{
					Item 3 copy = item_entries[a];
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
					Item 3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter2_count() >  item_entries[b].get_parameter2_count() and order == 0 )
				{
					Item 3 copy = item_entries[a];
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
				if ( item_entries[a].get_parameter1_count() <  item_entries[b].get_parameter1_count() and order == 1 )
				{
					Item 3 copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter1_count() >  item_entries[b].get_parameter1_count() and order == 0 )
				{
					Item 3 copy = item_entries[a];
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
	{
		int size = item_entries[i].get_parameter_count();
		for ( int a=0; a<size; a=a+1 )
			if ( item_entries[i].get_parameter(a) == item and !shown(i) )
			{
				show_entry(i);
				shown_entries[ shown_iter ] = i;
				shown_iter = shown_iter + 1;
			}

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
	{
		int size = item_entries[i].get_parameter1_count();
		for ( int a=0; a<size; a=a+1 )
			if ( item_entries[i].get_parameter1(a) == item and !shown(i) )
			{
				show_entry(i);
				shown_entries[ shown_iter ] = i;
				shown_iter = shown_iter + 1;
			}

	}

	shown_iter = 0;
}

// Swap entries
void swap ( int a, int b )
{
	if ( a >= 0 and a < iter  and  b >= 0 and b < iter )
	{
		Item 3 copy = item_entries[a];
		item_entries[a] = item_entries[b];
		item_entries[b] = copy;
	}
	else
		cout << "Could not swap / move: invalid entry num.\n";
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
		cout << "  item. Show entries that have [item]    name. Name / Rename a column    save. Save    exit. Exit\n";


		cout << "\nEnter your choice: ";
		cin >> choice;

		// Add entry
		if ( choice == "1" )
		{
			Item 3 entry;
			entry = make_entry();
			entry.info();
			add_entry(entry);
			add_entries();
			enter();
		}

		// Show entry
		if ( choice == "2" )
		{
			int i;
			cout << "Enter num. of entry: ";
			cin >> i;
			show_columns();
			show_entry(i - 1);
			enter();
		}

		// Show entries - complete
		if ( choice == "3" )
		{
			if ( iter == 0 )
				cout << "Entries are empty.\n";
			else
			{
				show_columns();
				for ( int i=0; i<iter; i=i+1 )
					show_entry(i);
			}
			enter();
		}

		// Show entries
		if ( choice == "4" )
		{
			int int_entries;
			cout << "Enter num.-s or entries ( 142, 1542 etc. ): ";
			cin >> int_entries;

			int digits[10], num = 0;
			while ( int_entries != 0 )
			{
				digits[ num ] = int_entries % 10;
				num = num + 1;
				int_entries = int_entries / 10;
			}

			show_columns();
			for ( int i=num-1; i>=0; i=i-1 )
				show_entry( digits[i] - 1 );
			enter();
		}

		// Remove entry
		if ( choice == "5" )
		{
			int i;
			cout << "Enter num. of entry: ";
			cin >> i;

			cout << "\nEntry that was deleted\n";
			show_columns();
			delete_entries[ delete_iter ] = i - 1;
			delete_iter = delete_iter + 1;

			add_entries();
			enter();
		}

		// Remove entries
		if ( choice == "6" )
		{
			int int_entries;
			cout << "Enter num.-s or entries ( 142, 1542 etc. ): ";
			cin >> int_entries;

			cout << "Entries that were deleted\n";
			show_columns();
			while ( int_entries != 0 )
			{
				delete_entries[ delete_iter ] = int_entries % 10 - 1;
				show_entry( delete_iter );
				delete_iter = delete_iter + 1;
				int_entries = int_entries / 10;
			}

			add_entries();
			enter();
		}

		// Clear entries
		if ( choice == "7" )
		{
			iter = 0;
			add_entries();
			cout << "Entries were cleared.\n";
			enter();
		}

		// Sort ( show / save )
		if ( choice == "8" )
		{
			cout << "1. \'Show\'  but not save entries       ";
			cout << "2. \'Save\'  but not show entries\n\n";
			cout << "Enter your choice: ";

			int sort_choice;
			cin >> sort_choice;

			if ( sort_choice != 1 and sort_choice != 2 )
				cout << "Sorting aborted.\n";
			else
			{
				Item 3 copy_items[10000];
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
			int a, b;
			cout << "Enter entry num. or entry 1 you want to swap: ";
			cin >> a;
			cout << "Enter entry num. or entry 2 you want to swap: ";
			cin >> b;

			swap( a - 1, b - 1 );

			add_entries();
			cout << "Entries were swapped and saved.\n";

			enter();
		}

		// Show entries that have [item]
		if ( choice == "item" )
		{
			string type;
			long item_parameter;
			cout << "Get item by parameter val.: ";
			cin >> item_parameter;
			show_columns();

			get_entry_item( item_parameter );

			enter();
		}

		// Name / rename a column
		if ( choice == "name" )
		{
			int num_column;
			string name;
			cout << "Enter num. of column you want to rename: ";
			cin >> num_column;

			cout << "Renaming column " << num_column << " of type '" << types[num_column - 1] << "', var. name '" << parameters[num_column - 1] << "' and previous name '" << columns[num_column - 1] << "' to: ";
			cin >> name;

			rename_column( num_column - 1, name );

			add_entries();
			enter();
		}

		// Save
		if ( choice == "save" )
		{
			add_entries();
			cout << "Entries were saved (they are by default when any modifications are made).";
			enter();
		}

		// Exit
		if ( choice == "exit" )
			break;

		choice = "";

	}

	// Save
	add_entries();

	return 0;
}
