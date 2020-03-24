#include <fstream>
#include <string>
#include <iostream>
#include <string.h>

using namespace std;


ofstream fo;











void continues()
{
	char enter;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> enter;	
}

void clear( string file )
{
	ofstream fo;
	fo.open( file );
	fo.close();	
}

string name = "";
string return_type = "";
string params[1000];
string type[1000];
int has_and[1000];
int is_num[1000];
int has_array[1000];
int param_iter = 0;

string types[] = { "int", "long", "double", "float", "bool", "short", "char", "string" };

bool is_string_in_string ( string a, string b )
{
	if ( a.length() < b.length() )
		return false;

	if ( a.length() == b.length() and a != b )
		return false;

	for ( int i=0; i<a.length(); i=i+1 )
		if ( a[i] == b[0] )
		{
			int is_in = true;

			for ( int l=0; l<b.length(); l=l+1 )
				if ( a[ i + l ] != b[l] )
					is_in = false;

			if ( is_in )
				return true;
		}

	return false;
}

bool is_type ( string a )
{
	for ( int i=0; i<=7; i=i+1 )
		if ( a == types[i] )
			return true;

	return false;
}

bool has_types ( string a )
{
	for ( int i=0; i<=7; i=i+1 )
		if ( is_string_in_string( type[i], types[i] ) )
			return true;

	return false;
}

void get_data ( string file )
{
	string file_1 = "";
	int l=0;

	while ( file[l] != '{' )
	{
		file_1 = file_1 + file[l];
		l = l + 1;
	}

	file = file_1;


	for ( int i=0; i<file.length(); i=i+1 )
		if ( file[i] == '	' or file[i] == '\n' or file[i] == ',' or file[i] == '(' or file[i] == ')' or file[i] == '{' or file[i] == '}'  )
			file[i] = ' ';

//	cout << "\"" << file << "\"    ";


	file_1 = "";
	for ( int i=0; i<file.length() - 1; i=i+1 )
	{
		if ( file[i] == ' ' and file[i + 1] == ' ' )
			continue;

		file_1 = file_1 + file[i];
	}

	file = file_1 + ' ';

//	cout << "\"" << file << "\"    ";

	string type_params[1000];

	for ( int i=0; i<100; i=i+1 )
		type_params[i] = "";

	int type_params_iter = 0;
	for ( int i=0; i<file.length(); i=i+1 )
	{
		if ( file[i] != ' ' )
			type_params[ type_params_iter ] = type_params[ type_params_iter ] + file[i];
		else
			type_params_iter = type_params_iter + 1;
	}


	int iter;
	for ( int i=0; i<type_params_iter; i=i+1 )
	{
		if ( !is_type( type_params[i] ) )
		{
			iter = i + 1;
			name = type_params[i];
			break;
		}

		return_type = return_type + type_params[i] + ' ';
	}
	return_type[ return_type.length() - 1 ] = '\0';

	

	for ( int i=iter; i<type_params_iter; i=i+1 )
	{
		if ( !is_type( type_params[i] ) )
		{
			params[param_iter] = type_params[i];
			param_iter = param_iter + 1;
			continue;
		}

	
		type[param_iter] = type[param_iter] + type_params[i] + ' ';
	}

	for ( int i=0; i<param_iter; i=i+1 )
	{
		string temp = type[i];

		string type_clear = "";

		for ( int l=0; l<temp.length() - 1; l=l+1 )
			type_clear = type_clear + temp[l];

		type[i] = type_clear;





		type_clear = "";
		temp = params[i];

		has_and[i] = -1;
		if ( temp[0] == '&' )
			has_and[i] = 9;


		if ( has_and[i] == 9 )
		{
			for ( int l=1; l<params[i].length(); l=l+1 )
				type_clear = type_clear + temp[l];

			params[i] = type_clear;
		}




		type_clear = "";
		temp = params[i];

		has_array[i] = -1;
		if ( temp[ temp.length() - 1 ] == ']' )
			has_array[i] = 9;

		if ( has_array[i] == 9 )
		{
			for ( int l=0; l<params[i].length(); l=l+1 )
			{
				if ( temp[l] == '[' )
					break;

				type_clear = type_clear + temp[l];
			}

			params[i] = type_clear;
		}
	}
}

