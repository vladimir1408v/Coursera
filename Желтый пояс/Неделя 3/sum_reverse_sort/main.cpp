// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <ostream>
#include "sum_reverse_sort.h"

ostream& operator<<(ostream& stream, vector<int> v)
{
   for(const auto& i : v)
      stream << i << " ";
   stream << endl;

   return stream;
}

int main()
{
   cout << Sum(10, 15) << endl;
   cout << Reverse("Kirill") << endl;

   vector<int> v = { 9,8,7,6,5,4,3,2,1 };
   Sort(v);
   cout << v << endl;

   system("PAUSE");
   return 0;
}

