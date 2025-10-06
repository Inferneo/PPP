#include <iostream>
using std::cout;

void f(int arr[], int len) {
    int la[len];
    for (int x = 0; x < len; ++x) {
        la[x] = arr[x];
    }
    for (int x = 0; x < len; ++x) {
        cout << la[x] << '\t';
    }
    cout << '\n';
    int* p = new int[len];
    for (int x = 0; x < len; ++x) {
        p[x] = arr[x];
    }
    for (int x = 0; x < len; ++x) {
        cout << p[x] << '\t';
    }
    delete [] p;
    cout << '\n';
}

int main() {

    int ga[10];
    for (int x = 0; x < 10; ++x) {
        ga[x] = 1 << x;
    }
    f(ga, 10);
    
    int aa[10];
    int sum = 1;
    for (int x = 1; x <= 10; ++x) {
        sum *= x;
        aa[x-1] = sum;
    }
    f(aa, 10);
}



