
class Point
{
  private:

	float x;
	float y;


  public:

	Point (){}

	Point ( float x, float y ){ this->x = x; this->y = y; }



	// Setters



	void set_x ( float x ){ this->x = x; }
	void set_y ( float y ){ this->y = y; }



	// Getters



	float get_x() { return this->x; }
	float get_y() { return this->y; }




	// Info



	void info()
	{
		cout << "x = " << this->get_x() << ", y = " << this->get_y();
	}
};




float distance ( Point a, Point b )
{
	float xa = a.get_x();
	float ya = a.get_y();
	float xb = b.get_x();
	float yb = b.get_y();

	return sqrt( ( xa - xb )*( xa - xb ) + ( ya - yb )*( ya - yb ) );
}


float area3 ( Point a1, Point a2, Point a3 )
{
	float l1 = distance( a1, a2 );
	float l2 = distance( a3, a2 );
	float l3 = distance( a3, a1 );

	float p = ( l1 + l2 + l3 ) / 2;

	return sqrt( p*( p - l1 )*( p - l2 )*( p - l3 ) );
}


class Shape
{
  private:

	Point p[ 1000 ] = {};
	int size;

	int length( Point p[] )
	{
		int i = 0;

		while ( p[ i ].get_x() != 0 )
			i = i + 1;

		return i;
	}

  public:

	Shape (){}

	Shape ( Point p[], int size )
	{
		for ( int i = 0; i < size; i = i + 1 )
			this->p[ i ] = p[ i ];

		this->size = size;
	}




	// Getters




	int get_size (){ return this->size; }
	void get_points ( Point p[] )
	{
		for ( int i = 0; i < this->size; i = i + 1 )
			p[ i ] = this->p[ i ];
	}




	// Setters




	void set_size ( int size ){ this->size = size; }
	void set_points ( Point p[] )
	{
		for ( int i = 0; i < this->size; i = i + 1 )
			this->p[ i ] = p[ i ];
	}





	// perimeter
	float perimeter ()
	{
		float perim = 0;

		for ( int i = 1; i < this->size; i = i + 1 )
			perim = perim + distance( p[ i ], p[ i - 1 ] );

		perim = perim + distance( p[ this->size - 1 ], p[ 0 ] );

		return perim;
	}

	

	

	// area
	float area ()
	{
		float ar = 0;

		Point p[ 1000 ] = {};
		int center[ 1000 ] = {};


		int i = 0;
		while ( this->p[ i ].get_x() )
		{
			p[ i ] = this->p[ i ];
			center[ i ] = -1;
			i = i + 1;
		}


		while ( this->length( p ) > 2 )
		{
			int size = this->length( p );

			if ( size > this->size )
				size = this->size;

			// cout << "size: " << size << " ";

			for ( i = 0; i + 2 < size; i = i + 2 )
			{
				// cout << i << ", ";

				ar = ar + area3( p[ i ], p[ i + 1 ], p[ i + 2 ] );

				center[ i + 1 ] = 1;
			}

			// i = i - 2;

			int count_center = 0;
			for ( int i = 0; i < this->size; i = i + 1 )			
				if ( center[ i ] == -1 )
					count_center = count_center + 1;

			if ( center[ size - 1 ] != 1 and i != size - 1 and count_center > 1 )
			{
				// cout << "center: " << i << ", ";

				ar = ar + area3( p[ i ], p[ size - 1 ], p[ 0 ] );
				center[ size - 1 ] = 1;
			}


			i = 0;
			Point pt[ 1000 ] = {};
			int l = 0;
			while ( p[ i ].get_x() )
			{
				if ( i >= this->size )
					break;

				if ( center[ i ] == 1 ) 
				{
					i = i + 1;
					continue;
				}

				pt[ l ] = p[ i ];
				i = i + 1;
				l = l + 1;
			}
			pt[ l ] = Point( 0, 0 );

			i = 0;
			while ( pt[ i ].get_x() )
			{
				p[ i ] = pt[ i ];
				i = i + 1;
			}
			p[ i ] = Point( 0, 0 );


			// for ( int i = 0; i < length( p ); i = i + 1 )
			//	p[ i ].info();
			// cout << "\n";

		}

		return ar;
	}


	void info ()
	{
		cout << "size = " << this->size << ", points = ";
		for ( int i = 0; i < this->size; i = i + 1 )
			cout << "[ " << this->p[ i ].get_x() << ", " << this->p[ i ].get_y() << " ]";
	}
};






class Line 
{
  private:

	float a;
	float b;
	float c;


  public:

	Line (){}

	Line ( float a, float b, float c )
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	Line ( float x, float y )
	{
		this->a = x;
		this->b = -1;
		this->c = y;
	}



	// Getters



	float get_a (){ return this->a; }
	float get_b (){ return this->b; }
	float get_c (){ return this->c; }



	// Setters



	void set_a ( float a ){ this->a = a; }
	void set_b ( float b ){ this->b = b; }
	void set_c ( float c ){ this->c = c; }



	bool is_on_this_line ( Point x )
	{
		if ( a * x.get_x() + b * x.get_y() + c != 0 )
			return false;

		return true;
	}


