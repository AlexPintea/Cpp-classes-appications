#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string convert_1[ 10000 ];
double convert[ 10000 ];
string convert_2[ 10000 ];
int convert_iter = 0;

void get_converts ()
{
	ifstream fi;
	fi.open( "converts" );

	convert_iter = 0;

	string temp;
	while ( fi >> temp )
	{
		convert_1[ convert_iter ] = temp;
		fi >> convert[ convert_iter ];
		fi >> convert_2[ convert_iter ];
		convert_iter = convert_iter + 1;
	}

	fi.close();
}

void set_converts ()
{
	ofstream fo;
	fo.open( "converts" );
	fo.close(); // clear file

	fo.open( "converts" );

	for ( int i = 0; i < convert_iter; i = i + 1 )
		fo << convert_1[ i ] << ' ' << convert[ i ] << ' ' << convert_2[ i ] << '\n';

	fo.close();
}

void add_convert ( string convert1, double converts, string convert2 )
{
	convert_1[ convert_iter ] = convert1;
	convert[ convert_iter ] = converts;
	convert_2[ convert_iter ] = convert2;

	convert_iter = convert_iter + 1;

	set_converts();
}

void remove_convert ( int l )
{
	ofstream fo;
	fo.open( "converts" );
	fo.close(); // clear file

	fo.open( "converts" );

	for ( int i = 0; i < convert_iter; i = i + 1 )
		if ( i != l )
			fo << convert_1[ i ] << ' ' << convert[ i ] << ' ' << convert_2[ i ] << '\n';

	fo.close();
}

string upper ( string a )
{
	if( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;
	return a;
}

void show_converts ()
{
	if ( convert_iter == 0 )
	{
		cout << "Converts invalid. Please add.\n";
		return;
	}

	for ( int i = 0; i < convert_iter; i = i + 1 )
		cout << '"' << upper( convert_1[ i ] ) << "\" is " << convert[ i ] << " \"" << upper( convert_2[ i ] ) << "\"\n";
}

void show_converts_num ()
{
	if ( convert_iter == 0 )
	{
		cout << "Converts invalid. Please add.\n";
		return;
	}

	for ( int i = 0; i < convert_iter; i = i + 1 )
		cout << "  " << i + 1 << ". \"" << upper( convert_1[ i ] ) << "\" is " << convert[ i ] << " \"" << upper( convert_2[ i ] ) << "\"\n";

}




void edit_convert ( int l )
{
	cout << "Edit:  1. Convert1  2. Convert2  3. Convert\n";
	cout << "Choice: ";

	string choice;

	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "1" )
	{
		cout << "Convert1: ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		convert_1[ l ] = choice;
		set_converts();
		return;
	}

	if ( choice == "2" )
	{
		cout << "Convert2: ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		convert_2[ l ] = choice;
		set_converts();
		return;
	}

	if ( choice == "3" )
	{
		double converts;
		cout << "Convert: ";
		cin >> converts;

		convert[ l ] = converts;
		set_converts();
		return;
	}
}


void convert_choice ( int l )
{
	cout << "Convert:  1. \"" << upper( convert_1[ l ] ) << "\" to \"" << upper( convert_2[ l ] ) << "\"  2. \"" << upper( convert_2[ l ] ) << "\" to \"" << upper( convert_1[ l ] ) << "\"\n";
	cout << "Choice: ";

	string choice;
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "1" )
	{
		cout << '"' << upper( convert_1[ l ] ) << "\": ";
		double convert1;
		cin >> convert1;

		cout << convert1 << " \"" << upper( convert_1[ l ] ) << "\" is " << convert1 / ( 1 / convert[ l ] ) << " \"" << upper( convert_2[ l ] ) << "\"\n";
	}

	if ( choice == "2" )
	{
		cout << '"' << upper( convert_2[ l ] ) << "\": ";
		double convert2;
		cin >> convert2;

		cout << convert2 << " \"" << upper( convert_2[ l ] ) << "\" is " << convert2 / convert[ l ] << " \"" << upper( convert_1[ l ] ) << "\"\n";
	}
}

int main ()
{
	get_converts();

//	for ( int i = 0; i < 10000; i = i + 1 )
//	{
		cout << "\033c";
		cout << "Choices:  1. Convert  2. Add Convert  3. Edit Convert  4. Remove Convert  5. Show Converts\n";
		cout << "Choice: ";

		string choice;
		getline( cin, choice );


		if ( choice == "1" )
		{
			cout << "\nConverts:\n";
			show_converts_num();

			cout << "\nConvert: ";

			int convert_num;
			cin >> convert_num;

			if ( convert_num <= 0 or convert_num > convert_iter )
				cout << "Invalid.\n";
			else
			{
				convert_num = convert_num - 1;
				convert_choice( convert_num );
			}

		}


		if ( choice == "2" )
		{
			string convert1;
			double converts;
			string convert2;

			cout << "\nConvert 1: ";
			getline( cin, convert1 );
			if ( convert1 == "" )
				getline( cin, convert1 );

			cout << "Convert: ";
			cin >> converts;

			cout << "Convert 2: ";
			getline( cin, convert2 );
			if ( convert2 == "" )
				getline( cin, convert2 );

			add_convert( convert1, converts, convert2 );
		}





		if ( choice == "3" )
		{
			cout << "\nConverts:\n";
			show_converts_num();

			int choice_edit;
			cout << "\nEdit: ";
			cin >> choice_edit;

			if ( choice_edit <= 0 or choice_edit > convert_iter )
				cout << "Invalid.\n";
			else
			{
				choice_edit = choice_edit - 1;
				edit_convert( choice_edit );
			}
		}

		if ( choice == "4" )
		{
			cout << "\nConverts:\n";
			show_converts_num();

			int choice_remove;
			cout << "\nRemove: ";
			cin >> choice_remove;

			if ( choice_remove <= 0 or choice_remove > convert_iter )
				cout << "Invalid.\n";
			else
			{
				choice_remove = choice_remove - 1;
				remove_convert( choice_remove );
			}
		}

		if ( choice == "5" )
		{
			cout << "\nConverts:\n";
			show_converts();
		}
//	}

	return 0;
}
