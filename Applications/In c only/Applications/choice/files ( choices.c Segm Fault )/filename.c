#include <string.h>
#include <stdio.h>

int main()
{

	printf( "Choices:\n    " );
	printf( "1. feature   " );
	printf( "\n\n  exit. Exits\n\n" );

	char choice[90] = {0};
	printf( "Your choice: " );
	fgets( choice, 90, stdin );
	choice[ strlen(choice) - 1 ] = '\0';


	// feature
	if ( choice == "1" )
	{
		// your code
	}


	return 0;
}