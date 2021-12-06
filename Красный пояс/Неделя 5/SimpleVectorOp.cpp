// SimpleVectorOp.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "simple_vector.h"
#include "test_runner.h"

#include <numeric>
#include <vector>
#include <tuple>

using namespace std;

void TestCopyAssignment() {	SimpleVector<int> numbers(10);
	iota(numbers.begin(), numbers.end(), 1);

	SimpleVector<int> dest;

	size_t d = dest.Size();
	ASSERT_EQUAL(d, 0u);

	dest = numbers;

	d = dest.Size();
	size_t n = numbers.Size();

	ASSERT_EQUAL(d, n);
	ASSERT(dest.Capacity() >= dest.Size());
	ASSERT(equal(dest.begin(), dest.end(), numbers.begin()));
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestCopyAssignment);

	system("PAUSE");
	return 0;
}

