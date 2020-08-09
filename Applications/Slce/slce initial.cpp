#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string filename;
string ext;
string filepath;
string file_1 = "";
string file_2 = "";


// inverts a string
void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}

// checks if  a  is in  b   or   b  is in  a  for datatype "string"
bool a_is_in_b ( string a, string b )
{
	if (a == b)
		return 1;

	int size_a = a.length();
	int size_b = b.length();

	if ( size_a > size_b )
	{
		for ( int i=0; i<size_a; i=i+1 )
			if (a[i] == b[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}
	else
	{
		for ( int i=0; i<size_b; i=i+1 )
			if (b[i] == a[0])
			{
				bool verif = 1;

				for ( int r=0; r<size_a; r=r+1 )
					if ( b[ r+i ] != a[r] )
						verif = 0;

				if (verif == 1)
				{
					return 1;
					break;
				}
			}
	}

	return 0;
}

// checks if  b  is in  a  for datatype "string"
bool b_is_in_a ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	return a_is_in_b( a, b );
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
 







void get_files ()
{
	ifstream fi;
	fi.open( filename );

	filename_ext();

	string temp = "";
	bool in_file_1 = true;
	while ( getline( fi, temp ) )
	{
		if ( b_is_in_a( temp, "main" ) )
			in_file_1 = false;

		if ( in_file_1 )
			file_1 = file_1 + temp + "\n";
		else
			file_2 = file_2 + temp + "\n";
	}

	fi.close();

	ofstream fo;
	fo.open( filepath + filename + "_initial.cpp" );
	fo << file_1;
	fo << file_2;
	fo.close();


	file_2 = "#include \"" + filename + ".cpp\"\n\n" + file_2;


	fo.open( filepath + filename + ".cpp" );
	fo << file_1;
	fo.close();

	fo.open( filepath + filename + "_include.cpp" );
	fo << file_2;
	fo.close();
}




int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	get_files();
 

	return 0;
}
