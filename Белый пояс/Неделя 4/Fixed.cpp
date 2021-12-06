// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <regex>
#include <iomanip>
#include <fstream>

using namespace std;

void Print(const string& path)
{
   ifstream input(path);
   string var;
   if(input)
   {
      while(getline(input, var))
      {
         double d = atof(var.c_str());
         cout << fixed << setprecision(3);
         cout << d << endl;
      }

      cout << endl;
      input.close();
   }
}

int main()
{
   Print("input.txt");

   system("PAUSE");
   return 0;
}

