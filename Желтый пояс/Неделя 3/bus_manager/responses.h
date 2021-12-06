#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

struct BusesForStopResponse
{
   vector<string> buses;
};

struct StopsForBusResponse
{
   string bus;
   vector<pair<string, vector<string>>> stops;
};

struct AllBusesResponse
{
   map<string, vector<string>> buses;
};


ostream& operator << (ostream& os, const BusesForStopResponse& r);
ostream& operator << (ostream& os, const StopsForBusResponse& r);
ostream& operator << (ostream& os, const AllBusesResponse& r);