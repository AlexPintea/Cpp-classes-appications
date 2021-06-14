
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

int length(int a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(long a)
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

int length(long a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length ( float a )
{
	if ( a == 0 ) return 1;

	long a_int = length( (long) a );
	double decimals = a - a_int;

	if ( decimals == 0 )
		return length( (long) a );

	long a_decimals = 0;
	while ( a - (long) a != 0 )
	{
		a_decimals = a_decimals + 1;
		a = a * 10;
	}
	return a_int + a_decimals;
}


int length_size ( float a )
{
	if ( a == 0 ) return 1;

	long a_int = length( (long) a );
	double decimals = a - a_int;

	if ( decimals == 0 )
		return length( (long) a );

	long a_decimals = 0;
	while ( (float) a - (long) a != 0 )
	{
		a_decimals = a_decimals + 1;
		a = a * 10;
	}

	if ( a > 0 )
		return a_int + a_decimals + 1;
	else
		return a_int + a_decimals + 2;
}

int length(float a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length ( double a )
{
	if ( a == 0 ) return 1;

	long a_int = length( (long) a );
	double decimals = a - a_int;

	if ( decimals == 0 )
		return length( (long) a );

	long a_decimals = 0;
	while ( (float) a - (long) a != 0 )
	{
		a_decimals = a_decimals + 1;
		a = a * 10;
	}
	return a_int + a_decimals;
}



int length_size ( double a )
{
	if ( a == 0 ) return 1;

	long a_int = length( (long) a );
	double decimals = a - a_int;


	if ( decimals == 0 )
		return length( (long) a );

	long a_decimals = 0;
	while ( (float) a - (long) a != 0 )
	{
		a_decimals = a_decimals + 1;
		a = a * 10;
	}

	if ( a > 0 )
		return a_int + a_decimals + 1;
	else
		return a_int + a_decimals + 1;		
}

int length(double a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length(bool a[])  // does not return validly
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
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

int length (string a)
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
}

int length ( string a[] )
{

	int i=0;

	while ( a[i].length() > 0 )
	{
		i=i+1;
	}

	return i;
}




