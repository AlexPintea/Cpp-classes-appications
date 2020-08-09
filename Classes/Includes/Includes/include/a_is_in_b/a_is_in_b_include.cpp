#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../empty.cpp" // length
#include "../../lists.cpp" // length
#include "../../last.cpp" // length
#include "../../convert.cpp" // length, last

#include "../../a_is_in_b.cpp"

int main()
{

	// ( info ) b in a is unidirectional 

	// a is in b


	cout << "// a is in b:\n";
	string a_string = "abaabb";
 	cout << remove_b_in_a ( a_string, "aab" ) << endl;
	string a_strings[20] = { "string1", "string2", "string3", "string4", "string5", "string6", "string7" };	
	string b_strings[20] = { "string4", "string5" };
	cout << a_is_in_b( a_strings, b_strings ) << endl;
	remove_b_in_a ( a_strings, b_strings );
	for ( int i=0; i<length(a_strings); i=i+1 )
		cout << a_strings[i] << "  ";
	cout << endl;

	char a_char[20] = { 'a', 'a', 'e', 'r', 'b', 'l', 'm', 'r', 'r', 'a' };
	char b_char[20] = { 'r', 'b', 'l', 'm' };
	cout << a_is_in_b( a_char, b_char ) << endl;
	remove_b_in_a ( a_char, b_char );
	for ( int i=0; i<length(a_char); i=i+1 )
		cout << "\'" << a_char[i] << "\' ";
	cout << endl;

	return 0;
}

