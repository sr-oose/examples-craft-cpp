#ifndef OBSERVER_H_
#define OBSERVER_H_

#include <string>

class Observer {
public:
	virtual void update() = 0;
	virtual ~Observer() = default;
};

class DataUpdateObserver: public Observer {
public:
	DataUpdateObserver(std::string name);
	virtual void update() override;

private:
	std::string name;
};

#endif
