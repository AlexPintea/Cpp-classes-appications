#include <string>
#include <fstream>
#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
// length of an int[]
int length ( int a[] )
{
	int i = 0;
	while ( a[ i ] != 0 )
		i = i + 1;
	return i;
}
// length of a string[]
int length ( string a[] )
{
	int i = 0;
	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}
// length of an int
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
	return i;
}
// length of a double
int length ( double a )
{
	if ( a == 0 ) return 1;

	long a_int = length( (long) a );
	double decimals = a - a_int;

	long a_decimals = 0;
	while ( (float) a - (long) a != 0 )
	{
		a_decimals = a_decimals + 1;
		a = a * 10;
	}
	return a_int + a_decimals + 1;
}
// check if a string is a prime
bool prime ( int num )
{
	if ( num == 0 ) return 0;
	if ( num == 1 ) return 1;
	if ( num == 2 ) return 1;
	if ( num % 2 == 0 ) return 0;

	for ( int d = 3; d < num; d = d + 2 )
		if ( num % d == 0 )
			return 0;
	return 1;
}
bool is_upper ( string a )
{
	if ( a[ 0 ] >= 'A' and a[ 0 ] <= 'Z' )
		return 1;
	return 0;
}
bool is_all_upper ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'a' and a[ i ] <= 'z' )
			return 0;
	return 1;
}
bool is_all_lw ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			return 0;
	return 1;
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


string filename;
string filepath;
string ext;

void filename_ext ()
{
	
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			have_ext = true;

			break;
		}
	}

	if ( ! have_ext )
		return;

	int d = 0;
	for ( int i = filename.length() - 1; i >= 0; i = i - 1 )
		if ( filename[ i ] != '/' )
			d = i;
		else
			break;

	filepath = "";
	for ( int i = 0; i < d; i = i + 1 )
		filepath = filepath + filename[ i ];

	string file_name = "";
	int l = 0;
	for ( int i = d; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}

		file_name = file_name + filename[ i ];
	}

	for ( int i = l; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' ) continue;	

		ext = ext + filename[ i ];
	}

	filename = file_name;
}
int aproximate ( double a )
{
	if ( a - (int) a >= 0.5 )
		return (int) a + 1;
	return (int) a;
}

int count_total = 0;
int count_total_length = 0;
long ints[ 10000 ];
int ints_iter = 0;

double doubles[ 10000 ];
int doubles_iter = 0;

double max_double;
double min_double;
long max_int;
long min_int;

string max_string = "";
string min_string;

string max_string_length = "";
string min_string_length;

string strings[ 10000 ];
int strings_iter = 0;








int appears_int ( long a )
{
	int count = 0;
	for ( int i = 0; i < ints_iter; i = i + 1 )
		if ( ints[ i ] == a )
			count = count + 1;
	return count;
}
int appears_int ( int a[], long b )
{
	int count = 0;
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ] == b )
			count = count + 1;
	return count;
}
int appears_double ( double a )
{
	int count = 0;
	for ( int i = 0; i < doubles_iter; i = i + 1 )
		if ( doubles[ i ] == a )
			count = count + 1;
	return count;
}
int appears_string ( string a )
{
	int count = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( strings[ i ] == a )
			count = count + 1;
	return count;
}
int appears_string ( string a[], string b )
{
	int count = 0;
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ] == b )
			count = count + 1;
	return count;
}
int appears_string_length ( string a[], int l )
{
	int count = 0;
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ].length() == l )
			count = count + 1;
	return count;
}



string common[ 10000 ];
int common_iter;

void get_common ()
{
	ifstream fi;
	fi.open( "common" );

	string temp;
	while ( fi >> temp )
	{
		common[ common_iter ] = temp;
		common_iter = common_iter + 1;
	}

	fi.close();
}
bool is_common ( string a )
{
	for ( int i = 0; i < common_iter; i = i + 1 )
		if ( common[ i ] == a )
			return 1;
	return 0;
}








