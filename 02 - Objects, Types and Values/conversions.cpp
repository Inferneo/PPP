#include <iostream>
using namespace std;

int main(){
    double d = 0;
    while (cin>>d){
        int i = d;
        char c = i;
        cout << "d==" << d
             << "\ni==" << i
             << "\nc==" << c
             << "\nchar(" << c << ")\n";
    }
    return 0;
}