#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter", "parameter2[1000]", "parameter1[1000][1000][1000][1000][1000]" };
string columns[4] = { "parameter", "parameter2[1000]", "parameter1[1000][1000][1000][1000][1000]" };
string types[4] = { "int", "float", "string" };

class Item\ {

	// "Item\" has parameters: parameter, parameter2[1000], parameter1[1000][1000][1000][1000][1000] 

	// Parameters:
	int parameter;
	int parameter2_count;
	float parameter2[1000];
	int parameter1_count;
	string parameter1[1000][1000][1000][1000][1000];
	string parameter1_data[1000];

	bool is_empty;

  public:


	int length ( float data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] != '\0' )
			i=i+1;

		return i;
	}

	int length ( string data[] ) // returns length + 1, returning i - 1 does not help
	{
		return data.length();
	}


	void set_parameter1_to_its_data ( string parameter1_data[], string parameter1[][1000][1000][1000][1000] )
	{
		int i = 0;

		while ( parameter1_data[i]  )
		{
			parameter1[i] = parameter1_data[i];
			i = i + 1;
		}
	}



	void copy ( float source[], float dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	void copy ( string source[], string dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	Item\()
	{
		this->parameter = 0;
		copy( NULL, this->parameter2 ); // You edit this
		copy( NULL, this->parameter1_data ); // You edit this

		this->is_empty = true;
	}

	Item\ ( int parameter, float parameter2[], string parameter1[]_data )
	{
		this->parameter = parameter;
, this->parameter );
		copy( parameter2, this->parameter2 );
		copy( parameter1_data, this->parameter1 );

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
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[1000]'. Its size is '" << parameter2_count << "'. 0 was returned.\n";
			return 0;
		}
	}
	int get_parameter2_count() { return this->parameter2_count; }
	void get_parameter1_data( string dest[] ) { copy( this->parameter1_data, dest ); };
	string get_parameter1_data( int i ) // get parameter1_data[i]
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

	bool get_is_empty() { return this->is_empty; }

	void get ( int parameter, float parameter2[], string parameter1[]_data )
	{
		parameter = this->parameter;
		copy( this->parameter2, parameter2 );
		copy( this->parameter1_data, parameter1 );
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
	void set_parameter1_data( string data[] ) { copy( data, this->parameter1 ); this->is_empty = false;  };
	void set_parameter1_data( string data, int i ) // set parameter1[i] to data
	{
		if ( i < parameter1_count and i >= 0 )
			parameter1[i] = data;
		else
		{
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter1[1000][1000][1000][1000][1000]'. Its size is '" << parameter1_count << "'. It was not modified.\n";
		}
	}
	void set_parameter1_data_count( int data ) { this->parameter1_count = data; }

	void set ( int parameter, float parameter2[], string parameter1[]_data )
	{
		this->parameter = parameter;
		copy( parameter2, this->parameter2 );
		copy( parameter1_data, this->parameter1 );

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item\ " << "{" << '\n';
		cout << "	int" << ' ' << "parameter = " << parameter << '\n';
		cout << "	int parameter2_count = " << parameter2_count << '\n';
		cout << "	float" << ' ' << "parameter2[1000] = { ";
		for ( int i=0; i<parameter2_count; i=i+1 )
			cout << "'" << parameter2[i] << "' ";
		cout << "}\n";

		cout << "	int parameter1_data_count = " << parameter1_count << '\n';
		cout << "	string" << ' ' << "parameter1[1000][1000][1000][1000][1000] = { ";
		for ( int i=0; i<parameter1_count; i=i+1 )
			cout << "'" << parameter1[i] << "' ";
		cout << "}\n";

	 	cout << '}' << "\n\n";
	}

};


int main ()
{

	return 0;
}
