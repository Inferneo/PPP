#include <iostream>
using namespace std;

int main(){
    char i = 'a';
    while (i <= 'z'){
        cout << i << '\t' << int(i) << '\n';
        ++i;
    }
    return 0;
}