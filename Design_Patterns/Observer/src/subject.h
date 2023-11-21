#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <vector>
#include "observer.h"


class Subject {
public:
	virtual void attach(Observer* observer); // Warum geht hier kein const-Zeiger?
	virtual void detach(const Observer* observer);
	virtual void notify() const;
	virtual ~Subject() = default;

private:
	std::vector<Observer*> observers;
};


class DataSubject: public Subject {
public:
	void updateData() const;
};


#endif
