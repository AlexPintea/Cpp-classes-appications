#define get_name(Variable) ( #Variable )

// Multi_string
class Multi_String 
{
	string multi_string;



	// Leave types



	// leave chars in a string to leave only $#$%!#
	string leave_chars_inner ( string a )
	{
		int size = a.length();

		string result = " ";

		for ( int i=0; i<size; i=i+1 )
		{
			if ( !( ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) or ( a[i] >= '0' and a[i] <= '9' ) ) and a[i] != ' ' )
				result = result + a[i];
			if ( a[i] == ' ' and result[ result.length() - 1 ] != ' ' )
				result = result + ' ';
		}

		return result;
	}

	// leaves numerics in a string
	string leave_numerics_inner ( string a )
	{
		int size = a.length();

		string result = " ";

		for ( int i=0; i<size; i=i+1 )
		{
			if ( a[i] >= '0' and a[i] <= '9' )
				result = result + a[i];
			if ( a[i] == ' ' and result[ result.length() - 1 ] != ' ' )
				result = result + ' ';
		}

		return result;
	}

	// leaves words in a string ( a, b, l,  etc. )
	string leave_words_inner ( string a )
	{
		int size = a.length();

		string result = " ";

		for ( int i=0; i<size; i=i+1 )
		{
			if ( ( a[i] >= 'a' and a[i] <= 'z' ) or ( a[i] >= 'A' and a[i] <= 'Z' ) )
				result = result + a[i];
			if ( a[i] == ' ' and result[ result.length() - 1 ] != ' ' )
				result = result + ' ';
		}

		return result;
	}




	// Check if an entry in in the string




	// removes a char in a string
	void remove_char_inner( string &a, int iter )
	{
		if ( iter < 0 or iter >=a.length() )
			return;

		int size = a.length();

		string result = "";

		for ( int i=0; i<size; i=i+1 )
			if ( i != iter )
				result = result + a[i];

		a = result;
	}

	// check if an entry in in the multi_string, return where if the cae
	int is_in_multi_string ( string name, string type )
	{
		string name_type = name + " " + type;

		for ( int i=0; i<this->multi_string.length() ;i=i+1 )
			if ( this->multi_string[i] == name_type[0] )
			{
				bool is_name_type = true;

				for ( int l=1; l<name_type.length(); l=l+1 )
					if ( this->multi_string[ l + i ] != name_type[l] )
					{
						is_name_type = false;
						break;
					}

				if ( is_name_type )
					return i;
			}

		return false;
	}



	// Convert long string



	// inverts a string
	void invert_string_inner( string &a )
	{
		int size = a.length();

		string b = "";

		for ( int i=size-1; i>=0; i=i-1 )
			b = b + a[i];

		a = b;
	}

	// check if a string is a long
	bool is_long_inner ( string a )
	{
		int size = a.length();

		if ( size > 19 and a[0] == '-' )
			return false;
		if ( size >= 19 and a[0] != '-' )
			return false;

		for ( int i=0; i<size; i=i+1 )
			if ( !( (a[i] >= '0' and a[i] <= '9') or a[i] == '-' )  )
				return false;

		return true;
	}

	// converts an long to a string
	string long_to_string_inner (long a)
	{
		int size = length_inner(a);

		bool is_neg = false;
		if ( a < 0 )
		{
			is_neg = true;
			a = -a;
		}

		string result = "";

		for (int i=0; i<size; i=i+1)
		{		
			char a_char = (char) (a % 10 + 48);

			if ( a_char >= '0' and a_char <= '9' )
				result = result + a_char;
			a = a / 10;
		}

		if ( is_neg )
			result = result + '-';

		invert_string_inner( result );

		return result;
	}

	// convert string to long
	long string_to_long_inner ( string a )
	{
		if ( a.length() == 1 )
			return a[0] - 48;

		int size = a.length();

		int iter = 0;
		bool is_neg = false;
		if ( a[0] == '-' )
		{
			is_neg = true;
			iter = 1;
		}

		long num_long = 0;

		for ( int i=iter; i<size; i=i+1 )
			num_long = num_long * 10 + ( a[i] - 48 );

		if ( is_neg )
			num_long = -num_long;

		return num_long;
	}



	
	// Convert bool string



	
	string bool_to_string_inner( bool a )
	{
		if ( a == 1 )
			return "true";

		return "flase";
	}

	bool string_to_bool_inner ( string a )
	{
		if ( a == "1" or a == "true" )
			return true;

		return false;
	}



	// Convert double string



	// length_inner of a long
	int length_inner(long a)
	{
		if (a == 0)
			return 1;

		int i=0;

		while ( a != '\0' )
		{
			i=i+1;
			a=a/10;
		}

		return i;
	}


	// length_inner of a string[]
	int length_inner ( string a[] )
	{

		int i=0;

		while ( a[i].length() > 0 )
		{
			i=i+1;
		}

		return i;
	}

	// digits_inner of a long
	void digits_inner ( long a, char num_digits_inner[] )
	{
		int size = length_inner(a);

		for ( int i=0; i<size; i=i+1 )
		{
			num_digits_inner[ size - i - 1 ] = (int) (a%10) + 48;
			a = a / 10;
		}
	}

	// converts a double to a string with a certain precision
	string double_to_string_inner ( double a )
	{
		bool is_neg = false;
		if ( a < 0 )
			is_neg = true;

		int iter = length_inner( (long) a );

		while ( ( (float) a - (long) a ) != 0.0 )
			a = a * 10;


		long a_as_long;

		if ( is_neg )
			a_as_long = -(long) a;
		else
			a_as_long = (long) a;


		char digits_inner_a[1000];
		digits_inner( a_as_long, digits_inner_a );

		string result = "";
		if ( is_neg )
			result = result + '-';
		for ( int i=0; i<length_inner( a_as_long ); i=i+1 )
		{
			if ( i == iter )
				result = result + '.';

			result = result + digits_inner_a[i];
		}

		return result;
	}
	// convert string to double
	double string_to_double_inner ( string a )
	{
		if ( a.length() == 1 )
			return a[0] - 48;

		if ( is_long_inner( a ) )
			return string_to_long_inner(a);


		double num_double = 0;

		int i = 0;
		bool is_neg = false;
		if ( a[0] == '-' )
		{
			is_neg = true;
			i = 1;
		}


		while ( a[i] != '.' )
		{
			num_double = num_double * 10 + ( a[i] - 48 );
			i = i + 1;
		}

		i = i + 1;
		int decimal_tens = 10;

		while ( a[i] )
		{
			double temp = a[i] - 48;
			num_double = num_double + temp / decimal_tens ;
			decimal_tens = decimal_tens * 10;
			i = i + 1;
		}

		if ( is_neg )
			num_double = -num_double;

		return num_double;
	}


  public:

	Multi_String ()
	{
		this->multi_string = "";
	}

	Multi_String ( string data )
	{
		this->multi_string = data;
	}


	// set / get multi_string


	void set_multi_string( string data )
	{
		this->multi_string = data;
	}

	string get_multi_string()
	{
		return this->multi_string;
	}



	// Make type entries


	void make_types ()
	{
		string data = this->multi_string;
		this->multi_string = "";

		this->multi_string = this->multi_string + "words string  " + leave_words_inner( data ) + "\n";
		this->multi_string = this->multi_string + "numerics double  " + leave_numerics_inner( data ) + "\n";
		this->multi_string = this->multi_string + "chars char  " + leave_chars_inner( data ) + "\n";
	}



	// Add an entry



	void add ( string a[], string name )
	{
		if ( is_in_multi_string( name, "string" ) )
		{
			cout << "Could not store \"" << name << " string\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " string   ";

		int i=0;
		while ( a[i].length() > 0 )
		{
			this->multi_string = this->multi_string + a[i] + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( string a, string name ) // only stores with 1 ' ' sep.
	{
		if ( is_in_multi_string( name, "string" ) )
		{
			cout << "Could not store \"" << name << " long\", name and type are already set.\n";
			return;
		}

		for ( int i=1; i<a.length(); i=i+1 ) // only stores with 1 ' ' sep.
			if ( a[i] == ' ' and a[i-1] == ' ' )
			{
				remove_char_inner( a, i );
				i = i - 1;
			}

		string a_strings[10];
		a_strings[0] = a;
		add( a_strings, name );
	}

	void add ( long a[], string name )
	{
		if ( is_in_multi_string( name, "long" ) )
		{
			cout << "Could not store \"" << name << " long\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " long   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + long_to_string_inner( a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( long a, string name )
	{
		if ( is_in_multi_string( name, "long" ) )
		{
			cout << "Could not store \"" << name << " long\", name and type are already set.\n";
			return;
		}

		long a_longs[10];
		a_longs[0] = a;
		a_longs[1] = '\0';
		add( a_longs, name );
	}

	void add ( int a[], string name )
	{
		if ( is_in_multi_string( name, "int" ) )
		{
			cout << "Could not store \"" << name << " int\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " int   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + long_to_string_inner( (long) a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( int a, string name )
	{
		if ( is_in_multi_string( name, "int" ) )
		{
			cout << "Could not store \"" << name << " int\", name and type are already set.\n";
			return;
		}

		int a_ints[10];
		a_ints[0] = a;
		a_ints[1] = '\0';
		add( a_ints, name );
	}

	void add ( bool a[], string name )
	{
		if ( is_in_multi_string( name, "bool" ) )
		{
			cout << "Could not store \"" << name << " bool\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " bool   ";

		int i=0;
		while ( a[i] ) // does not store "false"
		{
			this->multi_string = this->multi_string + bool_to_string_inner( a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( bool a, string name )
	{
		if ( is_in_multi_string( name, "bool" ) )
		{
			cout << "Could not store \"" << name << " bool\", name and type are already set.\n";
			return;
		}

		bool a_bools[10];
		a_bools[0] = a; // does not store "false" 
		a_bools[1] = '\0';
		add( a_bools, name );
	}



	void add ( double a[], string name )
	{
		if ( is_in_multi_string( name, "double" ) )
		{
			cout << "Could not store \"" << name << " double\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " double   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + double_to_string_inner( a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( double a, string name )
	{
		if ( is_in_multi_string( name, "double" ) )
		{
			cout << "Could not store \"" << name << " double\", name and type are already set.\n";
			return;
		}

		double a_doubles[10];
		a_doubles[0] = a;
		a_doubles[1] = '\0';
		add( a_doubles, name );
	}


	void add ( float a[], string name )
	{
		if ( is_in_multi_string( name, "float" ) )
		{
			cout << "Could not store \"" << name << " float\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " float   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + double_to_string_inner( (float) a[i] ) + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( float a, string name )
	{
		if ( is_in_multi_string( name, "float" ) )
		{
			cout << "Could not store \"" << name << " float\", name and type are already set.\n";
			return;
		}

		float a_floats[10];
		a_floats[0] = a;
		a_floats[1] = '\0';
		add( a_floats, name );
	}


	void add ( char a[], string name )
	{
		if ( is_in_multi_string( name, "char" ) )
		{
			cout << "Could not store \"" << name << " char\", name and type are already set.\n";
			return;
		}

		this->multi_string = this->multi_string + name + " char   ";

		int i=0;
		while ( a[i] )
		{
			this->multi_string = this->multi_string + a[i] + " ";
			i = i + 1;
		}
		this->multi_string = this->multi_string + "\n";
	}

	void add ( char a, string name )
	{
		if ( is_in_multi_string( name, "char" ) )
		{
			cout << "Could not store \"" << name << " char\", name and type are already set.\n";
			return;
		}

		char a_chars[10];
		a_chars[0] = a;
		a_chars[1] = '\0';
		add( a_chars, name );
	}



	// Get an entry



	void get ( string name, string type, string result[] )
	{
		// clears the result
		for ( int i=0; i<length_inner( result ); i=i+1 )
			result[i] = '\0';

		string name_type = name + ' ' + type;

		int iter = is_in_multi_string( name, type );

		int i=iter; // multi_string
		for ( int l=0; l<2; l=l )
		{
			if ( this->multi_string[i] == ' ' )
				l = l + 1;
			i = i + 1;
		}
		i = i + 1;
		
		int result_counter = 0;
		string temp = "";
		while ( this->multi_string[i] != '\n' )
		{
			temp = temp + this->multi_string[i];
			i = i + 1;
			if ( this->multi_string[i] == ' ' )
			{
				remove_char_inner( temp, 0 );

				result[ result_counter ] = temp;
				result_counter = result_counter + 1;
				temp = "";
			}
		}
	}

	void get ( string name, string type, string &result )
	{
		string result_strings[10];
		get( name, type, result_strings );

		result = "";
		for ( int i=0; i<length_inner( result_strings ); i=i+1 )
			result = result + result_strings[i] + " ";
	}

	void get ( string name, string type, long result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length_inner( result_string ); i=i+1 )
			result[i] = string_to_long_inner( result_string[i] );
	}

	void get ( string name, string type, long &result )
	{
		long result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}

	void get ( string name, string type, int result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length_inner( result_string ); i=i+1 )
			result[i] = (int) string_to_long_inner( result_string[i] );
	}

	void get ( string name, string type, int &result )
	{
		int result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}

	void get ( string name, string type, bool result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length_inner( result_string ); i=i+1 )
			result[i] = string_to_bool_inner( result_string[i] );
	}

	void get ( string name, string type, bool &result )
	{
		bool result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}

	void get ( string name, string type, double result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length_inner( result_string ); i=i+1 )
			result[i] = string_to_double_inner( result_string[i] );
	}

	void get ( string name, string type, double &result )
	{
		double result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}


	void get ( string name, string type, float result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length_inner( result_string ); i=i+1 )
			result[i] = (float) string_to_double_inner( result_string[i] );
	}

	void get ( string name, string type, float &result )
	{
		float result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}


	void get ( string name, string type, char result[] )
	{
		string result_string[1000];
		get( name, type, result_string );

		for ( int i=0; i<length_inner( result_string ); i=i+1 )
			result[i] = result_string[i][0];
	}

	void get ( string name, string type, char &result )
	{
		char result_string[1000];
		get( name, type, result_string );

		result = result_string[0];
	}



	// Remove an entry



	void del ( string name_of_store, string type )
	{
		string data = this->multi_string;
		this->multi_string = "";

		name_of_store = name_of_store + " " + type;

		for ( int i=0; i<data.length(); i=i+1 )
		{
			if ( data[i] == name_of_store[0] and data[i-1] == '\n' )
			{
				bool is_name = true;

				for ( int l=1; l<name_of_store.length(); l=l+1 )
					if ( data[ l + i ] != name_of_store[l] )
					{
						is_name = false;
						break;
					}

				if ( is_name )
					while ( data[i] != '\n' )
						i = i + 1;
			}

			this->multi_string = this->multi_string + data[i];
		}


		// remove '\n' of removed
		for ( int i=1; i<this->multi_string.length(); i=i+1 )
			if ( this->multi_string[i-1] == '\n' and this->multi_string[i] == '\n' )
			{
				remove_char_inner( this->multi_string, i );
				i = i - 1;
			}
	}



	// Show multi_string



	void show_multi_string ()
	{
		cout << "\n" << this->multi_string << "\n";
	}




	// Save multi_string in a file



	void save( string filename )
	{
		// make / clear the file
		ofstream fo;
		fo.open( filename );
		fo.close();

		fo.open( filename );
		fo << this->multi_string;
		fo.close();
	}

	void get_saved( string filename )
	{
		ifstream fi;
		fi.open( filename );

		this->multi_string = "";

		string temp;
		while ( getline( fi, temp ) )
			this->multi_string = this->multi_string + temp + "\n";

		fi.close();
		
	}

};







