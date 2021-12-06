// Swap.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "test_runner.h"

#include <algorithm>
#include <numeric>
using namespace std;

template <typename T>
void Swap(T* first, T* second)
{
	auto temp = *first;
	*first = *second;
	*second = temp;
}

template <typename T>
void SortPointers(vector<T*>& pointers)
{
	sort(pointers.begin(), pointers.end(), [](T* first, T* last) { return *first < *last; });
}

template <typename T>
void ReversedCopy(T* source, size_t count, T* destination)
{
	T* sourceFinish = source + count;
	T* destinationFinish = destination + count;

	if (destination >= sourceFinish || destinationFinish <= source) {
		reverse_copy(source, sourceFinish, destination);
	}
	else if (destination > source) {
		for (size_t i = 0; source + i < destination; ++i) {
			*(destinationFinish - i - 1) = *(source + i);
		}
		reverse(destination, sourceFinish);
	}
	else {
		for (size_t i = 0; sourceFinish - i - 1 >= destinationFinish; ++i) {
			*(destination + i) = *(sourceFinish - i - 1);
		}
		reverse(source, destinationFinish);
	}
}

void TestSwap() {
	int a = 1;
	int b = 2;
	Swap(&a, &b);
	ASSERT_EQUAL(a, 2);
	ASSERT_EQUAL(b, 1);

	string h = "world";
	string w = "hello";
	Swap(&h, &w);
	ASSERT_EQUAL(h, "hello");
	ASSERT_EQUAL(w, "world");
}

void TestSortPointers() {
	int one = 1;
	int two = 2;
	int three = 3;

	vector<int*> pointers;
	pointers.push_back(&two);
	pointers.push_back(&three);
	pointers.push_back(&one);

	SortPointers(pointers);

	ASSERT_EQUAL(pointers.size(), 3u);
	ASSERT_EQUAL(*pointers[0], 1);
	ASSERT_EQUAL(*pointers[1], 2);
	ASSERT_EQUAL(*pointers[2], 3);
}

void TestReverseCopy() {
	const size_t count = 7;

	int* source = new int[count];
	int* dest = new int[count];

	for (size_t i = 0; i < count; ++i) {
		source[i] = i + 1;
	}
	ReversedCopy(source, count, dest);
	const vector<int> expected1 = { 7, 6, 5, 4, 3, 2, 1 };
	ASSERT_EQUAL(vector<int>(dest, dest + count), expected1);

	ReversedCopy(source, count - 1, source + 1);
	const vector<int> expected2 = { 1, 6, 5, 4, 3, 2, 1 };
	ASSERT_EQUAL(vector<int>(source, source + count), expected2);

	delete[] dest;
	delete[] source;
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestSwap);
	RUN_TEST(tr, TestSortPointers);
	RUN_TEST(tr, TestReverseCopy);

	system("PAUSE");
	return 0;
}

