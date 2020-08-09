
// invert a string
string invert_string (string a)
{
	int len = a.length();
	string r = "";

	for (int i=len-1; i>=0; i=i-1)
	{
		r = r + a[i];
	}
	cout << "\n";

	return r;
}

void invert ( long a[] )
{
	int size = length( a );
	long b[ size + 1 ];

	for ( int i = 0; i < size; i = i + 1 )
		b[ size - i - 1 ] = a[ i ];

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];
}

void invert ( int a[] )
{
	int size = length( a );
	int b[ size + 1 ];

	for ( int i = 0; i < size; i = i + 1 )
		b[ size - i - 1 ] = a[ i ];

	for ( int i = 0; i < size; i = i + 1 )
		a[ i ] = b[ i ];
}

void invert (float a[])
{
	int size = length(a);

	float invert[10000]; // does not want invert[ length(a) + 1 ]; - Segm. Fault

	for (int i=0; i<size; i=i+1)
		invert[ size - i - 1 ] = a[i];

	for (int i=0; i<size; i=i+1)
		a[i] = invert[i];
}

void invert (double a[])
{
	int size = length(a);

	double invert[10000]; // does not want invert[ length(a) + 1 ]; - Segm. Fault

	for (int i=0; i<size; i=i+1)
		invert[ size - i - 1 ] = a[i];

	for (int i=0; i<size; i=i+1)
		a[i] = invert[i];
}

void invert (char a[])
{
	int size = length(a);

	char invert[10000]; // does not want invert[ length(a) + 1 ]; - Segm. Fault

	for (int i=0; i<size; i=i+1)
		invert[ size - i - 1 ] = a[i];

	for (int i=0; i<size; i=i+1)
		a[i] = invert[i];
}

void invert (string &a)
{
	int size = length(a);

	char invert[10000]; // does not want invert[ length(a) + 1 ]; - Segm. Fault

	for (int i=0; i<size; i=i+1)
		invert[ size - i - 1 ] = a[i];

	for (int i=0; i<size; i=i+1)
		a[i] = invert[i];
}

void invert (string a[])
{
	int size = length(a);

	string invert[10000]; // does not want invert[ length(a) + 1 ]; - Segm. Fault

	for (int i=0; i<size; i=i+1)
		invert[ size - i - 1 ] = a[i];

	for (int i=0; i<size; i=i+1)
		a[i] = invert[i];
}


// to continue
void continues ()
{
	char chars;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> chars;
//	cout << "\n";

//	string empty; // to continue
//	getline( cin, empty );
}
// replaces spaces in entered data, to make valid variable names
void replace_space (string &a)
{
	for (int i=0; i<a.length(); i=i+1)
		if ( a[i] == ' ' )
			a[i] = '_';
}

void replace_space (string &a, char b)
{
	for (int i=0; i<a.length(); i=i+1)
		if ( a[i] == ' ' )
			a[i] = b;
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
		if ( !( a[i] >= 'a' and a[i] <= 'z' ) and !( a[i] >= 'A' and a[i] <= 'Z' ) and !( a[i] >= '0' and a[i] <= '9' ) )
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

// move words of   string text   into   words[]
void move_words ( string text, string words[] )
{
	text = text + " ";

	int size = text.length();

	int words_iter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( text[i] == ' ' )
		{
			words_iter = words_iter + 1;
			words[ words_iter ] = "";
		}
		else
			words[ words_iter ] = words[ words_iter ] + text[i];
}

void move_strings ( string file, string strings[], string a )
{
	if ( a.length() == 0 ) return;
	int size = file.length();
	int strings_iter = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( file[ i ] == a[ 0 ] )
		{
			bool have_a = 1;
			int file_iter = i;
			for ( int l = file_iter; l < a.length(); l = l + 1 )
				if ( file[ l ] != a[ l ] )
				{
					have_a = 0;
					break;
				}

			if ( have_a )
			{
				i = i + a.length() - 1;
				strings_iter = strings_iter + 1;
				strings[ strings_iter ] = "";
				continue;
			}
		}
		strings[ strings_iter ] = strings[ strings_iter ] + file[ i ];
	}
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

// removes plurals
string remove_plural( string &word )
{
	string plural_removed = "";
	int size = word.length();

	for ( int i=0; i<size - 2; i=i+1 )
		plural_removed = plural_removed + word[i];

	if ( word[size - 2] != 'e' )
 		plural_removed = plural_removed + word[size - 2];

	word = plural_removed;

	return plural_removed;
}

// remove a  word  in  words[]  
void remove_word ( string words[], string word )
{
	string word_removed[10000];
	int iter = 0;

	int size = 0;
	while ( words[ size ].length() > 0 )
		size = size + 1;


	for ( int i=0; i<size; i=i+1 )
		if ( words[i] != word )
		{
			word_removed[ iter ] = words[i];
			iter = iter + 1;
		}

	for ( int i=0; i<size; i=i+1 )
		words[i] = "";

	for ( int i=0; i<iter; i=i+1 )
		words[i] = word_removed[i];
}


bool is_string_empty( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;
	return 1;
}

void get_strings ( string strings[] )
{
	string temp;
	int strings_iter = 0;

	cout << " ( empty means done )\n";

	while ( getline( cin, temp ) and ! is_string_empty ( temp ) )
	{
		strings[ strings_iter ] = temp;
		strings_iter = strings_iter + 1;
	}
}

// is in string[]
int in_strings ( string words[], string word )
{
	int size = length( words );

	for ( int i = 0; i < size; i = i + 1 )
		if ( word == words[i] )
			return i;

	return -1;
}



// is numeric char
bool is_integer ( char a )
{
	if ( a >= '0' and a <= '9' or a == '-' )
		return true;

	return false;
}


bool is_numeric ( char a )
{
	if ( a >= '0' and a <= '9' or a == '.' or a == '-' )
		return true;

	return false;
}

bool is_numeric ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= '0' and a[i] <= '9' ) or a[i] == '.' or a[i] == '-' ) )
			return false;

	return true;
}

bool is_integer ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( !( ( a[i] >= '0' and a[i] <= '9' ) or a[i] == '-' ) )
			return false;

	return true;
}

bool has_decimals ( string a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == '.' )
			return true;

	return false;
}

bool has_sign ( string a )
{
	if ( a[0] == '-' )
		return true;
	return false;
}


string datatype ( string a )
{
	if ( is_numeric( a ) )
	{
		if ( has_decimals( a ) )
		{
			return "double";
		}
		else
		{
			if ( a.length() <= 9 )
			{	
				if ( a == "1" or a == "0" )
					return "bool";
				else
					return "int";
			}
			else
				return "long";
		}
	}
	else
	{
		if ( a.length() == 1 )
			return "char";
		else
		{
			if ( a == "true" or a == "false" )
				return "bool";
			else
				return "string";
		}
	}

	return "-1";
}


