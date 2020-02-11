#include <iostream>
#include <fstream>
using namespace std;

ofstream file;
//// The conversation file

int i;
//// Iterator

string FileName;
//// Name of the file

string Precisations;
//// what you want to say before the conversation

string Name1, Name2;
//// Names of the characters

string Lines1, Lines2;
//// The conversation. Include the narrator in if you want (like this).
///
void ShowText (){
    cout<<"Welcome!"<<endl;
    cout<<"---------------------"<<endl;
    cout<<endl;
    cout<<"You have 2 characters and 17 lines for each. The conversation you type in will be made into a .tex file that you are able to make into a .pdf file."<<endl;
    cout<<endl;
    cout<<"Enter file name: ";
    std::getline(cin, FileName);
    file.open(FileName+".tex");
    cout<<"Enter name for character 1: "<<endl;
    std::getline(cin, Name1);
    cout<<"Enter name for character 2: "<<endl;
    std::getline(cin, Name2);
    cout<<"Enter precisations (will be shown under the name of the file): ";
    std::getline(cin, Precisations);
    cout<<"---------------------"<<endl;
    cout<<endl;
}

int main()
{
    ShowText();

    file<<"\\documentclass[a4paper,10pt]{article} \n \\usepackage[margin=0.5in]{geometry} \n \\usepackage[utf8]{inputenc} \n \\begin{document} \n";
    file<<"\\begin{center} \\begin{huge}\\textbf{"<<FileName<<"}\\end{huge} \n \n \\verb| |\\\\ \n"<<Precisations<<"\\end{center} \n \\begin{large}"<<endl;

    for (i=1;i<=17;i=i+1){
        cout<<"Line Exchange "<<i<<". "<<17-i+1<<" left."<<endl;
        cout<<Name1<<": ";
        std::getline(cin, Lines1);
        file<<"\\textbf{"<<Name1<<": }"<<Lines1<<"\\\\"<<endl;
        cout<<Name2<<": ";
        std::getline(cin, Lines2);
        file<<"\\textbf{"<<Name2<<": }"<<Lines2<<"\\\\"<<endl;
        file<<"\\verb| |\\\\"<<endl;
    }

    file<<"\\end{large} \n \\end{document}"<<endl;

    file.close();

    return 0;
}