	float get_y ( float x )
	{
		float y = ( -this->a/this->b ) * x - this->c/this->b;

		return y;
	}

	Point get_point_x ( float x )
	{
		float y = ( -this->a/this->b ) * x - this->c/this->b;

		return Point( x, y );
	}

	Point get_point_y ( float y )
	{
		float x = ( -this->b/this->a ) * y - this->c/this->a;

		return Point( x, y );
	}


	void info ()
	{
		cout << this->a << "x + " << this->b << "y + " << this->c;
	}
};



class Segment
{
  private:

	float l;
	float r;
	Line line;

  public:

	Segment ( Line line, float l, float r ) 
	{
		this->line = line;

		if ( l < r )
		{
			this->l = l;
			this->r = r;
		}
		else
		{
			this->l = r;
			this->r = l;
		}
	}

	

	// Getters



	float get_l () { return this->l; }
	float get_r () { return this->r; }



	// Setters



	void set_l ( float l ) { if( l > this->r ) return; this->l = l; }
	void set_r ( float r ) { if( this->l > r ) return; this->r = r; }




	Point middle ()
	{
		float x = ( this->l + this->r ) / 2;
		float y = ( line.get_y( this->l ) + line.get_y( this->r ) ) / 2;

		return Point( x, y );
	}

	Point middle ( float divide )
	{
		float x = ( this->l + this->r ) / divide;
		float y = ( line.get_y( this->l ) + line.get_y( this->r ) ) / divide;

		return Point( x, y );
	}

	float length ()
	{
		return distance(  Point( this->l, line.get_y( this->l ) ), Point( this->r, line.get_y( this->r ) )  );
	}


	void info ()
	{
		cout << line.get_a() << "x + " << line.get_b() << "y + " << line.get_c() << " / ";
		cout << "l = " << this->l << ", r = " << this->r;
	}
};


// ax + by + c = 0

// y1 = -b1/a1 x - c1/b1
// y2 = -b2/a2 x - c2/b2

// b1/a1 x + c1/b1 = b2/a2 x + c2/b2

// x = ( c2/b2 - c1/b1 ) / ( b1/a1 - b2/a2 )

Point line_union ( Line l1, Line l2 )
{
	float x = ( l2.get_c()/l2.get_b() - l1.get_c()/l1.get_b() ) / ( l1.get_b()/l1.get_a() - l2.get_b()/l2.get_a() );

	float y = l1.get_y( x );

	return Point ( x, y );
}


// Traingle
bool triangle ( double a1, double a2, double a3 )
{
	if ( a1 + a2 > a3 and a3 + a1 > a2 and a3 + a2 > a1 )
		return true;

	return false;
}

bool triangle ( Shape s )
{
	if ( s.get_size() != 3 )
		return false;

	Point p[ 1000 ];
	s.get_points( p );

	double l1 = distance( p[0], p[1] );
	double l2 = distance( p[1], p[2] );
	double l3 = distance( p[2], p[0] );
	
	return triangle( l1, l2, l3 );
}

bool pitagora ( double a1, double a2, double a3 )
{
	if ( ! triangle( a1, a2, a3 ) )
		return false;

	double a[ 5 ] = { a1, a2, a3 };

	if ( a[0]*a[0] + a[1]*a[1] == a[2]*a[2] )
		return true;
	
	if ( a[1]*a[1] + a[2]*a[2] == a[0]*a[0] )
		return true;
	
	if ( a[2]*a[2] + a[0]*a[0] == a[1]*a[1] )
		return true;
	
	return false;
}

bool pitagora ( Shape s )
{
	if ( s.get_size() != 3 )
		return false;

	Point p[ 1000 ];
	s.get_points( p );


	double l1 = distance( p[0], p[1] );
	double l2 = distance( p[1], p[2] );
	double l3 = distance( p[2], p[0] );
	
	return pitagora( l1, l2, l3 );
}


bool isoscel ( double a1, double a2, double a3 )
{
	if ( ! triangle( a1, a2, a3 ) )
		return false;

	if ( a1 == a2 or a3 == a1 or a2 == a3 )
		return true;

	return false;
}


bool isoscel ( Shape s )
{
	if ( s.get_size() != 3 )
		return false;

	Point p[ 1000 ];
	s.get_points( p );


	double l1 = distance( p[0], p[1] );
	double l2 = distance( p[1], p[2] );
	double l3 = distance( p[2], p[0] );
	
	return isoscel( l1, l2, l3 );
}

bool echilateral ( double a1, double a2, double a3 )
{
	if ( ! triangle( a1, a2, a3 ) )
		return false;

	if ( a1 == a2 and a2 == a3 )
		return true;

	return false;	
}

bool echilateral ( Shape s )
{
	if ( s.get_size() != 3 )
		return false;

	Point p[ 1000 ];
	s.get_points( p );


	double l1 = distance( p[0], p[1] );
	double l2 = distance( p[1], p[2] );
	double l3 = distance( p[2], p[0] );
	
	return echilateral( l1, l2, l3 );
}









