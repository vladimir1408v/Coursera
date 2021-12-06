// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <regex>
#include <cctype>

using namespace std;


class ReversibleString
{
public:
   ReversibleString(string str)
   {
      cur = str;
   }
   ReversibleString() {}

   void Reverse()
   {
      std::reverse(cur.begin(), cur.end());
   }
   string ToString() const
   {
      return cur;
   }
private:
   string cur = "";
};

int main()
{
   ReversibleString s("livedddasda");
   s.Reverse();
   cout << s.ToString() << endl;

   s.Reverse();
   const ReversibleString& s_ref = s;
   string tmp = s_ref.ToString();
   cout << tmp << endl;

   ReversibleString empty;
   cout << '"' << empty.ToString() << '"' << endl;

   system("PAUSE");
   return 0;
}

