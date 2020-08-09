#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}



int length ( int a )
{
	if ( a == 0 ) return 1;

	int i = 0;

	while ( a > 0 )
	{
		a = a / 10;
		i = i + 1;
	}

	return i;
}

string get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string file = "";
	string temp;
	while ( getline( fi, temp ) )
		file = file + temp + '\n';
	fi.close();
	return file;
}

void lower ( string &a )
{
	int size = a.length();
	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			a[ i ] = a[ i ] + 32;
}


string upper ( string a )
{
	lower( a );
	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;
	return a;
}


void move_words ( string text, string words[] )
{
	for ( int i = 0; i < length( words ); i = i + 1 )
		words[ i ] = "";

	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' or text[i] == '	' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}


void move_lines ( string text, string words[] )
{
	for ( int i = 0; i < length( words ); i = i + 1 )
		words[ i ] = "";

	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( text[i] == '.' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
	}
}


// removes a char in a string
void remove_char( string &a, int iter )
{
	if ( iter < 0 or iter >=a.length() )
		return;

	int size = a.length();

	string result = "";

	for ( int i=0; i<size; i=i+1 )
		if ( i != iter )
			result = result + a[i];

	a = result;
}


// remove chars
void remove_chars ( string &a )
{
	int size = a.length();

	// replace chars with ' '
	for ( int i=0; i<size; i=i+1 )
	{
		if ( !( a[i] >= 'a' and a[i] <= 'z' ) and !( a[i] >= 'A' and a[i] <= 'Z' ) )
			a[i] = ' ';
		if ( a[i] >= 'A' and a[i] <= 'Z' )
			a[i] = a[i] + 32;
	}


	string result = "";

	// reduce ' '-s
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] != ' ')
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + " ";


	// delete last ' '
	if ( result[ result.length() - 1 ] == ' ' )
		remove_char( result, result.length() - 1 );

	// delete initial ' '
	if ( result[ 0 ] == ' ' )
		remove_char( result, 0 );

	a = result;
}


bool is_string_empty ( string a )
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != ' ' and a[ l ] != '\n' and a[ l ] != '	' )
			return false;

	return true;
}

void empty ( string a[] )
{

	int size = length( a );

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = "";
}

// check if a string is an int
bool is_int ( string a )
{
	int size = a.length();

	if ( size >= 10 )
		return false;

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



void continues ()
{
	char enter;
	cout << "[ ']' + Enter ] to continue: ";
	cin >> enter;
}


// reduce ' '
string reduce_spaces ( string &a )
{
	int size = a.length();
	string result = "";
	int l;


	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '	' )
		{
			l = i;
			break;
		}

	for ( int i = l; i < size; i = i + 1 )
		if ( a[i] != ' ' and a[i] != '	' )
			result = result + a[i];
		else
			if ( result[ result.length() - 1 ] != ' ' )
				result = result + ' ';

	size = result.length();
	for ( int i = size - 1; i >= 0; i = i - 1 )
	{
		if ( result[ i ] != ' ' and result[ i ] != '	' )
			break;
		remove_char( result, i );
	}
	a = result;

	return a;
}


int positive ( int a )
{
	if ( a < 0 )
		a = -a;
	return a;
}

bool is_string ( string a[], string b );

class Verb 
{
  private:

	string vrb;
	string adv[ 90 ];

	int length_verb ( string a[] )
	{
		int i = 0;

		while ( a[ i ].length() > 0 )
			i = i + 1;
		return i;
	}

	void copy_verb ( string a[], string b[] )
	{
		int size = length_verb( b );
		for ( int l = 0; l < size; l = l + 1 )
			a[ l ] = b[ l ];
		a[ size ] = "";
	}

  public:

	Verb () {}

	Verb ( string vrb, string adv[] )
	{
		this->vrb = vrb;
		copy_verb( this->adv, adv );
	}

	void set_vrb ( string vrb ) { this->vrb = vrb; }
	void set_adv ( string adv[] ) { copy_verb( this->adv, adv ); }

	string get_vrb () { return this->vrb; }
	void get_adv ( string adv[] ) { copy_verb( adv, this->adv ); }

	void add_adv ( string a ) { this->adv[ length( this->adv ) ] = a; }

	void remove_adv ( string a ) 
	{
		string remain[ 90 ];
		int remain_iter = 0;
		for ( int i = 0; i < length_verb( this->adv ); i = i + 1 )
			if ( this->adv[ i ] != a )
			{
				remain[ remain_iter ] = this->adv[ i ];
				remain_iter = remain_iter + 1;
			}
		empty( this->adv );
		copy_verb( this->adv, remain );
	}
};

class Subject 
{
  private:

	string noun_singular;
	string noun_plural;
	string syn[ 90 ];
	string adj[ 90 ];
	Verb vrb[ 90 ];

	int length_subject ( string a[] )
	{
		int i = 0;

		while ( a[ i ].length() > 0 )
			i = i + 1;
		return i;
	}

	void copy_subject ( string a[], string b[] )
	{
		int size = length_subject( b );
		for ( int l = 0; l < size; l = l + 1 )
			a[ l ] = b[ l ];
		a[ size ] = "";
	}

	int length ( Verb a[] )
	{
		int i = 0;
		while ( a[ i ].get_vrb() != "" )
			i = i + 1;
		return i;
	}

	void copy_verbs ( Verb a[], Verb b[] )
	{
		int size = length( b );
		for ( int l = 0; l < size; l = l + 1 )
			a[ l ] = b[ l ];
	}

	void remove_verb ( string a[] )
	{
		int size = length_subject( a );

		string remain[ 10000 ];

		for ( int i = 1; i < size; i = i + 1 )
			remain[ i - 1 ] = a[ i ];

		copy_subject( a, remain );
	}

	void remove_subject ( string a[], string b )
	{
		int size = length_subject( a );

		string remain[ 10000 ];

		for ( int i = 0; i < size; i = i + 1 )
			if ( a[ i ] != b )
				remain[ i ] = a[ i ];

		copy_subject( a, remain );
	}

