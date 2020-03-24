#include <string.h>
#include <stdio.h>

char filename[90];
FILE* fo;

char choices[1000][90];
long choices_iter;


// length of a char[]
int length ( char a[] )
{
	int i=0; 

	while ( a[i] )
		i = i + 1;

	return i;
}


// convert char to long
long chars_to_long ( char a[] )
{
	if ( length( a ) == 1 )
		return a[0] - 48;

	int size = length( a );

	int iter = 0;
	int is_neg = 0;
	if ( a[0] == '-' )
	{
		is_neg = 1;
		iter = 1;
	}

	long num_long = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_long = num_long * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_long = -num_long;

	return num_long;
}


void add_c ( char a[] )
{
	int size = length(a);

	a[size - 1 ] = '.';
	a[size] = 'c';
	a[size + 1] = '\0';
}

void get_data ()
{
	printf( "%s", "Filename of your application: " );
	fgets( filename, 90, stdin );

	add_c( filename );

	printf ( "%s", "\nNum. of features of your applications: " );
	char choices_iter_chars[90];
	fgets( choices_iter_chars, 90, stdin );
	choices_iter_chars[ length(choices_iter_chars) - 1 ] = '\0';
	choices_iter = chars_to_long( choices_iter_chars );

	for ( int i=0; i<choices_iter; i=i+1 )
	{
		printf( "Name of feature %d: ", i + 1 );
		fgets( choices[i], 40, stdin );
		choices[i][ length(choices[i]) - 1 ] = '\0';
	}
}



int main ()
{

	get_data();
	
	fo = fopen( filename, "w" );

	fprintf( fo, "#include <string.h>\n#include <stdio.h>\n\n" );

	fprintf( fo, "int main()\n{\n\n" );

	fprintf( fo, "	printf( \"Choices:\\n    \" );\n" );

	for ( int i=0; i<choices_iter; i=i+1 )
		fprintf( fo, "	printf( \"%d. %s   \" );\n", i + 1, choices[i] );	

	fprintf( fo, "	printf( \"\\n\\n  exit. Exits\\n\\n\" );\n\n" );

	fprintf( fo, "	char choice[90] = {0};\n" );
	fprintf( fo, "	printf( \"Your choice: \" );\n" );
	fprintf( fo, "	fgets( choice, 90, stdin );\n" );
	fprintf( fo, "	choice[ strlen(choice) - 1 ] = \'\\0\';\n\n\n" );

	// choices ifs
	for ( int i=0; i<choices_iter; i=i+1 )
	{
		fprintf( fo, "	// %s\n", choices[i] );
		fprintf( fo, "	if ( choice == \"%d\" )\n", i + 1 );
		fprintf( fo, "	{\n");
		fprintf( fo, "		// your code\n");
		fprintf( fo, "	}\n\n\n" );
	}


	fprintf( fo, "	return 0;\n}" );

	fclose( fo );

	printf( "\nDone.\n" );

	return 0;
}
