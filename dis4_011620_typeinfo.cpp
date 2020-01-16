#include <iostream>
#include <typeinfo>
using namespace std;
int succ(int n) { return n+1; }
int add(double a, float b) { return a+b; }
typedef int (*IntFuncDoubFloPtr)(double, float);
int compute(double a, float b, IntFuncDoubFloPtr f) { return f(a, b); }
int main()
{
    cout << compute(5.0, -10.5, add) << endl;
    cout << typeid(compute).name() << endl;
    
    /*
    int *p;
    cout << typeid(p).name() << endl;
    cout << p << endl;
    int n = 5;
    p = &n;
    n++;
    cout << *p << endl;

    int array[5] = {0, 1, 2, 3, 4};
    int array4[4] = {0, -1, -2, -3};
    // array4 = array;  // compilation error: they are of different types!
    cout << typeid(array).name() << endl;
    cout << typeid(array[0]).name() << endl;
    cout << typeid(array[555666]).name() << endl;
    cout << typeid(succ).name() << endl;
    cout << typeid(add).name() << endl;
*/
    return 0;
}
