#include <string>
#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;







string filename;
string ext;




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

// a[] and b[] have iters
bool is_in ( int a[], int b[], int size, int iter )
{
	for ( int i=0; i<size; i=i+1 )
		if ( iter >= a[i] and iter <= b[i] )
			return true;

	return false;
}

// replace  b  in  a  for datatype "string"
string replace_b_in_a ( string &a, string b, string replacement )
{
	if ( !b_is_in_a( a, b ) )
		return a;

	int size_a = a.length();
	int size_b = b.length();

	int iter_1[1000];
	int iter_2[1000];

	int size_iter = 0;

	string result = "";

	for ( int i=0; i<size_a; i=i+1 )
		if ( a[i] == b[0] )
		{
			if ( i + size_b - 1 <= size_a )
			{
				bool verif = 1;
				iter_1[ size_iter ] = i;
			
				int r;
				for ( r=1; r<size_b; r=r+1 )
					if ( a[ r+i ] != b[r] )
						verif = 0;

				if (verif == 1)
				{
					iter_2[ size_iter ] = r + i - 1;
					size_iter = size_iter + 1;
				}
			}	
		}


	for ( int i=0; i<size_a; i=i+1 )
	{
		if ( !is_in( iter_1, iter_2, size_iter, i ) )
			result = result + a[i];
		else
		{
			result = result + replacement;
			while ( is_in( iter_1, iter_2, size_iter, i ) )
				i = i + 1;
			i = i - 1;
		}
	}

	a = result;

	return a;
}


void set_file ( string filename, string file )
{
	ofstream fo;
	fo.open( filename );
	fo.close();

	fo.open( filename );

	fo << file;

	fo.close();
}



int string_in_strings ( string a[], string b )
{
	for ( int l = 0; l < length( a ); l = l + 1 )
		if ( a[ l ] == b )
			return l;

	return -1;
}


int strings_iter = 0;
string string_1[ 1000 ];
string string_2[ 1000 ];
string string_files_2[ 1000 ];

int before_iter = 0;
string before[ 1000 ];
int file_iter = 0;
string file[ 1000 ];


void set_string_1_to_string_2 ( string &line )
{
	for ( int i = 0; i < length( string_1 ); i = i + 1 )
		while ( b_is_in_a( line, string_1[ i ] ) )
			replace_b_in_a ( line, string_1[ i ], string_2[ i ] );
}
void set_string_1_to_string_files_2 ( string &line )
{
	for ( int i = 0; i < length( string_1 ); i = i + 1 )
		while ( b_is_in_a( line, string_1[ i ] ) )
			replace_b_in_a ( line, string_1[ i ], string_files_2[ i ] );
}

