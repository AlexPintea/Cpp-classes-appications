#include <fstream>
#include <string>
#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

fstream server_file;

void set_server_file ( string data )
{
	// clears server file
	ofstream fo;
	fo.open( "response-file" );
	fo.close();


	server_file.open( "response-file" );
	server_file << data;
	server_file.close();
}

string get_server_file ()
{
	string data;

	server_file.open( "response-file" );
	getline( server_file, data );
	server_file.close();

	return data;
}






void replace ( string &a ); // option 1

void respond ()
{
	string data = get_server_file();

	// gets the option code
	string option_code = "";
	int l=0;
	while ( data[l] != ' ' )
	{
		option_code = option_code + data[l];
		l = l + 1;
	}
	
	if ( option_code == "1" ) // checks for options
		replace( data );


	// makes result
	int size = data.length();

	string result = "";
	for ( int i=0; i<size - 2; i=i+1 )
		result = result + data[ i + 2 ];



	set_server_file( result );
}






// replace '_' with ' '
void replace ( string &a )
{
	for ( int i=0; i<a.length(); i=i+1 )
		if ( a[i] == '_' )
			a[i] = ' ';
}





int main ()
{
	respond();

	return 0;
}
