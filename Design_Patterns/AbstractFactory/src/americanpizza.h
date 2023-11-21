#ifndef AMERICANPIZZA_H_
#define AMERICANPIZZA_H_

#include "pizzafactory.h"

namespace America {

class AmericanPizza : public Pizza {
public:
	virtual float getThickness() override {
		return 2.0f;
	}
};

class Margherita : public AmericanPizza {
public:
	virtual const char* getName() override {
		return "Great American Pizza Margherita";
	}
};


class SalamiPizza : public AmericanPizza {
public:
	virtual const char* getName() override {
		return "Great American Salami Pizza";
	}

protected:
	virtual float getToppingCost(){
		return 3.7f;
	}
};

}

class AmericanPizzaFactory : public PizzaFactory {
public:
	virtual PizzaPtr makeMargherita() override {
		return std::make_shared<America::Margherita>();
	}

	virtual PizzaPtr makeSalamiPizza() override {
		return std::make_shared<America::SalamiPizza>();
	}

};

#endif
