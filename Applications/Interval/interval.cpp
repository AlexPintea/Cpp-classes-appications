#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;


string filename;
int interval_1 = 0;
int interval_2 = 0;



int nums[ 100000 ];
int num_iter = 0;



void set_file ()
{
	ofstream fo;
	fo.open( filename );

	for ( int i = 0; i < num_iter; i = i + 1 )
	{
		fo << nums[ i ] << ' ';
		if ( i % 5 == 4 )
			fo << '\n';
	}

	fo.close();
}






bool prime ( int num )
{
	if ( num == 0 ) return 0;
	if ( num == 1 ) return 1;
	if ( num == 2 ) return 1;
	if ( num % 2 == 0 ) return 0;

	for ( int d = 3; d < num; d = d + 2 )
		if ( num % d == 0 )
			return 0;
	return 1;
}





int main ()
{
	cout << "Choices:  1. Even  2. Odd  3. Prime  4. Square  5. Exits\n";
	cout << "Choice: ";
	string choice;
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice != "1" and choice != "2" and choice != "3" and choice != "4" and choice != "5" )
		cout << "Invalid. Exited.\n";
	else
	{
		cout << "Filename: ";
	
		getline( cin, filename );
		if ( filename == "" )
			getline( cin, filename );

		cout << "Interval 1: ";
		cin >> interval_1;

		cout << "Interval 2: ";
		cin >> interval_2;

		while ( interval_2 <= interval_1 )
		{
			cout << "Invalid: Interval 2 > Interval 1\n";
			cout << "Interval 2: ";
			cin >> interval_2;
		}
	}



	if ( choice == "1" )
	{
		if ( interval_1 % 2 == 1 )
			interval_1 = interval_1 + 1;

		for ( int i = interval_1; i <= interval_2; i = i + 2 )
		{
			nums[ num_iter ] = i;
			num_iter = num_iter + 1;
		}

		set_file();
	}

	if ( choice == "2" )
	{
		if ( interval_1 % 2 == 0 )
			interval_1 = interval_1 + 1;

		for ( int i = interval_1; i <= interval_2; i = i + 2 )
		{
			nums[ num_iter ] = i;
			num_iter = num_iter + 1;
		}

		set_file();
	}

	if ( choice == "3" )
	{
		for ( int i = interval_1; i < interval_2; i = i + 1 )
			if ( prime( i ) )
			{
				nums[ num_iter ] = i;
				num_iter = num_iter + 1;
			}

		set_file();
	}

	if ( choice == "4" )
	{
		for ( int i = interval_1; i < interval_2; i = i + 1 )
			if ( (int) sqrt( i ) == sqrt( i ) )
			{
				nums[ num_iter ] = i;
				num_iter = num_iter + 1;
			}

		set_file();
	}

	cout << "Exited.\n";
	return 0;
}
