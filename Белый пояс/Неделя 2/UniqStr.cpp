// Capital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>

using namespace std;

set<string> BuildMapValuesSet(const map<int, string>& m)
{
   set<string> values;
   for(const auto& item : m)
      values.insert(item.second);
   
   return values;
}

int main()
{
   while(true)
   {
      set<string> strs;

      int op_count;
      cout << "Enter operations count:" << endl << endl;
      cin >> op_count;

      cout << endl << "Enter:" << endl << endl;

      for(int i = 0; i < op_count; ++i)
      {
         string str;
         cin >> str;

         strs.insert(str);
      }

      cout << endl << strs.size() << endl << endl;
   }

   system("PAUSE");
   return 0;
}

