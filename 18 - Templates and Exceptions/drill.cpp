#include <algorithm>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>
#include <type_traits>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

template<typename T>
struct S {

private:
    T val;

public:
    S() : val{} {};
    explicit S(T val) : val(std::move(val)) {}

    void print_S() const;

    T& access();
    const T& access() const;

    T& operator=(const T&);
};

template <typename T> void S<T>::print_S() const {
  if constexpr (std::is_same_v<T, vector<int>>) {
    for (auto const &x : val) {
      cout << x << '\t';
    }
  } else {
    cout << val;
  }
  cout << '\n';
}

template <typename T> 
T& S<T>::access() { return val; }

template<typename T>
const T& S<T>::access() const { return val; }

template<typename T>
T& S<T>::operator=(const T& a) {
    return *this;
}

template <typename T> 
void read_val(T& v) { 
    cin >> v;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v) {
    os << "{ ";
    for (auto x : v) {
        os << x << ", ";
    }
    os << "}";
    return os;
}

template<typename T>
std::istream& operator>>(std::istream& is, vector<T>& v) {
    is >> v;
    return is;
}


int main() {

    S<int> int_S {};
    S<char> char_S {'f'};
    S<double> double_S {32.21};
    S<string> string_S {"prayer is the key"};
    S<vector<int>> vector_S {{1,2,3,5,8}};
    
    // read_val(int_S.access());
    // int l = int_S.access();
    // cout << l << '\n';
    
    // read_val(char_S.access());
    // char c = char_S.access();
    // cout << c << '\n';
    
    // read_val(double_S.access());
    // double d = double_S.access();
    // cout << d << '\n';
    
    // read_val(string_S.access());
    // string s = string_S.access();
    // cout << s << '\n';

    vector<int> v = vector_S.access();
    cout << v << '\n';
}