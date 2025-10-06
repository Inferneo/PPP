#include <algorithm>
#include <chrono>
#include <iostream>
#include <map>
#include <random>
#include <string>
#include <utility>
#include <vector>

using std::cout;
using std::default_random_engine;
using std::map;
using std::pair;
using std::string;
using std::uniform_int_distribution;
using std::vector;
using std::ranges::find_if;

using namespace std::chrono;        // that's where the timing support is

default_random_engine &get_rand() {
  static default_random_engine ran;
  return ran;
};

int random_int(int min, int max) {
  return uniform_int_distribution<>{min, max}(get_rand());
}
int random_int(int max) { return random_int(0, max); }

string random_letters(int n, int m) {
    string s(random_int(n,m), 'x');
    for (char& ch : s) {
        ch = static_cast<char>(random_int('a', 'z'));
    }
    return s;
}

vector<pair<string, int>> generate(int n) {
  vector<pair<string, int>> res;
  for (int i = 0; i < n; ++i) {
    res.push_back({random_letters(4, 24), random_int(1'000'000)});
  }
  return res;
}

int main() {
    
    vector<std::pair<string, int>> v = generate(2'000'000);     // generate some data
    string x = v[v.size() / 2].first;                             // pick a string to search for

    auto t0 = steady_clock::now();                    // the point of time of the call
    auto pv = find_if(v, [&x](const auto &s) { return s.first == x; });     // linear search
    auto t1 = steady_clock::now();
    cout << "vector: " << pv->second << '\n';
    cout << duration_cast<milliseconds>((t1-t0)).count() << "ms\n\n"; // count is number of "clock ticks"

    map<string, int> m{v.begin(), v.end()};
    auto t2 = steady_clock::now();
    auto vm = m[x];                                 // tree search, may add an element
    auto t3 = steady_clock::now();
    cout << "map: " << vm << '\n';
    cout << duration_cast<milliseconds>(t3-t2).count() << "ms\n\n";

    auto t22 = steady_clock::now();
    auto pm = find_if(m, [&x] (const auto& s) { return s.first == x; });    // linear search
    auto t32 = steady_clock::now();
    cout << "map find_if: " << pm->second << '\n';
    cout << duration_cast<milliseconds>(t32-t22).count() << "ms\n\n";

}

