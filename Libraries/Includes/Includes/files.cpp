

string get_file ( string filename );
void set_file ( string filename, string data );

// make a file
void make_file ( string filename )
{
	string previous_file_data = get_file( filename );

	if ( previous_file_data != "" )
		return;

	ofstream f; // have to have ofstream
	f.open( filename );
	f.close();
}

// clear a file
void clear_file ( string filename )
{
	string previous_file_data = get_file( filename );

	if ( previous_file_data == "" )
		return;

	ofstream f; // have to have ofstream
	f.open( filename );
	f.close();
}













// rename a file
void rename_file ( string filename_1, string filename_2 )
{
	string file_data = get_file( filename_1 );

	make_file( filename_2 );

	set_file ( filename_2, file_data );
}

// get copy filename
void get_copy_filename ( string &filename, string copy_string )
{
	bool verif = false;
	for ( int i=0; i<filename.length(); i=i+1 )
		if ( filename[i] == '.' )
			verif = true;

	if ( verif )
	{
		// filename 1
		string filename_1 = "";
		string filename_2 = "";
		int i=0;
		while ( filename[i] != '.' )
		{
			filename_1 = filename_1 + filename[i];
			i=i+1;
		}
		i=i+1;
		for ( int l=i; l<filename.length(); l=l+1 )
			filename_2 = filename_2 + filename[l];

		filename = filename_1 + " " + copy_string + "." + filename_2;
	}
	else
		filename = filename + " " + copy_string;

}

// copy a file
void copy_file ( string filename )
{
	string file_data = get_file( filename );

	get_copy_filename( filename, "(copy)" );

	make_file( filename );

	set_file ( filename, file_data );
}

// copy a file including a counter in the filename
void copy_file_count ( string filename )
{
	// counter in file
	int counter = 0;
	ifstream fi;
	fi.open( "counter" );
	fi >> counter;
	fi.close();
	if ( counter == 0 )
		make_file( "counter" );

	counter = counter + 1;

	fstream fo;
	fo.open( "counter" );
	fo << counter;
	fo.close();

	// counter as string
	string counter_string = "";
	while ( counter != 0 )
	{
		counter_string = counter_string + (char) ( counter%10 + 48 );
		counter = counter / 10;
	}
	string inverted_counter_string = "";
	for ( int i=counter_string.length() - 1; i>=0; i=i-1 )
		inverted_counter_string = inverted_counter_string + counter_string[i];
	counter_string = inverted_counter_string;


	// make copied file


	string file_data = get_file( filename );

	get_copy_filename( filename, '(' + counter_string + ')' );

	make_file( filename );

	set_file ( filename, file_data );
}
















// get file data
string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();

	return file;
}

void get_file ( string filename, string strings[] )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	int strings_iter = 0;
	string temp;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();
}

void get_file_lines ( string filename, string strings[] )
{
	ifstream fi;
	fi.open( filename );

	// get file data
	int strings_iter = 0;
	string temp;
	while ( getline( fi, temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();
}
void get_file ( string filename, string strings[], string a )
{

	if ( a.length() == 0 ) return;

	string file = get_file( filename );

	int size = file.length();
	int strings_iter = 0;

	for ( int i = 0; i < size - 1; i = i + 1 )
	{
		if ( file[ i ] == a[ 0 ] )
		{
			bool have_a = 1;
			int file_iter = i;
			for ( int l = file_iter; l < a.length(); l = l + 1 )
				if ( file[ l ] != a[ l ] )
				{
					have_a = 0;
					break;
				}

			if ( have_a )
			{
				i = i + a.length() - 1;
				strings_iter = strings_iter + 1;
				strings[ strings_iter ] = "";
				continue;
			}
		}

		strings[ strings_iter ] = strings[ strings_iter ] + file[ i ];
	}
}


// set file data
void set_file ( string filename, string data )
{
	// set file data
	ofstream fo;
	fo.open( filename );

	fo << data;

	fo.close();

}

void set_file ( string filename, string strings[] )
{
	// set file data
	ofstream fo;
	fo.open( filename );

	int i = 0;
	while ( strings[ i ].length() > 0 )
	{
		fo << strings[ i ] << ' ';
		i = i + 1;
	}

	fo.close();
}

void set_file_lines ( string filename, string strings[] )
{
	// set file data
	ofstream fo;
	fo.open( filename );

	int i = 0;
	while ( strings[ i ].length() > 0 )
	{
		fo << strings[ i ] << '\n';
		i = i + 1;
	}

	fo.close();
}


void set_file ( string filename, string strings[], string a )
{
	// set file data
	ofstream fo;
	fo.open( filename );

	int i = 0;
	while ( strings[ i ].length() > 0 )
	{
		fo << strings[ i ] << a;
		i = i + 1;
	}

	fo.close();
}



// add to a file
void add_to_file ( string filename, string data )
{
	string file_data = get_file( filename );

	file_data = file_data + data;

	set_file( filename, file_data );
}

// add line to a file
void add_line_to_file ( string filename, string data )
{
	string file_data = get_file( filename );

	file_data = file_data + "\n" + data;

	set_file( filename, file_data );
}

// add word to a file
void add_word_to_file ( string filename, string data )
{
	string file_data = get_file( filename );

	file_data = file_data + ' ' + data;

	set_file( filename, file_data );
}



// File that stores a counter



int file_count ( string name )
{
	string counter_filename = name + "_counter";

	int file_counter = 0;

	ifstream fi;
	fi.open( counter_filename );
	fi >> file_counter;
	if ( file_counter == 0 )
	{
		fi.close();

		// make the file if not already made
		ofstream fo;
		fo.open( counter_filename );
		fo << 1;
		fo.close();


		return 1;
	}
	fi.close();


	file_counter = file_counter + 1;


	// clears the file
	clear_file( counter_filename );


	ofstream fo;
	fo.open( counter_filename );
	fo << file_counter;
	fo.close();

	return file_counter;
}




// Get Filename and Ext. of file "filename"



bool have_ext ( string filename )
{
	for ( int i = 0; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			return true;
		}
	}

	return false;
}

string get_filename ( string filename )
{
	if ( ! have_ext ( filename ) ) return filename;

	string file_name = "";
	int l = 0;
	for ( int i = 0; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}

		file_name = file_name + filename[ i ];
	}

	return file_name;
}

string get_ext ( string filename )
{
	if ( ! have_ext ( filename ) ) return "";

	string ext = "";
	int l = 0;
	for ( int i = filename.length() - 1; i >= 0; i = i - 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}
	}

	for ( int i = l + 1; i < filename.length(); i = i + 1 )	
		ext = ext + filename[ i ];

	return ext;
}


void filename_ext_filepath ( string &filename, string &ext, string &filepath )
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			have_ext = true;

			break;
		}
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


void get_files ( string filenames[], string files[] )
{
	int size = 0;
	while ( filenames[ size ].length() > 0 )
		size = size + 1;

	ifstream fi;
	string temp;
	for ( int i = 0; i < size; i = i + 1 )
	{
		files[ i ] = "";

		fi.open( filenames[ i ] );

		while ( getline( fi, temp ) )
			files[ i ] = files[ i ] + temp + '\n';

		fi.close();
	}
}

void set_files ( string filenames[], string files[] )
{
	int size = 0;
	while ( filenames[ size ].length() > 0 )
		size = size + 1;
	ofstream fo;
	string temp;
	for ( int i = 0; i < size; i = i + 1 )
	{
		fo.open( filenames[ i ] );

		fo << files[ i ];

		fo.close();
	}
}

