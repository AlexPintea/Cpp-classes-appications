#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream file_f("japanese.in"); 
ofstream file_g("braille.txt");

ifstream file_h("braille.txt");
ofstream file_l("japanese.out");

string ja[]={
"a","i","u","e","o",
"ka","ki","ku","ke","ko",
"sa","shi","su","se","so",
"ta","chi","tsu","te","to",
"na","ni","nu","ne","no",
"ha","hi","hu","he","ho",
"ma","mi","mu","me","mo",
"ya","yu","yo","ya","ra",
"ri","ru","re","ro","wa",
"wi","we","wo","w"
};

string br[]={
"100000","101000","110000","111000","011000",
"100001","101001","110001","111001","011001",
"100101","101101","110101","111101","011101",
"100110","101110","110110","111110","011110",
"100010","101010","110010","111010","011010",
"100011","101011","110011","111011","011011",
"100111","101111","110111","111111","011111",
"010010","010011","010110","010000","100100",
"101100","110100","111100","011100","000010",
"001010","001110","000110","001001"
};

string translate (string a){
  int ok=0;
  for (int i=0;i<=50;i++) 
     if (br[i]==a){ ok=1; return ja[i];} 
  if (ok==0) return "";
}

string translate_inv (string a){
  int ok=0;
  for (int i=0;i<=50;i++) 
     if (ja[i]==a){ ok=1; return br[i];} 
  if (ok==0) return "";
}

int main()
{ int i; string a, b;

//Translate from Japanese to Braille 
  while (!file_f.eof()) 
  { std::getline(file_f, a); b=""; 
    for (i=0;i<a.length();i++)
    {    if (a[i]!='-'){b=b+a[i];file_g<<translate_inv(b);}
	else {b="";file_g<<"-";}	
    }
    file_g<<"\n";
   }	  
   file_f.close();file_g.close();

//Translate from Braille to Japanese
   

  while (!file_h.eof()) 
  { std::getline(file_h, a); b=""; 
    for (i=0;i<a.length();i++)
    {    if (a[i]!='-'){b=b+a[i];file_l<<translate(b);}
	else {b="";file_l<<"";}	
    }
    file_l<<"\n";
   }	  
   file_h.close();file_l.close();

   return 0;
}
