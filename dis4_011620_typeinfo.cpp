#include <iostream>
#include <typeinfo>
using namespace std;
int main()
{
    int *p;
    cout << p << endl;
    cout << typeid(p).name();
    int n = 2;
    p = &n;
    n++;
    cout << endl << *p;
    
    return 0;
}
