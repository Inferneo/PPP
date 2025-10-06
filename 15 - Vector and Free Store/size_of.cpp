#include <iostream>

void sizes(char c, int i, int* p, bool b, double d) {
    std::cout << "the size of char is " << sizeof(char) << ' ' << sizeof(c) << '\n';
    std::cout << "the size of int is " << sizeof(int) << ' ' << sizeof(i) << '\n';
    std::cout << "the size of int* is " << sizeof(int*) << ' ' << sizeof(p) << '\n';
    std::cout << "the size of bool is " << sizeof(bool) << ' ' << sizeof(b) << '\n';
    std::cout << "the size of double is " << sizeof(double) << ' ' << sizeof(d) << '\n';
}

int main() {
    int n = 65;
    int* ptr = &n;
    sizes('a', 6, ptr, true, 4.5);
}