	void remove ( Verb a[], string b )
	{
		int size = length( a );

		Verb remain[ 10000 ];

		for ( int i = 0; i < size; i = i + 1 )
			if ( a[ i ].get_vrb() != b )
				remain[ i ] = a[ i ];

		copy_verbs( a, remain );
	}

  public:

	Subject ( string noun_singular, string noun_plural, string syn[], string adj[], Verb vrb[] )
	{
		this->noun_singular = noun_singular;
		this->noun_plural = noun_plural;

		copy_subject( this->syn, syn );
		copy_subject( this->adj, adj );
		copy_verbs( this->vrb, vrb );
	}

	Subject ( string filename )
	{
		ifstream fi;
		fi.open( "parts_files/subjects/" + filename );

		fi >> this->noun_singular;
		fi >> this->noun_plural;

		string syn_string = "";
		while ( is_string_empty( syn_string ) )
			getline( fi, syn_string );
		move_words( syn_string, this->syn );

		string adj_string = "";
		while ( is_string_empty( adj_string ) )
			getline( fi, adj_string );
		move_words( adj_string, this->adj );

		getline( fi, adj_string );


		string vrb_string = "vrb";
		string adverbs[ 10000 ];
		int vrb_iter = 0;

		while ( getline( fi, vrb_string ) and ! is_string_empty( vrb_string ) )
		{
			reduce_spaces( vrb_string );
			move_words( vrb_string, adverbs );

			string verb = adverbs[ 0 ];
			remove_verb( adverbs );

			Verb verb_temp = Verb ( verb, adverbs );

			this->vrb[ vrb_iter ] = verb_temp;
			vrb_iter = vrb_iter + 1;
		}		

		fi.close();
	}

	void set_singular ( string singular ) { this->noun_singular = singular; }
	void set_plural ( string plural ) { this->noun_plural = plural; }
	void set_syn ( string syn[] ) { copy_subject( this->syn, syn ); }
	void set_adj ( string adj[] ) { copy_subject( this->adj, adj ); }
	void set_vrb ( Verb vrb[] ) { copy_verbs( this->vrb, vrb ); }
	void set_adv ( string verb, string adverbs[] )
	{
		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
			if ( this->vrb[ i ].get_vrb() == verb )
			{
				this->vrb[ i ].set_adv( adverbs );
				this->set_file();	
				break;
			}
	}

	void set_adv ( int l, string adverbs[] )
	{
		if ( l < 0 or l >= length( this->vrb ) ) return;

		this->vrb[ l ].set_adv( adverbs );
		this->set_file();	
	}




	string get_singular () { return this->noun_singular; }
	string get_plural () { return this->noun_plural; }
	void get_syn ( string syn[] ) { copy_subject( syn, this->syn ); }
	void get_adj ( string adj[] ) { copy_subject( adj, this->adj ); }
	void get_vrb ( Verb vrb[] ) { copy_verbs( vrb, this->vrb ); }
	void get_adv ( string verb, string adverbs[] )
	{
		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
			if ( this->vrb[ i ].get_vrb() == verb )
			{
				this->vrb[ i ].get_adv( adverbs );
				this->set_file();	
				break;
			}
	}

	void get_adv ( int l, string adverbs[] )
	{
		if ( l < 0 or l >= length( this->vrb ) ) return;

		this->vrb[ l ].get_adv( adverbs );
		this->set_file();	
	}

	string get_syn ( int l ) 
	{
		if ( l < 0 or l >= length_subject( this->syn ) ) return "";
		return this->syn[ l ];
	}

	string get_adj ( int l ) 
	{
		if ( l < 0 or l >= length_subject( this->adj ) ) return "";
		return this->adj[ l ];
	}

	string get_vrb ( int l ) 
	{
		if ( l < 0 or l >= length( this->vrb ) ) return "";
		return this->vrb[ l ].get_vrb();
	}


	string get_adv ( string verb, int l ) 
	{
		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
			if ( this->vrb[ i ].get_vrb() == verb )
			{
				string adverbs[ 90 ];
				this->vrb[ i ].get_adv( adverbs );
				if ( l < 0 or l >= length_subject( adverbs ) ) return "";

				return adverbs[ l ];
			}

		return "";
	}

	string get_adv ( int verb_iter, int l ) 
	{
		string adverbs[ 90 ];
		this->vrb[ verb_iter ].get_adv( adverbs );
		if ( l < 0 or l >= length_subject( adverbs ) ) return "";

		return adverbs[ l ];
	}

	void add_syn ( string a ) { if ( is_string( this->syn, a ) ) return; this->syn[ length_subject( this->syn ) ] = a; this->set_file(); }
	void add_adj ( string a ) { if ( is_string( this->adj, a ) ) return; this->adj[ length_subject( this->adj ) ] = a; this->set_file(); }
	void add_vrb ( string a ) 
	{	
		string b[ 90 ];
		Verb l = Verb( a, b );
		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
			if ( this->vrb[ i ].get_vrb() == a )
				return;

		this->vrb[ length( this->vrb ) ] = l;
		this->set_file();
	}
	void add_vrb ( string a, string b[] ) 
	{	
		Verb l = Verb( a, b );

		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
			if ( this->vrb[ i ].get_vrb() == a )
				return;

		this->vrb[ length( this->vrb ) ] = l;
		this->set_file();
	}
	void add_vrb ( Verb l ) 
	{
		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
			if ( this->vrb[ i ].get_vrb() == l.get_vrb() )
				return;

		this->vrb[ length( this->vrb ) ] = l; 
		this->set_file();
	}

	void add_adv ( string verb, string adv )
	{
		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
			if ( this->vrb[ i ].get_vrb() == verb )
			{
				string adverbs[ 90 ];

				this->vrb[ i ].get_adv( adverbs );
				if ( is_string( adverbs, adv ) )
					return;

				adverbs[ length_subject( adverbs ) ] = adv;
				this->vrb[ i ].set_adv( adverbs );
				this->set_file();	
				break;
			}
	}

