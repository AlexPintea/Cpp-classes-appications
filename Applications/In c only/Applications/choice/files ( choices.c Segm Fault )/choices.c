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


// gets a file through filename
void get_file ( char filename[], char file[] )
{
	FILE* fi = fopen( filename, "r");

	// gets in file_temp, to make sure size is valid
	char file_temp[10000000] = {0};

	char c; // char in which we input file data
	int iter = 0;
	while ( ( c = fgetc(fi) ) != EOF ) // check for EOF
	{
		file_temp[iter] = c;
		iter = iter + 1;
	}

	strcpy( file, file_temp );

	fclose( fi );
}

// adds to a file through filename
void add_to_file ( char filename[], char add[] )
{
	char file_temp[10000000] = {0};
	get_file ( filename, file_temp );


	FILE* fo = fopen( filename, "w");

	fprintf( fo, "%s", file_temp );
	fprintf( fo, "%s", add );

	fclose( fo );
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

/*
void set_data ()
{
	char choices1[10000000] = {0};
	char choices2[10000000] = {0};
	char choices_main[10000000] = {0};

	char choices1_filename[90] = {0};
	strcpy( choices1_filename, "choice_parts/choices1" );
	char choices2_filename[90] = {0};
	strcpy( choices2_filename, "choice_parts/choices2" );
	char choices_main_filename[90] = {0};
	strcpy( choices_main_filename, "choice_parts/choices_main" );

	get_file ( choices1_filename, choices1 );
	get_file ( choices2_filename, choices2 );
	get_file ( choices_main_filename, choices_main );

	fo = fopen( filename, "w");

	add_to_file( filename, choices1 );

	// declare "valid_choices"[]
	fprintf( fo, "char valid_choices[1000][90] = { ");
	for ( int i=0; i<choices_iter; i=i+1 )
		fprintf( fo, "\"%d\", ", i + 1);
	 fprintf( fo, " \"exit\" };\n");

	// declare "choices"[]
	fprintf( fo, "char choices[1000][90] = { ");
	for ( int i=0; i<choices_iter; i=i+1 )
	{
		fprintf( fo, "\"%s\"", choices[i]);
		if ( i != choices_iter - 1 )
			fprintf( fo, ", " );
	}
	fprintf( fo, " };\n" );

	fprintf( fo, choices2 );

	// choices ifs
	for ( int i=0; i<choices_iter; i=i+1 )
	{
		fprintf( fo, "	// %s\n", choices[i] );
		fprintf( fo, "	if ( choice == \"%d\" )\n", i + 1 );
		fprintf( fo, "	{\n");
		fprintf( fo, "		// your code\n");
		fprintf( fo, "	}\n\n\n" );
	}

	fprintf( fo, choices_main );

	fclose( fo );
}*/

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

//	set_data(); // Segm. Fault in get_file()

	printf( "\nDone.\n" );

	return 0;
}
