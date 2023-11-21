#include <iostream>
#include "textsource.h"
#include "decorators.h"


using namespace std;

int main() {
	PtrTextSource source = make_shared<StringTextSource>("Zeile1\nZeile2\nZeile3");
	source = make_shared<LineNumberDecorator>(source);
	source = make_shared<CapitalizeDecorator>(source);
	cout << source->getText() << endl;
	return 0;
}
