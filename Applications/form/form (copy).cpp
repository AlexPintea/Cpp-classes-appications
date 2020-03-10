#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;

string name;

string filename;


// file you are editing
ofstream file;


struct Data
{
	string name;
	int type;
} data[ 70 ];

int num_data = 0;


// You are able to make:  Choice, Line, Slider


struct Choice
{
	int num; // how many choices
	string item[ 70 ];
	bool more;
} choices[ 70 ];

int num_choice = 0;


string lines[ 1000 ];

int num_line = 0;

struct Slider
{
	double a;
	double b;
} sliders[ 90 ];

int num_slider = 0;





// Make choices




// makes a choice in file
void make_choice( Choice a, string name )
{
	file << "\n// Getting data for " << name << "\n";
	file << "void get_" << name << "()\n";
	file << "{\n";

	if ( a.more == true )
	{
		file << "	cout << \"Enter choice / choices for [ " << name << " ]:\\n\";\n";
		file << "	int choices[ 70 ];\n\n";
		for ( int i=0; i<a.num; i=i+1 )
			file << "	cout << \"(" << i + 1 << ") " << a.item[i] << "\\n\";\n";
		file << "\n	cout << \"Enter your choices. Stop with -1.\\n\";\n";		
		file << "	int iter=0;\n\n";		
		file << "	while ( choices[ iter ] != -1 )\n";
		file << "	{\n";
		file << "		cout << \"Enter choice: \";\n";
		file << "		cin >> choices[i];\n";
		file << "		iter = iter + 1;\n";
		file << "	}\n\n";
		file << "	iter = iter - 1;\n\n";
		file << "	datafile << \"[\" << " << name << " << \"] - choices: \";\n\n";
		file << "	for ( int i=0; i<iter; i=i+1 )\n";
		file << "		datafile << choices[i] << \" \";\n";
		file << "	datafile << \"\\n\";\n";
	}

	if ( a.more == false )
	{
		file << "	cout << \"Enter choice for [ " << name << " ]:\\n\";\n";
		file << "	int choice;\n\n";
		for ( int i=0; i<a.num; i=i+1 )
			file << "	cout << \"(" << i + 1 << ") " << a.item[i] << "\\n\";\n";
		file << "	cout << \"Enter choice: \";\n";
		file << "\n	cin >> choice;\n";
		file << "	datafile << \"[" << name << "]\" - choice: \" << choice << \"\\n\";\n";
	}

	file << "}\n\n";

}

// make line
void make_line ( string name )
{
	file << "\n// Getting data for " << name << "\n";
	file << "void get_" << name << "()\n";
	file << "{\n";
	file << "	string data_string;\n";
	file << "	cout << \"Enter [ " << name << " ]: \";";
	file << "	getline( cin, data_string );\n";
	file << "	datafile << \"[" << name << "]\" - choice: \" << choice << \"\\n\";\n";
	file << "}\n\n";
}

// make slider
void make_slider ( Slider a, string name )
{
	file << "\n// Getting data for " << name << "\n";
	file << "void get_" << name << "()\n";
	file << "{\n";
	file << "	int a, b; // slider bounds\n";
	file << "	cout << \"Enter [ " << name << " ] slider bound 1 ( small ): \";";
	file << "	cin >> a;\n";
	file << "	cout << \"Enter [ " << name << " ] slider bound 2 ( large ): \";";
	file << "	cin >> b;\n";
	file << "	datafile << \"[" << name << "]\" - slider: \" << a << \" \" << b << \"\\n\";\n";
	file << "}\n\n";
}

// replaces spaces in a string
void replace_space( string &a )
{
	int size = a.length();

	for ( int i=0; i<size; i=i+1 )
		if ( a[i] == ' ' )
			a[i] = '_';
}

int main ()
{

	cout << "Enter a filename that is not in this folder: ";
	getline( cin, name );

	
	filename = name + ".cpp";

	cout << "Num. of data you want to get: ";
	cin >> num_data;

	for ( int i=0; i<num_data; i=i+1 )
	{
		cout << "Name of data (" << i + 1 << "): ";
		getline( cin, data[i].name );
		if ( i == 0 )
			getline( cin, data[i].name );
	}

	string choice = "";
	for ( int i=0; i<num_data; i=i+1 )
	{
		cout << "Get data (" << i + 1 << "):\n";
		cout << "  1. Choice   2. Line   3. Slider  4. More Choices";

		cout << "Your choice: ";
		getline( cin, choice );



		if ( !( choice[0] >= '1' and choice[0] <= '9' and choice.length() == 1 ) )
		{
//			cout << "Invalid choice for getting data (" << i + 1 << "): " << data[i] << ". Retry.\n\n";
			cout << "Invalid choice. Retry.\n\n";

			if ( i != 0 )
				i = i - 1;

			continue;
		}


		// Choice
		if ( choice == "1" )
		{
			data[i].type = 14;			

			Choice a;

			a.more = false;

			cout << "Enter num. choices: ";
			cin >> a.num;
			for ( int i=0; i<a.num; i=i+1 )
			{
				cout << "Choice num. (" << i + 1 << "): ";
				getline( cin, a.item[i] );
			}

			choices[ num_choice ] = a;
			num_choice = num_choice + 1;
		}

		// Line
		if ( choice == "2" )
		{
			data[i].type = 2;

			cout << "Line was added with the name you gave to data (" << i + 1 << "): " << data[i].name << "\n";

			lines[ num_line ] = data[i].name;
			num_line = num_line + 1;
		}

		// Slider
		if ( choice == "3" )
		{
			data[i].type = 3;

			Slider a;
			cout << "Enter bound 1 ( smaller ): \n";
			cin >> a.a;
			cout << "Enter bound 1 ( larger ): \n";
			cin >> a.b;

			sliders[ num_slider ] = a;
			num_slider = num_slider + 1;
		}

		// More Choices
		if ( choice == "4" )
		{
			data[i].type = 14;			

			Choice a;

			a.more = true;

			cout << "Enter num. choices: ";
			cin >> a.num;
			for ( int i=0; i<a.num; i=i+1 )
			{
				cout << "Choice num. (" << i + 1 << "): ";
				getline( cin, a.item[i] );
			}

			choices[ num_choice ] = a;

			num_choice = num_choice + 1;
		}


	}

	file.open( filename );

	file << "#include <string>\n#include <fstream>\n#include <string.h>\n#include <iostream>\n\nusing namespace std;\n\n";

	int choice_counter = 0;
	int line_counter = 0;
	int slider_counter = 0;

	for ( int i=0; i<num_data; i=i+1 )
	{
		if ( data[i].type == 14 )
		{
			make_choice( choices[ choice_counter ], data[i].name );
			choice_counter = choice_counter + 1;
		}

		if ( data[i].type == 2 )
		{
			make_line( lines[ line_counter ] ); // lines[] store data.name-s
			line_counter = line_counter + 1;
		}

		if ( data[i].type == 3 )
		{
			make_slider( sliders[ slider_counter ], data[i].name );
			slider_counter = slider_counter + 1;
		}
	}

	file << "int main()\n";
	file << "{\n";

	file << "	ofstream datafile;\n";
	file << "	datafile.open( \"data\" );\n\n";

	file << "	cout << \"" << name << ":\\n\\n\";\n\n";

	file << "	// Getting data\n";
	for ( int i=0; i<num_data; i=i+1 )
		file << "	get_" << data[i].name << "();\n";


	file << "	datafile.close();\n";
	file.close();

	return 0;
}
