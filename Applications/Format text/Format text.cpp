#include <string.h>
#include <fstream>
#include <iostream>
#include <string>


using namespace std;


ofstream file;
fstream num;
int choice;

string invert_string (string a)
{
	int len = a.length();
	string r = "";

	for (int i=len-1; i>=0; i=i-1)
	{
		r = r + a[i];
	}

	return r;
}

string int_string (int a)
{
	string r = "";

	while (a != 0)
	{		
		r = r + (char) (a%10 + 48);
		a=a/10;
	}

	r = invert_string(r);

	return r;
}

void apology ()
{
	string strings[4] ={ "name", "reason", "place" };

	string responses[4];

	file << "Good day,\n\n";
	cout << "Good day,\n\n";

	cout << "I will not be able to attend the ";
	file << "I will not be able to attend the ";
	
	cout << "(" << strings[2] << "): ";
	std::getline(cin, responses[2]);
	std::getline(cin, responses[2]);
	file << responses[2];
	cout << endl;

	cout << " since ";
	file << " since ";

	cout << "(" << strings[1] << "): ";
	std::getline(cin, responses[1]);
	file << responses[1];
	cout << endl;

	cout << ".\n\nI want to apologise and hope this will not happen in the future.\n\nYours,\n";
	file << ".\n\nI want to apologise and hope this will not happen in the future.\n\nYours,\n";

	cout << "(" << strings[0] << "): ";
	std:getline(cin, responses[0]);
	file << responses[0];
	cout << endl;
}

void thanks ()
{
	string strings[3] ={ "name", "reason" };

	string responses[3];

	file << "Good day,\n\n";
	cout << "Good day,\n\n";

	cout << "I want to thank you very much for ";
	file << "I want to thank you very much for ";
	
	cout << "(" << strings[1] << "): ";
	std::getline(cin, responses[1]);
	std::getline(cin, responses[1]);
	file << responses[1];
	cout << endl;

	cout << ".\n\nYou have made my day!\n\nYours,\n";
	file << ".\n\nYou have made my day!\n\nYours,\n";

	cout << "(" << strings[0] << "): ";
	std:getline(cin, responses[0]);
	file << responses[0];
	cout << endl;
}


void invitation ()
{
	string strings[4] ={ "name", "occasion", "place and time" };

	string responses[4];

	file << "Good day,\n\n";
	cout << "Good day,\n\n";

	cout << "I want to invite you to ";
	file << "I want to invite you to ";
	
	cout << "(" << strings[1] << "): ";
	getline(cin, responses[1]);
	getline(cin, responses[1]);
	file << responses[1];
	cout << endl;

	cout << ". It will take place at ";
	file << ". It will take place at ";

	cout << "(" << strings[2] << "): ";
	std::getline(cin, responses[2]);
	file << responses[2];
	cout << endl;




	cout << ".\n\nI cannot wait to see you then!\n\nYours,\n";
	file << ".\n\nI cannot wait to see you then!\n\nYours,\n";

	cout << "(" << strings[0] << "): ";
	std:getline(cin, responses[0]);
	file << responses[0];
	cout << endl;
}

void trip ()
{
	string strings[4] ={ "name", "how you are feeling", "place" };

	string responses[4];

	file << "Good day, allright!\n\n";
	cout << "Good day, allright!\n\n";

	cout << "I am on a trip to ";
	file << "I am on a trip to ";
	
	cout << "(" << strings[2] << "): ";
	std::getline(cin, responses[2]);
	std::getline(cin, responses[2]);
	file << responses[2];
	cout << endl;

	cout << ". And about how I\'m feeling, ... ";
	file << ". And about how I\'m feeling, ... ";

	cout << "(" << strings[1] << "): ";
	std::getline(cin, responses[1]);
	file << responses[1];
	cout << endl;

	cout << ".\n\nIt\'s all great to be here, I\'m really glad I came. Maybe you\'ll come someday.\n\nYours,\n";
	file << ".\n\nIt\'s all great to be here, I\'m really glad I came. Maybe you\'ll come someday.\n\nYours,\n";

	cout << "(" << strings[0] << "): ";
	std:getline(cin, responses[0]);
	file << responses[0];
	cout << endl;
}


