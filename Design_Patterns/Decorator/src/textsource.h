#ifndef TEXTSOURCE_H_
#define TEXTSOURCE_H_

#include <string>

class TextSource {
public:
	virtual std::string getText() const = 0;
	virtual ~TextSource() = default;
};

class StringTextSource: public TextSource {
public:
	StringTextSource(std::string text);
	virtual std::string getText() const override;

private:
	const std::string text;
};

#endif
