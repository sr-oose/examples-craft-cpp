#ifndef SHAPES_H_
#define SHAPES_H_

#include <iostream>

class Shape {
public:
	virtual void draw() = 0;
	virtual void remove() = 0;
	virtual ~Shape() = default;
};


class Circle : public Shape{
public:
	virtual void draw(){
		std::cout << "Circle drawn" << std::endl;
	}

	virtual void remove(){
		std::cout << "Circle removed" << std::endl;
	}
};

class Rectangle : public Shape{
public:
	virtual void draw(){
		std::cout << "Rectangle drawn" << std::endl;
	}

	virtual void remove(){
		std::cout << "Rectangle removed" << std::endl;
	}
};

#endif
