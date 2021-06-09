#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 1;
string parameters[2] = { "fle" };
string columns[2] = { "fle" };
string types[2] = { "int" };

class Fle {

	// "Fle" has parameters: fle 

	// Parameters:
	int fle;

	bool is_empty;

  public:







	Fle()
	{
		this->fle = 0;

		this->is_empty = true;
	}

	Fle ( int fle )
	{
		this->fle = fle;

		this->is_empty = true;
	}


	// Getters:
	int get_fle() { return this->fle; };

	bool get_is_empty() { return this->is_empty; }

	void get ( int fle )
	{
		fle = this->fle;
	}


	// Setters:
	void set_fle( int data ) { this->fle = data; this->is_empty = false;  };

	void set ( int fle )
	{
		this->fle = fle;

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Fle " << "{" << '\n';
		cout << "	int" << ' ' << "fle = " << fle << '\n';
	 	cout << '}' << "\n\n";
	}

};


int main ()
{

	return 0;
}
