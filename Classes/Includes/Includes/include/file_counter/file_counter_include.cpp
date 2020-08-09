#include "../../includes.cpp"

#include "../../file_counter.cpp"

int main ()
{
	Counter counter1;
	counter1.init( "counter1" );

	counter1.count();
//	counter1.count_reverse();
//	counter1.set_count( 7 );
//	counter1.reset();
//	counter1.rename( "counter_renamed1" );
//	counter1.count( 4 );

	cout << "Counter \"" << counter1.get_filename() << "\": " << counter1.get_count() << "\n'";

	return 0;
}