	void add_adv ( int l, string adv )
	{
		string adverbs[ 90 ];

		this->vrb[ l ].get_adv( adverbs );

		if ( is_string( adverbs, adv ) )
			return;

		adverbs[ length_subject( adverbs ) ] = adv;
		this->vrb[ l ].set_adv( adverbs );
		this->set_file();	
	}

	void remove_adj ( string a ) { remove_subject( this->adj, a ); this->set_file(); }
	void remove_syn ( string a ) { remove_subject( this->syn, a ); this->set_file(); }

	void remove_vrb ( string a ) { remove( this->vrb, a ); this->set_file(); }

	void set_file ()
	{
		ofstream fo;
		fo.open( "parts_files/subjects/" + this->noun_singular );
		fo.close(); // clear file

		fo.open( "parts_files/subjects/" + this->noun_singular );

		fo << this->noun_singular << '\n';
		fo << this->noun_plural << "\n\n";

		int syn_iter = length_subject( this->syn );
		for ( int i = 0; i < syn_iter; i = i + 1 )
			fo << this->syn[ i ] << ' ';
		fo << "\n\n";

		int adj_iter = length_subject( this->adj );
		for ( int i = 0; i < adj_iter; i = i + 1 )
			fo << this->adj[ i ] << ' ';
		fo << "\n\n";

		int vrb_iter = length( this->vrb );
		
		for ( int i = 0; i < vrb_iter; i = i + 1 )
		{
			fo << this->vrb[ i ].get_vrb() << "     ";

			string adverbs[ 10000 ];
			this->vrb[ i ].get_adv( adverbs );
			int adv_iter = length_subject( adverbs );
			for ( int l = 0; l < adv_iter; l = l + 1 )
				fo << adverbs[ l ] << ' ';
			fo << '\n';
		}

		fo.close();
	}

	void info ()
	{
		cout << "Subject:\n";
		cout << " noun_singular: \"" << this->noun_singular << "\"\n";
		cout << " noun_plural: \"" << this->noun_plural << "\"\n";
		cout << " syn: ";
		for ( int i = 0; i < length_subject( this->syn ); i = i + 1 )
		{
			cout << '"' << this->syn[ i ] << '"';
			if ( i != length_subject( syn ) - 1 )
				cout << ", ";
		}
		cout << '\n';
		cout << " adj: ";
		for ( int i = 0; i < length_subject( this->adj ); i = i + 1 )
		{
			cout << '"' << this->adj[ i ] << '"';
			if ( i != length_subject( adj ) - 1 )
				cout << ", ";
		}
		cout << '\n';
		cout << " vrb:\n";
		for ( int i = 0; i < length( this->vrb ); i = i + 1 )
		{
			cout << "  \'" << this->vrb[ i ].get_vrb() << "\': ";
			string adv[ 10000 ];
			this->vrb[ i ].get_adv( adv );
			int adv_iter = length_subject( adv );
			for ( int l = 0; l < adv_iter; l = l + 1 )
			{
				cout << '"' << adv[ l ] << '"';
				if ( l != length_subject( adv ) - 1 )
					cout << ", ";
			}
			cout << '\n';
		}
		cout << '\n';
	}
};



string common[ 10000 ];
int common_iter = 0;

string vrb[ 10000 ];
int vrb_iter = 0;

string adj[ 10000 ];
int adj_iter = 0;

string adv[ 10000 ];
int adv_iter = 0;

string noun[ 10000 ];
int noun_iter = 0;


string sb[ 10000 ];
int sb_iter = 0;


string sentance[ 10000 ];
int sentance_iter = 0;

void get_file ( string filename, int &strings_iter, string strings[] )
{
	strings_iter = 0;
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( fi >> temp )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();
}

