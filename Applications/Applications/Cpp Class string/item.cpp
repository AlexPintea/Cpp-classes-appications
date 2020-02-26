#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 0;
string parameters[1] = { };
string columns[1] = { };
string types[1] = { };

class Item {

	// "Item" has parameters: 

	// Parameters:

	bool is_empty;

  public:



	Item()
	{

		this->is_empty = true;
	}

	Item ( )
	{

		this->is_empty = true;
	}


	// Getters:

	bool get_is_empty() { return this->is_empty; }

	void get ( )
	{
	}


	// Setters:

	void set ( )
	{

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Item " << "{" << '\n';
	 	cout << '}' << "\n\n";
	}

};


int main ()
{

	return 0;
}
