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

typedef vector<string> vec_str;

bool CheckWord(const string& word)
{
   bool result = true;
   string temp(word);
   regex re("([0-9]*)([a-z]*)([A-Z]*)");
   smatch m;
   
   if(temp.size() < 1 || temp.size() > 15)
   {
      cout << "str < 1 || str > 15. Try again" << endl << endl;
      result = false;
   }

   if(result)
   {
      result = regex_match(temp, re);
      if(!result)
         cout << "don't support symbol" << endl << endl;
   }

   return result;
}

string ToLower(const string& word)
{
   string result(word);

   transform(result.begin(), result.end(), result.begin(), [](unsigned char s)
   {
      return std::tolower(s);
   });

   return result;
}


void Print(const vec_str& source)
{
   for(const string& x : source)
      cout << x << " ";
}

int main()
{
   while(true)
   {
      int n;
      cout << "Enter:" << endl;
      cin >> n;

      if(n < 0 || n > 1000)
      {
         cout << "n < 0 || n > 1000" << endl << endl;
         continue;
      }

      vec_str vresult;

      while(n != 0)
      {
         string str;
         cin >> str;

         if(!CheckWord(str))
            continue;

         vresult.push_back(str);

         n--;
      }

      sort(vresult.begin(), vresult.end(), [](string first, string second)
      {
         if(ToLower(first) <= ToLower(second))
            return true;

         return false;
      });

      Print(vresult);
      cout << endl << endl;
   }

   system("PAUSE");
   return 0;
}

