#include <string.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;


int num;
char l;
long long rows;
string names[100000] = {};
int types[100000] = {};

string filename;
string strings[ 100000 ];
int strings_iter = 0;

string type ( int a )
{
	if ( a == 1 ) return "int";
	if ( a == 2 ) return "string";
	if ( a == 3 ) return "double";
	if ( a == 4 ) return "char";
	if ( a == 5 ) return "bool";

	return "-1";
}

string type_sql ( int a )
{
	if ( a == 1 ) return "int";
	if ( a == 2 ) return "varchar(255)";
	if ( a == 3 ) return "double";
	if ( a == 4 ) return "char";
	if ( a == 5 ) return "bool";

	return "-1";
}





void get_strings()
{
	ifstream fi;
	fi.open( "strings" );

	string temp;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}

	fi.close();
}


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}

bool is_in ( string a[], string b )
{
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ] == b )
			return 1;
	return 0;
}


int main ()
{
	get_strings();
	cout << "Num. of columns: ";
	cin >> num;

	cout << "Num. of rows: ";
	cin >> rows;

	for ( int i = 0; i < num; i = i + 1 )
	{
		string temp;
		cout << "\nName of column " << i + 1 << ": ";
		getline( cin, temp );
		if ( temp == "" )
			getline( cin, temp );
		while ( is_in( names, temp ) )
		{
			cout << "Already mentioned!\nName of column " << i + 1 << ": ";
			getline( cin, temp );
			if ( temp == "" )
				getline( cin, temp );
		}
		names[ i ] = temp;
		cout << "1. int  2. string  3. double  4. char  5. bool\n";
		cout << "Column \"" << names[ i ] << "\" type: ";
		cin >> types[ i ];
	}


	cout << "\nFilename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	string choice;
	cout << "Make in Sql? ( y / n ): ";
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	ofstream fo;
	fo.open( filename );

	if ( choice == "y" )
	{
		string name;
		cout << "Name of table: ";
		getline( cin, name );

		if ( name == "" )
			getline( cin, name );


		string choice_iter;
		cout << "Self-iterating column \"id\"? ( y / n ): ";
		getline( cin, choice_iter );
		if ( choice_iter == "" )
			getline( cin, choice_iter );

		fo << "CREATE TABLE " << name << "\n(\n";
		if ( choice_iter == "y" )
			fo << "  id int,\n";			
		for ( int l = 0; l < num; l = l + 1 )
		{
			fo << "  " << names[ l ] << ' ' << type_sql( types[ l ] );
			if ( l != num - 1 )
				fo << ",\n";
		}
		fo << "\n);\n\n";

		for ( int i = 0; i < rows; i = i + 1 )
		{
			fo << "INSERT INTO " << name << " ( ";
			if ( choice_iter == "y" )
				fo << "id, ";			
			for ( int l = 0; l < num; l = l + 1 )
			{
				fo << names[ l ];
				if ( l != num - 1 )
					fo << ", ";
			}
			fo << " ) VALUES ( ";

			if ( choice_iter == "y" )
				fo << i;
			if ( num != 0 )
				fo << ", ";			

			for ( int l = 0; l < num; l = l + 1 )
			{
				if ( type( types[ l ] ) == "int" )
					fo << i + l + names[ l ].length() + strings[ i % strings_iter ].length() - 1;
				if ( type( types[ l ] ) == "string" or type( types[ l ] ) == "-1" )
					fo << "\"" << strings[ ( i + l + names[ l ].length() ) % strings_iter ] << "\"";
				if ( type( types[ l ] ) == "double" )
					fo << (double) ( i + l + 5 ) / 10 + (double) ( names[ l ].length() + strings[ i % strings_iter ].length() ) / ( i + 1 );
				if ( l != num - 1 )
					fo << ", ";
			}

			fo << " );\n";
		}
		
	}
	else
	{
		string choice_iter;
		cout << "Self-iterating column? ( y / n ): ";
		getline( cin, choice_iter );
		if ( choice_iter == "" )
			getline( cin, choice_iter );

		if ( choice_iter == "y" )
			fo << "\"self-iterating\" ";

		for ( int l = 0; l < num; l = l + 1 )
			fo << "\"" << names[ l ] << "\" ";
		fo << "\n\n";

		for ( int i = 0; i < rows; i = i + 1 )
		{
			if ( choice_iter == "y" )
				fo << i;
			if ( num != 0 )
				fo << ' ';

			for ( int l = 0; l < num; l = l + 1 )
			{

				if ( type( types[ l ] ) == "int" )
					fo << i + l + names[ l ].length() + names[ l ].length() - 5;
				if ( type( types[ l ] ) == "string" or type( types[ l ] ) == "-1" )
					fo << strings[ ( i + l + names[ l ].length() ) % strings_iter ];
				if ( type( types[ l ] ) == "double" )
					fo << (double) ( i + l + 5 ) / 10 + (double) names[ l ].length() / ( i + 1 );
				if ( type( types[ l ] ) == "char" )
					fo << 'f';
				if ( type( types[ l ] ) == "bool" )
					fo << 0;
				if ( l != num - 1 )
					fo << " ";
			}

			fo << "\n";
		}
	}

	fo.close();

	cout << "\nExited.\n";

	return 0;
}
