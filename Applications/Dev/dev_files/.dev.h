#include "commits/.files/commit.h"
#include ".maker_folder/maker_files/maker.h"
#include ".deb/deb.h"

void make_file_e ( string filename )
{
	string ext;
	string filepath;

	filename_ext_filepath_maker( filename, ext, filepath );

	ofstream fo;

	fo.open( "e" );
	fo.close(); // make / clear file

	fo.open( "e" );

	fo << "printf \"\\033c\"\n\nif test -f \"Makefile\"\nthen\n	make -s\n	./" << filename << "\n	rm -r " << filename << "\nelse\n	g++ -L a.out " << filename << ".cpp\n	./a.out\n	rm -r a.out\nfi\n\nif test -f \"" << filename << "\"\nthen\n	rm -r " << filename << "\nfi\n\nif test -f \"a.out\"\nthen\n	rm -r a.out\nfi";

	fo.close();

	command_deb( "chmod 767 e" );
}

void remake ( string filename )
{
	save ( filename );
	makefile ( filename );
	make_file_e ( filename );
	deb ( filename );
	cout << "( info ) Made: makefile, file 'e' and deb.\n";
	cout << filename << ":\n               ( empty line )\n";
}




void make ( string filename )
{
	save ( filename );
	deb ( filename );
	cout << "( info ) Made deb file and added for later commit.\n";
	cout << filename << ":\n                 ( empty line )\n";
}
