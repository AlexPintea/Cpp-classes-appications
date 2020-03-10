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
	fo.open( "server-file" );
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

string get_response ( string data )
{
	set_server_file( data );

	char command[] = "g++ -o response response.cpp && ./response";
	system( command );

	sleep( 0.1 );

	return get_server_file();
}

int main ()
{

	cout << "Cpp file: \"response.cpp\" replaced \'_\' with \' \' for: \"1 that_is_result\" to give: \"" << get_response ( "1 that_is_result" ) << "\".\n";

	return 0;
}
