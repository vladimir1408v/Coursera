// Example program
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

// компаратор для безработных
bool compNoEmployed(const Person& p)
{
   return p.is_employed == false; 
}

void PrintStats(vector<Person> persons)
{
    auto maleIt = partition(begin(persons), end(persons), [](const Person& p)
    {
        return p.gender == Gender::FEMALE;
    });
    
    auto femaleJobIt = partition(begin(persons), maleIt, compNoEmployed);
    auto maleJobIt = partition(maleIt, end(persons), compNoEmployed);
    
    cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl; 
    cout << "Median age for females = " << ComputeMedianAge(begin(persons), maleIt) << endl; 
    cout << "Median age for males = " << ComputeMedianAge(maleIt, end(persons)) << endl; 
    cout << "Median age for employed females = " << ComputeMedianAge(femaleJobIt, maleIt) << endl; 
    cout << "Median age for unemployed females = " << ComputeMedianAge(begin(persons), femaleJobIt) << endl;
    cout << "Median age for employed males = " << ComputeMedianAge(maleJobIt, end(persons)) << endl;
    cout << "Median age for unemployed males = " << ComputeMedianAge(maleIt, maleJobIt) << endl;
}

int main()
{
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
