// Example program
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

using namespace std;

// MergeSort with 2
template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end)
{
   if((range_end - range_begin) < 2)
        return;
   
   vector<typename RandomIt::value_type> elements(range_begin, range_end);
   
   auto middle = begin(elements) + elements.size() / 2;
   
   vector<typename RandomIt::value_type> first(begin(elements), middle);
   vector<typename RandomIt::value_type> second(middle, end(elements));
   
   MergeSort(begin(first), end(first));
   MergeSort(begin(second), end(second));
   
   elements.clear();
   merge(first.begin(), first.end(), second.begin(), second.end(), back_inserter(elements));
   
   swap_ranges(range_begin, range_end, begin(elements));
}

// MergeSort with 3
template <typename RandomIt>
void MergeSort2(RandomIt range_begin, RandomIt range_end)
{
   if((range_end - range_begin) < 3)
        return;
   
   vector<typename RandomIt::value_type> elements(range_begin, range_end);
   
   auto oneOfThird = begin(elements) + elements.size() / 3;
   auto secondOfThird = oneOfThird + (oneOfThird - begin(elements));
   
   vector<typename RandomIt::value_type> first(begin(elements), oneOfThird);
   vector<typename RandomIt::value_type> second(oneOfThird, secondOfThird);
   vector<typename RandomIt::value_type> third(secondOfThird, end(elements));
   
   MergeSort(begin(first), end(first));
   MergeSort(begin(second), end(second));
   MergeSort(begin(third), end(third));
   
   vector<typename RandomIt::value_type> twoOfThird;
   merge(first.begin(), first.end(), second.begin(), second.end(), back_inserter(twoOfThird));
   
   elements.clear();
   merge(twoOfThird.begin(), twoOfThird.end(), third.begin(), third.end(), back_inserter(elements));
   
   swap_ranges(range_begin, range_end, begin(elements));
}

int main()
{
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  
  vector<int> v2 = {6, 4, 7, 6, 4, 4, 0, 1, 5};
  MergeSort2(begin(v2), end(v2));
  for (int x : v2) {
    cout << x << " ";
  }
  cout << endl;
  
  return 0;
}
