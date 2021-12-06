#pragma once

#include <cstdlib>
#include <iterator>
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

	~SimpleVector() {
		ClearBuffer();
	}

	T& operator[](size_t index) {
		return *(buffer + index);
	}

	T* begin() { return buffer; }
	T* end() { return _last; }

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