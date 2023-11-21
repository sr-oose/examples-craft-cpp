#include <iostream>
#include <string.h>
using namespace std;

class IntArray {
public:
	IntArray(size_t size) : size(size)
	{
		cout << "Construct" << endl;
		memory = new int[size];
		memset(memory, 0, size * sizeof(int));
	}

	int& operator[](size_t index)
	{
		return memory[index];
	}

	IntArray(const IntArray& other)
	{
		cout << "Copy Construct" << endl;
		memory = new int[other.size];
		size = other.size;
		memcpy(memory, other.memory, sizeof(int) * size);
	}

	IntArray(IntArray&& other)
	{
		cout << "Move Construct" << endl;
		memory = other.memory;
		size = other.size;
		other.memory = nullptr;
		other.size = 0;
	}

	IntArray& operator=(const IntArray& other)
	{
		if (&other == this) return *this;
		delete[] memory;
		memory = new int[other.size];
		size = other.size;
		memcpy(memory, other.memory, sizeof(int) * size);
		return *this;
	}

	~IntArray()
	{
		delete[] memory;
	}

	size_t getSize()
	{
		return size;
	}

private:
	int* memory;
	size_t size;

};


IntArray reset(IntArray arr)
{
	for (size_t i = 0; i < arr.getSize(); i++)
		arr[i] = 0;
	return arr;
}


int main() {
	IntArray arr1(10);
	arr1[9] = 50;
	IntArray arr2(reset(arr1));
	cout << arr2[9] << endl;
	return 0;
}
