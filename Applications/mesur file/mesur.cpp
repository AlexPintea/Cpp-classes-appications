#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;

double measure[ 10000 ];
int measure_iter = 0;

double err[ 10000 ];
int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}
// length of an int
int length ( long a )
{
	if ( a == 0 ) return 1;
	int i = 0;

	while ( a != 0 )
	{
		i = i + 1;
		a = a / 10;
	}

	if ( a >= 0 )
		return i;
	else
		return i + 1;
}
// length of a double
int length ( double a )
{
	if ( a == 0 ) return 1;

	long a_int = length( (long) a );
	double decimals = a - (long) a;

	long a_decimals = 0;
	while ( (float) a - (long) a != 0 )
	{
		a_decimals = a_decimals + 1;
		a = a * 10;
	}

	int result = a_int + a_decimals;

	if ( a < 0 )
		result = result + 1;

	if ( decimals != 0 )
		result = result + 1;

	return result;
}

bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}

void continues ()
{
	char enter;
	cout << "\n[ ']' + Enter ] to continue: ";
	cin >> enter;
}

// check if a string is a long
bool is_long ( string a )
{
	int size = a.length();

	if ( size > 19 and a[0] == '-' )
		return false;
	if ( size >= 19 and a[0] != '-' )
		return false;

	for ( int i=0; i<size; i=i+1 )
		if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
			return false;

	return true;
}
// convert string to long
long string_to_long ( string a )
{
	if ( a.length() == 1 )
		return a[0] - 48;

	int size = a.length();

	int iter = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		iter = 1;
	}

	long num_long = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_long = num_long * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_long = -num_long;

	return num_long;
}
// check if a string is a double
bool is_double ( string a )
{
	int size = a.length();
	bool have_decimals = false;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( !( ( a[i] >= '0' and a[i] <= '9' ) or a[i] == '.' or a[i] == '-' ) )
			return false;
		if ( a[i] == '.' )
			have_decimals = true;
	}

	if ( have_decimals )
		return true;

	return false;
}
// convert string to double
double string_to_double ( string a )
{
	if ( a.length() == 1 )
		return a[0] - 48;

	if ( is_long( a ) )
		return string_to_long(a);


	double num_double = 0;

	int i = 0;
	bool is_neg = false;
	if ( a[0] == '-' )
	{
		is_neg = true;
		i = 1;
	}


	while ( a[i] != '.' )
	{
		num_double = num_double * 10 + ( a[i] - 48 );
		i = i + 1;
	}

	i = i + 1;
	int decimal_tens = 10;

	while ( a[i] )
	{
		double temp = a[i] - 48;
		num_double = num_double + temp / decimal_tens ;
		decimal_tens = decimal_tens * 10;
		i = i + 1;
	}

	if ( is_neg )
		num_double = -num_double;

	return num_double;
}
string upper ( string a )
{
	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;

	return a;
}


string files[ 10000 ];
int files_iter = 0;



