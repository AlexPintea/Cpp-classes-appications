#include <string>
#include <string.h>
#include <iostream>

using namespace std;

class Item {

	// "Item" has parameters: parameter, parameter2[10], parameter1 

	// Parameters:
	int parameter;
	float parameter2[10];
	bool parameter1;

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


  public:

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
	float get_parameter2( float dest[] ) { copy( this->parameter2, dest ); };
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
