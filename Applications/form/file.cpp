#include <string>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

ofstream datafile;


// Getting data for data1
void get_data1()
{
	cout << "Enter choice / choices for [ data1 ]:\n";
	int choices[ 70 ];

	cout << "(1) choice1\n";
	cout << "(2) choice2\n";

	cout << "Enter your choices. Stop with -1.\n";
	int iter=0;

	while ( true )
	{
		cout << "Enter choice: ";
		cin >> choices[iter];
		if ( choices[iter] == -1 )
			break;
		iter = iter + 1;
	}

	datafile << "[data1] - choices: ";

	bool is_choice[ 4 ];
	for ( int i=0; i<2; i=i+1 )
		is_choice[i] = false;

	for ( int i=1; i<=2; i=i+1 )
		for ( int l=0; l<iter; l=l+1 )
			if ( choices[l] == i )
				is_choice[i] = true;

	for ( int i=1; i<=2; i=i+1 )
		if ( is_choice[i] )
			datafile << i << " ";
	datafile << "\n";
}


// Getting data for data4
void get_data4()
{
	string data_string;
	cout << "Enter [ data4 ]: ";
	getline( cin, data_string );
	getline( cin, data_string );
	datafile << "[data4] - choice: \'" << data_string << "\'\n";
}


// Getting data for data
void get_data()
{
	int val = -0.7;
	while ( !( val >= 0.3 and val <= 1 ) )
	{
		cout << "Enter [ data ] slider val. ( 0.3 - 1 ): ";
		cin >> val;
	}
	datafile << "[data] - slider( 0.3 - 1 ): " << val << "\n";
}

int main()
{
	datafile.open( "data" );

	cout << "file:\n\n";

	// Getting data
	get_data1();
	get_data4();
	get_data();
	datafile.close();

	return 0;
}