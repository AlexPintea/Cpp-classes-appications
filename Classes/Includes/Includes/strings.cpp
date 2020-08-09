bool even ( string a )
{
	int size = a.length();

	if ( a[ size - 1 ] == '0' ) return 1;
	if ( a[ size - 1 ] == '2' ) return 1;
	if ( a[ size - 1 ] == '4' ) return 1;
	if ( a[ size - 1 ] == '6' ) return 1;
	if ( a[ size - 1 ] == '8' ) return 1;
	return 0;
}

bool odd ( string a )
{
	if ( ! even( a ) ) return 1;
	return 0;
}

bool pos ( string a )
{
	if ( a[ 0 ] != '-' ) return 1;
	return 0;
}

bool neg ( string a )
{
	if ( a[ 0 ] != '-' ) return 0;
	return 1;
}

char sub ( char a, char b )
{
	int a_int = (int) ( a - 48 ); 
	int b_int = (int) ( b - 48 );
	if ( a_int < b_int ) a_int = a_int + 10;
	int d = ( a_int - b_int ) % 10;

	if ( d < 0 )
		d = -d;

	return (char) ( d + 48 );
}


char add ( char a, char b )
{
	int a_int = (int) ( a - 48 ); 
	int b_int = (int) ( b - 48 );

	return (char) ( ( a_int + b_int ) % 10 + 48 );
}

bool have_double ( string a )
{
	for ( int l = 1; l < a.length(); l = l + 1 )
		if ( a[ l ] == '.' ) return 1;

	return 0; 	
}

void get_double ( string &num, string &decimals )
{
	if ( ! have_double( num ) )
		return;
	int l;
	string num_int = "";
	decimals = "";
	for ( int i = 0; i < num.length(); i = i + 1 )
	{
		if ( num[ i ] == '.' )
		{
			l = i;
			break;
		}

		num_int = num_int + num[ i ];
	}

	for ( int i = l + 1; i < num.length(); i = i + 1 )
		decimals = decimals + num[ i ];

	num = num_int;
}

void remove_sign ( string &a )
{
//	if ( a[ 0 ] != '-' )
//		return;

	string result = "";
	for ( int l = 1; l < a.length(); l = l + 1 )
		result = result + a[ l ];

	a = result;
}


bool is_decimal_int ( string a ) 
{
	for ( int l = 0; l < a.length(); l = l + 1 )
		if ( a[ l ] != '0' )
			return 0;
	return 1;
}

void remove_decimals ( string &a )
{
	string result = "";
	int i = 0;
	for ( int l = a.length() - 1; l >= 0; l = l - 1 )
	{
		if ( a[ l ] != '0' )
		{
			i = l;
			break;
		}
	}

	for ( int l = i; l >= 0; l = l - 1 )
		result = result + a[ l ];

	a = invert_string( result );
}


bool larger_num ( string a, string b )
{
	int size_a = a.length();
	int size_b = b.length();

	if ( neg( a ) and ! neg( b ) )
		return 0;

	if ( ! neg( a ) and neg( b ) )
		return 1;

	if ( neg( a ) and neg( b ) )
	{
		if ( size_a > size_b )
			return 0;

		if ( size_a == size_b )
		{
			for ( int l = 0; l < size_a; l = l + 1 )
				if ( a[ l ] < b[ l ] )
					return 1;
			return 0;
		}
	}
	else
	{
		if ( size_a > size_b )
			return 1;

		if ( size_a == size_b )
		{
			for ( int l = 0; l < size_a; l = l + 1 )
				if ( a[ l ] < b[ l ] )
					return 0;
			return 1;
		}
	}

	return 0;
}


string add ( string a, string b );


