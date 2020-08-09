#include "../../includes.cpp"

#include "../../length.cpp"

#include "../../asc_desc.cpp"

int main ()
{
	cout << is_asc( (int) 145 ) << "\n";
	cout << is_asc( (int) 74 ) << "\n";

	int a[10] = { 1, 4, 7, 9 };
	int b[10] = { 1, 4, 7, 9 };

	cout << is_asc( a ) << "\n";
	cout << is_desc( b ) << "\n";

	return 0;
}
