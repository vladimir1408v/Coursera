#include "stdafx.h"
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType
{
   NewBus,
   BusesForStop,
   StopsForBus,
   AllBuses
};

struct Query
{
   QueryType type;
   string bus;
   string stop;
   vector<string> stops;
};

istream& operator >> (istream& is, Query& q)
{
   q.stops.clear();
   string type;

   map<string, QueryType> operations = { 
      { "NEW_BUS",         QueryType::NewBus },
      { "BUSES_FOR_STOP",  QueryType::BusesForStop },
      { "STOPS_FOR_BUS",   QueryType::StopsForBus },
      { "ALL_BUSES",       QueryType::AllBuses }
   };

   is >> type;
   q.type = operations[type];

   switch(q.type)
   {
      case QueryType::NewBus:
      {
         int stop_count;

         is >> q.bus;
         is >> stop_count;

         if(stop_count < 0)
            stop_count = 0;

         for(int i = 0; i < stop_count; ++i)
         {
            string stop;
            is >> stop;

            q.stops.push_back(stop);
         }
      }
      break;
      case QueryType::BusesForStop:
      {
         string stop;
         is >> q.stop;
      }
      break;
      case QueryType::StopsForBus:
         is >> q.bus;
      break;
      case QueryType::AllBuses:
      break;
   }

   return is;
}

struct BusesForStopResponse
{
   vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r)
{
   if(r.buses.size())
   {
      for(const string& bus : r.buses)
         os << bus << " ";
      os << endl;
   }

   else
      os << "No stop" << endl;

   return os;
}

struct StopsForBusResponse
{
   string bus;
   vector<pair<string, vector<string>>> stops;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r)
{
   if(r.stops.size())
   {
      for(const auto& stop : r.stops)
      {
         os << "Stop " << stop.first << ": ";
         if(stop.second.size() == 1)
            os << "no interchange";

         else
         {
            for(const string& bus : stop.second)
               if(r.bus != bus)
                  os << bus << " ";
         }

         os << endl;
      }
   }

   else
      os << "No bus" << endl;
   
   return os;
}

struct AllBusesResponse
{
   map<string, vector<string>> buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r)
{
   if(r.buses.size())
   {
      for(const auto& bus : r.buses)
      {
         os << "Bus " << bus.first << ": ";
         for(const string& stop : bus.second)
            os << stop << " ";
         os << endl;
      }
   }

   else
      os << "No buses" << endl;

   return os;
}

class BusManager
{
public:
   void AddBus(const string& bus, const vector<string>& stops)
   {
      buses_to_stops[bus] = stops;
      for(const string& stop : stops)
         stops_to_buses[stop].push_back(bus);
   }

   BusesForStopResponse GetBusesForStop(const string& stop) const
   {
      BusesForStopResponse r;

      if(stops_to_buses.count(stop) != 0)
         for(const string& bus : stops_to_buses.at(stop))
            r.buses.push_back(bus);

      return r;
   }

   StopsForBusResponse GetStopsForBus(const string& bus) const
   {
      StopsForBusResponse r;
      r.bus = bus;

      if(buses_to_stops.count(bus) != 0)
         for(const string& stop : buses_to_stops.at(bus))
         {
            auto p = make_pair(stop, stops_to_buses.at(stop));
            r.stops.push_back(p);
         }

      return r;
   }

   AllBusesResponse GetAllBuses() const
   {
      AllBusesResponse r;

      if(!buses_to_stops.empty())
         for(const auto& bus_item : buses_to_stops)
            r.buses[bus_item.first] = bus_item.second;

      return r;
   }

protected:
   map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main()
{
   int query_count;
   Query q;

   cin >> query_count;

   BusManager bm;
   for(int i = 0; i < query_count; ++i)
   {
      cin >> q;
      switch(q.type)
      {
         case QueryType::NewBus:
         bm.AddBus(q.bus, q.stops);
         break;
         case QueryType::BusesForStop:
         cout << bm.GetBusesForStop(q.stop) << endl;
         break;
         case QueryType::StopsForBus:
         cout << bm.GetStopsForBus(q.bus) << endl;
         break;
         case QueryType::AllBuses:
         cout << bm.GetAllBuses() << endl;
         break;
      }
   }

   system("PAUSE");
   return 0;
}