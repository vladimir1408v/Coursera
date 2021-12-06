// Table.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "test_runner.h"
#include <vector>

using namespace std;

template<typename T>
class Table
{
public:
	Table(size_t rows, size_t colums)
	{
		Resize(rows, colums);
	}

	void Resize(size_t in_rows, size_t in_colums)
	{
		rows = in_rows;
		colums = in_colums;

		table.resize(rows);
		for (size_t i = 0; i < rows; i++)
			table[i].resize(colums);
	}

	pair<size_t, size_t> Size() { return make_pair(rows, colums); }

	vector<T>& operator[](size_t index) { return table[index]; }
	const vector<T>& operator[](size_t index) const { return table[index]; }

private:
	vector<vector<T>> table;
	size_t rows;
	size_t colums;
};

void TestTable() {
	Table<int> t(1, 1);
	ASSERT_EQUAL(t.Size().first, 1u);
	ASSERT_EQUAL(t.Size().second, 1u);
	t[0][0] = 42;
	ASSERT_EQUAL(t[0][0], 42);
	t.Resize(3, 4);
	ASSERT_EQUAL(t.Size().first, 3u);
	ASSERT_EQUAL(t.Size().second, 4u);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestTable);

	system("PAUSE");
	return 0;
}
