#include <iostream>
#include <string>

class B1 {
public:
    virtual void vf() const{
        std::cout << "B1::vf()" << '\n';
    };
    void f() const{
        std::cout << "B1::f()" << '\n';
    };
    virtual void pvf() const = 0;
};

class D1 : public B1 {
public:
    void vf() const override {
        std::cout << "D1::vf()" <<'\n';
    }
    void f() const {
        std::cout << "D1::f()" <<'\n';
    }
};

class D2 : public D1 {
    public:
    void pvf() const override {
        std::cout << "D2::pvf()" << '\n';
    }
};

class B2 {
    public:
    virtual void pvf() const = 0;
};

class D21 : public B2 {
    public:
    std::string s = "Override, baby.";
    void pvf() const override {
        std::cout << s << '\n';
    }
};

class D22 : public B2 {
    public:
    int n = 55;
    void pvf() const override {
        std::cout << n << '\n';
    }
};

void f (B2& b2_ref) {
    b2_ref.pvf();
}

int main() {
    // B1 b1;
    // b1.vf();
    // b1.f();

    // D1 d1;
    // d1.vf();
    // d1.f();

    // B1& b1_ref = d1;
    // b1_ref.vf();
    // b1_ref.f();

    // D2 d2;
    // d2.vf();
    // d2.f();
    // d2.pvf();

    D21 d21;
    D22 d22;

    B2& b2_ref = d22;

    f(b2_ref);
}