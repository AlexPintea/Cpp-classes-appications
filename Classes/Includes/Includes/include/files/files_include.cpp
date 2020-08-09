#include "../../includes.cpp"

#include "../../files.cpp"

int main ()
{

//	cout << file_count( "files" ) << "\n"; // makes file "files_counter"

//	make_file( "file_1" );

//	add_to_file( "file_1", "data\n\n\n" );

//	copy_file_count ( "file_1" );
//	string filename = "filename.css";
//	string ext;
//	string filepath;


//	filename_ext_filepath( filename, ext, filepath );

//	cout << "Filename: " << filename << "\n";
//	cout << "Ext: " << ext << "\n";

	string strings[ 10000 ];

	get_file( "file", strings, ".," );

	int i = 0;
	while ( strings[ i ].length() > 0 )
	{
		cout << i + 1 << ". '" << strings[ i ] << "'\n";
		i = i + 1;
	}
//	clear_file( "file_1" );

	return 0;
}
