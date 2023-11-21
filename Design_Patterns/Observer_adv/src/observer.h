#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer();
};

class DataUpdateObserver: public Observer {
public:
	DataUpdateObserver(std::string name);
	virtual void update() override;
	virtual ~DataUpdateObserver() override;

private:
	const std::string name;
};

#endif