void set_file ( int file_num, bool have_large )
{
	string filename;
	for ( int i = 0; i < files_iter; i = i + 1 )
		if ( i == file_num )
		{
			ifstream fi;
			fi.open( "mesur_file/" + files[ i ] );

			filename = files[ i ];

			double d;
			while ( fi >> d )
			{
				measure[ measure_iter ] = d;
				measure_iter = measure_iter + 1;
			}

			fi.close();
			break;
		}

	if ( measure_iter == 0 )
	{
		ofstream fo;
		fo.open( filename );
		fo << "Data invalid. Add data to measurement \"" << filename << "\" to get results.";
		fo.close();
		return;
	}

	double max_error;
	if ( have_large )
	{
		cout << "Max error: ";
		cin >> max_error;
	}

	double average = 0;
	double average_err = 0;


	for ( int i = 0; i < measure_iter; i = i + 1 )
		average = average + measure[ i ];
	average = average / measure_iter;

	for ( int i = 0; i < measure_iter; i = i + 1 )
	{
		if ( measure[ i ] > average )
			err[ i ] = measure[ i ] - average;
		else
			err[ i ] = average - measure[ i ];
		average_err = average_err + err[ i ];
	}
	average_err = average_err / measure_iter;

	if ( have_large )
	{
		average = 0;
		average_err = 0;

		double remain[ 10000 ];
		int remain_iter = 0;

		for ( int i = 0; i < measure_iter; i = i + 1 )
			if ( err[ i ] <= max_error )
			{
				remain[ remain_iter ] = measure[ i ];
				remain_iter = remain_iter + 1;
			}

		for ( int i = 0; i < measure_iter; i = i + 1 )
			measure[ i ] = 0;


		for ( int i = 0; i < measure_iter; i = i + 1 )
			err[ i ] = 0;

		for ( int i = 0; i < remain_iter; i = i + 1 )
			measure[ i ] = remain[ i ];
		measure_iter = remain_iter;

		for ( int i = 0; i < measure_iter; i = i + 1 )
			average = average + measure[ i ];
		average = average / measure_iter;

		

		for ( int i = 0; i < measure_iter; i = i + 1 )
		{
			if ( measure[ i ] > average )
				err[ i ] = measure[ i ] - average;
			else
				err[ i ] = average - measure[ i ];
			average_err = average_err + err[ i ];
		}
		average_err = average_err / measure_iter;
	}

	string measure_string = upper( filename );
	string average_string = "Average";
	string err_string = "Error";
	string average_err_string = "Average-Error";
	

	int maximum[ 5 ];
	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = 0;

	if ( measure_string.length() > maximum[ 0 ] ) maximum[ 0 ] = measure_string.length();
	if ( average_string.length() > maximum[ 1 ] ) maximum[ 1 ] = average_string.length();
	if ( err_string.length() > maximum[ 2 ] ) maximum[ 2 ] = err_string.length();
	if ( average_err_string.length() > maximum[ 3 ] ) maximum[ 3 ] = average_err_string.length();

	if ( (float) average - (long) average == 0 )
		if ( length( (long) average ) > maximum[ 1 ] ) maximum[ 1 ] = length( (long) average );
	else
		if ( length( average ) > maximum[ 1 ] ) maximum[ 1 ] = length( average );

	if ( (float) average_err - (long) average_err == 0 )
		if ( length( (long) average_err ) > maximum[ 3 ] ) maximum[ 3 ] = length( (long) average_err );
	else
		if ( length( average_err ) > maximum[ 3 ] ) maximum[ 3 ] = length( average_err );


	for ( int i = 0; i < measure_iter; i = i + 1 )
	{
		if ( (float) measure[ i ] - (long) measure[ i ] == 0 )
		{
			if ( length( (long) measure[ i ] ) > maximum[ 0 ] ) maximum[ 0 ] = length( (long) measure[ i ] );
		}
		else
			if ( length( measure[ i ] ) > maximum[ 0 ] ) maximum[ 0 ] = length( measure[ i ] );

		if ( (float) err[ i ] - (long) err[ i ] == 0 )
		{
			if ( length( (long) err[ i ] ) > maximum[ 2 ] ) maximum[ 2 ] = length( (long) err[ i ] );
		}
		else
			if ( length( err[ i ] ) > maximum[ 2 ] ) maximum[ 2 ] = length( err[ i ] );
	}

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = maximum[ i ] + 2;


	ofstream fo;
	fo.open( measure_string );

	fo << '"' << measure_string << "\" measurement results\n\n";

	fo << filename << " = " << average << " +- " << average_err << "\n\n";
	
	fo << measure_string;
	for ( int i = measure_string.length(); i < maximum[ 0 ]; i = i + 1 )
		fo << ' ';

	fo << average_string << ' ';
	for ( int i = average_string.length(); i < maximum[ 1 ]; i = i + 1 )
		fo << ' ';

	fo << err_string << ' ';
	for ( int i = err_string.length() + 2; i < length( err[ 0 ] ); i = i + 1 )
		fo << ' ';

	fo << average_err_string << ' ';
	fo << "\n\n";

	int length_measure;
	for ( int i = 0; i < measure_iter; i = i + 1 )
	{
		fo << measure[ i ];
		if ( (float) measure[ i ] - (long) measure[ i ] == 0 )
			length_measure = length( (long) measure[ i ] );
		else
			length_measure = length( measure[ i ] );
		for ( int l = length_measure; l < maximum[ 0 ]; l = l + 1 )
			fo << ' ';

		if ( i == 0 )
		{
			fo << average << ' ';
			if ( (float) average - (long) average == 0 )
				length_measure = length( (long) average );
			else
				length_measure = length( average );
			for ( int l = length_measure; l < maximum[ 1 ]; l = l + 1 )
				fo << ' ';
		}
		else
			for ( int l = 0; l <= maximum[ 1 ]; l = l + 1 )
				fo << ' ';

		if ( i != 0 )
		{
			fo << err[ i ] << ' ';
			if ( (float) err[ i ] - (long) err[ i ] == 0 )
				length_measure = length( (long) err[ i ] );
			else
				length_measure = length( err[ i ] );
			for ( int l = length_measure; l < maximum[ 0 ]; l = l + 1 )
				fo << ' ';
		}
		else
			fo << ' ' << err[ i ] << "  ";

		if ( i == 0 )
			fo << average_err << ' ';

		fo << '\n';
	}

	fo.close();

	for ( int i = 0; i < measure_iter; i = i + 1 )
		measure[ i ] = 0;;
	measure_iter = 0;
}


