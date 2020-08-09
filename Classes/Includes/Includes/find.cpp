// #include "lengths.cpp"


int find_int ( int a[], int num )
{
	int i=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			return i;
			break;
		}
		else
			i=i+1;

	return -1;
}

int find_last_int ( int a[], int num )
{
	int size = length(a);

	for ( int i=size-1; i>=0; i=i-1 )
		if ( a[i] == num )
		{	
			return i;
		}

	return -1;	
}

void find_ints ( int a[], int num, int positions[] )
{
	int i=0, r=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			positions[r] = i;
			r=r+1;
			i=i+1;
		}
		else
			i=i+1;
}

void find_ints_greater ( int a[], int num, int greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_ints_greater_or_equal ( int a[], int num, int greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_ints_smaller ( int a[], int num, int smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_ints_smaller_or_equal ( int a[], int num, int smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_ints_partial (int a[], int a1, int a2, int r[])
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);
	
	if ( a2 > size - 1 )
		return;

	int p=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
		{
			r[p] = a[i];
			p=p+1;
		}

}





















int count_ints ( int a[], int num )
{
	int size = length(a);

	int r = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == num )
			r=r+1;

	return r;
}

int count_ints_greater ( int a[], int num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
			r=r+1;

	return r;
}

int count_ints_greater_or_equal ( int a[], int num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
			r=r+1;
	
	return r;
}

int count_ints_smaller ( int a[], int num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
			r=r+1;

	return r;
}

int count_ints_smaller_or_equal ( int a[], int num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
			r=r+1;

	return r;
}

int count_partial ( int a[], int a1, int a2 )
{
	int size = length(a);

	int counter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
			counter = counter + 1;

	return counter;
}









int find ( float a[], float num )
{
	int i=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			return i;
			break;
		}
		else
			i=i+1;

	return -1;
}

int find_last ( float a[], float num )
{
	int size = length(a);

	for ( int i=size-1; i>=0; i=i-1 )
		if ( a[i] == num )
		{	
			return i;
		}

	return -1;	
}

void find ( float a[], float num, int positions[] )
{
	int i=0, r=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			positions[r] = i;
			r=r+1;
			i=i+1;
		}
		else
			i=i+1;
}

void find_greater ( float a[], float num, float greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_greater_or_equal ( float a[], float num, float greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_smaller ( float a[], float num, float smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_smaller_or_equal ( float a[], float num, float smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_partial (float a[], float a1, float a2, float r[])
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);
	
	if ( a2 > size - 1 )
		return;

	int p=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
		{
			r[p] = a[i];
			p=p+1;
		}

}








int find ( double a[], double num )
{
	int i=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			return i;
			break;
		}
		else
			i=i+1;

	return -1;
}

int find_last ( double a[], double num )
{
	int size = length(a);

	for ( int i=size-1; i>=0; i=i-1 )
		if ( a[i] == num )
		{	
			return i;
		}

	return -1;	
}

void find ( double a[], double num, int positions[] )
{
	int i=0, r=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			positions[r] = i;
			r=r+1;
			i=i+1;
		}
		else
			i=i+1;
}

void find_greater ( double a[], double num, double greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_greater_or_equal ( double a[], double num, double greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_smaller ( double a[], double num, double smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_smaller_or_equal ( double a[], double num, double smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_partial (double a[], double a1, double a2, double r[])
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);
	
	if ( a2 > size - 1 )
		return;

	int p=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
		{
			r[p] = a[i];
			p=p+1;
		}

}





















int count ( double a[], double num )
{
	int size = length(a);

	int r = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == num )
			r=r+1;

	return r;
}

int count_greater ( double a[], double num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
			r=r+1;

	return r;
}

int count_greater_or_equal ( double a[], double num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
			r=r+1;
	
	return r;
}

int count_smaller ( double a[], double num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
			r=r+1;

	return r;
}

int count_smaller_or_equal ( double a[], double num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
			r=r+1;

	return r;
}

int count_partial ( double a[], double a1, double a2 )
{
	int size = length(a);

	int counter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
			counter = counter + 1;

	return counter;
}












int find ( char a[], char num )
{
	int i=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			return i;
			break;
		}
		else
			i=i+1;

	return -1;
}

