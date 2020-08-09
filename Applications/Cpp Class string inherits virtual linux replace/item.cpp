#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter", "parameter2[1000]", "parameter1[1000][1000][1000][1000][1000]" };
string columns[4] = { "parameter", "parameter2[1000]", "parameter1[1000][1000][1000][1000][1000]" };
string types[4] = { "int", "float", "bool" };

class Item
{

	// "Item" has parameters: parameter, parameter2[1000], parameter1[1000][1000][1000][1000][1000] 

	// Parameters:
	int parameter;
	int parameter2_count;
	float parameter2[1000];
	int parameter1_count;
	bool parameter1[1000][1000][1000][1000][1000];
	bool parameter1_data[1000];
	int parameter1_data_count[70] = { 70, 70, 70, 70, 70 };

	bool is_empty;

  public:



	// for length of counters[], for getting and setting counters[]]

	int length ( int data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] != '\0' )
			i=i+1;

		return i;
	}

	void copy ( int source[], int dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}



	void increase_counters( int i[], int max_count[] )
	{
		int size = 0;
		while ( max_count[ size ] )
			size = size + 1;

		for ( int l=0; l<size-1; l=l+1 )
		{
			if ( i[l] == max_count[l] )
			{
				i[l] = 0;
				i[l + 1] = i[l + 1] + 1;
			}
			else
			{
				i[l] = i[l] + 1;
				break;
			}
		}
	}



	int length ( float data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] != '\0' )
			i=i+1;

		return i;
	}

	int length ( bool data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] != '\0' )
			i=i+1;

		return i;
	}


	void set_parameter1_to_its_data ( bool parameter1_data[], bool parameter1[][1000][1000][1000][1000] )
	{
		int i = 0;

		int l[ 7 ];

		for ( int i=0; i<7; i=i+1 )
			l[i] = 0;

		while ( parameter1_data[i] != false )
		{
			
			parameter1[ l[0] ][ l[1] ][ l[2] ][ l[3] ][ l[4] ] = parameter1_data[i];
 			increase_counters( l, parameter1_data_count );
			i = i + 1;
		}
	}



	void copy ( float source[], float dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	void copy ( bool source[], bool dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	Item()
	{
		this->parameter = 0;
		copy( NULL, this->parameter2 ); // You edit this
		copy( NULL, this->parameter1_data ); // You edit this

		this->is_empty = true;
	}

	Item ( int parameter, float parameter2[], bool parameter1_data[] )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		copy( parameter1_data, this->parameter1_data );

		this->is_empty = false;
	}

	Item ( Item &item )
	{
		this->parameter = item.parameter;
		copy( item.parameter2, this->parameter2 );
		copy( item.parameter1_data, this->parameter1_data );

		this->is_empty = false;
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
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[1000]'. Its size is '" << parameter2_count << "'. 0 was returned.\n";
			return 0;
		}
	}
	int get_parameter2_count() { return this->parameter2_count; }
	void get_parameter1_data( bool dest[] ) { copy( this->parameter1_data, dest ); };
	bool get_parameter1_data( int i ) // get parameter1_data[i]
	{
		if ( i < parameter1_count and i >= 0 )
			return parameter1_data[i];
		else
		{
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter1[1000][1000][1000][1000][1000]'. Its size is '" << parameter1_count << "'. 0 was returned.\n";
			return 0;
		}
	}
	int get_parameter1_count() { return this->parameter1_count; }
	void get_parameter1_data_count( int dest[] ) { copy( this->parameter1_data_count, dest ); };

	bool get_is_empty() { return this->is_empty; }

	void get ( int parameter, float parameter2[], bool parameter1_data[] )
	{
		parameter = this->parameter;
		copy( this->parameter2, parameter2 );
		copy( this->parameter1_data, parameter1_data );
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
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[1000]'. Its size is '" << parameter2_count << "'. It was not modified.\n";
		}
	}
	void set_parameter2_count( int data ) { this->parameter2_count = data; }
	void set_parameter1( bool data[] ) { copy( data, this->parameter1_data ); this->is_empty = false;  };
	void set_parameter1_item( bool data, int i ) // set parameter1[i] to data
	{
		if ( i < parameter1_count and i >= 0 )
			parameter1_data[i] = data;
		else
		{
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter1[1000][1000][1000][1000][1000]'. Its size is '" << parameter1_count << "'. It was not modified.\n";
		}
	}
	void set_parameter1_count( int data ) { this->parameter1_count = data; }
	void set_parameter1_data( int dest[] ) { copy( this->parameter1_data_count, dest ); };

	void set ( int parameter, float parameter2[], bool parameter1_data[] )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		copy( parameter1_data, this->parameter1_data );

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item " << "{" << '\n';
		cout << "	int" << ' ' << "parameter = " << parameter << '\n';
		cout << "	int parameter2_count = " << parameter2_count << '\n';
		cout << "	float" << ' ' << "parameter2[1000] = { ";
		for ( int i=0; i<parameter2_count; i=i+1 )
			cout << "'" << parameter2[i] << "' ";
		cout << "}\n";

		cout << "	int parameter1_data_count = " << parameter1_count << '\n';
		cout << "	bool" << ' ' << "parameter1[1000][1000][1000][1000][1000] = { ";
		for ( int i=0; i<parameter1_count; i=i+1 )
			cout << "'" << parameter1[i] << "' ";
		cout << "}\n";

	 	cout << '}' << "\n\n";
	}



	void subprogram ( int parameter_0 )
	{
		// implementation
	}

};


int main ()
{

	return 0;
}
