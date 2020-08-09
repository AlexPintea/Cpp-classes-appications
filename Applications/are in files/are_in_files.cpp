#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string filename_are_in;
string filepath;
string ext;

string are_in[ 100000 ];
int are_iter = 0;


string file[ 100000 ];
int file_iter = 0;

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


bool is_string_empty ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
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










void set_file ()
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
	filename_ext();

	if ( file_iter == 0 )
	{
		cout << "File \"" << filename << "\" empty / invalid.\n";
		return;
	}


	string choice;
	cout << "Have file with what you want to get ( y / n ): ";
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "y" )
	{
		cout << "Filename ( what you want to get ): ";
		getline( cin, filename_are_in );
		if ( filename_are_in == "" )
			getline( cin, filename_are_in );


		fi.open( filename_are_in );

		while ( getline( fi, temp ) )
		{
			are_in[ are_iter ] = temp;
			are_iter = are_iter + 1;
		}

		fi.close();

		if ( are_iter == 0 )
		{
			cout << "File \"" << filename_are_in << "\" empty / invalid.\n";
			return;
		}

	}
	else
	{
		cout << "Each on a line ( empty means done ).\n";
		getline( cin, temp );
		while ( ! is_string_empty( temp ) )
		{
			are_in[ are_iter ] = temp;
			are_iter = are_iter + 1;
			getline( cin, temp );

		}
	}

	ofstream fo;
	fo.open( filepath + filename + " are_in"  );

	fo << "Line num of file \"" << filename << "\", what is there.\n\n";

	for ( int i = 0; i < are_iter; i = i + 1 )
	{
		fo << "For \"" << are_in[ i ] << "\":\n";

		for ( int l = 0; l < file_iter; l = l + 1 )
			if ( b_is_in_a ( file[ l ], are_in[ i ] ) )
				fo << "  " << l + 1 << ": " << file[ l ] << '\n';
		fo << '\n';
	}

	fo.close();

	cout << "File '" << filename << " are_in' was made.\n";
	if ( filepath != "" )
		cout << "Filepath: " << filepath << '\n';
}


void set_files ()
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

	if ( file_iter == 0 )
	{
		cout << "File \"" << filename << "\" empty / invalid.\n";
		return;
	}

	string choice;
	cout << "Have file with what you want to get ( y / n ): ";
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "y" )
	{
		cout << "Filename ( what you want to get ): ";
		getline( cin, filename_are_in );
		if ( filename_are_in == "" )
			getline( cin, filename_are_in );


		fi.open( filename_are_in );

		while ( getline( fi, temp ) )
		{
			are_in[ are_iter ] = temp;
			are_iter = are_iter + 1;
		}

		fi.close();

		if ( are_iter == 0 )
		{
			cout << "File \"" << filename_are_in << "\" empty / invalid.\n";
			return;
		}

	}
	else
	{
		cout << "Each on a line ( empty means done ).\n";
		getline( cin, temp );
		while ( ! is_string_empty( temp ) )
		{
			are_in[ are_iter ] = temp;
			are_iter = are_iter + 1;
			getline( cin, temp );

		}
	}


	// for ( int i = 0; i < are_iter - 1; i = i + 1 )
	//	for ( int l = i + 1; l < are_iter; l = l + 1 )
	//		if ( are_in[ i ] > are_in[ l ] )
	//		{
	//			temp = are_in[ i ];
	//			are_in[ i ] = are_in[ l ];
	//			are_in[ l ] = temp;
	//		}


	ifstream filepaths;
	string files[ 10000 ];
	int files_iter = 0;


	ofstream fo;
	fo.open( filename + " are_in"  );

	fo << "Line num of files, what is there.\n\n";

	for ( int d = 0; d < file_iter; d = d + 1 )
	{
		filepaths.open( file[ d ] );

		while ( getline( filepaths, temp ) )
		{
			files[ files_iter ] = temp;
			files_iter = files_iter + 1;
		}

		filepaths.close();

		if ( files_iter == 0 )
		{
			cout << "Filepath: \"" << file[ d ] << "\" invalid.\n";
			continue;
		}


		fo << "\nFile: '" << file[ d ] << "':\n\n";

		for ( int i = 0; i < are_iter; i = i + 1 )
		{
			fo << "  For \"" << are_in[ i ] << "\":\n";

			for ( int l = 0; l < files_iter; l = l + 1 )
				if ( b_is_in_a ( files[ l ], are_in[ i ] ) )
					fo << "     " << l + 1 << ": " << files[ l ] << '\n';
			fo << '\n';
		}
		fo << "\n\n";

		files_iter = 0;
	}
	fo.close();
	cout << "File '" << filename << " are_in' was made.\n";
}
















int main ()
{
	string choice;
	cout << "Choices: 1. File  2. Files\n";
	cout << "Choice: ";

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "1" )		
	{
		cout << "files";
		cout << "\033c";
		cout << "Filename ( where to get ): ";
		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		set_file();
	}

	if ( choice == "2" )
	{
		cout << "\033c";
		cout << "Filename of filepaths ( where to get ): ";
		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		set_files();
	}

	if ( choice != "1" and choice != "2" )
		cout << "Invalid. Exited.\n";
	else
		cout << "Exited.\n";

	return 0;
}
