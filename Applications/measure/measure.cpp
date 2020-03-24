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

// function to show the timer 
void show_distance() 
{ 
	cout << "printf \033c";

	cout << "[ Ctrl + Z ] to Stop.\n";

	cout << "Distance you measured: " << counter / 2 / 1000 << " meters." << endl;
}

// counts
void count() 
{ 
	while (true)
	{ 	
		show_distance(); 

		sleep( 0.1 ); 

		counter = counter + 0.1; 
	} 
} 


int main ()
{

	cout << "Walk and return to measure a distance.\n[ Ctrl + Z ] to stop when you return.\n\n";

	enter( "measure" );

	count();

	return 0;
}
