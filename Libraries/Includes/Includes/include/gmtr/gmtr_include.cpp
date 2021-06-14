#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../last.cpp"
#include "../../mhmtces.cpp"

#include "../../gmtr.cpp"

int main ()
{



	// Point




	Point a = Point( 0, 4 );
	Point b = Point( 3, 0 );
	
	cout << "Distance: " << distance( a, b ) << "\n";




	// Distance




	Point pts1[ 90 ] = { Point( 1, 2 ), Point( 1, 1 ), Point( 2, 1 ), Point( 2, 2 ) };
	int size1 = 4;
	Shape s1 = Shape( pts1, size1 );
	cout << "Shape s1: ";
	s1.info();
	cout << "\n";

	cout << "Perimeter s1: " << s1.perimeter() << "\n";
	cout << "Area s1: " << s1.area() << "\n";



	Point pts2[ 90 ] = { Point( 1, 1 ), Point( 1, 2 ), Point( 2, 1 ) };
	int size2 = 3;
	Shape s2 = Shape( pts2, size2 );
	cout << "Shape s2: ";
	s2.info();
	cout << "\n";


	cout << "Perimeter s2: " << s2.perimeter() << "\n";
	cout << "Area s2: " << s2.area() << "\n\n";




	// Line




	Line l1 = Line( 1, 2, 3 );
	cout << "Line l1: ";
	l1.info();
	cout << "\n";
	Line l2 = Line( 2, 3, 1 );
	cout << "Line l2: ";
	l2.info();
	cout << "\n";


	Point l1_point = l1.get_point_x( -1 );
	l1_point.info();
	cout << "\n";



	Point l2_point = l2.get_point_y( 1 );
	l2_point.info();
	cout << "\n";


	cout << "Is on line l1: " << l1.is_on_this_line( Point( -1, -1 ) ) << "\n";
	cout << "Is on line l2: " << l2.is_on_this_line( Point( -1, -1 ) ) << "\n\n";


	line_union( l1, l2 ).info();	
	cout << "\n";


	Segment s = Segment( l1, 15, 2 );
	cout << "Segment: ";
	s.info();
	cout << "\n";
	cout << "Middle: ";
	s.middle().info();
	cout << "\n";
	cout << "Middle 3: ";
	s.middle( 3 ).info();
	cout << "\n";
	cout << "Length: " << s.length() << "\n\n";




	// Triangle




	cout << "Triangle: " << triangle( 2, 5, 4 ) << " ";
	cout << "Pitagora: " << pitagora( 0.3, 0.4, 0.5 ) << " ";
	cout << "Isoscel: " << isoscel( 4, 5, 4 ) << " ";
	cout << "Echilateral: " << echilateral( 2, 5, 4 ) << "\n";

	return 0;
}
