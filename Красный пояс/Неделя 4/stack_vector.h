#pragma once

#include <array>
#include <stdexcept>
using namespace std;

template <typename T, size_t N>
class StackVector {
public:
	explicit StackVector(size_t a_size = 0) 
		: size(a_size) 
	{
		if (size > N)
			throw invalid_argument("Error: size > N");
	}

	T& operator[](size_t index) {
		return buffer[index];
	}

	const T& operator[](size_t index) const {
		return buffer[index];
	}

	auto begin() {
		return buffer.begin();
	}

	auto end() {
		return buffer.begin() + size;
	}

	auto begin() const {
		return buffer.begin();
	}

	auto end() const {
		return buffer.begin() + size;
	}

	size_t Size() const {
		return size;
	}

	size_t Capacity() const {
		return N;
	}

	void PushBack(const T& value) 
	{
		if (size < N)
			buffer[size++] = value;

		else throw overflow_error("Error: buffer is full");
			
	}

	T PopBack() {
		if (size > 0)
		{
			--size;
			return buffer[size];
		}
			
		else throw underflow_error("Empty");
	}

private:
	size_t size = 0;
	array<T, N> buffer;
};

