// #include "lengths.cpp"




// gets string data ( val.-s of certain datatypes ) into data[] as strings
void get_data ( string a, string data[] )
{
	int size = a.length();

	// empty data
	for ( int i=0; i<length( data ); i=i+1 )
		data[i] = "";

	int counter = 0;

	a = a + ' ';

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			counter = counter + 1;
		else
			data[ counter ] = data[ counter ] + a[i];
}

// moves string data ( val.-s of certain datatypes ) into data[] as strings
void move_data ( string a, string data[], string separators )
{
	int size = a.length();

	// empty data
	for ( int i=0; i<length( data ); i=i+1 )
		data[i] = "";

	// empty data
	for ( int i=0; i<size; i=i+1 )
		if ( is_char_in_string( separators, a[i] ) )
			a[i] = ' ';

	reduce_spaces( a );

	int counter = 0;

	while ( a[0] == ' ' )
		remove_char( a, 0 );

	size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			counter = counter + 1;
		else
			data[ counter ] = data[ counter ] + a[i];
}





// string





// get entered string
void get ( string &entered_string )
{
	entered_string = "";

	while ( entered_string == "" )
		getline( cin, entered_string );
}

// get entered strings with separator chars
void get ( string entered_strings[], string separators )
{
	string temp;

	get( temp );
	reduce_spaces( temp );

	move_data( temp, entered_strings, separators );
}

// get entered strings
void get ( string entered_strings[] )
{
	get( entered_strings, " " );
}

// sets a string
void set ( string a )
{
	cout << a;
}

// sets a string[] with a separator string
void set ( string a[], string separator )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		if ( i != size - 1 )
			cout << separator;
	}
}


// sets a string[] with nums
void set_nums ( string a[] )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		cout << i + 1 << ". " << a[ i ] << "  ";
}

// sets a string[] with strings
void set_strings ( string a[], string strings[] )
{
	int size = length( a );

	for ( int i = length( strings ); i < size; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}

	for ( int i = 0; i < size; i = i + 1 )
		cout << strings[ i ] << ". " << a[ i ] << "  ";
}

// sets a string[]
void set ( string a[] )
{
	set( a, " " );
}



// sets a string[] with a separator string
void set ( string a[], int num_columns )
{
	int size = length(a);

	int max_length[ num_columns ];
	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length();

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		for ( int l=a[i].length(); l<max_length[ i % num_columns ]; l=l+1 )
			cout << ' ';
		if ( i % num_columns == num_columns - 1 )
			cout << "\n";
	}
}



