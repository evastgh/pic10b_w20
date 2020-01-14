#include <iostream>
using namespace std;
int main()
{
    int array[5] = {0, 10, 100, 1000, 10000};
    cout << array << endl;
    cout << *array << endl;
    cout << *(array + 1) << endl;
    cout << array + 1 << endl;
    cout << "----------" << endl;
    
    void* v_ptr = array;
    cout << v_ptr << endl;
    cout << v_ptr + 1 << endl;
    cout << "----------" << endl;
    
    double* d_ptr = static_cast<double*>(v_ptr); // be careful with casting!
    cout << d_ptr << endl;
    cout << d_ptr + 1 << endl;
    cout << *d_ptr << endl;

    return 0;
}
