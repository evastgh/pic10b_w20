#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
struct Polynomial {
	Polynomial() : coeff(1, 0.0) {}
	Polynomial(const vector<double>& coeff_in) : coeff(coeff_in) {}
	size_t get_deg() const { return coeff.size() - 1; }
	bool operator<(const Polynomial& other) {
		// this allows (p1 < p2)
		// think of this as a function bool compare(p1, p2);
		// or p1.compare(p2)
		// except you can use binary operator '<'

		if (this->get_deg() != other.get_deg())
			return this->get_deg() < other.get_deg();

		// if the degree is the same, compare the coefficients in descending order
		size_t d = this->get_deg();
		while (d >= 0) {
			if (this->coeff[d] != other.coeff[d])
				return this->coeff[d] < other.coeff[d];
			else
				--d;
		}
		// the two polynomials are identical, return false
		return false;
	}
	bool operator>=(const Polynomial& other) { return !(*this < other); }
	Polynomial& operator=(const Polynomial& other) { this->coeff = other.coeff; return *this; }
	Polynomial& operator+=(const Polynomial& other) {
		if (this->get_deg() >= other.get_deg()) {
			for (size_t i = 0; i <= other.get_deg(); ++i)
				coeff[i] += other.coeff[i];
		}
		else {
			size_t i = 0;
			for (; i <= this->get_deg(); ++i)
				coeff[i] += other.coeff[i];
			for (; i <= other.get_deg(); ++i)
				coeff.push_back(other.coeff[i]);
		}
		return *this;
	}

	friend ostream& operator<<(ostream& os, const Polynomial& poly);
	friend istream& operator>>(istream& is, Polynomial& poly);

	vector<double> coeff;
};

ostream& operator<<(ostream& os, const Polynomial& poly) {
	os << poly.coeff[0];
	for (size_t i = 1; i <= poly.get_deg(); ++i) {
		os << " + " << poly.coeff[i] << " x^" << i;
	}
	return os;
}
istream& operator>>(istream& is, Polynomial& poly) {
	// this allows cin >> poly;
	// after executing this line, poly will be stored with the data read from cin
	string line;
	getline(is, line);
	istringstream ss(line);

	Polynomial temp;
	double value;
	if (ss >> value) {
		// input not void, overwrite the 0-degree coefficient
		temp.coeff[0] = value;
		while (ss >> value)
			temp.coeff.push_back(value);
	}
	else {
		// input void, the polynomial should be 0, nothing to do here
	}
	poly = temp;
	return is;
}


int main() {
	Polynomial p1({ 1.0, 2.0, 1.0 }); // p1(x) = 1 + 2x + x^2
	Polynomial p2({ -1.0, 0.0, 1.0 }); // p1(x) = -1 + x^2
	cout << "p1 printed: " << p1 << endl;
	cout << "p2 printed: " << p2 << endl;

	
	// cout << "Is p2 < p1? Answer: " << (p2 < p1) << endl;

	
	Polynomial p3, p4;
	cin >> p3 >> p4;
	cout << "The inputted polynomial p3 is " << p3 << endl;
	cout << "The inputted polynomial p4 is " << p4 << endl;

	p2 += p4;
	cout << "p1 += p3 gives: " << (p1 += p3) << endl;

}
