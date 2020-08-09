#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string common[ 10000 ];
int common_iter = 0;
int length ( int a )
{
	if ( a == 0 ) return 1;

	int i = 0;

	while ( a != 0 )
	{
		i = i + 1;
		a = a / 10;
	}

	return i;
}
int length ( int a[] )
{
	int i = 0;

	while ( a[ i ] != 0 )
		i = i + 1;
	return i;
}

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}

int in_strings ( string a[], string b )
{
	int size = length( a );

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return i;
	return -1;
}
int count_in_strings ( string a[], string b )
{
	int size = length( a );

	int count = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			count = count + 1;
	return count;
}
void get_common_file ()
{
	common_iter = 0;

	ifstream fi;
	fi.open( "common_files/common" );

	string temp;

	while ( getline( fi, temp ) )
	{
		common[ common_iter ] = temp;
		common_iter = common_iter + 1;
	}

	fi.close();
}
void set_common_file ()
{
	ofstream fo;
	fo.open( "common_files/common" );
	for ( int i = 0; i < common_iter; i = i + 1 )
		fo << common[ i ] << '\n';
	fo.close();
}

void get_common ( int a, string strings[], int frev[] )
{
	for ( int i = 0; i < length( strings ); i = i + 1 )
		strings[ i ] = "";

	for ( int i = 0; i < length( frev ); i = i + 1 )
		frev[ i ] = 0;

	ifstream fi;
	fi.open( "common_files/" + common[ a ] );

	string temp;
	int strings_iter = 0;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		fi >> frev[ strings_iter ];
		strings_iter = strings_iter + 1;
	}

	fi.close();
}

double get_average_frev_common ( int a )
{
	string strings[ 10000 ];
	int frev[ 10000 ];

	get_common( a, strings, frev );
	double average_frev = 0;
	int size = length( strings );
	for ( int i = 0; i < size; i = i + 1 )
		average_frev = average_frev + frev[ i ];
	return average_frev / size;
}
double get_average_length_common ( int a )
{
	string strings[ 10000 ];
	int frev[ 10000 ];

	get_common( a, strings, frev );
	double average_frev = 0;
	int size = length( strings );
	for ( int i = 0; i < size; i = i + 1 )
		average_frev = average_frev + strings[ i ].length();
	return average_frev / size;
}
void get_common_frev ( string strings[], int frev[] )
{
	ifstream fi;
	fi.open( "common_files/common_frev" );
	string temp;


	int strings_iter = 0;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		fi >> frev[ strings_iter ];
		strings_iter = strings_iter + 1;
	}
	fi.close();
}
double get_common_frev_average ()
{
	string strings[ 10000 ];
	int frev[ 10000 ];

	get_common_frev( strings, frev );
	double average_frev = 0;
	int size = length( strings );
	for ( int i = 0; i < size; i = i + 1 )
		average_frev = average_frev + frev[ i ];
	return average_frev / size;
}
double get_common_length_average ()
{
	string strings[ 10000 ];
	int frev[ 10000 ];

	get_common_frev( strings, frev );
	double average_frev = 0;
	int size = length( strings );
	for ( int i = 0; i < size; i = i + 1 )
		average_frev = average_frev + strings[ i ].length();
	return average_frev / size;
}



int get_frev_of_common ( string a )
{
	ifstream fi;
	fi.open( "common_files/common_frev" );


	string temp;
	int frev_temp;
	while ( fi >> temp )
	{
		fi >> frev_temp;
		if ( temp == a )
			return frev_temp;
	}

	fi.close();

	return 0;
}


int pos ( int a )
{
	if ( a < 0 )
		return -a;
	return a;
}


