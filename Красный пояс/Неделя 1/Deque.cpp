// Table.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <exception>
#include <iostream>
#include "assert.h"

using namespace std;

template<typename T>
class Deque
{
public:
	Deque() {}

	// empty, size
	const bool Empty() const { return !(front.size() || back.size()); }
	const size_t Size() const { return front.size() + back.size(); }

	// front
	T& Front() { return FrontSafe(); }
	const T& Front() const { return FrontSafe(); }

	// back
	T& Back() { return BackSafe(); }
	const T& Back() const { return BackSafe(); }

	// push
	void PushFront(const T& value) { front.push_back(value); }
	void PushBack(const T& value) { back.push_back(value); }

	// at
	T& At(size_t index) { return AtSafe(index); }

	// operators
	T& operator[](size_t index) { return AtNotSafe(index); }
	const T& operator[](size_t index) const { return AtNotSafe(index); }

private:

	// safe with exception
	T& AtSafe(size_t index)
	{
		size_t fullsize = front.size() + back.size();
		if (index >= fullsize)
			throw out_of_range("");

		else
			return AtNotSafe(index);
	}

	// not safe
	T& AtNotSafe(size_t index)
	{
		size_t fullsize = front.size() + back.size();
		if (index > front.size() - 1)
		{
			index = back.size() - (fullsize - index);
			return back[index];
		}

		else
		{
			index = (front.size() - 1) - index;
			return front[index];
		}
	}

	T& FrontSafe()
	{
		return BackFront(front, back);
	}

	T& BackSafe()
	{
		return BackFront(back, front);
	}

	T& BackFront(vector<T>& vec1, vector<T>& vec2)
	{
		if (vec1.size())
			return vec1[vec1.size() - 1];
		else if (vec2.size())
			return vec2[0];

		throw out_of_range("");
	}

private:
	vector<T> front;
	vector<T> back;
};


int main() {
	Deque<int> dq;

	cout << "Empty: " << dq.Empty() << endl;

	/*for (size_t i = 0; i < 3; i++)
		dq.PushFront(i + 1);*/

	/*for (size_t i = 0; i < 3; i++)
		dq.PushBack(i + 2);*/

	cout << "Empty: " << dq.Empty() << endl;
	cout << "Size: " << dq.Size() << endl;

	cout << "Front: " << dq.Front() << endl;
	cout << "Back: " << dq.Back() << endl;

	/*int& number = dq.At(3);
	number += 10;
	cout << "AtSafe 3: " << number << endl;

	cout << "At 3: " << dq[3] << endl;*/
	cout << "AtSafe 0: " << dq.At(0) << endl;
	cout << "At 0: " << dq[0] << endl;

	//cout << "At 6: " << dq.At(6) << endl;
	//cout << "At 6: " << dq[6] << endl;

	system("PAUSE");
	return 0;
}
