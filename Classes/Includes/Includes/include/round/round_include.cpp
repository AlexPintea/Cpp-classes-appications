#include "../../includes.cpp"

#include "../../round.cpp"

int main ()
{
	
	float a = 1.54;
	round( a );
	cout << a << "\n";	

	float b = -1.9;
	round_asc( b );
	cout << b << "\n";	

	float l = -1.4;
	round_desc( l );
	cout << l << "\n";	

	return 0;
}
