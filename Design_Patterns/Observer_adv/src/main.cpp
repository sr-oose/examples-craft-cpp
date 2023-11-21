#include <iostream>
#include "subject.h"
#include "observer.h"

using namespace std;

int main() {
	DataSubject dataSubject;
	auto o1 = make_shared<DataUpdateObserver>("Observer 1");
	auto o2 = make_shared<DataUpdateObserver>("Observer 2");
	auto o3 = make_shared<DataUpdateObserver>("Observer 3");
	dataSubject.attach(o1);
	dataSubject.dataUpdated();
	dataSubject.attach(o2);
	dataSubject.dataUpdated();
	cout << "Calling reset() on o1" << endl;
    o1.reset();
	dataSubject.dataUpdated();
	dataSubject.attach(o3);
	dataSubject.dataUpdated();
	dataSubject.detach(o2);
	dataSubject.dataUpdated();
	return 0;
}
