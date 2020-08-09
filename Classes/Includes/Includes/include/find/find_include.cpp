#include "../../includes.cpp"

#include "../../length.cpp"

#include "../../find.cpp"

int main ()
{
	int a[9] = { 21, 41, 12, 3, 2, 91, 3, 6 };
	int positions[1000];
	int r[100000];

	cout << find_last_int (a, 2) << endl;

	find_ints(a, 2, positions);

	for (int i=0; i<length(positions); i=i+1)
		cout << positions[i] << " ";
	cout << endl;

	find_ints_partial(a, 2, 6, r);

	for (int i=0; i<length(r); i=i+1)
		cout << r[i] << " ";
	cout << endl;

	string strngs[10] = { "a", "w2rd", "w2rd", "strings", "qwe", "l", "strings", "w2rd", "w2rd" };
	string res[100];

	find_string_by_frst_char( strngs, 'w', res );

	for (int i=0; i<4; i=i+1)
		cout << res[i] << " ";
	cout << endl;

	cout << length(strngs) << endl;


	return 0;
}
