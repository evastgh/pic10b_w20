// c.f. https://www.geeksforgeeks.org/recursion/

#include <iostream>

int add(int a, int b) {
	std::cout << "adding a = " << a << " and b = " << b << std::endl;
	if (b == 0)
		return a;
	else
		return add(++a, --b);
}

// example 1
void fun1(int n) {
	int i = 0;
	if (n > 1)
		fun1(n - 1);
	for (i = 0; i < n; i++)
		std::cout << " * ";
	std::cout << std::endl;
}

// example 2
#define LIMIT 1000
void fun2(int n) {
	if (n <= 0)
		return;
	if (n > LIMIT) {
		std::cout << " * ";
		return;
	}
	std::cout << n << ' ';
	fun2(2 * n);
	std::cout << n << ' ';
}

// example 3
int fun3(int a, int b) {
	if (b == 0)
		return 0;
	if (b % 2 == 0)
		return fun3(a + a, b / 2);
	return fun3(a + a, b / 2) + a;
}

int main()
{
	// std::cout << add(5, -3);
	// fun1(5);
	// fun2(100);
	std::cout << fun3(4, 3);
}
