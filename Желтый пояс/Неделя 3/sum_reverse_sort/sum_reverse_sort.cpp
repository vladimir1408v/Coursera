#include "stdafx.h"
#include "sum_reverse_sort.h"
#include <algorithm>

int Sum(int x, int y)
{
   return x + y;
}

string Reverse(string s)
{
   string result(s);
   reverse(result.begin(), result.end());

   return result;
}

void Sort(vector<int>& nums)
{
   sort(nums.begin(), nums.end());
}