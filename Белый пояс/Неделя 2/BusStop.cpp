// Capital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> g_operation = { { "BUSES_FOR_STOP", 1 },{ "STOPS_FOR_BUS", 2 },{ "ALL_BUSES", 3 },{ "NEW_BUS", 4 } };

int main()
{
   while(true)
   {
      map<string, vector<string>> buses;

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
            case 1:  // BUSES_FOR_STOP 
            {
               string stop;
               cin >> stop;

               bool result = false;
               for(const auto& x : buses)
               {
                  for(const auto& j : x.second)
                  {
                     if(j == stop)
                     {
                        result = true;
                        cout << x.first << " ";
                        break;
                     }
                  }
               }

               if(!result)
                  cout << "No stop";

               cout << endl << endl;
            }
            break;
            case 2:  // STOPS_FOR_BUS
            {
               string bus;
               cin >> bus;

               if(buses.count(bus) != 0)
               {
                  for(const auto& j : buses[bus])
                  {
                     cout << "Stop " + j + ": ";
                     bool result = false;
                     for(const auto& b : buses)
                     {
                        if(bus != b.first)
                        {
                           for(const auto& s : b.second)
                           {
                              if(s == j)
                              {
                                 result = true;
                                 cout << b.first << " ";
                              }
                           }
                        }
                     }

                     if(!result)
                        cout << "no interchange" << endl;
                     else
                        cout << endl;
                  }
               } else
                  cout << "No bus" << endl;

               cout << endl;
            }
            break;
            case 3:  // ALL_BUSES
            {
               for(const auto& x : buses)
               {
                  cout << "Bus " + x.first + ": ";
                  for(const auto& j : x.second)
                     cout << j << " ";

                  cout << endl;
               }

               if(!buses.size())
                  cout << "No buses";

               cout << endl << endl;
            }
            break;
            case 4:  // NEW_BUS
            {
               string bus;
               int stop_count = 0;

               cin >> bus >> stop_count;
               for(int i = 0; i < stop_count; ++i)
               {
                  string stop;
                  cin >> stop;

                  buses[bus].push_back(stop);
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

