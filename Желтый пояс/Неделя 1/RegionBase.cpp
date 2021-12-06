// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>
#include <map>
#include <tuple>
#include <set>

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

enum class Lang
{
   DE, FR, IT
};

struct Region
{
   string std_name;
   string parent_std_name;
   map<Lang, string> names;
   int64_t population;
};

bool operator<(const Region& lhs, const Region& rhs)
{
   return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) < 
      tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions)
{
   set<Region> reg;
   int result = 0;

   for(size_t i = 0; i < regions.size(); ++i)
   {
      if(reg.count(regions[i]) == 0)
         reg.insert(regions[i]);
      else
         result++;
   }

   // все уникальны
   if(!result && regions.size())
      result = 1;

   return result;
}

int main()
{
   cout << FindMaxRepetitionCount({
      {
         "Moscow",
         "Russia",
         { { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
         89
      },{
         "Russia",
         "Eurasia",
         { { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
         89
      },{
         "Moscow",
         "Russia",
         { { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
         89
      },{
         "Moscow",
         "Russia",
         { { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
         89
      },{
         "Russia",
         "Eurasia",
         { { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
         89
      },
   }) << endl;

   cout << FindMaxRepetitionCount({
      {
         "Moscow",
         "Russia",
         { { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
         89
      },{
         "Russia",
         "Eurasia",
         { { Lang::DE, "Russland" },{ Lang::FR, "Russie" },{ Lang::IT, "Russia" } },
         89
      },{
         "Moscow",
         "Russia",
         { { Lang::DE, "Moskau" },{ Lang::FR, "Moscou deux" },{ Lang::IT, "Mosca" } },
         89
      },{
         "Moscow",
         "Toulouse",
         { { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
         89
      },{
         "Moscow",
         "Russia",
         { { Lang::DE, "Moskau" },{ Lang::FR, "Moscou" },{ Lang::IT, "Mosca" } },
         31
      },
   }) << endl;

   system("PAUSE");
   return 0;
}

