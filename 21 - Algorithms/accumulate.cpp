#include <iostream>
#include <iterator>
#include <vector>

template<std::input_iterator In,
         typename T, 
         std::invocable<T, typename In::value_type> BinOp>
[[nodiscard]]
T accumulate(In first, In last, T init, BinOp op) {
    while (first != last) {
        init = op(init, *first);
        ++first;
    }
    return init;
}

struct Record {
    double unit_price;
    int units;
};

double price(double v, const Record& r) {
    return v + r.unit_price * r.units;
}

double f(const std::vector<Record>& vr) {
    return accumulate(vr.begin(), vr.end(), 0, price);
}

int main() {

    std::vector<Record> vr {
        {3.50, 28},
        {5.45, 21}, 
        {2.30, 45},
        {7.64, 8}};

    std::cout << f(vr) << '\n';
}