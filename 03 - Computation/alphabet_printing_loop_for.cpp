#include <iostream>
using namespace std;

int main(){
    for (char i = '0';i <= '9';++i){
        cout << i << '\t' << int(i) << '\n';
    }
    for (char i = 'A';i <= 'Z';++i){
        cout << i << '\t' << int(i) << '\n';
    }
    for (char i = 'a';i <= 'z';++i){
        cout << i << '\t' << int(i) << '\n';
    }
    return 0;
}