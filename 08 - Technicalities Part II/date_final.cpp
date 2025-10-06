#include <ostream>
#include <vector>
#include <iostream>

struct Year {
    int y;
};

enum class Month {
    jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
public:
    Date(){}
    Date(Year y):y{Year{y}}{}
    Date(Year y, Month m, int d):y{y}, m{m}, d{d}{}
    Year year() const {return y;}
    Month month() const {return m;}
    int day() const {return d;}
    bool is_valid();
    void add_day(int n);
private:
    Year y {2001};
    Month m {Month::jan};
    int d {1};
};

int to_int(Month m) {
    return static_cast<int>(m);
}

bool Date::is_valid(){

    if (to_int(m) > 12 || 1 > to_int(m)) {
        return false;
    }

    if (d > 31 || 1 > d) {
      return false;
    }

    return true;
}

Month operator++(Month& m) {
    m = (m == Month::dec) ? Month::jan : Month{to_int(m) + 1};
    return m;
}

bool operator==(const Date& a, const Date& b) {
    return a.year() == b.year() && a.month() == b.month() && a.day() == b.day();
}

void Date::add_day(int n) {
    d += n;

    if (m == Month::feb && d > 28) {
        d -= 28;
        ++m;
    }
    else if (d > 31 && (m == Month::jan || m == Month::mar || m == Month::may || m == Month::jul 
                   || m == Month::aug || m == Month::oct || m == Month::dec)) {
                    d -= 31;
                    ++m;
                    if (m == Month::jan) {
                        y.y += 1;
                    }
    }
    else if (d > 30) {
        d -= 30;
        ++m;
    }

}

std::vector<std::string> month_tbl = {"Not a month", "January", "February", "March",
                                      "April", "May", "June", "July", "August",
                                      "September", "October", "November", "December"};

std::ostream &operator<<(std::ostream &os, Date& d) {
  return os << d.year().y << '/' << month_tbl[to_int(d.month())] << '/' << d.day();
}

int main() {
    
    Date today {Year{2025}, Month{12}, 31};
    Date tomorrow = today;
    tomorrow.add_day(1);
    std::cout << tomorrow << '\n'; 

    return 0;
}


