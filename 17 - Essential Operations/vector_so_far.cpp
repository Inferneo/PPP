#include <algorithm>
#include <initializer_list>
#include <iostream>

using std::copy;
using std::cout;
using std::initializer_list;

class Vector {
  /*
      invariant:
      if 0 <= n < sz, elem[n] is element n
      sz <= space;
      if sz < space there is space for (space - sz) doubles after elem[sz-1]
  */

  int sz;                                               // the size
  double* elem;                                         // pointer to the elements (or 0)
  int space;                                            // number of elements plus number of free slots

public:
    Vector() : sz(0), elem(nullptr), space(0) { }
    explicit Vector(int s) : sz(s), elem(new double[s]), space(s) {
        for (int i = 0; i < s; ++i) {
            elem[i] = 0;                                // elements are initialized
        }
    }

    Vector(initializer_list<double> lst);               // list initializer
    Vector& operator=(initializer_list<double> lst);    // list assignment

    Vector(const Vector&);                              // copy constructor
    Vector& operator=(const Vector&);                   // copy assignment

    Vector(Vector&&);                      
                 // move constructor
    Vector& operator=(Vector&&);                        // move assignment

    ~Vector() { delete [] elem; }                       // destructor

    double& operator[](int n) { return elem[n]; }       // access: return reference
    const double& operator[](int n) const { return elem[n]; }

    int size() const { return sz; }
    int capacity() const { return space; }

    void resize(int newsize);                           // growth
    void push_back(double d);
    void reserve(int newalloc);

    double* begin() const { return elem; }              // iteration support
    double* end() const { return elem + sz; }
};

Vector::Vector(initializer_list<double> lst)                    // initializer list constructor
        : sz(lst.end() - lst.begin()), 
          elem(new double[sz])                                  // uninitialized memory for elements
{
    copy(lst.begin(), lst.end(), elem);     // initialize using std::copy()
}

Vector& Vector::operator=(initializer_list<double> lst) {
    if (lst.size() > sz) {
        delete [] elem;
        space = lst.size();
        elem = new double[space];
    }
    sz = lst.size();
    copy(lst.begin(), lst.end(), elem);
    return *this;
}

Vector::Vector(const Vector& arg)                           // allocate elements, then initialize them by copying
    : sz(arg.sz), elem(new double[arg.sz]) 
{
    copy(arg.elem, arg.elem+sz, elem);  // copy elements [0:sz) from elem.arg into elem
}


Vector::Vector(Vector&& arg) 
    : sz(arg.sz), elem(arg.elem)    // copy arg's elem and sz
{
    arg.sz = 0;                     // make arg the empty Vector
    arg.elem = nullptr;
}

Vector& Vector::operator=(Vector&& arg)     // move arg to this Vector
{
    if (this != &arg) {         // protect against self-assignment
        delete [] elem;         // deallocate old space
        elem = arg.elem;        // copy arg's elem and sz
        sz = arg.sz;        
        arg.elem = nullptr;     // make arg the empty Vector 
        arg.sz = 0;
    }
    return *this;               // return a self-reference
}

void Vector::reserve(int newalloc) {
    if (newalloc <= space) {                            // never decrease allocation
        return;
    }
    double* p = new double[newalloc];                   // allocate new space
    for (int i = 0; i < sz; ++i) {                      // copy old elements
        p[i] = elem[i];
    }
    delete [] elem;                                     // deallocate old space
    elem = p;
    space = newalloc;
}

void Vector::resize(int newsize) 
// make the vector have newsize elements
// initialize each new element with the default value 0.0
{
    reserve(newsize);
    for (int i = sz; i < newsize; ++i) {    // initialize new elements
        elem[i] = 0;
    }
    sz = newsize;
}

void Vector::push_back(double d) 
// increase vector size by one; initialize the new element with d
{
    if (space == 0) {                       // start with space for 8 elements
        reserve(8);
    }
    else if (sz == space) {
        reserve(2 * space);       // get more space
    }
    elem[sz] = d;                           // add d at the end
    ++sz;                                   // increase the size (sz is the number of elements)
}

Vector& Vector::operator=(const Vector& a) 
// like copy constructor, but we must deal with old elements
{
    if (this == &a) {                       // self-assignment, no work needed  
        return *this;
    }

    if (a.sz <= space) {                    // enough space, no need for new allocation
        for (int i = 0; i < a.sz; ++i) {    // copy elements
            elem[i] = a.elem[i];
        }
        sz = a.sz;
        return *this;
    }

    double* p = new double[a.sz];           // allocate new space
    for (int i = 0; i < sz; ++i) {          // copy elements
        p[i] = a.elem[i];
    }
    delete [] elem;                         // deallocate old space

    space = sz = a.sz;                      // set new size
    elem = p;                               // set new elements
    return *this;                           // return self-reference
}

bool operator==(Vector& v1, Vector& v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    for (int i = 0; i < v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
};

bool operator!=(Vector& v1, Vector& v2) { 
    return !(v1 == v2); 
};

int main() {
    Vector V(1);
    V.resize(-30);

    cout << V.size() << '\n';
    cout << V.capacity() << '\n';

}