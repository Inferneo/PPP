#include <iostream>
#include <ostream>
using std::cout;

class Date {
public:
    Date(int yy, int mm, int dd)
        :y{yy}, m{mm}, d{dd}
        {}
    int year() {return y;}
    int month() {return m;}
    int day() {return d;}
private:
    int y, m, d;
};

std::ostream &operator<<(std::ostream &os, Date& d) {
  return os << d.year() << '/' << d.month() << '/' << d.day();
}

int main() {

    Date d {2024, 7, 21};
    cout << d << '\n';
    return 0;
}

