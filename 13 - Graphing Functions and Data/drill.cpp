#include <cctype>
#include <iostream>
#include <istream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

struct Person {
public:
    Person() {};
    Person(string fn, string ln, int a) : 
    _firstname(std::move(fn)), _lastname(std::move(ln)), _age(a) {};

    string name() const{ return _firstname + " " + _lastname; };
    int age() const { return _age; };

    void first_name(const string &n);
    void last_name(const string &n);
    void age(const int &a);

  private:
    string _firstname;
    string _lastname;
    int _age;
};

void Person::age(const int &a) {
  if (a < 0 || 150 < a) {
    throw std::invalid_argument("age out of range");
  }
  _age = a;
}

void Person::first_name(const string &n) {
  for (char c : n) {
    if (!std::isalpha(c) && c != ' ') {
      throw std::invalid_argument("not a valid name");
    }
  }
  _firstname = n;
}

void Person::last_name(const string &n) {
  for (char c : n) {
    if (!std::isalpha(c) && c != ' ') {
      throw std::invalid_argument("not a valid name");
    }
  }
  _lastname = n;
}

vector<Person> Persons;

std::istream& operator>>(std::istream &is, Person &p) {
  string fn, ln;
  int a;
  if (is >> fn >> ln >> a) {
      p.first_name(fn);
      p.last_name(ln);
      p.age(a);
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    return os << "Name: " << p.name() << '\t' << "Age: " << p.age() << '\n';
}

int main() {
    try {
    Person p {"", "",  0};
    int lst_length;
    cout << "Please enter length of list of persons:\n";
    cin >> lst_length;
    cout << "Please enter name and age of person(s):\n";
    for (int i = 0; i < lst_length; ++i) {
        cin >> p;
        Persons.push_back(p);
    }
    for (Person x : Persons) {
        cout << x;
    }
    } 
    catch (std::invalid_argument& e) {
        std::cerr << "error: " << e.what() << '\n';
    }
}