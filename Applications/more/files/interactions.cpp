#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Class
{
	string name = "Class";
	double param;

  public:

	Class(){}

	string get_name()
	{
		return this->name;
	}

	double get_param()
	{
		return this->param;
	}

	void set_param( double data )
	{
		if ( data > 10 )
		{
			this->param = 10;
			return;
		}
		if ( data < 9 )
		{
			this->param = 9;
			return;
		}
		this->param = data;
	}

};
int num_class = 1;




int length( string a[] )
{
	int i=0;

	while ( a[i].length() > 0 )
		i = i + 1;

	return i;
}


int main()
{

	string class_parameters[] = { "param" };
	Class classs[ num_class  + 1 ];
	for ( int i=0; i<num_class; i=i+1 )
	{
		classs[i].set_param ( ( i + 10 ) % 1 + 9 );
	}

	cout << "Interactions not available for 1 class\n";
	ofstream fo_0;
	fo_0.open( "interaction/class/class" );
	fo_0.close();

	fo_0.open( "interaction/class/class" );
	for ( int i=0; i<num_class; i=i+1 )
	{
		fo_0 << classs[i].get_param() << ' ';
  		fo_0 << '\n';
	}
	fo_0.close();

	return 0;
}