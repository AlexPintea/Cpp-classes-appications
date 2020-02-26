bool is_same_string ( string a, string b )
{
	if ( a.length() != b.length() )
	{
		cout << a << " with a.length() != " << b << " with b.length()\n";
		return false;
	}

	for ( int i=0; i<a.length(); i=i+1 )
	{
		if ( a[i] != b[i] )
		{
			cout << "\n" << a << " at a[" << i << "] = \'" << a[i] << "\'   !=   " << b << " at b[" << i << "] = " << b[i] << "\n";
			return false;
		}
	}

	return true;
}

int length(char a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

bool is_same_chars ( char char1[], char char2[] )
{
	if ( length( char1 ) != length( char2 ) )
		return false;

	char that[100] = { 't', 'h', 'a', 't' };

	for ( int i=0; i<length( char1 ); i=i+1 )
	{
		if ( ( char1 == that or char2 == that ) and char1[i] != char2[i] )
		{
			cout << "\n" << char1[i] << " != " << char2[i] << "\n";
		}
		if ( char1[i] != char2[i] )
			return false;
	}
	return true;
}

void string_to_chars( string a, char chars[] )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
	{
		if ( a[i] != '\0' )
			chars[i] = a[i];
	}

	cout << "\n" << a << " is now ";
	for ( int i=0; i<size; i=i+1 )
	{
		cout << "\'" << chars[i] << "\' ";
	}
	cout << "\n";
}

