#include <cmath>
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

    // int* p1 = new int(7);
    // int* p2 = new int[7];

    // for (int i = 0; i < 7; ++i) {
    //     p2[i] = 1 << i;
    // }

    // int* p3 = p2;

    // p2 = p1;
    // p2 = p3;
    
    // cout << "p1: " << p1 << '\n';
    // cout << "*p1: " << *p1 << '\n';
    // cout << "p2: " << p2 << '\n';
    // cout << "*p2: " << *p2 << '\n';

    // delete p1;
    // delete[] p2;

    // int* p1 = new int[10];
    // for (int i = 0; i < 10; ++i) {
    //     p1[i] = 1 << i;
    // }

    // int* p2 = new int[10];
    // for (int i = 0; i < 10; ++i) {
    //     p2[i] = p1[i];
    // }

    // print_array(cout, p1, 10);
    // print_array(cout, p2, 10);

    // delete [] p1;
    // delete[] p2;

    vector<int> vten_p1(10);
    vector<int> vten_p2(10);

    for (int i = 0; i < 10; ++i) {
        vten_p1[i] = 1 << i;
    }
    vector<int>* v_p1 = &vten_p1;
    vector<int>* v_p2 = &vten_p2;

    for (int i = 0; i < 10; ++i) {
        (*v_p2)[i] = (*v_p1)[i];
    }

    print_vector(cout, *v_p1, 10);
    print_vector(cout, *v_p2, 10);

}