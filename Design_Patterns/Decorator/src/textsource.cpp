#include "textsource.h"

using namespace std;

StringTextSource:: StringTextSource(std::string text):
	text(text) {

}

string StringTextSource::getText() const {
	return text;
}


