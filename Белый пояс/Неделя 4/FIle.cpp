// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <regex>
#include <fstream>

using namespace std;

void Print(const string& path)
{
   ifstream input(path);
   double var;
   if(input)
   {
      while(getline(input, var))
      {
         cout << fixed << setprecision(3);
         cout << str << endl;
      }

      cout << endl;
   }
}

int main()
{
   Print("input.txt");

   system("PAUSE");
   return 0;
}

