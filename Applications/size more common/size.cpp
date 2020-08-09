#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


string filename;
string filepath;
string ext;

string topic[ 1000 ];
double average_topics = 0;
double average[ 1000 ];
int count[ 1000 ];
int count_topics = 0;

int count_average = 0;
int file_iter = 0;


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


// converts a double to a string
string double_to_string ( double a )
{
	bool is_neg = false;
	if ( a < 0 )
		is_neg = true;

	int iter = length( (long) a );

	while ( (float) a - (long) a != 0.0 ) // 3 decimals maximum since float
		a = a * 10;



	int a_as_int;

	if ( is_neg )
		a_as_int = -(long) a;
	else
		a_as_int = (long) a;



	int size = length(a_as_int);

	int num_digits[170];
	for ( int i=0; i<size; i=i+1 )
	{
		num_digits[ size - i - 1 ] = (int) (a_as_int%10);
		a_as_int = a_as_int / 10;
	}


	string result = "";
	if ( is_neg )
		result = result + '-';
	for ( int i=0; i<size; i=i+1 )
	{
		if ( i == iter )
			result = result + '.';

		result = result + (char) ( num_digits[i] + 48 );
	}

	return result;
}


int length ( double a )
{
	return double_to_string( a ).length();
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
	for ( int i = 0; i < length( a ); i = i + 1 )
		if ( a[ i ] == b )
			return i;
	return -1;
}

void continues ()
{
	char enter;
	cout << "[ ']' + Enter ] to continue: ";
	cin >> enter;
}

// convert string to int
int string_to_int ( string a )
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

	int num_int = 0;

	for ( int i=iter; i<size; i=i+1 )
		num_int = num_int * 10 + ( a[i] - 48 );

	if ( is_neg )
		num_int = -num_int;

	return num_int;
}
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

bool is_numeric ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( ! ( a[ i ] >= '0' and a[ i ] <= '9' ) )

			return 0;
	return 1;
}









void swap_topics ( int iter1, int iter2 )
{
	string topic_temp;
	double average_temp;
	int count_temp;

	topic_temp = topic[ iter1 ];
	average_temp = average[ iter1 ];
	count_temp = count[ iter1 ];

	topic[ iter1 ] = topic[ iter2 ];
	average[ iter1 ] = average[ iter2 ];
	count[ iter1 ] = count[ iter2 ];
	
	topic[ iter2 ] = topic_temp;
	average[ iter2 ] = average_temp;
	count[ iter2 ] = count_temp;
}


void set_sizes_file()
{
	ofstream fo;
	fo.open( "results" );
	fo.close(); // clear file


	fo.open( "results" );

	int maximums[ 10 ];
	for ( int i = 0; i < 3; i = i + 1 )
		maximums[ i ] = 0;

	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		if ( topic[ i ].length() > maximums[ 0 ] )
			maximums[ 0 ] = topic[ i ].length();
		if ( length( average[ i ] ) > maximums[ 1 ] )
			maximums[ 1 ] = length( average[ i ] );
		if ( length( count[ i ] )  > maximums[ 2 ] )
			maximums[ 2 ] = length( count[ i ] );
	}

	string topic_string = "topic";
	string average_string = "Average";
	string count_string = "Word Count";

	if ( count_string.length() > maximums[ 0 ] )
		maximums[ 0 ] = count_string.length();
	if ( average_string.length() > maximums[ 1 ] )
		maximums[ 1 ] = average_string.length();
	if ( count_string.length() > maximums[ 2 ] )
		maximums[ 2 ] = count_string.length();

	fo << "Average: " << average_topics << " ( " << count_topics << " words in " << count_average << " valid topics )\n\n";

	fo << topic_string << ' ';
	for ( int l = topic_string.length(); l <= maximums[ 0 ]; l = l + 1 )
		fo << ' ';
	fo << average_string << ' ';
	for ( int l = average_string.length(); l <= maximums[ 1 ]; l = l + 1 )
		fo << ' ';
	fo << count_string << ' ';
	for ( int l = count_string.length(); l <= maximums[ 2 ]; l = l + 1 )
		fo << ' ';

	fo << "\n\n";

	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		fo << topic[ i ] << ' ';
		for ( int l = topic[ i ].length(); l <= maximums[ 0 ]; l = l + 1 )
			fo << ' ';
		if ( average[ i ] == -1 )
		{
			string invalid_string = "invalid";

			fo << invalid_string << ' ';
			for ( int l = invalid_string.length(); l <= maximums[ 1 ]; l = l + 1 )
				fo << ' ';
		}
		else
		{
			fo << average[ i ] << ' ';
			for ( int l = length( average[ i ] ); l <= maximums[ 1 ]; l = l + 1 )
				fo << ' ';
		}
		if ( count[ i ] == -1 )
		{
			fo << 0 << ' ';
			for ( int l = 1; l <= maximums[ 2 ]; l = l + 1 )
				fo << ' ';
		}
		else
		{
			fo << count[ i ] << ' ';
			for ( int l = length( count[ i ] ); l <= maximums[ 2 ]; l = l + 1 )
				fo << ' ';
		}
		fo << "\n";
	}

	fo.close();	
}

