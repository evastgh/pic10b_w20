#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Base {
	string name;
public:
	Base(const string& s) : name(s) {
		cout << "Constructing Base with name " << s << endl;
	}
	Base(const Base& other) : name(other.name + "(copied)") {
		cout << "Copy-constructing Base with name " << name << endl;
	}
	virtual ~Base() {
		cout << "Destructing Base with name " << name << endl;
	}
	const string& get_name() const { return name; }
};

class Derived : public Base {
	int data;
public: 
	Derived(const string& s, int i) : Base(s), data(i) {
		cout << "Constructing Derived with name " << s << " and data " << i << endl;
	}
	virtual ~Derived() {
		cout << "Destructing Derived with name " << get_name() << " and data " << data << endl;
	}
};
int main()
{
	// Base* base_ptr = new Derived(string("bruin"), 123);
	// delete base_ptr;

	vector<Base> vec;
	vec.push_back(Base(string("first element")));
	vec.push_back(Derived(string("second"), 101));
	// no memory leak

	vector<Base*> pvec;
	pvec.push_back(new Derived(string("thrid"), 103));

	for (size_t i = 0; i < pvec.size(); ++i)
		delete pvec[i];

	return 0;
}

