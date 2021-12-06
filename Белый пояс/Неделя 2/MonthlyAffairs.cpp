// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef vector<vector<string>> vec_vectorStr;
map<string, int> g_operation = { { "ADD", 1 },{ "DUMP", 2 },{ "NEXT", 3 } };
int daysCount[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main()
{
   while(true)
   {
      int op_count;
      cout << "Enter operation count:" << endl << endl;
      cin >> op_count;

      if(op_count < 0)
      {
         cout << "count < 0. Try again" << endl << endl;
         continue;
      }

      int month = 0;
      vec_vectorStr vWork(daysCount[month]);  // January
      cout << endl << "Enter operations:" << endl << endl;

      while(op_count != 0)
      {
         int i = 0;
         string op_string;
         cin >> op_string;
         int op_number = g_operation[op_string];

         if(op_number != 3)
         {
            cin >> i;

            i -= 1;
            if(i < 0 || i > vWork.size() - 1)
            {
               cout << "there is no day. Try again." << endl << endl;
               continue;
            }
         }

         switch(op_number)
         {
            case 1:  // ADD 
            {
               string business;
               cin >> business;
               
               vWork[i].push_back(business);
            }
            break;
            case 2:  // DUMP
            {
               cout << vWork[i].size() << " ";
               for(const string& str : vWork[i])
                  cout << str << " ";

               cout << endl;
            }
            break;

            case 3:  // NEXT
            {
               int cur = month;
               month++;
               if(month > 11)
                  month = 0;

               if(daysCount[month] >= daysCount[cur])
                  vWork.resize(daysCount[month]);

               else
               {
                  // Copy from current
                  vec_vectorStr vTemp(vWork);

                  // New size
                  vWork.resize(daysCount[month]);

                  // Copy in last day (begin from daysCount[month] + 1)
                  for(int d = daysCount[month]; d < daysCount[cur]; ++d)
                  {
                     for(int d1 = 0; d1 < vTemp[d].size(); ++d1)
                        vWork[daysCount[month] - 1].push_back(vTemp[d][d1]);
                  }
               }
            }
            break;
            default:
            cout << "no operation. Try again." << endl << endl;
            continue;
            break;
         }

         op_count--;
      }
   }

   system("PAUSE");
   return 0;
}