void congratulations ()
{
	string strings[3] ={ "name", "reason" };

	string responses[3];

	file << "A very good day,\n\n";
	cout << "A very good day,\n\n";

	cout << "I want to congratulate you on ";
	file << "I want to congratulate you on ";
	
	cout << "(" << strings[1] << "): ";
	std::getline(cin, responses[1]);
	std::getline(cin, responses[1]);
	file << responses[1];
	cout << endl;

	cout << ".\n\nIt's all your merit!\n\nYours,\n";
	file << ".\n\nIt's all your merit!\n\nYours,\n";

	cout << "(" << strings[0] << "): ";
	std:getline(cin, responses[0]);
	file << responses[0];
	cout << endl;
}

void request ()
{
	string strings[3] ={ "name", "request" };

	string responses[3];

	file << "Good day,\n\n";
	cout << "Good day,\n\n";

	cout << "I need some help. ";
	file << "I need some help. ";
	
	cout << "(" << strings[1] << "): ";
	std::getline(cin, responses[1]);
	std::getline(cin, responses[1]);
	file << responses[1];
	cout << endl;

	cout << ".\n\nThank you in advance.\n\nYours,\n";
	file << ".\n\nThank you in advance.\n\nYours,\n";

	cout << "(" << strings[0] << "): ";
	std:getline(cin, responses[0]);
	file << responses[0];
	cout << endl;
}


void angry ()
{
	string strings[3] ={ "name", "reason" };

	string responses[3];

	file << "Hi,\n\n";
	cout << "Hi,\n\n";

	cout << "I think I have reasons to be very angry with you. ";
	file << "I think I have reasons to be very angry with you. ";
	
	cout << "(" << strings[1] << "): ";
	std::getline(cin, responses[1]);
	std::getline(cin, responses[1]);
	file << responses[1];
	cout << endl;

	cout << ".\n\nDo not do this again.\n\nYours,\n";
	file << ".\n\nDo not do this again.\n\nYours,\n";

	cout << "(" << strings[0] << "): ";
	std:getline(cin, responses[0]);
	file << responses[0];
	cout << endl;
}


int main ()
{
	num.open( "num.txt" );

	cout << "Select a file:\n";
	cout << "1. apology\n";
	cout << "2. thanks\n";
	cout << "3. invitation\n";
	cout << "4. congratulations\n";
	cout << "5. request\n";
	cout << "6. angry\n";
	cout << "7. trip\n";

	cout << "\nEnter your choice: ";

	cin >> choice;

	cout << "\n\n";

	string filename;

	int id;

	num >> id;

	if (id == 0)
		id = 1;

	num.close();

	num.open("num.txt", std::ofstream::out | std::ofstream::trunc);
	num.close();

	num.open("num.txt");

	if ( choice == 1 )
	{
		filename = "apology_" + int_string( id ) + ".txt";

		file.open(filename);	

		apology();
	}
	if ( choice == 2 )
	{
		filename = "thanks_" + int_string( id ) + ".txt";
		file.open(filename);
		thanks();
	}

	if ( choice == 3 )
	{
		filename = "invitation_" + int_string( id ) + ".txt";
		file.open(filename);
		invitation();
	}
	if ( choice == 4 )
	{
		filename = "congratulations_" + int_string( id ) + ".txt";
		file.open(filename);
		congratulations();
	}
	if ( choice == 5 )
	{
		filename = "request_" + int_string( id ) + ".txt";
		file.open(filename);
		request();
	}
	if ( choice == 6 )
	{
		filename = "angry_" + int_string( id ) + ".txt";
		file.open(filename);
		angry();
	}
	if ( choice == 7 )
	{
		filename = "trip_" + int_string( id ) + ".txt";
		file.open(filename);
		trip();
	}

	num << id + 1;

	file.close();
	num.close();

	return 0;	
}