void set_common ( int a, string strings[], int frev[] )
{

	ofstream fo;
	fo.open( "common_files/" + common[ a ] );

	fo.close(); // clear file

	fo.open( "common_files/" + common[ a ] );

	int strings_iter = length( strings );

	string strings_a[ 10000 ];
	int frev_a[ 10000 ];

	get_common_frev( strings_a, frev_a );

	int size = length( strings_a );

	string added[ 10000 ];
	int added_iter = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( in_strings( strings_a, strings[ i ] ) > size / 2 and in_strings( added, strings[ i ] ) == -1 )
		{
			fo << strings[ i ] << ' ' << frev[ i ] << '\n';
			// cout << strings[ i ] << ' ' << frev[ i ] << '\n';
			added[ added_iter ] = strings[ i ];
			added_iter = added_iter + 1;
			for ( int l = 0; l < strings_iter; l = l + 1 )
			{
				int frev_i = get_frev_of_common( strings[ i ] );
				int frev_l = get_frev_of_common( strings[ l ] );
				if ( pos( frev_l - frev_i < 10 ) )
				{
					if ( in_strings( added, strings[ l ] ) != -1 or i == l ) 
						continue;
					fo << strings[ l ] << ' ' << frev[ l ] << '\n';
					// cout << '\n' << strings[ l ] << ' ' << frev[ l ] << ' ' << frev_l << '\n';
					// cout << strings[ i ] << ' ' << frev[ i ] << ' ' << frev_i << "\n\n";
					added[ added_iter ] = strings[ l ];
					added_iter = added_iter + 1;
				}
			}
		}
	}

	fo.close();

	string common_a[ 10000 ];
	int frev_common_a[ 10000 ];
	int common_a_iter = 0;

	ifstream fi;
	fi.open( "common_files/" + common[ a ] );

	string temp;
	while ( fi >> temp )
	{
		common_a[ common_a_iter ] = temp;
		fi >> frev_common_a[ common_a_iter ];
		common_a_iter = common_a_iter + 1;
	}

	fi.close();


	int frev_temp;
	for ( int i = 0; i < common_a_iter; i = i + 1 )
		for ( int l = 0; l < common_a_iter; l = l + 1 )
			if ( frev_common_a[ l ] < frev_common_a[ i ] )
			{
				frev_temp = frev_common_a[ i ];
				temp = common_a[ i ];

				frev_common_a[ i ] = frev_common_a[ l ];
				common_a[ i ] = common_a[ l ];				

				frev_common_a[ l ] = frev_temp;
				common_a[ l ] = temp;
			}


	fo.open( "common_files/" + common[ a ] );
	fo.close(); // clear file

	fo.open( "common_files/" + common[ a ] );

	for ( int i = 0; i < common_a_iter; i = i + 1 )
		fo << common_a[ i ] << ' ' << frev_common_a[ i ] << '\n';

	fo.close();
}
void add_topic ( string a )
{
	if ( in_strings( common, a ) != -1 )
	{
		cout << "Already added!\n";
		return;
	}	

	common[ common_iter ] = a;
	common_iter = common_iter + 1;
	set_common_file();

	ofstream fo;
	fo.open( "common_files/" + a );
	fo.close(); // clear file
}

void remove_topic ( int a )
{
	ofstream fo;
	fo.open( "common_files/common" );
	for ( int i = 0; i < common_iter; i = i + 1 )
		if ( a != i )
			fo << common[ i ] << '\n';

	fo.close();
	get_common_file();
}

void show_common ()
{
	string strings[ 10000 ];
	int frev[ 10000 ];
	int size;

	for ( int i = 0; i < common_iter; i = i + 1 )
	{
		cout << common[ i ] << '\n';
		get_common( i, strings, frev );

		size = length( strings );
		for ( int l = 0; l < size; l = l + 1 )
		{
			cout << strings[ l ] << ' ' << frev[ l ]; 
			if ( l != size - 1 )
				cout << ", ";
		}
	}	
}

void show_common_files ()
{
	if ( common_iter == 0 )
	{
		cout << "0 available. Please add!\n";
		return;
	}

	int maximum[ 5 ];
	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = 0;

	for ( int i = 0; i < common_iter; i = i + 1 )
		if ( common[ i ].length() + length( i + 1 ) > maximum[ i % 5 ] )
			maximum[ i % 5 ] = common[ i ].length() + length( i + 1 );

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = maximum[ i ] + 2;

	int size;
	for ( int i = 0; i < common_iter; i = i + 1 )
	{
		cout << i + 1 << ". " << common[ i ] << ' ';
		size = common[ i ].length() + length( i + 1 );

		for ( int l = size; l < maximum[ i % 5 ]; l = l + 1 )
			cout << ' ';
		if ( i % 5 == 4 ) cout << '\n';
	}
	cout << "\n\n";
}
void show_common ( int a )
{
	string strings[ 10000 ];
	int frev[ 10000 ];
	int size;

	cout << common[ a ] << '\n';
	get_common( a, strings, frev );

	size = length( strings );

	if ( size == 0 )
	{
		cout << "Please add to topic!\n";
		return;
	}

	cout << "Average frev: " << get_average_frev_common( a ) << "\n";
	cout << "Average length: " << get_average_length_common( a ) << "\n";
	for ( int l = 0; l < size; l = l + 1 )
		{
			cout << strings[ l ] << ' ' << frev[ l ]; 
			if ( l != size - 1 )
				cout << ", ";
		}
	cout << "\n";
}

