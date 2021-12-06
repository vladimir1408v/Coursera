// Init.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

struct Incognizable
{
   Incognizable() {};
   Incognizable(int in_first) {first = in_first;}
   Incognizable(int in_first, int in_second)
      { first = in_first; second = in_second; }

   int first = 0;
   int second = 0;
};

int main()
{
   Incognizable a;
   Incognizable b = {};
   Incognizable c = { 0 };
   Incognizable d = { 0, 1 };
   return 0;
}

