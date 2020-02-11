#include <iostream>

int* search(int arr[], size_t size, const int c) {
	if (size == 0) {
		return nullptr;
	}
	else {
		if (*arr == c) {
			return arr;
		}
		else {
			arr++;
			size--;
			return search(arr, size, c);
		}
	}
}
int main() {
	int* arr = new int[5];
	arr[0] = 1;
	arr[1] = 4;
	arr[2] = 9;
	arr[3] = 10;
	arr[4] = 15;

	std::cout << search(arr, 5, 5);
	return 0;
}
