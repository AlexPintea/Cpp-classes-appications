// #include "lengths.cpp"



// maximum




int max ( int a, int b )
{
	if ( a > b )
		return a;

	return b;
}

long max ( long a, long b )
{
	if ( a > b )
		return a;

	return b;
}

float max ( float a, float b )
{
	if ( a > b )
		return a;

	return b;
}

double max ( double a, double b )
{
	if ( a > b )
		return a;

	return b;
}

bool max ( bool a, bool b )
{
	if ( a > b )
		return a;

	return b;
}

char max ( char a, char b )
{
	if ( a > b )
		return a;

	return b;
}

string max ( string a, string b )
{
	if ( a > b )
		return a;

	return b;
}



// maximum[] length



bool max_length ( int a[], int b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool max_length ( long a[], long b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool max_length ( float a[], float b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool max_length ( double a[], double b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool max_length ( bool a[], bool b[] ) // does not return validly, due to  int length( bool a[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool max_length ( char a[], bool b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}

bool max_length ( string a[], string b[] )
{
	if ( length(a) > length(b) )
		return 1;

	return 0;
}



// minimum




int min ( int a, int b )
{
	if ( a < b )
		return a;

	return b;
}

long min ( long a, long b )
{
	if ( a < b )
		return a;

	return b;
}

float min ( float a, float b )
{
	if ( a < b )
		return a;

	return b;
}

double min ( double a, double b )
{
	if ( a < b )
		return a;

	return b;
}

bool min ( bool a, bool b )
{
	if ( a < b )
		return a;

	return b;
}

char min ( char a, char b )
{
	if ( a < b )
		return a;

	return b;
}

string min ( string a, string b )
{
	if ( a < b )
		return a;

	return b;
}



// minimum[]



bool min_length ( int a[], int b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool min_length ( long a[], long b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool min_length ( float a[], float b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool min_length ( double a[], double b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool min_length ( bool a[], bool b[] ) // does not return validly, due to  int length( bool a[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool min_length ( char a[], bool b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}

bool min_length ( string a[], string b[] )
{
	if ( length(a) < length(b) )
		return 1;

	return 0;
}






// maximum and minimum []




int max (int a[])
{

	int max = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

float max (float a[])
{

	float max = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

double max (double a[])
{

	double max = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

char max (char a[])
{

	char max = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

char max (string a)
{

	char max = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] < max)
			max = a[i];

	return max;
}


int min (int a[])
{

	int min = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

float min (float a[])
{

	float min = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

double min (double a[])
{

	double min = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

char min (char a[])
{

	char min = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

char min (string a)
{

	char min = a[0];
	int size = length(a);
	
	for (int i=1; i<size; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}




int max_partial (int a[], int a1, int a2)
{
	char max = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

float max_partial (float a[], int a1, int a2)
{
	char max = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

double max_partial (double a[], int a1, int a2)
{
	char max = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

char max_partial (char a[], int a1, int a2)
{
	char max = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}

char max_partial (string a, int a1, int a2)
{
	char max = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] > max)
			max = a[i];

	return max;
}






int min_partial (int a[], int a1, int a2)
{
	char min = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

float min_partial (float a[], int a1, int a2)
{
	char min = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

double min_partial (double a[], int a1, int a2)
{
	char min = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

char min_partial (char a[], int a1, int a2)
{
	char min = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}

char min_partial (string a, int a1, int a2)
{
	char min = a[0];
	int size = length(a);
	
	for (int i=a1; i<=a2; i=i+1)
		if (a[i] < min)
			min = a[i];

	return min;
}



