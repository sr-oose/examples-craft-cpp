#include <iostream>
#include <sstream>
#include <iomanip>
#include "decorators.h"

using namespace std;

std::string CapitalizeDecorator::getText() const {
	string text = source->getText();
	for (auto & c: text) c = toupper(c);
	return text;
}

std::string LineNumberDecorator::getText() const {
	ostringstream out;
	istringstream in(source->getText());
	int i = 1;
	string line;
	while (getline(in, line))
		out << setw(3) << i++ << ": " << line << endl;
	return out.str();
}
