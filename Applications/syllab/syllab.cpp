#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;



bool is_vowel ( char a )
{
	if ( a == 'a' or a == 'e' or a == 'i' or a == 'y' or a == 'u' or a == 'o' )
		return 1;
	if ( a == 'A' or a == 'E' or a == 'I' or a == 'Y' or a == 'U' or a == 'O' )
		return 1;
	return 0;
}



string get_syllabs ( string a )
{
	string result = "";
	int size = a.length();


	if ( size <= 5 )
		return a;

	bool have_vowel = 0;

	for ( int i = 0; i < size; i = i + 1 )
	{
		if ( is_vowel( a[ i ] ) )
			have_vowel = 1;

		result = result + a[ i ];

		if ( ! is_vowel( a[ i ] ) and have_vowel and i != size - 1 )
		{
			result = result + '-';
			have_vowel = 0;
		}
	}

	return result;
}



int main ()
{
	cout << "String: ";
	string a;

	cin >> a;

	cout << get_syllabs( a ) << '\n';

	return 0;
}
