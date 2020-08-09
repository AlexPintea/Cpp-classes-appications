
void filename_ext_filepath_maker ( string &filename, string &ext, string &filepath )
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
		if ( filename[ i ] == '.' )
		{
			have_ext = true;
			break;
		}

	if ( ! have_ext )
		return;

	int d = 0;
	for ( int i = filename.length() - 1; i >= 0; i = i - 1 )
		if ( filename[ i ] != '/' )
			d = i;
		else
			break;

	filepath = "";
	for ( int i = 0; i < d; i = i + 1 )
		filepath = filepath + filename[ i ];

	string file_name = "";
	int l = 0;
	for ( int i = d; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}

		file_name = file_name + filename[ i ];
	}

	for ( int i = l; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' ) continue;	

		ext = ext + filename[ i ];
	}

	filename = file_name;
}





void makefile ( string filename )
{
	// makes the file
	ofstream fo;
	fo.open( "Makefile" );
	fo.close();

	fo.open( "Makefile" );

	string ext;
	string filepath;

	filename_ext_filepath_maker( filename, ext, filepath );

	fo << filename << ": " << filename << ".o\n";
	fo << "	g++ " << filename << ".o -o " << filename << "\n";
	fo << "	rm -f " << filename << ".o\n\n";
	fo << filename << ".o: " << filename << ".cpp\n";
	fo << "	g++ -c " << filename << ".cpp\n\n";
	fo << "clean:\n";
	fo << "	rm -f " << filename << "\n";
	fo << "	rm -f " << filename << ".o";

	fo.close();	
}

