// #include "lengths.cpp"


int digit_at ( int num, int pos )
{
	int digits_inverted[1000];
	int num_digits=0;
	while ( num != 0 )
	{
		digits_inverted[ num_digits ] = num % 10;

		num_digits = num_digits + 1;
		num = num / 10;
	}
		
	for ( int i=0; i<num_digits; i=i+1 )
		if ( i == pos )
			return digits_inverted[i];

	return -1;
}

void digits_inverted ( int num, int digits[] )
{
	int num_digits=0;
	while ( num != 0 )
	{
		digits[ num_digits ] = num % 10;

		num_digits = num_digits + 1;
		num = num / 10;
	}
}

int aproximation ( int num, int pos )
{
	int num_digits_inverted[1000];
	int digit = digit_at( num, pos );
	digits_inverted( num, num_digits_inverted );
	int size = length( num );

	int tens = 1;
	for ( int i=0; i<pos; i=i+1 )
		tens = tens * 10;



	int smaller_num;
	int larger_num;

	int digits_num = 0;
	if ( pos + 1 < size )
		for ( int i=size-1; i>=pos+1; i=i-1 )
			digits_num = digits_num * 10 + num_digits_inverted[i];
	digits_num = digits_num * tens * 10;

	if ( digit != 0 )
		smaller_num = digits_num + tens * digit;
	else
		smaller_num = digits_num;

	if ( digit == 9 )
		larger_num = digits_num + tens * 10;
	else
		larger_num = digits_num + tens * ( digit + 1 );



	if ( larger_num - num < num - smaller_num )
		return larger_num;
	else
		return smaller_num;

	return -1;
}