void get_file_lines ( string filename, int &strings_iter, string strings[] )
{
	strings_iter = 0;
	ifstream fi;
	fi.open( filename );

	string temp;
	while ( getline( fi, temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
	fi.close();
}

void get_common () { get_file( "parts_files/common", common_iter, common ); }
void get_adj () { get_file( "parts_files/adj", adj_iter, adj ); }
void get_adv () { get_file( "parts_files/adv", adv_iter, adv ); }
void get_vrb () { get_file( "parts_files/vrb", vrb_iter, vrb ); }
void get_noun () { get_file( "parts_files/noun", noun_iter, noun ); }
void get_sb () { get_file( "parts_files/sb", sb_iter, sb ); }
void get_sentance () { get_file_lines( "parts_files/sentance", sentance_iter, sentance ); }


void set_file ( string filename, string strings[] )
{
	int strings_iter = length( strings );

	ofstream fo;
	fo.open( filename );
	fo.close(); // clear file

	fo.open( filename );

	for ( int i = 0; i < strings_iter; i = i + 1 )
		fo << strings[ i ] << '\n';

	fo.close();
}

void set_common () { set_file( "parts_files/common", common ); }
void set_adj () { set_file( "parts_files/adj", adj ); }
void set_adv () { set_file( "parts_files/adv", adv ); }
void set_vrb () { set_file( "parts_files/vrb", vrb ); }
void set_noun () { set_file( "parts_files/noun", noun ); }
void set_sb () { set_file( "parts_files/sb", sb ); }
void set_sentance () { set_file( "parts_files/sentance", sentance ); }

bool is_string ( string a[], string b )
{
	int size = length( a );

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return 1;
	return 0;
}

int in_strings ( string a[], string b )
{
	int size = length( a );

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == b )
			return i;
	return -1;
}


bool is_common ( string a ) { return is_string( common, a ); }
bool is_adj ( string a ) { return is_string( adj, a ); }
bool is_adv ( string a ) { return is_string( adv, a ); }
bool is_vrb ( string a ) { return is_string( vrb, a ); }
bool is_noun ( string a ) { return is_string( noun, a ); }
bool is_sb ( string a ) { return is_string( sb, a ); }
bool is_sentance ( string a ) { return is_string( sentance, a ); }

void add_string ( string a[], string b )
{
	if ( is_string( a, b ) )
		return;

	a[ length( a ) ] = b;
}



void add_common ( string a ) { add_string( common, a ); set_common(); }
void add_adj ( string a ) { add_string( adj, a ); set_adj(); }
void add_adv ( string a ) { add_string( adv, a ); set_adv(); }
void add_vrb ( string a ) { add_string( vrb, a ); set_vrb(); }
void add_noun ( string a ) { add_string( noun, a ); set_noun(); }
void add_sb ( string a ) { add_string( sb, a ); set_sb(); }
void add_sentance ( string a ) { add_string( sentance, a ); set_sentance(); }


void add_string ( string a[], string b[] )
{
	for ( int l = 0; l < length( b ); l = l + 1 )
		add_string( a, b[ l ] );
}

void add_common ( string a[] ) { add_string( common, a ); set_common(); }
void add_adj ( string a[] ) { add_string( adj, a ); set_adj(); }
void add_adv ( string a[] ) { add_string( adv, a ); set_adv(); }
void add_vrb ( string a[] ) { add_string( vrb, a ); set_vrb(); }
void add_noun ( string a[] ) { add_string( noun, a ); set_noun(); }
void add_sb ( string a[] ) { add_string( sb, a ); set_sb(); }
void add_sentance ( string a[] ) { add_string( sentance, a ); set_sentance(); }


void remove_string ( string a[], string b )
{
	string result[ 10000 ];
	int result_iter = 0;

	for ( int l = 0; l < length( a ); l = l + 1 )
		if ( b != a[ l ] )
		{
			result[ result_iter ] = a[ l ];
			result_iter = result_iter + 1;
		}
	empty( a );

	for ( int i = 0; i < result_iter; i = i + 1 )
		a[ i ] = result[ i ];
}




void remove_adj ( string a ) { remove_string( adj, a ); set_adj(); }
void remove_adv ( string a ) { remove_string( adv, a ); set_adv(); }
void remove_vrb ( string a ) { remove_string( vrb, a ); set_vrb(); }
void remove_noun ( string a ) { remove_string( noun, a ); set_noun(); }
void remove_common ( string a ) { remove_string( common, a ); set_common(); }
void remove_sentance ( string a ) { remove_string( sentance, a ); set_sentance(); }


void remove_string ( string a[], string b[] )
{
	string result[ 10000 ];
	int result_iter = 0;

	for ( int l = 0; l < length( a ); l = l + 1 )
		if ( ! is_string( b, a[ l ] ) )
		{
			result[ result_iter ] = a[ l ];
			result_iter = result_iter + 1;
		}
	empty( a );

	for ( int i = 0; i < result_iter; i = i + 1 )
		a[ i ] = result[ i ];
}


void remove_adj ( string a[] ) { remove_string( adj, a ); set_adj(); }
void remove_adv ( string a[] ) { remove_string( adv, a ); set_adv(); }
void remove_vrb ( string a[] ) { remove_string( vrb, a ); set_vrb(); }
void remove_noun ( string a[] ) { remove_string( noun, a ); set_noun(); }
void remove_common ( string a[] ) { remove_string( common, a ); set_common(); }
void remove_sentance ( string a[] ) { remove_string( sentance, a ); set_sentance(); }


string get_max_frev ( string filename )
{
	string strings[ 10000 ];
	int strings_iter;

	get_file( filename, strings_iter, strings );


	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		remove_chars( strings[ i ] );
		lower( strings[ i ] );
	}

	string remain[ 10000 ];
	int frev[ 10000 ];
	int remain_iter = 0;

	int l;
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		if ( is_common( strings[ i ] ) ) continue;
		l = in_strings( remain, strings[ i ] );
		if ( l == -1 )
		{
			remain[ remain_iter ] = strings[ i ];
			frev[ remain_iter ] = 1;
			remain_iter = remain_iter + 1;
		}
		else
			frev[ l ] = frev[ l ] + 1;
	}

	string max_string;
	int max_frev = 0;

	for ( int i = 0; i < remain_iter; i = i + 1 )
		if ( frev[ i ] > max_frev )
		{
			max_string = remain[ i ];
			max_frev = frev[ i ];
		}


	return max_string;
}




// sets a string[] with a separator string and nums
void set_num ( string a[], int num_columns )
{
	int size = length(a);

	int max_length[ num_columns ];
	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() + length( i + 1 ) > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length() + length( i + 1 );

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( i % num_columns == 0 )
			cout << "  ";
		cout << i + 1 << ". " << a[i];
		for ( int l=a[i].length() + length( i + 1 ); l<max_length[ i % num_columns ]; l=l+1 )
			cout << ' ';
		if ( i % num_columns == num_columns - 1 )
			cout << "\n";
	}
}


void add_subject ()
{
	string noun_topic;
	string noun_topic_plural;

	cout << "Set topic ( to noun singular ): ";
	cin >> noun_topic;

	if ( is_int( noun_topic ) )
	{
		int noun_int = string_to_int( noun_topic );
		noun_int = noun_int - 1;
		if ( noun_int < 0 or noun_int >= sb_iter )
		{
			cout << "Invalid subject num. Add file aborted.\n";
			return;
		}
		else
			noun_topic = sb[ noun_int ];
	}

	remove_chars( noun_topic );
	lower( noun_topic );

	if ( ! is_sb( noun_topic ) )
	{
		cout << "Set topic plural: ";
		cin >> noun_topic_plural;
		remove_chars( noun_topic_plural );
		lower( noun_topic_plural );


		string syn[ 10000 ];
		int sym_iter = 0;

		string syn_string;
		cout << "Synonims ( 1 line ): ";
		getline( cin, syn_string );
		if ( syn_string == "" )
			getline( cin, syn_string );
		remove_chars( syn_string );
		lower( syn_string );

		move_words( syn_string, syn );
		sym_iter = length( syn );


		string adject[ 10000 ];
		int adject_iter = 0;
		cout << "Adjectives ( each on a line / empty means done ):\n";

		string adj_temp = "adjective";
		while ( ! is_string_empty( adj_temp ) )
		{
			getline( cin, adj_temp );
			if ( is_string_empty( adj_temp ) )
				break;
			adject[ adject_iter ] = adj_temp;
			adject_iter = adject_iter + 1;
		}


		cout << "Verbs ( each on a line / empty means done ):\n";

		string temp = "verbs";
		string verb_string = "";
		string adverbs[ 90 ];
		string adverbs_string;

		Verb verbs[ 90 ];
		int verbs_iter = 0;

		while ( ! is_string_empty( temp ) )
		{
			cout << "\nVerb: ";
			getline( cin, temp );
			verb_string = temp;
			remove_chars( verb_string );
			lower( verb_string );

			if ( is_string_empty( verb_string ) )
				break;

			cout << "Adverbs for \"" << upper( verb_string ) << "\" ( 1 line ): ";
			getline( cin, adverbs_string );
			remove_chars( adverbs_string );
			lower( adverbs_string );

			move_words( adverbs_string, adverbs );

			Verb verb_temp = Verb( verb_string, adverbs );

			verbs[ verbs_iter ] = verb_temp;
			verbs_iter = verbs_iter + 1;

			empty( adverbs );
		}


		Subject sbjct = Subject( noun_topic, noun_topic_plural, syn, adject, verbs );

		sbjct.set_file();

		add_sb( noun_topic );
		add_adj( adject );
		for ( int i = 0; i < verbs_iter; i = i + 1 )
		{
			empty( adverbs );
			verbs[ i ].get_adv( adverbs );
			add_adv( adverbs );
		}
		for ( int i = 0; i < verbs_iter; i = i + 1 )
			add_vrb( verbs[ i ].get_vrb() );
		add_noun( syn );
		add_noun( noun_topic );
		add_noun( noun_topic_plural );
	}
	else
		cout << "Already added!";
}


