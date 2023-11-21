#ifndef PIZZAFACTORY_H_
#define PIZZAFACTORY_H_

#include <memory>
#include <iostream>

class Pizza {
public:
	virtual float getThickness() = 0;
	virtual const char* getName() = 0;

	virtual float getPrice() {
		return BASE_PRICE + getThickness() * THICKNESS_FACTOR + getToppingCost();
	}

	virtual void printInfo() {
		std::cout << "Pizza: "
				  << getName() << ", "
				  << getThickness() << "cm thick, "
				  << getPrice() << "$"
				  << std::endl;
	}

	virtual ~Pizza() = default;

protected:
	virtual float getToppingCost() {
		return 0.0f;
	}

private:
	static constexpr float BASE_PRICE = 6.0f;
	static constexpr float THICKNESS_FACTOR = 2.0f;

};

using PizzaPtr = std::shared_ptr<Pizza>;

class PizzaFactory {
public:
	virtual PizzaPtr makeMargherita() = 0;
	virtual PizzaPtr makeSalamiPizza() = 0;

	virtual ~PizzaFactory() = default;
};


#endif
