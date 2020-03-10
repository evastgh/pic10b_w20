#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
class Polynomial {
	vector<double> coeff;

public:
	Polynomial() : coeff(1, 0.0) {} // this is a polynomial p = 0.0 + 0.0x + ...
	Polynomial(const vector<double>& coeff_in) : coeff(coeff_in) {
	    if (coeff_in.size() == 0)
	        coeff.push_back(0.0);
	}
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
	    // Calling 'p1 += p2' will modify the state of p1; p2 is unchanged
	    // While executing the operator+=, '*this' refers to p1 
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

    // This allows 'cout << (-p1) << endl; '
    // This also allows 'p1 += (-p2); '
    // 
    // Recall: prefix operator is 'T& operator++()'
    //        postfix operator is 'T operator++(int)'
    // Calling for '-p1', it's prefix
	Polynomial operator-() {
		Polynomial temp; // construct a zero polynomial
		temp -= *this;
		return temp;
	}
	
	// 'vector<double> vec' allows 'vec[1]'
	// Since Polynomial is just a vector, can we do something similar?
	// This following operators allow calling for 'Polynomial p1' with 'p1[0]'
	// This allows ' p1[0] = 5566; '
	double& operator[] (size_t i) { return coeff[i]; }
    double operator[] (size_t i) const { return coeff[i]; } // TEST THIS: what happens if I forgot const?
	
	// Note that this operator is not declared as 
	// double& operator(size_t i) { return coeff[i]; }
	// This allows ' p1(0) ', works similarly as ' p1[0] '
	double& operator() (size_t i) { return coeff[i]; }
	double operator() (size_t i) const { return coeff[i]; }

    // This is a type-casting operator
    // Casting a ' double d = 5.6; ' to int is ' int n = int(d); '
    // It allows calls for ' Polynomial p; ' with ' vector<double> vec = vector<double>(p); '
    // It's somewhat like the reverse of the constructor Polynomial(const vector<double>& c), 
    // which turns a vector<double> to a Polynomial
    operator vector<double>() const {
        return coeff;
        // The return value of this functional call is of type 'vector<double>'
        // The above is actualyl the same as doing:
        // vectour<double> temp = coeff;
        // return temp;
    }
	
	friend ostream& operator<<(ostream& os, const Polynomial& poly);
	friend istream& operator>>(istream& is, Polynomial& poly);

	friend double& constant_term(Polynomial& poly);
	friend double& leading_term(Polynomial& poly);
	
	double& constant_term_inclass(Polynomial& poly) { return poly.coeff[0]; }
	double& constant_term_inclass_noinput() { return coeff[0]; }

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
    // I didn't define a constructor Polynomial(const Polynomial& other)
    // But, I did have constructor Polynomial(const vector<double>& coeff)
    // And the type-casting operator operator vector<double>(const Polynomial& poly)
	Polynomial temp(p1);
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

	/* 
	p1 += vector<double>({ 1.0 , 2.0 });
	cout << "p1 = " << p1 << endl;
    
    
	leading_term(p1) = 5566;
	cout << "p1 = " << p1 << endl; 
	
	p1.constant_term_inclass(p1) = 101;
	p1.constant_term_inclass_noinput() = 105;
    */
    /*
	cout << "-p2 = " << (-p2) << endl;
	cout << "p2(0) = " << p2(0) << endl;
	p2[0] = 5566;
	cout << "p2 = " << p2 << endl;
	

	vector<double> coeff_copy = vector<double>(p2);
	cout << "coeff_copy.size() = " << coeff_copy.size() << endl;
	
	// Note the implicit casting:
	vector<double> coeff_copy_p1 = p1;
	Polynomial p3(coeff_copy_p1);
	cout << "p3 = " << p3 << endl;
    */

	cout << "p1 + p2 = " << (p1 + p2) << endl;
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	
	vector<double> vec = { 33.4, 5.8, 3.14 };
	cout << "p2 + vec = " << (p2 + vec) << endl;


	// cout << "Is p2 < p1? Answer: " << (p2 < p1) << endl;

	
	// Polynomial p3, p4;
	// cin >> p3 >> p4;
	// cout << "The inputted polynomial p3 is " << p3 << endl;
	// cout << "The inputted polynomial p4 is " << p4 << endl;

	// p2 += p4;
	// cout << "p1 += p3 gives: " << (p1 += p3) << endl;



}
