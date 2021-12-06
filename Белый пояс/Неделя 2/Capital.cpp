// Capital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> g_operation = { { "CHANGE_CAPITAL", 1 },{ "RENAME", 2 },{ "ABOUT", 3 },{ "DUMP", 4 } };

int main()
{
   while(true)
   {
      map<string, string> capital;
      
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
            case 1:  // CHANGE_CAPITAL 
            {
               string scountry, scapital;
               cin >> scountry >> scapital;
               if(capital.count(scountry) == 0)
               {
                  cout << "Introduce new country " << scountry << " with capital " << scapital << endl;
               } else
               {
                  const string& oldcap = capital[scountry];
                  if(oldcap == scapital)
                  {
                     cout << "Country " << scountry << " hasn't changed its capital" << endl;
                  } else
                  {
                     cout << "Country " << scountry << " has changed its capital from " << oldcap << " to " << scapital << endl;
                  }
               }
               capital[scountry] = scapital;
            }
            break;
            case 2:  // RENAME
            {
               string oldName, newName;
               cin >> oldName >> newName;
               if(oldName == newName || capital.count(newName) == 1 || capital.count(oldName) == 0)
               {
                  cout << "Incorrect rename, skip" << endl;
               } else
               {
                  string desc = "Country " + oldName + " with capital " + capital[oldName] + " has been renamed to " + newName;
                  cout << desc << endl;
                  capital[newName] = capital[oldName];
                  capital.erase(oldName);
               }
            }
            break;
            case 3:  // ABOUT
            {
               string country;
               cin >> country;
               if(capital.count(country) == 0)
                  cout << "Country " << country << " doesn't exist" << endl;
               
               else
                  cout << "Country " << country << " has capital " << capital[country] << endl;
            }
            break;
            case 4:  // DUMP
            {
               if(capital.empty())
               {
                  cout << "There are no countries in the world" << endl;
               } else
               {
                  for(const auto& x : capital)
                     cout << x.first << "/" << x.second << " ";
                  cout << endl;
               }
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

