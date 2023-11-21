#include <iostream>
#include <memory>
using namespace std;

class Strategy
{
public:
	virtual void algorithm() = 0;
	virtual ~Strategy() = default;
};

class StrategyA : public Strategy
{
public:
	virtual void algorithm() override
	{
		cout << "StrategyA" << endl;
	}
};

class StrategyB : public Strategy
{
public:
	virtual void algorithm() override
	{
		cout << "StrategyB" << endl;
	}
};

class Context
{
public:
	Context(shared_ptr<Strategy> strategy) : strategy(strategy){ } // Dependency Injection

	void doSomething()
	{
		if (strategy != nullptr)
			strategy->algorithm();
	}

	void changeStrategy(shared_ptr<Strategy> newStrategy) // Dependency Injection
	{
		strategy = newStrategy;
	}

private:
	shared_ptr<Strategy> strategy;
};


int main() {
	shared_ptr<Strategy> strategyA = make_shared<StrategyA>();
	shared_ptr<Strategy> strategyB = make_shared<StrategyB>();

	Context context(strategyA);
	context.doSomething();
	context.changeStrategy(strategyB);
	context.doSomething();
	return 0;
}
