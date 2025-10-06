#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <iterator>
#include <list>
#include <ostream>
#include <string>
#include <vector>

using std::erase_if;
using std::ifstream;
using std::istream;
using std::istream_iterator;
using std::list;
using std::ofstream;
using std::ostream;
using std::ostream_iterator;
using std::sort;
using std::string;
using std::vector;

struct Item {
  string name;
  int iid;
  double value;
};

istream &operator>>(istream &is, Item &it) {
  return is >> it.name >> it.iid >> it.value;
}

ostream &operator<<(ostream &os, const Item &it) {
  return os << it.name << '\t' << it.iid << '\t' << it.value;
}

int main() {

  ifstream is{"items.txt"};     // open input stream
  ofstream os{"items_out.txt"}; // open output stream

  istream_iterator<Item> ii{is};       // make input iterator for stream
  istream_iterator<Item> eos;          // input sentinel
  ostream_iterator<Item> oo{os, "\n"}; // make output iterator for stream

  vector<Item> vi{ii, eos};

  vi.insert(vi.end(), {"horse shoe", 99, 12.34});
  vi.insert(vi.end(), {"Canon S400", 9988, 499.95});

  erase_if(vi, [](Item &a) { return a.name == "Dharma" || a.name == "Dao"; });

  sort(vi.begin(), vi.end(), [](const Item &a, const Item &b) {
    return a.value > b.value;
  });                             // sort the buffer
  copy(vi.begin(), vi.end(), oo); // copy buffer to output

  list<Item> li{ii, eos};

  li.insert(li.end(), {"horse shoe", 99, 12.34});
  li.insert(li.end(), {"Canon S400", 9988, 499.95});

  erase_if(li, [](Item &a) { return a.name == "Dharma" || a.name == "Dao"; });

  li.sort([](const Item &a, const Item &b) { return a.value > b.value; });
  copy(li.begin(), li.end(), oo); // copy buffer to output
}