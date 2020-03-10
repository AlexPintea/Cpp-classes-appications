#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int num_parameters = 1;
string parameters[2] = { "class_parameter" };
string columns[2] = { "class_parameter" };
string types[2] = { "int" };

class Class 9 : public Inheritance_1 // include it
{

	// "Class 9" has parameters: class_parameter 

	// Parameters:
	int class_parameter;

	bool is_empty;

  public:







	Class 9()
	{
		this->class_parameter = 0;

		this->is_empty = true;
	}

	Class 9 ( int class_parameter )
	{
		this->class_parameter = class_parameter;

		this->is_empty = false;
	}

	Class 9 ( Class 9 &Class 9 )
	{
		this->class_parameter = Class 9.class_parameter;

		this->is_empty = false;
	}


	// Getters:
	int get_class_parameter() { return this->class_parameter; };

	bool get_is_empty() { return this->is_empty; }

	void get ( int class_parameter )
	{
		class_parameter = this->class_parameter;
	}


	// Setters:
	void set_class_parameter( int data ) { this->class_parameter = data; this->is_empty = false;  };

	void set ( int class_parameter )
	{
		this->class_parameter = class_parameter;

	 	this->is_empty = false;
	}

	// Info:
	void info()
	{
		cout << "\nclass Class 9 " << "{" << '\n';
		cout << "	int" << ' ' << "class_parameter = " << class_parameter << '\n';
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
