#include <stdio.h>
#include <stdlib.h>

int chars_length ( char a[] )
{
	int m = 0;

	while ( a[ m ] )
		m = m + 1;

	return m;
}

int chars_is_empty ( char m[] )
{
	int l = chars_length( m );

	for ( int i = 0; i < l; i = i + 1 )
		if ( m[ i ] != ' ' && m[ i ] != '\n' && m[ i ] != '	' )
			return 0;

	return 1;
}

char * chars_concat ( char m1[], char m2[] )
{
	int l1 = chars_length( m1 );
	int l2 = chars_length( m1 );

	char static m[ 1000 ] = "";

	for ( int i = 0; i < l1; i = i + 1 )
		m[ i ] = m1[ i ];

	for ( int i = 0; i < l2; i = i + 1 )
		m[ l1 + i ] = m2[ i ];

	m[ l1 + l2 ] = '\0';

	return m;
}

void chars_copy ( char m1[], char m2[] )
{
	int l2 = chars_length( m2 );
	
	for ( int i = 0; i < l2; i = i + 1 )
		m1[ i ] = m2[ i ];

	m1[ l2 ] = '\0';	
}

void get ( char l[] )
{
	fgets( l, 1000, stdin );
	l[ chars_length( l ) - 1 ] = '\0';
}

void set_data ()
{
	int l;

	FILE *fptr;

	fptr = fopen( "your_struct.txt", "w" );

	if( fptr == NULL )
	{
		printf( "Error!\n" );
		return;
	}

	fprintf( fptr, "#include <stdio.h>\n\n" );

	printf( "Struct maker " );

	printf( "Property name and data-type\n" );

	char struct_name[ 45 ] = "";
	char property[ 45 ] = "";
	char type[ 45 ] = "";
	char* properties[ 67 ];
	char* types[ 67 ];

	while ( chars_is_empty( struct_name ) )
	{
		printf( "Struct name: " );

		fgets( struct_name, 1000, stdin );
	}

	fprintf( fptr, "%s", chars_concat( chars_concat( "struct ", struct_name ), "{ " ) );

	int iter = 0;

	while ( 1 )
	{
		printf( "Property name: " );
		get( property );

		if ( chars_is_empty( property ) )
		{
			printf( "Last property given. Exited.\n" );

//			printf( "%s", "File \"your_struct\" has you data." );
			break;
		}

		chars_copy( type, "" );

		while ( chars_is_empty( type ) )
		{
			printf( "Data-type: " );
			fgets( type, 1000, stdin );
		}

		type[ chars_length( type ) - 1 ] = '\0';

		fprintf( fptr, "\n	%s;", chars_concat( chars_concat( type, " " ), property ) );

		properties[ iter ] = malloc( chars_length( property ) + 1 );
		chars_copy( properties[ iter ], property );

		types[ iter ] = malloc( chars_length( type ) + 1 );
		chars_copy( types[ iter ], type );


		int a;
		int n;

		iter = iter + 1;
	}

	fprintf( fptr, "\n}\n\n" );
	struct_name[ chars_length( struct_name ) - 1 ] = '\0';
	fprintf( fptr, "void %s_attr ( struct %s strct, ", struct_name, struct_name );

	for ( int i = 0; i < iter; i = i + 1 )
	{
		fprintf( fptr, "%s %s", types[ i ], properties[ i ] );
		if ( i != iter - 1 )
			fprintf( fptr, ", " );	
	}	

	fprintf( fptr, " )\n{\n" );

	for ( int i = 0; i < iter; i = i + 1 )
		fprintf( fptr, "	strct.%s = %s;\n", properties[ i ], properties[ i ] );

	fprintf( fptr, "}\n\n" );



	fprintf( fptr, "void %s_info ()\n{\n", struct_name );
	fprintf( fptr, "	printf( \"  %s properties:\\n\" );\n", struct_name );

	for ( int i = 0; i < iter; i = i + 1 )
		fprintf( fptr, "	printf( %s, \"%s\", %s.%s );\n", "\"     %s: %s\\n\"", properties[ i ], struct_name, types[ i ] );

	fprintf( fptr, "}\n\n" );

//	fprintf( fptr, "int main ()\n{\n	struct %s strct;\n	%s_attr( strct );\n	%s_info( strct );\n\n	return 0;\n}" );

	fclose( fptr );
}


int main ()
{
	// printf( "struct " );

	set_data();

	return 0;
}
