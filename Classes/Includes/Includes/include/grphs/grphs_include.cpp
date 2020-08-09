#include "../../includes.cpp"

#include "../../grphs.cpp"

int main ()
{
	cout << "grphs\n";



	int a[ 34 ] = { 2, 3, 2, 3, 2 };
	int b[ 34 ] = { 1, 2, 1, 2, 1 };
	Graph graph = Graph( true, a, b );

	graph.adiacence();
	graph.lines();
	graph.all_num_lines();

	cout << graph.get_size() << ' ' << graph.get_num_lines() << "\n";

	cout << "\n";



	// Add line



	graph.add_line( 5, 4 );
	graph.add_line( 4, 3 );
	graph.add_line( 4, 1 );
	graph.add_line( 1, 5 );
	graph.remove_line( 3, 2 );
//	graph.set_unidirectional( false );

	graph.adiacence();
	graph.lines();
	graph.all_num_lines();

	graph.path( 5, 1 );

	cout << "\n";
	cout << graph.get_size() << ' ' << graph.get_num_lines() << "\n";



	int p[ 90 ] = { 1, 2, 3 };
	permutations( p );


	// Remove line


//	graph.remove_line( 4, 3 );
//	graph.remove_line( 5, 4 );

//	graph.adiacence();

//	graph.lines();

//	cout << "\n";


	return 0;
}
