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
	float parameter2[10];
	bool parameter1;

  public:


	int length ( float data[] )
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







	bool is_empty()
	{
		if ( this->parameter == 0 )
			return true;
		return false;
	}





	Item()
	{
		this->parameter = 0;
		copy( {}, this->parameter2 );
		this->parameter1 = false;
	}

	Item ( int parameter, float parameter2[], bool parameter1 )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		this->parameter1 = parameter1;
	}


	// Getters:
	int get_parameter() { return this->parameter; };
	void get_parameter2( float dest[] ) { copy( this->parameter2, dest ); };
	bool get_parameter1() { return this->parameter1; };

	void get ( int parameter, float parameter2[], bool parameter1 )
	{
		parameter = this->parameter;
		copy( this->parameter2, parameter2 );
		parameter1 = this->parameter1;
	}


	// Setters:
	void set_parameter( int data ) { this->parameter = data; };
	void set_parameter2( float data[] ) { copy( data, this->parameter2 ); };
	void set_parameter1( bool data ) { this->parameter1 = data; };

	void set ( int parameter, float parameter2[], bool parameter1 )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		this->parameter1 = parameter1;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item " << '{' << '\n';
		cout << "	int" << ' ' << "parameter" << '\n';
		cout << "	float" << ' ' << "parameter2[10]" << '\n';
		cout << "	bool" << ' ' << "parameter1" << '\n';
	 	cout << '}' << "\n\n";
	}


};


// Length of the Item-s
int length ( Item data[] )
{
	int i = 0;
	while ( data[i].is_empty() == false )
		i=i+1;

	return i;
}



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

	float temp[10000];

	counter = 0;
	cout << "Enter num. or val.-s you want to enter for \'parameter2[10]\' of type \'float\': ";
	cin >> counter;

	for ( int i=0; i<counter; i=i+1 )
	{
		cout << "Enter val. " << i + 1 << ": ";
		cin >> temp[i];
	}

	entry.set_parameter2( temp );

	cout << "Enter val. for \'parameter1\' of type \'bool\': ";

	bool temp_bool;

	cin >> temp_bool;
	entry.set_parameter1( temp_bool );

	cout << "\n\n";

	return entry;
}

// Add entry
void add_entry ( Item entry, Item item_entries[] )
{
	ofstream entries;
	entries.open("item_entries.txt");

	entries << "\n";
	int size = length( item_entries ) + 1;


	item_entries[ size ].set_parameter( entry.get_parameter() );
	entries << entry.get_parameter() << " ";

	float temp[10000];
	entry.get_parameter2( temp );
	item_entries[ size ].set_parameter2( temp );
	int size_of_temp = entry.length( temp );
	for ( int i=0; i<size_of_temp; i=i+1 )
		entries << temp[i] << ' ';


	item_entries[ size ].set_parameter1( entry.get_parameter1() );
	entries << entry.get_parameter1() << " ";


	entries.close();
}


// Show entry by line num.
void show_entry ( int a, Item item_entries[] )
{
	cout << item_entries[a].get_parameter() << ' ';

	float temp[10000];

	item_entries[a].get_parameter2( temp );
	int size = item_entries[a].length( temp );

	for ( int i=0; i<size; i=i+1 )
		cout << temp[i] << ' ';

	cout << item_entries[a].get_parameter1() << ' ';
}




int main()
{
	fstream entries;

	Item item_entries[10000];

	entries.open( "item_entries.txt" );

	string choice = "";

	while ( choice != "exit" )
	{
		cout << "\n\n";
		cout << "Operations:\n";
		cout << "	1. Add entry\n";
		cout << "	exit. Exit\n";


		cout << "\nEnter your choice: ";
		cin >> choice;

		if ( choice == "1" )
		{
			Item entry;
			entry = make_entry();
			add_entry(entry, item_entries);
		}

	}

	entries.close();

	return 0;

}
