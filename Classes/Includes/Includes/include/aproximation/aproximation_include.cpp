#include "../../includes.cpp"

#include "../../length.cpp"

#include "../../aproximation.cpp"

int main ()
{
	int num, pos;
	cout << "Num.: ";
	cin >> num;
	cout << "Posit.: ";
	cin >> pos;

	cout << aproximation( num, pos );
	cout << "\n";

	return 0;
}
