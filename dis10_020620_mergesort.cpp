#include <iostream>
#include <vector>
using namespace std;
/*
	sort the input vector vec to ascending order
*/
void mergeSort(vector<int>& vec) {
	if (vec.size() <= 1) // if this is == 0, the recursion wouldn't terminate :O
		return;

	vector<int> vec_left, vec_right;
	for (size_t i = 0; i < vec.size() / 2; ++i)
		vec_left.push_back(vec[i]);
	for (size_t i = vec.size() / 2; i < vec.size(); ++i)
		vec_right.push_back(vec[i]);

	// recursive calls HERE!!!
	mergeSort(vec_left);
	mergeSort(vec_right);

	// merge vec_left and vec_right in ascending order
	vector<int> return_value;
	size_t i_left = 0, i_right = 0;
	while (i_left < vec_left.size() && i_right < vec_right.size()) {
		if (vec_left[i_left] < vec_right[i_right]) {
			return_value.push_back(vec_left[i_left]);
			i_left++;
		}
		else {
			return_value.push_back(vec_right[i_right]);
			i_right++;
		}
	}
	// one of these two predicates is violated, not both
	// i_left < vec_left.size()  vs.  i_right < vec_right.size()
	// and we need to put the remaining elements into return_value
	if (i_left < vec_left.size()) {
		for (; i_left < vec_left.size(); ++i_left)
			return_value.push_back(vec_left[i_left]);
	}
	else {
		for (; i_right < vec_right.size(); ++i_right)
			return_value.push_back(vec_right[i_right]);
	}

	// no return_value, so assign vec to return_value
	vec = return_value;
	// or swap(vec, return_value)
	// see https://en.cppreference.com/w/cpp/algorithm/swap
}

ostream& operator<<(ostream& os, const vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); ++i)
		os << vec[i] << ", ";
	return os;
}

int main()
{
	vector<int> vec = { 10, 1, 9, 6, 17, 500, 90, 2 };
	cout << vec << endl;
	mergeSort(vec);
	cout << "Sorted vector:" << endl;
	cout << vec;
}
