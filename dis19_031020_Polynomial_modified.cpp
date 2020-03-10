#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Polynomial {
	vector<double> coeff;

public:
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
	Polynomial& operator-=(const Polynomial& other) {
		if (this->get_deg() >= other.get_deg()) {
			for (size_t i = 0; i <= other.get_deg(); ++i)
				coeff[i] -= other.coeff[i];
		}
		else {
			size_t i = 0;
			for (; i <= this->get_deg(); ++i)
				coeff[i] -= other.coeff[i];
			for (; i <= other.get_deg(); ++i)
				coeff.push_back(-other.coeff[i]);
		}
		return *this;
	}

	Polynomial operator-() {
		Polynomial temp;
		temp -= *this;
		return temp;
	}
	operator vector<double>() const { return coeff; }
	double& operator[] (size_t i) { return coeff[i]; }
	double operator[] (size_t i) const { return coeff[i]; } // what happens if I forgot const?
	double& operator() (size_t i) { return coeff[i]; }
	double operator() (size_t i) const { return coeff[i]; }

	friend ostream& operator<<(ostream& os, const Polynomial& poly);
	friend istream& operator>>(istream& is, Polynomial& poly);

	friend double& constant_term(Polynomial& poly);
	friend double& leading_term(Polynomial& poly);

	friend Polynomial operator+(const Polynomial& p1, const Polynomial& p2);

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

Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
	Polynomial temp(p1.coeff);
	temp += p2;
	return temp;
}

double& constant_term(Polynomial& poly) { return poly.coeff[0]; }
double& leading_term(Polynomial& poly) { return poly.coeff[poly.get_deg()]; }

int main() {
	Polynomial p1({ 1.0, 2.0, 1.0 }); // p1(x) = 1 + 2x + x^2
	Polynomial p2({ -1.0, 0.0, 1.0 }); // p1(x) = -1 + x^2
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;

	p1 += vector<double>({ 1.0 , 2.0 });
	cout << "p1 = " << p1 << endl;

	leading_term(p1) = 5566;
	cout << "p1 = " << p1 << endl;

	cout << "-p2 = " << (-p2) << endl;

	vector<double> coeff_copy = p2;
	cout << "coeff_copy = " << coeff_copy[0] << endl;

	cout << "p1 + p2 = " << (p1 + p2) << endl;

	// cout << "Is p2 < p1? Answer: " << (p2 < p1) << endl;

	
	// Polynomial p3, p4;
	// cin >> p3 >> p4;
	// cout << "The inputted polynomial p3 is " << p3 << endl;
	// cout << "The inputted polynomial p4 is " << p4 << endl;

	// p2 += p4;
	// cout << "p1 += p3 gives: " << (p1 += p3) << endl;



}
