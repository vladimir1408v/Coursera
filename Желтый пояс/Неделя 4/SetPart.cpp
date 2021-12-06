// Example program
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border)
{
    vector<T> result;
    
    auto findIt = find(begin(elements), end(elements), border);
    if(findIt != end(elements))
    {
      for(auto it = ++findIt; it != elements.end(); ++it)
        result.push_back(*it);
    }

    return result;
}

int main()
{
  for (int x : FindGreaterElements(set<int>{1, 6, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;
  
  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}