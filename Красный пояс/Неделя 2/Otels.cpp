// EBook.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "profile.h"

#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>

using namespace std;

class ReadingManager
{
public:
   ReadingManager() {};

   void Read(int user_id, int page_count)
   {
      // добавление
      if(user.count(user_id) == 0)
         AddUser(user_id);

      // обработка не нужного
      if(pages.count(user[user_id]) != 0 && pages[user[user_id]].count(user_id) != 0)
      {
         pages[user[user_id]].erase(user_id);
         if(pages[user[user_id]].size() == 0)
            pages.erase(user[user_id]);
      }

      // обновление инфы
      user[user_id] = page_count;
      pages[page_count].insert(user_id);
   }

   double Cheer(int user_id) const
   {
      // обработка условий
      if(user.count(user_id) == 0)
         return 0;

      const int user_count = GetUserCount();
      if(user_count == 1)
         return 1;

      // обработка граничных значений
      auto userIter = pages.find(user.at(user_id));
      if(userIter == begin(pages))
         return 0;
      else if(userIter == prev(end(pages)) && prev(end(pages))->second.size() == 1)
         return 1; 

      else
      {
         // подсчет
         int count = 0;
         for(auto it = begin(pages); it != userIter; ++it)
            count += it->second.size();

         return ((double)count / (count + 1.0));
      }
   }

private:

   map<int, int> user;
   map<int, set<int>> pages;

   int GetUserCount() const
      { return user.size(); }
   void AddUser(int user_id)
      { user.insert({ user_id , 0 }); }
};

void Test()
{
   LOG_DURATION("ReadingManager");

   ReadingManager manager;

   cout << setprecision(6) << manager.Cheer(5) << "\n";
   manager.Read(1, 10);
   cout << setprecision(6) << manager.Cheer(1) << "\n";
   manager.Read(2, 5);
   manager.Read(3, 7);
   cout << setprecision(6) << manager.Cheer(2) << "\n";
   cout << setprecision(6) << manager.Cheer(3) << "\n";
   manager.Read(3, 10);
   cout << setprecision(6) << manager.Cheer(3) << "\n";
   manager.Read(3, 11);
   cout << setprecision(6) << manager.Cheer(3) << "\n";
   cout << setprecision(6) << manager.Cheer(1) << "\n";
}

int main()
{
   Test();

   /*ios::sync_with_stdio(false);
   cin.tie(nullptr);

   ReadingManager manager;

   int query_count;
   cin >> query_count;

   for (int query_id = 0; query_id < query_count; ++query_id) {
   string query_type;
   cin >> query_type;
   int user_id;
   cin >> user_id;

   if (query_type == "READ") {
   int page_count;
   cin >> page_count;
   manager.Read(user_id, page_count);
   }
   else if (query_type == "CHEER") {
   cout << setprecision(6) << manager.Cheer(user_id) << "\n";
   }
   }*/

   system("PAUSE");
   return 0;
}