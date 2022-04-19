#include <iostream>
#include "String.h"
using namespace std;
int main()
{
  TString a;
  TString v(4, 'h');
  TString d = "hhh";
  TString w(d);
  TString t('bbb', 4);
  int f = 0;
  try
  {
    a = v + d;
  }
  catch (char* s)
  {
    cout << s;
  }
  try
  {
    f = a.find('h');
  }
  catch (char* s)
  {
    cout << s;
  }
  try
  {
    TString* str1 = new TString();
    TString* str2 = new TString("hello");
    TString* str3 = new TString(*str2);
  }
  catch (TString s)
  {
    cout << s;
  }


}