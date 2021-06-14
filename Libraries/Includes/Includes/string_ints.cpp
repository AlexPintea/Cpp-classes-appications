

string digit_string ( int a )
{
	if ( a == 0 )
		return "zero";
	if ( a == 1 )
		return "one";
	if ( a == 2 )
		return "two";
	if ( a == 3 )
		return "three";
	if ( a == 4 )
		return "four";
	if ( a == 5 )
		return "five";
	if ( a == 6 )
		return "six";
	if ( a == 7 )
		return "seven";
	if ( a == 8 )
		return "eight";
	if ( a == 9 )
		return "nine";

	return "-1";
}

string int_string ( int a )
{
	int digits[10];

	int num_digits=0;
	while ( a != 0 )
	{
		digits[ num_digits ] = a % 10;
		a = a / 10;
		num_digits = num_digits + 1;
	}

	string result = "";
	for ( int i=num_digits - 1; i>=0; i=i-1 )
		result = result + digit_string( digits[i] ) + ' ';

	return result;
}

