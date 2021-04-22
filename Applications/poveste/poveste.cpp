#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}


int length ( string a[] )
{
	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;

	return i;
}



// inverts a string
void invert_string( string &a )
{
	int size = a.length();

	string b = "";

	for ( int i=size-1; i>=0; i=i-1 )
		b = b + a[i];

	a = b;
}

// is numeric char
bool is_numeric( char a )
{
	if ( a >= '0' and a <= '9' )
		return true;

	return false;
}



// datatypes to a string



// converts an int to a string
string int_to_string (int a)
{
	int size = length(a);

	bool is_neg = false;
	if ( a < 0 )
	{
		is_neg = true;
		a = -a;
	}

	string result = "";

	for (int i=0; i<size; i=i+1)
	{	
		char a_char = (char) (a % 10 + 48);

		if ( is_numeric( a_char ) )
			result = result + a_char;
		a = a / 10;
	}

	if ( is_neg )
		result = result + '-';

	invert_string( result );

	return result;
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
	if ( a.length() == 0 )
		return a;

	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;

	return a;
}


string firstnames_male[ 1000 ];
string firstnames_female[ 1000 ];
string lastnames[ 1000 ];
string other_names[ 1000 ];
string statuses[ 1000 ];
string adjectives_pos[ 1000 ];
string adjectives_neg[ 1000 ];
string appearances[ 1000 ];

string place_names[ 1000 ];
string place_adjectives[ 1000 ];
string achivements[ 1000 ];

string nums[ 1000 ];

string items[ 1000 ];
string completions[ 1000 ];



bool rand_bool () 
{
	return 0;
}

int rand ( int a )
{
	return 0;
}

int rand ( int a1, int a2 )
{
	return 0;
}

int rand ( string a[] )
{
	return 0;
}

class Character 
{
  public:

	string firstname;
	string lastname;
	string other_name;
	int age;
	bool gender;
	string status;
	string qualities[ 1000 ];
	string defects[ 1000 ];
	string appearance[ 1000 ];
	bool pos;


	Character ()
	{
		this->gender = rand_bool();

		if ( this->gender == 0 )
			this->firstname = firstnames_male[ rand( length( firstnames_male ) ) ];
		else
			this->firstname = firstnames_female[ rand( length( firstnames_female ) ) ];

		this->firstname = upper( this->firstname );

		this->lastname = upper( lastnames[ rand( length( lastnames ) ) ] );
		this->other_name = upper( other_names[ rand( length( other_names ) ) ] );
		this->age = rand( 100 );
		this->status = statuses[ rand( length( statuses ) ) ];
		for ( int i = 0; i < 9; i = i + 1 )
			this->qualities[ i ] = adjectives_pos[ rand( length( adjectives_pos ) ) ];
		for ( int i = 0; i < 9; i = i + 1 )
			this->defects[ i ] = adjectives_neg[ rand( length( adjectives_neg ) ) ];
		for ( int i = 0; i < 9; i = i + 1 )
			this->appearance[ i ] = appearances[ rand( length( appearances ) ) ];
		this->pos = rand_bool();
	}

	Character ( bool gender )
	{
		this->gender = gender;

		if ( this->gender == 0 )
			this->firstname = firstnames_male[ rand( length( firstnames_male ) ) ];
		else
			this->firstname = firstnames_female[ rand( length( firstnames_female ) ) ];

		this->firstname = upper( this->firstname );

		this->lastname = upper( lastnames[ rand( length( lastnames ) ) ] );
		this->other_name = upper( other_names[ rand( length( other_names ) ) ] );
		this->age = rand( 100 );
		this->status = statuses[ rand( length( statuses ) ) ];
		for ( int i = 0; i < 9; i = i + 1 )
			this->qualities[ i ] = adjectives_pos[ rand( length( adjectives_pos ) ) ];
		for ( int i = 0; i < 9; i = i + 1 )
			this->defects[ i ] = adjectives_neg[ rand( length( adjectives_neg ) ) ];
		for ( int i = 0; i < 9; i = i + 1 )
			this->appearance[ i ] = appearances[ rand( length( appearances ) ) ];
		this->pos = rand_bool();
	}

