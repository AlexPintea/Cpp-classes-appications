#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string sw ( int w )
{
	string result = "";

	for ( int i = 0; i < w; i = i + 1 )
		result = result + ' ';

	return result;
}

string sw ( char f, int w )
{
	string result = "";

	for ( int i = 0; i < w; i = i + 1 )
		result = result + f;

	return result;
}

float mul ( float a, float b )
{
	float a_float = a;
	for ( int i = 1; i < b; i = i + 1 )
		a = a + a_float;
	return a;
}

int mul ( int a, int b )
{
	int a_int = a;
	for ( int i = 1; i < b; i = i + 1 )
		a = a + a_int;
	return a;
}

float prec ( float a, int p )
{
	float result;
	int tens = 1;
	for ( int i = 0; i < p; i = i + 1 )
	{
		a = mul( a, 10.0 );
		tens = mul( tens, 10 );
	}

	int a_int = (int) a;

	result = (float) a_int / tens;

	return result;
}


int main ()
{
	cout << sw( 5 ) << "- width of 5 set\n";
	cout << sw( '/', 5 ) << "- width of 5 set\n";

	cout << prec( 15.2421, 3 ) << '\n';

	return 0;
}
