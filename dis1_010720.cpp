#include <iostream>
using namespace std;

int incm(int& x)
{
    x = x + 1;
    return x;
}

struct Baboon {
    Baboon(int n) { cout << "Baboon receiving " << n; }
};

class Rakun {
  public:
    double trash;
    Baboon babu;
    Rakun() : trash(5.6), babu(7) {}
};

int main()
{
    // Rakun r = 0; // this line won't compile
    Rakun r;
    // cout << r.trash;
    
    /*
    int ten = 10;
    incm(ten);
    cout << ten;
    */
    
    /*
    int a;
    a++;
    cout a;
    
    double b;
    b++;
    cout << b;
    
    string s = "pic10"'
    cout << s[1];
    
    string ss;
    cout << ss[1];
    */
    
    return 0;
}
