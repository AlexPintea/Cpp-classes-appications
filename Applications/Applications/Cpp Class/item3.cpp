#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 3;
string parameters[4] = { "parameter[10]", "parameter2[10]", "parameter1[10]" };
string columns[4] = { "parameter[10]", "parameter2[10]", "parameter1[10]" };
string types[4] = { "int", "float", "char" };

class Item3 {

	// "Item3" has parameters: parameter[10], parameter2[10], parameter1[10] 

	// Parameters:
	int parameter_count;
	int parameter[10];
	int parameter2_count;
	float parameter2[10];
	int parameter1_count;
	char parameter1[10];

	bool is_empty;

  public:


	int length ( int data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] != '\0' )
			i=i+1;

		return i;
	}

	int length ( float data[] ) // returns length + 1, returning i - 1 does not help
	{
		int i = 0;
		while ( data[i] != '\0' )
			i=i+1;

		return i;
	}

	int length ( char data[] ) // returns length + 1, returning i - 1 does not help
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

	void copy ( float source[], float dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	void copy ( char source[], char dest[] )
	{
		for ( int i=0; i<length(source); i=i+1)
			dest[i] = source[i];
	}

	Item3()
	{
//		copy( {}, this->parameter ); // You edit this
//		copy( {}, this->parameter2 ); // You edit this
//		copy( {}, this->parameter1 ); // You edit this

		this->is_empty = true;
	}

	Item3 ( int parameter[], float parameter2[], char parameter1[] )
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
	void get_parameter1( char dest[] ) { copy( this->parameter1, dest ); };
	char get_parameter1( int i ) // get parameter1[i]
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

	void get ( int parameter[], float parameter2[], char parameter1[] )
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
	void set_parameter1( char data[] ) { copy( data, this->parameter1 ); this->is_empty = false;  };
	void set_parameter1( char data, int i ) // set parameter1[i] to data
	{
		if ( i < parameter1_count and i >= 0 )
			parameter1[i] = data;
		else
		{
			cout << "\n(set) Item at '" << i << "' ("<< i+1 << "-th) is not available in 'parameter1[10]'. Its size is '" << parameter1_count << "'. It was not modified.\n";
		}
	}
	void set_parameter1_count( int data ) { this->parameter1_count = data; }

	void set ( int parameter[], float parameter2[], char parameter1[] )
	{
		copy( parameter, this->parameter );
		copy( parameter2, this->parameter2 );
		copy( parameter1, this->parameter1 );

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item3 " << "{" << '\n';
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
		cout << "	char" << ' ' << "parameter1[10] = { ";
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
