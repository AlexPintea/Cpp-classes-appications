#include <iostream>
#include <unistd.h>

using namespace std;


// to continue
void enter( string reason )
{
	char enter;
	cout << "[ \']\' + Enter ] to " << reason << ": ";
	cin >> enter;
	cout << "\n";
}


double counter = 0;

double counter_s = 0;

string typed = "";

// counts
void count() 
{ 
	while (true)
	{ 	
		sleep( 0.1 ); 

		counter = counter + 0.1; 

		counter_s = counter / 2 / 1000;
	} 
} 


int main ()
{

	cout << "Measure how fast you can type.\n\n";

	enter( "type" );

	count();

	return 0;
}