void files ()
{
	if ( common_iter == 0 )
	{
		cout << "Please add topics to remake them.\n";
		return;
	}


	string common_a[ 10000 ];
	int frev_a[ 10000 ];
	int common_a_iter;

	get_common_frev( common_a, frev_a );


	common_a_iter = length( common_a );

	if ( common_a_iter < 900 )
	{
		cout << "Only " << common_a_iter << " commons available. Please add until 900.\n";
		cout << "( in order to be efective )\n";
		return;
	}

	common_a[ common_a_iter / 2 ] = "";
	common_a_iter = length( common_a );


	ifstream fi;
	string temps[ 10000 ];
	int temps_frev[ 10000 ];
	int temps_iter;
	string temp;
	ofstream fo;
	for ( int i = 0; i < common_iter; i = i + 1 )
	{
		temps_iter = 0;
		fi.open( "common_files/" + common[ i ] );

		while ( fi >> temp )
		{
			if ( in_strings( common_a, temp ) == -1 )
			{
				temps[ temps_iter ] = temp;
				fi >> temps_frev[ temps_iter ];
				temps_iter = temps_iter + 1;
			}
			else
				fi >> temp;
		}

		fi.close();

		fo.open( "common_files/" + common[ i ] );
		fo.close(); // clear file

		fo.open( "common_files/" + common[ i ] );

		for ( int l = 0; l < temps_iter; l = l + 1 )
			fo << temps[ l ] << ' ' << temps_frev[ i ] << '\n';

		fo.close();
	}

	cout << "Files with topics were remade.\n";
}

void add_file ( string filename )
{
	string common_a[ 10000 ];
	int frev_a[ 10000 ];
	int common_iter_a = 0;


	ifstream fi;
	fi.open( "common_files/common_frev" );
	string temp;
	while ( fi >> temp )
	{
		common_a[ common_iter_a ] = temp;
		fi >> frev_a[ common_iter_a ];
		common_iter_a = common_iter_a + 1;
	}
	fi.close();
	common_iter_a = length( common_a );

	fi.open( filename );

	string strings[ 10000 ];
	int strings_iter = 0;

	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();


	string remain[ 10000 ];
	int remain_frev[ 10000 ];
	int remain_iter = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( in_strings( remain, strings[ i ] ) == -1 )
		{
			remain[ remain_iter ] = strings[ i ];
			remain_frev[ remain_iter ] = count_in_strings( strings, strings[ i ] );
			remain_iter = remain_iter + 1;
		}

	for ( int i = 0; i < remain_iter; i = i + 1 )
	{
		int l = in_strings( common_a, remain[ i ] );
		if ( l != -1 )
			frev_a[ l ] = frev_a[ l ] + remain_frev[ i ];
		else
		{
			common_a[ common_iter_a ] = remain[ i ];
			frev_a[ common_iter_a ] = remain_frev[ i ];
			common_iter_a = common_iter_a + 1;
		}
	}


	int frev_temp;
	for ( int i = 0; i < common_iter_a; i = i + 1 )
		for ( int l = 0; l < common_iter_a; l = l + 1 )
			if ( frev_a[ l ] < frev_a[ i ] )
			{
				frev_temp = frev_a[ i ];
				temp = common_a[ i ];

				frev_a[ i ] = frev_a[ l ];
				common_a[ i ] = common_a[ l ];				

				frev_a[ l ] = frev_temp;
				common_a[ l ] = temp;
			}

	string max_frev_string;
	int max_iter = 0;
	int max_frev = -1;

	for ( int i = 0; i < remain_iter; i = i + 1 )
		if ( remain_frev[ i ] >= max_frev and get_frev_of_common( remain[ i ] ) <= get_frev_of_common( common_a[ common_iter_a / 2 ] ) )
		{
			if ( remain_frev[ i ] == max_frev and get_frev_of_common( remain[ i ] ) <= get_frev_of_common( remain[ max_iter ] ) )
				continue;

			// cout << remain[ i ] << ' ' << remain[ max_iter ] << '\n';
			// cout << get_frev_of_common( common_a[ i ] ) << ' ' << get_frev_of_common( common_a[ i ] ) << "\n\n";

			max_frev = remain_frev[ i ];
			max_iter = i;
			max_frev_string = remain[ i ];
		}

	if ( max_frev != -1 )
		cout << "\"" << max_frev_string << "\" has max frev. ( " << max_frev << " ) in file ( could be topic ).\n";

	ofstream fo;
	fo.open( "common_files/common_frev" );

	for ( int i = 0; i < common_iter_a; i = i + 1 )
		fo << common_a[ i ] << ' ' << frev_a[ i ] << '\n';

	fo.close();
}


