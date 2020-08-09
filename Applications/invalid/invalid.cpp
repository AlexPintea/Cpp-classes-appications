#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;

int nums[ 100000 ];
int num_iter = 0;


void get_file ()
{
	ifstream fi;
	fi.open( filename );

	int temp;
	int maximum = -1;
	while ( fi >> temp )
	{
		nums[ num_iter ] = temp;
		num_iter = num_iter + 1;

		if ( temp > maximum )
			maximum = temp;
	}

	for ( int i = 0; i < num_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < num_iter; l = l + 1 )
			if ( nums[ i ] > nums[ l ] )
			{
				temp = nums[ i ];
				nums[ i ] = nums[ l ];
				nums[ l ] = temp;
			}



	int remain[ 10000 ];
	int remain_iter = 0;
	for ( int i = 0; i < num_iter - 1; i = i + 1 )
		if ( nums[ i + 1 ] - nums[ i ] > 1 )
			for ( int l = nums[ i ] + 1; l < nums[ i + 1 ]; l = l + 1 )
			{
				remain[ remain_iter ] = l;
				remain_iter = remain_iter + 1;
			}

	for ( int i = 0; i < remain_iter; i = i + 1 )
		cout << remain[ i ] << ' ';
	cout << "\n";

	ofstream fo;
	fo.open( "result" );

	fo << "Result of file \"" << filename << "\":\n\n";

	for ( int i = 0; i < remain_iter; i = i + 1 )
		fo << remain[ i ] << ' ';
	fo << "\n";

	fo.close();

	fi.close();
}







int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );


//	ofstream fo;
//	fo.open( "file" );

//	for ( int i = 0; i <= 1000; i = i + 1 )
//	{
//		fo << i << ' ';
//		if ( i % 5 == 4 )
//			fo << '\n';
//	}

//	fo.close();


	get_file();

	return 0;
}
