#include <iostream>
#include "observer.h"

using namespace std;

Observer::~Observer(){
	cout << "Destroy base class" << endl;
}

DataUpdateObserver::DataUpdateObserver(string name) :
		name(name) {
}

void DataUpdateObserver::update(){
	cout << name << ": Data update notification received." << endl;
}

DataUpdateObserver::~DataUpdateObserver(){
	cout << "Destroy " << name << endl;
}
