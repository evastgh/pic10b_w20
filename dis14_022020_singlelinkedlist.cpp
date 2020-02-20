#include <iostream>
using namespace std;
struct Node {
	string data;
	Node* next;
	Node(const string& data_in) : data(data_in), next(nullptr) {}
	~Node() {
		cout << "Calling destructor of Node with data = " << data << endl;
	}
};
struct List {
	Node* first;
	List() : first(nullptr) { }
	List(Node* node) : first(node) {}
	void insert(Node* pos, Node* to_be_inserted) {
		// ?
	}
	void destructor_helper(Node* node) {
		if (node->next == nullptr)
			delete node;
		else {
			destructor_helper(node->next);
			delete node;
		}
	}
	~List() {
		destructor_helper(first);
	}
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
	{
		Node* second = new Node("world");
		first->next = second;
		Node* third = new Node("my");
		second->next = third;
	}
	List l(first);
	// Now I have a single-linked list with two elements!

	// cout << first << endl;
	// delete first; // this deletes all first, second, third, ...

}
