// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <regex>
#include <iomanip>
#include <fstream>

using namespace std;

struct student
{
   string name = "";
   string lastname = "";
   int birthday = 0;
   int birthmonth = 0;
   int birthyear = 0;
};

typedef vector<student> vec_stud;
map<string, int> g_operation = { { "name", 1 },{ "date", 2 }};

int main()
{
   while(true)
   {
      vec_stud students;
      int stud_count = 0;
      cout << "Enter students count:" << endl << endl;
      cin >> stud_count;
      
      while(stud_count != 0)
      {
         student stud;
         cout << endl << "Enter student:" << endl << endl;
         cin >> stud.name >> stud.lastname >> stud.birthday >> stud.birthmonth >> stud.birthyear;

         students.push_back(stud);
         stud_count--;
      }

      int op_count;
      cout << endl << "Enter operations count:" << endl << endl;
      cin >> op_count;

      cout << endl << "Enter operation:" << endl << endl;

      while(op_count != 0)
      {
         int i = 0;
         string op_string;
         cin >> op_string >> i;
         int op_number = g_operation[op_string];

         i -= 1;
         if(i < 0 || i > students.size() - 1)
            op_number = 3;

         switch(op_number)
         {
            case 1:  // name 
            {
               cout << students[i].name + " " + students[i].lastname << endl << endl;
            }
            break;
            case 2:  // date
            {
               ostringstream bithday;
               bithday << students[i].birthday << "." << students[i].birthmonth << "." << students[i].birthyear;
               cout << bithday.str() << endl << endl;
            }
            break;
            default:
            cout << "bad request" << endl << endl;
            break;
         }

         op_count--;
      }
   }

   system("PAUSE");
   return 0;
}



