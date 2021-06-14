#include "../../includes.cpp"

#include "../../linuxfile.cpp"

int main () 
{
	// make copy, mrge, (folder), flnme endng, rnme files

	make_empty_linux_file ( "file2" );
	empty_and_check ( "file1.sh" );
	compile ( "file.sh" );

	string filenames[3] = { "1.sh", "2.sh" };

	make_empty_linux_file( filenames );

	enter( "1.sh", "echo File 1.sh compiled." );
	enter( "2.sh", "echo File 2.sh compiled." );

	compile ( filenames );

	cout << endl << endl;




	Linuxfile linux_file;
	// vazut cum se face initializare cu name

	linux_file.setName( "linux_file" );

	linux_file.make_empty_linux_file();

	



	Linuxfile linux_file1, linux_file2;

	linux_file1.setName( "linux_file1" );
	linux_file2.setName( "linux_file2" );

	linux_file1.enter( "echo linux_file1\ncompiles." );
	linux_file2.enter( "echo linux_file2\ncompiles." );

	cout << "\'" << linux_file1.getFile() << "\'" << endl;
	cout << linux_file2.getFile() << endl;

	linux_file1.enter( "echo linux_file1 compiles" );
	linux_file2.enter( "echo linux_file2 compiles" );

	Linuxfile Linuxfiles[3] = { linux_file1, linux_file2 };

	compile( Linuxfiles );



	make_empty_linux_file( Linuxfiles );


	return 0;	
}
