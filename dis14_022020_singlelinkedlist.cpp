#include <iostream>
using namespace std;
struct Node {
	string data;
	Node* next;
	Node(const string& data_in) : data(data_in), next(nullptr) {}
	~Node() {  }
};
void print(Node* node) {
	while (true) {
		cout << node->data << ' ';
		if (node->next == nullptr)
			break;
		else
			node = node->next;
	}
	cout << "EOL";
}
ostream& operator<<(ostream& os, Node* node) {
	while (true) {
		os << node->data << ' ';
		if (node->next == nullptr)
			break;
		else
			node = node->next;
	}
	os << "EOL";
	return os;
}

int main()
{
	Node* first = new Node("Hello");
	Node* second = new Node("world");
	first->next = second;
	Node* third = new Node("my");
	second->next = third;
	// Now I have a single-linked list with two elements!

	cout << first;
	delete first; // this deletes all first, second, third, ...

}
