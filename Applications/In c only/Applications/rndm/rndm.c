#include <string.h>
#include <stdio.h>


long long rndes;
long a[9];


int chars_to_ints ( char chars[], long ints[] )
{
	int l=0, rndes;
	ints[0] = 0;

	rndes = 0;
	for ( int i=0; i<9; i=i+1 )
	{
		if ( chars[i] == '\n' )
		{
			l = i + 1;
			break;
		}
		else
			rndes = rndes * 10 + (int) ( chars[i] - 48 );
	}

	for ( int i=0; i<9; i=i+1 )
	{
		ints[i] = 0;
		while ( chars[l] != '\n' )
		{
			ints[i] = ints[i] * 10 + (int) ( chars[l] - 48 );
			l = l + 1;
		}
	}

	return rndes;
}

long rnd ( long mins, long maxs )
{
	char file[1000];

	FILE* fi = fopen( "rnd_file", "r");

	// gets in file_temp, to make sure size is valid
	char file_temp[1000] = {0};

	char c; // char in which we input file data
	int iter = 0;
	while ( ( c = fgetc(fi) ) != EOF ) // check for EOF
	{
		file_temp[iter] = c;
		iter = iter + 1;
	}

	strcpy( file, file_temp );

	fclose( fi );

	if ( strcmp( file, "" ) == 0 )
		for ( int i=0; i<9; i=i+1 )
		{
			rndes = 0;
			a[i] = ( mins + maxs + i ) % ( maxs - mins ) + mins;
		}
	else
		rndes = chars_to_ints( file, a );

	for ( int i=0; i<9; i=i+1 )
		a[i] =( a[i] + maxs - mins / ( 9 - i ) + rndes ) % ( maxs - mins ) + mins;

	for ( int i=0; i<7; i=i+1 )
		a[i] = ( maxs - a[i] ) % ( maxs - mins ) + mins;

	for ( int i=0; i<9; i=i+1 )
		if ( a[i] > maxs )
			a[i] = maxs;

	for ( int i=0; i<9; i=i+1 )
		if ( a[i] < mins )
			a[i] = mins;

	for ( int i=0; i<=7; i=i+1 )
		for ( int l=i + 1; l<9; l=l+1 )
			if ( a[i] == a[l] )
				if ( a[i] == maxs )
					a[l] = a[l] - 1;
				else
					a[l] = a[l] + 1;

	rndes = rndes + 1;


	FILE* fo = fopen( "rnd_file", "w");

	fprintf( fo, "%d\n", rndes );
	for ( int i=0; i<9; i=i+1 )
		fprintf( fo, "%d\n", a[i] );

	fclose( fo );

	return a[ rndes % 9 ];
}






int main ()
{
	printf( "%d", rnd( 14, 97 ) );

	return 0;
}