	string get_info ()
	{
		string info = this->firstname + ' ' + this->lastname + " \"" + this->other_name + "\" ( ";
		if ( this->gender == 0 )
			info = info + "male";
		else
			info = info + "female";
		info = info + " )\n";


		info = info + " - is an " + int_to_string( this->age ) + " year old " + this->status + '\n';
		info = info + " - qualities: ";
		for ( int i = 0; i < 9; i = i + 1 )
		{
			info = info + this->qualities[ i ];
			if ( i != 9 - 1 )
				info = info + ", ";
		}
		info = info + '\n';

		info = info + " - defects: ";
		for ( int i = 0; i < 9; i = i + 1 )
		{
			info = info + this->defects[ i ];
			if ( i != 9 - 1 )
				info = info + ", ";
		}
		info = info + '\n';

		info = info + " - appearance: ";
		for ( int i = 0; i < 9; i = i + 1 )
		{
			info = info + this->appearance[ i ];
			if ( i != 9 - 1 )
				info = info + ", ";
		}
		info = info + "\n\n\n";

		return info;
	}
};


struct challange
{
	string completion;
	int time;
	string item[ 25 ];
	Character pos[ 25 ];
	Character neg[ 25 ];
} challanges[ 90 ];

struct place 
{
	string name;
	string adjectives[ 90 ];
} places[ 90 ];


string achivement;



string init[ 1000 ]; 
string journey[ 1000 ]; // precedes challange ( completion )
string completion[ 1000 ]; 
string last[ 1000 ]; // sort of completion


