#include <iostream>
#include <algorithm>
#include "subject.h"

using namespace std;

void Subject::attach(const ObserverWeakPtr observer) {
	for (auto& o : observers) {
		if (o.expired()) {
			o = observer;
			return;
		}
	}
	observers.push_back(observer);
}

void Subject::detach(const ObserverWeakPtr observer) {
	for (auto& o : observers){
		if (observer == o)
			o.reset();
	}
}

void Subject::notify() const {
	for (auto& o : observers)
	{
		std::shared_ptr<Observer> shared = o.lock();
		if (nullptr != shared) shared->update();
	}
}

void DataSubject::dataUpdated() const {
	cout << "DataSubject: Data is updated." << endl;
	notify();
}


template <typename T> bool operator==(const weak_ptr<T>& p1, const weak_ptr<T>& p2) {
	return !p1.owner_before(p2) && !p2.owner_before(p1);
}
