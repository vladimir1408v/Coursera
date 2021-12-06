// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

typedef vector<int> vec_int;
map<string, int> g_operation = { {"WORRY", 1}, {"QUIET", 2}, {"COME", 3}, {"WORRY_COUNT", 4} };

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

      vec_int vqueue;
      cout << endl << "Enter operations:" << endl << endl;

      while(op_count != 0)
      {
         int i;
         string op_string;
         cin >> op_string;
         int op_number = g_operation[op_string];

         if(op_number != 4)  // WORRY_COUNT
            cin >> i;

         switch(op_number)
         {
            case 1:  // WORRY 
            case 2:  // QUIET
            {
               if(vqueue.size() && i <= vqueue.size() - 1)
                  vqueue[i] = op_number;

               else
               {
                  cout << "queue is empty or no index. Try again." << endl << endl;
                  continue;
               }
            }
            break;

            case 3:  // COME
            {
               if(i < 0)
               {
                  i = abs(i);

                  if(vqueue.size() && i <= vqueue.size())
                     vqueue.erase(vqueue.end() - i, vqueue.end());

                  else
                  {
                     cout << "removed more than queue. Try again." << endl << endl;
                     continue;
                  }
               }

               else
               {
                  for(size_t q = 0; q < i; q++)
                     vqueue.push_back(2); // QUIET
               }
            }
            break;
            case 4:  // WORRY_COUNT
            {
               vec_int result;

               for(int i = 0; i < vqueue.size(); ++i)
               {
                  if(vqueue[i] == 1) // WORRY 
                     result.push_back(i);
               }

               cout << result.size() << endl << endl;
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

