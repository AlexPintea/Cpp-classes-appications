#include <string.h>
#include <stdio.h>

FILE* file;
char name[] = "application";

// length of a char[]
int length ( char a[] )
{
	int i=0; 

	while ( a[i] )
		i = i + 1;

	return i;
}


// convert char to long
long char_to_long ( char a[] )
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

// this converts the char encoding of types[] ( 1 - 7 ) to the actual data type chars
void type ( char a[] )
{
	if ( strcmp( a, "1" ) == 0 )
		strcpy( a, "int" );
	if ( strcmp( a, "2" ) == 0 )
		strcpy( a, "float" );
	if ( strcmp( a, "3" ) == 0 )
		strcpy( a, "double" );
	if ( strcmp( a, "4" ) == 0 )
		strcpy( a, "char" );
	if ( strcmp( a, "5" ) == 0 )
		strcpy( a, "long" );
}

void enter()
{
	printf( "[ \']\' + Enter ] to continue: " );
	fgetc( stdin );
	printf( "\n" );
}


void includes ()
{
	fprintf( file, "#include <string.h>\n#include <stdio.h>\n\n" );
}

void mains ()
{
	fprintf( file, "\n\nint main()\n{\n	// your code\n\n	return 0;\n}" );
}

void variable ()
{
	printf( "Variable name: " );
	char var_name[90];
	fgets( var_name, 90, stdin );
	var_name[ length(var_name)  - 1] = '\0';

	printf( "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
	printf( "Variable type: " );
	char var_type[97];
	fgets( var_type, 4, stdin );
	var_type[ length(var_type)  - 1] = '\0';
	type( var_type );

	fprintf( file, "\n%s %s;\n", var_type, var_name );
}

void variables ()
{
	printf( "Stop with \"/done\".\n" );
	for ( int i=0; i<10000; i=i+1 )
	{
		printf( "Variable name: " );
		char var_name[90];
		fgets( var_name, 90, stdin );
		var_name[ length(var_name)  - 1] = '\0';
		if ( strcmp( var_name, "/done" ) == 0 )
			break;

		printf( "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
		printf( "Variable type: " );
		char var_type[90];
		fgets( var_type, 70, stdin );
		var_type[ length(var_type)  - 1] = '\0';
		type( var_type );

		fprintf( file, "\n%s %s;\n", var_type, var_name );
		printf( "\n" );
	}

	printf( "\nStopped.\n" );
}

void subprogram ()
{
	printf( "Subprogram name: " );
	char subprogram_name[90];
	fgets( subprogram_name, 90, stdin );
	subprogram_name[ length(subprogram_name)  - 1] = '\0';
	printf( "\n" );

	printf( "Enter num. of parameters: " );
	char num_parameters_chars[90];
	fgets( num_parameters_chars, 90, stdin );
	num_parameters_chars[ length(num_parameters_chars)  - 1] = '\0';
	long num_parameters = char_to_long( num_parameters_chars );

	char parameters[90][70];
	char parameter_types[90][70];

	for ( long i=0; i<num_parameters; i=i+1 )
	{
		printf( "Parameter %d name: ", i + 1 );
		fgets( parameters[i], 40, stdin );
		parameters[i][ length(parameters[i])  - 1] = '\0';

		printf( "%s", "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
		printf( "Parameter %d type: ", i + 1 );
		fgets( parameter_types[i], 40, stdin );
		parameter_types[i][ length(parameter_types[i])  - 1] = '\0';
		type( parameter_types[i] );
		printf( "%s", "\n" );
	}

	printf( "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
	printf( "Return type: " );
	char return_type[97];
	fgets( return_type, 90, stdin );
	return_type[ length(return_type)  - 1] = '\0';
	type( return_type );

	fprintf( file, "\n%s %s ( ", return_type, subprogram_name );
	for ( long i=0; i<num_parameters; i=i+1 )
	{
		fprintf( file, "%s %s", parameter_types[i], parameters[i] );
		if ( i != num_parameters - 1 )
			fprintf( file, "," );
		fprintf( file, " " );
	}

	fprintf( file, ")\n" );
	fprintf( file, "{\n" );
	fprintf( file, "	// your code\n" );
	fprintf( file, "}\n\n" );
	fprintf( file, "\n" );
}

void structs ()
{
	printf( "Struct name: " );
	char struct_name[90];
	fgets( struct_name, 90, stdin );
	struct_name[ length(struct_name)  - 1] = '\0';
	printf( "\n" );

	printf( "Enter num. of parameters: " );
	char num_parameters_chars[90];
	fgets( num_parameters_chars, 90, stdin );
	num_parameters_chars[ length(num_parameters_chars)  - 1] = '\0';
	long num_parameters = char_to_long( num_parameters_chars );

	char parameters[90][70];
	char parameter_types[90][70];

	for ( long i=0; i<num_parameters; i=i+1 )
	{
		printf( "Parameter %d name: ", i + 1 );
		fgets( parameters[i], 40, stdin );
		parameters[i][ length(parameters[i])  - 1] = '\0';

		printf( "%s", "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
		printf( "Parameter %d type: ", i + 1 );
		fgets( parameter_types[i], 40, stdin );
		parameter_types[i][ length(parameter_types[i])  - 1] = '\0';
		type( parameter_types[i] );
		printf( "%s", "\n" );
	}

	fprintf( file, "\nstruct %s\n{\n", struct_name );
	for ( int i=0; i<num_parameters; i=i+1 )
		fprintf( file, "	%s %s;\n", parameter_types[i], parameters[i] );

	fprintf( file, "};\n\n" );
	printf( "\n" );
}

char choice[90] = {0};

void show_choices()
{
	printf( "\nChoices:  1. variable   2. subprogram   3. struct   4. variables\n" );
	printf( "          exit. Save & Exit\n\n" );

	printf( "Your choice: " );

	fgets( choice, 90, stdin );
	choice[ length(choice)  - 1] = '\0';

	if ( strcmp( choice, "1" ) != 0 && strcmp( choice, "2" ) != 0 && strcmp( choice, "3" ) != 0 && strcmp( choice, "4" ) != 0 && strcmp( choice, "5" ) != 0 && strcmp( choice, "exit" ) != 0 )
	{
		printf( "Invalid choice. Retry.\n\n" );
		return;
	}

	if ( strcmp( choice, "1" ) == 0 )
		variable();
	if ( strcmp( choice, "2" ) == 0 )
		subprogram();
	if ( strcmp( choice, "3" ) == 0 )
		structs();
	if ( strcmp( choice, "4" ) == 0 )
		variables();
}

void add_c ( char a[] )
{
	int size = length(a);

	a[size - 1 ] = '.';
	a[size] = 'c';
	a[size + 1] = '\0';
}


int main ()
{
	printf( "( info ) Does not check for same variable names. What you enter stays.\n\n" );

	enter();

	char empty[90]; // to continue
	fgets( empty, 90, stdin );
	while ( strcmp( name, "application" ) == 0 )
	{
		printf( "Enter name of application ( \"application\" is invalid ): " );
		fgets( name, 90, stdin );
	}

	add_c( name );

 	file = fopen( name, "w");

	includes();

	printf( "\nYou are editing \'%s\'.\n", name );

	while ( strcmp( choice, "exit" ) != 0 )
		show_choices();

	mains();

 	fclose( file );

	printf( "\nApplication done\n\n" );

	return 0;
}
