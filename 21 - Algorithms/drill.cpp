#include <algorithm>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iterator>
#include <numeric>
#include <ostream>
#include <utility>
#include <vector>

std::ifstream is{"floats.txt"};
std::istream_iterator<double> ii{is};
std::istream_iterator<double> eos;

template <typename T>
std::ostream &operator<<(std::ostream &os, std::vector<T> &vec) {
  for (auto &x : vec) {
    os << x << '\t';
  }
  return os;
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
  return os << std::left << std::setw(13) << p.first << std::right
            << std::setw(13) << p.second << '\n';
}

int main() {
  std::vector<double> vd = {ii, eos};

  std::vector<int> vi(vd.size());
  std::copy(vd.begin(), vd.end(), vi.begin());

  for (int i = 0; i < vd.size(); ++i) {
    std::cout << std::pair<double, int>{vd[i], vi[i]};
  }

  double vd_sum = std::accumulate(vd.begin(), vd.end(), 0.0);
  int vi_sum = std::accumulate(vi.begin(), vi.end(), 0);

  double diff = vd_sum - vi_sum;

  std::cout << '\n' << vd_sum;
  std::cout << '\n' << vi_sum;
  std::cout << '\n' << diff << '\n';

  std::reverse(vd.begin(), vd.end());

  std::cout << '\n' << vd << '\n';

  double vd_mean = vd_sum / vd.size();

  std::cout << '\n' << vd_mean << '\n';

  std::vector<double> vd2;
  std::copy_if(vd.begin(), vd.end(), std::back_inserter(vd2),
               [&](const auto &s) { return s < vd_mean; });

  std::cout << '\n' << vd2 << '\n';

  std::sort(vd2.begin(), vd2.end());

  std::cout << '\n' << vd2 << '\n';
}
