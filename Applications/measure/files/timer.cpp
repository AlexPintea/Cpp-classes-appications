#include <iostream>
#include <unistd.h> 
using namespace std; 

int counter = 0; 

// function to show the timer 
void show_distance() 
{ 
	cout << counter  << endl;
}

// 
void count() 
{ 
	while (true)
	{ 	
		show_distance(); 

		sleep(1); 

		counter++; 
	} 
} 


int main() 
{ 

	

	count();

	return 0; 
} 

