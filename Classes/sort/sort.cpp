#include <string.h>
#include <iostream>
#include <string>

using namespace std;

// clear && g++ -o "Sort class" "Sort class.cpp" && ./"Sort class"

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

int length(long a[])
{
	int i=0;

	while ( a[i] != '\0' )
	{
		i=i+1;
	}

	return i;
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



void swap (int &a, int &b)
{
	int aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (long &a, long &b)
{
	long aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (float &a, float &b)
{
	float aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (double &a, double &b)
{
	double aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (bool &a, bool &b)
{
	bool aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (char &a, char &b)
{
	char aux;

	aux = a;
	a = b;
	b = aux;
}

void swap (string &a, string &b)
{
	string aux;

	aux = a;
	a = b;
	b = aux;
}


void sort (int a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (int a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort (long a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (long a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}


void sort (float a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (float a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort (double a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (double a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort (bool a[]) // does not return validly due to void length( bool a )
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (bool a[]) // does not return validly due to void length( bool a )
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort (char a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (char a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort (string &a)
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (string &a) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort (string a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] > a[k] )
				{
					swap(a[i], a[k]);
				}
}

void sort_invert (string a[]) 
{
	int size = length (a);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
			if ( a[i] < a[k] )
				{
					swap(a[i], a[k]);
				}
}

void invert (int a[])
{
	int size = length(a);

	int invert[10000]; // does not want invert[ length(a) + 1 ]; - Segm. Fault

	for (int i=0; i<size; i=i+1)
		invert[ size - i - 1 ] = a[i];

	for (int i=0; i<size; i=i+1)
		a[i] = invert[i];
}

void invert (long a[])
{
	int size = length(a);

	long invert[10000]; // does not want invert[ length(a) + 1 ]; - Segm. Fault

	for (int i=0; i<size; i=i+1)
		invert[ size - i - 1 ] = a[i];

	for (int i=0; i<size; i=i+1)
		a[i] = invert[i];
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

void initialise (int a[], int init)
{
	int size = length(a);

	for (int i=0; i<size; i=i+1)
		a[i] = init;
}

void initialise (float a[], float init)
{
	int size = length(a);

	for (int i=0; i<size; i=i+1)
		a[i] = init;
}

void initialise (double a[], double init)
{
	double size = length(a);

	for (int i=0; i<size; i=i+1)
		a[i] = init;
}

void initialise (char a[], char init)
{
	char size = length(a);

	for (int i=0; i<size; i=i+1)
		a[i] = init;
}

int appears (int a[], int item) 
{
	int size = length(a);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
	{
		if ( a[i] == item )
			counter = counter + 1;
	}

	return counter;
}

int appears (float a[], float item) 
{
	int size = length(a);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
	{
		if ( a[i] == item )
			counter = counter + 1;
	}

	return counter;
}

int appears (double a[], double item) 
{
	int size = length(a);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
	{
		if ( a[i] == item )
			counter = counter + 1;
	}

	return counter;
}

int appears (char a[], char item) 
{
	int size = length(a);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
	{
		if ( a[i] == item )
			counter = counter + 1;
	}

	return counter;
}

int appears (string a, char item) 
{
	int size = length(a);
	int counter = 0;

	for (int i=0; i<size; i=i+1)
	{
		if ( a[i] == item )
			counter = counter + 1;
	}

	return counter;
}

void sort_by_freq (int a[]) 
{
	int size = length(a);
	int freq[ size + 1 ];

	initialise(freq, 0);

	for (int i=0; i<size; i=i+1)
		freq[i] = appears(a, a[i]);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{
			if ( freq[i] == freq [k] && a[i] > a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( freq[i] > freq[k] )
			{
				swap(freq[i], freq[k]);
				swap(a[i], a[k]);
			}
		}
}


void sort_by_freq_invert (int a[]) 
{
	sort_by_freq(a);

	invert(a);
}


void sort_by_freq (float a[]) 
{
	int size = length(a);
	int freq[ size + 1 ];

	initialise(freq, 0);

	for (int i=0; i<size; i=i+1)
		freq[i] = appears(a, a[i]);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{			
			if ( freq[i] == freq [k] && a[i] > a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( freq[i] > freq[k] )			
			{
				swap(freq[i], freq[k]);
				swap(a[i], a[k]);
			}

		}

}

void sort_by_freq_invert (float a[]) 
{
	sort_by_freq(a);

	invert(a);
}

void sort_by_freq (double a[]) 
{
	int size = length(a);
	int freq[ size + 1 ];

	initialise(freq, 0);

	for (int i=0; i<size; i=i+1)
		freq[i] = appears(a, a[i]);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{			
			if ( freq[i] == freq [k] && a[i] > a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( freq[i] > freq[k] )			
			{
				swap(freq[i], freq[k]);
				swap(a[i], a[k]);
			}

		}

}

void sort_by_freq_invert (double a[]) 
{
	sort_by_freq(a);

	invert(a);
}



void sort_by_freq (char a[]) 
{
	int size = length(a);
	int freq[ size + 1 ];

	initialise(freq, 0);

	for (int i=0; i<size; i=i+1)
		freq[i] = appears(a, a[i]);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{			
			if ( freq[i] == freq [k] && a[i] > a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( freq[i] > freq[k] )			
			{
				swap(freq[i], freq[k]);
				swap(a[i], a[k]);
			}

		}
}

void sort_by_freq_invert (char a[]) 
{
	sort_by_freq(a);

	invert(a);
}

void sort_by_freq (string &a) 
{
	int size = length(a);
	int freq[ size + 1 ];

	initialise(freq, 0);

	for (int i=0; i<size; i=i+1)
		freq[i] = appears(a, a[i]);

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{			
			if ( freq[i] == freq [k] && a[i] > a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( freq[i] > freq[k] )			
			{
				swap(freq[i], freq[k]);
				swap(a[i], a[k]);
			}

		}
}

void sort_by_freq_invert (string &a) 
{
	sort_by_freq(a);

	invert(a);
}


void sort_by_size (string a[])
{
	int size = length(a);

	int words[ size + 1 ];

	for (int i=0; i<size; i=i+1)
		words[i] = a[i].length();

	for (int i=0; i<size; i=i+1)
		cout << words[i] << " ";
	cout << endl;

	for (int i=0; i<size-1; i=i+1)
		for (int k=i+1; k<size; k=k+1)
		{			
			if ( words[i] == words[k] && a[i] > a[k] )
			{
				swap(a[i], a[k]);
				continue;
			}

			if ( words[i] > words[k] )			
			{
				swap(words[i], words[k]);
				swap(a[i], a[k]);
			}
		}
}


void sort_by_size_invert (string a[])
{
	sort_by_size(a);

	invert(a);
}

void sort_partial (int a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] > a[k] )
			{
				swap(a[i], a[k]);
			}
}

void sort_partial_invert (int a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] < a[k] )
			{
				swap(a[i], a[k]);
			}
}



void sort_partial (float a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] > a[k] )
			{
				swap(a[i], a[k]);
			}
}

void sort_partial_invert (float a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] < a[k] )
			{
				swap(a[i], a[k]);
			}
}

void sort_partial (double a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] > a[k] )
			{
				swap(a[i], a[k]);
			}
}

void sort_partial_invert (double a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] < a[k] )
			{
				swap(a[i], a[k]);
			}
}

void sort_partial (char a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] > a[k] )
			{
				swap(a[i], a[k]);
			}
}

void sort_partial_invert (char a[], int a1, int a2) 
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;

	for (int i=a1; i<a2; i=i+1)
		for (int k=i+1; k<=a2; k=k+1)
			if ( a[i] < a[k] )
			{
				swap(a[i], a[k]);
			}
}




void partial_invert (int a[], int a1, int a2)
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;


	int b[ a2 - a1 + 1 ];

	int l = a2 - a1;

	for (int i=a1; i<=a2; i=i+1)
	{	
		b[l] = a[i];
		l=l-1;
	}

	l=0;
	for (int i=a1; i<=a2; i=i+1)
	{	
		a[i] = b[l];
		l=l+1;
	}
}


void partial_invert (float a[], int a1, int a2)
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;


	float b[ a2 - a1 + 1 ];

	int l = a2 - a1;

	for (int i=a1; i<=a2; i=i+1)
	{	
		b[l] = a[i];
		l=l-1;
	}

	l=0;
	for (int i=a1; i<=a2; i=i+1)
	{	
		a[i] = b[l];
		l=l+1;
	}
}


void partial_invert (double a[], int a1, int a2)
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;


	double b[ a2 - a1 + 1 ];

	int l = a2 - a1;

	for (int i=a1; i<=a2; i=i+1)
	{	
		b[l] = a[i];
		l=l-1;
	}

	l=0;
	for (int i=a1; i<=a2; i=i+1)
	{	
		a[i] = b[l];
		l=l+1;
	}
}


void partial_invert (char a[], int a1, int a2)
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;


	char b[ a2 - a1 + 1 ];

	int l = a2 - a1;

	for (int i=a1; i<=a2; i=i+1)
	{	
		b[l] = a[i];
		l=l-1;
	}

	l=0;
	for (int i=a1; i<=a2; i=i+1)
	{	
		a[i] = b[l];
		l=l+1;
	}
}