// sets a string[] with a separator string
void set ( string a[], int num_columns, bool vertical )
{
	if ( ! vertical )
	{
		set( a, num_columns );
		return;
	}
	int size = length(a);

	if ( num_columns == size )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 0 and num_columns > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 1 and num_columns - 1 > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	int l;

	if ( size % l == 0 )
		l = size / num_columns;
	else
		l = size / num_columns + 1;

	int max_length[ l + 1 ];
	for ( int i=0; i<l; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length();

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	int count = 0;
	for ( int i=0; i<l; i=i+1 )
	{
		count = 0;
		for ( int d=0; d + i<size; d=d+l )
		{
			if ( count >= num_columns )
				break;

			cout << a[i+d];
			for ( int u=a[i+d].length(); u<max_length[ count % num_columns ]; u=u+1 )
				cout << ' ';
			count = count + 1;
		}
		cout << "\n";
	}
	if ( size % num_columns != 0 )
		cout << '\n';
}



// sets a string[] with a separator string and nums
void set_num ( string a[], int num_columns )
{
	int size = length(a);

	int max_length[ num_columns ];
	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() + length( i + 1 ) > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length() + length( i + 1 );

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	for ( int i=0; i<size; i=i+1 )
	{
		cout << i + 1 << ". " << a[i];
		for ( int l=a[i].length() + length( i + 1 ); l<max_length[ i % num_columns ]; l=l+1 )
			cout << ' ';
		if ( i % num_columns == num_columns - 1 )
			cout << "\n";
	}
}





// sets a string[] with a separator string
void set_num ( string a[], int num_columns, bool vertical )
{
	if ( ! vertical )
	{
		set( a, num_columns );
		return;
	}
	int size = length(a);

	if ( num_columns == size )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 0 and num_columns > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 1 and num_columns - 1 > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	int l;

	if ( size % l == 0 )
		l = size / num_columns;
	else
		l = size / num_columns + 1;

	int max_length[ l + 1 ];
	for ( int i=0; i<l; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() + length( i + 1 ) > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length() + length( i + 1 );

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	int count = 0;
	for ( int i=0; i<l; i=i+1 )
	{
		count = 0;
		for ( int d=0; d + i<size; d=d+l )
		{
			if ( count >= num_columns )
				break;

			cout << i + d + 1 << ". " << a[i+d];
			for ( int u=a[i+d].length() + length( i + 1 ); u<max_length[ count % num_columns ]; u=u+1 )
				cout << ' ';
			count = count + 1;
		}
		cout << "\n";
	}


	if ( size % num_columns != 0 )
		cout << '\n';
}

// sets a string[] with a separator string and nums
void set_strings ( string a[], string strings[], int num_columns )
{
	int size = length(a);



	for ( int i = length( strings ); i < size; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}
	int max_length[ num_columns ];
	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() + strings[ i ].length() > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length() + strings[ i ].length();

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	for ( int i=0; i<size; i=i+1 )
	{
		if ( strings[ i ] != "" )
		{
			cout << strings[ i ] << ". " << a[i];
			for ( int l=a[i].length() + strings[ i ].length(); l<max_length[ i % num_columns ]; l=l+1 )
				cout << ' ';
		}
		else
		{
			cout << a[i];

			for ( int l=a[i].length(); l<max_length[ i % num_columns ] + 2; l=l+1 )
				cout << ' ';
		}
		if ( i % num_columns == num_columns - 1 )
			cout << "\n";
	}
	if ( size % num_columns != 0 )
		cout << '\n';
}





// sets a string[] with a separator string
void set_strings ( string a[], string strings[], int num_columns, bool vertical )
{
	if ( ! vertical )
	{
		set( a, num_columns );
		return;
	}
	int size = length(a);

	if ( num_columns == size )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 0 and num_columns > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 1 and num_columns - 1 > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	for ( int i = length( strings ); i < size; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}


	int l;

	if ( size % l == 0 )
		l = size / num_columns;
	else
		l = size / num_columns + 1;

	int max_length[ l + 1 ];
	for ( int i=0; i<l; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() + strings[i].length() > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length() + strings[i].length();

	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;

	int count = 0;
	for ( int i=0; i<l; i=i+1 )
	{
		count = 0;
		for ( int d=0; d + i<size; d=d+l )
		{
			if ( count >= num_columns )
				break;

			if ( strings[ i + d ] != "" )
			{
				cout << strings[ i + d ] << ". " << a[i+d];
				for ( int u=a[i+d].length() + strings[i].length(); u<max_length[ count % num_columns ]; u=u+1 )
					cout << ' ';
			}
			else
			{
				cout << a[i+d];
				for ( int u=a[i+d].length(); u<max_length[ count % num_columns ] + 2; u=u+1 )
					cout << ' ';
			}

			count = count + 1;
		}
		cout << "\n";
	}


	if ( size % num_columns != 0 )
		cout << '\n';
}

// sets a string[] with a separator string and nums
void set_columns ( string a[], string strings[], int num_columns )
{
	int size = length(a);



	for ( int i = length( strings ); i < num_columns; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}
	int max_length[ num_columns ];
	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length();


	for ( int i=0; i<num_columns; i=i+1 )
		if ( strings[ i ].length() > max_length[ i ] )
			max_length[ i ] = strings[ i ].length();


	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;


	for ( int i=0; i<num_columns; i=i+1 )
	{
		cout << strings[ i ];
		for ( int l=strings[ i ].length(); l<max_length[ i ]; l=l+1 )
			cout << ' ';
	}


	cout << "\n\n";

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		for ( int l=a[i].length(); l<max_length[ i % num_columns ]; l=l+1 )
			cout << ' ';
		if ( i % num_columns == num_columns - 1 )
			cout << "\n";
	}
	if ( size % num_columns != 0 )
		cout << '\n';
}


// sets a string[] with a separator string
void set_columns ( string a[], string strings[], int num_columns, bool vertical )
{
	if ( ! vertical )
	{
		set( a, num_columns );
		return;
	}
	int size = length(a);

	if ( num_columns == size )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 0 and num_columns > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	if ( size % 2 == 1 and num_columns - 1 > size / 2 )
	{
		set( a, " " );
		cout << '\n';
		return;
	}

	int l;

	if ( size % l == 0 )
		l = size / num_columns;
	else
		l = size / num_columns + 1;

	int max_length[ l + 1 ];
	for ( int i=0; i<l; i=i+1 )
		max_length[i] = 0;

	for ( int i=0; i<size; i=i+1 )
		if ( a[i].length() > max_length[ i % num_columns ] )
			max_length[ i % num_columns ] = a[i].length();

	for ( int i=0; i<num_columns; i=i+1 )
		if ( strings[ i ].length() > max_length[ i ] )
			max_length[ i ] = strings[ i ].length();


	for ( int i=0; i<num_columns; i=i+1 )
		max_length[i] = max_length[i] + 2;


	for ( int i=0; i<num_columns; i=i+1 )
	{
		cout << strings[ i ];
		for ( int l=strings[ i ].length(); l<max_length[ i ]; l=l+1 )
			cout << ' ';
	}

	cout << "\n\n";

	int count = 0;
	for ( int i=0; i<l; i=i+1 )
	{
		count = 0;
		for ( int d=0; d + i<size; d=d+l )
		{
			if ( count >= num_columns )
				break;


			cout << a[i+d];
			for ( int u=a[i+d].length(); u<max_length[ count % num_columns ]; u=u+1 )
				cout << ' ';

			count = count + 1;
		}
		cout << "\n";
	}


	if ( size % num_columns != 0 )
		cout << '\n';
}

// sets an int[] columns
void set ( int a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set( b, num_columns );
}

// sets an int[] columns vertical
void set ( int a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set( b, num_columns, vertical );
}


// sets an long[] columns
void set ( long a[], int num_columns )
{
	int size = length( a );

	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set( b, num_columns );
}

// sets an long[] columns
void set ( long a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set( b, num_columns, vertical );
}

// sets an double[] columns
void set ( double a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set( b, num_columns );
}

// sets an double[] columns
void set ( double a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set( b, num_columns, vertical );
}


// sets an float[] columns
void set ( float a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set( b, num_columns );
}

// sets an float[] columns
void set ( float a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set( b, num_columns, vertical );
}

// sets an char[] columns
void set ( char a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set( b, num_columns );
}

// sets an char[] columns
void set ( char a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set( b, num_columns, vertical );
}





// set_nums an int[] columns
void set_num ( int a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set_num( b, num_columns );
}

// set_nums an int[] columns vertical
void set_num ( int a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set_num( b, num_columns, vertical );
}


// set_nums an long[] columns
void set_num ( long a[], int num_columns )
{
	int size = length( a );

	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set_num( b, num_columns );
}

// set_nums an long[] columns
void set_num ( long a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set_num( b, num_columns, vertical );
}

// set_nums an double[] columns
void set_num ( double a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set_num( b, num_columns );
}

// set_nums an double[] columns
void set_num ( double a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set_num( b, num_columns, vertical );
}


// set_nums an float[] columns
void set_num ( float a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set_num( b, num_columns );
}

// set_nums an float[] columns
void set_num ( float a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set_num( b, num_columns, vertical );
}

// set_nums an char[] columns
void set_num ( char a[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set_num( b, num_columns );
}


// set_nums an char[] columns
void set_num ( char a[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set_num( b, num_columns, vertical );
}

// set_stringss an int[] columns
void set_strings ( int a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set_strings( b, strings, num_columns );
}

// set_stringss an int[] columns vertical
void set_strings ( int a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set_strings( b, strings, num_columns, vertical );
}


// set_stringss an long[] columns
void set_strings ( long a[], string strings[], int num_columns )
{
	int size = length( a );

	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set_strings( b, strings, num_columns );
}

// set_stringss an long[] columns
void set_strings ( long a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set_strings( b, strings, num_columns, vertical );
}

// set_stringss an double[] columns
void set_strings ( double a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set_strings( b, strings, num_columns );
}

// set_stringss an double[] columns
void set_strings ( double a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set_strings( b, strings, num_columns, vertical );

}


// set_stringss an float[] columns
void set_strings ( float a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set_strings( b, strings, num_columns );
}

// set_stringss an float[] columns
void set_strings ( float a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set_strings( b, strings, num_columns, vertical );
}

// set_stringss an char[] columns
void set_strings ( char a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set_strings( b, strings, num_columns );
}


// set_stringss an char[] columns
void set_strings ( char a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set_strings( b, strings, num_columns, vertical );
}



// set_columnss an int[] columns
void set_columns ( int a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set_columns( b, strings, num_columns );
}

// set_columnss an int[] columns vertical
void set_columns ( int a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = int_to_string( a[ l ] );

	set_columns( b, strings, num_columns, vertical );
}


// set_columnss an long[] columns
void set_columns ( long a[], string strings[], int num_columns )
{
	int size = length( a );

	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set_columns( b, strings, num_columns );
}

// set_columnss an long[] columns
void set_columns ( long a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = long_to_string( a[ l ] );

	set_columns( b, strings, num_columns, vertical );
}

// set_columnss an double[] columns
void set_columns ( double a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set_columns( b, strings, num_columns );
}

// set_columnss an double[] columns
void set_columns ( double a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = double_to_string( a[ l ] );

	set_columns( b, strings, num_columns, vertical );

}


// set_columnss an float[] columns
void set_columns ( float a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set_columns( b, strings, num_columns );
}

// set_columnss an float[] columns
void set_columns ( float a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = float_to_string( a[ l ] );

	set_columns( b, strings, num_columns, vertical );
}

// set_columnss an char[] columns
void set_columns ( char a[], string strings[], int num_columns )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set_columns( b, strings, num_columns );
}


// set_columnss an char[] columns
void set_columns ( char a[], string strings[], int num_columns, bool vertical )
{
	int size = length( a );
	string b[ size + 1 ];

	for ( int l = 0; l < size; l = l + 1 )
		b[ l ] = char_to_string( a[ l ] );

	set_columns( b, strings, num_columns, vertical );
}




// long (same as int)




// get entered long
void get ( long &entered_long )
{
	string temp;

	get( temp );

	if ( is_long( temp ) )
		entered_long = string_to_long( temp );
	else
		entered_long = -1;
}

// get entered longs with separator chars
void get ( long entered_longs[], string separators )
{
	string temp;

	get( temp );
	reduce_spaces( temp );

	string temp_strings[1000];
	move_data( temp, temp_strings, separators );

	string_to_long( temp_strings, entered_longs );
}

// get entered longs
void get ( long entered_longs[] )
{
	get ( entered_longs, " " );
}

// sets a long
void set ( long a )
{
	cout << a;
}

// sets a long[] with a separator string
void set ( long a[], string separator )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		if ( i != size - 1 )
			cout << separator;
	}
}

// sets a long[] with nums
void set_nums ( long a[] )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		cout << i + 1 << ". " << a[ i ] << "  ";
}

