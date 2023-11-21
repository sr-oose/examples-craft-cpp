#include "pizzeria.h"
#include "americanpizza.h"
#include "italianpizza.h"

using namespace std;

int main(int argc, char** argv) {
	auto americanFactory = make_shared<AmericanPizzaFactory>();
	auto italianFactory = make_shared<ItalianPizzaFactory>();

	Pizzeria pizzeria(americanFactory);
	pizzeria.makePizzas();
	pizzeria.changeSupplier(italianFactory);
	pizzeria.makePizzas();

	return 0;
}



