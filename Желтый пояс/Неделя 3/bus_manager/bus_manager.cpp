#include "stdafx.h"
#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops)
{
   buses_to_stops[bus] = stops;
   for(const string& stop : stops)
      stops_to_buses[stop].push_back(bus);
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const
{
   BusesForStopResponse r;

   if(stops_to_buses.count(stop) != 0)
      for(const string& bus : stops_to_buses.at(stop))
         r.buses.push_back(bus);

   return r;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const
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

AllBusesResponse BusManager::GetAllBuses() const
{
   AllBusesResponse r;

   if(!buses_to_stops.empty())
      for(const auto& bus_item : buses_to_stops)
         r.buses[bus_item.first] = bus_item.second;

   return r;
}           