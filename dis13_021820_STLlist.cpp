#include <iostream>
#include <list>
#include <string>
using namespace std;
ostream& operator<<(ostream& os, const list<string>& l) {
	for (list<string>::const_iterator it = l.cbegin(); it != l.cend(); ++it)
		os << *it << ' ';
	os << "EOL";
	return os;
}
int main()
{
	list<string> l;
	cout << "Initial l = " << l << endl; // if cbegin was requested here, it's probably null
	l.push_back("hello");
	list<string>::const_iterator begin = l.cbegin();
	l.push_back("world");
	cout << "After pushing l = " << l << endl;
	list<string>::const_iterator new_begin = l.cbegin();
	if (begin == new_begin) {
		cout << "begin == new_begin";
	}
	l.insert(++l.begin(), "inserted");
	cout << "After inserting l = " << l << endl;
	cout << "Last item of l = " << *(--l.end()) << endl;

}
