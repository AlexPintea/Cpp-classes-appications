class Solid 
{
  private:

	double v = 0;
	double d = 0;

	double l = -1; // depth
	double w = -1;
	double h = -1;

  public: 

	Solid ()
	{
		this->v = 0;
		this->d = 0;
	}

	Solid ( double v, double d )
	{
		this->v = v;
		this->d = d;
	}

	Solid ( double w, double h, double l, double d )
	{
		this->v = w * h * l;
		this->d = d;

		this->w = w;
		this->h = h;
		this->l = l;
	}

	double get_v () { return this->v; }
	double get_d () { return this->d; }

	double get_depth () { return this->l; }
	double get_width () { return this->w; }
	double get_height () { return this->h; }

	void set_v ( double v ) { this->v = v; }
	void set_d ( double d ) { this->d = d; }

	void set_depth ( double l )
	{
		this->l = l; if ( this->is_rectangle() ) this->v = w * h * l; 
		else { this->w = l; this->h = l; this->v = w * h * l; } 
	}
	void set_width ( double w )
	{
		this->w = w; if ( this->is_rectangle() ) this->v = w * h * l; 
		else { this->l = w; this->h = w; this->v = w * h * l; } 
	}
	void set_height ( double h )
	{
		this->h = h; if ( this->is_rectangle() ) this->v = w * h * l; 
		else { this->w = h; this->l = h; this->v = w * h * l; } 
	}

	double get_mass () { return d * v; }
	double get_weight () { return d * v * 9.8; }


	bool is_rectangle ()
	{
		if ( l == -1 ) return 0;
		if ( w == -1 ) return 0;
		if ( h == -1 ) return 0;
		return 1;
	}

	double get_areas ( double areas[] )
	{
		areas[ 0 ] = l * h;
		areas[ 1 ] = l * w;
		areas[ 2 ] = w * h;
	}

	void info ()
	{
		if ( is_rectangle() )
		{
			cout << "w = " << w << ", ";
			cout << "h = " << h << ", ";
			cout << "d = " << l << ", ";
			cout << "v = " << v << ", ";
			cout << "density = " << d << '\n';
		}
		else
		{
			cout << "v = " << v << ", ";
			cout << "density = " << d << '\n';
		}
	}
};



class Lens 
{
  private:
	double f;
  public:

	Lens() { this->f = 0; }

	Lens( double f ) { this->f = f;	}

	double get_f () { return f; }
 	void set_f () { this->f = f; }

	double get_convergence () { return 1 / f; }

	void get_position ( double &x, double &y )
	{
		x = 1 / ( 1 / f - 1 / x );
		y = 1 / ( 1 / f - 1 / y );
	}

	void info ()
	{
		cout << "f = " << f << '\n';
	}
};


class Linear 
{

  private:
	double v;
  public:

	Linear () { this->v = 0; }
	Linear ( double v ) { this->v = v; }

	double get_v () { return this->v; }
	void set_v ( double v ) { this->v = v; }

	double get_distance ( double tme ) { return v * tme; }
	double get_time ( double d ) { return d / this->v; }

	void info () { cout << "v = " << v << '\n'; }
};
class Acl
{
  private:
	
	double v0;
	double a;

  public:

	Acl () { this->v0 = 0; this->a = 0; }
	Acl ( double a ) { this->v0 = 0; this->a = a; }
	Acl ( double v0, double a ) { this->v0 = v0; this->a = a; }

	double get_v0 () { return this->v0; }
	double get_a () { return this->a; }

	void set_v0 ( double v0 ) { this->v0 = v0; }
	void set_a ( double a ) { this->a = a; }

	double get_distance ( double tme ) 
	{
		double v = v0 + a * tme;
		return v * tme;
	}

	double get_time ( double d )
	{
		// a x tme x tme + v0 x tme - d = 0;
		double dl = sqrt( v0 * v0 - 4 * a * ( -d ) );
		double tme = ( -v0 + dl ) / ( 2 * a );
		return tme;
	}


	void info () { cout << "v0 = " << v0 << ", a = " << a << '\n'; }
};


class Calorimeter
{
  private:
	double coef;
	double m;
  public: 

	Calorimeter () { this->coef = 0; this->m = 0; }

	Calorimeter ( double coef, double m ) { this->coef = coef; this->m = m; }

	double get_coef () { return this->coef; }
	double get_m () { return this->m; }

	double set_coef ( double coef ) { this->coef = coef; }
	double set_m ( double m ) { this->m = m; }

	double get_Coef () { return this->coef * this->m; }
	void info () { cout << "coef = " << coef << ", m = " << m << '\n'; }
};





// class Refr
// {
//   private:
// 	double a;
// 	double b;
// 	double c;

// 	double m1;

// 	double get_slope () { return - a / b; }

//   public:

// 	Refr ( double a, double b, double c )
// 	{
// 		this->a = a;
// 		this->b = b;
// 		this->c = c;

// 		this->m1 = 1;
// 	}

// 	Refr ( double a, double b, double c, double m1 )
// 	{
// 		this->a = a;
// 		this->b = b;
// 		this->c = c;

// 		this->m1 = m1;
// 	}

// 	double get_a () { return this->a; }
// 	double get_b () { return this->b; }
// 	double get_c () { return this->c; }
// 	double get_m1 () { return this->m1; }

// 	void set_a ( double a ) { this->a = a; }
// 	void set_b ( double b ) { this->b = b; }
// 	void set_c ( double c ) { this->c = c; }
// 	void set_m1 ( double m1 ) { this->m1 = m1; }

// 	void refr ( double m2 )
// 	{
// 		double slope2 = m1 / m2 * get_slope();
// 		this->b = m1 / m2 * b;
// 		this->a = slope2 * ( -b );
// 	}

// 	double get_y ( double x, double m2 )
// 	{
// 		this->refr( m2 );
// 		return ( x * a + c ) / ( -b );
// 	}

// 	void info () { cout << a << "x + " << b << "y + " << c << " = 0, m1 = " << m1 << '\n'; }

// 	double get_ref ()
// 	{
// 		return -c/b;
// 	}
// };



class Electric
{
  private:
	int num;

  public:

	Electric () { this->num = 0; }
	Electric ( int num ) { this->num = num; }

	double get_num () { return this->num; }
	double set_num ( double num ) { this->num = num; }

	double get_intensity () { return this->num *10; }


	double get_tension ( double r ) { return r * get_intensity(); }

	double get_e ( double r ) { return get_intensity() * get_tension( r ) * r; }

	double get_magnetic () { return this->num; }

	void info () { cout << "num = " << num << '\n'; }
};






void get_reflection ( double &a ) { a = -a; }
