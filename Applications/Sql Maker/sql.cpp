#include <fstream>
#include <iostream>
#include <string>

using namespace std;


struct table 
{
	string name;
	int nr_columns;
	string columns[100];
	int columns_type[100];
};

table tables[100];
int nr_tables;

void replace_space (string &a)
{
	for (int i=0; i<a.length(); i=i+1)
		if ( a[i] == ' ' )
			a[i] = '_';
}

string type_name (int a)
{
	if (a == 1)
		return "int";

	if (a == 2)
		return "varchar(255)";

	return "";
}

int main () 
{
	ofstream file;
	
	int datse;
	
	cout<<"Make an Sql database!\n\n";
	cout<<"Nr of tables: ";
	cin>>nr_tables;

	cout<<"For each of these tables you will have to provide:\n1. name  2. nr_columns  3. name of each column  4. type of each column\n\n";

	file.open("file.sql");

	cout << "Tables:\n\n";

	for (int r=0; r<nr_tables; r=r+1)
	{
		cout<<"Enter name of table "<< r+1 <<" : ";
		std::getline(cin, tables[r].name);
		std::getline(cin, tables[r].name);

		replace_space( tables[r].name );

		cout<<"Enter num. or columns for table "<< r+1 <<" : ";
		cin >> tables[r].nr_columns;
		cout<<endl;

		cout << "Columns for table " << r+1 << ":\n\n";

		for (int i=0; i<tables[r].nr_columns; i=i+1)
		{
			cout << "Enter name of column " << i+1 <<" : ";
			std::getline(cin, tables[r].columns[i]);
			std::getline(cin, tables[r].columns[i]);

			replace_space( tables[r].columns[i] );
			
			cout << "1. int  2. varchar(255)" << endl;
			cout << "Enter type of column " << i+1 <<" : ";
			cin >> tables[r].columns_type[i];
			cout<<endl;
		}

	}

	file << "CREATE DATABASE DB;\n\n";

	file << "-- Creating tables\n\n";

	for (int r=0; r<nr_tables; r=r+1)
	{
		file << "CREATE TABLE " << tables[r].name << " (\n";		
		file << "	id int NOT NULL,\n"; 

		for (int i=0; i<tables[r].nr_columns; i=i+1)
		{
			file << "	" << tables[r].columns[i] << " " << type_name( tables[r].columns_type[i] ) << " NOT NULL,\n"; 
		}

		file << "	PRIMARY KEY (id)\n);\n\n";
	}


	file << "-- Adding data to tables\n\n";

	for (int r=0; r<nr_tables; r=r+1)
	{
		file << "-- For table " << tables[r].name << ":\n\n";


		for (int l=0; l<10; l=l+1)
		{
			file << "INSERT INTO " << tables[r].name << " ( id, " ;

			for (int i=0; i<tables[r].nr_columns; i=i+1)
			{
				file << tables[r].columns[i];
				if ( i != tables[r].nr_columns - 1 )
					file << ",";
				file << " ";
			}

			file << ")\nVALUES ( " << l << ", ";

			for (int i=0; i<tables[r].nr_columns; i=i+1)
			{
				if ( tables[r].columns_type[i] == 1 )
					file << l;

				if ( tables[r].columns_type[i] == 2 )
					file << "\"" << tables[r].columns[i] << l << "\"";

				if ( i != tables[r].nr_columns - 1 )
					file << ",";
				file << " ";
			}

			file << ");\n\n";

		}
	}

/*
	file << "-- Queries\n\n" ;

	for (int r=0; r<nr_tables; r=r+1)
	{
		file << "-- Query for table" << r+1 << "\n\n" ;

		file << "SELECT ";

		for (int i=0; i<tables[r].nr_columns; i=i+1)
		{
			file << tables[r].columns[i];

			if ( i != tables[r].nr_columns - 1 )
				file << ",";
			file << " ";
		}

		file << "FRM " << tables[r].name << ";\n\n";
	}
*/

	file.close();

	return 0;	
}