// sets a long[] with longs
void set_longs ( long a[], string strings[] )
{
	int size = length( a );

	for ( int i = length( strings ); i < size; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}

	for ( int i = 0; i < size; i = i + 1 )
		cout << strings[ i ] << ". " << a[ i ] << "  ";
}


// sets a long[]
void set ( long a[] )
{
	set( a, " " );
}


// ints


// get entered int
void get ( int &entered_int )
{
	get( entered_int );
}

// get entered ints with separator chars
void get ( int entered_ints[], string separators )
{
	get( entered_ints, separators );
}

// get entered ints
void get ( int entered_ints[] )
{
	get ( entered_ints, " " );
}

// sets a int
void set ( int a )
{
	cout << a;
}

// sets a int[] with a separator string
void set ( int a[], string separator )
{
	set( a, separator );
}

// sets a int[] with nums
void set_nums ( int a[] )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		cout << i + 1 << ". " << a[ i ] << "  ";
}
// sets a int[] with ints
void set_ints ( int a[], string strings[] )
{
	int size = length( a );

	for ( int i = length( strings ); i < size; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}

	for ( int i = 0; i < size; i = i + 1 )
		cout << strings[ i ] << ". " << a[ i ] << "  ";
}

// sets a int[]
void set ( int a[] )
{
	set( a, " " );
}