void get_strings ()
{
	string temp;
	int iter = 0;

	ifstream fi;
	fi.open( "text_files/" );

	fi.close();


	// firstnames_male
	fi.open( "text_files/character/firstnames_male" );

	while ( fi >> temp )
	{
		firstnames_male[ iter ] = upper( temp );
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// firstnames_female
	fi.open( "text_files/character/firstnames_female" );

	while ( fi >> temp )
	{
		firstnames_female[ iter ] = upper( temp );
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// lastnames
	fi.open( "text_files/character/lastnames" );

	while ( fi >> temp )
	{
		lastnames[ iter ] = upper( temp );
		iter = iter + 1;
	}

	fi.close();
	iter = 0;

	// other_names
	fi.open( "text_files/character/other_names" );

	while ( fi >> temp )
	{
		other_names[ iter ] = upper( temp );
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// statuses
	fi.open( "text_files/character/statuses" );

	while ( fi >> temp )
	{
		statuses[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// adjectives_pos
	fi.open( "text_files/character/adjectives_pos" );

	while ( fi >> temp )
	{
		adjectives_pos[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// adjectives_neg
	fi.open( "text_files/character/adjectives_neg" );

	while ( fi >> temp )
	{
		adjectives_neg[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// appearances
	fi.open( "text_files/character/appearances" );

	while ( fi >> temp )
	{
		appearances[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;







	// completions
	fi.open( "text_files/place/completions" );

	while ( getline( fi, temp ) )
	{
		completions[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// nums
	fi.open( "text_files/place/nums" );

	while ( fi >> temp )
	{
		nums[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// items
	fi.open( "text_files/place/items" );

	while ( getline( fi, temp ) )
	{
		items[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// place_names
	fi.open( "text_files/place/place_names" );

	while ( getline( fi, temp ) )
	{
		place_names[ iter ] = upper( temp );
		iter = iter + 1;
	}

	fi.close();
	iter = 0;


	// place_adjectives
	fi.open( "text_files/place/place_adjectives" );

	while ( getline( fi, temp ) )
	{
		place_adjectives[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;

	// achive
	fi.open( "text_files/character/achive" );

	while ( getline( fi, temp ) )
	{
		achivements[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;






	// place_adjectives
	fi.open( "text_files/structure/init" );

	while ( getline( fi, temp ) )
	{
		init[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;

	// place_adjectives
	fi.open( "text_files/structure/journey" );

	while ( getline( fi, temp ) )
	{
		journey[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;

	// place_adjectives
	fi.open( "text_files/structure/completion" );

	while ( getline( fi, temp ) )
	{
		completion[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;

	// place_adjectives
	fi.open( "text_files/structure/last" );

	while ( getline( fi, temp ) )
	{
		last[ iter ] = temp;
		iter = iter + 1;
	}

	fi.close();
	iter = 0;

}

Character protagonist;
Character siblings[ 15 ];
Character mother;
Character father;

place place1;
place place2;

challange chlnge;

void set ()
{
	achivement = achivements[ rand( length( achivements ) ) ];

	for ( int i = 0; i < 15; i = i + 1 )
	{
		places[ i ].name = place_names[ rand( length( place_names ) ) ];
		for ( int l = 0; l < 3; l = l + 1 )
			places[ i ].adjectives[ l ] = place_adjectives[ rand( length( place_adjectives ) ) ];
	}	

	place1.name = place_names[ rand( length( place_names ) ) ];
	for ( int l = 0; l < 3; l = l + 1 )
		place1.adjectives[ l ] = place_adjectives[ rand( length( place_adjectives ) ) ];

	place2.name = place_names[ rand( length( place_names ) ) ];
	for ( int l = 0; l < 3; l = l + 1 )
		place2.adjectives[ l ] = place_adjectives[ rand( length( place_adjectives ) ) ];

	for ( int i = 0; i < 9; i = i + 1 )
	{
		challanges[ i ].completion = completions[ rand( length( completions ) ) ];
		challanges[ i ].time = rand( 9 );

		for ( int l = 0; l < 9; l = l + 1 )
		{
			challanges[ i ].item[ l ] = items[ rand( length( items ) ) ];

			challanges[ i ].pos[ l ] = Character( l % 2 );
			challanges[ i ].pos[ l ].pos = 1;

			challanges[ i ].neg[ l ] = Character( l % 2 );
			challanges[ i ].neg[ l ].pos = 0;
		}
	}

	protagonist = Character();
	protagonist.age = rand( 15, 25 );
	protagonist.pos = 1;

	ofstream fo;
	fo.open( "result" );
	fo.close(); // clear file

	fo.open( "result" );

	fo << "Protagonist\n\n";
	fo << protagonist.get_info();

	fo << "Initial place: " << place1.name << "\n\n";
	fo << "Final place: " << place2.name << "\n\n";
	fo << "Final goal: " << achivement << "\n\n\n";

	fo << "Siblings\n\n";

	for ( int i = 0; i < 3; i = i + 1 )
	{
		siblings[ i ] = Character();
		fo << siblings[ i ].get_info();
	}

	fo << "Parents\n\n";
	mother = Character( 1 );
	fo << mother.get_info();
	father = Character( 0 );
	fo << father.get_info();


	Character temp;	
	fo << "Challanges\n\n";
	for ( int l = 3; l < 9; l = l + 1 ) // l = 0
	{
		fo << upper( challanges[ l ].completion ) << ":\n";

		fo << " - place: " << places[ l ].name << " ( ";
		for ( int i = 0; i < 3; i = i + 1 )
		{
			fo << places[ l ].adjectives[ i ];
			if ( i != 3 - 1 )
				fo << ", ";
		}
		fo << " )\n";

		for ( int m = 0; m < 2; m = m + 1 ) // 2 should be rand( 1 , 4 ) !!!!!
		{
			challanges[ l ].pos[ m ].pos = 0;
			temp = challanges[ l ].pos[ m ];
			fo << " - negative character \"" << temp.firstname << ' ' << temp.lastname << "\" ( ";
			for ( int i = 0; i < 9; i = i + 1 )
			{
				fo << temp.appearance[ i ];
				if ( i != 9 - 1 )
					fo << ", ";
			}
			fo << " )\n";
		}


		for ( int m = 0; m < 2; m = m + 1 ) // 2 should be rand( 1 , 4 ) !!!!!
		{
			challanges[ l ].pos[ m ].pos = 1;
			temp = challanges[ l ].pos[ m ];
			fo << " - positive character \"" << temp.firstname << ' ' << temp.lastname << "\" ( ";
			for ( int i = 0; i < 9; i = i + 1 )
			{
				fo << temp.appearance[ i ];
				if ( i != 9 - 1 )
					fo << ", ";
			}
			fo << " )\n";
		}

		fo << " - completed in " << challanges[ l ].time << " days\n";
		fo << " - given items: ";

		for ( int i = 0; i < 9; i = i + 1 )
		{
			fo << '"' << challanges[ l ].item[ i ] << '"';
			if ( i != 9 - 1 )
				fo << ", ";
		}

		fo << "\n\n";
	}


	fo.close();
}


// move words of   string text   into   words[]
void move_words ( string text, string words[], char separator )
{
	text = text + separator;

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == separator )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}




string get_char_property ( Character a[], string iter1, string property, string iter2 )
{
	int i = string_to_int( iter1 );
	int l = string_to_int( iter2 );

	if ( property == "quality" )
		return a[ i ].qualities[ l ];
	if ( property == "defect" )
		return a[ i ].defects[ l ];
	if ( property == "appearance" )
		return a[ i ].appearance[ l ];

	return "invalid_string";
}

string get_char_property ( Character a, string property, string iter )
{
	int i = string_to_int( iter );

	if ( property == "quality" )
		return a.qualities[ i ];
	if ( property == "defect" )
		return a.defects[ i ];
	if ( property == "appearance" )
		return a.appearance[ i ];

	return "invalid_string";
}

string get_char_property ( Character a[], string iter, string property )
{
	int i = string_to_int( iter );

	if ( property == "fname" )
		return a[ i ].firstname;
	if ( property == "lname" )
		return a[ i ].lastname;
	if ( property == "oname" )
		return a[ i ].other_name;
	if ( property == "age" )
		return int_to_string( a[ i ].age );
	if ( property == "gender" )
	{
		if ( a[ i ].gender == 0 )
			return "man";
		else
			return "woman";
	}
	if ( property == "status" )
		return a[ i ].status;
	if ( property == "pos" )
	{
		if ( a[ i ].pos )
			return "positive";
		else
			return "negative";
	}

	return "invalid_string";
}

string get_char_property ( Character a, string property )
{
	if ( property == "fname" )
		return a.firstname;
	if ( property == "lname" )
		return a.lastname;
	if ( property == "oname" )
		return a.other_name;
	if ( property == "age" )
		return int_to_string( a.age );
	if ( property == "gender" )
	{
		if ( a.gender == 0 )
			return "man";
		else
			return "woman";
	}
	if ( property == "status" )
		return a.status;
	if ( property == "pos" )
	{
		if ( a.pos )
			return "positive";
		else
			return "negative";
	}
	
	return "invalid_string";
}

Character pos_chars[ 1000 ];
Character neg_chars[ 1000 ];

string get_place_property ( place a[], string iter1, string property, string iter2 )
{
	int i = string_to_int( iter1 );
	int l = string_to_int( iter2 );

	if ( property == "attr" )
		return places[ i ].adjectives[ l ];
}

string get_place_property ( place a[], string iter, string property )
{
	int i = string_to_int( iter );
	if ( property == "name" )
		return places[ i ].adjectives[ i ];
}

string get_place_property ( place a, string property, string iter )
{
	int i = string_to_int( iter );
	if ( property == "attr" )
		return a.adjectives[ i ];
}

string get_place_property ( place a, string property )
{
	if ( property == "name" )
		return a.name;
}



string get_challange_property ( string property, string iter )
{
	int i = string_to_int( iter );

	if ( property == "item" )
		return chlnge.item[ i ];
	return "invalid_string";
}

string get_challange_property ( string property )
{
	if ( property == "ach" )
		return chlnge.completion;
	if ( property == "time" )
		return int_to_string( chlnge.time );
	return "invalid_string";
}

void lower ( string &a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			a[ i ] = a[ i ] + 32;
}

string get_property ( string a )
{
	lower( a );

	int count_parts = 0;
	int size = a.length();

	string parts[ 5 ];

	for ( int i = 0; i < size; i = i + 1 )
		if ( a[ i ] == '_' )
			count_parts = count_parts + 1;
	count_parts = count_parts + 1;


	move_words( a, parts, '_' );


	if ( count_parts == 1 )
	{
		if ( parts[ 0 ] == "achivement" )
			return achivement;


		if ( parts[ 0 ] == "he" )
		{
			if ( protagonist.gender == 0 )
				return "he";
			else
				return "she";
		}

		if ( parts[ 0 ] == "him" )
		{
			if ( protagonist.gender == 0 )
				return "him";
			else
				return "her";
		}

		if ( parts[ 0 ] == "his" )
		{
			if ( protagonist.gender == 0 )
				return "his";
			else
				return "hers";
		}

	}

	if ( count_parts == 2 )
	{
		if ( parts[ 0 ] == "prot" )
			return get_char_property( protagonist, parts[ 1 ] );

		if ( parts[ 0 ] == "mother" )
			return get_char_property( mother, parts[ 1 ] );

		if ( parts[ 0 ] == "father" )
			return get_char_property( father, parts[ 1 ] );


		if ( parts[ 0 ] == "place1" )
			return get_place_property( place1, parts[ 1 ] );

		if ( parts[ 0 ] == "place2" )
			return get_place_property( place2, parts[ 1 ] );


		if ( parts[ 0 ] == "challange" ) // remake chlnge variable for every challange ( completion )
			return get_challange_property( parts[ 1 ] );
	}

	if ( count_parts == 3 )
	{
		if ( parts[ 0 ] == "prot" )
			return get_char_property( protagonist, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "mother" )
			return get_char_property( mother, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "father" )
			return get_char_property( father, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "pos" ) // remake character array for every challange ( completion )
			return get_char_property( pos_chars, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "neg" ) // remake character array for every challange ( completion )
			return get_char_property( neg_chars, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "sibling" )
			return get_char_property( siblings, parts[ 1 ], parts[ 2 ] );


		if ( parts[ 0 ] == "place" )
			return get_place_property( places, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "place1" )
			return get_place_property( place1, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "place2" )
			return get_place_property( place2, parts[ 1 ], parts[ 2 ] );

		if ( parts[ 0 ] == "challange" ) // remake chlnge variable for every challange ( completion )
			return get_challange_property( parts[ 1 ], parts[ 2 ] );
	}

	if ( count_parts == 4 )
	{
		if ( parts[ 0 ] == "pos" ) // remake character array for every challange ( completion )
			return get_char_property( pos_chars, parts[ 1 ], parts[ 2 ], parts[ 3 ] );

		if ( parts[ 0 ] == "neg" ) // remake character array for every challange ( completion )
			return get_char_property( neg_chars, parts[ 1 ], parts[ 2 ], parts[ 3 ] );

		if ( parts[ 0 ] == "sibling" )
			return get_char_property( siblings, parts[ 1 ], parts[ 2 ], parts[ 3 ] );


		if ( parts[ 0 ] == "place" )
			return get_place_property( places, parts[ 1 ], parts[ 2 ], parts[ 3 ] );
	}

	return "invalid_string";
}

string get_replaced ( string a )
{
	int size = a.length();
	string property = "";
	string result = "";

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( a[ i ] == '[' )
		{
			property = "";
			i = i + 1;
			while ( a[ i ] != ']' )
			{
				property = property + a[ i ];
				i = i + 1;
			}

			string prpty = get_property( property );

			if ( property[ 0 ] >= 'A' and property[ 0 ] <= 'Z' )
				prpty = upper( prpty );

			result = result + prpty;
			continue;
		}

		result = result + a[ i ];
	}

	return result;
}

string inits; 
string journeys[ 1000 ]; // precedes challange ( completion )
string compltns[ 1000 ]; 
string lasts; // sort of completion

void set_structure ()
{
	inits = init[ rand( length( init ) ) ];
	lasts = last[ rand( length( last ) ) ];
	for ( int i = 0; i < 9; i = i + 1 )
	{
		journeys[ i ] = journey[ rand( length( journey ) ) ];
		compltns[ i ] = completion[ rand( length( completion ) ) ];
	}

	place p1 = place1;
	place p2 = place2;

	ofstream fo;
	fo.open( "result_poveste" );

	fo << get_replaced( inits ) << "\n\n";

	for ( int i = 0; i < 9; i = i + 1 )
	{
		chlnge = challanges[ i ];
		for ( int l = 0; l < 9; l = l + 1 )
			pos_chars[ l ] = chlnge.pos[ l ];
		for ( int l = 0; l < 9; l = l + 1 )
			neg_chars[ l ] = chlnge.neg[ l ];

		place1 = places[ i ];
		place2 = places[ i + 1 ];

		fo << get_replaced( journeys[ i ] ) << "\n";
		fo << get_replaced( compltns[ i ] ) << "\n\n";
	}

	fo << get_replaced( lasts );

	fo.close();
}


int main ()
{
	get_strings();
	set();
	set_structure();

	cout << "Completed.\n";
	cout << "Exited. ";
	cout << "Done. ";

	return 0;
}
