#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../empty.cpp" // length
#include "../../swap.cpp"
#include "../../last.cpp"
#include "../../lists.cpp"
#include "../../convert.cpp"
#include "../../a_is_in_b.cpp" // empty
#include "../../sort.cpp" // a_is_in_b, length, last, swap

#include "../../digits.cpp"


int main ()
{


	// int


	cout << "// int ( same as long )\n";
	int num_digits_int[1000];
	int a_int = 4194;
	
	digits( a_int, num_digits_int );
	for ( int i=0; i<length( a_int ); i=i+1 )
		cout << "\'" << num_digits_int[i] << "\' ";
	cout << "\n";

	cout << count_digits( a_int , 4 ) << "\n";


	// double ( same as float ).


	cout << "// double ( same as float )\n";
	int num_digits_double[1000];
	double a_double = 12.9104;
	digits( a_double, num_digits_double );

	for ( int i=0; i<7; i=i+1 )
		cout << "\'" << num_digits_double[i] << "\' ";
	cout << "\n";

	cout << double_digits_int( a_double ) << "\n";
	cout << double_decimals_int( a_double ) << "\n";

	cout << length( a_double ) << "\n";
	cout << length_decimals( a_double ) << "\n";

	cout << count_digits( a_double , 1 ) << "\n";
	

	return 0;
}
