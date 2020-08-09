#include "../../includes.cpp"

#include "../../length.cpp"

#include "../../for_each.cpp"

void half ( int &a )
{
	a = a / 2;
}

int main ()
{

	int a_ints[10] = { 2, 4, 6, 8 };

	for_each ( a_ints, half );

	for ( int i=0; i<length(a_ints); i=i+1 )
		cout << "\'" << a_ints[i] << "\'";
	cout << "\n";

	return 0;
}
