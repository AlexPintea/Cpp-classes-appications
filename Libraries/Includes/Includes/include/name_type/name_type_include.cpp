#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../empty.cpp" // length
#include "../../last.cpp" // length
#include "../../convert.cpp" // length, empty
#include "../../leave_remove.cpp" // empty, last

#include "../../name_type.cpp"

int main ()
{
	int b[104][70][29];

	cout << get_type(b) << "\n";
	cout << get_name(b) << "\n";
	cout << type( get_type(b) ) << "\n";
	cout << size( get_type(b) ) << "\n";



	//  int is enough for sizes:
	//	bool b[7299999]; // as much as an [] can have ( add 1, and its Segm. fault )
	//	int a_int = 7299999;
	//	cout << a_int << "\n\n"; // could be stored in an int. 

	// get sizes as int
	int sizes[190];

	size( get_type(b), sizes );

	int i=0; 
	while ( sizes[i] ) 
	{
		cout << sizes[i] << " ";
		i=i+1;
	} 
	cout << "\n";



	cout << type_size( get_type(b) ) << "\n";
	cout << type_name( get_type(b), get_name(b) ) << "\n";
	cout << name_size( get_type(b), get_name(b) ) << "\n";
	cout << type_name_size( get_type(b), get_name(b) ) << "\n\n";



	cout << get_type(verif_int_double) << "\n";
	cout << get_name(verif_int_double) << "\n";
	cout << subprogram_parameter_types( get_type( verif_int_double ) ) << "\n";
	cout << subprogram_return_type( get_type( verif_int_double ) ) << "\n";

	cout << subprogram_name_parameter_types( get_type( verif_int_double ), get_name( verif_int_double ) ) << "\n";
	cout << subprogram_return_type_name( get_type( verif_int_double ), get_name( verif_int_double ) ) << "\n";
	cout << subprogram_return_type_name_parameter_types( get_type( verif_int_double ), get_name( verif_int_double ) ) << "\n";

	return 0;
}
