#pragma once

#include <string>
using namespace std;

struct Date {
	int year, month, day;

	friend ostream& operator<<(ostream &os, const Date& date);
	friend istream& operator>>(istream &is, Date& date);
	friend bool operator<(const Date& lhs, const Date& rhs);
	friend bool operator==(const Date& lhs, const Date& rhs);
};

struct Time {
	int hours, minutes;

	friend ostream& operator<<(ostream &os, const Time& date);
	friend istream& operator>>(istream &is, Time& date);
	friend bool operator<(const Time& lhs, const Time& rhs);
	friend bool operator==(const Time& lhs, const Time& rhs);
};

bool operator<(const Time& lhs, const Time& rhs)
{
	int lmin = lhs.hours * 60 + lhs.minutes;
	int rmin = rhs.hours * 60 + rhs.minutes;

	return lmin < rmin;
}

bool operator<(const Date& lhs, const Date& rhs)
{
	if (lhs.year < rhs.year) return true;
	else if(lhs.year == rhs.year && lhs.month < rhs.month) return true;
	else if (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day < rhs.day) return true;

	return false;
}

bool operator==(const Date& lhs, const Date& rhs)
{
	return (lhs.year == rhs.year && lhs.month == rhs.month && lhs.day == rhs.day);
}

bool operator==(const Time& lhs, const Time& rhs)
{
	return (lhs.hours == rhs.hours && lhs.minutes == rhs.minutes);
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.year << " " << date.month << " " << date.day;

	return os;
}

ostream& operator<<(ostream& os, const Time& date)
{
	os << date.hours << ":" << date.minutes;

	return os;
}

istream& operator>>(istream& is, Date& date)
{
	is >> date.year;
	is.ignore(1, '-');
	is >> date.month;
	is.ignore(1, '-');
	is >> date.day;

	return is;
}

istream& operator>>(istream& is, Time& date)
{
	is >> date.hours;
	is.ignore(1, ':');
	is >> date.minutes;

	return is;
}


struct AirlineTicket {
	string from;
	string to;
	string airline;
	Date departure_date;
	Time departure_time;
	Date arrival_date;
	Time arrival_time;
	int price;
};