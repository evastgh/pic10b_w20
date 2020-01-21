#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;

class Point {
	double x, y;
public:
	Point(double x, double y) : x(x), y(y) {}
	void print() { cout << "(" << x << ", " << y << ")"; }
};

class Rectangle {
	Point* center;
	double width, length;
	bool managing_center;
public:
	Rectangle(double w, double l)
		: width(w), length(l)
		, center(new Point(0, 0)), managing_center(true) {}
	Rectangle(double w, double l, Point* c) 
		: width(w), length(l)
		, center(c), managing_center(false) {}
	~Rectangle() {
		if (managing_center)
			delete center;
	}
	void print() {
		cout << "Rectangle, width = " << width;
		cout << ", length = " << length;
		cout << ", center = ";
		center->print();
	}
};
/*
struct Square {
	Point* center;
	double length;
	bool managing_center; 
	// ...so similar to Rectangle, don't wanna duplicate the code
};
*/

class Square : Rectangle {
public:
	// Square(double l) : width(l), length(l), center(new Point(0,0)) {} // complile error
	Square(double l) : Rectangle(l, l) {}
	Square(double l, Point* c) : Rectangle(l, l, c) {}
	void print() { ((Rectangle*)this)->print(); }
};
#endif
