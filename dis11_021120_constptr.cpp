int main()
{
	int sample[3] = { 0, 1, 2 };
	int another[3] = { 5, 6, 7 };

	sample[0] = 5566;


	int const* arr = sample;
	arr[0] = 5; // error, dereferencing arr results in type "int const"
	arr = another; // okay
	const int* brr = sample;
	brr[0] = 5; // error, dereferencing brr results in type "const int"
	brr = another; // okay
	int* const crr = sample;
	crr[0] = 5; // okay
	crr = another; // error, crr is a const variable of type "int*", cannot modify it
}
