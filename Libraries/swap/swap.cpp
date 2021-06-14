#include <string>
#include <iostream>
#include <fstream>

using namespace std;



void swap (int &a, int &b)
{
	int aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (long &a, long &b)
{
	long aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (float &a, float &b)
{
	float aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (double &a, double &b)
{
	double aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (bool &a, bool &b)
{
	bool aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (char &a, char &b)
{
	char aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (string &a, string &b)
{
	string aux;

	aux = a;
	a = b;
	b = aux;
}







int main ()
{
	int a = 10;
	int b = 5;

	swap( a, b );

	cout << a;
}
