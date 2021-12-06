
#include "stdafx.h"
#include <iostream>
#include <exception>
#include <string>
#include <sstream>

using namespace std;

string AskTimeServer()
{
   //return "sssss";
   //throw invalid_argument("argument");
}

void EnsureNextSymbolAndSkip(stringstream& stream)
{
   if(stream.peek() != ':')
   {
      throw system_error(error_code());
   }
   stream.ignore(1);
}

bool CheckTime(const string& s)
{
   bool result = true;
   int hour = 0;
   int min = 0;
   int sec = 0;

   stringstream stream(s);
   stream >> hour;
   EnsureNextSymbolAndSkip(stream);
   stream >> min;
   EnsureNextSymbolAndSkip(stream);
   stream >> sec;
   
   return result;
}

class TimeServer
{
public:
   string GetCurrentTime()
   {
      try
      {
         string time = AskTimeServer();
         bool check = CheckTime(time);
         if(check)
            last_fetched_time = time;
      } catch(system_error& se)
      {
         // system_error обрабатываем здесь или идет проброс дальше
         cout << "Exception got: " << se.what() << endl;
      }

      return last_fetched_time;
   }

private:
   string last_fetched_time = "00:00:00";
};

int main()
{
   TimeServer ts;
   try
   {
      cout << ts.GetCurrentTime() << endl;
   } catch(exception& e)
   {
      cout << "Exception got: " << e.what() << endl;
   }

   system("PAUSE");
   return 0;
}