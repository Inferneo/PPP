#include <concepts>
#include <iostream>
#include <iterator>
#include <vector>

template <std::input_iterator In,
          std::equality_comparable_with<typename In::value_type> T>
In find(In first, In last, const T &val) {
  while (first != last && *first != val) {
    ++first;
  }
  return first;
}

template <std::input_iterator In,
          std::equality_comparable_with<typename In::value_type> T>
In find_pedestrian(In first, In last, const T &val) {
  for (In p = first; p != last; ++p) {
    if (*p == val) {
      return p;
    }
  }
  return last;
}

int main() {
  std::vector<int> v = {10, 20, 30, 40, 50};
  auto f = find(v.begin(), v.end(), 35);
  if (f != v.end()) {
    std::cout << *f << '\n';
  }
}