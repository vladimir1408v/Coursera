// coursera1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <cstdint>
#include <map>
#include <tuple>
#include <set>
#include <utility>

typedef uint8_t   u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

using namespace std;

typedef vector<s32> vec_int;

// Перечислимый тип для статуса задачи
enum class TaskStatus
{
   NEW,          // новая
   IN_PROGRESS,  // в разработке
   TESTING,      // на тестировании
   DONE          // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks
{
public:
   // Получить статистику по статусам задач конкретного разработчика
   const TasksInfo& GetPersonTasksInfo(const string& person) const
   {
      return employee.at(person);
   }

   // Добавить новую задачу (в статусе NEW) для конкретного разработчитка
   void AddNewTask(const string& person)
   {
      if(employee.count(person) == 0)
      {
         employee[person].insert(make_pair(TaskStatus::NEW,          1));
         employee[person].insert(make_pair(TaskStatus::IN_PROGRESS,  0));
         employee[person].insert(make_pair(TaskStatus::TESTING,      0));
         employee[person].insert(make_pair(TaskStatus::DONE,         0));
      }

      else
         employee[person][TaskStatus::NEW]++;
   }

   // Обновить статусы по данному количеству задач конкретного разработчика,
   // подробности см. ниже
   tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string& person, int task_count)
   {
      u32 cur_count = GetNotCompletedTaskCount(person);
      if(employee.count(person) == 0 || !cur_count)
         return { {} , {} };

      if(task_count > cur_count)
         task_count = cur_count;

      TasksInfo& currentTask = employee.at(person);

      TasksInfo untouchedTask;
      TasksInfo updatedTask;

      for(int j = static_cast<int>(TaskStatus::NEW); j < static_cast<int>(TaskStatus::DONE); ++j)
      {
         TaskStatus status = static_cast<TaskStatus>(j);
         TaskStatus statusNext = static_cast<TaskStatus>(j + 1);
         if(currentTask[status] > 0)
         {
            while(task_count > 0 && currentTask[status] > 0)
            {
               // обновляем у работника
               currentTask[status] -= 1;
               currentTask[statusNext] += 1;

               untouchedTask[status] = currentTask[status];
               if(updatedTask.count(status) != 0)
                  untouchedTask[status] -= updatedTask[status];  // не учитваем обновленные задачи
               
               // от 0вых избавляемся
               if(untouchedTask[status] == 0)
                  untouchedTask.erase(status);

               updatedTask[statusNext] += 1;

               task_count--;
            }

            if(task_count == 0)
               break;

         } else
            continue;
      }

      return { updatedTask , untouchedTask };
   }

private:

   u32 GetNotCompletedTaskCount(const string& person)
   {
      u32 count = 0;

      for(const auto& item : employee[person])
      {
         if(item.first != TaskStatus::DONE)
            count += item.second;
      }

      return count;
   }

private:
   map<string, TasksInfo> employee;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info)
{
   cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
      ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
      ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
      ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main()
{
   TeamTasks tasks;
   tasks.AddNewTask("Ilia");
   for(int i = 0; i < 3; ++i)
   {
      tasks.AddNewTask("Ivan");
   }
   cout << "Ilia's tasks: ";
   PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
   cout << "Ivan's tasks: ";
   PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));

   TasksInfo updated_tasks, untouched_tasks;

   tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
   cout << "Updated Ivan's tasks: ";
   PrintTasksInfo(updated_tasks);
   cout << "Untouched Ivan's tasks: ";
   PrintTasksInfo(untouched_tasks);

   tie(updated_tasks, untouched_tasks) =
      tasks.PerformPersonTasks("Ivan", 2);
   cout << "Updated Ivan's tasks: ";
   PrintTasksInfo(updated_tasks);
   cout << "Untouched Ivan's tasks: ";
   PrintTasksInfo(untouched_tasks);

   system("PAUSE");
   return 0;
}

