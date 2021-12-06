#pragma once

#include <string_view>
#include <vector>
using namespace std;

struct HttpRequest {

	HttpRequest() {};
	HttpRequest(string_view line)
	{
		size_t pos = 0;
		const size_t pos_end = line.npos;

		vector<string_view> result;

		do
		{
			size_t space = line.find(' ', pos);
			if (space == pos)
			{
				pos++;
				continue;
			}

			result.push_back(space == pos_end ?
				line.substr(pos) :
				line.substr(pos, space - pos));

			if (space == pos_end)
				break;
			else
				pos = space + 1;

		} while (true);

		if (result.size() == 3)
		{
			method		= result[0];
			uri			= result[1];
			protocol 	= result[2];
		}
	};

	string_view method, uri, protocol;
};
