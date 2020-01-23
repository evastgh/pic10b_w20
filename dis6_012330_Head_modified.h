#ifndef _HEADER_H_
#define _HEADER_H_
#include <iostream>
using namespace std;

class Point {
public:
	double x, y;
	Point(double x, double y) : x(x), y(y) {}
	void print() { cout << "(" << x << ", " << y << ")"; }
};

class Rectangle {
protected:
	Point* center;
private:
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
	const double get_width() const { return width; }
	const double get_length() const { return length; }
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
	Point const* get_center() const { return center; } // center is protected
	const double get_length() const { 
		return ((Rectangle*)this)->get_length(); 
	} // length is private
	void print() { ((Rectangle*)this)->print(); }
};

#include <vector>
// vector<Square*> find_in_first_quadrant(vector<Square*> vec); // copying the vector that doesn't need to be copied, slow
vector<Square*> find_in_first_quadrant(const vector<Square*>& vec) {
	// vector<Square*> return_value(vec.size(), nullptr);
	vector<Square*> return_value;
	for (size_t i = 0; i < vec.size(); ++i) {
		Square* s_ptr = vec[i];
		Point const* c_ptr = s_ptr->get_center();
		double length = s_ptr->get_length();
		if ((*c_ptr).x - 0.5 * length)
			if ((*c_ptr).y - 0.5 * length)
				// return_value[i] = s_ptr;
				return_value.push_back(s_ptr);
	}
	return return_value;
}
#endif
