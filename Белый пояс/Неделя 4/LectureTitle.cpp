// Init.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <regex>
#include <cctype>

using namespace std;

struct Specialization
{
   string specialization = "";
   explicit Specialization(string in_str)
   {
      specialization = in_str;
   }
};

struct Course
{
   string course = "";
   explicit Course(string in_str)
   {
      course = in_str;
   }
};

struct Week
{
   string week = "";
   explicit Week(string in_str)
   {
      week = in_str;
   }
};

struct LectureTitle
{
   string specialization = "";
   string course = "";
   string week = "";

   LectureTitle(Specialization in_special, Course in_course, Week in_week)
   {
      specialization = in_special.specialization;
      course = in_course.course;
      week = in_week.week;
   }
};

int main()
{
   LectureTitle title(
      Specialization("C++"),
      Course("White belt"),
      Week("4th")
   );

   system("PAUSE");
   return 0;
}