void partial_invert (string a[], int a1, int a2)
{
	if ( a1 < 0 or a2 < 0 )
		return;

	int size = length (a);

	if ( a2 > size - 1 )
		return;


	string b[ a2 - a1 + 1 ];

	int l = a2 - a1;

	for (int i=a1; i<=a2; i=i+1)
	{	
		b[l] = a[i];
		l=l-1;
	}

	l=0;
	for (int i=a1; i<=a2; i=i+1)
	{	
		a[i] = b[l];
		l=l+1;
	}
}



void count_data (char a[], int &numeric_counter, int &writing_counter, int &sign_counter)
{
	int size = length(a);

	numeric_counter = 0;
	for (int i=0; i<size; i=i+1)
		if ( a[i] >= '1' && a[i] <= '9' )
			numeric_counter = numeric_counter+1;

	writing_counter = 0;
	for (int i=0; i<size; i=i+1)
		if ( (a[i] >= 'a' && a[i] <= 'z') or (a[i] >= 'A' && a[i] <= 'Z') )
			writing_counter = writing_counter+1;

	sign_counter = 0;
	for (int i=0; i<size; i=i+1)
		if ( (a[i] >= ' ' && a[i] <= '/') or (a[i] >= ':' && a[i] <= 64) or (a[i] >= '[' && a[i] <= 96) or (a[i] >= '{' && a[i] <= 126) )
			sign_counter = sign_counter+1;

}


void sort_by_data (char a[], int numeric[],  char writing[], char signs[] )
{
	int size = length(a);

	int r=0;
	for (int i=0; i<size; i=i+1)
		if ( a[i] >= '1' && a[i] <= '9' )
		{
			numeric[r] = a[i] - 48;
			r=r+1;
		}

	r=0;
	for (int i=0; i<size; i=i+1)
		if ( (a[i] >= 'a' && a[i] <= 'z') or (a[i] >= 'A' && a[i] <= 'Z') )
		{
			writing[r] = a[i];
			r=r+1;
		}

	r=0;
	for (int i=0; i<size; i=i+1)
		if ( (a[i] >= ' ' && a[i] <= '/') or (a[i] >= ':' && a[i] <= 64) or (a[i] >= '[' && a[i] <= 96) or (a[i] >= '{' && a[i] <= 126) )
		{
			signs[r] = a[i];
			r=r+1;
		}

}

void merge_sort (int a[])
{

}

void quick_sort (int a[]) 
{

}


int main()
{

	cout << "\ncompiles\n";

	return 0;
}

