#include "String.h"

TString::TString()
{
  str = new char [1];
  str[0] = 0;
  len = 1;


}

TString::TString(int l, char c)
{
  if (l != 0)
    len = l;
  else
    throw "строка";
  str = new char [len];
  for (int i = 0; i < len; i++)
    str[i] = l;

}

TString::TString(char* s)
{
  if (s == 0)
  throw "строка";
    len = strlen(s) + 1;
    str = new char[len];
    for (int i = 0; i < len; i++)
      str[i] = s[i];
  


}

TString::TString(const TString& p)
{
  len = p.len;
  str = new char[len];
  for (int i = 0; i < 0; i++)
    str[i] = p.str[i];

}

TString::~TString()
{
  if(str!=0)
  {
    delete[] str;
    str = 0;

  }
}

TString TString::operator+(const TString& p) 
{
TString res;
int tmp, l, len,m=0; 
tmp = strlen(this->str); 
l = strlen(p.str);
len = tmp + l;
res.str = new char[len + 1];
for (m; m < tmp; m++);
{
  res.str[m] = this->str[m];
}
for (int j = 0; j < l; j++, m++)
{
  res.str[m] = p.str[j]; 
}
res.str[len] = '\0';
return res;
}

TString TString::operator+(char* s) 
{
  if (s == 0)
    throw"строка";
  int l = strlen(s);
  TString w = len + l;
  for (int i = 0; i < len - 1; i++)
    w[i] = str[i];
  for (int i = 0; i < l; i++)
    w[i + len] = s[i];
  w[w.len - 1] = 0;
  return w;

}

TString TString::operator=(char* s)
{
  int strN = strlen(s) + len;
  char* tmp = new char[strN];
  for (int i = 0; i < strN; i++)
  {
    if (i < len - 1)
    {
      tmp[i] = str[i];
    }
    else
    {
      tmp[i] = s[i - len + 1];

    }
    len = strN;
    delete [] str;
    str = tmp;
    
  }
  return *this;
}

bool TString::operator>(const TString& p)
{
  if (len > p.len)
    return true;
    return false;
}

bool TString::operator<(const TString& p)
{
  if (len < p.len)
    return true;
  return false;
}

char& TString::operator[](int i)
{
  if (i < 0 || i >= len)
    throw"значение [i] не входит в диапазон";
  return str[i];
}

int TString::find(char c)
{
  int n = 0;
  int len = strlen(this->str);
  for (int i = 0; i < len; i++)
    if (this->str[i] == c)
    {
      n = i + 1;
      std::cout << n << std::endl;
      break;
    }
  if (n == 0)
    std::cout << "Haven't this letter in string " << std::endl;
  return n;
}

int TString::find(char* s)
{
  int find = 0;
  if (s == 0) throw"...";
  int l = strlen(s);
  for (int i = 0; i < len; i++)
  {
    find = 0;
    for (int j = 0; j < l; j++)
      if (str[i + j] = s[j])
        break;
        find = -1;
    if (find == 0)
      return i;
  }
  return -1;
}

TString** TString::Split(char c) 
{
  int k = 0;
  int count = 0;
  int start = 0;
  for (int i = 0; i < len; i++) {
    if (str[i] == c)
      count++;
    if (count == 0)
      return 0;
    TString** temp = new TString*[count];
    for (int j = 0; j < len; j++) 
    {

      if (str[j] == c)
      {
        temp[k] = new TString(str[start], j-start);
        start = j + 1;
        k++;
      }
    }
    temp[k] = new TString(str[start], len - start);
    return temp;
  }
}



bool operator==(const TString& p, const TString& m)
{
  if (p.len == m.len) 
  {
    int k = 0;
    while (p.str[k] == m.str[k]) {
      k++;
    }
    if ((k - 1) == p.len)
      return true;
  }
  return false;
}

std::istream& operator>>(std::istream& istr, TString& p)//pppp
{
  
    istr >> p.str;
    return istr;
 
}

std::ostream& operator<<(std::ostream& ostr, TString& p)
{
  ostr << "str=" << std::endl;
  return ostr;
}