void set_file ( string filename )
{
	string strings[ 10000 ];
	int strings_iter;

	string file = get_file( filename );
	move_lines( file, strings );
	strings_iter = length( strings );

	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		remove_chars( strings[ i ] );
		lower( strings[ i ] );		
	}

	cout << '\"' << upper( get_max_frev( filename ) ) << "\" could be topic.\n";

	if ( sb_iter != 0 )
	{
		cout << "Subjects:\n";
		set_num( sb, 5 );
		cout << "\n\n";
	}

	string noun_topic;
	string noun_topic_plural;

	cout << "Set topic ( to noun singular ): ";
	cin >> noun_topic;

	if ( is_int( noun_topic ) )
	{
		int noun_int = string_to_int( noun_topic );
		noun_int = noun_int - 1;
		if ( noun_int < 0 or noun_int >= sb_iter )
		{
			cout << "Invalid subject num. Add file aborted.\n";
			return;
		}
		else
			noun_topic = sb[ noun_int ];
	}

	remove_chars( noun_topic );
	lower( noun_topic );

	if ( ! is_sb( noun_topic ) )
	{
		cout << "Set topic plural: ";
		cin >> noun_topic_plural;
		remove_chars( noun_topic_plural );
		lower( noun_topic_plural );


		string syn[ 10000 ];
		int sym_iter = 0;

		string syn_string;
		cout << "Synonims ( 1 line ): ";
		getline( cin, syn_string );
		if ( syn_string == "" )
			getline( cin, syn_string );
		remove_chars( syn_string );
		lower( syn_string );

		move_words( syn_string, syn );
		sym_iter = length( syn );


		string adject[ 10000 ];
		int adject_iter = 0;
		cout << "Adjectives ( each on a line / empty means done ):\n";

		string adj_temp = "adjective";
		while ( ! is_string_empty( adj_temp ) )
		{
			getline( cin, adj_temp );
			if ( is_string_empty( adj_temp ) )
				break;
			adject[ adject_iter ] = adj_temp;
			adject_iter = adject_iter + 1;
		}


		cout << "Verbs ( each on a line / empty means done ):\n";

		string temp = "verbs";
		string verb_string = "";
		string adverbs[ 90 ];
		string adverbs_string;

		Verb verbs[ 90 ];
		int verbs_iter = 0;

		while ( ! is_string_empty( temp ) )
		{
			cout << "\nVerb: ";
			getline( cin, temp );
			verb_string = temp;
			remove_chars( verb_string );
			lower( verb_string );

			if ( is_string_empty( verb_string ) )
				break;

			cout << "Adverbs for \"" << upper( verb_string ) << "\" ( 1 line ): ";
			getline( cin, adverbs_string );
			remove_chars( adverbs_string );
			lower( adverbs_string );

			move_words( adverbs_string, adverbs );

			Verb verb_temp = Verb( verb_string, adverbs );

			verbs[ verbs_iter ] = verb_temp;
			verbs_iter = verbs_iter + 1;

			empty( adverbs );
		}


		Subject sbjct = Subject( noun_topic, noun_topic_plural, syn, adject, verbs );

		sbjct.set_file();

		add_sb( noun_topic );
		add_adj( adject );
		for ( int i = 0; i < verbs_iter; i = i + 1 )
		{
			empty( adverbs );
			verbs[ i ].get_adv( adverbs );
			add_adv( adverbs );
		}
		for ( int i = 0; i < verbs_iter; i = i + 1 )
			add_vrb( verbs[ i ].get_vrb() );
		add_noun( syn );
		add_noun( noun_topic );
		add_noun( noun_topic_plural );
	}

	Subject sbjct = Subject( noun_topic );
 
	string temps[ 10000 ];
	int temps_iter;
	string sentance;
	for ( int i = 0; i < strings_iter; i = i + 1 )
	{
		empty( temps );
		move_words( strings[ i ], temps );
		temps_iter = length( temps );
		sentance = "";

		for ( int l = 0; l < temps_iter; l = l + 1 )
		{
			if ( is_string_empty( temps[ l ] ) )
				continue;

			if ( is_common( temps[ l ] ) )
			{
				sentance = sentance + temps[ l ] + ' ';
				continue;
			}

			if ( is_adj( temps[ l ] ) )
			{
				sentance = sentance + "(adj) ";
				sbjct.add_adj( temps[ l ] );
				continue;
			}

			if ( is_adv( temps[ l ] ) )
			{
				sentance = sentance + "(adv) ";

				string temp_verb = "";
				int pos;
				int temp_verb_iter = 0;
				for ( int b = 0; b < temps_iter; b = b + 1 )
					if ( is_vrb( temps[ b ] ) )
					{
						if ( temp_verb_iter == 0 )
						{
							temp_verb = temps[ b ];
							pos = positive( b - l );
						}

						if ( temp_verb_iter > 0 and positive( b - l ) < pos  )
						{
							temp_verb = temps[ b ];
							pos = positive( b - l );
						}

						temp_verb_iter = temp_verb_iter + 1;
					}

				if ( temp_verb_iter == 0 )
					continue;

				if ( temp_verb != "" )
					sbjct.add_adv( temp_verb, temps[ l ] );

				continue;
			}

			if ( is_vrb( temps[ l ] ) )
			{
				sentance = sentance + "(vrb) ";
				sbjct.add_vrb( temps[ l ] );
				continue;
			}

			if ( is_noun( temps[ l ] ) )
			{
				sentance = sentance + "(noun) ";
				sbjct.add_syn( temps[ l ] );
				continue;
			}

			cout << "In sentance - \"" << upper( strings[ i ] ) << ".\":\n";
			cout << '\'' << temps[ l ] << "\' is a:\n";
			cout << "1. Adj  2. Adv  3. Vrb  4. Noun  5. Common word\n";
			cout << "Choice: ";
			string choice;
			getline( cin, choice );
			if ( choice == "" )
				getline( cin, choice );
			if ( choice == "1" ) { add_adj( temps[ l ] ); }
			if ( choice == "2" ) { add_adv( temps[ l ] ); }
			if ( choice == "3" ) { add_vrb( temps[ l ] ); }
			if ( choice == "4" ) { add_noun( temps[ l ] ); }
			if ( choice == "5" ) { add_common( temps[ l ] ); }

			if ( l != 0 )
				l = l - 1;
		}

		reduce_spaces( sentance );
		add_sentance( sentance );
	}
}

