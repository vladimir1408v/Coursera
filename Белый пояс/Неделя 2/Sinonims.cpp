// Capital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<string, int> g_operation = { { "ADD", 1 },{ "COUNT", 2 },{ "CHECK", 3 } };

int main()
{
   while(true)
   {
      map<string, set<string>> many;

      int op_count;
      cout << "Enter operations count:" << endl << endl;
      cin >> op_count;

      cout << endl << "Enter operation:" << endl << endl;

      while(op_count != 0)
      {
         string op_string;
         cin >> op_string;
         int op_number = g_operation[op_string];

         switch(op_number)
         {
            case 1:  // ADD 
            {
               string first, second;
               cin >> first >> second;

               many[first].insert(second);
               many[second].insert(first);
            }
            break;
            case 2:  // COUNT
            {
               string first;
               cin >> first;
               cout << many[first].size() << endl << endl;
            }
            break;
            case 3:  // CHECK
            {
               string first, second;
               cin >> first >> second;

               bool result = false;
               if(many[first].count(second) != 0)
                  result = true;

               string desc = "NO";
               if(result)
                  desc = "YES";

               cout << desc << endl << endl;
            }
            break;
            default:
            cout << "bad request" << endl << endl;
            break;
         }

         op_count--;
      }
   }

   system("PAUSE");
   return 0;
}

