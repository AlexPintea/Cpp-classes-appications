#include <string.h>
#include <stdio.h>

// cpp to h filename
void make_filename ( char a[] )
{
	char filename = "";

	for ( int i=0; i<a.length(); i=i+1 )
	{
		if ( a[i] == '.' )
			break;

		filename[i] = a[i];
	}
	filename[i] = '.';
	filename[i + 1] = 'h';
	filename[i + 2] = '\0';

	strcpy( a, filename );
}

int is_main ( char a[0] )
{
	int is_main_name;
	int main_iter;

	// check for main
	if ( a.length() >= 7 )
		for ( int i=0; i<a.length() - 3; i=i+1 )
			if ( a[i] == ' ' and a[i+1] == 'm' and a[i+2] == 'a' and a[i+3] == 'i' and a[i+4] == 'n' and a[i+5] == ' ' )
			{
				is_main_name = 1;
				main_iter = i;
			}

	if ( is_main_name == 0 )
		return 0;

	for ( int i=0; i<main_iter-1; i=i+1 )
		if ( a[i] == '/' and a[i+1] == '/' )
			return 0;

	return 1;	
}


// checks if a char is a subprogram header
int is_subprogram ( char a[] )
{
	int brackets = 0;

	for ( int i=0; i<a.length(); i=i+1 )
		if ( a[i] == '(' or a[i] == ')' )
			brackets = brackets + 1;

	if ( brackets < 2 )
		return 0;

	if ( is_main( a ) )
		return 0;

	char type = "";

	for ( int i=0; i<a.length(); i=i+1 )
	{
		if ( a[i] == ' ' )
			break;

		type = type + a[i];
	}


	if ( type == "int" or type == "long" or type == "double" or type == "float" or type == "char" or type == "bool" or type == "char" or type == "void" )
		return 1;

	return 0;
}


// makes header file
void make_header_file ( char filename[] )
{
	FILE* file = fopen( filename, "w");
	FILE* fi = fopen( filename, "r");

	file << "#include \"" << filename << "\"\n\n";

	char temp;
	while ( scanf( fi, temp ) )
		if ( is_subprogram( temp ) )
		{

			if ( temp[ temp.length() - 1 ] == '{' )
				temp[ temp.length() - 1 ] = '\0';
			temp = temp + ";";

			file << temp << "\n\n";
		}

	fclose( file );
	fclose( fi );


}