void add_file ( string filename, int a )
{
	string common_a[ 10000 ];

	int frev_a[ 10000 ];
	int common_iter_a;

	get_common( a, common_a, frev_a );
	common_iter_a = length( common_a );

	ifstream fi;
	fi.open( filename );

	string strings[ 10000 ];
	int strings_iter = 0;

	string temp;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();

	string remain[ 10000 ];
	int remain_frev[ 10000 ];
	int remain_iter = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( in_strings( remain, strings[ i ] ) == -1 )
		{
			remain[ remain_iter ] = strings[ i ];
			remain_frev[ remain_iter ] = count_in_strings( strings, strings[ i ] );
			remain_iter = remain_iter + 1;
		}

	for ( int i = 0; i < remain_iter; i = i + 1 )
	{
		int l = in_strings( common_a, remain[ i ] );
		if ( l != -1 )
			frev_a[ l ] = frev_a[ l ] + remain_frev[ i ];
		else
		{
			common_a[ common_iter_a ] = remain[ i ];
			frev_a[ common_iter_a ] = remain_frev[ i ];
			common_iter_a = common_iter_a + 1;
		}
	}
	set_common( a, common_a, frev_a );
}

void add_file ( string filename, string a )
{
	ifstream fi;
	fi.open( filename );

	string strings[ 10000 ];
	int strings_iter = 0;

	string temp;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();

	string remain[ 10000 ];
	int remain_frev[ 10000 ];
	int remain_iter = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( in_strings( remain, strings[ i ] ) == -1 )
		{
			remain[ remain_iter ] = strings[ i ];
			remain_frev[ remain_iter ] = count_in_strings( strings, strings[ i ] );
			remain_iter = remain_iter + 1;
		}

	add_topic( a );

	set_common( common_iter - 1, remain, remain_frev );
}
void continues ()
{
	char enter;
	cout << "[ ']' + Enter ] to continue: ";
	cin >> enter;
}

// check if a string is an int
bool is_int ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}
// convert string to int
int string_to_int ( string a )
{
	int size = a.length();

	int iter = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		iter = 1;
	}

	int num_int = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_int = num_int * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_int = -num_int;

	return num_int;
}

string upper ( string a )
{
	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;
	return a;
}





long get_file_num ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	long num = 0;
	while ( fi >> temp )
		num = num + 1;

	fi.close();

	return num;
}

void add_files ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;

	long file_iter = 0;

	ofstream fo;

	fo.open( "files" );

	while ( fi >> temp )
	{
		fo << temp << ' ';
		file_iter = file_iter + 1;

		if ( file_iter > 9000 )
		{
			fo.close();
			add_file( "files" );
			fo.open( "files" );
			fo.close();
			fo.open( "files" );
		}
	}

	fo.close();

	fi.close();
}

void add_files ( string filename, int num )
{
	ifstream fi;
	fi.open( filename );

	string temp;

	long file_iter = 0;

	ofstream fo;

	fo.open( "files" );

	while ( fi >> temp )
	{
		fo << temp << ' ';
		file_iter = file_iter + 1;

		if ( file_iter > 9000 )
		{
			fo.close();
			add_file( "files", num );
			fo.open( "files" );
			fo.close();
			fo.open( "files" );
		}
	}

	fo.close();

	fi.close();
}

void add_files ( string filename, string common_string )
{
	ifstream fi;
	fi.open( filename );

	string temp;

	long file_iter = 0;

	ofstream fo;

	fo.open( "files" );

	while ( fi >> temp )
	{
		fo << temp << ' ';
		file_iter = file_iter + 1;

		if ( file_iter > 9000 )
		{
			fo.close();
			add_file( "files", common_string );
			fo.open( "files" );
			fo.close();
			fo.open( "files" );
		}
	}

	fo.close();

	fi.close();
}

