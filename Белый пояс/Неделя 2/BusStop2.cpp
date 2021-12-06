// Capital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>

using namespace std;

map<string, int> g_operation = { { "BUSES_FOR_STOP", 1 },{ "STOPS_FOR_BUS", 2 },{ "ALL_BUSES", 3 },{ "NEW_BUS", 4 } };

int main()
{
   while(true)
   {
      map<vector<string>, int> buses;

      int op_count;
      cout << "Enter operations count:" << endl << endl;
      cin >> op_count;

      cout << endl << "Enter:" << endl << endl;

      while(op_count != 0)
      {
         int stop_count = 0;
         cin >> stop_count;

         vector<string> stops;
         for(int i = 0; i < stop_count; ++i)
         {
            string stop;
            cin >> stop;

            stops.push_back(stop);
         }

         stringstream ss;
         if(buses.count(stops) != 0)
         {
            ss << buses[stops];
            cout << "Already exists for " + ss.str();
         }

         else
         {
            int bus = buses.size() + 1;
            ss.clear();
            ss << bus;
            buses[stops] = bus;
            cout << "New bus " + ss.str();
         }

         cout << endl << endl;

         op_count--;
      }
   }

   system("PAUSE");
   return 0;
}

