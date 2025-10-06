#include <iostream>
using std::cout;

class Ptr {
private:
    double* p;

public:
    Ptr() : p(nullptr) {};   // Default Constructor

    explicit Ptr(double d) : p(new double(d)){}

    Ptr(const Ptr&);                 // Copy Constructor
    Ptr& operator=(const Ptr&);      // Copy Assignment

    Ptr(Ptr&&);                // Move Constructor
    Ptr& operator=(Ptr&&);     // Move Assignment

    ~Ptr() { delete p;}        // Destructor

    double& operator*() { return *p; };
    const double& operator*() const { return *p; }

};

Ptr::Ptr(const Ptr& arg) : p(new double{*arg.p}){}

Ptr& Ptr::operator=(const Ptr& arg) { 
    if (&arg == this) {
        return *this; 
    }
    delete p;
    p = new double{*arg.p};
    return *this;
}

Ptr::Ptr(Ptr&& arg) : p(arg.p){ arg.p = nullptr; }

Ptr& Ptr::operator=(Ptr&& arg) {
    if (this != &arg) {
        delete p;
        p = arg.p;
        arg.p = nullptr;
    }
    return *this;
}

int main() {
    Ptr a {50};
    a = Ptr{30};
    *a = 70;
    double f = *a;
    cout << f << '\n';
}