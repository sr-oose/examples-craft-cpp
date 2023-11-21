#include <iostream>
#include <algorithm>
#include "subject.h"

using namespace std;

void Subject::attach(Observer* observer) {
	observers.push_back(observer);
}

void Subject::detach(const Observer* observer) {
	//Erase-Remove-Idiom:
	observers.erase(remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify() const {
	//                                            Lambda-Funktion
	// for_each(observers.begin(), observers.end(), [](auto o) {o->update();});
	for (Observer* observer : observers)
		observer->update();
}

void DataSubject::updateData() const {
	cout << "DataSubject: Data is updated." << endl;
	notify();
}
