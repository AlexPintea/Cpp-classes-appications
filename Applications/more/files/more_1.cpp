#include <fstream>
#include <string>
#include <iostream>
#include <string.h>


using namespace std;

int num_classes;




int length(int a)
{
	if (a == 0)
		return 1;

	int i=0;

	while ( a != 0 )
	{
		i=i+1;
		a=a/10;
	}

	return i;
}
// converts a double to a string
string double_to_string ( double a )
{
	bool is_neg = false;
	if ( a < 0 )
		is_neg = true;

	int iter = length( (long) a );

	while ( (float) a - (long) a != 0.0 ) // 3 decimals maximum since float
		a = a * 10;



	int a_as_int;

	if ( is_neg )
		a_as_int = -(long) a;
	else
		a_as_int = (long) a;



	int size = length(a_as_int);

	int num_digits[170];
	for ( int i=0; i<size; i=i+1 )
	{
		num_digits[ size - i - 1 ] = (int) (a_as_int%10);
		a_as_int = a_as_int / 10;
	}


	string result = "";
	if ( is_neg )
		result = result + '-';
	for ( int i=0; i<size; i=i+1 )
	{
		if ( i == iter )
			result = result + '.';

		result = result + (char) ( num_digits[i] + 48 );
	}

	return result;
}



string large_char ( string a )
{
	if ( a[0] >= 'a' and a[0] <= 'z' )
		a[0] = a[0] - 32;

	return a;
}


string names[1000];
int names_iter = 0;