void get_files ()
{
	ifstream fi;
	fi.open( "mesur_file/mesur" );

	string temp;
	while ( fi >> temp )
	{
		files[ files_iter ] = upper( temp );
		files_iter = files_iter + 1;
	}

	fi.close();
}





void set_files ()
{
	ofstream fo;

	fo.open( "mesur_file/mesur" );

	for ( int l = 0; l < files_iter; l = l + 1 )
	 	fo << files[ l ] << ' ';

	fo.close();
}

void add_file ( string a )
{
	files[ files_iter ] = a;
	files_iter = files_iter + 1;
	set_files();
}


void remove_file ( int a )
{
	ofstream fo;

	fo.open( "mesur_file/mesur" );

	for ( int l = 0; l < files_iter; l = l + 1 )
		if ( l != a )
		 	fo << files[ l ] << ' ';

	fo.close();

	get_files();
}







string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";

	while ( fi >> temp )
		file = file + temp + '\n';

	fi.close();
	return file;
}

void add_data ( int a, double d )
{
	string filename = files[ a ];
	string file = get_file( "mesur_file/" + filename );

	ofstream fo;
	fo.open( "mesur_file/" + filename );
	fo.close(); // clear file

	fo.open( "mesur_file/" + filename );

	fo << file << d;

	fo.close();
}


void show_columns ( string data_temp[] )
{
	int maximum[ 10 ];
	int temp_iter = length( data_temp );

	if ( temp_iter == 0 )
	{
		cout << "0 to show. Please add!\n";
		return;
	}

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = 0;

	for ( int i = 0; i < temp_iter; i = i + 1 )
		if ( data_temp[ i ].length() > maximum[ i % 5 ] )
			maximum[ i % 5 ] = data_temp[ i ].length();

	for ( int i = 0; i < 5; i = i + 1 )
		maximum[ i ] = maximum[ i ] + 2;

	for ( int i = 0; i < temp_iter; i = i + 1 )
	{
		if ( i % 5 == 0 )
			cout << "  ";

		cout << i + 1 << ". " << data_temp[ i ] << "  ";
		for ( int l = data_temp[ i ].length() + length( (long) ( i + 1 ) ); l < maximum[ i % 5 ]; l = l + 1 )
			cout << ' ';
		if ( i % 5 == 4 )
			cout << '\n';
	}

	if ( ( temp_iter - 1 ) % 5 == 4 )
		cout << '\n';
	else
		cout << "\n\n";
}

void get_data ( int file_num, string data_temp[] )
{
	string filename = files[ file_num ];
	ifstream fi;
	fi.open( "mesur_file/" + filename );

	string temp;
	int temp_iter = 0;

	while ( fi >> temp )
	{
		data_temp[ temp_iter ] = temp;
		temp_iter = temp_iter + 1;
	}

	fi.close();
}

void show_data ( int file_num )
{
	string filename = files[ file_num ];

	string temp;
	string data_temp[ 1000 ];
	get_data( file_num, data_temp );
	int temp_iter = length( data_temp );

	cout << '"' << filename << "\" data:\n";	
	show_columns( data_temp );
}

void remove_data ( int a )
{
	string filename = files[ a ];

	string data_temp[ 1000 ];
	get_data( a, data_temp );
	int temp_iter = length( data_temp );

	show_data( a );

	int data_int = 0;
	cout << "Remove data: ";

	cin >> data_int;

	data_int = data_int - 1;

	if ( data_int < 0 or data_int >= temp_iter )
	{
		cout << data_int << ' ' << temp_iter << ' ';
		cout << "Invalid.\n";
		return;
	}

	ofstream fo;
	fo.open( "mesur_file/" + filename );
	fo.close(); // clear file

	fo.open( "mesur_file/" + filename );

	for ( int i = 0; i < temp_iter; i = i + 1 )
		if ( i != data_int )
			fo << data_temp[ i ] << '\n';

	fo.close();
}

