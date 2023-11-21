#ifndef COMMAND_H_
#define COMMAND_H_

#include <string>
#include <iostream>
#include <memory>
#include "shapes.h"

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~Command() = default;
};


class DrawTextCommand : public Command {
public:
	DrawTextCommand(const std::string text) : text(text){}

	virtual void execute() override {
		std::cout << "Drawing text '" << text << "'.\n";
	}

	virtual void undo() override {
		std::cout << "Deleting text '" << text << "'.\n";
	}

private:
	const std::string text;
};


class DrawShapeCommand : public Command {
public:
	DrawShapeCommand(std::shared_ptr<Shape> shape) : shape(shape) { }

	virtual void execute() override {
		shape->draw();
	}

	virtual void undo() override {
		shape->remove();
	}

private:
	std::shared_ptr<Shape> shape;
};

#endif
