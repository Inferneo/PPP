#include <iostream>
#include <vector>

using std::cout;
using std::vector;

void f(vector<int> v){
    vector<int> lv(v.size());
    lv = v;
    for (int x:lv) {
        cout << x << '\t';
    }
    cout << '\n';
    vector<int> lv2 = v;
    for (int x : lv2) {
        cout << x << '\t';
    }
    cout << '\n';
}

int main() {
    vector<int> gv;
    for (int x = 0; x < 10; ++x) {
        gv.push_back(1 << x);
    }
    f(gv);

    vector<int> vv;
    int fact = 1;
    for (int x = 1; x <= 10; ++x) {
        fact *= x;
        vv.push_back(fact); 
    }
    f(vv);
}