void add_files_size ( string filename )
{
	if ( get_file_num( filename ) > 9000 )
		add_files( filename );
	else
		add_file( filename );
}

void add_files_size ( string filename, int num )
{
	if ( get_file_num( filename ) > 9000 )
		add_files( filename, num );
	else
		add_file( filename, num );
}



void add_files_size ( string filename, string common_string )
{
	if ( get_file_num( filename ) > 9000 )
		add_files( filename, common_string );
	else
		add_file( filename, common_string );
}


int main ()
{
	get_common_file();

	for ( int i = 0; i < 10000; i = i + 1 )
	{
		cout << "choice";
		cout << "\033c";

		if ( i == 0 )
		{
			cout << "File \"common_files/common_frev\" - frev. for every file.\n";
			cout << "Average frev: " << get_common_frev_average() << '\n';
			cout << "Average length: " << get_common_length_average() << '\n';
			continues();
			continue;
		}

		cout << "Choices:\n";
		cout << "  1. Add File  2. Add topic  3. Remove topic  4. Show topics  5. Show topic\n";
		cout << " files. Remake files  exit. Exits\n\n";
		string choice;
		cout << "Choice: ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		if ( choice == "1" )
		{
			cout << "Filename: ";

			string filename;

			getline( cin, filename );
			if ( filename == "" )
				getline( cin, filename );

			add_files_size( filename );
			cout << "File added!\n";

			cout << "Add to a topic ( y / n ): ";
			getline( cin, choice );
			if ( choice == "" )
				getline( cin, choice );


			if ( choice == "y" )
			{
				show_common_files();

				cout << "( num of topic / name to add )\n";
				cout << "Add to: ";
				getline( cin, choice );
				if ( choice == "" )
					getline( cin, choice );

				if ( is_int( choice ) )
				{
					int common_int = string_to_int( choice );
					common_int = common_int - 1;
					if ( common_int < 0 or common_int >= common_iter )
						cout << "Invalid.\n";
					else
					{
						add_files_size( filename, common_int );
						cout << "File added to \"" << common[ common_int ] << "\"!\n";
					}
				}
				else
				{
					int l = in_strings( common, choice );
					if ( l != -1 )
					{
						add_files_size( filename, l );
						cout << "File added to \"" << common[ l ] << "\"!\n";
					}
					else
					{
						add_files_size( filename, upper( choice ) );
						cout << "File added to \"" << upper( choice ) << "\"!\n";
					}
				}
			}

			continues();
			continue;
		}

		if ( choice == "2" )
		{
			show_common_files();

			cout << "Name: ";
			string common_string;
			getline( cin, common_string );
			if ( common_string == "" )
				getline( cin, common_string );

			add_topic( upper( common_string ) );

			continues();
			continue;
		}

		if ( choice == "3" )
		{
			show_common_files();

			cout << "Remove topic: ";
			string common_string;
			getline( cin, common_string );
			if ( common_string == "" )
				getline( cin, common_string );

			if ( is_int( common_string ) )
			{
				int common_int = string_to_int( common_string );
				common_int = common_int - 1;
				if ( common_int < 0 or common_int >= common_iter )
					cout << "Invalid.\n";
				else
					remove_topic( common_int );
			}
			else
				cout << "Invalid.\n";

			add_topic( common_string );		
			continues();
			continue;
		}

		if ( choice == "4" )
		{
			show_common_files();
			continues();
			continue;
		}

		if ( choice == "5" )
		{
			show_common_files();

			cout << "( num of topic )\n";
			cout << "Show topic: ";
			string common_string;
			getline( cin, common_string );
			if ( common_string == "" )
				getline( cin, common_string );

			if ( is_int( common_string ) )
			{
				int common_int = string_to_int( common_string );
				common_int = common_int - 1;
				if ( common_int < 0 or common_int >= common_iter )
					cout << "Invalid.\n";
				else
					show_common( common_int );
			}
			else
				cout << "Invalid.\n";
			continues();
			continue;			
		}

		if ( choice == "files" )
		{
			files();
			continues();
			continue;			
		}

		if ( choice == "exit" )
		{
			cout << "Exited.\n";
			break;
		}
	}

	return 0;
}
