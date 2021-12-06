#pragma once

#include <cstdlib>
#include <iterator>
#include <algorithm>

using namespace std;

// SimpleVector
template <typename T>
class SimpleVector {
public:
	SimpleVector() {
		buffer = nullptr;
		_last = nullptr;
		_end = nullptr;
	}
	explicit SimpleVector(size_t size) {
		buffer = new T[size];
		_last = buffer + size;
		_end = _last;
	}

	SimpleVector(const SimpleVector& rhs)
	{
		buffer = new T[rhs.Capacity()];
		_last = rhs._last;
		_end = rhs._end;

		copy(rhs.begin(), rhs.end(), begin());
	}

	~SimpleVector() {
		ClearBuffer();
	}

	void operator=(const SimpleVector& rhs) {
		if (rhs.Size() <= Capacity()) {
			copy(rhs.begin(), rhs.end(), begin());
			_last = rhs.buffer + rhs.Size();
			_end = _last;
		}
		else {
			SimpleVector<T> tmp(rhs);

			size_t size = rhs.Size();
			swap(tmp.buffer, buffer);
			_last = buffer + size;
			_end = _last;
		}
	}

	T& operator[](size_t index) {
		return *(buffer + index);
	}

	T* begin() { return buffer; }
	T* end() { return _last; }

	const T* begin() const { return buffer; }
	const T* end() const { return _last; }

	size_t Size() const { return _last - buffer; }

	size_t Capacity() const { return _end - buffer; }
	
	void PushBack(const T& value) {
		if (Size() == Capacity())
		{
			size_t count = Size();
			size_t new_size = Capacity() ? Capacity() * 2 : 2;

			T* temp = new T[new_size];
			memset(temp, 0, new_size * sizeof(T));
			if(buffer)
				memcpy(temp, buffer, Capacity() * sizeof(T));

			ClearBuffer();
			
			buffer = temp;

			_last = buffer + count;
			_end = buffer + new_size;
		}

		*_last = value;
		_last++;
	}

protected:
	void ClearBuffer() {
		if (buffer)
			delete[] buffer;
	}

private:
	T* buffer;
	T* _end;
	T* _last;
};