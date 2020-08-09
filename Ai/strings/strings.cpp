#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


int length ( string a[] )
{

	int i = 0;

	while ( a[ i ].length() > 0 )
		i = i + 1;
	return i;
}



string strings[] = { "a_string", "b_string", "c_string", "i_string", "l_string", "m_string", "p_string", "w_string", "z_string" }; // in order



bool in_strings ( string a[], string b )
{
	int size = length( a );

	int pos = (int) b[0] - 97;

	if ( pos >= size )
		pos = size - 1;

	if ( pos < 0 )
		pos = 0;


	// cout << pos << "\n";

	string temp = strings[ pos ];
	int i = pos;

	if ( temp == b )
	{
		cout << "Result in 0 iterations of a string[] of length " << size << "\n";
		return 1;
	}

	int l = 0;
	int count = 0;
	while ( strings[ i ] != b )
	{
		count = count + 1;
		// cout << l << ' ' << i << "\n";

		if ( strings[ l ] > b and strings[ i ] < b and l - i == 1 )
		{
			cout << "Result in " << count << " iterations of a string[] of length " << size << "\n";
			return 0;
		}

		if ( strings[ i ] > b and strings[ l ] < b and i - l == 1  )
		{
			cout << "Result in " << count << " iterations of a string[] of length " << size << "\n";
			return 0;
		}

		if ( strings[ i ] > b )
		{
			if ( i > 0 )
			{
				l = i;
				i = i - 1;
				continue;
			}
			else
				break;
		}		

		if ( strings[ i ] < b )
		{
			if ( i < size - 1 )
			{
				l = i;
				i = i + 1;
				continue;
			}
			else
				break;
		}		

		l = i;
	}

	cout << "Result in " << count << " iterations of a string[] of length " << size << "\n";

	if ( strings[ i ] == b )
		return 1;
	
	return 0;
}


int main ()
{
	string a;
	cout << "String: ";
	getline( cin, a );
	if ( a == "" )
		getline( cin, a );

	bool l = in_strings( strings, a );

	if ( l )
		cout << "Valid.\n";
	else
		cout << "Invalid.\n";

	return 0;
}

