#include <iostream>
using namespace std;
struct MyArray {
    int* m_ptr;
    MyArray(int n) : m_ptr(new int[n]) {}
    ~MyArray() { delete[] m_ptr; }
};
int main()
{
    int n;
    cin >> n;
    //int* array = new int[n];
    // delete[] array;
    MyArray ma(n);
    return 0;
}
