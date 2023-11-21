#include <iostream>
#include "observer.h"

using namespace std;

DataUpdateObserver::DataUpdateObserver(string name) :
		name(name) {
}

void DataUpdateObserver::update() {
	cout << name << ": Data update notification received." << endl;
}