string get_sentance_string ( Subject a )
{
	string pattern;

	for ( int i = 0; i < sentance_iter; i = i + 1 )
		if ( i == 0 )
		{
			pattern = sentance[ i ];
			break;
		}

	string patterns[ 90 ];
	int patterns_iter = 0;

	move_words( pattern, patterns );
	patterns_iter = length( patterns );

	string sentance = "";
	string vrb_string = "";
	bool have_noun_singular = 0;

	for ( int i = 0; i < patterns_iter; i = i + 1 )
	{
		if ( patterns[ i ] == "(adj)" )
		{
			sentance = sentance + a.get_adj( 0 ); + ' ';
			continue;
		}
		if ( patterns[ i ] == "(adv)" )
		{
			if ( vrb_string == "" )
				vrb_string = a.get_vrb( 0 );

			sentance = sentance + a.get_adv( vrb_string, 0 ); + ' ';
			continue;
		}
		if ( patterns[ i ] == "(vrb)" )
		{
			sentance = sentance + a.get_vrb( 0 ) + ' ';
			continue;
		}
		if ( patterns[ i ] == "(noun)" )
		{
			if ( ! have_noun_singular )
			{
				sentance = sentance + a.get_singular() + ' ';
				have_noun_singular = 1;
			}
			else
				sentance = sentance + a.get_syn( 0 ) + ' ';

			continue;
		}

		sentance = sentance + patterns[ i ] + ' ';
	}

	reduce_spaces( sentance );
	return upper( sentance ) + '.';
}

void edit ()
{
	string choice;
	cout << "Choices:  1. Adj  2. Adv  3. Vrb  4. Noun  5. Common words  6. Sentance\n";
	cout << "Choice: ";

	getline( cin, choice );

	if ( ! is_int( choice ) )
	{
		cout << "Invalid choice. Editing aborted.\n";
		return;
	}
	else
	{
		int num = string_to_int( choice );
		if ( num < 1 or num > 6 )
		{
			cout << "Invalid choice. Editing aborted.\n";
			return;
		}
	}

	if ( choice == "1" ) { choice = "adj"; }
	if ( choice == "2" ) { choice = "adv"; }
	if ( choice == "3" ) { choice = "vrb"; }
	if ( choice == "4" ) { choice = "noun"; }
	if ( choice == "5" ) { choice = "common"; }
	if ( choice == "6" ) { choice = "sentance"; }

	string edit_choice;
	if ( choice != "sentance" )
	{
		cout << '\n' << upper( choice ) << " choices:  1. Add word  2. Remove word  3. Show words\n";
		cout << "Choice: ";
	}
	else
	{
		cout << "\nSentance choices:  1. Add sentance  2. Remove sentance  3. Show sentances\n";
		cout << "Choice: ";
	}

	getline( cin, edit_choice );
	if ( edit_choice == "" )
		getline( cin, edit_choice );

	if ( ! is_int( edit_choice ) )
	{
		cout << "Invalid choice. Editing aborted.\n";
		return;
	}
	else
	{
		int num = string_to_int( edit_choice );
		if ( num < 1 or num > 3 )
		{
			cout << "Invalid choice. Editing aborted.\n";
			return;
		}
	}

	if ( choice == "adj" ) { cout << "\nAdjectives:\n"; }
	if ( choice == "adv" ) { cout << "\nAdverbs:\n"; }
	if ( choice == "vrb" ) { cout << "\nVerbs:\n"; }
	if ( choice == "noun" ) { cout << "\nNouns:\n"; }
	if ( choice == "common" ) { cout << "\nCommon words:\n"; }
	if ( choice == "sentance" ) { cout << "\nSentances:\n"; }


	string strings[ 10000 ];
	int strings_iter = 0;

	if ( choice != "sentance" )
		get_file( "parts_files/" + choice, strings_iter, strings );
	else
		get_file_lines( "parts_files/sentance", strings_iter, strings );

	if ( choice != "sentance" )
	{
		for ( int i = 0; i < strings_iter; i = i + 1 )
		{
			cout << '"' << strings[ i ] << '"';
			if ( i != strings_iter - 1 )
				cout << ", ";
		}
		cout << '\n';
	}
	else
	{
		if ( edit_choice == "2" )
			for ( int i = 0; i < strings_iter; i = i + 1 )
				cout << i + 1 << ". " << strings[ i ] << '\n';
		else
			for ( int i = 0; i < strings_iter; i = i + 1 )
				cout << strings[ i ] << '\n';
	}
	
	cout << '\n';

	if ( edit_choice == "3" )
		return;

	if ( edit_choice == "1" )
		cout << "Add \"" << choice << "\" ( empty means done ):\n";
	else
		cout << "Remove \"" << choice << "\" ( empty means done ):\n";

	string words[ 10000 ];
	int words_iter = 0;

	string temp = "temps";
	while ( getline( cin, temp ) and ! is_string_empty( temp ) )
	{
		remove_chars( temp );
		reduce_spaces( temp );
		lower( temp );

		words[ words_iter ] = temp;
		words_iter = words_iter + 1;
	}

	if ( edit_choice == "1" )
	{
		if ( choice == "adj" ) { add_adj( words ); }
		if ( choice == "adv" ) { add_adv( words ); }
		if ( choice == "vrb" ) { add_vrb( words ); }
		if ( choice == "noun" ) { add_noun( words ); }
		if ( choice == "common" ) { add_common( words ); }
		if ( choice == "sentance" ) { add_sentance( words ); }
	}
	else
	{
		if ( choice == "adj" ) { remove_adj( words ); }
		if ( choice == "adv" ) { remove_adv( words ); }
		if ( choice == "vrb" ) { remove_vrb( words ); }
		if ( choice == "noun" ) { remove_noun( words ); }
		if ( choice == "common" ) { remove_common( words ); }
		if ( choice == "sentance" ) { remove_sentance( words ); }
	}
}


