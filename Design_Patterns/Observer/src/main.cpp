#include <iostream>
#include "subject.h"
#include "observer.h"

using namespace std;

int main() {
	DataSubject dataSubject;
	DataUpdateObserver o1("Observer 1");
	{
		DataUpdateObserver o2("Observer 2");
		dataSubject.attach(&o1);
		dataSubject.updateData();
		dataSubject.attach(&o2);
		dataSubject.updateData();
		dataSubject.detach(&o1);
	}
		dataSubject.updateData();
	// What's the problem here?
	return 0;
}