string sub ( string a, string b )
{
	if ( have_double( a ) and have_double( b ) )
	{
		string decimals_a;
		string decimals_b;
		get_double( a, decimals_a );
		get_double( b, decimals_b );
		if ( decimals_a.length() > decimals_b.length() )
			for ( int l = decimals_b.length(); l < decimals_a.length(); l = l + 1 )
				decimals_b = decimals_b + '0';
		if ( decimals_b.length() > decimals_a.length() )
			for ( int l = decimals_a.length(); l < decimals_b.length(); l = l + 1 )
				decimals_a = decimals_a + '0';
		string sum = sub( a, b );
		string decimals_sum = sub( decimals_a, decimals_b );
		remove_decimals( decimals_sum );

		if ( decimals_sum.length() > decimals_a.length() )
		{
			remove_sign( decimals_sum );
			sum = add( sum, "1" );
		}
	
		if ( is_decimal_int( decimals_sum ) or ! is_numeric( decimals_sum ) )
			return sum;
		else
			return sum + '.' + decimals_sum;
	}

	if ( have_double( a ) and ! have_double( b ) )
	{
		string decimals_a;
		get_double( a, decimals_a );
		return sub( a, b ) + '.' + decimals_a;
	}

	if ( ! have_double( a ) and have_double( b ) )
	{
		string decimals_b;
		get_double( b, decimals_b );
		return sub( a, b ) + '.' + decimals_b;
	}

	if ( neg( a ) and ! neg( b ) )
	{
		remove_sign( a );
		return '-' + add( a, b );
	}

	if ( ! neg( a ) and neg( b ) )
	{
		remove_sign( b );
		return add( a, b );
	}

	if ( neg( a ) and neg( b ) )
	{
		remove_sign( a );
		remove_sign( b );
		return '-' + add( a, b );
	}

	string result = "";
	if ( ! larger_num( a, b ) )
	{
		string temp = a;
		a = b;
		b = temp;
		result = "-";
	}

	a = invert_string( a );
	b = invert_string( b );

	int nums[ 90 ];
	int nums_iter = 0;

	int size_a = a.length();
	int size_b = b.length();

	int a_int;
	int b_int;

	int sum;
	bool have_reminder = 0;
	bool reminder = 0;
	for ( int l = 0; l < size_b; l = l + 1 )
	{
		a_int = (int) ( a[ l ] - 48 );
		b_int = (int) ( b[ l ] - 48 );
		reminder = 1;
		if ( a_int < b_int )
		{
			if ( l != size_a - 1 )
			{
				sum = ( a_int + 10 - b_int ) % 10;
				have_reminder = 1;
				reminder = 0;
			}
			else
			{
				sum = b_int - a_int;
				have_reminder = 1;
				reminder = 0;
			}
		}
		else
			sum = a_int - b_int;

		if ( have_reminder and reminder )
		{
			sum = sum - 1;
			have_reminder = 0;
		}

		if ( sum < 0 )
		{
			sum = -sum;
			have_reminder = 1;
		}

		sum = sum % 10;

		nums[ nums_iter ] = sum;
		nums_iter = nums_iter + 1;
	}
	for ( int l = size_b; l < size_a; l = l + 1 )
	{
		a_int = (int) ( a[ l ] - 48 );
		sum = a_int;
		if ( have_reminder )
		{
			sum = sum - 1;
			if ( sum == 0 )
				sum = 9;
			else
				have_reminder = 0;
		}

		sum = sum % 10;

		nums[ nums_iter ] = sum;
		nums_iter = nums_iter + 1;
	}



	if ( have_reminder )
	{
		nums[ nums_iter - 1 ] = sub( a[ size_a - 1 ], '1' );
		if ( nums[ nums_iter - 1 ] == '0' )
			nums_iter = nums_iter - 1;
		have_reminder = 0;
	}
	
	int num_iter = nums_iter - 1;
	while ( nums[ num_iter ] == 0 )
		num_iter = num_iter - 1;
	for ( int l = num_iter; l >= 0; l = l - 1 )
		result = result + (char) ( nums[ l ] + 48 );

	return result;
}





string add ( string a, string b )
{
	if ( have_double( a ) and have_double( b ) )
	{
		string decimals_a;
		string decimals_b;
		get_double( a, decimals_a );
		get_double( b, decimals_b );
		if ( decimals_a.length() > decimals_b.length() )
			for ( int l = decimals_b.length(); l < decimals_a.length(); l = l + 1 )
				decimals_b = decimals_b + '0';
		if ( decimals_b.length() > decimals_a.length() )
			for ( int l = decimals_a.length(); l < decimals_b.length(); l = l + 1 )
				decimals_a = decimals_a + '0';
		string sum = add( a, b );
		string decimals_sum = add( decimals_a, decimals_b );
		remove_decimals( decimals_sum );

		if ( decimals_sum.length() > decimals_a.length() )
		{
			remove_sign( decimals_sum );
			sum = add( sum, "1" );
		}
		if ( is_decimal_int( decimals_sum ) or ! is_numeric( decimals_sum ) )
			return sum;
		else
			return sum + '.' + decimals_sum;
	}

	if ( have_double( a ) and ! have_double( b ) )
	{
		string decimals_a;
		get_double( a, decimals_a );
		return add( a, b ) + '.' + decimals_a;
	}

	if ( ! have_double( a ) and have_double( b ) )
	{
		string decimals_b;
		get_double( b, decimals_b );
		return add( a, b ) + '.' + decimals_b;
	}

	if ( neg( a ) and ! neg( b ) )
	{
		remove_sign( a );
		return sub( b, a );
	}

	if ( ! neg( a ) and neg( b ) )
	{
		remove_sign( b );
		return sub( a, b );
	}

	if ( neg( a ) and neg( b ) )
	{
		remove_sign( a );
		remove_sign( b );
		return '-' + add( a, b );
	}

	string a_string;
	a = invert_string( a );
	b = invert_string( b );

	if ( a.length() < b.length() )
	{
		string temp = a;
		a = b;
		b = temp;
	}

	int nums[ 90 ];
	int nums_iter = 0;

	int size_a = a.length();
	int size_b = b.length();

	int a_int;
	int b_int;

	int sum;
	bool have_reminder = 0;

	for ( int l = 0; l < size_b; l = l + 1 )
	{
		a_int = (int) ( a[ l ] - 48 ); 
		b_int = (int) ( b[ l ] - 48 );

		sum = a_int + b_int;

		if ( have_reminder )
		{
			sum = sum + 1;
			have_reminder = 0;
		}

		if ( sum >= 10 )
			have_reminder = 1;

		sum = sum % 10;

		nums[ nums_iter ] = sum;
		nums_iter = nums_iter + 1;
	}
	for ( int l = size_b; l < size_a; l = l + 1 )
	{
		a_int = (int) ( a[ l ] - 48 );
		sum = a_int;
		if ( have_reminder )
		{
			sum = sum + 1;
			have_reminder = 0;
		}

		if ( sum >= 10 )
			have_reminder = 1;

		sum = sum % 10;

		nums[ nums_iter ] = sum;
		nums_iter = nums_iter + 1;
	}

	if ( have_reminder )
	{
		nums[ nums_iter ] = 1;
		nums_iter = nums_iter + 1;		
		have_reminder = 0;
	}

	string result = "";
	for ( int l = nums_iter - 1; l >= 0; l = l - 1 )
		result = result + (char) ( nums[ l ] + 48 );

	return result;
}


