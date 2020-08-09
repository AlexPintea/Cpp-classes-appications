#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter", "parameter2[10]", "parameter1" };
int types[4] = { 1, 2, 7 };

class Item {

	// "Item" has parameters: parameter, parameter2[10], parameter1 

	// Parameters:
	int parameter;
	int parameter2_count;
	float parameter2[10];
	bool parameter1;

	bool is_empty;

  public:


	int length ( float data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] != '\0' )
			i=i+1;

		return i;
	}


	void copy ( float source[], float dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	Item()
	{
		this->parameter = 0;
//		copy( {}, this->parameter2 ); // You edit this
		this->parameter1 = false;

		this->is_empty = true;
	}

	Item ( int parameter, float parameter2[], bool parameter1 )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		this->parameter1 = parameter1;

		 this->is_empty = true;
	}


	// Getters:
	int get_parameter() { return this->parameter; };
	void get_parameter2( float dest[] ) { copy( this->parameter2, dest ); };
	bool get_parameter1() { return this->parameter1; };

	bool get_is_empty() { return this->is_empty; }

	int get_parameter2_count() { return this->parameter2_count; }

	void get ( int parameter, float parameter2[], bool parameter1 )
	{
		parameter = this->parameter;
		copy( this->parameter2, parameter2 );
		parameter1 = this->parameter1;
	}


	// Setters:
	void set_parameter( int data ) { this->parameter = data; this->is_empty = false;  };
	void set_parameter2( float data[] ) { copy( data, this->parameter2 ); this->is_empty = false;  };
	void set_parameter1( bool data ) { this->parameter1 = data; this->is_empty = false;  };

	void set_parameter2_count( int data ) { this->parameter2_count = data; }

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
		cout << "\nclass Item " << "{" << '\n';
		cout << "	int" << ' ' << "parameter = " << parameter << '\n';
		cout << "	int parameter2_count = " << parameter2_count << '\n';
		cout << "	float" << ' ' << "parameter2[10] = { ";
		for ( int i=0; i<parameter2_count; i=i+1 )
			cout << "'" << parameter2[i] << "' ";
		cout << "}\n";

		cout << "	bool" << ' ' << "parameter1 = " << parameter1 << '\n';
	 	cout << '}' << "\n\n";
	}

};



Item item_entries[10000];
int iter = 0;


int delete_entries[10000]; // the entries that are to be removed
int delete_iter = 0;

// Make entry
Item make_entry ()
{
	Item entry;

	cout << "\n";

	int counter = 0;

	cout << "Enter val. for \'parameter\' of type \'int\': ";

	int temp_int;

	cin >> temp_int;
	entry.set_parameter( temp_int );

	float temp[10000] = {};

	counter = 0;
	cout << "Enter num. or val.-s you want to enter for \'parameter2[10]\' of type \'float\': ";
	cin >> counter;

	for ( int i=0; i<counter; i=i+1 )
	{
		cout << "Enter val. " << i + 1 << ": ";
		cin >> temp[i]; // null val.-s do not pass this
	}

	entry.set_parameter2( temp );
	entry.set_parameter2_count ( counter );

	cout << "Enter val. for \'parameter1\' of type \'bool\' ( 1 / 0 ): ";

	bool temp_bool;

	cin >> temp_bool;
	entry.set_parameter1( temp_bool );

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

	for ( int i=0; i<iter; i=i+1 )
	{
		entries << item_entries[i].get_parameter() << " ";

		float temp[10000];
		item_entries[i].get_parameter2( temp );
		int size_of_temp = item_entries[i].get_parameter2_count();
		entries << "  " << size_of_temp << "  ";

		for ( int i=0; i<size_of_temp; i=i+1 )
			entries << temp[i] << ' ';
		entries << "  ";

		entries << item_entries[i].get_parameter1() << " ";

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

	int counter;

	for ( int i=0; i<iter; i=i+1 )
	{
		int temp_int;

		entries >> temp_int;
		item_entries[i].set_parameter( temp_int );
		float temp[10000] = {};

		counter = 0;
		entries >> counter;

		for ( int i=0; i<counter; i=i+1 )
		{
			entries >> temp[i]; // null val.-s do not pass this
		}

		item_entries[i].set_parameter2( temp );
		item_entries[i].set_parameter2_count ( counter );
		bool temp_bool;

		entries >> temp_bool;
		item_entries[i].set_parameter1( temp_bool );
	}
	entries.close();
}


// Is to be removed
bool is_in_delete_entries (int a)
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
		cout << "Entry num. '" << i + 1 << "' is to be removed.\n" ;
		return;
	}
		cout << item_entries[i].get_parameter() << " ";

		float temp[10000];
		item_entries[i].get_parameter2( temp );
		int size_of_temp = item_entries[i].get_parameter2_count();
		cout << "  " << size_of_temp << "  ";

		for ( int i=0; i<size_of_temp; i=i+1 )
			cout << temp[i] << ' ';
		cout << "  ";

		cout << item_entries[i].get_parameter1() << " ";

	cout << "\n";

}



int main()
{
	get_entries();

	string choice = "";

	for ( int i=0; i<100000; i=i+1 )
	{
		cout << "\n\n";
		cout << "Operation num. " << i + 1 << "\n";
		cout << "Operations:\n";
		cout << "	1. Add entry\n";
		cout << "	2. Show entry\n";
		cout << "	3. Show entries - complete\n";
		cout << "	4. Show entries\n";
		cout << "	5. Remove entry\n";
		cout << "	6. Remove entries\n";
		cout << "	7. Clear entries\n";
		cout << "	exit. Exit\n";


		cout << "\nEnter your choice: ";
		cin >> choice;

		if ( choice == "1" )
		{
			Item entry;
			entry = make_entry();
			entry.info();
			add_entry(entry);
		}

		if ( choice == "2" )
		{
			int i;
			cout << "Enter num. of entry: ";
			cin >> i;
			show_entry(i - 1);
		}

		if ( choice == "3" )
		{
			if ( iter == 0 )
				cout << "Entries are empty.\n";
			else
				for ( int i=0; i<iter; i=i+1 )
					show_entry(i);
		}

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

			for ( int i=num-1; i>=0; i=i-1 )
				show_entry( digits[i] - 1 );
		}

		if ( choice == "5" )
		{
			int i;
			cout << "Enter num. of entry: ";
			cin >> i;
			delete_entries[ delete_iter ] = i - 1;
			delete_iter = delete_iter + 1;
			cout << "Entry is to be deleted when you \'exit\'.";
		}

		if ( choice == "6" )
		{
			int int_entries;
			cout << "Enter num.-s or entries ( 142, 1542 etc. ): ";
			cin >> int_entries;

			while ( int_entries != 0 )
			{
				delete_entries[ delete_iter ] = int_entries % 10 - 1;
				delete_iter = delete_iter + 1;
				int_entries = int_entries / 10;
			}
			cout << "Entries are to be deleted when you \'exit\'.";
		}

		if ( choice == "7" )
		{
			iter = 0;
			cout << "Entries are to be deleted when you \'exit\'.";
		}

		if ( choice == "exit" )
		{
			break;
		}

		choice = "";

	}

	add_entries();

	return 0;

}