void edit_subjects ()
{
	if ( sb_iter == 0 )
	{
		cout << "Subjects invalid. Please add!\n";
		return;
	}

	string edit_choice;
	cout << "Subject choices:  1. Add subject  2. Remove subject  3. Edit subject  4. Show subject\n";
	cout << "Choice: ";

	getline( cin, edit_choice );
	if ( edit_choice == "" )
		getline( cin, edit_choice );

	if ( ! is_int( edit_choice ) )
	{
		cout << "Invalid choice. Editing aborted.\n";
		return;
	}
	else
	{
		int num = string_to_int( edit_choice );
		if ( num < 1 or num > 3 )
		{
			cout << "Invalid choice. Editing aborted.\n";
			return;
		}
	}

	if ( edit_choice == "1" )
	{
		add_subject();
		return;
	}

	cout << "Subjects:\n";
	set_num( sb, 5 );
	cout << "\n\n";


	cout << "Choice: ";
	string choice;
	getline( cin, choice );
	if ( choice == "" )
		getline( cin, choice );

	if ( ! is_int( choice ) )
	{
		cout << "Invalid choice. Editing aborted.\n";
		return;
	}


	int num = string_to_int( choice );
	if ( num < 1 or num > sb_iter )
	{
		cout << "Invalid choice. Editing aborted.\n";
		return;
	}
	num = num - 1;

	if ( edit_choice == "2" )
	{
		remove_string( sb, sb[ num ] );
		set_file( "parts_files/sb", sb );
		return;
	}


	Subject sbjct = Subject( sb[ num ] );

	if ( edit_choice == "3" or edit_choice == "4" )
		sbjct.info();

	if ( edit_choice == "4" )
		return;

	if ( edit_choice == "3" )
	{
		string choice_subject;

		cout << "Edit:  1. Singular  2. Plural  3. Synonims  4. Adj  5. Vrb  6. Adv\n";
		cout << "Choice: ";

		getline( cin, choice_subject );
		if ( choice_subject == "" )
			getline( cin, choice_subject );

		if ( ! is_int( choice_subject ) )
		{
			cout << "Invalid choice. Editing aborted.\n";
			return;
		}

		num = string_to_int( choice_subject );
		if ( num < 1 or num > 6 )
		{
			cout << "Invalid choice. Editing aborted.\n";
			return;
		}
		num = num - 1;


		string subject_temp;
		string temps[ 10000 ];
		int temps_iter = 0;

		if ( choice_subject == "1" )
		{
			cout << "Set singular ( was \"" << sbjct.get_singular() << "\" ) to: ";
			cin >> subject_temp;
			lower( subject_temp );
			sbjct.set_singular( subject_temp );
		}

		if ( choice_subject == "2" )
		{
			cout << "Set plural ( was \"" << sbjct.get_plural() << "\" ) to: ";
			cin >> subject_temp;
			lower( subject_temp );
			sbjct.set_plural( subject_temp );
		}

		if ( choice_subject == "3" )
		{
			string syn_choice;
			cout << "Synonims:  1. Add  2. Remove\n";

			getline( cin, syn_choice );
			if ( syn_choice == "" )
				getline( cin, syn_choice );
		

			if ( ! is_int( syn_choice ) )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}

			num = string_to_int( syn_choice );
			if ( num < 1 or num > 2 )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}
			num = num - 1;

			if ( num == 1 )
			{
				cout << "Add synonim ( empty means done ):\n";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );
					sbjct.add_syn( subject_temp );			
				}
			}
			else
			{
				cout << "Remove synonim ( empty means done ):\n";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );
					sbjct.remove_syn( subject_temp );				
				}
			}
		}

		if ( choice_subject == "4" )
		{
			string adj_choice;
			cout << "Adj:  1. Add  2. Remove\n";

			getline( cin, adj_choice );
			if ( adj_choice == "" )
				getline( cin, adj_choice );
		

			if ( ! is_int( adj_choice ) )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}

			num = string_to_int( adj_choice );
			if ( num < 1 or num > 2 )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}
			num = num - 1;

			if ( num == 1 )
			{
				cout << "Add adj: ";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );
					sbjct.add_adj( subject_temp );			
				}
			}
			else
			{
				cout << "Remove adj: ";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );
					sbjct.remove_adj( subject_temp );				
				}
			}			
		}

		if ( choice_subject == "5" )
		{
			string vrb_choice;
			cout << "Vrb:  1. Add  2. Remove\n";

			cout << "Choice: ";

			getline( cin, vrb_choice );
			if ( vrb_choice == "" )
				getline( cin, vrb_choice );
		

			if ( ! is_int( vrb_choice ) )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}

			num = string_to_int( vrb_choice );
			if ( num < 1 or num > 2 )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}
			num = num - 1;

			if ( num == 0 )
			{
				cout << "Add vrb ( empty means done ):\n";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );

					cout << "Add adv for vrb \"" << subject_temp << "\" ( y / n ): ";

					string add_adv_choice;

					getline( cin, add_adv_choice );
					while ( add_adv_choice == "" )
						getline( cin, add_adv_choice );

					if ( add_adv_choice == "y" )
					{
						cout << "Add adv ( empty means done ):\n";
						string verb = subject_temp;
						string adverbs[ 90 ];
						int adverbs_iter = 0;

						while ( getline( cin, subject_temp ) and ! is_string_empty( subject_temp ) )
						{
							remove_chars( subject_temp );
							reduce_spaces( subject_temp );
							lower( subject_temp );

							adverbs[ adverbs_iter ] = subject_temp;
							adverbs_iter = adverbs_iter + 1;
						}

						sbjct.add_vrb( verb, adverbs );
					}
					else
						sbjct.add_vrb( subject_temp );
					cout << '\n';		
				}
			}
			else
			{
				cout << "Remove vrb ( empty means done ):\n";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );
					sbjct.remove_vrb( subject_temp );				
				}
			}
		}

		if ( choice_subject == "6" )
		{
			Verb verbs[ 90 ];
			string verb_string[ 90 ];
			int verb_iter = 0;
			sbjct.get_vrb( verbs );

			while ( verbs[ verb_iter ].get_vrb() != "" )
			{
				verb_string[ verb_iter ] = verbs[ verb_iter ].get_vrb();
				verb_iter = verb_iter + 1;			
			}

			cout << '\n';
			cout << "Verbs of \"" << upper( sbjct.get_singular() ) << "\":\n";

			set_num( verb_string, 5 );

			cout << "\n\n";

			cout << "Choice: ";
			string choice_verb;

			getline( cin, choice_verb );
			if ( choice_verb == "" )
				getline( cin, choice_verb );


			if ( ! is_int( choice_verb ) )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}

			num = string_to_int( choice_verb );
			if ( num < 1 or num > verb_iter )
			{
				cout << "Invalid choice. Editing aborted.\n";
				return;
			}
			num = num - 1;
 
			int l = num;

			cout << '\'' << verbs[ l ].get_vrb() << "\': ";
			string adverbs[ 10000 ];
			verbs[ l ].get_adv( adverbs );

			for ( int i = 0; i < length( adverbs ); i = i + 1 )
			{
				cout << '"' << adverbs[ i ] << '"';
				if ( i != length( adverbs ) - 1 )
					cout << ", ";
			}

			cout << "\n\n";
			string adv_vrb_choice;
			cout << "Verb \"" << verbs[ l ].get_vrb() << "\" choices:  1. Add adv  2. Remove adv\n";
			cout << "Choice: ";

			getline( cin, adv_vrb_choice );
			if ( adv_vrb_choice == "" )
				getline( cin, adv_vrb_choice );

			if ( ! is_int( adv_vrb_choice ) )
			{
				cout << "Invalid choice. Aborted.\n";
				return;
			}

			num = string_to_int( choice_verb );
			if ( num < 1 or num > verb_iter )
			{
				cout << "Invalid choice. Aborted.\n";
				return;
			}
			num = num - 1;

			cout << '\n';

			if ( num == 0 )
			{
				cout << "Add adv ( empty means done ):\n";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );
					adverbs[ length( adverbs ) ] = subject_temp;
				}
			}
			else
			{
				cout << "Remove adv ( empty means done ):\n";

				while ( cin >> subject_temp and ! is_string_empty( subject_temp ) )
				{
					lower( subject_temp );
					remove_string( adverbs, subject_temp );
				}
			}

			sbjct.set_adv( l, adverbs );
		}

	}

}

