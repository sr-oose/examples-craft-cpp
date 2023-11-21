#include <iostream>
using namespace std;


class Shape
{
public:
	Shape(string name) : name(name)
	{
		cout << "Init Shape" << endl;
	}

	virtual float calcSurface() = 0;

	virtual void printSurface()
	{
		cout << "Surface " << calcSurface() << endl;
	}

private:
	string name;
};

class Triangle : public Shape
{
public:
	Triangle() : Shape("Triangle")
	{
		cout << "Init Triangle" << endl;
		height = 0.0;
		base = 0.0;
	}

	virtual float calcSurface() override
	{
		return 0.5 * height * base;
	}

	void setHeight(float base)
	{
		if (height < 0.0)
			this->height = 0.0;
		else
			this->height = height;
	}

	void setBase(float base)
	{
		this->base = base;
	}

private:
	float height;
	float base;
};


class Rectangle : public Shape 
{
public:
	Rectangle(float width = 0.0, float height = 0.0) : Shape("Rectangle"), width{width}, height{height}
	{
		cout << "Init Rectangle" << endl;
	}

	virtual float calcSurface() override
	{
		return width * height;
	}

private:
	float width;
	float height;

};

class Square : public Shape {
public:
	Square(float edge) : Shape("Quadrat"), r(edge, edge) {}

	virtual float calcSurface()
	{
		return r.calcSurface();
	}


private:
	Rectangle r;
};

int main() {
	Triangle triangle;
	triangle.setBase(2);
	triangle.setHeight(2);
	triangle.printSurface();
	Shape* shape = &triangle;
	shape->printSurface();

	Square square(2.0);
	shape = &square;
	shape->printSurface();

	return 0;
}
