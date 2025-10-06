#include <iostream>
#include <iterator>
#include <ranges>
#include <vector>

template <std::input_iterator In, std::input_iterator In2, typename T>
T inner_product(In first, In last, In2 first2, T init) {
  while (first != last) {
    init = init + (*first) * (*first2);
    ++first;
    ++first2;
  }
  return init;
}

template <std::ranges::input_range R1, std::ranges::input_range R2, typename T>
T inner_product_range(R1 first, R2 first2, T init) {
  return inner_product(std::begin(first), std::end(first), std::begin(first2),
                       0);
}

std::vector<double> dow_price = {104.48, 165.02, 285.76, 412.58, 231.71, 23.90};

std::vector<double> dow_weight = {2.41, 2.84, 2.88, 1.23, 6.32, 8.21};

double dji_index =
    inner_product(dow_price.begin(), dow_price.end(), dow_weight.begin(), 0);

int main() {

  std::cout << dji_index << '\n';

  std::cout << inner_product_range(dow_price, dow_weight, 0) << '\n';
}
