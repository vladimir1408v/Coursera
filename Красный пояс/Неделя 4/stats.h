#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
#include <iostream>
using namespace std;

class Stats {
public:
	Stats() {
		methods_["GET"] = 0;
		methods_["PUT"] = 0;
		methods_["DELETE"] = 0;
		methods_["POST"] = 0;
		methods_["UNKNOWN"] = 0;

		uri_["/"] = 0;
		uri_["/order"] = 0;
		uri_["/product"] = 0;
		uri_["/basket"] = 0;
		uri_["/help"] = 0;
		uri_["unknown"] = 0;
	}

	void AddMethod(string_view method)
	{
		if(methods_.count(method))
			methods_[method]++;
		else
			methods_["UNKNOWN"]++;
	};

	void AddUri(string_view uri)
	{
		if (uri_.count(uri))
			uri_[uri]++;
		else
			uri_["unknown"]++;
	};

	const map<string_view, int>& GetMethodStats() const { return methods_; };
	const map<string_view, int>& GetUriStats() const { return uri_; };

private:
	map<string_view, int> methods_;
	map<string_view, int> uri_;
};

HttpRequest ParseRequest(string_view line)
{
	return HttpRequest(line);
};


