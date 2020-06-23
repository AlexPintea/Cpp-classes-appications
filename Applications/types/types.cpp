#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

bool is_numeric ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= '0' and a[i] <= '9' ) or a[i] == '.' ) )
			return false;

	return true;
}

bool has_decimals ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == '.' )
			return true;

	return false;
}

string datatype ( string a )
{
	if ( is_numeric( a ) )
	{
		if ( has_decimals( a ) )
		{
			return "double";
		}
		else
		{
			if ( a.length() <= 9 )
			{	
				if ( a == "1" or a == "0" )
					return "bool";
				else
					return "int";
			}
			else
				return "long";
		}
	}
	else
	{
		if ( a.length() == 1 )
			return "char";
		else
		{
			if ( a == "true" or a == "false" )
				return "bool";
			else
				return "string";
		}
	}

	return "-1";
}

int main ()
{
	string a;
	cout << "Datatype: ";
	getline( cin, a );

	cout << datatype( a );

	cout << "\n";

	return 0;
}
