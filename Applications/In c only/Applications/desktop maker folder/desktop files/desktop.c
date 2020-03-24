#include <string.h>
#include <stdio.h>



// desktop files do not actually "gnome-terminal -e filename"

// length of a string
int length( char word[] )
{
	int	length = 0;
	while ( word[ length ] )
		length = length + 1;

	return length;
}



// sets a file through filename
void set_file ( char filename[], char file[] )
{
	FILE* fo = fopen( filename, "w");

	fprintf( fo, "%s", file );

	fclose( fo );
}


void large_char ( char a[] )
{
	if ( a[0] >= 'a' && a[0] <= 'z' )
		a[0] = a[0] - 32;
}

void small_char ( char a[] )
{
	if ( a[0] >= 'A' && a[0] <= 'Z' )
		a[0] = a[0] + 32;
}

void make_desktop ( char filename[] )
{
	char filename_desktop[90];
	strcpy( filename_desktop, filename );
	strcat( filename_desktop, ".desktop" );
	
	FILE* file = fopen( filename_desktop, "w");

	fprintf( file, "[Desktop Entry]\n" );
	large_char( filename );
	fprintf( file, "Name=%s\n", filename );
	small_char( filename );
	fprintf( file, "Exec=gnome-terminal -e %s\n", filename );
	fprintf( file, "Icon=utilities-terminal\n" );
	fprintf( file, "Type=Application" );

	fclose( file );
}
