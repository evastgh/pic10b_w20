#include <iostream>
#include <vector>
using namespace std;
class Shape { // shallow base class
public:
	virtual void print() const {}
};
class Circle : public Shape {
	double r; // radius
public:
	Circle(double r_in) : r(r_in) {}
	virtual void print() const override { cout << "Circle with radius " << r << endl; }
};
class Rectangle : public Shape {
	double w, l; // width and length
public:
	Rectangle(double w_in, double l_in) : w(w_in), l(l_in) {}
	virtual void print() const override { 
		cout << "Rectangle with width " << w << " and length " << l << endl; 
	}
};

/*
int main()
{
	cout << "Please input 1 if you want cirlce, or 2 for rectangle. " << endl;
	int type;
	cin >> type;
	// fundamentalist solution
	// Circle circ;
	// Rectangle rec;
	// bool is_circle;
	
	Shape* ptr = nullptr; // initialized as nullptr to ensure no memory corruption

	if (type == 1) {
		cout << "Circle it is. Please input the radius: ";
		double r;
		cin >> r;
		// Circle circ(r);
		ptr = new Circle(r);
	}
	else {
		cout << "Rectangle it is. Please input the width: ";
		double w, l;
		cin >> w;
		cout << "Please input the length: ";
		cin >> l;
		// Rectangle rec(w, l);
		ptr = new Rectangle(w, l);
	}
	// access either case (circle or rectangle) using ptr
	ptr->print();
	// fundamentalist: try to read the data at ptr and see if it's Circle or Rectangle
}
*/
int main() {
	bool proceed = true;
	vector<Shape*> array;
	while (proceed) {
		cout << "Please type 1 for circle, 2 for rectangle: ";
		int type;
		cin >> type;
		Shape* ptr = nullptr;
		if (type == 1) {
			cout << "Circle it is. Please input the radius: ";
			double r;
			cin >> r;
			ptr = new Circle(r);
		}
		else {
			cout << "Rectangle it is. Please input the width: ";
			double w, l;
			cin >> w;
			cout << "Please input the length: ";
			cin >> l;
			ptr = new Rectangle(w, l);
		}
		array.push_back(ptr);

		cin.get();
		cout << "Continue? (y/n)";
		char c;
		cin.get(c);
		if (c == 'y')
			proceed = true;
		else
			proceed = false;
	}

	for (size_t i = 0; i < array.size(); ++i)
		array[i]->print();
}
