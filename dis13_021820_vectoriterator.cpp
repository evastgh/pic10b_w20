#include <iostream>
#include <vector>
using namespace std;
ostream& operator<<(ostream& os, const vector<int>& vec) {
	// for (size_t i = 0; i < vec.size(); ++i)
	// 	os << vec[i] << ' ';
	for (vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it)
		os << *it << ' ';

	os << "END";
	return os;
} // this operator overload allows 'cout << my_vec;'
int main()
{
	/*
	vector<int> v;
	v.push_back(101);
	v.push_back(102);
	v.push_back(103);
	*/
	vector<int> vec = { 101, 102, 103 }; // syntactic sugar: initiali... list? ?? 
	for (size_t i = 0; i < vec.size(); ++i) {
		cout << vec[i] << ' ';
	}
	cout << endl;

	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
		cout << *it << ' ';
		// cout << vec[it] << ' '; // iterator is not an index!
		// cout << it << ' '; // no operator<< implemented for iterator
	}
	for (vector<int>::iterator it = vec.begin(); it < vec.end(); ++it) {
		cout << *it << ' ';
		*it = 105; // dereference it to modify the value of entries in vec
	}
	cout << vec.back();
	// vec.back() returns int& of it's last element
	// vec.end() returns an iterator pointing to &(vec.back())+1

	// read about const_iterator
}
