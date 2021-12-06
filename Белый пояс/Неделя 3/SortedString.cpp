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

class SortedStrings
{
public:
   void AddString(const string& s)
   {
      m_vStrings.push_back(s);
   }
   vector<string> GetSortedStrings()
   {
      sort(m_vStrings.begin(), m_vStrings.end());
      return m_vStrings;
   }
private:
   vector<string> m_vStrings;
};

void PrintSortedStrings(SortedStrings& strings)
{
   for(const string& s : strings.GetSortedStrings())
   {
      cout << s << " ";
   }
   cout << endl;
}

int main()
{
   SortedStrings strings;

   strings.AddString("first");
   strings.AddString("third");
   strings.AddString("second");
   PrintSortedStrings(strings);

   strings.AddString("second");
   PrintSortedStrings(strings);

   system("PAUSE");
   return 0;
}