void set_file ()
{

	for ( int i = 0; i < file_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < file_iter; l = l + 1 )
		{
			if ( average[ i ] < average[ l ] )
				swap_topics( i, l );
		}

	ofstream fo;
	fo.open( "size counts/size_count" );
	fo.close(); // clear file


	fo.open( "size counts/size_count" );


	for ( int i = 0; i < file_iter; i = i + 1 )
	{

		fo << topic[ i ] << ' ';
		fo << average[ i ] << ' ';
		fo << count[ i ] << '\n';
	}

	fo.close();
	set_sizes_file();
}

void get_file ()
{
	file_iter = 0;
	average_topics = 0;
	count_topics = 0;
	count_average = 0;

	ifstream fi;

	fi.open( "size counts/size_count" );

	string temp;

	while ( fi >> temp )
	{
		topic[ file_iter ] = temp;
		fi >> average[ file_iter ];
		if ( average[ file_iter ] != -1 )
		{
			average_topics = average_topics + average[ file_iter ];

			count_average = count_average + 1;
		}

		fi >> count[ file_iter ];
		if ( count[ file_iter ] != -1 )
			count_topics = count_topics + count[ file_iter ];
		file_iter = file_iter + 1;
	}

	fi.close();

	average_topics = average_topics / count_average;

	for ( int i = 0; i < file_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < file_iter; l = l + 1 )
		{
			if ( average[ i ] < average[ l ] )
				swap_topics( i, l );
		}

	set_file();
}

void show_topics ()
{

	int maximums[ 10 ];
	for ( int i = 0; i < 5; i = i + 1 )
		maximums[ i ] = 0;


	for ( int i = 0; i < file_iter; i = i + 1 )
		if ( topic[ i ].length() + length( i + 1 ) > maximums[ i % 5 ] )
			maximums[ i % 5 ] = topic[ i ].length() + length( i + 1 );
	cout << "\033cAvailable topics:\n ";
	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		cout << i + 1 << ". " << topic[ i ];


		for ( int l = topic[ i ].length() + length( i + 1 ); l < maximums[ i % 5 ] + 2; l = l + 1 )
			cout << ' ';

		if ( i % 5 == 4 )
			cout << "\n ";
	}
}
void get_average ( int topic_iter )
{
	ifstream fi;

	fi.open( filename );

	string temp;
	double size = 0;
	int size_count = 0;
	while ( fi >> temp )
	{
		size = size + temp.length();
		size_count = size_count + 1;
	}

	fi.close();


	double last_size = average[ topic_iter ];
	int last_count = count[ topic_iter ];

	if ( last_size != -1 and last_count != -1 )
	{
		for ( int i = 0; i < last_count; i = i + 1 )
			size = size + last_size;
		size_count = size_count + last_count;
	}

	size = size / size_count;

	average[ topic_iter ] = size;
	count[ topic_iter ] = size_count;

	cout << "\033c";
	cout << "For topic \"" << topic[ topic_iter ] << "\":\n\n";
	if ( last_size != -1 and last_count != -1 )
	{
		cout << "Previous average size: " << last_size << "\n";
		cout << "Previous count: " << last_count << "\n";
		cout << "\n";
	}

	cout << "Average size: " << size << "\n";
	cout << "Count: " << size_count << "\n";
	set_file();
}

void add_topic_average ( string a )
{
	int l = in_strings( topic, a );
	if ( l != -1 )
	{
		get_average( l );
		return;
	}

	topic[ file_iter ] = a;
	average[ file_iter ] = -1;
	count[ file_iter ] = -1;

	file_iter = file_iter + 1;

	get_average( file_iter - 1 );		

	cout << "\"" << a << "\" was added as a topic!\n";
}

void add_topic ( string a )
{
	int l = in_strings( topic, a );
	if ( l != -1 )
	{
		cout << "\"" << a << "\" is already a topic!\n";
		return;
	}

	topic[ file_iter ] = a;
	average[ file_iter ] = -1;
	count[ file_iter ] = -1;

	file_iter = file_iter + 1;


	set_file();


	cout << "\"" << a << "\" was added as a topic!\n";
}

