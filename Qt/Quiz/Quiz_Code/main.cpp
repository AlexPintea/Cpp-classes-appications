#include <iostream>
#include <fstream>
using namespace std;

ofstream file;

int i;
//// Iterator

int Correct[70];
//// Correct Answers

string Q[70], A[70][70];
//// Strings for questions and answers

string FileName;

void ShowText (){
    cout<<"Welcome!"<<endl;
    cout<<"-------------------"<<endl;
    cout<<"Enter file name: ";
    cin>>FileName;
    file.open(FileName+".tex");
    cout<<endl;
    cout<<"Ok, now you'll give 14 questions with 4 answers each."<<endl;
    cout<<endl;
}

int main()
{   ShowText();
    for (i=1;i<=14;i=i+1){
        cout<<"Q("<<i<<"):";
        std::getline(cin, Q[i]);
        std::getline(cin, Q[i]);
        cout<<endl;
        cout<<"A1("<<i<<"):";
        std::getline(cin, A[1][i]);
        cout<<endl;
        cout<<"A2("<<i<<"):";
        std::getline(cin, A[2][i]);
        cout<<endl;
        cout<<"A3("<<i<<"):";
        std::getline(cin, A[3][i]);
        cout<<endl;
        cout<<"A4("<<i<<"):";
        std::getline(cin, A[4][i]);
        cout<<endl;
        cout<<"Which is correct? (1, 2, 3, 4) Correct answer: "<<endl;
        cin>>Correct[i];
        cout<<endl;
    }

    file<<"\n \\documentclass[a4paper,10pt]{article} \n \\usepackage[margin=1in]{geometry} \n \\usepackage[utf8]{inputenc} \n \\begin{document}";
    file<<"\n \\begin{center} \\begin{Huge}"<<FileName<<"\\end{Huge} \\\\ Each is 1 / 14. \\end{center} \n";
    for (i=1;i<=14;i=i+1){

            file<<"\\begin{enumerate} \n";

            file<<"\\item[\\textbf{"<<i<<".}]"<<"\\textbf{"<<Q[i]<<"} \n";

            file<<"\\item[1)]"<<A[1][i]<<"\n";

            file<<"\\item[2)]"<<A[2][i]<<"\n";

            file<<"\\item[3)]"<<A[3][i]<<"\n";

            file<<"\\item[4)]"<<A[4][i]<<"\n";

            file<<"\\end{enumerate} \n";

            file<<endl;

        }

    file<<"\\newpage"<<endl;

    file<<"\n \\begin{center} \\begin{Huge} Answers for: "<<FileName<<"\\end{Huge} \\end{center} \\begin{Large} \n"<<endl;

    for (i=1;i<=14;i=i+1){

            file<<"\\noindent \\textbf{"<<i<<"}. "<<Q[i]<<": \\textbf{"<<Correct[i]<<")} "<<A[Correct[i]][i]<<"\n \n \n \n \n";

            file<<endl;

        }

    file<<"\n \\end{Large} \n \\end{document}";

    file.close();
    return 0;
}
