class Graph 
{

  private:

	int size = 0;
	int num_lines = 0;
	bool unidirectional = 1;
	int a[ 1000 ] = {};
	int b[ 1000 ] = {};



	int length_graph ( int a[] )
	{
		int i = 0;

		while ( a[ i ] )
			i = i + 1;
		
		return i;
	}

	void set_size ()
	{
		int maxim = a[ 0 ];
		for ( int i = 0; i < this->num_lines; i = i + 1 )
		{
			if ( a[ i ] > maxim )
				maxim = a[ i ];
			if ( b[ i ] > maxim )
				maxim = b[ i ];
		}

		this->size = maxim;
	}


  public:


	Graph(){}

	Graph( bool unidirectional ){ this->unidirectional = unidirectional; }

	Graph( bool unidirectional, int a[], int b[] )
	{
		if ( this->length_graph( a ) != this->length_graph( b ) )
		{
			cout << "Graph: Size mismatch. Aborted.\n";
			return;
		}

		this->unidirectional = unidirectional;

		this->num_lines = length_graph( a );

		this->size = a[ 0 ];

		int l = 0;

		for ( int i = 0; i < num_lines; i = i + 1 )
		{
			if ( a[ i ] > this->size )
				this->size = a[ i ];

			if ( b[ i ] > this->size )
				this->size = b[ i ];


			if ( this->have_line( a[ i ], b[ i ] ) )
				continue;


			this->a[ l ] = a[ i ];
			this->b[ l ] = b[ i ];
			l = l + 1;
		}

		this->num_lines = l;
	}




	// Getters




	int get_size () { return this->size; }	
	int get_num_lines () { return this->num_lines; }	
	bool get_unidirectional () { return this->unidirectional; }	
	void get_lines ( int a[], int b[] )
	{
		for ( int i = 0; i < num_lines; i = i + 1 )
		{
			a[ i ] = this->a[ i ];
			b[ i ] = this->b[ i ];
		}

		a[ num_lines ] = 0;
		b[ num_lines ] = 0;
	}




	// Setters




	void set_lines ( int a[], int b[] )
	{
		if ( this->length_graph( a ) != this->length_graph( b ) )
		{
			cout << "Graph: Size mismatch. Aborted.\n";
			return;
		}

		this->num_lines = length_graph( a );

		this->size = a[ 0 ];

		int l = 0;

		for ( int i = 0; i < num_lines; i = i + 1 )
		{
			if ( a[ i ] > this->size )
				this->size = a[ i ];

			if ( b[ i ] > this->size )
				this->size = b[ i ];


			if ( this->have_line( a[ i ], b[ i ] ) )
				continue;


			this->a[ l ] = a[ i ];
			this->b[ l ] = b[ i ];
			l = l + 1;
		}

		this->num_lines = l;
	}
	void set_unidirectional ( bool unidirectional ) { this->unidirectional = unidirectional; }





	// Line check





	// check for a line
	bool have_line ( int a1, int a2 )
	{
		if ( a1 > this->size or a2 > this->size or a1 <= 0 or a2 <= 0 )
		{
			cout << "Invalid nums: " << a1 << ' ' << a2 << " size: " << this->size << "\n";
			return false;
		}

		for ( int i = 0; i < this->num_lines; i = i + 1 )
		{
			if ( this->unidirectional )
			{
				if ( this->a[ i ] == a1 and this->b[ i ] == a2 )
					return true;
			}
			else
				if ( ( this->a[ i ] == a1 and this->b[ i ] == a2 ) or ( this->a[ i ] == a2 and this->b[ i ] == a1 ) )
					return true;	
		}

		return false;
	}




	// adds a line to graph
	void add_line ( int a, int b )
	{
		if ( a <= 0 or b <= 0 )
		{
			cout << "Invalid nums.\n";
			return;
		}


		if ( a > this->size ) this->size = a; // checks to set size
		if ( b > this->size ) this->size = b;

		this->a[ this->num_lines ] = a;
		this->b[ this->num_lines ] = b;

		this->num_lines = this->num_lines + 1;

		this->a[ this->num_lines ] = 0;
		this->b[ this->num_lines ] = 0;
	}


