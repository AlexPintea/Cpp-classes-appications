#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"
#include "../../mhmtces.cpp"

#include "../../physics.cpp"

int main ()
{
	Solid solid = Solid( 1, 2, 3, 0.9 );
	cout << "Solid: ";
	solid.info();
	cout << "Solid mass: " << solid.get_mass() << '\n';
	cout << "Solid v: " << solid.get_v() << '\n';
	double areas[ 10 ];
	solid.get_areas( areas );
	cout << "Solid areas: a1 = " << areas[ 0 ] << ", a2 = " << areas[ 1 ] << ", a3 = " << areas[ 2 ] << '\n';
	cout << "\n\n";

	Lens lens = Lens ( 10 );
	cout << "Lens: ";
	lens.info();
	cout << "Lens convergence: " << lens.get_convergence() << '\n';
	double pos1 = 10;
	double pos2 = 5;
	lens.get_position( pos1, pos2 );
	cout << "Lens position 10, 5: " << pos1 << ", " << pos2 << '\n';
	cout << "\n\n";


	Linear linear = Linear( 10 );
	cout << "Linear: ";
	linear.info();
	cout << "Linear time 10: " << linear.get_time( 10 ) << '\n';
	cout << "Linear distance 10: " << linear.get_distance( 10 ) << '\n';
	cout << "\n\n";




	Acl acl = Acl ( 1, 5 );
	cout << "Acl: ";
	acl.info();
	cout << "Acl time 5: " << acl.get_time( 5 ) << '\n';
	cout << "Acl distance 10: " << acl.get_distance( 10 ) << '\n';
	cout << "\n\n";


	Calorimeter calorimeter = Calorimeter( 0.9, 5 );
	cout << "Calorimeter: ";
	calorimeter.info();
	cout << "Calorimeter Coef: " << calorimeter.get_Coef() << '\n';
	cout << "\n\n";

	Electric electric = Electric( 10 );
	cout << "Electric: ";
	electric.info();
	cout << "Electric intensity: " << electric.get_intensity() << '\n';
	cout << "Electric tension 10: " << electric.get_tension( 10 ) << '\n';
	cout << "Electric e 10: " << electric.get_e( 10 ) << '\n';
	cout << "Electric magnetic: " << electric.get_magnetic() << '\n';



	return 0;
}
