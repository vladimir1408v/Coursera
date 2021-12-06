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

void Print(const vector<int>& vector, int in_row, int in_colums)
{
   int colums = 0;
   for(const int& n : vector)
   {
      if(colums == in_colums)
      {
         colums = 0;
         cout << endl;
      }

      cout << setw(10);
      cout << n;

      colums++;
   }
}

int main()
{
   int row = 0;
   int colums = 0;
   vector<int> numbers;
   ifstream input("input.txt");
   if(input)
   {
      input >> row;
      input.ignore(1);
      input >> colums;

      for(int i = 0; i < row; ++i)
      {
         for(int j = 0; j < colums; ++j)
         {
            int number = 0;
            input >> number;
            input.ignore(1);

            numbers.push_back(number);
         }
      }
      input.close();
   }

   Print(numbers, row, colums);

   system("PAUSE");
   return 0;
}

