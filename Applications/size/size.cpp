#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


void get_average ( string filename )
{
	ifstream fi;

	fi.open( filename );

	string temp;
	double size = 0;
	int count = 0;
	while ( fi >> temp )
	{
		size = size + temp.length();
		count = count + 1;
	}

	fi.close();

	fi.open( "size_count" );

	double last_size = -1;
	int last_count = -1;

	fi >> last_size;
	fi >> last_count;
	fi.close();

	if ( last_size != -1 and last_count != -1 )
	{
		for ( int i = 0; i < last_count; i = i + 1 )
			size = size + last_size;
		count = count + last_count;
	}

	size = size / count;

	ofstream fo;
	fo.open( "size_count" );
	fo.close(); // clear file

	fo.open( "size_count" );

	fo << size << ' ';
	fo << count;

	fo.close();

	cout << "\033c";

	if ( last_size != -1 and last_count != -1 )
	{
		cout << "Previous average size: " << last_size << "\n";
		cout << "Previous count: " << last_count << "\n";
		cout << "\n";
	}

	cout << "Average size: " << size << "\n";
	cout << "Count: " << count << "\n";
}
int main ()
{
	string filename;
	double size;
	int count;




	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );
	get_average( filename );

	return 0;
}
