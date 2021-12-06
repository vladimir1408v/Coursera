// Translator.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "test_runner.h"
#include <string>
#include <vector>

using namespace std;

class Translator {
	using TranslateList = map<string_view, string_view>;
public:
	void Add(string_view in_source, string_view in_target) {
		const string_view source = CheckAndGetView(in_source);
		const string_view target = CheckAndGetView(in_target);
		
		forward[source] = target;
		backward[target] = source;
	}
	string_view TranslateForward(string_view source) const {
		return Translate(forward, source);
	}
	string_view TranslateBackward(string_view target) const {
		return Translate(backward, target);
	}

private:
	string_view Translate(const TranslateList& dict, string_view s) {
		if (dict.count(s) != 0)
			return dict.at(s);

		return{};
	}

	string_view CheckAndGetView(string_view s) {
		for (const auto* translateList : { &forward, &backward }) {
			if (translateList->count(s) != 0) {
				return translateList->at(s);
			}
		}
		return buffer.emplace_back(s);
	}

	TranslateList forward;
	TranslateList backward;
	deque<string> buffer;
};

void TestSimple() {
	Translator translator;
	translator.Add(string("okno"), string("window"));
	translator.Add(string("stol"), string("table"));

	ASSERT_EQUAL(translator.TranslateForward("okno"), "window");
	ASSERT_EQUAL(translator.TranslateBackward("table"), "stol");
	ASSERT_EQUAL(translator.TranslateBackward("stol"), "");
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestSimple);
	return 0;
}

