#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::vector;

ostream& print_array(ostream& os, int* a, int n) {
    for (int i = 0; i < n; ++i) {
        os << a[i] << '\t';
    }
    os << '\n';
    return os;
}

ostream& print_vector(ostream& os, vector<int> v, int sz) {
    for (int i = 0; i < sz; ++i) {
        os << v[i] << '\t';
    }
    os << '\n';
    return os;
}

int main() {

    int *ten = new int[10];
    int* eleven = new int[11];
    int* twenty = new int[20];

    for (int i = 0; i < 20; ++i) {
        if (i < 10) {
            ten[i] = 100 + i;
        }
        if (i < 11) {
            eleven[i] = 100 + i;
        }
        twenty[i] = 100 + i;
    }

    print_array(cout, ten, 10);
    print_array(cout, eleven, 11);
    print_array(cout, twenty, 20);
    
    delete[] ten;
    delete[] eleven;
    delete[] twenty;

    vector<int> vten(10);
    vector<int> veleven(11);
    vector<int> vtwenty(20);

    for (int i = 0; i < 20; ++i) {
        if (i < 10) {
            vten[i] = 100 + i;
        }
        if (i < 11) {
            veleven[i] = 100 + i;
        }
        vtwenty[i] = 100 + i;
    }

    print_vector(cout, vten, 10);
    print_vector(cout, veleven, 11);
    print_vector(cout, vtwenty, 20);
}