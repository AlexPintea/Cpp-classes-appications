#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

// to continue
void enter()
{
	char enter;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> enter;
	cout << "\n";
}

// gets the distance
double num_steps_to_distance( int num_steps )
{
	double distance = num_steps * 0.93;

	distance = distance / 2;

	return distance;
}

int main ()
{
	int num_steps = 0;

	cout << "( info ) Walk distance you want to measure twice ( returning ).\n";
	cout << "   (!)   Count your steps.\n\n";

	enter();

	cout << "Num. Steps: ";
	cin >> num_steps;
	cout << "\n";

	cout << "You walked: " << num_steps_to_distance( num_steps )  << "m.\n\nExited.\n";
	

	return 0;
}
