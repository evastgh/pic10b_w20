#include <iostream>
#include <vector>
using namespace std;
/*
	sort the input vector vec to ascending order
*/
void mergeSort(vector<int>& vec, size_t start, size_t end) {
	if (end-start <= 1) // end-start is the size!
		return;

	// no need to make copies of vec_left and vec_right

	// recursive calls HERE!!!
	size_t middle = start + (end - start) / 2;
	mergeSort(vec, start, middle); // vec_left
	mergeSort(vec, middle, end); // vec_right

	size_t size_left = middle - start;
	size_t size_right = end - middle;

	// merge vec_left and vec_right in ascending order
	vector<int> return_value;
	size_t i_left = start, i_right = middle;
	while (i_left < middle && i_right < end) {
		if (vec[i_left] < vec[i_right]) {
			return_value.push_back(vec[i_left]);
			i_left++;
		}
		else {
			return_value.push_back(vec[i_right]);
			i_right++;
		}
	}
	// one of these two predicates is violated, not both
	// i_left < vec_left.size()  vs.  i_right < vec_right.size()
	// and we need to put the remaining elements into return_value
	if (i_left < middle) {
		for (; i_left < middle; ++i_left)
			return_value.push_back(vec[i_left]);
	}
	else {
		for (; i_right < end; ++i_right)
			return_value.push_back(vec[i_right]);
	}

	// no return_value, so assign vec to return_value
	for (size_t i = start; i < end; ++i)
		vec[i] = return_value[i - start];
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
	mergeSort(vec, 0, vec.size());
	cout << "Sorted vector:" << endl;
	cout << vec;
}
