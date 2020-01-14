#include <iostream>
using namespace std;

int main()
{
    int array[3] = {0, 1, 2};
    cout << "check pt 1" << endl;
    delete[] array;
    cout << "check pt 2" << endl;
    return 0;
}
