#include <string.h>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

ofstream file;	   // file that will host the website
fstream identifier;	// file that will identify each website


string title, under_title, about, about_title, contact_item, contact_title;

int colors;

struct color_theme 
{

	string primary;
	string primary_dark;
	string primary_light;
	string light;
	string light_dark;
	
};

color_theme color_themes[8] = {
{ "rgb(123, 123, 124)", "rgb(90, 90, 91)", "rgb(201, 201, 208)", "rgb(241, 241, 243)", "rgb(50, 50, 58)" },
{ "rgb(103, 123, 124)", "rgb(90, 10, 91)", "rgb(101, 201, 208)", "rgb(241, 21, 243)", "rgb(50, 5, 58)" },
{ "rgb(123, 103, 124)", "rgb(90, 90, 10)", "rgb(201, 101, 208)", "rgb(21, 241, 243)", "rgb(5, 50, 58)" },
{ "rgb(123, 123, 104)", "rgb(10, 90, 91)", "rgb(201, 201, 8)", "rgb(241, 241, 23)", "rgb(50, 50, 58)" },
{ "rgb(123, 123, 124)", "rgb(90, 10, 91)", "rgb(201, 21, 208)", "rgb(24, 241, 243)", "rgb(5, 50, 58)" },
};

int main ()
{
	int id;
	identifier>>id;
	identifier.open("identifier.id");
 
 
	cout<<"Make a website!\n\n";

	cout<<"Enter the title:  ";
	std::getline(cin, title);
 

	file.open("index.html");


	cout<<"Enter the under title:  ";
	std::getline(cin, under_title);
	cout<<"\n\n";

 
	file<<"<html>\n\n<head>\n\n<title> " << title << " </title>\n";
 
	file<<"<link rel=\"stylesheet\" href=\"style.css\" />\n\n";
 
	file<<"<style>\n\n";
 
	cout<<"Color you want the website to be: ";
	cout<<"1. Elegant  2. Modern  3. Optimistic  4. Fancy  5. Elevated";
	cout<<"\n\nEnter a number: ";
	cin>>colors;
	cout<<"\n\n";
	colors=colors-1;
 
	file<<"		body\n		{\n			background-image: linear-gradient( " << color_themes[colors].primary << ", rgb(234, 234, 234), " << color_themes[colors].primary_dark << " );\n		}\n\n		#nav span a:hover\n		{\n			color: " << color_themes[colors].primary_light << ";\n		}\n\n		#nav span a:active\n		{\n			color: " << color_themes[colors].light << ";\n		}\n\n		#nav\n		{\n			background-image: linear-gradient( " << color_themes[colors].primary << ", " << color_themes[colors].light_dark << " );\n		}\n\n		#about-div\n		{\n			background-image: linear-gradient( " << color_themes[colors].primary_dark << ", " << color_themes[colors].primary << " );\n		}\n\n		#title-div\n		{\n			background-image: linear-gradient( rgb(234, 234, 234), " << color_themes[colors].primary << ");\n		}\n\n		#title-around\n		{\n			border-color: " << color_themes[colors].primary << ";\n		}\n\n		#under-title-around\n		{\n		border-color: " << color_themes[colors].primary << ";\n		}\n\n";

	file<<"</style>\n\n";

	file<<"	<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\"> \n\n";

	file<<"</head>\n\n<body>\n\n<div id=\"nav\">\n	<span> <a href=\"#\"> Home </a> </span>\n	<span> <a href=\"#about\"> About </a> </span>\n	<span> <a href=\"#contact\"> Contact </a> </span>\n</div>\n\n\n\n\n<div id=\"title-div\">\n	<div>\n\n		<div id=\"title-around\">\n			<h1 id=\"title\"> " << title << " </h1>\n 		</div>\n\n		<div id=\"under-title-around\">\n			<h2 id=\"under-title\"> " <<  under_title << " </h2>\n		</div>\n\n	</div>\n</div>\n\n\n\n\n";

	cout<<"Name your \"About\" paragraphs: ";
	std::getline(cin, about_title);
	std::getline(cin, about_title);

	file<<"<p id=\"about\"> </p>\n\n <div id=\"about-div\">\n	<div>\n\n		<p id=\"about-title\">" << about_title <<"</p>\n\n";




	cout<<"\n\nNum. of paragraphs you will have under \"About\" ( 1 - 15 ): ";
	int nr_paragraphs;
	string paragraph;
	cin>>nr_paragraphs;


	std::getline(cin, paragraph);
	for (int i=0; i<nr_paragraphs; i=i+1)
	{
		cout<<"Enter text for \"About\" paragraph "<< i+1 <<": ";
		std::getline(cin, paragraph);

		file<<"		<p class=\"about-item\"> "<< paragraph << " </p>\n\n";

		paragraph="";
	}



	cout<<"\n\n";

	file << "\n	</div>\n</div>\n\n<hr />\n\n\n\n\n";

	cout<<"Name your \"Contact\" paragraphs: ";
	std::getline(cin, contact_title);

	file<<"<p id=\"contact\"></p>\n\n <div id=\"contact-div\">\n	<div>\n\n		<p id=\"contact-title\">" << contact_title <<"</p>";	

	cout<<"\n\nNum. of paragraphs you will have under \"Contact\" ( 1 - 9 ): ";
	cin>>nr_paragraphs;

	std::getline(cin, paragraph);
	for (int i=0; i<nr_paragraphs; i=i+1)
	{
		cout<<"Enter text for \"Contact\" paragraph "<< i+1 <<": ";
		std::getline(cin, paragraph);

		file<<"		<p class=\"contact-item\">"<< paragraph << " </p>\n\n";

		paragraph="";
	}

	file<<"\n</div>\n</div>\n\n<hr />\n<hr />"; // 

	id=id+1;
	// delete id
	identifier<<id;

	file.close();
	identifier.close();

	return 0;
}
