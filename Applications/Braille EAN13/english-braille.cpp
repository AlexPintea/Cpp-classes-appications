#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream file_f("english.in"); 
ofstream file_g("braille.txt");

ifstream file_h("braille.txt");
ofstream file_l("english.out");

string ea[]={
"a","b","c","d","e","f","g","h","i","j",
"k","l","m","n","o","p","q","r","s","t",
"u","v","w","x","y","z","#","0","1","2",
"3","4","5","6","7","8","9"
};

//the numbers use "Nemeth code" 

string br[]={
"100000","101000","110000","110100","100100","111000","111100","101100","011000","011100",
"100010","101010","110010","110110","100110","111010","111110","101110","011010","011110",
"100011","101011","011101","110011","110111","100111","010111","000111","001000","001010",
"001100","001101","001001","001110","001111","001011","001100"
};


string translate (string a){
  int ok=0;
  for (int i=0;i<=50;i++) 
     if (br[i]==a){ ok=1; return ea[i];} 
  if (ok==0) return "";
}

string translate_inv (string a){
  int ok=0;
  for (int i=0;i<=50;i++) 
     if (ea[i]==a){ ok=1; return br[i];} 
  if (ok==0) return "";
}

int main()
{ int i; string a, b;

//Translate from English to Braille 
  while (!file_f.eof()) 
  { std::getline(file_f, a); b=""; 
    for (i=0;i<a.length();i++)
    {    if (a[i]!=' '){b=a[i];file_g<<translate_inv(b)<<"-";}//b=a[i];
	else {
		b="";
		if (a[i]=='\n') file_g<<"\n";else file_g<<" ";
	}
    }
    file_g<<"\n";
   }	  
   file_f.close();file_g.close();

//Translate from Braille to English
   
  while (!file_h.eof()) 
  { std::getline(file_h, a); b=""; 
    for (i=0;i<a.length();i++)
    {    
	if ((a[i]!=' ') && (a[i]!='-')){b=b+a[i];file_l<<translate(b);}
	else{
             b="";  
    	    if (a[i]==' ') file_l<<" ";
          }    
   }
	file_l<<"\n";
  }	  
   file_h.close();file_l.close();

   return 0;
}