void set_strings ()
{

	int files = 0;
	for ( int i = 0; i < before_iter; i = i + 1 )
	{
		if ( before[ i ].length() <= 7 )
			continue;


		if ( before[ i ][ 0 ] == '(' and before[ i ][ 1 ] == '(' and before[ i ][ 2 ] == '('
		and  before[ i ][ 3 ] == '(' and before[ i ][ 4 ] == '(' )
		{
			files = i;
			break;
		}

		if ( before[ i ][ 0 ] == '-' and before[ i ][ 1 ] == '(' )	
		{


			string_1[ strings_iter ] = "";

			int l = 2;
			while ( ! ( before[ i ][ l ] == ')' and before[ i ][ l + 1 ] == '-' ) )
			{
				string_1[ strings_iter ] = string_1[ strings_iter ] + before[ i ][ l ];
				l = l + 1;
			}


			while ( ! ( before[ i ][ l ] == '-' and before[ i ][ l + 1 ] == '(' ) )
				l = l + 1;
			l = l + 2;


			string_2[ strings_iter ] = "";

			while ( ! ( before[ i ][ l ] == ')' and before[ i ][ l + 1 ] == '-' ) )
			{
				string_2[ strings_iter ] = string_2[ strings_iter ] + before[ i ][ l ];
				l = l + 1;
			}

			strings_iter = strings_iter + 1;
		}
	}









	string file_string_1 = "";
	string file_1[ 1000 ];
	for ( int i = 1; i < file_iter; i = i + 1 )
		file_1[ i ]	= file[ i ];

	for ( int i = 1; i < file_iter; i = i + 1 )
	{
		set_string_1_to_string_2( file_1[ i ] );
		file_string_1 = file_string_1 + file_1[ i ] + "\n";
	}

	set_file( filename + " initial", file_string_1 );





	int num_files = -1;
	string filenames[ 1000 ];
	for ( int i = files; i < before_iter; i = i + 1 )
	{
		if ( before[ i ].length() <= 7 )
			continue;

		if ( before[ i ][ 0 ] == '(' and before[ i ][ 1 ] == '(' and before[ i ][ 2 ] == '('
		and  before[ i ][ 3 ] == '(' and before[ i ][ 4 ] == '(' )
		{
			num_files = num_files + 1;
			filenames[ num_files ] = "";
			for ( int l = 5; l < before[ i ].length(); l = l + 1 )
				if ( before[ i ][ l ] != ' ' and before[ i ][ l ] != '	' and before[ i ][ l ] != '\n' )
					filenames[ num_files ] = filenames[ num_files ] + before[ i ][ l ];

			for ( int i = 0; i < length( string_files_2 ); i = i + 1 )
				string_files_2[ i ] = string_2[ i ];

			continue;

		}


		if ( ! ( before[ i ][ 0 ] == '-' and before[ i ][ 1 ] == '(' ) )	
			continue;		


		string strings_1 = "";

		int l = 2;
		while ( ! ( before[ i ][ l ] == ')' and before[ i ][ l + 1 ] == '-' ) )
		{
			strings_1 = strings_1 + before[ i ][ l ];
			l = l + 1;
		}




		int iter_2 = string_in_strings( string_1, strings_1 );
		if ( iter_2 == -1 )
			continue;
		while ( ! ( before[ i ][ l ] == '-' and before[ i ][ l + 1 ] == '(' ) )
			l = l + 1;
		l = l + 2;

		string_files_2[ iter_2 ] = "";

		while ( ! ( before[ i ][ l ] == ')' and before[ i ][ l + 1 ] == '-' ) )
		{
			string_files_2[ iter_2 ] = string_files_2[ iter_2 ] + before[ i ][ l ];
			l = l + 1;
		}

		string file_string = "";
		string file_2[ 1000 ];
		for ( int i = 1; i < file_iter; i = i + 1 )
			file_2[ i ]	= file[ i ];

		for ( int i = 1; i < file_iter; i = i + 1 )
		{
			set_string_1_to_string_files_2( file_2[ i ] );
			file_string = file_string + file_2[ i ] + "\n";
		}

		set_file( filename + ' ' + filenames[ num_files ] + ext, file_string );




	}
}
bool get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );


	string temp;
	bool before_file = true;

	while ( getline( fi, temp ) )
	{
		if ( temp[ 0 ] == ')' and temp[ 1 ] == ')' and temp[ 2 ] == ')' and temp[ 3 ] == ')' and temp[ 4 ] == ')' )
			before_file = false;

		if ( before_file )
		{
			before[ before_iter ] = temp;
			before_iter = before_iter + 1;
		}
		else
		{
			file[ file_iter ] = temp;
			file_iter = file_iter + 1;
		}
	}



	fi.close();


	if ( before_file ) 
	{
		



		fi.open( filename );
		while ( getline( fi, temp ) )
		{
			file[ file_iter ] = temp;
			file_iter = file_iter + 1;			
		}
		fi.close();


		if ( file_iter <= 1 ) { cout << "File is empty.\n"; return false; }

		string filename_before;
		cout << "Filename of before file: ";


		getline( cin, filename_before );

		fi.open( filename_before );


		while ( getline( fi, temp ) )
		{
			if ( before_file )
			{
				before[ before_iter ] = temp;
				before_iter = before_iter + 1;
			}
		}

	}

	if ( file_iter <= 1 ) { cout << "File is empty.\n"; return false; }




	return true;
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


	
	for ( int i = l; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' ) continue;	

		ext = ext + filename[ i ];
	}


	filename = file_name;

}
 

 

int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	filename_ext();

	if ( get_file ( filename ) )
		set_strings ();

	return 0;
}
