// ObjectsPool.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
	T* Allocate()
	{
		T* object = TryAllocate();
		if (!object)
		{
			object = new T();
			use.insert(object);
		}

		return object;
	}

	T* TryAllocate()
	{
		T* result = nullptr;
		if (!free.empty())
		{
			result = free.front();
			use.insert(result);
			
			free.pop();
		}

		return result;
	}

	void Deallocate(T* object)
	{
		if (use.count(object) == 0)
			throw invalid_argument("Not found");

		else
		{
			use.erase(object);
			free.push(object);
		}
	}

	~ObjectPool() 
	{
		for (T* object : use)
			delete object;

		for (size_t i = 0; i < free.size(); ++i)
		{
			delete free.front();
			free.pop();
		}
	}

private:
	std::set<T*> use;
	std::queue<T*> free;
};

void TestObjectPool() {
	ObjectPool<string> pool;

	auto p1 = pool.Allocate();
	auto p2 = pool.Allocate();
	auto p3 = pool.Allocate();

	*p1 = "first";
	*p2 = "second";
	*p3 = "third";

	pool.Deallocate(p2);
	ASSERT_EQUAL(*pool.Allocate(), "second");

	pool.Deallocate(p3);
	pool.Deallocate(p1);
	ASSERT_EQUAL(*pool.Allocate(), "third");
	ASSERT_EQUAL(*pool.Allocate(), "first");

	pool.Deallocate(p1);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestObjectPool);

	system("PAUSE");
	return 0;
}
