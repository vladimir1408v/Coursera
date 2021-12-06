// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>>

using namespace std;

class Person
{
public:
   void ChangeFirstName(int year, const string& first_name)
   {
      names[year] = first_name;
   }
   void ChangeLastName(int year, const string& last_name)
   {
      lastNames[year] = last_name;
   }
   string GetFullName(int year)
   {
      string fullName = "";
      string name = GetName(names, year);
      string lastName = GetName(lastNames, year);

      if(name.empty() && !lastName.empty())
         fullName = lastName + " with unknown first name";
      else if(!name.empty() && lastName.empty())
         fullName = name + " with unknown last name";
      else if(!name.empty() && !lastName.empty())
         fullName = name + " " + lastName;
      else
         fullName = "Incognito";

      return fullName;
   }
private:
   map<int, string> names;
   map<int, string> lastNames;

   // получение имени 
   string GetName(map<int, string> names, int year)
   {
      string name;

      auto it = names.upper_bound(year);

      if(it != names.begin())
         name = prev(it)->second;

      return name;
   }
};

int main()
{
   Person person;

   person.ChangeFirstName(1965, "Polina");
   person.ChangeLastName(1967, "Sergeeva");
   for(int year : {1900, 1965, 1990})
   {
      cout << person.GetFullName(year) << endl;
   }

   person.ChangeFirstName(1970, "Appolinaria");
   for(int year : {1969, 1970})
   {
      cout << person.GetFullName(year) << endl;
   }

   person.ChangeLastName(1968, "Volkova");
   for(int year : {1969, 1970})
   {
      cout << person.GetFullName(year) << endl;
   }

   system("PAUSE");
   return 0;
}

