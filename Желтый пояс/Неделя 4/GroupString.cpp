
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, char prefix)
{
   string prefixStr = "";
   prefixStr.push_back(prefix);

   auto first = lower_bound(range_begin, range_end, prefixStr);

   prefixStr[prefixStr.size() - 1]++;
   auto second = lower_bound(range_begin, range_end, prefixStr);

   return{ first, second };
}

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(RandomIt range_begin, RandomIt range_end, const string& prefix)
{
   string prefixStr = prefix;
   
   auto first = lower_bound(range_begin, range_end, prefixStr);

   prefixStr[prefixStr.size() - 1]++;
   auto second = lower_bound(range_begin, range_end, prefixStr);

   return{ first, second };
}

int main()
{
   {
      const vector<string> sorted_strings = { "moscow", "murmansk", "vologda" };

      const auto m_result =
         FindStartsWith(begin(sorted_strings), end(sorted_strings), 'm');
      for(auto it = m_result.first; it != m_result.second; ++it)
      {
         cout << *it << " ";
      }
      cout << endl;

      const auto p_result =
         FindStartsWith(begin(sorted_strings), end(sorted_strings), 'p');
      cout << (p_result.first - begin(sorted_strings)) << " " <<
         (p_result.second - begin(sorted_strings)) << endl;

      const auto z_result =
         FindStartsWith(begin(sorted_strings), end(sorted_strings), 'z');
      cout << (z_result.first - begin(sorted_strings)) << " " <<
         (z_result.second - begin(sorted_strings)) << endl;
   }
   
   {
      const vector<string> sorted_strings = { "moscow", "motovilikha", "murmansk" };

      const auto mo_result =
         FindStartsWith(begin(sorted_strings), end(sorted_strings), "mo");
      for(auto it = mo_result.first; it != mo_result.second; ++it)
      {
         cout << *it << " ";
      }
      cout << endl;

      const auto mt_result =
         FindStartsWith(begin(sorted_strings), end(sorted_strings), "mt");
      cout << (mt_result.first - begin(sorted_strings)) << " " <<
         (mt_result.second - begin(sorted_strings)) << endl;

      const auto na_result =
         FindStartsWith(begin(sorted_strings), end(sorted_strings), "na");
      cout << (na_result.first - begin(sorted_strings)) << " " <<
         (na_result.second - begin(sorted_strings)) << endl;
   }

   system("PAUSE");
   return 0;
}
