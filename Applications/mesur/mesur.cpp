#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;

double measure[ 10000 ];
int measure_iter = 0;

double err[ 10000 ];
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




void set_file ()
{
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

	fo << err_string;
	for ( int i = err_string.length() + 1; i < length( err[ 0 ] ); i = i + 1 )
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
}







int main ()
{
	cout << "Name of measurement: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	cout << "Choices:  1. Data  2. Data file\n";
	cout << "Choice: ";

	string choice;
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( choice == "1" )
	{
		cout << "Measured data ( empty means done )\n";

		string temp = "measure string";
		while ( ! is_string_empty( temp ) )
		{
			cout << measure_iter + 1 << ". ";

			getline( cin, temp );
			if ( temp == "" )
				getline( cin, temp );

			if ( is_string_empty( temp ) )
				break;

			if ( is_double( temp ) )
			{
				measure[ measure_iter ] = string_to_double( temp );
				measure_iter = measure_iter + 1;
			}
			if ( is_long( temp ) )
			{
				measure[ measure_iter ] = string_to_long( temp );
				measure_iter = measure_iter + 1;
			}
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

			if ( is_double( temp ) )
			{
				measure[ measure_iter ] = string_to_double( temp );
				measure_iter = measure_iter + 1;
			}
			if ( is_long( temp ) )
			{
				measure[ measure_iter ] = string_to_long( temp );
				measure_iter = measure_iter + 1;
			}
		}

		fi.close();
	}

	set_file();

	return 0;
}
