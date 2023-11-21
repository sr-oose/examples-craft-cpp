#include <iostream>
#include <memory>
using namespace std;

struct Array
{
	virtual int& operator[](int index) = 0;
	virtual ~Array() = default;
};

struct RealArray : public Array {
    int mArray[10];

    virtual int& operator[](int index) override
    {
        return mArray[index];
    }
};

struct ArrayProxy : public Array {
	RealArray realArray;
	ArrayProxy() = default;
    virtual int& operator[](int index) override
    {
        if (index > 9) {
            throw "index too large";
        }
        return realArray[index];
    }


};

int main() {
    try {
        ArrayProxy a;
        a[0] = 1;   // ok
        a[10] = 42;  // throws exception
    }
    catch (const char * e) {
        cout << e << endl;
    }
}
