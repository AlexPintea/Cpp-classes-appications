
class Counter 
{
	int counter;
	string filename;

	// clears a file
	void clear_file ()
	{
		ofstream f; // have to have ofstream
		f.open( this->filename );
		f.close();
	}

	// makes file that stores our counter
	void make_count_file ()
	{
		ofstream f;
		f.open( this->filename );
		f << 0;
		f.close();
	}

	// get the count stored in the counter file
	void get_file_count()
	{
		fstream f;
		f.open( this->filename );
		f >> this->counter;
		f.close();
	}

  public:

	Counter ()
	{
		this->counter = 0;
		this->filename = "";
	}

	Counter ( string data )
	{
		this->filename = data;
		get_file_count();
	}

	Counter ( int data )
	{
		this->counter = 0;
		this->counter = data;
	}

	Counter ( int data_int, string data_string )
	{
		this->counter = data_int;
		this->filename = data_string;
	}




	// Count




	// increases and saves counter in count file
	void count()
	{
		get_file_count();

		make_count_file();
		clear_file (  );
		make_count_file();

		ofstream f;
		f.open( this->filename );
		this->counter = this->counter + 1;
		f << this->counter;
		f.close();
	}

	// increases by data and saves counter in count file
	void count( int data )
	{
		get_file_count();

		make_count_file();
		clear_file (  );
		make_count_file();

		ofstream f;
		f.open( this->filename );
		this->counter = this->counter + data;
		f << this->counter;
		f.close();
	}

	// decreases and saves counter in count file
	void count_reverse()
	{
		get_file_count();

		make_count_file();
		clear_file (  );
		make_count_file();

		ofstream f;
		f.open( this->filename );
		this->counter = this->counter - 1;
		f << this->counter;
		f.close();
	}

	// decreases by data and saves counter in count file
	void count_reverse( int data )
	{
		get_file_count();

		make_count_file();
		clear_file (  );
		make_count_file();

		ofstream f;
		f.open( this->filename );
		this->counter = this->counter - data;
		f << this->counter;
		f.close();
	}




	// Setters




	// set count to data
	void set_count( int data )
	{
		make_count_file();
		clear_file ();
		make_count_file();

		ofstream f;
		f.open( this->filename );
		this->counter = data;
		f << this->counter;
		f.close();
	}

	// set filename to data
	void set_filename( string data )
	{
		this->filename = data;
	}




	// Getters




	// returns the counter
	int get_count()
	{
		get_file_count();

		return this->counter;
	}

	// get the count stored in the counter file
	string get_filename()
	{
		return this->filename;
	}




	// Reset




	// reset counter
	void reset()
	{
		this->counter = 0;
		make_count_file();
		clear_file();
		make_count_file();
	}




	// Inittialise




	// initialise counter
	void init( string data )
	{
		this->set_filename ( data );
		this->get_count();
	}




	// Rename




	// rename counter
	void rename( string data )
	{
		this->set_filename ( data );

		ofstream f;
		f.open( this->filename );
		f << this->counter;
		f.close();
	}

};