	// removes a graph line
	void remove_line ( int a, int b )
	{
		if ( a > this->size or b > this->size or a <= 0 or b <= 0 )
		{
			cout << "Invalid nums.\n";
			return;
		}


		int a1[ 1000 ];
		int b1[ 1000 ];

		int l = 0;

		bool removed = false;

		if ( this->unidirectional )
		{
			for ( int i = 0; i < this->num_lines; i = i + 1 )
				if ( ! ( this->a[ i ] == a and this->b[ i ] == b ) )
				{
					a1[ l ] = this->a[ i ];
					b1[ l ] = this->b[ i ];
					l = l + 1;
				}
				else
					removed = true;
		}
		else
			for ( int i = 0; i < this->num_lines; i = i + 1 )
				if ( ! ( ( this->a[ i ] == a and this->b[ i ] == b ) or ( this->a[ i ] == b and this->b[ i ] == a ) ) )
				{
					a1[ l ] = this->a[ i ];
					b1[ l ] = this->b[ i ];
					l = l + 1;
				}
				else
					removed = true;


		if ( ! removed )
		{
			cout << "Line ( " << a << ", " << b << " ) invalid. Removal impossible.\n";
			return;
		}


		for ( int i = 0; i < this->num_lines - 1; i = i + 1 )	
		{
			this->a[ i ] = a1[ i ];
			this->b[ i ] = b1[ i ];
		}

		this->a[ this->num_lines - 1 ] = 0;
		this->b[ this->num_lines - 1 ] = 0;

		this->num_lines = this->num_lines - 1;

		this->set_size();
	}



	void path ( int a, int b )
	{
		if ( a > this->size or b > this->size or a <= 0 or b <= 0 )
		{
			cout << "Invalid nums.\n";
			return;
		}


		int pos = a;

		if ( this->unidirectional )
		{

			cout << a;

			int i = 0;
			while ( this->a[ i ] != b )
			{
				if ( this->a[ i ] == pos )
				{
					pos = this->b[ i ];
					cout << " - " << this->b[ i ];
					i = -1;

					if ( pos == b )
						break;
				}

				i = i + 1;
			}
		}
		else
			for ( int i = 0; i < this->num_lines; i = i + 1 )
			{
				if ( this->a[ i ] == pos )
				{
					pos = this->b[ i ];
					cout << this->a[ i ] << " - " << this->b[ i ] << ", ";
					i = 0;

					if ( pos == b )
						break;
				}
				if ( this->b[ i ] == pos )
				{
					pos = this->a[ i ];
					cout << this->b[ i ] << " - " << this->a[ i ] << ", ";
					i = 0;

					if ( pos == b )
						break;
				}
			}
	}





	// show adiacence
	void adiacence ()
	{
		for ( int i = 0; i < this->size; i = i + 1 )
		{
			for ( int l = 0; l < this->size; l = l + 1 )
			{
				if ( this->have_line( i + 1, l + 1 ) )
					cout << "1 ";
				else
					cout << "0 ";
			}

			cout << "\n";
		}
	}


	// show lines
	void lines ()
	{
		if ( this->unidirectional )
		{
			for ( int i = 0; i < this->size; i = i + 1 )
				for ( int l = 0; l < this->size; l = l + 1 )
					if ( this->have_line( i + 1, l + 1 ) )
						cout << i + 1 << " - " << l + 1 << "\n";
		}
		else
			for ( int i = 0; i < this->size - 1; i = i + 1 )
				for ( int l = i + 1; l < this->size; l = l + 1 )
					if ( this->have_line( i + 1, l + 1 ) )
						cout << i + 1 << " [-] " << l + 1 << "\n";
		
	}


	// num. of lines for a pos
	int num_lines_for_pos ( int pos )
	{
		int count = 0;

		if ( this->unidirectional )
			for ( int l = 0; l < this->num_lines; l = l + 1 )
				if ( pos == a[ l ] )
					count = count + 1;
		
		return count;
	}


	// num. of lines for all pos
	void all_num_lines ()
	{
		for ( int i = 0; i < this->size; i = i + 1 )
			cout << i + 1 << ": " << num_lines_for_pos( i + 1 ) << "\n";
	}
};



int length_graph ( int a[] )
{
	int i = 0;

	while ( a[ i ] )
		i = i + 1;
	
	return i;
}

void permutations ( int a[] )
{
	int count = 0;

	for ( int i = 0; i < length_graph( a ) - 1; i = i + 1 )
		for ( int l = i + 1; l < length_graph( a ); l = l + 1 )
		{
			count = count + 1;
			cout << count << ": ";

			for ( int k = 0; k < length_graph( a ); k = k + 1 )
				cout << a[ k ] << ' ';
			cout << "\n";


			int b = a[ i ];
			a[ i ] = a[ l ];
			a[ l ] = b;
		}
}


