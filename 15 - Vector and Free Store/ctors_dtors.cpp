#include <iostream>

using std::cout;

struct Caller{
    Caller(int s) : fry(new int(s)) {
        cout << "Constructor called!" << '\n';
        cout << *fry <<'\n';
    };
    ~Caller() {
        cout << "Destructor called!" << '\n';
        cout << *fry <<'\n';
        delete fry;
    };

    int* fry;
};

int main() {
    Caller(34);
}