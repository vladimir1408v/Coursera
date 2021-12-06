// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>

typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

using namespace std;

typedef vector<s32> vec_int;

int main()
{
   while(true)
   {
      try
      {
         s32 n;
         u16 r; // u16 так как u8 воспринимается cin как char

         cout << "Enter n,r:" << endl << endl;
         cin >> n >> r;

         if(n < 0)
            throw out_of_range("n < 0");

         u64 weight = 0;
         cout << endl << "Enter w,h,d:" << endl << endl;
         for(size_t i = 0; i < n; ++i)
         {
            u16 w, h, d;
            cin >> w >> h >> d;

            u64 v = w * h * d;
            u64 w1 = v * r;
            weight += w1;
         }

         cout << endl << weight << endl << endl;

      } catch(out_of_range& e)
      {
         cout << e.what() << endl;
         continue;
      }
   }

   system("PAUSE");
   return 0;
}

