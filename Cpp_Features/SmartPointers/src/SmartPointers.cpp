#include <iostream>
#include <memory>
using namespace std;


class CoolObject
{
public:

	CoolObject(int id) : id(id), value(0)
	{
		cout << "CoolObject " << id << " construct" << endl;
	}

	~CoolObject()
	{
		cout << "CoolObject " << id << " destruct" << endl;
	}

	void setValue(int value)
	{
		this->value = value;
	}

	int getValue()
	{
		return value;
	}

private:
	int id;
	int value;
};

using CoolObjectPtr = unique_ptr<CoolObject>;

CoolObjectPtr createCoolObject(int id)
{
	return make_unique<CoolObject>(id);
}


int main() {
		auto ptr = createCoolObject(1);
		ptr->setValue(5);
		cout << "Before 2nd create" << endl;
		ptr = createCoolObject(2);
		auto shared1 = make_shared<CoolObject>(3);
		auto shared2 = shared1;
		auto weak = new weak_ptr<CoolObject>(shared1);
		auto shared3 = weak->lock();
		shared1.reset();
		shared2.reset();
		cout << "expired: " << weak->expired() << endl;
		cout << "End of main()" << endl;
		return 0;
}
