#include <iostream>
#include <string>
using namespace std;
class Parent {
	string name;
public:
	Parent(const string& name_in) : name(name_in) {
		cout << "constructing Parent with name = " << name_in << endl;
	}
	~Parent() { cout << "destructing Parent with name " << name << endl; }
	virtual void print() { cout << "Parent saying hi. " << endl; }
};

class Child : public Parent {
	int age;
public:
	Child(const string& name_in, int age_in) : Parent(name_in), age(age_in) {
		cout << "constructing Child with age = " << age_in << endl;
	}
	~Child() { cout << "destructing Child with age " << age << endl; }
	// void print() override { cout << "Child saying yo." << endl; }
	virtual void print() { cout << "Child saying yo." << endl; }

};

int main()
{
	// Child c("Young", 13);
	// c.print();
	Parent* ptr = new Child("Young", 13);
	(*ptr).print();
	return 0;
}
