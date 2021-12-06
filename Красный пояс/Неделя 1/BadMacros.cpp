#include "stdafx.h"
#include "test_runner.h"

#include <ostream>
#include <iostream>

using namespace std;

// избавились от ;
#define PRINT_VALUES(out, x, y) out << (x) << endl << (y) << endl

int main() {

	TestRunner tr;
	tr.RunTest([] {
		ostringstream output;
		PRINT_VALUES(output, 5, "red belt");
		ASSERT_EQUAL(output.str(), "5\nred belt\n");
	}, "PRINT_VALUES usage example");

	system("PAUSE");
	return 0;
}