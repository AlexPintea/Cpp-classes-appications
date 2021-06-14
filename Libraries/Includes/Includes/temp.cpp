string temp_1[ 10000 ];
string temp_2[ 10000 ];
int temp_iter = 0;

string lower_temp ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] >= 'A' and a[ i ] <= 'Z' )
			a[ i ] = a[ i ] - 32;
	return a;
}

int is_temp ( string a )
{
	for ( int i = 0; i < temp_iter; i = i + 1 )
		if ( lower_temp( temp_1[ i ] ) == lower_temp( a ) )
			return i;
	return -1;
}

void temp ( string a, string b )
{
	int l = is_temp( a );
	if ( l != -1 )
	{
		temp_2[ l ] = lower_temp( b );
		return;
	}

	temp_1[ temp_iter ] = lower_temp( a );
	temp_2[ temp_iter ] = lower_temp( b );
	temp_iter = temp_iter + 1;
}

void temp ( string a, long b )
{

	int l = is_temp( a );
	if ( l != -1 )
	{
		temp_2[ l ] = long_to_string( b );
		return;
	}


	temp_1[ temp_iter ] = a;
	temp_2[ temp_iter ] = long_to_string( b );
	temp_iter = temp_iter + 1;
}

void temp ( string a, int b )
{
	int l = is_temp( a );
	if ( l != -1 )
	{
		temp_2[ l ] = int_to_string( b );
		return;
	}

	temp_1[ temp_iter ] = a;
	temp_2[ temp_iter ] = int_to_string( b );
	temp_iter = temp_iter + 1;
}

// for bool: always takes bool

void temp ( string a, double b )
{
	int l = is_temp( a );
	if ( l != -1 )
	{
		temp_2[ l ] = double_to_string( b );
		return;
	}

	temp_1[ temp_iter ] = a;
	temp_2[ temp_iter ] = double_to_string( b );
	temp_iter = temp_iter + 1;
}

void temp ( string a, float b )
{
	int l = is_temp( a );
	if ( l != -1 )
	{
		temp_2[ l ] = float_to_string( b );
		return;
	}

	temp_1[ temp_iter ] = a;
	temp_2[ temp_iter ] = float_to_string( b );
	temp_iter = temp_iter + 1;
}

void temp ( string a, char b )
{
	int l = is_temp( a );
	if ( l != -1 )
	{
		temp_2[ l ] = char_to_string( b );
		return;
	}

	temp_1[ temp_iter ] = a;
	temp_2[ temp_iter ] = char_to_string( b );
	temp_iter = temp_iter + 1;
}

string temp ( string a )
{
	for ( int i = 0; i < temp_iter; i = i + 1 )
		if ( lower_temp( temp_1[ i ] ) == lower_temp( a ) )
			return temp_2[ i ];
	return "";
}
