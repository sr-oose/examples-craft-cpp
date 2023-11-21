#ifndef ITALIANPIZZA_H_
#define ITALIANPIZZA_H_

#include "pizzafactory.h"

namespace Italia {

class RealPizza : public Pizza {
public:
	virtual float getThickness() override {
		return 0.4f;
	}
};

class PizzaOriginale : public RealPizza {
public:
	virtual const char* getName() override {
		return "La Pizza Originale";
	}
};


class PizzaSalame : public RealPizza {
public:
	virtual const char* getName() override {
		return "Pizza Salame Italiana";
	}

protected:
	virtual float getToppingCost() override {
		return 2.3f;
	}
};

}

class ItalianPizzaFactory : public PizzaFactory {
public:
	virtual PizzaPtr makeMargherita() override {
		return std::make_shared<Italia::PizzaOriginale>();
	}

	virtual PizzaPtr makeSalamiPizza() override {
		return std::make_shared<Italia::PizzaSalame>();
	}

};



#endif
