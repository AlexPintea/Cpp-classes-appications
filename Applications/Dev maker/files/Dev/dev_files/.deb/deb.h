void command_deb ( string a )
{
	char result[ 1000 ];
	int size = a.length();
	int i;
	for ( i = 0; i < size; i = i + 1)
		result[ i ] = a[ i ];
	
	result[ i ] = '\0';

	system( result );
}

string large_char_deb ( string a )
{
	if ( a[0] >= 'a' and a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}

void make_desktop_deb ( string filename )
{

	// makes / clears the file
	ofstream file;
	file.open( filename + ".desktop" );
	file.close();


	file.open( filename + ".desktop" );

	file << "[Desktop Entry]\n";
	file << "Name=" << large_char_deb( filename ) << "\n";
	file << "Exec=gnome-terminal -e /usr/my_debs/" << filename << "\n";
	file << "Icon=utilities-terminal\n";
	file << "Type=Application";


	file.close();	
}

int deb ( string filename )
{
	string ext;
	string filepath;

	filename_ext_filepath_maker( filename, ext, filepath );

	make_desktop_deb( filename );

	// makes / clears file
	ofstream deb_sh;
	deb_sh.open( "deb-sh" );
	deb_sh.close();

	deb_sh.open( "deb-sh" );
	deb_sh << filename;
	deb_sh.close();	

	command_deb( "./dev_files/.deb/deb.sh" );

	return 0;
}

// void install ( string filename )
// {
//	string ext;
//	string filepath;
//	filename_ext_filepath( filename, ext, filepath );
//	command_deb( "dpkg -i " + filename + ".deb" );	
// }
