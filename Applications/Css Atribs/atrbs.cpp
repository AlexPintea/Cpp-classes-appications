#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string ext;
string filepath;
string choice;
string file;

void add_string ( string &a, string b, int string_iter )
{
	string result = "";

	for ( int i = 0; i < a.length(); i = i + 1 )
	{
		result = result + a[ i ];

		if ( i == string_iter )
			result = result + b;
	}

	a = result;
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
	ifstream fi;
	fi.open( filename );

	string temp;
	file = "";
	while ( getline( fi, temp ) )
		file = file + temp + "\n";

	fi.close();

	ofstream fo;

	filename_ext();
	string file_name;
	temp = "";

	if ( choice == "1" )	
	{
		file_name = filename + " converted 1";
		if ( ext != "" )
			file_name = filename + '.' + ext;


		fo.open( file_name );


		for ( int i = 0; i < file.length(); i = i + 1 )
		{
			if ( file[ i ] == '[' )
			{

				i = i + 1;
				temp = "";
				while ( file[ i ] == ' ' or file[ i ] == '	' )
					i = i + 1;

				bool have_val = 0;
				while ( file[ i ] != ']' )
				{
					if ( file[ i ] == '=' )
					{
						have_val = 1;

						break;
					}

					if ( file[ i ] != ' ' and file[ i ] != '	' )
						temp = temp + file[ i ];

					i = i + 1;
				}


				if ( have_val ) continue;
				add_string( file, ", ." + temp + ' ', i );
			}
		}

		fo << file;
		if ( filepath == "" )
			cout << "File: \"" << file_name << "\" was made. \n";


		else
			cout << "File: \"" << file_name << "\" was made. Filepath: " << filepath << " \n";
	}

	if ( choice == "2" )	
	{
		file_name = filename + " converted 2";
		if ( ext != "" )
			file_name = filename + '.' + ext;

		fo.open( file_name );

		for ( int i = 0; i < file.length(); i = i + 1 )
		{
			if ( file[ i ] == '.' )
			{

				i = i + 1;
				temp = "";

				while ( file[ i ] != ' ' and file[ i ] != '	' and file[ i ] != '{' )
				{
					temp = temp + file[ i ];
					i = i + 1;
				}
				i = i - 1;
				add_string( file, ", [ " + temp + " ] ", i );
			}
		}
		fo << file;
		if ( filepath == "" )
			cout << "File: \"" << file_name << "\" was made. \n";
		else
			cout << "File: \"" << file_name << "\" was made. Filepath: " << filepath << " \n";

	}

	if ( choice == "3" )	
	{
		file_name = filename + " converted 3";
		if ( ext != "" )
			file_name = filename + '.' + ext;


		fo.open( file_name );


		for ( int i = 0; i < file.length(); i = i + 1 )
		{
			if ( file[ i ] == '[' )
			{
				bool have_val = 0;
				int l = i;
				while ( file[ l ] != '=' )
				{
					if ( file[ l ] == ']' )
						break;

					l = l + 1;
				}

				if ( file[ l ] == '=' )
					have_val = 1;
				

				if ( ! have_val )
					continue;

				i = i + 1;
				string val = "";
				temp = "";
				while ( file[ i ] == ' ' or file[ i ] == '	' )
					i = i + 1;

				while ( file[ i ] != '=' )
				{
					if ( file[ i ] != ' ' and file[ i ] != '	' )
						temp = temp + file[ i ];

					i = i + 1;
				}

				while ( file[ i ] != ']' )
				{

					if ( file[ i ] != ' ' and file[ i ] != '	' and file[ i ] != '\'' and file[ i ] != '"' and file[ i ] != '=' )
						val = val + file[ i ];

					i = i + 1;
				}

				add_string( file, ", ." + temp + '-' + val + ' ', i );
			}
		}

		fo << file;


		if ( filepath == "" )
			cout << "File: \"" << file_name << "\" was made. \n";
		else
			cout << "File: \"" << file_name << "\" was made. Filepath: " << filepath << " \n";
	}

	if ( choice == "4" )	
	{
		file_name = filename + " converted 4";
		if ( ext != "" )
			file_name = filename + '.' + ext;


		fo.open( file_name );


		for ( int i = 0; i < file.length(); i = i + 1 )
		{
			if ( file[ i ] == '[' )
			{
				bool have_val = 0;
				int l = i;
				while ( file[ l ] != '=' )
				{
					if ( file[ l ] == ']' )
						break;

					l = l + 1;
				}

				if ( file[ l ] == '=' )
					have_val = 1;
				

				if ( ! have_val )
					continue;

				i = i + 1;
				string val = "";
				temp = "";
				while ( file[ i ] == ' ' or file[ i ] == '	' )
					i = i + 1;

				while ( file[ i ] != '=' )
				{
					if ( file[ i ] != ' ' and file[ i ] != '	' )
						temp = temp + file[ i ];

					i = i + 1;
				}

				while ( file[ i ] != ']' )
				{

					if ( file[ i ] != ' ' and file[ i ] != '	' and file[ i ] != '\'' and file[ i ] != '"' and file[ i ] != '=' )
						val = val + file[ i ];

					i = i + 1;
				}

				add_string( file, ", [ " + temp + '-' + val + " ]", i );
			}
		}

		fo << file;


		if ( filepath == "" )
			cout << "File: \"" << file_name << "\" was made. \n";
		else
			cout << "File: \"" << file_name << "\" was made. Filepath: " << filepath << " \n";
	}


	fo.close();
}

void remove_spaces ( string &a )
{
	string result = "";

	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '	' )
			result = result + a[ l ];

	a = result;
}









int main ()
{
	cout << "\033c";
	cout << "Choices:\n";
	cout << " 1. Attributes to Classes\n";
	cout << " 2. Classes to Attributes\n";
	cout << " 3. Attribute Values to Classes\n";
	cout << " 4. Attribute Values to Attributes\n";

	cout << "\nChoice: ";
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	remove_spaces( choice );




	while ( choice != "1" and choice != "2" and choice != "3" and choice != "4" )
	{
		cout << "\033c";
		cout << "Choices:\n";
		cout << " 1. Attributes to Classes\n";
		cout << " 2. Classes to Attributes\n";
		cout << " 3. Attribute Values to Classes\n";
		cout << " 4. Attribute Values to Attributes ( not completed ) \n";

		cout << "\nInvalid. Retry.";
		cout << "\nChoice: ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );	

		remove_spaces( choice );
	}
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	set_file();

	return 0;
}
