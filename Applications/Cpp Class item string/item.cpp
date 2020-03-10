#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter", "parameter", "parameter" };
string columns[4] = { "parameter", "parameter", "parameter" };
string types[4] = { "int", "int", "int" };

class Item {

	// "Item" has parameters: parameter, parameter, parameter 

	// Parameters:
	int parameter;
	int parameter;
	int parameter;

	bool is_empty;

  public:



	Item()
	{
		this->parameter = null;
		this->parameter = null;
		this->parameter = null;

		this->is_empty = true;
	}

	Item ( int parameter, int parameter, int parameter )
	{
		this->parameter = parameter;
		this->parameter = parameter;
		this->parameter = parameter;

		this->is_empty = true;
	}


	// Getters:
	int get_parameter() { return this->parameter; };
	int get_parameter() { return this->parameter; };
	int get_parameter() { return this->parameter; };

	bool get_is_empty() { return this->is_empty; }

	void get ( int parameter, int parameter, int parameter )
	{
		parameter = this->parameter;
		parameter = this->parameter;
		parameter = this->parameter;
	}


	// Setters:
	void set_parameter( int data ) { this->parameter = data; this->is_empty = false;  };
	void set_parameter( int data ) { this->parameter = data; this->is_empty = false;  };
	void set_parameter( int data ) { this->parameter = data; this->is_empty = false;  };

	void set ( int parameter, int parameter, int parameter )
	{
		this->parameter = parameter;
		this->parameter = parameter;
		this->parameter = parameter;

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item " << "{" << '\n';
		cout << "	int" << ' ' << "parameter = " << parameter << '\n';
		cout << "	int" << ' ' << "parameter = " << parameter << '\n';
		cout << "	int" << ' ' << "parameter = " << parameter << '\n';
	 	cout << '}' << "\n\n";
	}

};



Item item_entries[10000]; // entries
int iter = 0;


int delete_entries[10000]; // entries that are to be removed
int delete_iter = 0;

// Make entry
Item make_entry ()
{
	Item entry;

	cout << "\n";

	int counter = 0;

	cout << "Enter val. for \'parameter\' of type \'int\': ";

	int temp_int_0;

	cin >> temp_int_0;
	entry.set_parameter( temp_int_0 );

	cout << "Enter val. for \'parameter\' of type \'int\': ";

	int temp_int_1;

	cin >> temp_int_1;
	entry.set_parameter( temp_int_1 );

	cout << "Enter val. for \'parameter\' of type \'int\': ";

	int temp_int_2;

	cin >> temp_int_2;
	entry.set_parameter( temp_int_2 );

	cout << "\n\n";

	return entry;
}

// Add entry
void add_entry ( Item entry )
{
	item_entries[ iter ] = entry;
	iter = iter +1;
}


// Add entries
void add_entries ()
{
	ofstream entries;
	entries.open("item_entries");
	entries.close();
	entries.open("item_entries");

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
		entries << item_entries[i].get_parameter() << " ";

		entries << item_entries[i].get_parameter() << " ";

		entries << item_entries[i].get_parameter() << " ";

		if ( i != iter - 1)
			entries << '\n';
	}

	entries.close();
}


// Get entries
void get_entries()
{
	fstream entries;
	entries.open( "item_entries" );

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
		int temp_int_1;

		entries >> temp_int_1;
		item_entries[i].set_parameter( temp_int_1 );
		int temp_int_2;

		entries >> temp_int_2;
		item_entries[i].set_parameter( temp_int_2 );
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

	cout << item_entries[i].get_parameter() << " ";

	cout << item_entries[i].get_parameter() << " ";

	cout << item_entries[i].get_parameter() << " ";

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
					Item copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter() >  item_entries[b].get_parameter() and order == 0 )
				{
					Item copy = item_entries[a];
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
				if ( item_entries[a].get_parameter() <  item_entries[b].get_parameter() and order == 1 )
				{
					Item copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter() >  item_entries[b].get_parameter() and order == 0 )
				{
					Item copy = item_entries[a];
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
				if ( item_entries[a].get_parameter() <  item_entries[b].get_parameter() and order == 1 )
				{
					Item copy = item_entries[a];
					item_entries[a] = item_entries[b];
					item_entries[b] = copy;
				}

				if ( item_entries[a].get_parameter() >  item_entries[b].get_parameter() and order == 0 )
				{
					Item copy = item_entries[a];
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
		if ( item_entries[i].get_parameter() == item and !shown(i) )
		{
			show_entry(i);
			shown_entries[ shown_iter ] = i;
			shown_iter = shown_iter + 1;
		}

	for ( int i=0; i<iter; i=i+1 )
		if ( item_entries[i].get_parameter() == item and !shown(i) )
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
		Item copy = item_entries[a];
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
			Item entry;
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
				Item copy_items[10000];
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
