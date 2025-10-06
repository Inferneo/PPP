#include <iostream>
using namespace std;

int square(int x){
    int sum = 0;
    for (int i = 1;i <= x;++i){
        sum += x;
    }
    return sum;
}

int main(){
    for (int n = 1; n < 10; ++n){
        cout << n << '\t' << square(n) <<'\n';
    }
    return 0;
}