// doubles ( same as floats )




// get entered double
void get ( double &entered_double )
{
	string temp;

	get( temp );

	if ( is_double( temp ) )
		entered_double = string_to_double( temp );
	else
		entered_double = -1;
}

// get entered doubles with separator chars
void get ( double entered_doubles[], string separators )
{
	string temp;

	get( temp );
	reduce_spaces( temp );

	string temp_strings[1000];
	move_data( temp, temp_strings, separators );

	string_to_double( temp_strings, entered_doubles );
}

// get entered doubles
void get ( double entered_doubles[] )
{
	get ( entered_doubles, " " );
}

// sets a double
void set ( double a )
{
	cout << a;
}

// sets a double[] with a separator string
void set ( double a[], string separator )
{
	int size = length(a);

	for ( int i=0; i<size; i=i+1 )
	{
		cout << a[i];
		if ( i != size - 1 )
			cout << separator;
	}
}

// sets a double[] with nums
void set_nums ( double a[] )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		cout << i + 1 << ". " << a[ i ] << "  ";
}

// sets a double[] with doubles
void set_doubles ( double a[], string strings[] )
{
	int size = length( a );

	for ( int i = length( strings ); i < size; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}

	for ( int i = 0; i < size; i = i + 1 )
		cout << strings[ i ] << ". " << a[ i ] << "  ";
}


