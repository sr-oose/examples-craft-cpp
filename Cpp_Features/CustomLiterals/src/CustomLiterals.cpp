#include <iostream>
#include <stdexcept>
using namespace std;

enum class Unit : uint32_t {cm, m, km};

class Length {
public:
	Length(double value, Unit unit)
	{
		switch(unit)
		{
		case Unit::cm:
			meters = value / 100.0;
			break;
		case Unit::m:
			meters = value;
			break;
		case Unit::km:
			meters = value * 1000.0;
			break;
		default:
			throw std::invalid_argument("Invalid unit");

		}
	}

	Length operator+(const Length& other)
	{
		return Length(meters + other.meters, Unit::m);
	}

	void print(){
		cout << meters << " m" <<  endl;
	}

private:
	double meters;
};

Length operator""km(long double value){
	return Length(value, Unit::km);
}

Length operator""m(long double value){
	return Length(value, Unit::m);
}

Length operator""cm(long double value){
	return Length(value, Unit::cm);
}

int main() {
	Length l1 = 2.0km;
	Length l2 = 5.0m;
	Length l3 = l1 + l2 + 56.0cm;
	l3.print();
	return 0;
}
