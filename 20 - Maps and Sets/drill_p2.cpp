#include <iomanip>
#include <ios>
#include <iostream>
#include <map>
#include <numeric>
#include <ostream>
#include <string>
// #include <utility>

using std::accumulate;
using std::basic_string;
// using std::cin;
using std::cout;
using std::left;
using std::map;
using std::ostream;
// using std::pair;
using std::right;
using std::setw;
using std::string;

template<typename K, typename V>
ostream &operator<<(ostream &os, map<K, V> &m) {
  for (auto &p : m) {
    os << left << setw(12) << p.first << right << setw(5) << p.second << '\n';
  }
    return os; 
}

int main() {

    map<string, int> msi;

    msi["lecture"] = 21;
    msi["monsoon"] = 7;
    msi["oblivion"] = 42;
    msi["tarkovsky"] = 197;
    msi["entropy"] = 93;
    msi["neon"] = 88;
    msi["nocturne"] = 11;
    msi["ascent"] = 314;
    msi["labyrinth"] = 66;
    msi["horizon"] = 5;
    
    cout << msi;

    double sum =
        accumulate(msi.begin(), msi.end(), 0,
                   [](double acc, const auto &p) { return acc + p.second; });

    cout << sum << '\n';

    // msi.erase(msi.begin(), msi.end());

    // for (pair<string, int> p; cin >> p.first >> p.second;) {
    //     msi.insert(p);
    // }

    map<int, string> mis;

    for (auto &[k, v] : msi) {
        mis[v] = k;
    }

    cout << mis;
}