void remove_topic ( string a )
{
	int l = in_strings( topic, a );
	if ( l == -1 )
	{
		cout << "\"" << a << "\" is invalid as a topic!\n";
		return;
	}

	ofstream fo;
	fo.open( "size counts/size_count" );
	fo.close(); // clear file

	fo.open( "size counts/size_count" );

	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		if ( l == i )
			continue;

		fo << topic[ i ] << ' ';
		fo << average[ i ] << ' ';
		fo << count[ i ] << '\n';
	}


	fo.close();

	get_file();

	cout << "\"" << a << "\" was removed!\n";
}
void remove_topic ( int l )
{
	if ( l < 0 or l > file_iter )
	{
		cout << "\"" << l << "\" is invalid as a topic num!\n";
		return;
	}

	ofstream fo;
	fo.open( "size counts/size_count" );
	fo.close(); // clear file

	fo.open( "size counts/size_count" );

	for ( int i = 0; i < file_iter; i = i + 1 )
	{
		if ( l == i )
			continue;

		fo << topic[ i ] << ' ';
		fo << average[ i ] << ' ';
		fo << count[ i ] << '\n';
	}


	fo.close();

	get_file();

	cout << "\"" << topic[ l ] << "\" was removed!\n";
}



void show_topics_sizes ()
{
	cout << "\033c";
	cout << "Average: " << average_topics << " ( " << count_topics << " words in " << count_average << " topics )\n\n";

	for ( int i = 0; i < file_iter - 1; i = i + 1 )
		for ( int l = i + 1; l < file_iter; l = l + 1 )
		{
			if ( average[ i ] < average[ l ] )
				swap_topics( i, l );
		}

	for ( int i = 0; i < file_iter; i = i + 1 )
	{

		cout << i + 1 << ". ";

		if ( average[ i ] == -1 )
		{
			cout << topic[ i ] << ": has 0 words for now.\n";

			continue;
		}

		cout << topic[ i ] << ": has an average word size of ";
		cout << average[ i ] << ' ';

		cout << "( " << count[ i ] << " words )\n";
	}
	cout << "\n";
	cout << "File \"results\" also has size data.\n";
}



int main ()
{
	get_file();

	string choice;


	for ( int i = 0; i < 100000; i = i + 1 )
	{

		cout << "choice";
		cout << "\033c";
		cout << "Choices:";
		cout << " 1. Add File  2. Add topic  3. Remove topic  4. Show topics and sizes  5. Exits\n";
		cout << "Choice: ";
		getline( cin, choice );
		if ( choice == "" )
			getline( cin, choice );

		cout << "\n";

		if ( choice == "1" )
		{
			cout << "Filename of file to add: ";
			getline( cin, filename );
			if ( filename == "" )
				getline( cin, filename );

			filename_ext();

			show_topics();

			string topic_string;
			cout << "\n\n( num for available topics / topic to add )\n";
			cout << "File \"" + filename + "\" is on topic: ";
			getline( cin, topic_string );
			if ( topic_string == "" )
				getline( cin, topic_string );

			filename = filepath + filename + ext;

			if ( is_numeric( topic_string ) )
			{
				int topic_choice = string_to_int( topic_string );

				topic_choice = topic_choice - 1;
				get_average( topic_choice );
			}
			else 
				add_topic_average( topic_string );
		}


		if ( choice == "2" )
		{
			string topic_string;
			cout << "Add topic: ";
			getline( cin, topic_string );
			if ( topic_string == "" )
				getline( cin, topic_string );
			add_topic( topic_string );
		}

		if ( choice == "3" )
		{
			show_topics();

			string topic_string;
			cout << "\n\n( num of topic / topic to remove )\n";
			cout << "Remove topic: ";
			getline( cin, topic_string );
			if ( topic_string == "" )
				getline( cin, topic_string );

			if ( is_numeric( topic_string ) )
			{
				int topic_choice = string_to_int( topic_string );

				topic_choice = topic_choice - 1;

				remove_topic( topic_choice );
			}
			else 
				remove_topic( topic_string );
		}

		if ( choice == "4" )
		{
			show_topics_sizes();
		}

		if ( choice == "5" )
		{
			cout << "Exited.\n";
			break;
		}




		if ( choice == "1" or choice == "2" or choice == "3" or choice == "4" or choice == "5" )
			continues();
	}

	return 0;
}
