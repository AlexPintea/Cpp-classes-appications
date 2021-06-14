void remove_fv ( string &file )
{
	string result = "";
	int size = file.length() - 1;
	for ( int i = 0; i < size; i = i + 1 )
		result = result + file[ i ];
	file = result; 
}

void clear_fv ( string filename )
{
	ofstream fo;
	fo.open( "fv/" + filename );
	fo.close(); // clear file
}

string get_fv ( string filename )
{
	ifstream fi;
	fi.open( "fv/" + filename );

	string temp;
	string file = "";
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	remove_fv( file );
	fi.close();
	return file;
}

bool have_fv ( string filename )
{
	if ( get_fv( filename ) != "" )
		return 1;
	return 0;
}

void set_fv ( string filename, int val )
{
	ofstream fo;

	clear_fv( filename );
	fo.open( "fv/" + filename );
	fo << val;
	fo.close();
}

void set_fv ( string filename, long val )
{
	ofstream fo;

	clear_fv( filename );
	fo.open( "fv/" + filename );
	fo << val;
	fo.close();
}

void set_fv ( string filename, double val )
{
	ofstream fo;

	clear_fv( filename );
	fo.open( "fv/" + filename );
	fo << val;
	fo.close();
}

void set_fv ( string filename, float val )
{
	ofstream fo;

	clear_fv( filename );
	fo.open( "fv/" + filename );
	fo << val;
	fo.close();
}

// for bool gets any as bool

void set_fv ( string filename, char val )
{
	ofstream fo;

	clear_fv( filename );
	fo.open( "fv/" + filename );
	fo << val;
	fo.close();
}

void set_fv ( string filename, string val )
{
	ofstream fo;

	clear_fv( filename );
	fo.open( "fv/" + filename );
	fo << val;
	fo.close();
}

