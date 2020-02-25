#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class List;
class Iterator;

class Node
{
public:
	/**
	   Constructs a node with a given data value.
	   @param s the data to store in this node
	*/
	Node(string s);
private:
	string data;
	Node* previous;
	Node* next;
	friend class List;
	friend class Iterator; // wrapper to make accessing private data of Node easier, and provide functions to march in a list
};

class List
{
public:
	/**
	   Constructs an empty list;
	*/
	List();
	/**
	   Appends an element to the list.
	   @param data the value to append
	*/
	void push_back(string data);
	/**
	   Inserts an element into the list.
	   @param iter the position before which to insert
	   @param s the value to append
	*/
	void insert(Iterator iter, string s);
	/**
	   Removes an element from the list.
	   @param iter the position to remove
	   @return an iterator pointing to the element after the
	   erased element
	*/
	Iterator erase(Iterator iter);
	/**
	   Gets the beginning position of the list.
	   @return an iterator pointing to the beginning of the list
	*/
	Iterator begin();
	/**
	   Gets the past-the-end position of the list.
	   @return an iterator pointing past the end of the list
	*/
	Iterator end();

	~List() {
		Node* to_be_deleted = first;
		while (to_be_deleted != NULL) {
			Node* next_to_be_deleted = to_be_deleted->next;
			delete to_be_deleted;
			to_be_deleted = next_to_be_deleted;
		}
	}
private:
	Node* first;
	Node* last;
	friend class Iterator;
	friend ostream& operator<<(ostream&, List&);
};

class Iterator
{
public:
	/**
	   Constructs an iterator that does not point into any list.
	*/
	Iterator();
	/**
	   Looks up the value at a position.
	   @return the value of the node to which the iterator points
	*/
	string get() const;
	/**
	   Advances the iterator to the next node.
	*/
	// in STL list, this is Iterator& operator++(int)
	// we call this function with ++it
	// in this cpp file, iterators are incremented by calling it.next()
	void next();
	/**
	   Moves the iterator to the previous node.
	*/
	// similarly, this is --it in STL
	void previous();
	/**
	   Compares two iterators
	   @param b the iterator to compare with this iterator
	   @return true if this iterator and b are equal
	*/
	// in STL list, we loop over list by
	// for(list<string>::iterator it = l.begin(); !(it == l.end()); ++it)
	// alterantively, we can also do
	// for(list<string>::iterator it = l.begin(); bool(it); ++it)
	// in this cpp file, the syntax is
	// for(Iterator it = l.begin(); !it.equals(l.end()); it.next())
	// alternatively, we can also do
	// for(Iterator it = l.begin(); it.is_valid(); it.next())
	// with the function defined
	// bool is_valid() const { return position == NULL; }
	bool equals(Iterator b) const;

	Iterator(Node* p, List* c) : position(p), container(c) {}
	Iterator get_next() { return position? Iterator(position->next, container) : Iterator(NULL, container); }
	Iterator get_prev() { return position? Iterator(position->previous, container) : Iterator(NULL, container); }
private:
	Node* position;
	List* container;
	friend class List;
	friend ostream& operator<<(ostream&, List&);
};

ostream& operator<<(ostream& os, List& l) {
	for (Iterator pos = l.begin(); !pos.equals(l.end()); pos.next()) {
		Node* node = pos.position;
		Node* next = pos.get_next().position;
		Node* prev = pos.get_prev().position;
		os << "prev" << prev << "; current" << node << "; next" << next << "; data = ";
		if (node == NULL)
			os << "N/A" << endl;
		else
			os << pos.get() << endl;
	}
	return os;
}

Node::Node(string s)
{
	data = s;
	previous = NULL;
	next = NULL;
}

List::List()
{
	first = NULL;
	last = NULL;
}

void List::push_back(string data)
{
	Node* new_node = new Node(data);
	if (last == NULL) // List is empty
	{
		first = new_node;
		last = new_node;
	}
	else
	{
		// look at this->last
		// sew together last and new_node
		new_node->previous = last;
		last->next = new_node;

		// for bookkeeping purposes: List needs to keep track of the last item
		this->last = new_node;
	}
}

void List::insert(Iterator iter, string s)
{
	if (iter.position == NULL)
	{
		push_back(s);
		return;
	}

	Node* after = iter.position;
	Node* before = after->previous;
	Node* new_node = new Node(s);

	// sew new_node with before
	new_node->previous = before;
	if (before == NULL) // Insert at beginning
		first = new_node;
	else
		before->next = new_node;

	// sew new_node with after
	new_node->next = after;
	after->previous = new_node;

}

Iterator List::erase(Iterator iter)
{
	assert(iter.position != NULL);
	Node* remove = iter.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	if (remove == first)
		first = after;
	else
		before->next = after;
	if (remove == last)
		last = before;
	else
		after->previous = before;
	delete remove;
	Iterator r;
	r.position = after;
	r.container = this;
	return r;
}

Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}

Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

Iterator::Iterator()
{
	position = NULL;
	container = NULL;
}

string Iterator::get() const
{
	assert(position != NULL);
	return position->data;
}

void Iterator::next()
{
	assert(position != NULL);
	position = position->next;
}

void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position->previous;
}

bool Iterator::equals(Iterator b) const
{
	return position == b.position;
}

int main()
{
	List staff;
	Iterator pos;

	staff.push_back("Tom");
	staff.push_back("Dick");
	staff.push_back("Harry");

	for (Iterator pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << "\n";

	for (Iterator pos = staff.end() /*??*/; /*??*/; pos.previous())
		cout << pos.get() << "\n";


	cout << staff;

	/*
	staff.push_front("Tom");
	staff.push_front("Dick");
	staff.push_front("Harry");
	staff.push_front("Juliet");

	cout << "******* Initial List *******\n";
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << "\n";

	// reverse the list
	cout << "******* Reverse List *******\n";
	staff.reverse();
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << "\n";

	// swap two elements
	Iterator pos1, pos2;
	pos1 = staff.begin();
	pos2 = staff.begin();
	pos2.next();
	pos2.next();
	staff.swap(pos1, pos2);
	cout << "******* After Swapping *******\n";
	for (pos = staff.begin(); !pos.equals(staff.end()); pos.next())
		cout << pos.get() << "\n";
		*/
	return 0;
}