void file ()
{
	ifstream fi;

	fi.open( "files" );

	string file = "";
	string temp;

	while ( getline( fi, temp ) )
		file = file + temp + '\n';

	fi.close();




	get_data( file );

	clear( "file.cpp" );
	fo.open( "file.cpp" );

	fo << "#include <string>\n#include <iostream>\n#include <fstream>\n#include <string.h>\n\nusing namespace std;\n\n";

	fo << file;

	fo << "\n\nint main ()\n{\n";


	for ( int i=0; i<param_iter; i=i+1 )
	{
		int counter = 7;
		if ( is_string_in_string( type[i], "short" ) )
			counter = 2;

		fo << '	' << type[i] << ' ' << params[i] << "[ " << counter + 2 << " ];\n";

		if ( type[i] == "char" )
		{
			fo << "	for ( int i=0; i<" << counter << "; i=i+1 )\n";
			fo << "		" << params[i] << "[i] = (char) i % 127;\n";
			continue;
		}

		if ( type[i] == "string" )
		{
			fo << "	for ( int i=0; i<" << counter << "; i=i+1 )\n";
			fo << "		" << params[i] << "[i] = \"\";\n";
			fo << "	for ( int i=0; i<" << counter << "; i=i+1 )\n";
			fo << "	{\n";
			fo << "		for ( int l=0; l<=i; l=l+1 )\n";
			fo << "			" << params[i] << "[i] = " << params[i] << "[i] + (char) ( l % 127 + 32 );\n";
			fo << "	}\n";
			continue;
		}

		fo << "	for ( int i=0; i<" << counter << "; i=i+1 )\n";
		fo << "		" << params[i] << "[i] = i;\n";

		fo << "\n";
	}

	fo << "	ofstream fo;\n";
	fo << "	fo.open( \"results\" );\n";
	fo << "	fo.close();\n\n";

	fo << "	fo.open( \"results\" );\n";
	for ( int i=0; i<param_iter; i=i+1 )
	{
		for ( int l=0; l<=i; l=l+1 )
			fo << "	";

		int counter = 7;
		if ( is_string_in_string( type[i], "short" ) )
			counter = 2;


		fo << "for ( int i_" << i + 1 << " = 0; i_" << i + 1 << " < " << counter << "; i_" << i + 1 << " = i_" << i + 1 << " + 1 )\n";
	}


	for ( int l=0; l<param_iter; l=l+1 )
		fo << "	";
	fo << "{\n";

	for ( int i=0; i<param_iter; i=i+1 )
	{
		if ( has_array[i] != 9 )
		{
			for ( int l=0; l<=param_iter; l=l+1 )
				fo << "	";
			fo << "fo << \"" << params[i] << " = \\'\" << " << params[i] << "[ i_" << i + 1 << " ] << \"\\' \";\n ";
		}
		else
			fo << "fo << \""<< params[i] << "[] \";\n";
	}

	for ( int l=0; l<=param_iter; l=l+1 )
		fo << "	";
	if ( return_type != "void" )
		fo << "fo << \"" << name << " = \" << ";

	fo << name << "( ";
	for ( int i=0; i<param_iter; i=i+1 )
	{
		if ( has_array[i] != 9 )
			fo << params[i] << "[ i_" << i + 1 << " ]";
		else
			fo << params[i];

		if ( i != param_iter - 1 )
			fo << ", ";
	}
	fo << " ) << \"   \";\n";


	for ( int i=0; i<param_iter; i=i+1 )
		if ( has_and[i] == 9 )
		{
			for ( int l=0; l<=param_iter; l=l+1 )
				fo << "	";
			fo << "fo << \"&" << params[i] << " = \\'\" << " << params[i] << "[ i_" << i + 1 << " ] << \"\\' \";\n ";
		}


	if ( return_type == "void" )
		fo << " cout << \"\\n\"; ";

	for ( int l=0; l<=param_iter; l=l+1 )
		fo << "	";
	fo << "fo << \"\\n\";\n";

	for ( int l=0; l<param_iter; l=l+1 )
		fo << "	";
	fo << "}\n";
	fo << "	fo.close();\n";


	fo << "\n	return 0;\n}";

	fo.close();
}

int main ()
{

	cout << "Edit \"files\".\n\n";
	continues();
	file();

	char command[] = "clear && g++ -o file file.cpp && ./file";
	system( command );

	cout << "printf \033c";
//	cout << name << ' ' << return_type << '\n';
//	for ( int i=0; i<param_iter; i=i+1 )
//		cout << type[i] << ' ' << params[i] << '\n'; 


	cout << "File \"results\".\n";

	return 0;
}
