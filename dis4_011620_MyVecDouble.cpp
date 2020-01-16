#include <iostream>
#include <vector>
using namespace std;
struct MyVecDouble {
    MyVecDouble(size_t size_in, double value)
        : m_size(size_in)
        , m_data(new double[m_size]) 
    {
        m_data = new double[m_size];
        for (size_t i = 0; i < m_size; ++i)
            m_data[i] = value;
    }
    ~MyVecDouble() { delete[] m_data; }
    void resize(size_t new_size) {
        double* new_data = new double[new_size];
        for (size_t i = 0; i < m_size && i < new_size; ++i) 
            new_data[i] = m_data[i]; // deep copy
        
        delete[] m_data;
        m_data = new_data;
        m_size = new_size;
    }
    size_t size() const { return m_size; }
    double operator[](size_t i) { return m_data[i]; }
    private:
    size_t m_size;
    double* m_data;
};
int main()
{
    MyVecDouble v(20, 55.66);
    v.resize(10);
    for (size_t i = 0; i < v.size(); ++i)
        cout << v[i] << ' ';

    return 0;
}
