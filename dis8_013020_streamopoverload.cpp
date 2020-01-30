#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
struct Sphere {
	double x, y, z, r;
	Sphere(double x, double y, double z, double r)
		: x(x), y(y), z(z), r(r)
	{}
	void print() {
		cout << "Sphere centered at (" << x << ", " << y << ", " << z;
		cout << ") with radius " << r << ". " << endl;
	}
};
ostream& operator<<(ostream& os, const Sphere& s) {
	os << "Sphere centered at (" << s.x << ", " << s.y << ", " << s.z;
	os << ") with radius " << s.r << ". " << endl;
	return os;
}
int main()
{
	Sphere s(55.66, 0, 1.0, 0.9);
	Sphere s1(55.66, 0, 1.0, 0.8);
	Sphere s2(55.66, 0, 1.0, 0.7);
	// s.print();
	ofstream fs;
	fs.open("test.txt", ios::app); // default behavior: overwrite!
	// if no directory specified, opens a file located inside the VS project
	// cout << s;
	// similar to cout << 123 << "hello" << 101.11 << ' ' << endl << s;
	fs << s << s1 << s2;

}
