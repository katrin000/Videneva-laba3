#pragma once
#include <iostream>
class TString {

protected:
  char* str;
  int len;

public:
  TString();
  TString(int l, char c = 0);
  TString(char* s);
  TString(const TString& p);
  ~TString();
  TString operator +(const TString& p);
  TString operator +(char* s);
  TString operator =(char* s);
  friend bool operator ==(const TString& p, const TString& m);
  bool operator >(const TString& p);
  bool operator <(const TString& p);
  char& operator[](int i);
  int find(char c);
  int find(char* s);
  TString** Split(char c);
  int m = 0;
  friend std::istream& operator >>(std::istream& istr, TString& p);
  friend std::ostream& operator <<(std::ostream& ostr, TString& p);
};

