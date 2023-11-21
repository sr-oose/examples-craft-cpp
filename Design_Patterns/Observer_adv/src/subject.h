#ifndef SUBJECT_H_
#define SUBJECT_H_

#include <vector>
#include <memory>
#include "observer.h"

using ObserverWeakPtr=std::weak_ptr<Observer>;

class Subject {
public:
	virtual void attach(const ObserverWeakPtr observer);
	virtual void detach(const ObserverWeakPtr observer);
	virtual void notify() const;
	virtual ~Subject() = default;

private:
	std::vector<ObserverWeakPtr> observers;
};


class DataSubject: public Subject {
public:
	void dataUpdated() const;
};

template <typename T> bool operator==(const std::weak_ptr<T>& p1, const std::weak_ptr<T>& p2);


#endif
