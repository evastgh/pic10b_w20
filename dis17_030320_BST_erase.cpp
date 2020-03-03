#include <iostream>
using namespace std;

struct TreeNode {
	TreeNode(int data_in) : data(data_in), parent(NULL), left(NULL), right(NULL) {}
	int data;
	TreeNode* parent; // keeping track of its parent!
	TreeNode* left;
	TreeNode* right;
	void print() {
		cout << "data " << data << " current " << this << " parent " << parent << " left " << left << " right " << right << endl;	
	}
	~TreeNode() {
		cout << "Calling destructor with";
		this->print();
		if (parent != NULL) {
			// parent still exist, erase link with its parents!
			if (parent->left == this) {
				parent->left = NULL;
				parent->print();
			}
			else if (parent->right == this)
				parent->right = NULL;
			else
				cout << "This child is abandoned." << endl;
		}
	}
};

void printTree(string prefix, TreeNode* start) {
	if (start == NULL) {
		return;
	}
	cout << prefix << ' ';
	start->print();
	printTree(prefix+"L", start->left);
	printTree(prefix+"R", start->right);
}

struct BinarySearchTree {
	TreeNode* root;
	TreeNode* search_helper(int value, TreeNode* start) {
		if (start == NULL)
			return NULL;
		int mid_data = start->data;
		if (value == mid_data) { return start; }
		else {
			if (value < mid_data) return search_helper(value, start->left);
			else return search_helper(value, start->right);
		}
	}
	TreeNode* search(int value) {
		TreeNode* start = root;
		return search_helper(value, root);
	}
	TreeNode* insert_helper(int value, TreeNode* start) {
		if (value <= start->data) {
			if (start->left == NULL) {
				start->left = new TreeNode(value);
				start->left->parent = start; // keep track of parent!
				return start->left;
			}
			return insert_helper(value, start->left);
		}
		else {
			if (start->right == NULL) {
				start->right = new TreeNode(value);
				start->right->parent = start; // keep track of parent!
				return start->right;
			}
			return insert_helper(value, start->right);
		}
	}
	TreeNode* insert(int value) {
		TreeNode* pos = this->search(value);
		if (pos != NULL) {
			// don't insert, just return this position
			return pos;
		}
		else
			return insert_helper(value, root);
		// this function can be improved by rewriting insert_helper
		// to avoid calling search, which is an expensive recursive call
	}
	
	bool erase(int value) {
		TreeNode* find_result = search(value);
		if (find_result == NULL)
			return false;

		if (find_result->left == NULL && find_result->right == NULL) {
			// find_result is at the bottom, no need to promote anything, just delete
			delete find_result;
			return true;
		}

		if (find_result->left != NULL && find_result->right == NULL) {
			// promote left subtree
			TreeNode* left_subtree = find_result->left;
			if (find_result->parent == NULL) { // find_result == root
				root = left_subtree;
				delete find_result;
			}
			else if (find_result->parent->left == find_result) {
				find_result->parent->left = left_subtree;
				delete find_result;
			}
			else {
				find_result->parent->right = left_subtree;
				delete find_result;
			}
			return true;
		}

		if (find_result->left == NULL && find_result->right != NULL) {
			// promote right subtree
			TreeNode* right_subtree = find_result->right;
			if (find_result->parent == NULL) { // find_result == root
				root = right_subtree;
				delete find_result;
			}
			else if (find_result->parent->left == find_result) {
				find_result->parent->left = right_subtree;
				delete find_result;
			}
			else {
				find_result->parent->right = right_subtree;
				delete find_result;
			}
			return true;
		}

		// find_result has both sides, find right_min and swap
		TreeNode* right_min = find_result->right;
		while (right_min->left != NULL) {
			right_min = right_min->left;
		}

		find_result->data = right_min->data; // move data up

		if (right_min->parent == NULL) {
			cout << "what's happening?" << endl;
			cin.get();
		}
		if (right_min->parent->left == right_min) {
			right_min->parent->left = right_min->right;
			delete right_min;
		}
		else {
			right_min->parent->right = right_min->right;
			delete right_min;
		}

		return true;
	}

	void printState() const {
		printTree(string(""), root);
	}
};

int main()
{
	BinarySearchTree t;
	t.root = new TreeNode(55);
	t.insert(30);
	t.insert(70);
	t.insert(71);
	t.insert(80);
	t.insert(21);
	t.insert(55);
	t.insert(40);
	t.printState();

	cout << "Erasing 55" << endl;
	t.erase(55);
	t.printState();

}
