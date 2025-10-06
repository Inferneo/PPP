#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cout << "Enter a number:";
    cin >> n;
    cout << "\nn times 3:" << n*3
              << "\nn squared:" << n*n
              << "\nhalf of n:" << n/2
              << "\nsqrt of n:" << sqrt(n)
              << "\nn modulo 3:" << n%3
              << "\n"; 
    return 0;
}