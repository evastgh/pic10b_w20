#include <iostream>
#include <vector>
using namespace std;

int main()
{
    bool proceed = true;
    /* fundamentalist approach
    double array[100]; // fixed size array
    size_t count = 0; */
    vector<double> array;
    while (proceed) {
        cout << "Please input a floating point number: ";
        double input;
        cin >> input;
        
        /* fundamentalist
        array[count] = input;
        count++;*/
        array.push_back(input);
        
        cin.get();
        cout << "Continue? (y/n)";
        char c;
        cin.get(c);
        if (c=='y')
            proceed = true;
        else
            proceed = false;
    }
    /* fundamentalist 
    for (size_t i = 0; i < count; ++i)
        cout << array[i] << ' ';*/
    for (size_t i = 0; i < array.size(); ++i)
        cout << array[i] << ' ';
    // print the double inputted above???
    

    return 0;
}
