#include "../../includes.cpp"

#include "../../length.cpp"
#include "../../empty.cpp" // length
#include "../../last.cpp" // empty
#include "../../convert.cpp" // empty
#include "../../lists.cpp" // empty
#include "../../a_is_in_b.cpp" // empty

#include "../../sort.cpp"

int main () 
{

	// easy sorting

	int a[9] = { 4, 1, 2, 5, 3, 8, 6, 7 };
	int size = length(a);



	cout << length(a) << endl;
	sort(a);
	sort_invert(a);
	
	for (int i=0; i<size; i=i+1)
		cout << a[i] << " ";
	cout << endl;


	
	char s[9] = { 'q', 'w', 'f', 's', 'b', 'a', 'g', 'l' };

	sort(s);
	for (int i=0; i<size; i=i+1)
		cout << s[i] << " ";
	cout << endl;

	string k = "qwfsbagl";

	cout << length(k) << endl;
	sort(k);
	for (int i=0; i<size; i=i+1)
		cout << k[i] << " ";
	cout << endl;

	float f[9] = { 1.34, 4.28, 8.12, 98, 7, 72.01, 3.010210, 9.21 };

	cout << length(f) << endl;
	sort(f);
	for (int i=0; i<size; i=i+1)
		cout << f[i] << " ";
	cout << endl;

	double d[9] = { 1.34, 4.28, 8.12, 98, 7, 72.01, 3.010210, 9.21 };

	cout << length(d) << endl;
	sort(d);
	for (int i=0; i<size; i=i+1)
		cout << d[i] << " ";
	cout << endl;

	string strngs[9] = { "a", "w2rd", "w2rd", "strings", "qwe", "l", "strings", "w2rd" };

//	sort(strngs);
	for (int i=0; i<size; i=i+1)
		cout << strngs[i] << " ";
	cout << endl;

	

	// sort freq

	int ints[9] = { 1, 4, 20, 40, 10, 2, 1, 1 };

	sort_by_freq_invert(ints);

	for (int i=0; i<size; i=i+1)
		cout << ints[i] << " ";
	cout << endl;

	float floats[9] = { 1.04, 4.1, 2, 4.1, 1.04, 2, 1.04, 1.04 };

	sort_by_freq(floats);

	for (int i=0; i<size; i=i+1)
		cout << floats[i] << " ";
	cout << endl;

	double doubles[9] = { 1.04, 4.1, 2, 4.1, 1.04, 2, 1.04, 1.04 };

	sort_by_freq_invert(doubles);

	for (int i=0; i<size; i=i+1)
		cout << doubles[i] << " ";
	cout << endl;

	char chars[9] = { 'q', 'l', 'q', 'l', 'b', 'b', 'q', 'b' };

	sort_by_freq_invert(chars);

	for (int i=0; i<size; i=i+1)
		cout << chars[i] << " ";
	cout << endl;

	string strings = "qlqlbbqb";

	sort_by_freq(strings);

	for (int i=0; i<size; i=i+1)
		cout << strings[i] << " ";
	cout << endl;


	// sort size

//	sort_by_size(ints);

	for (int i=0; i<size; i=i+1)
		cout << ints[i] << " ";
	cout << endl;
	
	sort_by_size_invert( strngs );

	for (int i=0; i<size; i=i+1)
		cout << strngs[i] << " ";
	cout << endl;

	// sort partial

	sort_partial_invert(ints, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << ints[i] << " ";
	cout << endl;



	for (int i=0; i<size; i=i+1)
		cout << floats[i] << " ";
	cout << endl;

	sort_partial(floats, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << floats[i] << " ";
	cout << endl;



	for (int i=0; i<size; i=i+1)
		cout << doubles[i] << " ";
	cout << endl;

	sort_partial_invert(doubles, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << doubles[i] << " ";
	cout << endl;




	for (int i=0; i<size; i=i+1)
		cout << chars[i] << " ";
	cout << endl;

	sort_partial_invert(chars, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << chars[i] << " ";
	cout << endl;


	// partial invert

	for (int i=0; i<size; i=i+1)
		cout << ints[i] << " ";
	cout << endl;

	partial_invert(ints, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << ints[i] << " ";
	cout << endl;
	

	for (int i=0; i<size; i=i+1)
		cout << floats[i] << " ";
	cout << endl;

	partial_invert(floats, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << floats[i] << " ";
	cout << endl;
	

	for (int i=0; i<size; i=i+1)
		cout << doubles[i] << " ";
	cout << endl;

	partial_invert(doubles, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << doubles[i] << " ";
	cout << endl;
	

	for (int i=0; i<size; i=i+1)
		cout << chars[i] << " ";
	cout << endl;

	partial_invert(chars, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << chars[i] << " ";
	cout << endl;
	

	for (int i=0; i<size; i=i+1)
		cout << strngs[i] << " ";
	cout << endl;

	partial_invert(strngs, 2, 6);

	for (int i=0; i<size; i=i+1)
		cout << strngs[i] << " ";
	cout << endl;
	

	// sort by data

	char datas[9] = { '1', 'r', '/', '?', '\"', '4', '!', ']' };

	int numeric_counter;
	int writing_counter;
	int sign_counter;

	count_data( datas, numeric_counter, writing_counter, sign_counter );

	cout << numeric_counter << ' ' << writing_counter << ' ' << sign_counter << endl;

	int numeric[1000];
	char writing[1000];
	char signs[1000];

	sort_by_data( datas, numeric, writing, signs );

	for (int i=0; i<length(numeric); i=i+1)
		cout << numeric[i] << " ";
	cout << endl;

	for (int i=0; i<length(writing); i=i+1)
		cout << writing[i] << " ";
	cout << endl;

	for (int i=0; i<length(signs); i=i+1)
		cout << signs[i] << " ";
	cout << endl;

	cout << string_max("a", "ab") << endl;

	// a is in b

	cout << a_is_in_b ( 0, 190 ) << endl;

	cout << a_is_in_b ( 4, 10 ) << endl;

	int a_nums[9] = { 4, 1, 2, 5, 3, 8, 6, 7 };
	int b_nums[4] = { 3, 8, 6 };

	cout << a_is_in_b ( a_nums, b_nums ) << endl;

	int char_a[9] = { 'q', 'l', 'q', 'l', 'b', 'b', 'q', 'b' };
	int char_b[4] = { 'l', 'b', 'b' };

	cout << 4 << endl << 4 << endl << 4 << endl << 4 << endl << 4 << endl << 4 << endl;

	cout << a_is_in_b ( char_a, char_b ) << endl;


	return 0;
}