int main ()
{

	// clears "interactions.cpp"
	ofstream fo;
	fo.open( "files/interactions.cpp" );
	fo.close();


	fo.open( "files/interactions.cpp" );
	fo << "#include <iostream>\n#include <string>\n#include <fstream>\n\nusing namespace std;\n\n";

	// clears the "command" file
	ifstream fi;
	fi.open( "files/command" );

	fi >> num_classes;


	string main_string = "";
	string parameters_string[1000];
	string parameters_declaration_string[1000];
	string parameters_temp_string[1000];
	string parameters_interacted_string[1000];

	for ( int i=0; i<num_classes; i=i+1 )
	{

		string name;
		string parameters[1000];
		double boundery_1[1000];
		double boundery_2[1000];
		int num_param;

		int num_iter;



		fi >> name;

		names[ names_iter ] = name;
		names_iter = names_iter + 1;

		fi >> num_param;
		for ( int i=0; i<num_param; i=i+1 )
		{
			fi >> parameters[i];
			fi >> boundery_1[i];
			fi >> boundery_2[i];
		}
		fi >> num_iter;

		parameters_string[i] = "";
		parameters_declaration_string[i] = "";
		parameters_temp_string[i] = "";
		parameters_interacted_string[i] = "";
		for ( int l=0; l<num_param; l=l+1 )
		{
			parameters_string[i] = parameters_string[i] + "	cout << \"" + large_char( name ) + " " + parameters[l] + " increases by: \";\n";
			
			parameters_declaration_string[i] = parameters_declaration_string[i] + "	double " + name + "_" + parameters[l] + "_increase;\n";
			parameters_string[i] = parameters_string[i] + "	cin >> " + name + "_" + parameters[l] + "_increase;\n\n";

			parameters_temp_string[i] = parameters_temp_string[i] + "		" + name + "s[i].set_" + parameters[l] + "( " + name + "s[i].get_" + parameters[l] + "() - " + name + '_' + parameters[l] + "_increase );\n";


			parameters_interacted_string[i] = parameters_interacted_string[i] + "		fo_" + double_to_string( i ) + " << " + name + "s[i].get_" + parameters[l] + "() << \' \';\n";
		}


		fo << "class " << large_char( name ) << "\n";
		fo << "{\n";

		fo << "	string name = \"" << large_char( name ) << "\";\n";
		for ( int l=0; l<num_param; l=l+1 )
			fo << "	double " << parameters[l] << ";\n";


		fo << "\n  public:\n\n";


		fo << "	" << large_char( name ) << "(){}\n\n";

		fo << "	string get_name()\n";
		fo << "	{\n";
		fo << "		return this->name;\n";
		fo << "	}\n\n";

		for ( int l=0; l<num_param; l=l+1 )
		{
			fo << "	double get_" << parameters[l] << "()\n";
			fo << "	{\n";
			fo << "		return this->" << parameters[l] << ";\n";
			fo << "	}\n\n";
		}

		for ( int l=0; l<num_param; l=l+1 )
		{
			fo << "	void set_" << parameters[l] << "( double data )\n";
			fo << "	{\n";
			fo << "		if ( data > " << boundery_2[l] << " )\n";
			fo << "		{\n";
			fo << "			this->" << parameters[l] << " = " << boundery_2[l] << ";\n";
			fo << "			return;\n";
			fo << "		}\n";
			fo << "		if ( data < " << boundery_1[l] << " )\n";
			fo << "		{\n";
			fo << "			this->" << parameters[l] << " = " << boundery_1[l] << ";\n";
			fo << "			return;\n";
			fo << "		}\n";
			fo << "		this->" << parameters[l] << " = data;\n";
			fo << "	}\n\n";
		}

		fo << "};\n";
		fo << "int num_" << name << " = " << num_iter << ";\n\n\n";





		main_string = main_string + "	string " + name + "_parameters[] = { ";
		for ( int l=0; l<num_param; l=l+1 )
		{
			main_string = main_string + "\"" + parameters[i] + "\"";
			if ( l != num_param - 1 )
				main_string = main_string + ", ";
		}

		main_string = main_string +" };\n";
		main_string = main_string + "	" + large_char( name ) + ' ' + name + "s[ num_" + name + "  + 1 ];\n";
		main_string = main_string + "	for ( int i=0; i<num_" + name +"; i=i+1 )\n";
		main_string = main_string + "	{\n";
		for ( int l=0; l<num_param; l=l+1 )
			main_string = main_string + "		" + name + "s[i].set_" + parameters[l] + " ( ( i + " + double_to_string( boundery_2[l] ) + " ) % " + double_to_string( boundery_2[l] - boundery_1[l] ) + " + " + double_to_string( boundery_1[l] ) + " );\n";
		main_string = main_string + "	}\n\n";

	}

	fi.close();




	fo << "\n\nint length( string a[] )\n";
	fo << "{\n";
	fo << "	int i=0;\n\n";
	fo << "	while ( a[i].length() > 0 )\n";
	fo << "		i = i + 1;\n\n";
	fo << "	return i;\n";
	fo << "}\n\n\n";

	fo << "int main()\n{\n\n";

	fo << main_string;

	if ( names_iter > 1 )
		for ( int i=0; i<names_iter; i=i+1 )
			fo << parameters_declaration_string[i];
	else
		fo << "	cout << \"Interactions not available for 1 class\\n\";\n";

	for ( int i=0; i<names_iter - 1; i=i+1 )
		for ( int l=i+1; l<names_iter; l=l+1 )
		{
			fo << "\n\n	cout << \"\\nInteraction: " << large_char( names[ i ] ) << "\" << \" - \" << \"" << large_char( names[l] ) << "\\n\";\n";

			fo << parameters_string[i];
			fo << parameters_string[l];


			fo << "	int smaller_num_" << i + 1 << '_' << l + 1 << ";\n";
			fo << "	if ( num_" << names[i] << " < num_" << names[l] << " )\n";
			fo << "		smaller_num_" << i + 1 << '_' << l + 1 << " = num_" << names[i] << ";\n";
			fo << "	else\n";
			fo << "		smaller_num_" << i + 1 << '_' << l + 1 << " = num_" << names[l] << ";\n\n";
			fo << "	for ( int i=0; i<smaller_num_" << i + 1 << '_' << l + 1 << "; i=i+1 )\n";
			fo << "	{\n";
			fo << parameters_temp_string[i];
			fo << parameters_temp_string[l];
			fo << "	}\n";

		}

	for ( int i=0; i<names_iter; i=i+1 )
	{
		fo << "	ofstream fo_" + double_to_string( i ) + ";\n";
		fo << "	fo_" + double_to_string( i ) + ".open( \"interaction/" + names[i] + '/' + names[i] + "\" );\n";
		fo << "	fo_" + double_to_string( i ) + ".close();\n\n";
		fo << "	fo_" + double_to_string( i ) + ".open( \"interaction/" + names[i] + '/' + names[i] + "\" );\n";
		fo << "	for ( int i=0; i<num_" << names[i] << "; i=i+1 )\n";
		fo << "	{\n";
		fo << parameters_interacted_string[i] << "  ";
		fo << "		fo_" + double_to_string( i ) + " << \'\\n\';\n";
		fo << "	}\n";
		fo << "	fo_" + double_to_string( i ) + ".close();\n\n";
	}

	fo <<"	return 0;\n}";

	fo.close();

	char command_interaction[] = "g++ -o \"files/interactions\" \"files/interactions.cpp\" && \"./files/interactions\"";
	system( command_interaction );

	return 0;
}
