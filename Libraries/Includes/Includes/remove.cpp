void get_common ( string a[], string common_filename )
{
	ifstream fi;

	fi.open( common_filename );
	int l = 0;

	string temp;
	while ( fi >> temp )
	{
		a[ l ] = temp;
		l = l + 1;
	}

	fi.close();
}
string upper_common ( string a ) // - used
{
	if ( a[ 0 ] >= 'a' and a[ 0 ] <= 'z' )
		a[ 0 ] = a[ 0 ] - 32;

	return a;
}

















string pref[] = { "in", "un", "ir" };

string remove_pref_common ( string a )
{
	int size_pref = length( pref );
	bool have_pref = 0;
	for ( int i = 0; i < size_pref; i = i + 1 )
	{
		have_pref = 1;
		for ( int l = 0; l < pref[ i ].length(); l = l + 1 )
		{
			string pref_string =  pref[ i ];
			if ( pref_string[ l ] != a[ l ] )
			{
				have_pref = 0;
				break;
			}
		}

		if ( have_pref == 1 )
		{
			if ( a == pref[ i ] )
				return a;

			string result = "";

			for ( int l = pref[ i ].length(); l < a.length(); l = l + 1 )
				result = result + a[ l ];

			return result;
		}
	}

	return a;
}



string remove_plural_common ( string a )
{
	string result = "";

	if ( a[ a.length() - 1 ] == 's' and a[ a.length() - 2 ] == 'e' )
	{
		for ( int i = 0; i < a.length() - 2; i = i + 1 )
			result = result + a[ i ];

		return result;
	}

	if ( a[ a.length() - 1 ] == 's' )
	{
		for ( int i = 0; i < a.length() - 1; i = i + 1 )
			result = result + a[ i ];

		return result;
	}

	return a;
}

void remove_chars_common ( string &a )
{
	string result = "";
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'a' and a[ i ] <= 'z' )
			result = result + a[ i ];

	a = result;
}

void lower_common ( string &a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'A' and a[ 0 ] <= 'Z' )
			a[ i ] = a[ i ] + 32;
}

bool is_common ( string a, string common_filename )
{
	lower_common( a );
	remove_chars_common( a );

	string common[ 10000 ];
	get_common( common, common_filename );

	int size = length( common );

	for ( int i = 0; i < size; i = i + 1 )
		if ( common[ i ] == a or common[ i ] == remove_pref_common( a ) or common[ i ] == remove_plural_common( a ) )
			return 1;
	return 0;
}

void get_remove_common ( string strings[], string a, string common_filename )
{
	string words[ 10000 ];

	move_words( a, words );

	int size = length( words );
	int strings_iter = 0;


	for ( int i = 0; i < size; i = i + 1 )
		if ( ! is_common( words[ i ], common_filename ) )
		{
			strings[ strings_iter ] = words[ i ];
			strings_iter = strings_iter + 1;
		}
}

void get_remove_common ( string strings[], string filename, string common_filename, bool file )
{
	if ( file == 1 )
	{
		get_remove_common( strings, filename, common_filename );
		return;
	}
	
	int strings_iter = 0;

	ifstream fi;
	fi.open( filename );

	string temp;
	while ( fi >> temp )
		if ( ! is_common( temp, common_filename ) )
		{
			strings[ strings_iter ] = temp;
			strings_iter = strings_iter + 1;
		}

	fi.close();
}

void remove_common ( string strings[], string common_filename )
{
	int size = length( strings );

	string result[ 10000 ];
	int result_iter = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( ! is_common( strings[ i ], common_filename ) )
		{
			result[ result_iter ] = strings[ i ];
			result_iter = result_iter + 1;
		}

	empty( strings );

	for ( int i = 0; i < result_iter; i = i + 1 )
		strings[ i ] = result[ i ];
}

void get_leave_common ( string strings[], string a, string common_filename )
{
	string words[ 10000 ];

	move_words( a, words );

	int size = length( words );
	int strings_iter = 0;


	for ( int i = 0; i < size; i = i + 1 )
		if ( is_common( words[ i ], common_filename ) )
		{
			strings[ strings_iter ] = words[ i ];
			strings_iter = strings_iter + 1;
		}
}

void get_leave_common ( string strings[], string filename, string common_filename, bool file )
{
	if ( file == 1 )
	{
		get_remove_common( strings, filename, common_filename );
		return;
	}

	int strings_iter = 0;

	ifstream fi;
	fi.open( filename );

	string temp;
	while ( fi >> temp )
		if ( is_common( temp, common_filename ) )
		{
			strings[ strings_iter ] = temp;
			strings_iter = strings_iter + 1;
		}

	fi.close();
}

void leave_common ( string strings[], string common_filename )
{
	int size = length( strings );

	string result[ 10000 ];
	int result_iter = 0;

	for ( int i = 0; i < size; i = i + 1 )
		if ( is_common( strings[ i ], common_filename ) )
		{
			result[ result_iter ] = strings[ i ];
			result_iter = result_iter + 1;
		}

	empty( strings );

	for ( int i = 0; i < result_iter; i = i + 1 )
		strings[ i ] = result[ i ];
}
