#include <string>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;


struct question
{
	string question;
	int iter = 0;
	string answers[ 100 ];
	bool valid[ 100 ];
};

char alph[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p' };

question exam[ 100 ];
int exam_iter = 0;

bool is_string_empty ( string a )
{
	for ( int i = 0; i < a.length(); i = i + 1 )
		if ( a[ i ] != ' ' and a[ i ] != '\n' and a[ i ] != '	' )
			return 0;

	return 1;
}

string remove_initial_char ( string p )
{
	string result = "";

	for ( int i = 1; i < p.length(); i = i + 1 )
		result = result + p[ i ];

	return result;
}

void get_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;

	bool have_question = 0;

	while ( getline( fi, temp ) )
	{
		if ( is_string_empty( temp ) )
		{
			if ( have_question == 1 )
			{
				have_question = 0;
				exam_iter = exam_iter + 1;
			}
			continue;
		}

		if ( temp[ 0 ] == ')' )
		{
			have_question = 1;

			exam[ exam_iter ].question = remove_initial_char( temp );

			continue;
		}

		if ( have_question )
		{
			if ( temp[ 0 ] == '/' )
			{
				exam[ exam_iter ].answers[ exam[ exam_iter ].iter ] = remove_initial_char( temp );
				exam[ exam_iter ].valid[ exam[ exam_iter ].iter ] = 1;
			}
			else
			{
				exam[ exam_iter ].answers[ exam[ exam_iter ].iter ] = temp;
				exam[ exam_iter ].valid[ exam[ exam_iter ].iter ] = 0;
			}

			exam[ exam_iter ].iter = exam[ exam_iter ].iter + 1;
		}
	}

	fi.close();
}

string get_data_file ( string filename )
{
	ifstream fi;
	fi.open( filename );

	string temp;
	string file = "";

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();

	return file;
}

void filename_ext_filepath ( string &filename, string &ext, string &filepath )
{
	ext = "";

	bool have_ext = false;
	for ( int i = 0; i < filename.length(); i = i + 1 )
		if ( filename[ i ] == '.' )
		{
			have_ext = true;
			break;
		}

	if ( ! have_ext )
		return;

	int d = 0;
	for ( int i = filename.length() - 1; i >= 0; i = i - 1 )
		if ( filename[ i ] != '/' )
			d = i;
		else
			break;

	filepath = "";
	for ( int i = 0; i < d; i = i + 1 )
		filepath = filepath + filename[ i ];

	string file_name = "";
	int l = 0;
	for ( int i = d; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' )
		{
			l = i;
			break;
		}

		file_name = file_name + filename[ i ];
	}

	for ( int i = l; i < filename.length(); i = i + 1 )
	{
		if ( filename[ i ] == '.' ) continue;	

		ext = ext + filename[ i ];
	}

	filename = file_name;
}

void set_file ( string filename )
{
	ofstream fo;

	string ext;
	string filepath;

	filename_ext_filepath( filename, ext, filepath );

	fo.open( filename + ".tex" );


	fo << get_data_file( "data/before1" );
	fo << "\\Huge " << filename << "\\vspace{25pt}\n\n\\end{center}\n\n";

	for ( int i = 0; i < exam_iter; i = i + 1 )
	{
		fo << "\\begin{question}\n";
		fo << exam[ i ].question << '\n';
		fo << "\\begin{tasks}(2)\n";
		for ( int p = 0; p < exam[ i ].iter; p = p + 1 )
			fo << "\\task " << exam[ i ].answers[ p ] << '\n';
		fo << "\\end{tasks}\n\\end{question}\n\n";
	}

	fo << "\\end{document}\n";

	fo.close();

	fo.open( "Results of: " + filename + ".tex" );

	fo << get_data_file( "data/before2" );
	fo << "\n\\huge ''" << filename << "'' Results \n\\large\n";
	fo << get_data_file( "data/multi" );
	for ( int i = 0; i < exam_iter; i = i + 1 )
	{
		fo << "\\item ";
		for ( int p = 0; p < exam[ i ].iter; p = p + 1 )
		{
			if ( exam[ i ].valid[ p ] )
				fo << alph[ p ] << ") " << exam[ i ].answers[ p ] << " ";
		}
		fo << "\n";
	}

	fo << "\\end{enumerate}\n\\end{multicols}\n\\end{document}";

	fo.close();
}

int main ()
{
	cout << "exams ";

	cout << "Filename: ";

	string filename = "questions";

//	getline( cin, filename );
//	if ( filename == "" )
//		getline( cin, filename );
	int l;


	int m;
	int z;

	get_file( filename );

	set_file( filename );

	return 0;
}
