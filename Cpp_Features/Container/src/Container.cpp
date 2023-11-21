#include <iostream>
#include <array>
#include <vector>
#include <map>
#include <algorithm>


class A
{

};

using MyInt = int64_t;

int main() {
	std::array<int, 10> arr;
	std::fill(arr.begin(), arr.end(), 0);
	arr[9] = 50;


	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}

	for (std::array<int, 10>::iterator i = arr.begin(); i != arr.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	for (auto i = arr.begin(); i != arr.end(); i++)
	{
		std::cout << *i << std::endl;
	}

	for (int i : arr)
	{
		std::cout << i << std::endl;
	}

	std::vector<int> intvec = {1, 2, 3, 4, 5, 6};
	intvec.push_back(7);
	intvec[0] = 5;

	std::sort(intvec.begin(), intvec.end());

	for (int i : intvec)
	{
		std::cout << i << std::endl;
	}

	std::map<int,std::string> mymap;
	mymap[4] = "xyz";
	mymap[4000] = "a";
	mymap[4] = "abc";

	return 0;
}