void get_strings()
{
	get_common();
	get_adj();
	get_adv();
	get_vrb();
	get_noun();
	get_sb();
	get_sentance();
}

int main ()
{
	get_strings();

	for ( int i = 0; i < 10000; i = i + 1 )
	{
		string choice;
		cout << "\033c";
		cout << "Choices:  1. Add File  2. Get Sentance  3. Sentances and words  4. Subjects  5. Exits\n";
		cout << "Choice: ";

		getline( cin, choice );

		cout << '\n';

		if ( choice == "1" )
		{
			cout << "Filename: ";

			string filename;

			getline( cin, filename );
			if ( filename == "" )
				getline( cin, filename );

			set_file( filename );

			cout << "File added!\n";

			continues();
			continue;
		}

		if ( choice == "2" )
		{
			if ( sb_iter != 0 )
			{
				cout << "Subjects:\n";
				set_num( sb, 5 );
				cout << "\n\n";
				cout << "Choice: ";

				getline( cin, choice );
				if ( choice == "" )
					getline( cin, choice );

				lower( choice );

				if ( is_int( choice ) )
				{
					int noun_int = string_to_int( choice );
					noun_int = noun_int - 1;
					if ( noun_int < 0 or noun_int >= sb_iter )
					{
						cout << "Invalid subject num.\n";
						continues();
						continue;
					}
					else
						choice = sb[ noun_int ];
				}

				string sentance;

				Subject sbjct = Subject( choice );

				if ( sbjct.get_singular() != "" )
					cout << '\n' << get_sentance_string( sbjct ) << "\n\n";
				else
					cout << "Invalid subject.\n";
			}
			else
				cout << "Subjects invalid.\n";

			continues();
			continue;
		}

		if ( choice == "3" )
		{
			edit();
			continues();
			continue;
		}

		if ( choice == "4" )
		{
			edit_subjects();
			continues();
			continue;
		}

		if ( choice == "5" )
		{
			cout << "Exited.\n";
			break;
		}
	}

	return 0;
}
