#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../empty.cpp" // length

#include "../../leave_remove.cpp"

int main()
{


	// leave / remove



	cout << "// chars leave / remove:\n";
	char leave_chars_char[20] = { '[', '1', 'b', '7', '9', 'l', '&' };
	leave_chars( leave_chars_char );\
	for ( int i=0; i<length(leave_chars_char); i=i+1 )
		cout << "\'" << leave_chars_char[i] << "\' ";
	cout << endl;

	char leave_numerics_char[20] = { '[', '1', 'b', '7', '9', 'l', '&' };
	leave_numerics( leave_numerics_char );\
	for ( int i=0; i<length(leave_numerics_char); i=i+1 )
		cout << "\'" << leave_numerics_char[i] << "\' ";
	cout << endl;

	char leave_data_char[20] = { '[', '1', 'b', '7', '9', 'l', '&' };
	leave_data( leave_data_char );\
	for ( int i=0; i<length(leave_data_char); i=i+1 )
		cout << "\'" << leave_data_char[i] << "\' ";
	cout << endl;


	cout << endl;


	cout << "// string leave / remove:\n";
	string leave_chars_string = "[1b79l&";
	cout << leave_chars( leave_chars_string ) << endl;
	string leave_numerics_string = "[1b79l&";
	cout << leave_numerics( leave_numerics_string ) << endl;
	string leave_data_string = "[1b79l&";
	cout << leave_data( leave_data_string ) << endl;

	return 0;
}

