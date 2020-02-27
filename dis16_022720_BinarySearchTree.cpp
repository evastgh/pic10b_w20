#include <iostream>
using namespace std;

struct TreeNode {
	TreeNode(int data_in) : data(data_in), left(NULL), right(NULL) {
		cout << "Constructing TreeNode with data " << data << endl;
	}
// private: 
	int data;
	TreeNode* left;
	TreeNode* right;
};

void printTree(string prefix, TreeNode* start) {
	if (start == NULL) {
		return;
	}
	cout << prefix << start->data << endl;
	printTree(prefix+"L", start->left);
	printTree(prefix+"R", start->right);
}

struct BinarySearchTree {
	// private:
	TreeNode* root;
	TreeNode* search_helper(int value, TreeNode* start) {
		cout << "calling search_helper with value " << value << " and start " << start << endl;
		if (start == NULL)
			return NULL;
		int mid_data = start->data;
		cout << "start is not NULL, it has data " << mid_data << endl;
		if (value == mid_data) {
			return start;
		}
		else {
			if (value < mid_data) {
				cout << "value is smaller, going left" << endl;
				search_helper(value, start->left);
			}
			else {
				cout << "value is bigger, going right" << endl;
				search_helper(value, start->right);
			}
		}
	}
	TreeNode* search(int value) {
		/*
		Example: binary search on sorted vector<int> vec
		int middle = vec[vec.size()/2];
		if (value = middle)
			return vec.size()/2;
		else {
			if (value < middle)
				return search(value, first_half_of_vec);
			else
				return search(value, second_half_of_vec);
		}
		*/
		return search_helper(value, root);
	}
	TreeNode* insert_helper(int value, TreeNode* start) {
		// if (start==NULL) .... too late, no info for insertion?!
		if (value <= start->data) {
			if (start->left == NULL) {
				start->left = new TreeNode(value);
				return start->left;
			}
			return insert_helper(value, start->left);
		}
		else {
			if (start->right == NULL) {
				start->right = new TreeNode(value);
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

	void printState() {
		printTree(string(""), root);
	}
};

int main()
{
	BinarySearchTree t;
	t.root = new TreeNode(55);
	t.root->left = new TreeNode(30);
	t.root->right = new TreeNode(70);
	t.insert(71);
	t.insert(80);
	t.insert(21);
	t.insert(55);
	t.printState();
	
	if (t.search(71) != NULL) {
		cout << "71 is found in tree" << endl;
	}
}
