// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vec_string;

void MoveStrings(vec_string& source, vec_string& destination)
{
   for(auto x : source)
      destination.push_back(x);

   source.clear();
}

void Print(const vec_string& source)
{
   for(auto x : source)
      cout << x << endl;
}

int main()
{
   vec_string source = { "a", "b", "c" };
   vec_string destination = { "z" };

   MoveStrings(source, destination);
   
   Print(source);
   cout << endl;
   Print(destination);

   cout << endl;

   system("PAUSE");
   return 0;
}

