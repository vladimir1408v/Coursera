// Example program
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

void PermutationsEnumeration(const int& num)
{
    vector<int> numbers;
    for(int i = 1; i <= num; ++i)
       numbers.push_back(i);
       
    do {
        for(auto it = begin(numbers); it != end(numbers); ++it)
            cout << *it << " ";
        cout << endl;    
    } while(next_permutation(numbers.begin(), numbers.end()));
}

int main()
{
    while(true)
    {
        int count;
        cin >> count;
        
        if(count > 9)
            count = 9;
        else if(count < 1)
            count = 1;
        
        PermutationsEnumeration(count);
    }
    
    return 0;
}
