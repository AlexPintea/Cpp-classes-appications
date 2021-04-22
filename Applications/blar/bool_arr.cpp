#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


class Bool_Arr
{

  private:
	int l = 0;
	bool arr[ 10000 ];

  public:
	Bool_Arr(){}

	void add ( bool a )
	{
		arr[ l ] = a;
		l = l + 1;
	}

	void add ( bool a, int i )
	{
		l = l + 1;
		for ( int m = l - 2; m >= i; m = m - 1 )
			arr[ m + 1 ] = arr[ m ];
		arr[ i ] = a;
	}

	void set ( bool a, int i )
	{
		arr[ i ] = a;
		if ( i > l )
			l = i;
	}

	void remove ( int i )
	{
		l = l - 1;
		for ( int m = i; m <= l - 1; m = m + 1 )
			arr[ m ] = arr[ m + 1 ];
	}

	int length () { return l; }




	void info ()
	{
		cout << "Bool_Arr: ";
		for ( int i = 0; i < l; i = i + 1 )
		{
			cout << arr[ i ];
			if ( i != l - 1 )
				cout << ", ";
		}
		cout << ". ( length = " << l << " )\n";
	}

	bool get ( int i ) 
	{
		if ( i < l and i >=0 )
			return arr[ i ];
		if ( i < 0 )
			cout << "Negative iterator given.\n";
		if ( i >= l )
			cout << "Iterator larger than length of array.\n";
		return 0;
	}

};






int main ()
{
	Bool_Arr blar;

	for ( int i = 0; i < 9; i = i + 1 )
		if ( i % 2 == 0 )
			blar.add( 1 );
		else
			blar.add( 0 );

	blar.info();

	blar.add( 0, 2 );
	blar.info();

	blar.remove( 0 );
	blar.remove( 0 );
	blar.remove( 0 );
	blar.remove( 0 );
	blar.remove( 0 );
	blar.info();

	return 0;
}
