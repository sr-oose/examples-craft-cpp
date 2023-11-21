#ifndef DECORATORS_H_
#define DECORATORS_H_

#include <memory>
#include "textsource.h"

using PtrTextSource = std::shared_ptr<TextSource>;

class TextSourceDecorator: public TextSource {
public:
	TextSourceDecorator(const PtrTextSource source) : source(source) {};

protected:
	const PtrTextSource source;
};

class CapitalizeDecorator: public TextSourceDecorator {
public:
	CapitalizeDecorator(const PtrTextSource source) : TextSourceDecorator(source) {};
	virtual std::string getText() const override;

};


class LineNumberDecorator: public TextSourceDecorator {
public:
	LineNumberDecorator(const PtrTextSource source) : TextSourceDecorator(source) {};
	virtual std::string getText() const override;

};

#endif
