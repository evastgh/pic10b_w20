#include <iostream>
using namespace std;
struct MyClass {
    int student_count;
    MyClass(int sc) : student_count(sc) {}
};

ostream& operator<<(ostream& os, const MyClass& mc) {
    os << "MyClass has " << mc.student_count << " students.";
    return os;
}
    
int main()
{
    MyClass mc(30);
    int n = 5;
    cout << mc << endl;
    return 0;
}
