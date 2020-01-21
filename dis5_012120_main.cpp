#include "Header.h"
#include <iostream>

int main()
{
	/*
	Point* p = new Point(3.14, 2.7);
	{
		Rectangle r(2.0, 1.0, p);
		r.print();
	}
	// p->print();
	delete p; */
	Square s(55.66);
	s.print(); // compile error, private inheritance
	// Rectangle* p = new Square(55.66); // compile error, private inheritance not known in main()
}
