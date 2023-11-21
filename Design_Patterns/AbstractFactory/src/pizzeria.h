#ifndef PIZZERIA_H_
#define PIZZERIA_H_

#include <iostream>
#include "pizzafactory.h"

class Pizzeria {
	using FactoryPtr = std::shared_ptr<PizzaFactory>;

public:
	Pizzeria (FactoryPtr supplier) : supplier(supplier) { };

	void makePizzas(){
		supplier->makeSalamiPizza()->printInfo();
		supplier->makeMargherita()->printInfo();
	}

	void changeSupplier(FactoryPtr newSupplier){
		this->supplier = newSupplier;
	}

private:
	FactoryPtr supplier;

};



#endif
