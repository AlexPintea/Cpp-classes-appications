#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter", "parameter2[10]", "parameter1" };
string columns[4] = { "parameter", "parameter2[10]", "parameter1" };
string types[4] = { "int", "float", "bool" };

class Item1 {

	// "Item1" has parameters: parameter, parameter2[10], parameter1 

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

	Item1()
	{
		this->parameter = 0;
//		copy( {}, this->parameter2 ); // You edit this
		this->parameter1 = false;

		this->is_empty = true;
	}

	Item1 ( int parameter, float parameter2[], bool parameter1 )
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
			cout << "\n(get) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[10]'. Its size is '" << parameter2_count << "'. 0 was returned.\n";
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
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter2[10]'. Its size is '" << parameter2_count << "'. It was not modified.\n";
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
		cout << "\nclass Item1 " << "{" << '\n';
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


int main ()
{

	return 0;
}
