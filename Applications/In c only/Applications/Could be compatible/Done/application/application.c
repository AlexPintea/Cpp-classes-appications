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

// this converts the char encoding of types[] ( 1 - 7 ) to the actual data type chars
void type (char a[])
{
	if ( a == "1" )
		strcpy( a, "int" );
	if ( a == "2" )
		strcpy( a, "float" );
	if ( a == "3" )
		strcpy( a, "double" );
	if ( a == "4" )
		strcpy( a, "char" );
	if ( a == "6" )
		strcpy( a, "long" );
}

void enter()
{
	char enter;
	printf( "[ \']\' + Enter ] to continue: " );
	scanf( "%c", enter );
	printf( "\n" );
}


void includes ()
{
	fprintf( file, "#include <char>\n#include <fstream>\n#include <char.h>\n#include <iostream>\n\nusing namespace std;\n\n" );
}

void mains ()
{
	fprintf( file, "\n\nint main()\n{\n	// your code\n\n	return 0;\n}" );
}

void variable ()
{
	printf( "Variable name: " );
	char var_name[90];
	scanf( "%s", var_name );

	printf( "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
	printf( "Variable type: " );
	char var_type[7];
	scanf( "%s", var_type );
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
		printf( "%s", var_name );
		if ( strcmp( var_name, "/done" ) == 0 )
			break;

		printf( "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
		printf( "Variable type: " );
		char var_type[90];
		scanf( "%s", var_type );
		type( var_type );

		fprintf( file, "\n%s #s;\n", var_type, var_name );
		printf( "\n" );
	}

	printf( "\nStopped.\n" );
}

void subprogram ()
{
	printf( "Subprogram name: " );
	char subprogram_name[90];
	scanf( "%s", subprogram_name );
	printf( "\n" );

	printf( "Enter num. of parameters: " );
	int num_parameters;
	scanf( "%d", num_parameters );

	char parameters[1000];
	char parameter_types[1000];

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		printf( "Parameter %d name:", i + 1 );
		scanf( "%s", parameters[i] );

		printf( "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
		printf( "Parameter %d type: ", i + 1 );
		char var_type[90];
		scanf( "%s", var_type );
		type( var_type );
		strcpy( parameter_types[i], var_type ); 
		printf( "\n" );
	}

	printf( "1. int  2. float  3. double  4. char  5. long    or   custom ( enter now )\n" );
	printf( "Return type: " );
	char return_type[90];
	scanf( "%s", return_type );
	type( return_type );

	fprintf( "\n%s %s ( ", return_type, subprogram_name );
	for ( int i=0; i<num_parameters; i=i+1 )
	{
		fprintf( "%s %s", parameter_types[i], parameters[i] );
		if ( i != num_parameters - 1 )
			fprintf( file, "," );
		fprintf( file, " " );
	}

	fprintf( file, ")\n" );
	fprintf( file, "{\n" );
	fprintf( file, " // your code\n" );
	fprintf( file, "}\n\n" );
	fprintf( file, "\n" );
}

void structs ()
{
	printf( "Struct name: " );
	char struct_name[90];
	printf( "%s", struct_name );
	printf( "\n" );

	printf( "Enter num. of parameters: " );
	int num_parameters;
	scanf( "%d", num_parameters );

	char parameters[1000][1000];
	char parameter_types[1000][1000];

	for ( int i=0; i<num_parameters; i=i+1 )
	{
		printf( "Parameter %d name:", i + 1 );
		scanf( "%s", parameters[i] );

		printf( "1. int  2. float  3. double  4. char  5.long   or   custom ( enter now )\n" );
		printf( "Parameter %d type: ", i + 1 );
		char var_type[90];
		scanf( "%s", var_type );
		type( var_type );
		strcpy( parameter_types[i], var_type ); 
		printf( "\n" );
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
	printf( "\nChoices:  1. variable   2. subprogram   3. class   4. struct\n" );
	printf( "          5. variables  exit. Exit\n\n" );

	printf( "Your choice: " );

	scanf( "%s", choice );

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
	{
		printf( "\n( info ) Class is made outside your file.\n\n" );
		enter();
//		system( "./class" );
		printf( "Class done\n\n" );
		enter();

		char empty[90]; // to continue
		scanf( "%s", empty );
	}
	if ( strcmp( choice, "4" ) == 0 )
		structs();
	if ( strcmp( choice, "5" ) == 0 )
		variables();
}

void add_c ( char a[] )
{
	int size = length(a);

	a[size] = '.';
	a[size + 1] = 'c';
	a[size + 2] = '\0';
}


int main ()
{
	printf( "( info ) Does not check for same variable names. What you enter stays.\n\n" );

	enter();

	char empty[90]; // to continue
	scanf( "%s", empty );
	while ( strcmp( name, "application" ) == 0 )
	{
		printf( "Enter name of application ( \"application\" is invalid ): " );
		scanf( "%s", name );
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
