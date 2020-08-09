#include <string>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <string.h>

using namespace std;

string string_iters ( string a, int num )
{
	if ( num > a.length() ) return a;

	string result = "";
	for ( int i = num; i < a.length(); i = i + 1 )
		result = result + a[ i ];

	return result;
}

void show_string( string a, int num ) 
{ 
	cout << "\033c";
	cout << string_iters( a, num );
}

void slid( string a ) 
{ 
	int num = 0;
	while ( true )
	{ 	
		show_string( a, num ); 
		usleep( 1000 ); 
		num = num + 1; 
	} 
} 




int main ()
{
	slid( "files" );

	return 0;
}
