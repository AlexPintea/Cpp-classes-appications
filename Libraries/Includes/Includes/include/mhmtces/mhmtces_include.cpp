#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"

#include "../../mhmtces.cpp"

int main()
{
	


	// Even / Odd / Pos / Neg, Digits




	int a = 21;
	cout << "Even: " << even( a ) << ' ';
	cout << "Odd: " << odd( a ) << "\n";

	cout << "Pos: " << pos( a ) << ' ';
	cout << "Neg: " << neg( a ) << "\n";

	int evens[ 14 ] = { 1, 2, 3, 4, 5, 6, 7, 9 };
	cout << "Count Even: " << count_even( evens ) << "\n";

	cout << "Leave Even: ";
	leave_even ( evens );
	for ( int i = 0; i < length( evens ); i = i + 1 )
		cout << evens[ i ] << ' ';
	cout << "\n";


	int positives[ 14 ] = { -1, -2, 3, -4, 5, -6, 7, 9 };
	cout << "Count Pos: " << count_pos( positives ) << "\n";

	cout << "Leave Pos: ";
	leave_pos ( positives );
	for ( int i = 0; i < length( positives ); i = i + 1 )
		cout << positives[ i ] << ' ';
	cout << "\n\n";

	cout << "Digits: " << fd( 142 ) << ' ' << ld( 94 ) << "\n";




	// Prime



	
	cout << "Prime: ";
	cout << prime( a ) << "\n";

	int primes[ 14 ] = { 1, 2, 3, 4, 5, 6, 7, 9 };
	cout << "Count Prime: " << count_prime( primes ) << "\n";

	cout << "Leave Prime: ";
	leave_prime ( primes );
	for ( int i = 0; i < length( primes ); i = i + 1 )
		cout << primes[ i ] << ' ';
	cout << "\n\n";




	// Divisors




	cout << "Prime Divisors: ";
	int pd[ 90 ];
	prime_divisors( 96, pd );
	for ( int i = 0; i < length( pd ); i = i + 1 )
		cout << pd[ i ] << ' ';
	cout << "\n";

	cout << "Divisors: ";
	int d[ 90 ];
	divisors( 24, d );
	for ( int i = 0; i < length( d ); i = i + 1 )
		cout << d[ i ] << ' ';
	cout << "\n";

	cout << "Least common Divisor: ";
	cout << lc ( 64, 92 ) << ' ';
	cout << "Greatest common Multiple: ";
	cout << gc ( 32, 16 ) << "\n\n";




	// Square




	cout << "Is Square: ";
	cout << sq( 49 ) << "\n\n";




	// Perm / Arm / Comb




	cout << "Perm: ";
	cout << perm( 4 ) << ' ';
	cout << "Arn: ";
	cout << arn( 10, 2 ) << ' ';
	cout << "Comb: ";
	cout << comb( 10, 2 ) << "\n\n";




	// Means




	cout << "Gmean: " << gmean( 10, 9 ) << ' ';	
	cout << "Amean: " << amean( evens ) << "\n\n";	




	// Equation




	Equation equation = Equation( 1, 4, 4 );
	float res[ 5 ];
	equation.result( res );
	cout << "Results of equation: " << res[ 0 ] << ' ' << res[ 1 ] << "\n";

	cout << "Extreme x: " << equation.extreme_x() << "\n";
	cout << "Extreme y: " << equation.extreme_y() << "\n\n";




	// Det




	float a2[2][2] = { 1, 2,
					   3, 4 }; // 4 - 6 = -2

	cout << "Det of a2: " << det( a2 ) << "\n";


	float a3[3][3] = { 1, 2, 3,
					   4, 0, 1, 
					   0, 1, 4 }; // 12 - ( 1 + 32 ) = -21

	cout << "Det of a3: " << det( a3 ) << "\n\n";




	// Base




	cout << "Base2: " << base2( 10 ) << "\n";
	cout << "Base16: " << base16( 90 ) << "\n\n";




	// Interval




	Interval interval1 = Interval( 1, 5, true, false );
	cout << "Interval 1: ";
	interval1.info();
	cout << "\n";
	cout << "Is 2 in Interval 1: " << interval1.is_in( 2 ) << "\n";
	Interval interval2 = Interval( 2.9, 15, false, true );
	cout << "Interval 2: ";
	interval2.info();
	cout << "\n";
	cout << "Is 2 in Interval 2: " << interval2.is_in( 2 ) << "\n";

	cout << "Interval Union: ";
	interval_union( interval1, interval2 ).info();
	cout << "\n";

	cout << "Interval Common: ";
	interval_common( interval1, interval2 ).info();
	cout << "\n\n";




	// Prg Ar




	Prg_Ar prg_ar = Prg_Ar( 1, 5 );
	cout << "Prg Ar: ";
	prg_ar.info();
	cout << "Prg Ar [ 15 ]: " << prg_ar.get_a( 15 ) << '\n';
	cout << "Prg Ar sum 15: " << prg_ar.get_sum( 15 ) << '\n';
	cout << "Prg Ar sum 14, 15: " << prg_ar.get_sum( 14, 15 ) << '\n';
	cout << "Prg Ar until [ 15 ]: ";
	double prg[ 10000 ];
	prg_ar.get_prg( 0, 15, prg );
	for ( int i = 0; i < length( prg ); i = i + 1 )
		cout << prg[ i ] << ' ';
	cout << "\n\n";




	// Prg Gmer




	Prg_Gmer prg_gmer = Prg_Gmer( 1, 2 );
	cout << "Prg Gmer: ";
	prg_gmer.info();
	cout << "Prg Gmer [ 9 ]: " << prg_gmer.get_a( 9 ) << '\n';
	cout << "Prg Gmer sum 9: " << prg_gmer.get_sum( 9 ) << '\n';
	cout << "Prg Gmer sum 14, 9: " << prg_gmer.get_sum( 14, 9 ) << '\n';
	cout << "Prg Gmer until [ 9 ]: ";
	prg_gmer.get_prg( 0, 9, prg );


	for ( int i = 0; i < length( prg ); i = i + 1 )
		cout << prg[ i ] << ' ';
	cout << "\n\n";
	cout << "choice";

	return 0;
}
