#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string ext;
string filepath;
string choice;
string lines;
string asc;
string result;

string file[ 10000 ];
int file_iter = 0;

double file_double[ 10000 ];
int file_double_iter= 0;

void get_file_1 ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
	{
		file[ file_iter ] = temp;
		file_iter = file_iter + 1;
	}

	fi.close();
}

void get_file_2 ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( fi >> temp )
	{
		file[ file_iter ] = temp;
		file_iter = file_iter + 1;
	}

	fi.close();
}

void get_file_double ( string filename )
{
	ifstream fi;
	fi.open( filename );

	double temp;
	while ( fi >> temp )
	{
		file_double[ file_double_iter ] = temp;
		file_double_iter = file_double_iter + 1;
	}

	fi.close();
}


void filename_ext ()
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



void set_file ()
{
	if ( choice == "1" )
	{
		if ( lines == "1" )
			get_file_1( filename );
		else
			get_file_2( filename );
	}	
	else
		get_file_double( filename );

	
	filename_ext();

	if ( file_double_iter != 0 )
	{
		double temp_double;
		if ( asc == "1" )
		{
			for ( int i = 0; i < file_double_iter; i = i + 1 )
				for ( int l = i + 1; l < file_double_iter; l = l + 1 )
					if ( file_double[ i ] > file_double[ l ] )
					{
						temp_double = file_double[ i ];
						file_double[ i ] = file_double[ l ];
						file_double[ l ] = temp_double;
					}
		}
		else
		{
			for ( int i = 0; i < file_double_iter; i = i + 1 )
				for ( int l = i + 1; l < file_double_iter; l = l + 1 )
					if ( file_double[ i ] < file_double[ l ] )
					{
						temp_double = file_double[ i ];
						file_double[ i ] = file_double[ l ];
						file_double[ l ] = temp_double;
					}
		}
	}
	else
	{
		string temp;
		if ( asc == "1" )
		{
			for ( int i = 0; i < file_iter; i = i + 1 )
				for ( int l = i + 1; l < file_iter; l = l + 1 )
					if ( file[ i ] > file[ l ] )
					{
						temp = file[ i ];
						file[ i ] = file[ l ];
						file[ l ] = temp;
					}
		}
		else
		{
			for ( int i = 0; i < file_iter; i = i + 1 )
				for ( int l = i + 1; l < file_iter; l = l + 1 )
					if ( file[ i ] < file[ l ] )
					{
						temp = file[ i ];
						file[ i ] = file[ l ];
						file[ l ] = temp;
					}
		}
	}

	ofstream fo;
	fo.open( filename + " result" );

	if ( file_double_iter != 0 )
	{
		if ( result == "1" )
			for ( int i = 0; i < file_double_iter; i = i + 1 )
				fo << file_double[ i ] << '\n';
		else
			for ( int i = 0; i < file_double_iter; i = i + 1 )
				fo << file_double[ i ] << ' ';
	}
	else
	{
		if ( result == "1" )
			for ( int i = 0; i < file_iter; i = i + 1 )
				fo << file[ i ] << '\n';
		else
			for ( int i = 0; i < file_iter; i = i + 1 )
				fo << file[ i ] << ' ';
	}

	fo.close();
}




int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	cout << "Choices:  1. Sort strings  2. Sort numerics\n";
	cout << "Choice: ";
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	cout << "Choices:  1. Asc  2. Desc\n";
	cout << "Choice: ";
	getline( cin, asc );
	if ( asc == "" )
		getline( cin, asc );

	if ( choice == "1" )
	{
		cout << "Choices:  1. Sort lines  2. Sort with ' '\n";

		cout << "Choice: ";
		getline( cin, lines );
		if ( lines == "" )
			getline( cin, lines );
	}

	cout << "Choices:  1. Results on lines  2. Results with ' '\n";
	cout << "Choice: ";
	getline( cin, result );
	if ( result == "" )
		getline( cin, result );

	set_file();
	return 0;
}
