#include "../../includes.cpp"

#include "../../brackets.cpp"

int main ()
{

	double a_double[14][14] = { 1,   4.1, 2.7,
					            4.9, 3,   2, 
					            3,   0.1, 2  };

	string a_string[14][14] = { "a", "ab", "bl",
					            "b", "b",  "p", 
					            "o", "l",  "m"  };

	char a_char[14][14] = { '1', 'a', 'p',
					        'b', 'p', 'm', 
					        '7', 'l', 'r'  };



	cout << sizeof(a_double) / sizeof(a_double[0]) << "\n\n";

	cout << length_1(a_double) << "\n";
	cout << length_2(a_double) << "\n\n";

	cout << maximum(a_double) << "\n";
	cout << maximum(a_string) << "\n";
	cout << maximum(a_char) << "\n";


	int i=0;
	string arr_string[1000];
	arr( a_string, arr_string );
	while ( arr_string[i].length() > 0 )
	{
		cout << arr_string[i] << " ";
		i = i + 1;
	}
	cout << "\n\n";

	double l_string[7][9];
	double l_arr[1000] = { 1, 4, 3, 2, 4, 5, 3, 2, 6,      3, 2, 5, 6, 4, 2, 3, 9, 4,      3, 1, 5, 1, 4, 2, 3, 1, 9 };

	arr_invert( l_arr, l_string );

	cout << length_1(l_string) << "\n";
	cout << length_2(l_string) << "\n";


	for ( int i=0; i<length_1( l_string ); i=i+1 )
	{
		for ( int l=0; l<length_2( l_string ); l=l+1 )
			cout << l_string[i][l] << "  ";
		cout << "\n";
	}
	cout << "\n";

	return 0;
}
