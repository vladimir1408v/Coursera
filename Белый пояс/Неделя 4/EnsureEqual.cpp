// EnsureEqual.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <exception>

using namespace std;

void EnsureEqual(const string& left, const string& right)
{
   if(left != right)
   {
      throw runtime_error(left + " != " + right);
   }
}

int main()
{
   try
   {
      EnsureEqual("C++ White", "C++ White");
      EnsureEqual("C++ White", "C++ Yellow");
   } catch(runtime_error& e)
   {
      cout << e.what() << endl;
   }

   system("PAUSE");
   return 0;
}
