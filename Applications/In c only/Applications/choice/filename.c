#include <string.h>
#include <stdio.h>

int main()
{

	printf( "Choices:\n    " );
	printf( "1. feature1   " );
	printf( "2. feature4   " );
	printf( "3. feature   " );
	printf( "4. features   " );
	printf( "\n\n  exit. Exits\n\n" );

	char choice[90] = {0};
	printf( "Your choice: " );
	fgets( choice, 90, stdin );
	choice[ strlen(choice) - 1 ] = '\0';


	// feature1
	if ( choice == "1" )
	{
		// your code
	}


	// feature4
	if ( choice == "2" )
	{
		// your code
	}


	// feature
	if ( choice == "3" )
	{
		// your code
	}


	// features
	if ( choice == "4" )
	{
		// your code
	}


	return 0;
}