int find_last ( char a[], char num )
{
	int size = length(a);

	for ( int i=size-1; i>=0; i=i-1 )
		if ( a[i] == num )
		{	
			return i;
		}

	return -1;	
}

void find ( char a[], char num, int positions[] )
{
	int i=0, r=0;

	while ( a[i] != '\0' )
		if ( a[i] == num )
		{
			positions[r] = i;
			r=r+1;
			i=i+1;
		}
		else
			i=i+1;
}

void find_greater ( char a[], char num, char greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_greater_or_equal ( char a[], char num, char greater[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
		{
			greater[r] = a[i];
			r=r+1;
		}
}

void find_smaller ( char a[], char num, char smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_smaller_or_equal ( char a[], char num, char smaller[] )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
		{
			smaller[r] = a[i];
			r=r+1;
		}
}

void find_partial (char a[], char a1, char a2, char r[])
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);
	
	if ( a2 > size - 1 )
		return;

	int p=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
		{
			r[p] = a[i];
			p=p+1;
		}

}









int find ( string a[], string num )
{
	int i=0;

	while ( a[i] != "" )
		if ( a[i] == num )
		{
			return i;
			break;
		}
		else
			i=i+1;

	return -1;
}

int find_last ( string a[], string num )
{
	int size = length(a);

	for ( int i=size-1; i>=0; i=i-1 )
		if ( a[i] == num )
		{	
			return i;
		}

	return -1;	
}

void find ( string a[], string num, int positions[] )
{
	int i=0, r=0;

	while ( a[i] != "" )
		if ( a[i] == num )
		{
			positions[r] = i;
			r=r+1;
			i=i+1;
		}
		else
			i=i+1;
}


int count ( string a[], string num )
{
	int size = length(a);

	int r = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == num )
			r=r+1;

	return r;
}












int count ( char a[], char num )
{
	int size = length(a);

	int r = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == num )
			r=r+1;

	return r;
}

int count_greater ( char a[], char num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
			r=r+1;

	return r;
}

int count_greater_or_equal ( char a[], char num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
			r=r+1;
	
	return r;
}

int count_smaller ( char a[], char num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
			r=r+1;

	return r;
}

int count_smaller_or_equal ( char a[], char num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
			r=r+1;

	return r;
}

int count_partial ( char a[], int a1, int a2 )
{
	int size = length(a);

	int counter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
			counter = counter + 1;

	return counter;
}













int count ( float a[], float num )
{
	int size = length(a);

	int r = 0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == num )
			r=r+1;

	return r;
}

int count_greater ( float a[], float num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] > num )
			r=r+1;

	return r;
}

int count_greater_or_equal ( float a[], float num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= num )
			r=r+1;
	
	return r;
}

int count_smaller ( float a[], float num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] < num )
			r=r+1;

	return r;
}

int count_smaller_or_equal ( float a[], float num )
{
	int size = length(a);

	int r=0;
	for ( int i=0; i<size; i=i+1 )
		if ( a[i] <= num )
			r=r+1;

	return r;
}

int count_partial ( float a[], int a1, int a2 )
{
	int size = length(a);

	int counter = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] >= a1 && a[i] <= a2 )
			counter = counter + 1;

	return counter;
}












int last_digit (int a)
{
	return a%10;
}

void find_int_by_last_digit (int a[], int digit, int r[])
{
	int size = length(a);

	int p=0;
	for (int i=0; i<size; i=i+1)
		if ( last_digit(a[i]) == digit )
		{
			r[p] = a[i];
			p=p+1;
		}
}







char frst_char (string a)
{
	return a[0];
}

int find_string_by_frst_char (string a[], char r, string res[]) 
{
	int size = length(a);

	int p=0;
	for (int i=0; i<size; i=i+1)
		if ( frst_char(a[i]) == r )
		{
			res[p] = a[i];
			p=p+1;
		}
}







