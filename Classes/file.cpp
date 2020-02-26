// give length 10 to a parameter[], if it does not have one
void give_length( string &parameter )
{
	int size = parameter.length();

	if ( parameter[ size - 1 ] == ']' and parameter[ size - 2 ] == '[' )
	{
		parameter[ size - 1 ] = '1';
		parameter = parameter + "0]";
	}
}

// show info
void show_info()
{
	
	cout << "Info:\n\n";

	cout << "( info ) Do not enter empty variable columns or datatypes.\n";
	cout << "( info ) If you want to store multiple items of the same type in one variable, type \"[]\" after variable name.\n";
	cout << "         If you know how many you want to store ( maximum ), type \"parameter_name[142]\" etc.\n\n";

	char enter;
	cout << "[ \']\' + Enter ] to continue: ";
	cin >> enter;

	cout << "\n";
}

	cout << "\n\nClass is complete.\n\n";



// nt clss, cmplete