void get_file ()
{
	get_common();

	ifstream fi;
	fi.open( filename );

	string temp;

	string files[ 10000 ];

	while ( fi >> temp )
	{
		files[ count_total ] = temp;
		count_total = count_total + 1;
		count_total_length = count_total_length + temp.length();

		// Ints
		if ( is_long( temp ) )
		{
			long temp_int = string_to_long( temp );
			if ( ints_iter == 0 )
			{
				max_int = temp_int;
				min_int = temp_int;
			}
			ints[ ints_iter ] = temp_int;
			ints_iter = ints_iter + 1;
			if ( temp_int > max_int ) max_int = temp_int;
			if ( temp_int < min_int ) min_int = temp_int;
			continue;
		}		

		// Doubles
		if ( is_double( temp ) )
		{
			double temp_double = string_to_double( temp );
			if ( doubles_iter == 0 )
			{
				max_double = temp_double;
				min_double = temp_double;
			}
			doubles[ doubles_iter ] = temp_double;
			doubles_iter = doubles_iter + 1;
			if ( temp_double > max_double ) max_double = temp_double;
			if ( temp_double < min_double ) min_double = temp_double;
			continue;
		}

		// Strings
		if ( strings_iter == 0 )
		{
			max_string = temp;
			min_string = temp;
			max_string_length = temp;
			min_string_length = temp;
		}
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
		if ( temp > max_string ) max_string = temp;
		if ( temp < min_string ) min_string = temp;
		if ( temp.length() > max_string_length.length() ) max_string_length = temp;
		if ( temp.length() < min_string_length.length() ) min_string_length = temp;
	}

	fi.close();
	filename_ext();

	// Sort Ints	
	for ( int i = 0; i < ints_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < ints_iter; l = l + 1 )
			if ( ints[ i ] > ints[ l ] )
			{
				long temp_int = ints[ i ];
				ints[ i ] = ints[ l ];
				ints[ l ] = temp_int;
			}

	// Sort Doubles	
	for ( int i = 0; i < doubles_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < doubles_iter; l = l + 1 )
			if ( doubles[ i ] > doubles[ l ] )
			{
				double temp_double = doubles[ i ];
				doubles[ i ] = doubles[ l ];
				doubles[ l ] = temp_double;
			}

	// Sort Strings	
	for ( int i = 0; i < strings_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < strings_iter; l = l + 1 )
			if ( strings[ i ] > strings[ l ] )
			{
				temp = strings[ i ];
				strings[ i ] = strings[ l ];
				strings[ l ] = temp;
			}

	// Sort File	
	for ( int i = 0; i < count_total - 1; i = i + 1 )
		for ( int l = i + 1; l < count_total; l = l + 1 )
			if ( files[ i ] > files[ l ] )
			{
				temp = files[ i ];
				files[ i ] = files[ l ];
				files[ l ] = temp;
			}



	// Filename / Filepath	
	int count = 0;
	ofstream fo;
	fo.open( "result" );

	if ( ext != "" )
		fo << "Results of file \"" << filename << '.' << ext << "\" ";
	else
		fo << "Results of file \"" << filename << "\" ";

	if ( filepath != "" )
		fo << "( Filepath \"" << filepath << "\" )";
	fo << "\n\n";





	if ( strings_iter != 0 )
	{
		fo << "Strings:\n";

		// Determine count and average frev.
		int counts_string = 0;
		int max_frev_string = 0;
		double average_frev_string = 0;
		int counts_of_string[ 10000 ];

		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			count = appears_string( strings[ i ] );
			if ( count > max_frev_string )
				max_frev_string = count;
			average_frev_string = average_frev_string + count;
			if ( count != 1 )
				i = i + count - 1;
			counts_of_string[ counts_string ] = count;
			counts_string = counts_string + 1;
		}

		int average_frev_of_string = 0;
		int max_appears_string = 0;
		for ( int i = 1; i <= max_frev_string; i = i + 1 )
			if ( appears_int( counts_of_string, i ) > max_appears_string )
			{
				max_appears_string = appears_int( counts_of_string, i );
				average_frev_of_string = i;
			}

		int string_count_appear = 0;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			count = appears_string( strings[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			string_count_appear = string_count_appear + 1;
		}







		double average_string_length = 0;
		int length_strings[ 10000 ];
		string max_string_length = "";
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			average_string_length = average_string_length + strings[ i ].length();
			length_strings[ i ] = strings[ i ].length();
			if ( length_strings[ i ] > max_string_length.length() )
				max_string_length = strings[ i ];
		}
		average_string_length = average_string_length / strings_iter;

		int average_string_of_length = 0;
		int average_string_length_count = 0;
		for ( int i = 0; i <= max_string_length.length(); i = i + 1 )
			if ( appears_string_length( strings, strings[ i ].length() ) > average_string_length_count )
			{
				average_string_of_length = strings[ i ].length();
				average_string_length_count = appears_string_length( strings, strings[ i ].length() );
			}

		int string_count_appears = 0;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			count = appears_string( strings[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			string_count_appears = string_count_appears + 1;
		}

		fo << "\nStrings of file \"" << filename << "\" ( " << strings_iter << " total - " << string_count_appears <<  " dis. )\n";
		fo << "Average frev: " << average_frev_string / counts_string << " ( " << aproximate( average_frev_string / counts_string ) << " ) / most appear: ";
		fo << average_frev_of_string << '\n';




		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			count = appears_string( strings[ i ] );
			if ( count != 1 )
			{
				fo << "[ " << strings[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << strings[ i ] << ' ';
		}
		fo << "\n\n";

		string upper[ 10000 ];
		int upper_iter = 0;

		for ( int i = 0; i < strings_iter; i = i + 1 )
			if ( is_upper( strings[ i ] ) )
			{
				upper[ upper_iter ] = strings[ i ];
				upper_iter = upper_iter + 1;
			}

		fo << "Average string length: " << average_string_length << " ( " << aproximate( average_string_length ) << " ) / ";
		fo << "most have length " << average_string_of_length << "\n\n";




		int upper_count_appear = 0;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			if ( ! is_upper( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			upper_count_appear = upper_count_appear + 1;
		}


		fo << "Upper strings of file \"" << filename << "\" ( " << upper_iter << " total - " << upper_count_appear << "  dis. )\n";

		for ( int i = 0; i < upper_iter; i = i + 1 )
		{
			if ( ! is_upper( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
			{
				fo << "[ " << strings[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << strings[ i ] << ' ';
		}
		fo << "\n\n";

		int lw_count_appear = 0;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			if ( is_upper( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			lw_count_appear = lw_count_appear + 1;
		}

		fo << "Lw strings of file \"" << filename << "\" ( " << strings_iter - upper_iter << " total - " << lw_count_appear << " dis. )\n";

		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			if ( is_upper( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
			{
				fo << "[ " << strings[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << strings[ i ] << ' ';
		}



		string upper_all[ 10000 ];
		int upper_all_iter = 0;

		for ( int i = 0; i < strings_iter; i = i + 1 )
			if ( is_all_upper( strings[ i ] ) )
			{
				upper_all[ upper_all_iter ] = strings[ i ];
				upper_all_iter = upper_all_iter + 1;
			}

		fo << "\n\n";
		int upper_all_count_appear = 0;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			if ( ! is_all_upper( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			upper_all_count_appear = upper_all_count_appear + 1;
		}


		fo << "All Upper strings of file \"" << filename << "\" ( " << upper_all_iter << " total - " << upper_all_count_appear << " dis. )\n";

		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			if ( ! is_all_upper( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
			{
				fo << "[ " << strings[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << strings[ i ] << ' ';
		}
		fo << "\n\n";

		string lw_all[ 10000 ];
		int lw_all_iter = 0;

		for ( int i = 0; i < strings_iter; i = i + 1 )
			if ( is_all_lw( strings[ i ] ) )
			{
				lw_all[ lw_all_iter ] = strings[ i ];
				lw_all_iter = lw_all_iter + 1;
			}

		int lw_all_count_appear = 0;
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			if ( ! is_all_lw( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			lw_all_count_appear = lw_all_count_appear + 1;
		}


		fo << "All Lw strings of file \"" << filename << "\" ( " << lw_all_iter << " total - " << lw_all_count_appear << " dis. )\n";

		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			if ( ! is_all_lw( strings[ i ] ) ) continue;
			count = appears_string( strings[ i ] );
			if ( count != 1 )
			{
				fo << "[ " << strings[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << strings[ i ] << ' ';
		}
		fo << "\n\n";

		fo << "Max of strings: " << max_string << '\n';
		fo << "Min of strings: " << min_string << '\n';
		fo << "Max of strings ( max length = " << max_string_length.length() << " ): " << max_string_length << '\n';
		fo << "Min of strings ( min length = " << min_string_length.length() << " ): " << min_string_length << '\n';
		fo << "\n\n\n\n\n";
	}
	fo << "In total:\n\n";


	fo << "Count total: " << count_total << "\n";
	fo << "Count total length: " << count_total_length << "\n";
	fo << "Average length: " << (double) count_total_length / count_total << " ( " << aproximate( (double) count_total_length / count_total ) <<  " ) / most have length: ";



	int max_length = 0;
	for ( int i = 0; i < count_total; i = i + 1 )
		if ( files[ i ].length() > max_length )
			max_length = files[ i ].length();

	int average_length = 0;
	for ( int i = 1; i <= max_length; i = i + 1 )
		if ( appears_string_length( files, i ) > average_length )
			average_length = i;

	fo << average_length << '\n';

	if ( ext != "" )
		fi.open( filepath + filename + '.' + ext );
	else
		fi.open( filepath + filename );
		
	string file = "";
	string files_length[ 1000 ];
	int lines = 0;
	int line_length = 0;
	while ( getline( fi, temp ) )
	{
		files_length[ lines ] = temp;
		lines = lines + 1;
		line_length = line_length + temp.length();
		file = file + temp + '\n';
	}
	fi.close();

	fo << "Count total length ( with wh-space ): " << file.length() - 1 << "\n";

	int wh = file.length() - 1 - count_total_length;
	fo << "Wh-space: " << wh << "\n";


	fo << "Content / Wh-space: " << (double) count_total_length / ( file.length() - 1 ) * 100 << "% / " << (double) wh / ( file.length() - 1 ) * 100 << '%' << " ( ";
	fo << aproximate( (double) count_total_length / ( file.length() - 1 ) * 100 )<< "% / " << aproximate( (double) wh / ( file.length() - 1 ) * 100 ) << '%' << " )\n";
	

	fo << "Lines: " << lines << '\n';
	fo << "Average line length: " << (double) line_length / lines << " ( " << aproximate( (double) line_length / lines ) << " ) / most have length: ";

	max_length = 0;
	for ( int i = 0; i < lines; i = i + 1 )
		if ( files_length[ i ].length() > max_length )
			max_length = files_length[ i ].length();

	average_length = 0;
	for ( int i = 1; i <= max_length; i = i + 1 )
		if ( appears_string_length( files_length, i ) > average_length )
			average_length = i;

	fo << average_length << '\n';

	int average_total_frev = 0;
	int counts[ 10000 ];
	int counts_iter = 0;
	for ( int i = 0; i < count_total; i = i + 1 )
	{
		counts[ counts_iter ] = appears_string( files, files[ i ] );
		counts_iter = counts_iter + 1;
	}

	int average_total_frev_all = 0;
	for ( int i = 0; i < counts_iter; i = i + 1 )
	{
		average_total_frev_all = average_total_frev_all + counts[ i ];
		if ( appears_int( counts, counts[ i ] ) > average_total_frev )
			average_total_frev = counts[ i ];
	}

	fo << "Average frev: " << (double) average_total_frev_all / counts_iter << " ( " << aproximate( (double) average_total_frev_all / counts_iter ) << " ) / ";
	fo << "most appear " << average_total_frev << '\n';









	fo << "\n\n";


	string unc[ 10000 ];
	int unc_counts[ 10000 ];
	int unc_iter = 0;
	int unc_total_count = 0;

	string common_strings[ 10000 ];
	int common_strings_counts[ 10000 ];
	int common_strings_iter = 0;
	int common_strings_total_count = 0;

	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		int count = appears_string( strings[ i ] );
		if ( ! is_common( strings[ i ] ) )
		{
			unc[ unc_iter ] = strings[ i ];
			unc_counts[ unc_iter ] = count;
			unc_iter = unc_iter + 1;
		}
		else
		{
			common_strings[ common_strings_iter ] = strings[ i ];
			common_strings_counts[ common_strings_iter ] = count;
			common_strings_iter = common_strings_iter + 1;
		}
		if ( count > 1 )
			i = i + count - 1;
	}

	for ( int i = 0; i < unc_iter; i = i + 1 )
		unc_total_count = unc_total_count + unc_counts[ i ];

	for ( int i = 0; i < common_strings_iter; i = i + 1 )
		common_strings_total_count = common_strings_total_count + common_strings_counts[ i ];

	fo << "Uncommon words ( " << unc_total_count << " total - " << unc_iter << " dis. )\n";

	for ( int i = 0; i < unc_iter; i = i + 1 )
	{
		if ( unc_counts[ i ] != 1 )
			fo << "[ " << unc[ i ] << " (" << unc_counts[ i ] << ")] ";
		else
			fo << unc[ i ] << ' ';
	}
	fo << "\n\n";

	fo << "Uncommon words mentioned a lot / uncommon words total ( count )\n";

	double mentioned_average;
	int mentioned_count = 0;

	for ( int i = 0; i < unc_iter; i = i + 1 )
		if ( unc_counts[ i ] != 1 )
		{
			mentioned_average = mentioned_average + (double) unc_counts[ i ] / unc_total_count;
			mentioned_count = mentioned_count + 1;
		}

	mentioned_average = mentioned_average / mentioned_count;

	double mentioned[ 10000 ];
	string mentioned_string[ 10000 ];
	int mentioned_iter = 0;

	double temp_mentioned;
	string temp_string_mentioned;
	for ( int i = 0; i < unc_iter; i = i + 1 )
		if ( unc_counts[ i ] != 1 )
		{
			temp_mentioned = (double) unc_counts[ i ] / unc_total_count;
			if ( temp_mentioned > mentioned_average )
			{
				mentioned_string[ mentioned_iter ] = unc[ i ];
				mentioned[ mentioned_iter ] = temp_mentioned;
				mentioned_iter = mentioned_iter + 1;
			}
		}

	for ( int i = 0; i < mentioned_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < mentioned_iter; l = l + 1 )
			if ( mentioned[ i ] > mentioned[ l ] )
			{
				temp_string_mentioned = mentioned_string[ i ];
				temp_mentioned = mentioned[ i ];

				mentioned_string[ i ] = mentioned_string[ l ];
				mentioned[ i ] = mentioned[ l ];

				mentioned_string[ l ] = temp_string_mentioned;
				mentioned[ l ] = temp_mentioned;
			}

	for ( int i = 0; i < mentioned_iter; i = i + 1 )
		fo << mentioned_string[ i ] << " - " << mentioned[ i ] * 100  << "%\n";
	fo << "\n";

	fo << "Common words ( " << common_strings_total_count << " total - " << common_strings_iter << " dis. )\n";


	for ( int i = 0; i < common_strings_iter; i = i + 1 )
	{
		if ( common_strings_counts[ i ] != 1 )
			fo << "[ " << common_strings[ i ] << " (" << common_strings_counts[ i ] << ")] ";
		else
			fo << common_strings[ i ] << ' ';
	}
	fo << "\n\n";

	fo << "Uncommon words / total ( count ): " << (double) unc_total_count / count_total * 100 << "%\n";
	fo << "Uncommon words / total words ( count ): " << (double) unc_total_count / strings_iter * 100 << "%\n";

	int unc_length = 0;
	for ( int i = 0; i < strings_iter; i = i + 1 )
		if ( ! is_common( strings[ i ] ) )
			unc_length = unc_length + strings[ i ].length();
	fo << "Uncommon words / total and wh-space ( length ): " << (double) unc_length / ( file.length() - 1 ) * 100 << "%\n";

	fo << "Numerical Data: " << ints_iter + doubles_iter << " ( " << ints_iter << " ints, " << doubles_iter << " doubles ) " << (double) ( ints_iter + doubles_iter ) / count_total * 100 << "%\n";;

	fo << "Uncommon words and Numerical Data / total ( count ): " << (double) ( ints_iter + doubles_iter + unc_total_count ) / count_total * 100 << "%\n";


	int ints_length = 0;
	int doubles_length = 0;

	for ( int i = 0; i < ints_iter; i = i + 1 )
		ints_length = ints_length + length( ints[ i ] );

	for ( int i = 0; i < doubles_iter; i = i + 1 )
		doubles_length = doubles_length + length( doubles[ i ] );


	fo << "Uncommon words and Numerical Data / total and wh-space ( length ): " << (double) ( ints_length + doubles_length + unc_length ) / ( file.length() - 1 ) * 100 << "%\n";

	fo << "\n\n\n\n\n";



	// Ints
	if ( ints_iter != 0 ) 
	{
		fo << "Ints:\n";

		// Determine count and average frev.
		int counts_int = 0;
		int max_frev_int = 0;
		double average_frev_int = 0;
		int counts_of_int[ 10000 ];

		for ( int i = 0; i < ints_iter; i = i + 1 )
		{
			count = appears_int( ints[ i ] );
			if ( count > max_frev_int )
				max_frev_int = count;
			average_frev_int = average_frev_int + count;
			if ( count != 1 )
				i = i + count - 1;
			counts_of_int[ counts_int ] = count;
			counts_int = counts_int + 1;
		}

		int average_frev_of_int = 0;
		int max_appears_int = 0;
		for ( int i = 1; i <= max_frev_int; i = i + 1 )
			if ( appears_int( counts_of_int, i ) > max_appears_int )
			{
				max_appears_int = appears_int( counts_of_int, i );
				average_frev_of_int = i;
			}

		fo << "\nInts of file \"" << filename << "\" ( " << ints_iter << " total - " << counts_int << " dis. )\n";
		fo << "Average frev: " << average_frev_int / counts_int << " ( " << aproximate( average_frev_int / counts_int ) << " ) / most appear: ";

		fo << average_frev_of_int << '\n';

		for ( int i = 0; i < ints_iter; i = i + 1 )
		{
			count = appears_int( ints[ i ] );
			if ( count != 1 )
			{
				fo << "[" << ints[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << ints[ i ] << ' ';
		}
		fo << "\n\n";

		long even[ 10000 ];
		int even_iter = 0;
		long odd[ 10000 ];
		int odd_iter = 0;

		for ( int i = 0; i < ints_iter; i = i + 1 )
		{
			if ( ints[ i ] % 2 == 0 )
			{
				even[ even_iter ] = ints[ i ];
				even_iter = even_iter + 1;
			}
			else
			{
				odd[ odd_iter ] = ints[ i ];
				odd_iter = odd_iter + 1;
			}
		}



		int even_count_appear = 0;
		for ( int i = 0; i < even_iter; i = i + 1 )
		{
			count = appears_int( even[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			even_count_appear = even_count_appear + 1;
		}


		fo << "Even ints of file \"" << filename << "\" ( " << even_iter << " total - " << even_count_appear << " dis. )\n";

		for ( int i = 0; i < even_iter; i = i + 1 )
		{
			count = appears_int( even[ i ] );
			if ( count != 1 )
			{
				fo << "[" << even[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << even[ i ] << ' ';
		}

		fo << "\n\n";


		int odd_count_appear = 0;
		for ( int i = 0; i < odd_iter; i = i + 1 )
		{
			count = appears_int( odd[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			odd_count_appear = odd_count_appear + 1;
		}

		fo << "Odd ints of file \"" << filename << "\" ( " << odd_iter << " total - " << odd_count_appear << " dis. )\n";

		for ( int i = 0; i < odd_iter; i = i + 1 )
		{
			count = appears_int( odd[ i ] );
			if ( count != 1 )
			{
				fo << "[" << odd[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << odd[ i ] << ' ';
		}
		fo << "\n\n";


		long pos[ 10000 ];
		int pos_iter = 0;
		long neg[ 10000 ];
		int neg_iter = 0;

		for ( int i = 0; i < ints_iter; i = i + 1 )
		{
			if ( ints[ i ] >= 0 )
			{
				pos[ pos_iter ] = ints[ i ];
				pos_iter = pos_iter + 1;
			}
			else
			{
				neg[ neg_iter ] = ints[ i ];
				neg_iter = neg_iter + 1;
			}
		}


		int pos_count_appear = 0;
		for ( int i = 0; i < pos_iter; i = i + 1 )
		{
			count = appears_int( pos[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			pos_count_appear = pos_count_appear + 1;
		}

		fo << "Pos ints of file \"" << filename << "\" ( " << pos_iter << " total - " << pos_count_appear << " dis. )\n";

		for ( int i = 0; i < pos_iter; i = i + 1 )
		{
			count = appears_int( pos[ i ] );
			if ( count != 1 )
			{
				fo << "[" << pos[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << pos[ i ] << ' ';
		}
		fo << "\n\n";


		int neg_count_appear = 0;
		for ( int i = 0; i < neg_iter; i = i + 1 )
		{
			count = appears_int( neg[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			neg_count_appear = neg_count_appear + 1;
		}

		fo << "Neg ints of file \"" << filename << "\" ( " << neg_iter << " total - " << neg_count_appear << " dis. )\n";

		for ( int i = 0; i < neg_iter; i = i + 1 )
		{
			count = appears_int( neg[ i ] );
			if ( count != 1 )
			{
				fo << "[" << neg[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << neg[ i ] << ' ';
		}
		fo << "\n\n";





		long primes[ 10000 ];
		int primes_iter = 0;

		for ( int i = 0; i < ints_iter; i = i + 1 )
			if ( prime( ints[ i ] ) )
			{
				primes[ primes_iter ] = ints[ i ];
				primes_iter = primes_iter + 1;
			}

		int prime_count_appear = 0;
		for ( int i = 0; i < primes_iter; i = i + 1 )
		{
			count = appears_int( primes[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			prime_count_appear = prime_count_appear + 1;
		}

		fo << "Prime ints of file \"" << filename << "\" ( " << primes_iter << " total - " << prime_count_appear << " dis. )\n";

		for ( int i = 0; i < primes_iter; i = i + 1 )
		{
			count = appears_int( primes[ i ] );
			if ( count != 1 )
			{
				fo << "[" << primes[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << primes[ i ] << ' ';
		}
		fo << "\n\n";






		long squares[ 10000 ];
		int squares_iter = 0;

		for ( int i = 0; i < ints_iter; i = i + 1 )
			if ( (int) sqrt( ints[ i ] ) == sqrt( ints[ i ] ) )
			{
				squares[ squares_iter ] = ints[ i ];
				squares_iter = squares_iter + 1;
			}

		int square_count_appear = 0;
		for ( int i = 0; i < squares_iter; i = i + 1 )
		{
			count = appears_int( squares[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			square_count_appear = square_count_appear + 1;
		}

		fo << "Square ints of file \"" << filename << "\" ( " << squares_iter << " total - " << square_count_appear << " dis. )\n";

		for ( int i = 0; i < squares_iter; i = i + 1 )
		{
			count = appears_int( squares[ i ] );
			if ( count != 1 )
			{
				fo << "[" << squares[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << squares[ i ] << ' ';
		}
		fo << "\n\n";





		int remain[ 10000 ];
		int remain_iter = 0;

		for ( int i = 0; i < ints_iter - 1; i = i + 1 )
			if ( ints[ i + 1 ] - ints[ i ] > 1 )
				for ( int l = ints[ i ] + 1; l < ints[ i + 1 ]; l = l + 1 )
				{
					remain[ remain_iter ] = l;
					remain_iter = remain_iter + 1;
				}

		fo << "Remaining ints of file \"" << filename << "\" [ " << min_int << ", " << max_int << " ]\n";
		bool have_interval = 0;
		bool last_interval = 0;
		int last_int;

		// for ( int i = 0; i < remain_iter - 1; i = i + 1 )
		//	fo << remain[ i ] << ' ';
		// fo << "\n\n";

		for ( int i = 0; i < remain_iter - 1; i = i + 1 )
		{
			if ( have_interval == 0 )
			{
				last_int = remain[ i ];
				have_interval = 1;
			}

			if ( remain[ i + 1 ] - remain[ i ] == 1 and i + 1 != remain_iter - 1 )
				continue;

			if ( i + 1 == remain_iter - 1 )
			{
				if ( last_interval )
					fo << remain[ i + 1 ] << " ]";
				else
					fo << remain[ i + 1 ];
				have_interval = 0;
			}
			else
			{
				if ( remain[ i ] != last_int and remain[ i ] - last_int > 5 )
				{
					fo << "[ " << last_int << ", " << remain[ i ] << " ], ";
					last_interval = 1;
				}
				else
				{
					for ( int l = last_int; l <= remain[ i ]; l = l + 1 )
						fo << l << ", ";
					last_interval = 0;
				}
					
				have_interval = 0;
			}

		}


		fo << "\n\n";

		remain_iter = 0;


		fo << "Max of ints: " << max_int << '\n';
		fo << "Min of ints: " << min_int << '\n';
		fo << "\n\n\n\n\n";
	}


	if ( doubles_iter != 0 )
	{
		fo << "Doubles:\n";

		// Determine count and average frev.
		int counts_double = 0;
		int max_frev_double = 0;
		double average_frev_double = 0;
		int counts_of_double[ 10000 ];

		for ( int i = 0; i < doubles_iter; i = i + 1 )
		{
			count = appears_double( doubles[ i ] );
			if ( count > max_frev_double )
				max_frev_double = count;
			average_frev_double = average_frev_double + count;
			if ( count != 1 )
				i = i + count - 1;
			counts_of_double[ counts_double ] = count;
			counts_double = counts_double + 1;
		}

		int average_frev_of_double = 0;
		int max_appears_double = 0;
		for ( int i = 1; i <= max_frev_double; i = i + 1 )
			if ( appears_int( counts_of_double, i ) > max_appears_double )
			{
				max_appears_double = appears_int( counts_of_double, i );
				average_frev_of_double = i;
			}

		int double_count_appear = 0;
		for ( int i = 0; i < doubles_iter; i = i + 1 )
		{
			count = appears_double( doubles[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			double_count_appear = double_count_appear + 1;
		}

		fo << "\nDoubles of file \"" << filename << "\" ( " << doubles_iter << " total - " << double_count_appear <<  " dis. )\n";
		fo << "Average frev: " << average_frev_double / counts_double << " ( " << aproximate( average_frev_double / counts_double ) << " ) / most appear: ";
		fo << average_frev_of_double << '\n';


		for ( int i = 0; i < doubles_iter; i = i + 1 )
		{
			count = appears_double( doubles[ i ] );
			if ( count != 1 )
			{
				fo << "[" << doubles[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << doubles[ i ] << ' ';
		}
		fo << "\n\n";


		double pos_double[ 10000 ];
		int pos_double_iter = 0;
		double neg_double[ 10000 ];
		int neg_double_iter = 0;

		for ( int i = 0; i < doubles_iter; i = i + 1 )
		{
			if ( doubles[ i ] >= 0 )
			{
				pos_double[ pos_double_iter ] = doubles[ i ];
				pos_double_iter = pos_double_iter + 1;
			}
			else
			{
				neg_double[ neg_double_iter ] = doubles[ i ];
				neg_double_iter = neg_double_iter + 1;
			}
		}


		int pos_double_count_appear = 0;
		for ( int i = 0; i < pos_double_iter; i = i + 1 )
		{
			count = appears_double( pos_double[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			pos_double_count_appear = pos_double_count_appear + 1;
		}

		fo << "Pos doubles of file \"" << filename << "\" ( " << pos_double_iter << " total - " << pos_double_count_appear << " dis. )\n";

		for ( int i = 0; i < pos_double_iter; i = i + 1 )
		{
			count = appears_double( pos_double[ i ] );
			if ( count != 1 )
			{
				fo << "[" << pos_double[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << pos_double[ i ] << ' ';
		}
		fo << "\n\n";


		int neg_double_count_appear = 0;
		for ( int i = 0; i < neg_double_iter; i = i + 1 )
		{
			count = appears_double( neg_double[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			neg_double_count_appear = neg_double_count_appear + 1;
		}

		fo << "Neg doubles of file \"" << filename << "\" ( " << neg_double_iter << " total - " << neg_double_count_appear << " dis. )\n";

		for ( int i = 0; i < neg_double_iter; i = i + 1 )
		{
			count = appears_double( neg_double[ i ] );
			if ( count != 1 )
			{
				fo << "[" << neg_double[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << neg_double[ i ] << ' ';
		}
		fo << "\n\n";

		fo << "Max of doubles: " << max_double << '\n';
		fo << "Min of doubles: " << min_double << '\n';
		fo << "\n\n\n\n\n";
	}

	if ( ints_iter != 0 and doubles_iter != 0 )
	{
		fo << "Ints and Doubles:\n\n";

		double pos_all[ 10000 ];
		int pos_all_iter = 0;
		double neg_all[ 10000 ];
		int neg_all_iter = 0;

		for ( int i = 0; i < ints_iter; i = i + 1 )
		{
			if ( ints[ i ] >= 0 )
			{
				pos_all[ pos_all_iter ] = ints[ i ];
				pos_all_iter = pos_all_iter + 1;
			}
			else
			{
				neg_all[ neg_all_iter ] = ints[ i ];
				neg_all_iter = neg_all_iter + 1;
			}
		}

		for ( int i = 0; i < doubles_iter; i = i + 1 )
		{
			if ( doubles[ i ] >= 0 )
			{
				pos_all[ pos_all_iter ] = doubles[ i ];
				pos_all_iter = pos_all_iter + 1;
			}
			else
			{
				neg_all[ neg_all_iter ] = doubles[ i ];
				neg_all_iter = neg_all_iter + 1;
			}
		}

		// Sort Pos
		for ( int i = 0; i < pos_all_iter - 1; i = i + 1 )
			for ( int l = i + 1; l < pos_all_iter; l = l + 1 )
				if ( pos_all[ i ] > pos_all[ l ] )
				{
					double temp_double = pos_all[ i ];
					pos_all[ i ] = pos_all[ l ];
					pos_all[ l ] = temp_double;
				}

		// Sort Pos
		for ( int i = 0; i < neg_all_iter - 1; i = i + 1 )
			for ( int l = i + 1; l < neg_all_iter; l = l + 1 )
				if ( neg_all[ i ] > neg_all[ l ] )
				{
					double temp_double = neg_all[ i ];
					neg_all[ i ] = neg_all[ l ];
					neg_all[ l ] = temp_double;
				}

		int pos_all_count_appear = 0;
		for ( int i = 0; i < pos_all_iter; i = i + 1 )
		{
			if ( (long) pos_all[ i ] == pos_all[ i ] )
				count = appears_int( pos_all[ i ] );
			else
				count = appears_double( pos_all[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			pos_all_count_appear = pos_all_count_appear + 1;
		}

		fo << "Pos ints and doubles of file \"" << filename << "\" ( " << pos_all_iter << " total - " << pos_all_count_appear << " dis. )\n";

		for ( int i = 0; i < pos_all_iter; i = i + 1 )
		{
			if ( (long) pos_all[ i ] == pos_all[ i ] )
				count = appears_int( pos_all[ i ] );
			else
				count = appears_double( pos_all[ i ] );
			if ( count != 1 )
			{
				fo << "[" << pos_all[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << pos_all[ i ] << ' ';
		}
		fo << "\n\n";


		int neg_all_count_appear = 0;
		for ( int i = 0; i < neg_all_iter; i = i + 1 )
		{
			if ( (long) neg_all[ i ] == neg_all[ i ] )
				count = appears_int( neg_all[ i ] );
			else
				count = appears_double( neg_all[ i ] );
			if ( count != 1 )
				i = i + count - 1;
			neg_all_count_appear = neg_all_count_appear + 1;
		}

		fo << "Neg ints and doubles of file \"" << filename << "\" ( " << neg_all_iter << " total - " << neg_all_count_appear << " dis. )\n";

		for ( int i = 0; i < neg_all_iter; i = i + 1 )
		{
			if ( (long) neg_all[ i ] == neg_all[ i ] )
				count = appears_int( neg_all[ i ] );
			else
				count = appears_double( neg_all[ i ] );
			if ( count != 1 )
			{
				fo << "[" << neg_all[ i ] << ' ';
				fo << '(' << count << ")] ";
				i = i + count - 1;
			}
			else
				fo << neg_all[ i ] << ' ';
		}
	}


	fo.close();
}







int main ()
{
	cout << "Filename: ";
	getline( cin, filename );
	if ( filename == "" )
		getline( cin, filename );

	get_file();

	return 0;
}
