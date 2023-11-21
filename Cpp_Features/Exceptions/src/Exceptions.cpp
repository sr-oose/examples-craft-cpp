#include <iostream>
#include <exception>
using namespace std;

class DivByZeroException : public std::exception
{
public:
	DivByZeroException(const char* errordesc) : errordesc(errordesc)
	{

	}

	const char* errordesc;
};

int divide(int numerator, int denominator)
{
	if (denominator == 0)
		throw DivByZeroException{"Division by zero"};

	return numerator / denominator;
}


int main() {
	try
	{
		int x = divide(4, 2);
		int y = divide(4, 0);
	}
	catch (const DivByZeroException& ex)
	{
		cerr << ex.errordesc << endl;
	}
	catch (const std::exception& ex)
	{
		cerr << ex.what() << endl;
	}
	catch (...)
	{
		cerr << "Unknown error" << endl;
	}

	return 0;
}
