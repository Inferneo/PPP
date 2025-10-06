#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::string;
using std::vector;

struct X {
    int val;

    void out(const string& s, int nv) {
        cout << this << " -> " << s << " : " << val << " (" << nv << ")\n";
    }

    X() { out("X()", 0); val = 0; }                            // default constructor
    X(int x) { out("X(int)", x); val = x; }
    X(const X& x) { out("X(X&)", x.val); val = x.val; }         // copy constructor
    X(X&& x) { out("X(X&&)", x.val); val = x.val; x.val = 0; }  // move constructor

    X& operator=(const X& x) {
        out("X copy assignment", x.val); val = x.val; return *this;
    }
    X& operator=(X&& x) { 
        out("X move assignment", x.val); val = x.val; x.val = 0; return *this;
    }
    ~X() { out("~X()", 0); }                                    // destructor
};


X glob {2};     // a global variable

X copy(X a) { cout << "copy()\n"; return a; }
X copy2(X a) { cout << "copy2()\n"; X aa = a; return aa; }
X& ref_to(X& a) { cout << "ref_to()\n"; return a; }
X* make(int i) { cout << "make()\n"; X a(i); return new X(a); }

struct XX { X a; X b; };    // members

int main() {

    X loc {4};              // local variable
    X loc2 {loc};              // copy construction
    loc = X{5};             // copy assignment
    loc2 = copy(loc);       // call by value and return
    loc2 = copy2(loc);
    X loc3 {6};
    X& r = ref_to(loc);     // call by reference and return
    delete make(7);
    delete make(8);
    vector<X> v(4);         // default values
    XX loc4;
    X* p = new X{9};        // an X on the free store
    delete p;
    X* pp = new X[5];         // an array of Xs on the free store
    delete[] pp;

}