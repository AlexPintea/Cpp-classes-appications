#include <iostream>
#include <fstream>
using namespace std;

ifstream file_df("code_d.in");
ofstream file_dg("code_d.out");
ifstream file_dh("code_d.out");


void decod_country (string &a, int &k)
{
  if (a=="2"){a="AABBAB";k=2; } if (a=="3"){a="AABBBA";k=3; }
  if (a=="4"){a="ABAABB";k=4; } if (a=="5"){a="ABBAAB";k=5; }
  if (a=="6"){a="ABBBAA";k=6; } if (a=="7"){a="ABABAB";k=7; }
  if (a=="8"){a="ABABBA";k=8; } if (a=="9"){a="ABBABA";k=9; }
}

void invert_right (string v, int &s)
{ int a, b, c, d, i, n; s=i=a=b=c=d=0;  string a1="1", a2="2", a3="3", a4="4";
    while (v[i]=='1'){a++;i++; } while (v[i]=='0'){b++;i++; }
    while (v[i]=='1'){c++;i++; } while (v[i]=='0'){d++;i++; }
  s=a*1000+b*100+c*10+d;
}

void invert_A (string v, int &s)
{ int a, b, c, d, i, n; s=i=a=b=c=d=0;  string a1="1", a2="2", a3="3", a4="4";
    while (v[i]=='0'){a++;i++; } while (v[i]=='1'){b++;i++; }
    while (v[i]=='0'){c++;i++; } while (v[i]=='1'){d++;i++; }
  s=a*1000+b*100+c*10+d;
}
// invert_B exactly as invert_A 

void decod (string a, int b[])
{ string k;string aa[14]={"","","","","","","","","","","","","",""};
  int c, i, j; int bb[13];i=0;k=a[0];decod_country(k, c);  b[0]=c; j=2;

//LEFT side of the code
  for (int ij=1;ij<=6;ij++){while (a[j]!=' '){aa[ij]=aa[ij]+a[j];j++;}j++;}
  for (int ij=1;ij<=6;ij++){invert_A(aa[ij],bb[ij]);b[ij]=bb[ij];}

//RIGHT side of the code
  for (int ij=7;ij<=12;ij++){while (a[j]!=' '){aa[ij]=aa[ij]+a[j];j++;}j++;}         
  for (int ij=7;ij<=12;ij++){invert_right(aa[ij],bb[ij]);b[ij]=bb[ij];}

  for (i=1;i<=12;i++)
  {   if (b[i]==3211 || b[i]==1123){b[i]=0;} if (b[i]==2221 || b[i]==1222){b[i]=1;}
      if (b[i]==2122 || b[i]==2212){b[i]=2;} if (b[i]==1411 || b[i]==1141){b[i]=3;}
      if (b[i]==1132 || b[i]==2311){b[i]=4;} if (b[i]==1231 || b[i]==1321){b[i]=5;}
      if (b[i]==1114 || b[i]==4111){b[i]=6;} if (b[i]==1312 || b[i]==2131){b[i]=7;}
      if (b[i]==1213 || b[i]==3121){b[i]=8;} if (b[i]==3112 || b[i]==2113){b[i]=9;}
  }
}

void checksum (int a[])
{ int i, s1, s2, s, n, c; s1=0;s2=0;
  for (i=1;i<=12;i++){if (i%2==1){s1=s1+a[i];}else{s2=s2+a[i];} }
 
  s=s1+3*s2; n=s/10; n=n*10; c=s-n; a[13]=10-c;
}

int invert_string (string &a)
{ int i;   string b=""; b=b+a[0]+" ";
  for (i=a.length();i>=2;i=i-1){ b=b+a[i];}
  a=b;
}

void checking(string a, int novers, int fi, int li, string checkst)
{ for(int vers=1;vers<=novers;vers++)
  { string s=""; for(int i=fi;i<=li;i++) s=s+a[i];
    if (s==checkst) cout<<" barcode variant "<<vers<<" is correct";
  }
}

string cost(string a)
{  string s=""; for(int i=8;i<=11;i++) s=s+a[i]; return s;
}


int main()
{  string a, k; int b[1234], i; 

/* D)*/
std::getline(file_df, a);file_df.close();
decod(a, b); for (i=0;i<=12;i++){file_dg<<b[i];}  file_dg<<"\n"; file_dg.close();
std::getline(file_dh, a);file_dh.close();cout<<cost(a);
//4). pork steak (packed in the store), cost = 4 euros and 16 cents; “the last four digits before the checksum are the prices (pork steak: 0416 # 4 euros and 16 cents).”[3]
string deverif="0416";int gh1=1, gh2=8,gh3=11;checking(a,gh1,gh2,gh3,deverif);

return 0;
}
