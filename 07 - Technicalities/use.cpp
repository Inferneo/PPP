#include "foo.h"
#include "foo.cpp"

// #include <iostream>
// using std::cout;

auto run() -> void {
    return;
}

int main() {
    print_foo();
    print(foo);
    return 0;
}