void show_files ()
{
	cout << "Measurements:\n";
	show_columns( files );
}













int main ()
{
	get_files();

	for ( int i = 0; i < 10000; i = i + 1 )
	{

		cout << "choice";
		cout << "\033c";
		cout << "Choices:\n";
		cout << "  1. Add   2. Remove  3. Get Results  4. Add Data  5. Remove Data\n";
		cout << "  6. Show  7. Show Data\n";
		cout << "\nChoice: ";

		string choice;
		getline( cin, choice );

		if ( choice == "" )
			getline( cin, choice );

		cout << "choice";
		cout << "\033c";

		if ( choice == "1" )
		{
			cout << "Name of measurement to add: ";
			getline( cin, filename );
			if ( filename == "" )
				getline( cin, filename );

			add_file( upper( filename ) );
			cout << "Measurement \"" << upper( filename ) << "\" added.\n";
			continues();
			continue;
		}

		if ( choice == "2" )
		{
			show_files();

			cout << "Remove measurement: ";


			int file_num = 0;
			cin >> file_num;

			file_num = file_num - 1;



			if ( file_num < 0 or file_num >= files_iter )
				cout << "Invalid.\n";
			else
			{
				string filename = files[ file_num ];
				remove_file( file_num );
				cout << "Measurement \"" << filename << "\" removed.\n";
			}
			continues();
			continue;
		}


		if ( choice == "3" )
		{
			show_files();
			int file_num;

			cout << "Get results of measurement: ";
			cin >> file_num;

			file_num = file_num - 1;

			if ( file_num < 0 or file_num >= files_iter )
				cout << "Invalid.\n";
			else
			{

				cout << "Remove large errors ( y / n ): ";

				getline( cin, choice );
				if ( choice == "" )
					getline( cin, choice );


				if ( choice == "y" )
					set_file( file_num, 1 );
				else
					set_file( file_num, 0 );

				cout << "Results set in file \"" << files[ file_num ] << "\".\n";
			}
			continues();
			continue;
		}

		if ( choice == "4" )
		{
			show_files();

			cout << "Add data to measurement: ";

			int file_num;
			cin >> file_num;

			file_num = file_num - 1;

			if ( file_num < 0 or file_num >= files_iter )
			{
				cout << "Invalid.\n";
				continues();
				continue;
			}

			cout << "Choices:  1. Data  2. Data file\n";
			cout << "Choice: ";

			getline( cin, choice );
			if ( choice == "" )
				getline( cin, choice );

			if ( choice == "1" )
			{
				cout << "Measured data ( empty means done )\n";

				int i = 0;
				string temp = "measure string";
				while ( ! is_string_empty( temp ) )
				{
					cout << i + 1 << ". ";
					i = i + 1;
					getline( cin, temp );

					if ( is_string_empty( temp ) )
						break;

					double d;
					if ( is_double( temp ) )
						d = string_to_double( temp );
					if ( is_long( temp ) )
						d = (double) string_to_long( temp );


					add_data( file_num, d );
				}
			}
			else
			{
				cout << "Filename: ";
				string filename;
				getline( cin, filename );

				if ( filename == "" )
					getline( cin, filename );

				ifstream fi;
				fi.open( filename );

				string temp;
				while ( fi >> temp )
				{
					if ( is_string_empty( temp ) )
						break;

					double d = 0;
					if ( is_double( temp ) )
						d = string_to_double( temp );
					if ( is_long( temp ) )
						d = (double) string_to_long( temp );

					add_data( file_num, d );
				}

				fi.close();
			}
			cout << "Data added.\n";
			continues();
			continue;
		}

		if ( choice == "5" )
		{
			show_files();


			int file_num;
			cout << "Remove data of measurement: ";
			cin >> file_num;

			file_num = file_num - 1;

			if ( file_num < 0 or file_num >= files_iter )
				cout << "Invalid.\n";
			else
			{
				remove_data( file_num );
				cout << "Data removed.\n";
			}
			continues();
			continue;
		}

		if ( choice == "6" )
		{
			show_files();
			continues();
			continue;
		}

		if ( choice == "7" )
		{
			show_files();


			int file_num;
			cout << "Show data of measurement: ";
			cin >> file_num;

			file_num = file_num - 1;

			if ( file_num < 0 or file_num >= files_iter )
				cout << "Invalid.\n";
			else
				show_data( file_num );
			continues();
			continue;

			// cout << "Exited measurements.\n";
			// break;
		}
	}

	return 0;
}
