#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string filepath;
string ext;
ifstream file;
int count = 1;
int maximum;


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}

int length ( int a )
{
	if ( a == 0 ) return 1;

	int i = 0;
	while ( a != 0 )
	{
		i = i + 1;
		a = a / 10;
	}

	return i;
}

void invert_string ( string &a )
{
	string result = "";

	for ( int i = a.length() - 1; i >= 0; i = i - 1 )
		result = result + a[ i ];

	a = result;
}

bool is_numeric ( char a )
{
	if ( a >= '0' and a <= '9' )
		return 1;
	return 0;
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






// converts an int to a string
string int_to_string (int a)
{
	int size = length(a);

	bool is_neg = false;
	if ( a < 0 )
	{
		is_neg = true;
		a = -a;
	}

	string result = "";

	for (int i=0; i<size; i=i+1)
	{	
		char a_char = (char) (a % 10 + 48);

		if ( is_numeric( a_char ) )
			result = result + a_char;
		a = a / 10;
	}

	if ( is_neg )
		result = result + '-';

	invert_string( result );

	return result;
}

void set_files ()
{
	file.open( filename );
	filename_ext();

	ofstream fo;
	string temp;
	int file_count = 0;
	string file_temp = "";
	bool have_files;
	while ( getline( file, temp ) )
	{
		file_temp = file_temp + temp + '\n';
		file_count = file_count + 1;

		if ( file_count >= maximum )
		{
			file_temp[ file_temp.length() - 1 ] = ' ';
			fo.open( filepath + filename + ' ' + int_to_string( count ) + ext );
			fo << file_temp;
			fo.close();
			count = count + 1;

			file_count = 0;
			file_temp = "";

			have_files = 1;
		}
	}

	file.close();

	if ( file_temp != "" and have_files )
	{
		file_temp[ file_temp.length() - 1 ] = ' ';
		fo.open( filepath + filename + ' ' + int_to_string( count ) + ext );
		fo << file_temp;
		fo.close();
		count = count + 1;
		file_count = 0;
		file_temp = "";
	}
	else
	{
		cout << have_files;

		if ( ext != "" )
			cout << "File '" << filename << '.' << ext << "' remains.\n";
		else
			cout << "File '" << filename << "' remains.\n";
		return;
	}

	if ( count != 1 )
		cout << "Files: '" << filename << " [ 1 - " << count - 1 << " ]." << ext << "' were made.\n";
	if ( filepath != "" )
		cout << "Filepath: " << filepath << '\n';
}







int main ()
{


	cout << "choice";



	cout << "\033c";

	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	cout << "Maximum line count / file: ";
	cin >> maximum;

	set_files();

	return 0;
}