// sets a double[]
void set ( double a[] )
{
	set( a, " " );
}


// floats


// get entered float
void get ( float &entered_float )
{
	get( entered_float );
}

// get entered floats with separator chars
void get ( float entered_floats[], string separators )
{
	get( entered_floats, separators );
}

// get entered floats
void get ( float entered_floats[] )
{
	get ( entered_floats, " " );
}

// sets a float
void set ( float a )
{
	cout << a;
}

// sets a float[] with a separator string
void set ( float a[], string separator )
{
	set( a, separator );
}
// sets a float[] with nums
void set_nums ( float a[] )
{
	int size = length( a );
	for ( int i = 0; i < size; i = i + 1 )
		cout << i + 1 << ". " << a[ i ] << "  ";
}

// sets a float[] with floats
void set_floats ( float a[], string strings[] )
{
	int size = length( a );

	for ( int i = length( strings ); i < size; i = i + 1 )
	{
		if ( strings[ i ] != "" ) continue;
		strings[ i ] == "";
	}

	for ( int i = 0; i < size; i = i + 1 )
		cout << strings[ i ] << ". " << a[ i ] << "  ";
}

// sets a float[]
void set ( float a[] )
{
	set( a, " " );
}




// chars




// get entered char
void get ( char &entered_char )
{
	string temp;

	get( temp );

	if ( is_char( temp ) )
		entered_char = string_to_char( temp );
	else
		entered_char = -1;
}

// get entered chars with separator chars
// ISO forbids this

// get entered chars
// ISO forbids this

// sets a char
void set ( char a )
{
	cout << a;
}

// sets a char[] with a separator string
// ISO forbids this

// sets a char[]
// ISO forbids this




// bools
// are not available





// set_get




// clears
void clear ( int num )
{
	for ( int i=0; i<num; i=i+1 )
		cout << "\b";
}

// get a string
void set_get ( string set, string &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	getline( cin, get );
	if ( get == "" )
		getline( cin, get );
}

// get a long
void set_get ( string set, long &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_long( get_string ) )
		get = string_to_long( get_string );
	else
		get = -1; // if get_string was !long
}

// get a int
void set_get ( string set, int &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_int( get_string ) )
		get = string_to_int( get_string );
	else
		get = -1; // if get_string was !int
}

// get a double
void set_get ( string set, double &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_double( get_string ) )
		get = string_to_double( get_string );
	else
		get = -1; // if get_string was !double
}

// get a float
void set_get ( string set, float &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_float( get_string ) )
		get = string_to_float( get_string );
	else
		get = -1; // if get_string was !float
}

// get a char
void set_get ( string set, char &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_char( get_string ) )
		get = string_to_char( get_string );
	else
		get = -1; // if get_string was !char
}

// get a bool
void set_get ( string set, bool &get )
{
	set = "          = ( " + set + " )";

	cout << set;

	clear( set.length() );

	string get_string;

	getline( cin, get_string );
	if ( get_string == "" )
		getline( cin, get_string );

	if ( is_bool( get_string ) )
		get = string_to_bool( get_string );
	else
		get = -1; // if get_string was !bool
}


