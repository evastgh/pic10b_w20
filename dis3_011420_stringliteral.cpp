#include <iostream>
#include <string>
using namespace std;
void print(const string& s) { cout << s << endl; }
// void print(string&& s) { cout << s << endl; }
void printnum(const int& n) { cout << n << endl; }
int main()
{
    // string s = string("hi");
    // string s = "hi";
    print("hi");
    printnum(1);
    return 0;
}
