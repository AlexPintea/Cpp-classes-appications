#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 1;
string parameters[2] = { "1" };
string columns[2] = { "1" };
string types[2] = { "int" };

class Class_1 : public Inheritance // include it
{

	// "Class_1" has parameters: 1 

	// Parameters:
	int 1;

	bool is_empty;

  public:







	Class_1()
	{
		this->1 = 0;

		this->is_empty = true;
	}

	Class_1 ( int 1 )
	{
		this->1 = 1;

		this->is_empty = false;
	}

	Class_1 ( Class_1 &class_1 )
	{
		this->1 = class_1.1;

		this->is_empty = false;
	}


	// Getters:
	int get_1() { return this->1; };

	bool get_is_empty() { return this->is_empty; }

	void get ( int 1 )
	{
		1 = this->1;
	}


	// Setters:
	void set_1( int data ) { this->1 = data; this->is_empty = false;  };

	void set ( int 1 )
	{
		this->1 = 1;

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Class_1 " << "{" << '\n';
		cout << "	int" << ' ' << "1 = " << 1 << '\n';
	 	cout << '}' << "\n\n";
	}



	virtual void sub1 (  ) = 0;
	void sub (  )	{
		// implementation
	}

	virtual void sub9 (  ) = 0;
};


int main ()
{

	return 0;
}
