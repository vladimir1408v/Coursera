// Example program
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s)
{
    vector<string> result;
    
    auto it = begin(s);   
    while(it != end(s))
    {
        auto spaceIt = find(it, end(s), ' ');
        string str(it, spaceIt);
        result.push_back(str);
        
        if(spaceIt != end(s))
            spaceIt++;
        
        it = spaceIt;
    }
    
    return result;     
}

int main()
{
  string s = "C Cpp Java Python";

  vector<string> words = SplitIntoWords(s);
  cout << words.size() << " ";
  for (auto it = begin(words); it != end(words); ++it) {
    if (it != begin(words)) {
      cout << "/";
    }
    cout << *it;
  }
  cout << endl;
  
  return 0;
}